#ifndef WIDGET_BUTTON_MODITEM_H
#define WIDGET_BUTTON_MODITEM_H

#include <QWidget>

namespace Ui {
class Widget_Button_ModItem;
}

class Widget_Button_ModItem : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Button_ModItem(QWidget *parent = nullptr);
    explicit Widget_Button_ModItem(QPixmap ico,QString title,QString tip,QString langTip,QString osTip,QString otherTip,QWidget *parent = nullptr);
    ~Widget_Button_ModItem();

private:
    Ui::Widget_Button_ModItem *ui;

public:
    void SetIcon(QPixmap ico,QSize icoSize = QSize(48,48)); //设置图标样式
    void SetTitle(QString text); //设置大标题
    void SetTip(QString text); //设置模板提示
    void SetLangTip(QString text);//设置语言提示文本
    void SetOsTip(QString text);//设置OS提示文本
    void SetOtherTip(QString text);//设置其他提示文本


private:
    void mousePressEvent(QMouseEvent *event);// 当按钮被按下,重写

signals://使用signals声明信号函数，访问级别为protected
    void onDown();//被按下信号

};

#endif // WIDGET_BUTTON_MODITEM_H
