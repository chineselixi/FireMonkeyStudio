#include "Form_PropertyEditor.h"
#include "ui_Form_PropertyEditor.h"
#include "Form_EditorSpace.h"
#include "QMetaObject"


Form_PropertyEditor::Form_PropertyEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_PropertyEditor)
{
    ui->setupUi(this);

    propertyManger = new QtVariantPropertyManager(ui->propertyBox); //创建抽象属性管理器
    propertyEnumMsnger = new QtEnumPropertyManager(ui->propertyBox); //创建枚举属性管理器

    propertyFactory = new QtVariantEditorFactory(ui->propertyBox);   //创建抽象编辑器工厂
    propertyEnumFactory = new QtEnumEditorFactory(ui->propertyBox);  //创建枚举编辑器工厂

    //链接改变事件
    connect(propertyManger,&QtVariantPropertyManager::valueChanged,this,&Form_PropertyEditor::PropertyValueChanged);
    connect(propertyEnumMsnger,&QtEnumPropertyManager::valueChanged,this,&Form_PropertyEditor::EnumValueChanged);

    ui->propertyBox->setFactoryForManager(propertyManger,propertyFactory); //绑定管理器与编辑器，这样管理器才可以激发信号
    ui->propertyBox->setFactoryForManager(propertyEnumMsnger,propertyEnumFactory); //绑定枚举管理器与枚举工厂
}

Form_PropertyEditor::~Form_PropertyEditor()
{
    delete ui;
}


//注册控件属性
void Form_PropertyEditor::registerWidgetsAttr(QString editorSpaceSign, QList<widgetMsg> widgetMsgs)
{
    this->editorSpaceSign = editorSpaceSign;
    this->widgetMsgs = widgetMsgs;
}


//获取相同的属性节点信息
QList<AttributeNode> Form_PropertyEditor::getEqualAttrNodes()
{
    QList<AttributeNode> t_retNodes;
    //找出相同属性
    if(this->widgetMsgs.length() > 0){
        QList<AttributeNode> t_equalAttrNodes = this->widgetMsgs[0].attrs;
        for(qsizetype a = t_equalAttrNodes.length() - 1; a >= 0; a--){      //倒着遍历属性
            for(qsizetype i = 0; i < this->widgetMsgs.length(); i++){
                QList<AttributeNode> t_attrNodes = this->widgetMsgs[i].attrs;
                for(qsizetype x = 0; x < t_attrNodes.length(); i++){
                    if(t_equalAttrNodes[a].attrSign != t_attrNodes[x].attrSign ||
                        t_equalAttrNodes[a].title != t_attrNodes[x].title ||
                        t_equalAttrNodes[a].value != t_attrNodes[x].value){
                        goto BREAK; //只要有一个不相等，就跳出这个属性
                    }
                }
            }
            continue; //到循环尾，跳过删除选项，保留这个属性，就是全组件都有的
            BREAK:
            t_equalAttrNodes.removeAt(a);
        }
    }
}


//显示控件组的属性
void Form_PropertyEditor::showWidgetsAttr()
{
    //去除相同的属性
    //存储相同属性的控件对象的widget指针

    //激发消息
}





//加载对象组
void Form_PropertyEditor::loadPropertyMsgs(QVector<Plugin_Base *> objs,Form_EditorSpace* editor)
{
    this->widgetObjects = objs;
    this->showProertyMsg();
}



//根据编辑器指针移除全部属性信息
void Form_PropertyEditor::removeProertyMsg_editor(Form_EditorSpace *editor)
{
    if(this->editorObj == editor){
        this->widgetObjects.clear();
        this->editorObj =nullptr;
    }
    this->showProertyMsg(); //重新显示信息
}


//移除控件对象，若不移除，则可能出现奔溃
void Form_PropertyEditor::removeProertyMsg_obj(Plugin_Base *obj)
{
    for(int a = this->widgetObjects.length() - 1;a >= 0;a--){
        if(this->widgetObjects[a] == obj){
            this->widgetObjects.removeAt(a);
        }
    }
    this->showProertyMsg(); //重新显示信息
    if(this->widgetObjects.length() == 0){editorObj = nullptr;} //当前没有可用对象则直接撤销
}


void Form_PropertyEditor::showProertyMsg()
{
//    ui->propertyBox->clear(); //关闭所有的属性选项，将会自动销毁所有的item
//    if(this->widgetObjects.length() == 1){ //如果只是单个属性
//        //开始加载信息
//        QtVariantProperty* t_groupItem; //分组对象
//        QtVariantProperty* t_variantItem; //属性对象
//        QtProperty* t_item;  //下拉状态对象

//        //加载对象基本信息
//        t_groupItem = propertyManger->addProperty(QtVariantPropertyManager::groupTypeId(),tr("基本属性"));
//        t_variantItem = propertyManger->addProperty(QVariant::String,tr("对象名"));
//        t_variantItem->setValue(this->widgetObjects[0]->getWidgetInstance()->objectName());
//        t_groupItem->addSubProperty(t_variantItem); //加入分组
//        ui->propertyBox->addProperty(t_groupItem); //显示基本分组信息

//        //加载尺寸信息
//        t_groupItem = propertyManger->addProperty(QtVariantPropertyManager::groupTypeId(),tr("尺寸"));
//        t_variantItem = propertyManger->addProperty(QVariant::Rect,tr("窗体"));
//        t_variantItem->setValue(this->widgetObjects[0]->getWidgetInstance()->geometry());
//        t_variantItem->setEnabled(this->widgetObjects[0]->enable_geometry); //设置禁用
//        t_groupItem->addSubProperty(t_variantItem);

//        t_variantItem = propertyManger->addProperty(QVariant::Size,tr("最小尺寸"));
//        t_variantItem->setValue(this->widgetObjects[0]->getWidgetInstance()->minimumSize());
//        t_variantItem->setEnabled(this->widgetObjects[0]->enable_minSize);  //设置禁用
//        t_groupItem->addSubProperty(t_variantItem);

//        t_variantItem = propertyManger->addProperty(QVariant::Size,tr("最大尺寸"));
//        t_variantItem->setValue(this->widgetObjects[0]->getWidgetInstance()->maximumSize());
//        t_variantItem->setEnabled(this->widgetObjects[0]->enable_maxSize);  //设置禁用
//        t_groupItem->addSubProperty(t_variantItem);

//        ui->propertyBox->addProperty(t_groupItem); //显示基本分组信息
//    }


//    if(this->widgetObjects.length() >= 1){ //如果是多个对象
//        QVector<propertyMsg> t_pList = this->widgetObjects[0]->propertyList; //取出第一个属性列表信息
//        QVector<propertyMsg> t_newProperty;  //新的属性列表

//        bool t_hasProperty = true;
//        bool t_same = true;

//        for(int a = 0; a<t_pList.length() ;a++){  //遍历当前属性表的每一个属性
//            t_hasProperty = true;
//            t_same = true;

//            for(int b = 1;b < this->widgetObjects.length();b++){ //遍历当前除自己的剩余对象
//                t_hasProperty = false; //默认为假，如果某一个对象没有该属性，则直接跳出
//                for(int c = 0; c < this->widgetObjects[b]->propertyList.length(); c++){ //遍历属于对象的所有属性
//                    if(t_pList[a] << this->widgetObjects[b]->propertyList[c]){  //判断属性是否相同,注意，这里<<是运算符重载
//                        qDebug() << "属性相同" << t_pList[a].name;
//                        t_hasProperty = true;
//                        if(!(t_pList[a] == this->widgetObjects[b]->propertyList[c])){ //判断值是否相等
//                            t_same = false;
//                        }
//                        break;
//                    }
//                }
//                if(t_hasProperty == false){
//                    break;
//                }
//            }

//            //如果都有这个参数，则代表存在
//            if(t_hasProperty == true){
//                propertyMsg t_property = t_pList[a];
//                if(t_same == false){ //加载
//                    t_property = ""; //制空参数
//                }
//                t_newProperty.append(t_property);
//            }
//        }

//        //按加载分类信息
//        QVector<QString> t_signNameList;
//        for(auto t_sign : t_newProperty){t_signNameList.append(t_sign.sign);}
//        t_signNameList = this->uniqueMsgList<QString>(t_signNameList); //分组类型去重

//        //创建所有的分组信息
//        struct GroupMsg{
//            QString name;
//            QtVariantProperty* groupItem;
//        };
//        QVector<GroupMsg> t_groList;
//        for(auto value : t_signNameList){
//            GroupMsg t_groMsg;
//            t_groMsg.name = value;
//            t_groMsg.groupItem = propertyManger->addProperty(QtVariantPropertyManager::groupTypeId(),value);
//            ui->propertyBox->addProperty(t_groMsg.groupItem); //加入分组信息到属性表
//            t_groList.append(t_groMsg); //加入到列表
//        }

//        //开始加载自定义属性
//        QtVariantProperty* t_variantItem; //属性对象
//        QtProperty* t_item;  //下拉状态对象
//        for(auto t_property : t_newProperty){  //从最新整理的列表加载属性
//            t_variantItem = nullptr;

//            switch(t_property.type){
//            case propertyType::Int:{
//                t_variantItem = propertyManger->addProperty(QVariant::Int,t_property.name);
//                t_variantItem->setValue(t_property.value_Int); //设置初始值
//                break;
//            }
//            case propertyType::Double:{
//                t_variantItem = propertyManger->addProperty(QVariant::Double,t_property.name);
//                t_variantItem->setValue(t_property.value_Double); //设置初始值
//                break;
//            }
//            case propertyType::Bool:{
//                t_variantItem = propertyManger->addProperty(QVariant::Bool,t_property.name);
//                t_variantItem->setValue(t_property.value_Bool); //设置初始值
//                break;
//            }
//            case propertyType::Color:{
//                t_variantItem = propertyManger->addProperty(QVariant::Color,t_property.name);
//                t_variantItem->setValue(t_property.value_Color); //设置初始值
//                break;
//            }
//            case propertyType::String:{
//                t_variantItem = propertyManger->addProperty(QVariant::String,t_property.name);
//                t_variantItem->setValue(t_property.value_String); //设置初始值
//                break;
//            }
//            case propertyType::Size:{
//                t_variantItem = propertyManger->addProperty(QVariant::Size,t_property.name);
//                t_variantItem->setValue(t_property.value_Size); //设置初始值
//                break;
//            }
//            case propertyType::Enum:{
//                t_item = propertyEnumMsnger->addProperty(t_property.name);
//                propertyEnumMsnger->setEnumNames(t_item,t_property.value_Enum);
//                propertyEnumMsnger->setValue(t_item,t_property.value_EnumIndex);
//                t_variantItem = (QtVariantProperty*)t_item;
//                break;
//            }
//            default:{
//                break;
//            }
//            }

//            for(auto value : t_groList){
//                if(value.name == t_property.sign){
//                    value.groupItem->addSubProperty(t_variantItem);
//                    goto BREAK_FRO; //跳过默认父项添加
//                }
//            }
//            ui->propertyBox->addProperty(t_variantItem);
//        BREAK_FRO:{}
//        }
//    }
}





//去除重复数据
template<class T>
QVector<T> Form_PropertyEditor::uniqueMsgList(QVector<T> v)
{
    QVector<T> t_list;
    for(auto value : v){
        for(auto item : t_list){
            if(item == value){
                goto BREAK;
            }
        }
        t_list.append(value);
    BREAK:{}
    }
    return t_list;
}





//编辑的内容被改变
void Form_PropertyEditor::PropertyValueChanged(QtProperty *property,const QVariant &val)
{
    switch(val.typeId()){
    case QVariant::Int:{

        break;
    }
    case QVariant::Double:{
        break;
    }
    case QVariant::Bool:{
        break;
    }
    case QVariant::Color:{
        break;
    }
    case QVariant::String:{
        break;
    }
    case QVariant::Size:{
        break;
    }
    case QVariant::Rect:{
        break;
    }
    default:{
        break;
    }
    }
    qDebug() << "编辑的内容被改变 typeId=" << val.typeId() ;
}



//编辑器枚举被改变
void Form_PropertyEditor::EnumValueChanged(QtProperty *property, int val)
{
    qDebug() << "EnumValueChanged val=" << property->valueText() << val;
}
