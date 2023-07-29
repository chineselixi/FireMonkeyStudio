#include "Form_settings_Color.h"
#include "ui_Form_settings_Color.h"

Form_settings_Color::Form_settings_Color(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_settings_Color)
{
    ui->setupUi(this);
}

Form_settings_Color::~Form_settings_Color()
{
    delete ui;
}
