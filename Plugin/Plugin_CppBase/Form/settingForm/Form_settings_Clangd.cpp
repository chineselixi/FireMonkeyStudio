#include "Form_settings_Clangd.h"
#include "ui_Form_settings_Clangd.h"

Form_settings_Clangd::Form_settings_Clangd(Plugin_CppBase* pluginP,QWidget *parent) :
    pluginPtr(pluginP),
    QWidget(parent),
    ui(new Ui::Form_settings_Clangd)
{
    ui->setupUi(this);
}

Form_settings_Clangd::~Form_settings_Clangd()
{
    delete ui;
}

//确认键被按下
void Form_settings_Clangd::Event_Ok()
{

}

//取消键被按下
void Form_settings_Clangd::Event_cancel()
{

}

//应用键被按下
void Form_settings_Clangd::Event_use()
{

}
