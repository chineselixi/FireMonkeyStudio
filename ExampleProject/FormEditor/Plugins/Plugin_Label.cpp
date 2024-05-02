#include "Plugin_Label.h"
#include "QLabel"
#include "QFont"

#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"

#include "util/FunUtil.h"

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
    t_msg.classSign = "QLabel";
    t_msg.pluginPtr = this;         //出席消息的插件
    t_msg.widget = new QLabel;     //组件指针
    t_msg.isPack = false;           //是否为容器，如果为true，则
    t_msg.isSelect = true;          //是否被选择
    t_msg.attrs = {
        {
            "标题",         //属性显示标题
            "基础",            //分类信息
            "title",           //属性响应类名
            "标签",           //属性初始值
            {},             //枚举选项
            true            //属性可编辑
        },
        {
            "字体",         //属性显示标题
            "基础",            //分类信息
            "font",           //属性响应类名
            QFont(),           //属性初始值
            {},             //枚举选项
            true            //属性可编辑
        },
        {
            "文字颜色",         //属性显示标题
            "颜色",            //分类信息
            "textColor",           //属性响应类名
            QColor(),           //属性初始值
            {},             //枚举选项
            true            //属性可编辑
        },
        {
            "使用背景颜色",         //属性显示标题
            "颜色",            //分类信息
            "useBackColor",           //属性响应类名
            false,           //属性初始值
            {},             //枚举选项
            true            //属性可编辑
        },
        {
            "背景颜色",         //属性显示标题
            "颜色",            //分类信息
            "backColor",           //属性响应类名
            QColor(),           //属性初始值
            {},             //枚举选项
            true            //属性可编辑
        },
    };

    if(Geometry.width() <= 0){Geometry.setWidth(54);}
    if(Geometry.height() <= 0){Geometry.setHeight(24);}

    ((QLabel*)t_msg.widget)->setText("标签");
    t_msg.widget->setGeometry(Geometry);
    return t_msg;
}


//根据组件指针与属性，调整此组件信息
void Plugin_Label::adjustWidget(QWidget *widget, QList<AttributeNode> &attrs)
{
    QLabel* t_label = dynamic_cast<QLabel*>(widget);
    if(!t_label) return;

    AttributeNode* t_attr = nullptr;
    t_attr = this->getListAttr(attrs,"基础","title");
    if(t_attr != nullptr){
        t_label->setText(t_attr->value.toString());
    }

    t_attr = this->getListAttr(attrs,"基础","font");
    if(t_attr != nullptr){
        t_label->setFont(t_attr->value.value<QFont>());
    }

    t_attr = this->getListAttr(attrs,"颜色","textColor");
    if(t_attr != nullptr){
        QString t_style = R"(
            #%1{
                color:%2;
            }
        )";
        t_label->setStyleSheet(t_style.arg(t_label->objectName()).arg(t_attr->value.value<QColor>().name()));
    }

    t_attr = this->getListAttr(attrs,"颜色","useBackColor");
    if(t_attr != nullptr){
        if(t_attr->value.toBool()){
            t_attr = this->getListAttr(attrs,"颜色","backColor");
            QString t_style = R"(
                #%1{
                    background-color:%2;
                }
            )";
            t_label->setStyleSheet(t_label->styleSheet() + t_style.arg(t_label->objectName()).arg(t_attr->value.value<QColor>().name()));
        }
    }
}

//获取配置文件
QJsonValue Plugin_Label::getConfigure(widgetMsg& msg)
{
    return QJsonObject();
}


//配置文件调整组件信息
void Plugin_Label::configAdjustWidgetMsg(widgetMsg &msg, QJsonValue config, Fun_Get_Widget fun_getWidget)
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
