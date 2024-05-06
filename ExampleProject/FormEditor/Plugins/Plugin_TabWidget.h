#ifndef PLUGIN_TABWIDGET
#define PLUGIN_TABWIDGET

#include "Plugin_Base.h"


class Plugin_TabWidget : public Plugin_Base
{
public:
    Plugin_TabWidget();

public:
    widgetMsg createWidgetInstance(QRect Geometry = QRect()) override;          //获取默认组件实例
    void adjustWidget(QWidget* widget,QList<AttributeNode>& attrs) override; //根据组件指针与属性，调整此组件信息
    QJsonValue getConfigure(widgetMsg& msg) override;  //获取配置文件
    void configAdjustWidgetMsg(widgetMsg& msg, QJsonValue config, Fun_Get_Widget fun_getWidget) override;   //配置文件调整组件信息
    QList<QAction*> getMenuAction() override;   //获取菜单选项

public:
    void onSubWidgetEnter(QWidget* packWidget,QWidget* subWidget) override;     //当子控件进入
    void onMenuActionClick(QAction* action,widgetMsg* widget) override;         //当菜单选项被点击

public:
    //代码被创建
    QString code_onWidgetBuild(QWidget* widget, QList<AttributeNode> attrs, QList<EventNode> events) override;
    //代码属性赋值
    QString code_onAttributeBuild(QWidget* widget, QList<AttributeNode> attrs, QList<EventNode> events) override;
    //代码被销毁
    QString code_onWidgetClose(QWidget* widget, QList<AttributeNode> attrs, QList<EventNode> events) override;

};

#endif // PLUGIN_TABWIDGET
