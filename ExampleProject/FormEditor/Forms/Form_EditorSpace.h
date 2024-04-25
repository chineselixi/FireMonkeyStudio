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
    //树节点信息
    struct treeNode{
        widgetMsg msg;
        QTreeWidgetItem* treeItem = nullptr;
    };

private:
    QString editorSpaceSign = "";       //编辑器标记，用于区分多个编辑器
    Form_Roi* roiWidget = nullptr;      //选区绘画窗口指针
    widgetMsg baseWidget;               //基础底层控件
    QList<widgetMsg> widgets;           //编辑器内的控件列表
    QList<treeNode> treeMsgList;        //树节点信息
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

private:
    void buildTreeWidgetItem(widgetMsg msg,bool isRoot = false);    //创建树组件节点
    QWidget* getWidgetToItem(QTreeWidgetItem* item);   //根据treeItem获取关联Widget信息
    void setRootTreeItem(QWidget* baseParent); //设置树根
    QTreeWidgetItem* getWidgetParentTreeItemPtr(QWidget* widget); //获取Widget父组件的treeItem指针
    void adjustTreeItem(); //调整树item
    void selectTreeItem(QList<QWidget *> widgets);  //根据组件列表选择对于的treeItem
    void selectTreeItem(QList<widgetMsg> widgets);  //根据组件列表选择对于的treeItem
    void showProperty(); //显示属性
    widgetMsg* getWidgetMsg(QWidget* widget);   //获取Widget信息指针

public:
    void event_onMdiAreaScrollChange(int dx, int dy); //当MdiArea滚动改变
    void event_onMdiAreaReSize(QResizeEvent *resizeEvent); //当MdiArea尺寸改变
    void event_onObjectRename(QWidget* widget,QString newName); //设置对象新名称

private slots:
    //矩形选择器槽函数
    void ROI_onSubWidgetsChanged(QWidget* parentWidget);   //当ROI控件有子控件加入
    void ROI_onWidgetSelected(QList<QWidget*> widgets);    //当ROI控件被选择，参数：选择的控件列表
    void ROI_onWidgetMove(QList<QWidget*> widgets);         //当控件移动
    void ROI_onWidgetBaseGeometryChanged(QRect rect);       //baseWidget尺寸改变
    void ROI_onWidgetGeometryChanged(QWidget* widget);      //组件尺寸改变

    //属性编辑器槽函数
    void PRO_onWidgetNameChange(QString editorSpaceSign,widgetMsg* updateWidgetMessage,QString& newName);    //目标控件对象名称被改变
    void PRO_onWidgetUpdate(QString editorSpaceSign,widgetMsg* updateWidgetMessage);                        //控件属性被更新


    void on_splitter_splitterMoved(int pos, int index);//分割条比例调整
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column); //当TreeItem被点击

private:
    Ui::Form_EditorSpace *ui;

    void resizeEvent(QResizeEvent* event) override;     //窗体尺寸被改变

};

#endif // FORM_EDITORSPACE_H
