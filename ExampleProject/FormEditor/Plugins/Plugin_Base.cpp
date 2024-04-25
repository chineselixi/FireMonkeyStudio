#include "Plugin_Base.h"



//从列表获取属性指针
AttributeNode *Plugin_Base::getListAttr(QList<AttributeNode> &attrs, QString group, QString attrSign)
{
    for(AttributeNode& item : attrs){
        if(item.group == group && item.attrSign == attrSign){
            return &item;
        }
    }
    return nullptr;
}

//组件创建返回的代码
QString Plugin_Base::code_onWidgetBuild(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}

//组件属性赋值返回的代码
QString Plugin_Base::code_onAttributeBuild(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}

//组件销毁返回的代码
QString Plugin_Base::code_onWidgetClose(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}
