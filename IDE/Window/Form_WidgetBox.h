#ifndef FORM_WIDGETBOX_H
#define FORM_WIDGETBOX_H

#include <QWidget>

namespace Ui {
class Form_WidgetBox;
}

class Form_WidgetBox : public QWidget
{
    Q_OBJECT

public:
    explicit Form_WidgetBox(QWidget *parent = nullptr);
    ~Form_WidgetBox();

private:
    Ui::Form_WidgetBox *ui;

public:
    QSize sizeHint() const; //重写获取尺寸的函数，这样在QDockWidget下就可以自定义宽高了
    void addItem(QPixmap pixmap,QString title,QString sign); //添加项目

signals://使用signals声明信号函数，访问级别为protected
    void onItemDown(QString title,QString sign);//被按下信号

};

#endif // FORM_WIDGETBOX_H
