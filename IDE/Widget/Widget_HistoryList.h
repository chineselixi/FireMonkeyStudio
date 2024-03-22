#ifndef WIDGET_HISTORYLIST_H
#define WIDGET_HISTORYLIST_H

#include <QWidget>

namespace Ui {
class Widget_HistoryList;
}

class Widget_HistoryList : public QWidget
{
    Q_OBJECT
public:
    struct itemMsg{
        QPixmap ico;
        QString title;
        QString tip;
        QString path;
    };

public:
    explicit Widget_HistoryList(QWidget *parent = nullptr);
    ~Widget_HistoryList();

    void addItem(itemMsg item);            //添加item
    void addItems(QList<itemMsg> items);   //添加多个item
    void deleteItem(QString path);         //根据path删除item
    void deleteAll();                      //删除所有的item

private slots:
    void on_pushButton_clear_clicked(); //清理全部被点击


signals:
    void event_onProjectOpen(QString path);     //打开工程


private:
    Ui::Widget_HistoryList *ui;
};

#endif // WIDGET_HISTORYLIST_H
