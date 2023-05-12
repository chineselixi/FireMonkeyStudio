/********************************************************************************
** Form generated from reading UI file 'Form_Editor.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_EDITOR_H
#define UI_FORM_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Editor
{
public:

    void setupUi(QWidget *Form_Editor)
    {
        if (Form_Editor->objectName().isEmpty())
            Form_Editor->setObjectName("Form_Editor");
        Form_Editor->resize(400, 300);

        retranslateUi(Form_Editor);

        QMetaObject::connectSlotsByName(Form_Editor);
    } // setupUi

    void retranslateUi(QWidget *Form_Editor)
    {
        Form_Editor->setWindowTitle(QCoreApplication::translate("Form_Editor", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_Editor: public Ui_Form_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_EDITOR_H
