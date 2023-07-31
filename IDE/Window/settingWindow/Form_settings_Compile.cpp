#include "Form_settings_Compile.h"
#include "ui_Form_settings_Compile.h"

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
