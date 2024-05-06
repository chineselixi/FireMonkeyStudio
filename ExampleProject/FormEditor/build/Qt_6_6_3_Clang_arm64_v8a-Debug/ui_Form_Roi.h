/********************************************************************************
** Form generated from reading UI file 'Form_Roi.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_ROI_H
#define UI_FORM_ROI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Roi
{
public:

    void setupUi(QWidget *Form_Roi)
    {
        if (Form_Roi->objectName().isEmpty())
            Form_Roi->setObjectName("Form_Roi");
        Form_Roi->setEnabled(true);
        Form_Roi->resize(376, 276);
        Form_Roi->setCursor(QCursor(Qt::ArrowCursor));
        Form_Roi->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Form_Roi);

        QMetaObject::connectSlotsByName(Form_Roi);
    } // setupUi

    void retranslateUi(QWidget *Form_Roi)
    {
        Form_Roi->setWindowTitle(QCoreApplication::translate("Form_Roi", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_Roi: public Ui_Form_Roi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_ROI_H
