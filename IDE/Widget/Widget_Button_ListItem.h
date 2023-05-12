#ifndef WIDGET_BUTTON_LISTITEM_H
#define WIDGET_BUTTON_LISTITEM_H

#include <QWidget>

namespace Ui {
class Widget_Button_ListItem;
}

class Widget_Button_ListItem : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Button_ListItem(QWidget *parent = nullptr);
    explicit Widget_Button_ListItem(QPixmap ico,QString title,QString text,QString date,QWidget *parent = nullptr);
    ~Widget_Button_ListItem();



public:
    void SetIcon(QPixmap ico,QSize icoSize = QSize(32,32)); //设置图标样式
    void SetTitle(QString text); //设置大标题
    void SetTip(QString text); //设置小标题
    void SetDate(QString date); //设置日期

    QString GetTitle(); //获取标题
    QString GetTip(); //获取提示信息
    QString GetDate(); //获取日期信息

private:
    Ui::Widget_Button_ListItem *ui;

private:
    void mousePressEvent(QMouseEvent *event);// 当按钮被按下,重写

signals://使用signals声明信号函数，访问级别为protected
    void onDown();//被按下信号
};

#endif // WIDGET_BUTTON_LISTITEM_H
