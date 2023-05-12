#include "Form_Content.h"
#include "ui_Form_Content.h"

Form_Content::Form_Content(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Form_Content)
{
    ui->setupUi(this);
}

Form_Content::~Form_Content()
{
    delete ui;
}
