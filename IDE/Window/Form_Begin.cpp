#include "Form_Begin.h"
#include "ui_Form_Beginui.h"

Form_Begin::Form_Begin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Begin)
{
    ui->setupUi(this);
}

Form_Begin::~Form_Begin()
{
    delete ui;
}
