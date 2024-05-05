#include "Form_StyleEditor.h"
#include "ui_Form_StyleEditor.h"
#include "QAbstractButton"

Form_StyleEditor::Form_StyleEditor(QWidget *parent,QWidget* subWidget)
    : QDialog(parent)
    , ui(new Ui::Form_StyleEditor)
{
    ui->setupUi(this);
    widget = subWidget;
    if(widget != nullptr){
        ui->plainTextEdit->setPlainText(widget->styleSheet());
    }
}

Form_StyleEditor::~Form_StyleEditor()
{
    delete ui;
}

void Form_StyleEditor::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button == (QAbstractButton*)ui->buttonBox->button(QDialogButtonBox::Save))
    {
        if(widget != nullptr){
            widget->setStyleSheet(ui->plainTextEdit->toPlainText());
        }
    }
}

