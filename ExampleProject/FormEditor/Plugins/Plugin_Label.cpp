#include "Plugin_Label.h"
#include "QLabel"


Plugin_Label::Plugin_Label()
{
    this->pluginTitle = "标签";
    this->pluginTip = "文字标签，主要用于显示文本";
    this->pluginSign = "LabelWidgetPlugin";
    this->pluginIco = QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Label_16x.png");
}


//获取默认组件实例
widgetMsg Plugin_Label::createWidgetInstance(QRect Geometry)
{
    widgetMsg t_msg;
    t_msg.objectName = "标签";
    t_msg.pluginPtr = this;         //出席消息的插件
    t_msg.widget = new QLabel;     //组件指针
    t_msg.isPack = false;           //是否为容器，如果为true，则
    t_msg.isSelect = true;          //是否被选择
    t_msg.attrs = {{
        "标题",         //属性显示标题
        "title",           //属性响应类名
        "标签",           //属性初始值
        true               //属性可编辑
    }};

    if(Geometry.width() <= 0){Geometry.setWidth(54);}
    if(Geometry.height() <= 0){Geometry.setHeight(24);}

    ((QLabel*)t_msg.widget)->setText("标签");
    t_msg.widget->setGeometry(Geometry);
    return t_msg;
}


//根据组件指针与属性，调整此组件信息
void Plugin_Label::adjustWidget(QWidget *widget, QList<AttributeNode> &attrs)
{

}


//代码被创建
QString Plugin_Label::code_onWidgetBuild(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}


//代码属性赋值
QString Plugin_Label::code_onAttributeBuild(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}

//代码被销毁
QString Plugin_Label::code_onWidgetClose(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}
