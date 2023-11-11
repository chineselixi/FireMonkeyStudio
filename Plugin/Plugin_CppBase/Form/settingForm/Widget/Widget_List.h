#ifndef WIDGET_LIST_H
#define WIDGET_LIST_H

#include <QWidget>

namespace Ui {
class Widget_List;
}

class Widget_List : public QWidget
{
    Q_OBJECT
private:
    QVector<QString> list;


private:
    void arrangeList(); //去重整理
    void flashUI(); //更新列表
    void addNode(QString sign); //添加信息
    void removeNode(QString sign); //删除信息

public:
    explicit Widget_List(QWidget *parent = nullptr);
    ~Widget_List();

    void setList(QVector<QString> list); //添加列表到UI
    QVector<QString> getList(); //获取列表




private slots:
    void on_btnAdd_clicked(); //添加按钮被按下
    void on_btnDelete_clicked(); //删除按钮被按下

private:
    Ui::Widget_List *ui;
};

#endif // WIDGET_LIST_H
