#ifndef WIDGET_BUTTON_MODHISTORYITEM_H
#define WIDGET_BUTTON_MODHISTORYITEM_H

#include <QWidget>

namespace Ui {
class Widget_Button_ModHistoryItem;
}

class Widget_Button_ModHistoryItem : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Button_ModHistoryItem(QWidget *parent = nullptr);
    explicit Widget_Button_ModHistoryItem(QPixmap ico,QString title,QString modStr,QString date,QWidget *parent = nullptr);
    ~Widget_Button_ModHistoryItem();

private:
    Ui::Widget_Button_ModHistoryItem *ui;

public:
    void SetIcon(QPixmap ico,QSize icoSize = QSize(20,20)); //设置图标样式
    void SetTitle(QString text); //设置大标题
    void SetModStr(QString text); //设置模板语言


private:
    void mousePressEvent(QMouseEvent *event);// 当按钮被按下,重写

signals://使用signals声明信号函数，访问级别为protected
    void onDown();//被按下信号
};

#endif // WIDGET_BUTTON_MODHISTORYITEM_H
