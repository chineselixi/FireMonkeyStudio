#include "Form_settings_Git.h"
#include "ui_Form_settings_Git.h"

Form_settings_Git::Form_settings_Git(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_settings_Git)
{
    ui->setupUi(this);
}

Form_settings_Git::~Form_settings_Git()
{
    delete ui;
}
