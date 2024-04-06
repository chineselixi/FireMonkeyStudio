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
