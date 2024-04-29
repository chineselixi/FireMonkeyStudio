#include "Plugin_TabWidget.h"
#include "QTabWidget"

#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"

#include "util/FunUtil.h"

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
    t_msg.classSign = "QTabWidget";
    t_msg.pluginPtr = this;         //出席消息的插件
    t_msg.widget = new QTabWidget;     //组件指针
    t_msg.isPack = true;           //是否为容器，如果为true，则
    t_msg.isSelect = true;          //是否被选择
    t_msg.attrs = {
        {
            "当前索引",         //属性显示标题
            "基础",            //分类信息
            "tabIndex",         //属性响应类名
            0,                //属性初始值
            {},             //枚举选项
            true            //属性可编辑
        },
        {
            "TAB标题",         //属性显示标题
            "基础",            //分类信息
            "tabTitle",         //属性响应类名
            "子夹1",                //属性初始值
            {},             //枚举选项
            true            //属性可编辑
        }
    };
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
    //转换TAB，如果转换失败，则不调整
    QTabWidget* t_tab = dynamic_cast<QTabWidget*>(widget);
    if(t_tab == nullptr) return;

    AttributeNode* t_attr = nullptr;
    t_attr = this->getListAttr(attrs,"基础","tabIndex");
    if(t_attr != nullptr){
        if(t_attr->value.toInt() != t_tab->currentIndex()){ //不是当前的选项卡才进行选择
            t_tab->setCurrentIndex(t_attr->value.toInt());
            t_attr->value.setValue(t_tab->currentIndex());
            t_attr = this->getListAttr(attrs,"基础","tabTitle");
            if(t_attr != nullptr){
                t_attr->value.setValue(t_tab->tabText(t_tab->currentIndex()));
            }
        }
    }

    t_attr = this->getListAttr(attrs,"基础","tabTitle");
    if(t_attr != nullptr){
        t_tab->setTabText(t_tab->currentIndex(),t_attr->value.toString());
    }

}


//子控件加入
void Plugin_TabWidget::subWidgetEnter(QWidget *packWidget, QWidget *subWidget)
{
    if(packWidget && subWidget){
        QTabWidget* t_tabWidget = dynamic_cast<QTabWidget*>(packWidget);
        if(t_tabWidget == nullptr)return;
        QWidget* t_currenWidget = t_tabWidget->currentWidget(); //获取当前的widget
        if(t_currenWidget == nullptr) return;

        subWidget->setParent(t_currenWidget);

        QRect t_rec;
        if(FunUtil::getWidgetRelativePosition(t_currenWidget,packWidget,t_rec)){
            subWidget->move(subWidget->x() - t_rec.x(),subWidget->y() - t_rec.y());
        }
    }
}


//获取配置文件
QJsonObject Plugin_TabWidget::getConfigure(widgetMsg& msg)
{
    return QJsonObject();
}

//配置文件调整组件信息
void Plugin_TabWidget::configAdjustWidgetMsg(widgetMsg &msg, QJsonObject config, Fun_Get_Widget fun_getWidget)
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
