/********************************************************************************
** Form generated from reading UI file 'Form_Terminal.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_TERMINAL_H
#define UI_FORM_TERMINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "Widget_TextEdit.h"

QT_BEGIN_NAMESPACE

class Ui_Form_Terminal
{
public:
    QGridLayout *gridLayout;
    Widget_TextEdit *textEdit;

    void setupUi(QWidget *Form_Terminal)
    {
        if (Form_Terminal->objectName().isEmpty())
            Form_Terminal->setObjectName("Form_Terminal");
        Form_Terminal->resize(717, 447);
        gridLayout = new QGridLayout(Form_Terminal);
        gridLayout->setObjectName("gridLayout");
        textEdit = new Widget_TextEdit(Form_Terminal);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        retranslateUi(Form_Terminal);

        QMetaObject::connectSlotsByName(Form_Terminal);
    } // setupUi

    void retranslateUi(QWidget *Form_Terminal)
    {
        Form_Terminal->setWindowTitle(QCoreApplication::translate("Form_Terminal", "FMS Terminal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_Terminal: public Ui_Form_Terminal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_TERMINAL_H
