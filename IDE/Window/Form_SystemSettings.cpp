#include "Form_SystemSettings.h"
#include "ui_Form_SystemSettings.h"

Form_SystemSettings::Form_SystemSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_SystemSettings)
{
    ui->setupUi(this);
}

Form_SystemSettings::~Form_SystemSettings()
{
    delete ui;
}
