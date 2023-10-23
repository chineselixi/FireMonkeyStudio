#ifndef FORM_SETTINGS_COMPILE_H
#define FORM_SETTINGS_COMPILE_H

#include <QWidget>
#include "../../IDE/module/mod_settingsFormBase.h"

namespace Ui {
class Form_settings_Compile;
}

class Form_settings_Compile : public QWidget,public mod_settingsFormBase
{
    Q_OBJECT

public:
    explicit Form_settings_Compile(QWidget *parent = nullptr);
    ~Form_settings_Compile();


    //基本事件
    void Event_Ok() override; //确认键被按下
    void Event_cancel() override; //取消键被按下
    void Event_use() override; //应用键被按下

private:
    Ui::Form_settings_Compile *ui;
};

#endif // FORM_SETTINGS_COMPILE_H
