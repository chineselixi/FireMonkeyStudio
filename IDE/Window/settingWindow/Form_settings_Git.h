#ifndef FORM_SETTINGS_GIT_H
#define FORM_SETTINGS_GIT_H

#include <QWidget>
#include "module/mod_settingsFormBase.h"
#include "QProcess"

namespace Ui {
class Form_settings_Git;
}

class Form_settings_Git : public QWidget,public mod_settingsFormBase
{
    Q_OBJECT

public:
    explicit Form_settings_Git(QWidget *parent = nullptr);
    ~Form_settings_Git();

    void Event_Ok() override; //确认键被按下
    void Event_cancel() override; //取消键被按下
    void Event_use() override; //应用键被按下

private slots:
    void on_btn_select_clicked(); //选择路径

    void on_btn_test_clicked();

    void on_checkBox_showPsw_stateChanged(int arg1);

private:
    void Init();
    static void loadSettings(); //静态加载设置

private:
    Ui::Form_settings_Git *ui;
    QProcess* process = nullptr;
};

#endif // FORM_SETTINGS_GIT_H
