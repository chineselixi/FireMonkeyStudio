#ifndef WIDGET_BUTTON_HISTORYITEM_H
#define WIDGET_BUTTON_HISTORYITEM_H

#include <QWidget>

namespace Ui {
class Widget_Button_HistoryItem;
}

class Widget_Button_HistoryItem : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Button_HistoryItem(QWidget *parent = nullptr);
    ~Widget_Button_HistoryItem();


public:
    void setMsg(QPixmap ico, QString title, QString tip, QString path); //设置item信息



private slots:
    void on_pushButton_clicked();
    void on_pushButton_close_clicked();

private:
    Ui::Widget_Button_HistoryItem *ui;

protected:
    void enterEvent(QEnterEvent *event) override;            //进入QWidget瞬间事件
    void leaveEvent(QEvent *) override;                      //离开QWidget瞬间事件
    void mousePressEvent(QMouseEvent *event) override;       //摁住鼠标事件


signals:
    void itemClose(QString path);   //项目被关闭
    void itemClick(QString path);   //项目被点击

};

#endif // WIDGET_BUTTON_HISTORYITEM_H
