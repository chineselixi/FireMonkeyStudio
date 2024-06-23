#ifndef FORM_SETTINGS_CLANGD_H
#define FORM_SETTINGS_CLANGD_H

#include <QWidget>
#include "../../IDE/module/mod_settingsFormBase.h"
#include "../../Plugin_CppBase_global.h"

namespace Ui {
class Form_settings_Clangd;
}

class Plugin_CppBase;

class Form_settings_Clangd : public QWidget,public mod_settingsFormBase
{
    Q_OBJECT

private:
    Ui::Form_settings_Clangd *ui;
    Plugin_CppBase* pluginPtr;

public:
    explicit Form_settings_Clangd(Plugin_CppBase* pluginP,QWidget *parent = nullptr);
    ~Form_settings_Clangd();

    //基本事件
    void Event_Ok() override; //确认键被按下
    void Event_cancel() override; //取消键被按下
    void Event_use() override; //应用键被按下


};

#endif // FORM_SETTINGS_CLANGD_H
