#ifndef FORM_EDITORSPACE_H
#define FORM_EDITORSPACE_H

#include <QWidget>
#include "QMainWindow"
#include "ui_Form_EditorSpace.h"
#include "Form_Roi.h"
#include "GlobalMsg.h"
#include "Plugins/Plugin_Base.h"

namespace Ui {
class Form_EditorSpace;
}

class Form_EditorSpace : public QWidget
{
    Q_OBJECT

private:
    Form_Roi* roiWidget = nullptr;      //选区绘画窗口指针
    widgetMsg baseWidget;               //基础底层控件
    QList<widgetMsg> widgets;           //编辑器内的控件列表
    QMdiSubWindow* baseSubWindow;       //编辑器的主窗口

public:
    explicit Form_EditorSpace(QWidget *parent = nullptr);
    ~Form_EditorSpace();

public:
    //根据一个初始名字，在列表中获取唯一不重复的名字
    QString getUniqueName(QString baseName);
    //创建插件，并且加入到列表
    QWidget* createWidgetMsgToList(Plugin_Base* pluginPtr,          //预创建插件的指针
                                   QRect geometry,                  //需要创建控件的矩形
                                   Plugin_Base* parentPluginPtr,    //父插件的的指针
                                   QWidget* parentWidget);          //父控件的指针
    //获取控件信息列表
    QList<widgetMsg>& getWidgetMsgs();
    //获取编辑容器控件指针
    QWidget* getEditorSpaceWidgetPtr();
    //获取基础控件信息
    widgetMsg& getBaseWidgetMsg();


public:
    void event_onMdiAreaScrollChange(int dx, int dy); //当MdiArea滚动改变
    void event_onMdiAreaReSize(QResizeEvent *resizeEvent); //当MdiArea尺寸改变
    void event_onTreeItemClick(QWidget* widget); //当TreeItem被点击
    void event_onObjectRename(QWidget* widget,QString newName); //设置对象新名称

private slots:
    void on_splitter_splitterMoved(int pos, int index);//分割条比例调整
    void onParentBaseWidgetGeometryChanged(QRect rect);   //baseWidget尺寸改变


private:
    Ui::Form_EditorSpace *ui;

    void resizeEvent(QResizeEvent* event) override;     //窗体尺寸被改变

};

#endif // FORM_EDITORSPACE_H
