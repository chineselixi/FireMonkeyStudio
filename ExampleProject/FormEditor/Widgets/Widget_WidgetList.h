#ifndef WIDGET_WIDGETLIST_H
#define WIDGET_WIDGETLIST_H

#include <QWidget>
#include "QTreeWidgetItem"

namespace Ui {
class Widget_widgetList;
}

class Widget_widgetList : public QWidget
{
    Q_OBJECT

    struct itemMsg{
        QWidget* widgetItem = nullptr;
        QTreeWidgetItem* treeItem = nullptr;
        QString title = "NULL";
        QString classTitle = "NoClass";
    };


public:
    explicit Widget_widgetList(QWidget *parent = nullptr);
    ~Widget_widgetList();

private:
    QVector<itemMsg> itemList;
    QTreeWidgetItem* baseItem;

public:
    void addBaseItem(QWidget* widgetItem,QIcon ico,QString title,QString classTitle); //添加根节点
    void addItem(QWidget* widgetItem,QIcon ico,QString title,QString classTitle); //添加项目
    void removeItem(QWidget* widgetItem); //移除项目
    void selectItem(QWidget* widgetItem); //选择Item
    void changeItemTitle(QWidget* widgetItem,QString newTitle); //更改项目名称
    void changeItemClassTitle(QWidget* widgetItem,QString newClassTitle); //更改类名称



signals:
    void event_Menu_onItemRemove(QWidget* item); //菜单选择删除这个项目，只是通知，不做任何更改
    void event_onItemClick(QWidget* item); //当列表的项目被点击


private slots:
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::Widget_widgetList *ui;
};

#endif // WIDGET_WIDGETLIST_H
