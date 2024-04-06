#include "Plugin_Button.h"
#include "QPushButton"


Plugin_Button::Plugin_Button()
{
    this->pluginTitle = "按钮";
    this->pluginTip = "一个基础按钮";
    this->pluginSign = "ButtonWidgetPlugin";
    this->pluginIco = QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Button_16x.png");
}


//获取默认组件实例
widgetMsg Plugin_Button::createWidgetInstance(QRect Geometry)
{
    widgetMsg t_msg;
    t_msg.objectName = "按钮";
    t_msg.pluginPtr = this;         //出席消息的插件
    t_msg.widget = new QPushButton;     //组件指针
    t_msg.isPack = false;           //是否为容器，如果为true，则
    t_msg.isSelect = true;          //是否被选择
    t_msg.attrs = {{
        "按钮标题",         //属性显示标题
        "title",           //属性响应类名
        "主窗口",           //属性初始值
        true               //属性可编辑
    }};
    t_msg.events = {        {
        "被点击",          //事件显示的标题
        "onClick",         //事件代码属性名
        "[=]()=>void"      //事件的lambda表达式
    }};

    if(Geometry.width() <= 0){Geometry.setWidth(80);}
    if(Geometry.height() <= 0){Geometry.setHeight(24);}

    ((QPushButton*)t_msg.widget)->setText("按钮");
    t_msg.widget->setGeometry(Geometry);
    return t_msg;
}


//根据组件指针与属性，调整此组件信息
void Plugin_Button::adjustWidget(QWidget *widget, QList<AttributeNode> &attrs)
{

}


//代码被创建
QString Plugin_Button::code_onWidgetBuild(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}


//代码属性赋值
QString Plugin_Button::code_onAttributeBuild(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}

//代码被销毁
QString Plugin_Button::code_onWidgetClose(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}
