/********************************************************************************
** Form generated from reading UI file 'Form_TextPrint.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_TEXTPRINT_H
#define UI_FORM_TEXTPRINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_TextPrint
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *Form_TextPrint)
    {
        if (Form_TextPrint->objectName().isEmpty())
            Form_TextPrint->setObjectName("Form_TextPrint");
        Form_TextPrint->resize(637, 315);
        Form_TextPrint->setStyleSheet(QString::fromUtf8("#textEdit{\n"
"	background-color: rgb(230, 231, 232);\n"
"}"));
        gridLayout = new QGridLayout(Form_TextPrint);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(Form_TextPrint);
        textEdit->setObjectName("textEdit");
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        retranslateUi(Form_TextPrint);

        QMetaObject::connectSlotsByName(Form_TextPrint);
    } // setupUi

    void retranslateUi(QWidget *Form_TextPrint)
    {
        Form_TextPrint->setWindowTitle(QCoreApplication::translate("Form_TextPrint", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_TextPrint: public Ui_Form_TextPrint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_TEXTPRINT_H
