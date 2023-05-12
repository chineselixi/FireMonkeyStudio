#ifndef WIDGET_BUTTON_START_H
#define WIDGET_BUTTON_START_H

#include <QWidget>

namespace Ui {
class Widget_Button_Start;
}

class Widget_Button_Start : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Button_Start(QWidget *parent = nullptr);
    explicit Widget_Button_Start(QPixmap ico,QString title,QString text,QWidget *parent = nullptr);
    ~Widget_Button_Start();

private:
    Ui::Widget_Button_Start *ui;
public:
    void SetIcon(QPixmap ico,QSize icoSize = QSize(48,48)); //设置图标样式
    void SetTitle(QString text); //设置大标题
    void SetTip(QString text); //设置小标题
private:
    void mousePressEvent(QMouseEvent *event);// 当按钮被按下,重写

signals://使用signals声明信号函数，访问级别为protected
    void onDown();//被按下信号
};

#endif // WIDGET_BUTTON_START_H
