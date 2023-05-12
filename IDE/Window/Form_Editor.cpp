#include "Form_Editor.h"
#include "ui_Form_Editor.h"

Form_Editor::Form_Editor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Editor)
{
    ui->setupUi(this);
}

Form_Editor::~Form_Editor()
{
    delete ui;
}
