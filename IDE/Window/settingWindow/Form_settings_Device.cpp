#include "Form_settings_Device.h"
#include "ui_Form_settings_Device.h"

Form_settings_Device::Form_settings_Device(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_settings_Device)
{
    ui->setupUi(this);
}

Form_settings_Device::~Form_settings_Device()
{
    delete ui;
}
