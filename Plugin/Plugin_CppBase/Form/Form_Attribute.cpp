#include "Form_Attributee.h"
#include "ui_Form_Attribute.h"

Form_Attribute::Form_Attribute(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Attribute)
{
    ui->setupUi(this);
}

Form_Attribute::~Form_Attribute()
{
    delete ui;
}
