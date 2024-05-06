
#include "Plugin_MainWindow.h"
#include "QLayout"

#include "QPushButton"

#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"
#include "QLayout"

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
    t_msg.classSign = "QWidget";
    t_msg.pluginPtr = this;
    t_msg.widget = new QWidget;
    t_msg.isPack = true;
    t_msg.isSelect = true;
    t_msg.attrs = {{
        "窗口标题",         //属性显示标题
        "基础",              //分类信息
        "windowTitle",     //属性响应类名
        "窗口",           //属性初始值
        {},             //枚举选项
        true,            //属性可编辑
    },
    {
        "布局",         //属性显示标题
        "对其方式",              //分类信息
        "layout",     //属性响应类名
        "无布局",           //属性初始值
        {"无布局","垂直布局","水平布局","网格布局","表单布局"},             //枚举选项
        true,            //属性可编辑
    },
    {"左边距","对其方式","leftMargin",0,{},false},
    {"右边距","对其方式","rightMargin",0,{},false},
    {"上边距","对其方式","topMargin",0,{},false},
    {"底边距","对其方式","bottomMargin",0,{},false},
    {"水平间距","对其方式","horizontalSpacing",6,{},false},
    {"垂直间距","对其方式","verticalSpacing",6,{},false},
    };
    t_msg.events = {        {
        "创建完毕",         //事件显示的标题
        "onBuild",         //事件代码属性名
        "[=]()=>void"      //事件的lambda表达式
    }};

    if(Geometry.width() == 0){Geometry.setWidth(200);}
    if(Geometry.height() == 0){Geometry.setHeight(150);}

    t_msg.widget->setGeometry(Geometry);
    return t_msg;
}


//根据组件指针与属性，调整此组件信息
void Plugin_MainWindow::adjustWidget(QWidget *widget, QList<AttributeNode> &attrs)
{
    QWidget* t_widget = dynamic_cast<QWidget*>(widget);
    if(!t_widget) return;

    AttributeNode* t_attr = nullptr;
    t_attr = this->getListAttr(attrs,"基础","windowTitle");
    if(t_attr != nullptr){
        t_widget->setWindowTitle(t_attr->value.toString());
    }
    t_attr = this->getListAttr(attrs,"对其方式","layout");

    if(t_attr != nullptr){
        QString t_layoutStr = t_attr->value.toString();
        QList<QWidget*> t_subWidgets = t_widget->findChildren<QWidget*>(Qt::FindDirectChildrenOnly);

        if(t_layoutStr == "无布局"){
            delete t_widget->layout();

        }
        else if(t_layoutStr == "垂直布局"){
            delete t_widget->layout();
            QVBoxLayout* t_vbl = new QVBoxLayout(t_widget);
            //按照顶部排序
            for(qsizetype a = 0; a<t_subWidgets.length(); a++){
                for(qsizetype b = 0; b<t_subWidgets.length() - a - 1; b++){
                    if(t_subWidgets[b]->geometry().top() > t_subWidgets[b + 1]->geometry().top()){
                        QWidget* t_w;
                        t_w = t_subWidgets[b];
                        t_subWidgets[b] = t_subWidgets[b + 1];
                        t_subWidgets[b + 1] = t_w;
                    }
                }
            }
            for(qsizetype i = 0; i<t_subWidgets.length(); i++){
                t_vbl->addWidget(t_subWidgets[i],1);
            }
        }
        else if(t_layoutStr == "水平布局"){
            delete t_widget->layout();
            QHBoxLayout* t_hbl = new QHBoxLayout(t_widget);
            //按照顶部排序
            for(qsizetype a = 0; a<t_subWidgets.length(); a++){
                for(qsizetype b = 0; b<t_subWidgets.length() - a - 1; b++){
                    if(t_subWidgets[b]->geometry().left() > t_subWidgets[b + 1]->geometry().left()){
                        QWidget* t_w;
                        t_w = t_subWidgets[b];
                        t_subWidgets[b] = t_subWidgets[b + 1];
                        t_subWidgets[b + 1] = t_w;
                    }
                }
            }
            for(qsizetype i = 0; i<t_subWidgets.length(); i++){
                t_hbl->addWidget(t_subWidgets[i],1);
            }
        }
        else if(t_layoutStr == "网格布局"){

        }
        else if(t_layoutStr == "表单布局"){

        }

    }
}


//子控件进入(参数1为容器控件，是本插件插件的。参数2为进入的子控件)
void Plugin_MainWindow::onSubWidgetEnter(QWidget* packWidget,QWidget* subWidget)
{
    if(packWidget && subWidget){
        subWidget->setParent(packWidget);
        subWidget->show();
        subWidget->raise();
    }
}


//获取配置文件
QJsonValue Plugin_MainWindow::getConfigure(widgetMsg& msg)
{
    QJsonValue t_retValue;
    QWidget* t_widget = dynamic_cast<QWidget*>(msg.widget);

    if(t_widget != nullptr){
        QJsonArray t_jsonArray;

        QList<QWidget*> t_subWidgets = t_widget->findChildren<QWidget*>(Qt::FindDirectChildrenOnly);
        for(QWidget* currSub : t_subWidgets){
            if(!currSub->objectName().isEmpty()){
                t_jsonArray.append(currSub->objectName());
            }
        }
        t_retValue = t_jsonArray;
    }
    return t_retValue;
}


//配置文件调整组件信息
void Plugin_MainWindow::configAdjustWidgetMsg(widgetMsg &msg, QJsonValue config, Fun_Get_Widget fun_getWidget)
{
    QWidget* t_widget = dynamic_cast<QWidget*>(msg.widget);    //转换为TabWidget
    if(t_widget != nullptr){
        QJsonArray t_jsonArray = config.toArray();
        for(QJsonValue value : t_jsonArray){
            QWidget* t_subWidget = fun_getWidget(value.toString());
            if(t_subWidget){
                t_subWidget->setParent(t_widget);
            }
        }
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

