#ifndef WIDGET_BUTTON_WIDGETITEM_H
#define WIDGET_BUTTON_WIDGETITEM_H

#include <QWidget>

namespace Ui {
class Widget_Button_WidgetItem;
}

class Widget_Button_WidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Button_WidgetItem(QWidget *parent = nullptr);
    explicit Widget_Button_WidgetItem(QPixmap pixmap, QString title, QString sign,QWidget *parent = nullptr);
    ~Widget_Button_WidgetItem();

private:
    Ui::Widget_Button_WidgetItem *ui;
    QString Sign = "";

public:
    void SetIcon(QPixmap pixmap,QSize icoSize = QSize(16,16)); //设置图标样式
    void SetTitle(QString text); //设置标题
    void SetSign(QString text); //设置小标题
    QString GetTitle(); //获取标题
    QString GetSign(); //获取标记
};

#endif // WIDGET_BUTTON_WIDGETITEM_H
