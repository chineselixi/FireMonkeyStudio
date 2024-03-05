#include "Form_settings_ProjectManger.h"
#include "ui_Form_settings_ProjectManger.h"

Form_settings_ProjectManger::Form_settings_ProjectManger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_settings_ProjectManger)
{
    ui->setupUi(this);
}

Form_settings_ProjectManger::~Form_settings_ProjectManger()
{
    delete ui;
}


//静态加载设置
void Form_settings_ProjectManger::loadSettings()
{

}

//确认键被按下
void Form_settings_ProjectManger::Event_Ok()
{

}

//取消键被按下
void Form_settings_ProjectManger::Event_cancel()
{

}

//应用键被按下
void Form_settings_ProjectManger::Event_use()
{

}
