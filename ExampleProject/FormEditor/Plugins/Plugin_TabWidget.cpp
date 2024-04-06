#include "Plugin_TabWidget.h"
#include "QTabWidget"


Plugin_TabWidget::Plugin_TabWidget()
{
    this->pluginTitle = "选择夹";
    this->pluginTip = "可用于不同组件在不同子夹之间切换";
    this->pluginSign = "TabWidgetPlugin";
    this->pluginIco = QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Tab_16x.png");
}


//获取默认组件实例
widgetMsg Plugin_TabWidget::createWidgetInstance(QRect Geometry)
{
    widgetMsg t_msg;
    t_msg.objectName = "选择夹";
    t_msg.pluginPtr = this;         //出席消息的插件
    t_msg.widget = new QTabWidget;     //组件指针
    t_msg.isPack = true;           //是否为容器，如果为true，则
    t_msg.isSelect = true;          //是否被选择
    t_msg.attrs = {{
        "当前索引",         //属性显示标题
        "tabIndex",           //属性响应类名
        "0",           //属性初始值
        true               //属性可编辑
    }};
    t_msg.events = {        {
        "选择夹被切换",          //事件显示的标题
        "onSwitch",         //事件代码属性名
        "[=](int index)=>void"      //事件的lambda表达式
    }};

    if(Geometry.width() <= 0){Geometry.setWidth(127);}
    if(Geometry.height() <= 0){Geometry.setHeight(80);}

    QTabWidget* t_tabWidget = (QTabWidget*)t_msg.widget;
    t_tabWidget->addTab(new QWidget,"子夹1");
    t_tabWidget->addTab(new QWidget,"子夹2");

    t_msg.widget->setGeometry(Geometry);
    return t_msg;
}


//根据组件指针与属性，调整此组件信息
void Plugin_TabWidget::adjustWidget(QWidget *widget, QList<AttributeNode> &attrs)
{

}


//代码被创建
QString Plugin_TabWidget::code_onWidgetBuild(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}


//代码属性赋值
QString Plugin_TabWidget::code_onAttributeBuild(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}

//代码被销毁
QString Plugin_TabWidget::code_onWidgetClose(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}
