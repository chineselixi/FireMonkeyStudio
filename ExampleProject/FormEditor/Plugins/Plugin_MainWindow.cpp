
#include "Plugin_MainWindow.h"
#include "QLayout"

#include "QPushButton"

Plugin_MainWindow::Plugin_MainWindow()
{
    this->pluginTitle = "窗体";
    this->pluginTip = "用于存储基础组件容器窗口";
    this->pluginSign = "WindowWidgetPlugin";
    this->pluginIco = QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/OpenfileDialog_16x.png");
}


//获取默认组件实例
widgetMsg Plugin_MainWindow::createWidgetInstance(QRect Geometry)
{
    widgetMsg t_msg;
    t_msg.objectName = "窗体";
    t_msg.pluginPtr = this;
    t_msg.widget = new QWidget;
    t_msg.isPack = true;
    t_msg.isSelect = true;
    t_msg.attrs = {{
        "窗口标题",         //属性显示标题
        "windowTitle",     //属性响应类名
        "主窗口",           //属性初始值
        true               //属性可编辑
    }};
    t_msg.events = {        {
        "创建完毕",         //事件显示的标题
        "onBuild",         //事件代码属性名
        "[=]()=>void"      //事件的lambda表达式
    }};

    if(Geometry.width() == 0){Geometry.setWidth(450);}
    if(Geometry.height() == 0){Geometry.setHeight(320);}

    t_msg.widget->setGeometry(Geometry);
    return t_msg;
}


//根据组件指针与属性，调整此组件信息
void Plugin_MainWindow::adjustWidget(QWidget *widget, QList<AttributeNode> &attrs)
{

}


//子控件进入(参数1为容器控件，是本插件插件的。参数2为进入的子控件)
void Plugin_MainWindow::subWidgetEnter(QWidget* packWidget,QWidget* subWidget)
{
    if(packWidget && subWidget){
        subWidget->setParent(packWidget);
        subWidget->show();
        subWidget->raise();
    }
}


//代码被创建
QString Plugin_MainWindow::code_onWidgetBuild(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}


//代码属性赋值
QString Plugin_MainWindow::code_onAttributeBuild(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}

//代码被销毁
QString Plugin_MainWindow::code_onWidgetClose(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}

