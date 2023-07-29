#ifndef FORM_SYSTEMSETTINGS_H
#define FORM_SYSTEMSETTINGS_H

#include <QWidget>
#include "Widget/Widget_Button_WidgetItem.h"
#include "QList"
#include "QListWidgetItem"

namespace Ui {
class Form_SystemSettings;
}

class Form_SystemSettings : public QWidget
{
    Q_OBJECT

private:
    //设置标记结构体
    struct set_sign{
        Widget_Button_WidgetItem* btn_sign;
        QListWidgetItem* listWidget;
        QWidget* form;
        int widgetIndex;
    };

private:
    Ui::Form_SystemSettings *ui;
    QList<set_sign> setMsgList; //设置标记信息列表

public:
    explicit Form_SystemSettings(QWidget *parent = nullptr);
    ~Form_SystemSettings();

    int addSetItem(QString title,QPixmap pixmap,QWidget* widget); //将Widget添加到设置项



private slots:
    void on_pushButton_ok_clicked(); //确认按钮
    void on_pushButton_cancel_clicked(); //取消按钮
    void on_pushButton_use_clicked(); //应用按钮
};

#endif // FORM_SYSTEMSETTINGS_H
