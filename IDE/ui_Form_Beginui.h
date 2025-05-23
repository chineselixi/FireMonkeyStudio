/********************************************************************************
** Form generated from reading UI file 'Form_Beginui.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_BEGINUI_H
#define UI_FORM_BEGINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Begin
{
public:
    QProgressBar *progressBar;
    QLabel *label_tipLable;

    void setupUi(QWidget *Form_Begin)
    {
        if (Form_Begin->objectName().isEmpty())
            Form_Begin->setObjectName("Form_Begin");
        Form_Begin->resize(400, 300);
        progressBar = new QProgressBar(Form_Begin);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(0, 280, 401, 23));
        progressBar->setValue(24);
        label_tipLable = new QLabel(Form_Begin);
        label_tipLable->setObjectName("label_tipLable");
        label_tipLable->setGeometry(QRect(10, 270, 191, 16));
        label_tipLable->setLineWidth(-3);

        retranslateUi(Form_Begin);

        QMetaObject::connectSlotsByName(Form_Begin);
    } // setupUi

    void retranslateUi(QWidget *Form_Begin)
    {
        Form_Begin->setWindowTitle(QCoreApplication::translate("Form_Begin", "Form", nullptr));
        label_tipLable->setText(QCoreApplication::translate("Form_Begin", "\346\254\242\350\277\216\344\275\277\347\224\250\347\201\253\347\214\264\345\274\200\345\217\221\345\245\227\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_Begin: public Ui_Form_Begin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_BEGINUI_H
