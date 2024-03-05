#ifndef FORM_SETTINGS_PROJECTMANGER_H
#define FORM_SETTINGS_PROJECTMANGER_H

#include <QWidget>
#include "module/mod_settingsFormBase.h"


namespace Ui {
class Form_settings_ProjectManger;
}

class Form_settings_ProjectManger : public QWidget,public mod_settingsFormBase
{
    Q_OBJECT

public:
    explicit Form_settings_ProjectManger(QWidget *parent = nullptr);
    ~Form_settings_ProjectManger();

    static void loadSettings(); //静态加载设置

    void Event_Ok() override; //确认键被按下
    void Event_cancel() override; //取消键被按下
    void Event_use() override; //应用键被按下

private:
    Ui::Form_settings_ProjectManger *ui;
};

#endif // FORM_SETTINGS_PROJECTMANGER_H
