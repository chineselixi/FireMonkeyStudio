#include "Form_PropertyEditor.h"
#include "ui_Form_PropertyEditor.h"
#include "Form_EditorSpace.h"
#include "QMetaObject"


Form_PropertyEditor::Form_PropertyEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_PropertyEditor)
{
    ui->setupUi(this);
    Form::PropertyEditorPtr = this;

    variantPropertyManger = new QtVariantPropertyManager(ui->propertyBox); //创建抽象属性管理器
    enumPropertyMsnger = new QtEnumPropertyManager(ui->propertyBox); //创建枚举属性管理器

    variantPropertyFactory = new QtVariantEditorFactory(ui->propertyBox);   //创建抽象编辑器工厂
    enumPropertyFactory = new QtEnumEditorFactory(ui->propertyBox);  //创建枚举编辑器工厂


    //链接改变事件
    connect(variantPropertyManger,&QtVariantPropertyManager::valueChanged,this,&Form_PropertyEditor::PropertyValueChanged);    //属性值改变
    connect(enumPropertyMsnger,&QtEnumPropertyManager::valueChanged,this,&Form_PropertyEditor::EnumValueChanged);       //枚举值改变

    ui->propertyBox->setFactoryForManager(variantPropertyManger,variantPropertyFactory); //绑定管理器与编辑器，这样管理器才可以激发信号
    ui->propertyBox->setFactoryForManager(enumPropertyMsnger,enumPropertyFactory); //绑定枚举管理器与枚举工厂
}

Form_PropertyEditor::~Form_PropertyEditor()
{
    delete ui;
    Form::PropertyEditorPtr = nullptr;
}




//显示控件组的属性
void Form_PropertyEditor::showWidgetsAttr(QString editorSpaceSign, widgetMsg* selectWidget)
{
    //保存widgetMsg
    this->editorSpaceSign = editorSpaceSign;
    this->nowSelectWidgetMsg = selectWidget;

    //清空属性框
    ui->propertyBox->clear();
    this->propertyList.clear();

    if(selectWidget == nullptr) return;

    //显示属性
    QtVariantProperty* t_group = nullptr;
    t_group = variantPropertyManger->addProperty(QtVariantPropertyManager::groupTypeId(),"对象");
    t_group->addSubProperty(this->addProperty({tr("对象名"),NORMALGROUP,"objectName",selectWidget->objectName,{},true}));
    ui->propertyBox->addProperty(t_group);

    t_group = variantPropertyManger->addProperty(QtVariantPropertyManager::groupTypeId(),"尺寸");
    t_group->addSubProperty(this->addProperty({tr("默认尺寸"),NORMALGROUP,"geometry",selectWidget->widget->geometry(),{},true}));
    t_group->addSubProperty(this->addProperty({tr("最小尺寸"),NORMALGROUP,"minimumSize",selectWidget->widget->minimumSize(),{},true}));
    t_group->addSubProperty(this->addProperty({tr("最大尺寸"),NORMALGROUP,"maximumSize",selectWidget->widget->maximumSize(),{},true}));
    ui->propertyBox->addProperty(t_group);

    //显示基本属性
    //分类
    QMap<QString,QList<AttributeNode>> t_attrGroup;
    for(AttributeNode an : selectWidget->attrs){
        if(an.group.isEmpty()) an.group = tr("基础"); //没有分组标记的默认值
        QList<AttributeNode> t_ans = t_attrGroup.value(an.group);
        t_ans.append(an);
        t_attrGroup.insert(an.group,t_ans);
    }

    //显示属性
    for(QString key : t_attrGroup.keys()){
        QList<AttributeNode> t_ans = t_attrGroup.value(key);
        if(t_ans.length() > 0){
            AttributeNode t_tempAn = t_ans[0];
            t_group = variantPropertyManger->addProperty(QtVariantPropertyManager::groupTypeId(),key);
            for(AttributeNode anItem : t_ans){
                t_group->addSubProperty(this->addProperty(anItem));
            }
            ui->propertyBox->addProperty(t_group);
        }
    }
}



//添加属性信息
QtProperty *Form_PropertyEditor::addProperty(AttributeNode an)
{
    QtProperty* t_retProperty;
    if(an.enums.length() == 0){ //默认属性
        QtVariantProperty* t_vp = variantPropertyManger->addProperty(an.value.typeId(),an.title);
        t_vp->setValue(an.value);
        t_retProperty = t_vp;
    }
    else{ //枚举属性
        t_retProperty = enumPropertyMsnger->addProperty(an.title);
        enumPropertyMsnger->setEnumNames(t_retProperty,an.enums);
        int t_index = -1;
        for(int i = 0; i < an.enums.length(); i++){
            if(an.enums[i] == an.value.toString()){
                t_index = i;
                break;
            }
        }
        enumPropertyMsnger->setValue(t_retProperty,t_index);
    }
    propertyList.append({t_retProperty,an});    //记录属性指针与属性信息
    return t_retProperty;
}


//根据QtProperty指针获取attr
AttributeNode* Form_PropertyEditor::getAttr(QtProperty *property)
{
    for(Form_PropertyEditor::property& proItem : propertyList){
        if(proItem.propertyPtr == property){
            //获取真实的地址
            for(AttributeNode& node : this->nowSelectWidgetMsg->attrs){
                if(node ^ proItem.attrNode){
                    return &node;
                }
            }

            return &proItem.attrNode;
        }
    }
    return nullptr;
}



//编辑的内容被改变
void Form_PropertyEditor::PropertyValueChanged(QtProperty *property,const QVariant &val)
{
    if(this->nowSelectWidgetMsg == nullptr) return;

    AttributeNode* t_attr = this->getAttr(property);
    if(t_attr){
        if(t_attr->value == val) return;

        if(t_attr->group == NORMALGROUP){   //内置属性被改变
            if(t_attr->attrSign == "objectName"){
                if(val.toString() != this->nowSelectWidgetMsg->widget->objectName()){
                    QString t_newName = val.toString();
                    this->onWidgetNameChange(this->editorSpaceSign,this->nowSelectWidgetMsg,t_newName);
                    this->nowSelectWidgetMsg->objectName = t_newName;
                    this->nowSelectWidgetMsg->widget->setObjectName(t_newName);
                    this->variantPropertyManger->setValue(property,t_newName);
                }
            }
            else if(t_attr->attrSign == "geometry"){
                if(val.toRect() != this->nowSelectWidgetMsg->widget->geometry())
                this->nowSelectWidgetMsg->widget->setGeometry(val.toRect());
            }
            else if(t_attr->attrSign == "minimumSize"){
                if(val.toSize() != this->nowSelectWidgetMsg->widget->minimumSize())
                this->nowSelectWidgetMsg->widget->setMinimumSize(val.toSize());
            }
            else if(t_attr->attrSign == "maximumSize"){
                if(val.toSize() != this->nowSelectWidgetMsg->widget->maximumSize())
                this->nowSelectWidgetMsg->widget->setMaximumSize(val.toSize());
            }
        }
        else{   //外置属性改变
            if(t_attr->enums.length() > 0 && val.typeId() == QVariant::Int){
                int t_index = val.toInt();
                if(t_index >= 0 && t_index <= t_attr->enums.length() - 1){
                    val.fromValue(t_attr->enums[t_index]);
                }
            }
            t_attr->value = val;
            this->nowSelectWidgetMsg->pluginPtr->adjustWidget(this->nowSelectWidgetMsg->widget,this->nowSelectWidgetMsg->attrs); //调用插件更改属性
        }
        this->onWidgetUpdate(this->editorSpaceSign,this->nowSelectWidgetMsg);   //激发事件更新事件
        this->showWidgetsAttr(this->editorSpaceSign,this->nowSelectWidgetMsg);  //更新显示的属性
    }
}



//编辑器枚举被改变
void Form_PropertyEditor::EnumValueChanged(QtProperty *property, int val)
{
    this->PropertyValueChanged(property,val);
}
