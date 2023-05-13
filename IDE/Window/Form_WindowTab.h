#ifndef FORM_WINDOWTAB_H
#define FORM_WINDOWTAB_H

#include <QWidget>
#include "Plugin/Plugin_Global.h"

namespace Ui {
class Form_WindowTab;
}

class Form_WindowTab : public QWidget
{
    Q_OBJECT
public:


    struct tabMsg{
        QString title;    //标题文本
        QString signText; //标记文本
        QWidget* formPth = nullptr; //窗口指针
        QWidget* tabWidgetPth = nullptr; //Tab窗体指针，此包含布局
        PluginGlobalMsg::TabType type = PluginGlobalMsg::TabType::form;
    };

public:
    explicit Form_WindowTab(QWidget *parent = nullptr);
    ~Form_WindowTab();




private slots:
    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::Form_WindowTab *ui;
    QVector<tabMsg> tabMsgList; //选项卡信息列表

public:
    void addTabWidget(QString title,QWidget* form,QString sign,QIcon titeIco,bool select = true,PluginGlobalMsg::TabType type = PluginGlobalMsg::TabType::form); //添加窗体到Tab
    bool removeTabMsg(QWidget* form); //根据widget指针标记删除列表信息
    bool removeTabMsg(QString sign); //根据sign标记删除列表信息
    bool resetTabMsg(QString oldSign,tabMsg newMsg); //根据标记更改信息
    bool resetTabMsg(QWidget* oldWidget,tabMsg newMsg); //根据窗体指针更改信息
    bool hasTabMsg(QString sign,bool select = false); //根据标记查看TAB是否已经存在
    bool hasTabMsg(QWidget* widget,bool select = false); //根据Widgte指针查看TAB是否已经存在

    tabMsg getMsg(QString sign); //根据标记获取信息
    tabMsg getMsg(QWidget* widget); //根据窗体指针获取信息
};

#endif // FORM_WINDOWTAB_H
