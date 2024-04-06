#include "Plugin_Base.h"


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
