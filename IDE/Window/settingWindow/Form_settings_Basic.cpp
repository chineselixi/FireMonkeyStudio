#include "Form_settings_Basic.h"
#include "ui_Form_settings_Basic.h"

Form_settings_Basic::Form_settings_Basic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_settings_Basic)
{
    ui->setupUi(this);
}

Form_settings_Basic::~Form_settings_Basic()
{
    delete ui;
}
