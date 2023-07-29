#include "Form_settings_DataBase.h"
#include "ui_Form_settings_DataBase.h"

Form_settings_DataBase::Form_settings_DataBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_settings_DataBase)
{
    ui->setupUi(this);
}

Form_settings_DataBase::~Form_settings_DataBase()
{
    delete ui;
}
