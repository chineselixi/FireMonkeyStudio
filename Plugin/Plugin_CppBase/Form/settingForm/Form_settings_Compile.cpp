#include "Form_settings_Compile.h"
#include "ui_Form_settings_Compile.h"
#include "../../../../IDE/module/mod_settingsFormBase.cpp"

Form_settings_Compile::Form_settings_Compile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_settings_Compile)
{
    ui->setupUi(this);
}

Form_settings_Compile::~Form_settings_Compile()
{
    delete ui;
}


//确认键被按下
void Form_settings_Compile::Event_Ok()
{

}

//取消键被按下
void Form_settings_Compile::Event_cancel()
{

}

//应用键被按下
void Form_settings_Compile::Event_use()
{

}
