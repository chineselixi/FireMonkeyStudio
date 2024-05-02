
#ifndef PLUGIN_BASE_H
#define PLUGIN_BASE_H

#include "QWidget"
#include "QList"
#include "../GlobalMsg.h"

typedef std::function<QWidget*(QString objName)> Fun_Get_Widget;

class Plugin_Base
{
public:
    QString pluginTitle = "默认控件";    //插件在组件箱的标题
    QString pluginTip = "默认的控件";    //插件在组件箱的提示
    QString pluginSign = "null";   //插件插件类标记
    QPixmap pluginIco;                  //插件图标

public:
    AttributeNode* getListAttr(QList<AttributeNode> &attrs,QString group,QString attrSign);  //从列表获取属性指针
    static QJsonValue attributesToJson(QList<AttributeNode> attrs); //将属性转换为Json对象
    static QList<AttributeNode> jsonArrayToAttrs(QJsonArray jsonArray); //将jsonArray转换为attrs
    static QVariant jsonvalueToVariant(QJsonValue jsonValue, QMetaType::Type type); //将jsonValue转换为QVariant

    virtual widgetMsg createWidgetInstance(QRect Geometry = QRect()) = 0;   //创建一个控件实例
    virtual void adjustWidget(QWidget* widget,QList<AttributeNode>& attrs) = 0; //根据组件指针与属性，调整此组件信息

    virtual QJsonValue getConfigure(widgetMsg& msg) = 0; //获取保存的配置文件
    virtual void configAdjustWidgetMsg(widgetMsg& msg, QJsonValue config, Fun_Get_Widget fun_getWidget) = 0;   //配置文件调整组件信息


    //子控件进入(参数1为容器控件，是本插件插件的。参数2为进入的子控件)
    virtual void subWidgetEnter(QWidget* packWidget,QWidget* subWidget);
    //系统获取插件的右键菜单
    virtual QList<QAction*> getMenuAction();
    //菜单选项被按下
    virtual void onMenuActionClick(QAction* action,widgetMsg* widget);

    //组件创建返回的代码
    virtual QString code_onWidgetBuild(QWidget* widget, QList<AttributeNode> attrs, QList<EventNode> events);
    //组件属性赋值返回的代码
    virtual QString code_onAttributeBuild(QWidget* widget, QList<AttributeNode> attrs, QList<EventNode> events);
    //组件销毁返回的代码
    virtual QString code_onWidgetClose(QWidget* widget, QList<AttributeNode> attrs, QList<EventNode> events);
};

#endif // PLUGIN_BASE_H
