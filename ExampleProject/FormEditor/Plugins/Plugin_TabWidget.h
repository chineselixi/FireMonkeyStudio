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
    void subWidgetEnter(QWidget* packWidget,QWidget* subWidget) override;   //子控件进入

public:
    //代码被创建
    QString code_onWidgetBuild(QWidget* widget, QList<AttributeNode> attrs, QList<EventNode> events) override;
    //代码属性赋值
    QString code_onAttributeBuild(QWidget* widget, QList<AttributeNode> attrs, QList<EventNode> events) override;
    //代码被销毁
    QString code_onWidgetClose(QWidget* widget, QList<AttributeNode> attrs, QList<EventNode> events) override;

};

#endif // PLUGIN_TABWIDGET
