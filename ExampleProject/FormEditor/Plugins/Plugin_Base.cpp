#include "Plugin_Base.h"
#include "QMenu"


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

//子控件进入(参数1为容器控件，是本插件插件的。参数2为进入的子控件)
void Plugin_Base::subWidgetEnter(QWidget *packWidget, QWidget *subWidget)
{

}

//菜单选项被按下
void Plugin_Base::onMenuActionClick(QAction* action,widgetMsg* widget)
{

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
