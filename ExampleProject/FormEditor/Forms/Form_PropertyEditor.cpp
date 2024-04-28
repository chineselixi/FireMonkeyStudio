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
void Form_PropertyEditor::showWidgetsAttr(QWidget* signBaseWidget, widgetMsg* selectWidget)
{
    static QList<AttributeNode> t_oldAttrNodes;
    //验证参数，如果为空，则全部回收所有信息
    if(selectWidget == nullptr){
        this->editorBaseWidget = nullptr;
        this->nowSelectWidgetMsg = nullptr;
        this->variantPropertyManger->clear();
        this->enumPropertyMsnger->clear();
        ui->propertyBox->clear();
        this->propertyList.clear();
        return;
    }

    //将属性按组分类
    QMap<QString,QList<AttributeNode>> t_newAttrGroup;
    for(AttributeNode an : selectWidget->attrs){
        if(an.group.isEmpty()) an.group = tr("基础"); //没有分组标记的默认值
        QList<AttributeNode> t_ans = t_newAttrGroup.value(an.group);
        t_ans.append(an);
        t_newAttrGroup.insert(an.group,t_ans);
    }
    if(signBaseWidget != this->editorBaseWidget || selectWidget != this->nowSelectWidgetMsg){   //判断是否更新了组件信息
        //选择了新的组件
        //清空属性框
        ui->propertyBox->clear();
        this->propertyList.clear();

        //显示基础属性
        this->showBaseProperty(selectWidget->widget);

        //按照分组显示创建并且显示属性
        QtProperty* t_group = nullptr;
        for(QString key : t_newAttrGroup.keys()){
            QList<AttributeNode> t_ans = t_newAttrGroup.value(key);
            if(t_ans.length() > 0){ //此分类组存在属性才开始分组
                t_group = variantPropertyManger->addProperty(QtVariantPropertyManager::groupTypeId(),key);
                //this->propertyList.append({t_retProperty,an});    //记录属性指针与属性信息
                for(AttributeNode anItem : t_ans){
                    t_group->addSubProperty(this->addProperty(anItem));
                }
                ui->propertyBox->addProperty(t_group);
                this->propertyList.append({t_group,AttributeNode()});   //保存组
            }
        }
    }
    else{
        //只是更新了属性
        //将老组分类
        QMap<QString,QList<AttributeNode>> t_oldAttrGroup;
        for(AttributeNode an : t_oldAttrNodes){
            if(an.group.isEmpty()) an.group = tr("基础"); //没有分组标记的默认值
            QList<AttributeNode> t_ans = t_oldAttrGroup.value(an.group);
            t_ans.append(an);
            t_oldAttrGroup.insert(an.group,t_ans);
        }

        //显示基础属性
        QList<property*> t_baseProperty = this->getPropertyMsgByGroup(NORMALGROUP);
        for(property* baseProItem : t_baseProperty){
            if(baseProItem){
                if(baseProItem->attrNode.attrSign == "geometry"){
                    baseProItem->attrNode.value = this->nowSelectWidgetMsg->widget->geometry();
                    this->variantPropertyManger->setValue(baseProItem->propertyPtr,baseProItem->attrNode.value);
                }
                else if(baseProItem->attrNode.attrSign == "minimumSize"){
                    baseProItem->attrNode.value = this->nowSelectWidgetMsg->widget->minimumSize();
                    this->variantPropertyManger->setValue(baseProItem->propertyPtr,baseProItem->attrNode.value);
                }
                else if(baseProItem->attrNode.attrSign == "maximumSize"){
                    baseProItem->attrNode.value = this->nowSelectWidgetMsg->widget->maximumSize();
                    this->variantPropertyManger->setValue(baseProItem->propertyPtr,baseProItem->attrNode.value);
                }
            }
        }


        //this->showBaseProperty(selectWidget->widget);

        QStringList groupSame,groupLack,groupNew;
        this->getListDifference(t_oldAttrGroup.keys(),t_newAttrGroup.keys(),groupSame,groupLack,groupNew);

        QtVariantProperty* t_group = nullptr;
        //相同的组
        for(QString item : groupSame){
            //系统的组就判断组件是否相同
            QMap<QString,AttributeNode> t_newGroupAttrSigns,t_oldGroupAttrSigns;
            for(AttributeNode attrNode : t_newAttrGroup.value(item)){t_newGroupAttrSigns.insert(attrNode.attrSign,attrNode);}
            for(AttributeNode attrNode : t_oldAttrGroup.value(item)){t_oldGroupAttrSigns.insert(attrNode.attrSign,attrNode);}

            QStringList signSame,signLack,signNew;
            this->getListDifference(t_oldGroupAttrSigns.keys(),t_newGroupAttrSigns.keys(),signSame,signLack,signNew);

            //相同的属性
            for(QString attrSignItem : signSame){
                AttributeNode t_sa = t_newGroupAttrSigns.value(attrSignItem);
                for(property& proi : propertyList){
                    if(proi.attrNode.attrSign == t_sa.attrSign
                        && proi.attrNode.group == t_sa.group){  //分组，标记相等
                        proi.attrNode.value = t_sa.value;
                        if(t_sa.enums.length() == 0){   //普通属性
                            QtVariantProperty* t_vp = dynamic_cast<QtVariantProperty*>(proi.propertyPtr);
                            if(t_vp)
                            t_vp->setValue(t_sa.value);
                        }
                        else{   //枚举属性
                            int t_index = -1;
                            enumPropertyMsnger->setEnumNames(proi.propertyPtr,t_sa.enums);
                            for(int i = 0; i < t_sa.enums.length(); i++){
                                if(t_sa.enums[i] == t_sa.value.toString()){
                                    t_index = i;
                                    break;
                                }
                            }
                            enumPropertyMsnger->setValue(proi.propertyPtr,t_index);
                        }
                        break;
                    }
                }
            }

            //缺少的属性
            for(QString attrSignItem : signLack){
                for(qsizetype i = propertyList.length() - 1; i >= 0; i--){  //倒删属性
                    if(propertyList[i].attrNode.attrSign == attrSignItem
                        && propertyList[i].attrNode.group == item){
                        ui->propertyBox->removeProperty(propertyList[i].propertyPtr);
                        propertyList.removeAt(i);
                        break;
                    }
                }
            }

            //新增的属性
            if(signNew.length() > 0){
                //获取当前组的指针信息
                QtProperty* t_newAttrGroup = nullptr;
                for(qsizetype i = propertyList.length() - 1; i >= 0; i--){  //倒删属性
                    if(propertyList[i].propertyPtr->propertyName() == item){
                        t_newAttrGroup = propertyList[i].propertyPtr;
                        break;
                    }
                }

                if(t_newAttrGroup){
                    for(QString attrSignItem : signNew){
                        AttributeNode t_sa = t_newGroupAttrSigns.value(attrSignItem);
                        QtProperty* t_retAdd = this->addProperty(t_sa); //当前组新增属性
                        t_newAttrGroup->addSubProperty(t_retAdd);
                    }
                }
            }

        }


        //缺少的组
        for(QString item : groupLack){
            for(qsizetype a = propertyList.length() - 1; a >= 0; a--){
                QtVariantProperty* t_vpro = dynamic_cast<QtVariantProperty*>(propertyList[a].propertyPtr);
                if(t_vpro != nullptr && t_vpro->propertyType() == QtVariantPropertyManager::groupTypeId()){ //找到了这个组，删除组信息
                    //先删除组的子项信息
                    QList<QtProperty*> t_subs = t_vpro->subProperties(); //获取组的子项信息
                    ui->propertyBox->removeProperty(t_vpro);    //移除这个组
                    propertyList.removeAt(a);

                    //遍历移除子项
                    for(QtProperty* subItem : t_subs){
                        for(qsizetype b = propertyList.length() - 1; b >= 0; b--){
                            if(propertyList[b].propertyPtr == subItem){
                                propertyList.removeAt(b);
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }

        //新增的组
        for(QString item : groupNew){
            t_group = variantPropertyManger->addProperty(QtVariantPropertyManager::groupTypeId(),item);
            QList<AttributeNode> t_ans = t_newAttrGroup.value(item);
            for(AttributeNode anItem : t_ans){
                t_group->addSubProperty(this->addProperty(anItem));
            }
            ui->propertyBox->addProperty(t_group);
            this->propertyList.append({t_group,AttributeNode()});   //保存组
        }
    }

    //更新属性信息
    t_oldAttrNodes = selectWidget->attrs; //更新老的属性组
    this->editorBaseWidget = signBaseWidget;
    this->nowSelectWidgetMsg = selectWidget;
}



//添加属性信息
QtProperty *Form_PropertyEditor::addProperty(AttributeNode an)
{
    QtProperty* t_retProperty = nullptr;;
    bool t_hasProperty = false;
    for(property item : this->propertyList){
        if(item.attrNode ^ an){
            t_retProperty = item.propertyPtr;
            t_hasProperty = true;
            break;
        }
    }

    if(an.enums.length() == 0){ //默认属性
        if(t_retProperty == nullptr){       //列表不存在此属性，才创建
            QtVariantProperty* t_vp = variantPropertyManger->addProperty(an.value.typeId(),an.title);
            t_retProperty = t_vp;
        }
        variantPropertyManger->setValue(t_retProperty,an.value);
    }
    else{ //枚举属性
        if(t_retProperty == nullptr)
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
    t_retProperty->setEnabled(an.canEdit);
    if(!t_hasProperty)
    this->propertyList.append({t_retProperty,an});    //记录属性指针与属性信息
    return t_retProperty;
}


//根据组获取属性节点信息
QList<Form_PropertyEditor::property*> Form_PropertyEditor::getPropertyMsgByGroup(QString group)
{
    QList<property*> t_retPro;
    for(Form_PropertyEditor::property& proItem : propertyList){
        if(proItem.attrNode.group == group){
            t_retPro.append(&proItem);
        }
    }
    return t_retPro;
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


//两个字符串列表，返回两个元素系统部分，新较少的缺少部分和增加部分
void Form_PropertyEditor::getListDifference(QStringList oldStrList,
                                            QStringList newStrList,
                                            QStringList &retSame,
                                            QStringList &retLack,
                                            QStringList &retNew)
{
    bool* t_sign = (bool*)malloc(oldStrList.length() * sizeof(bool));   //申请一块内存用于标记
    for(int a = 0; a < oldStrList.length();a++)t_sign[a] = false;       //更改内存区域为0

    for(int a = 0; a < newStrList.length(); a++){
        for(int b = 0; b < oldStrList.length(); b++){
            if(newStrList[a] == oldStrList[b]){ //存在相同的
                retSame.append(newStrList[a]);    //新和旧系统的部分
                t_sign[b] = true;   //标记这个位置是存在的
                goto BREAKOLD;      //跳出循环
            }
        }
        retNew.append(newStrList[a]); //新的存在，旧的不存在的部分
        BREAKOLD:
        continue;
    }

    //旧存在新的不存在的部分
    for(int a = 0; a < oldStrList.length();a++){
        if(t_sign[a] == false){
            retLack.append(oldStrList[a]);
        }
    }
    free(t_sign);//释放内存
}


//显示基础的属性信息
void Form_PropertyEditor::showBaseProperty(QWidget *widget)
{
    QtVariantProperty* t_group = nullptr;
    t_group = variantPropertyManger->addProperty(QtVariantPropertyManager::groupTypeId(),"对象");
    t_group->addSubProperty(this->addProperty({tr("对象名"),NORMALGROUP,"objectName",widget->objectName(),{},true}));
    ui->propertyBox->addProperty(t_group);

    t_group = variantPropertyManger->addProperty(QtVariantPropertyManager::groupTypeId(),"尺寸");
    t_group->addSubProperty(this->addProperty({tr("默认尺寸"),NORMALGROUP,"geometry",widget->geometry(),{},true}));
    t_group->addSubProperty(this->addProperty({tr("最小尺寸"),NORMALGROUP,"minimumSize",widget->minimumSize(),{},true}));
    t_group->addSubProperty(this->addProperty({tr("最大尺寸"),NORMALGROUP,"maximumSize",widget->maximumSize(),{},true}));
    ui->propertyBox->addProperty(t_group);
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
                    this->onWidgetNameChange(this->editorBaseWidget,this->nowSelectWidgetMsg,t_newName);
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
        this->showWidgetsAttr(this->editorBaseWidget,this->nowSelectWidgetMsg);  //更新显示的属性
        this->onWidgetUpdate(this->editorBaseWidget,this->nowSelectWidgetMsg);   //激发事件更新事件
    }
}



//编辑器枚举被改变
void Form_PropertyEditor::EnumValueChanged(QtProperty *property, int val)
{
    this->PropertyValueChanged(property,val);
}
