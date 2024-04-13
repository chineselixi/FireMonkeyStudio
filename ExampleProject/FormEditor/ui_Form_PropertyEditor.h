/********************************************************************************
** Form generated from reading UI file 'Form_PropertyEditor.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_PROPERTYEDITOR_H
#define UI_FORM_PROPERTYEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "qtpropertybrowser/qttreepropertybrowser.h"

QT_BEGIN_NAMESPACE

class Ui_Form_PropertyEditor
{
public:
    QGridLayout *gridLayout;
    QtTreePropertyBrowser *propertyBox;

    void setupUi(QWidget *Form_PropertyEditor)
    {
        if (Form_PropertyEditor->objectName().isEmpty())
            Form_PropertyEditor->setObjectName("Form_PropertyEditor");
        Form_PropertyEditor->resize(250, 642);
        Form_PropertyEditor->setMinimumSize(QSize(150, 0));
        Form_PropertyEditor->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Form_PropertyEditor);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        propertyBox = new QtTreePropertyBrowser(Form_PropertyEditor);
        propertyBox->setObjectName("propertyBox");

        gridLayout->addWidget(propertyBox, 0, 0, 1, 1);


        retranslateUi(Form_PropertyEditor);

        QMetaObject::connectSlotsByName(Form_PropertyEditor);
    } // setupUi

    void retranslateUi(QWidget *Form_PropertyEditor)
    {
        Form_PropertyEditor->setWindowTitle(QCoreApplication::translate("Form_PropertyEditor", "\345\261\236\346\200\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_PropertyEditor: public Ui_Form_PropertyEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_PROPERTYEDITOR_H
