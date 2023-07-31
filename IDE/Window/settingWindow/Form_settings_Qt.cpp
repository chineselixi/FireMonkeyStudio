#include "Form_settings_Qt.h"
#include "ui_Form_settings_Qt.h"

Form_settings_Qt::Form_settings_Qt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_settings_Qt)
{
    ui->setupUi(this);
}

Form_settings_Qt::~Form_settings_Qt()
{
    delete ui;
}
