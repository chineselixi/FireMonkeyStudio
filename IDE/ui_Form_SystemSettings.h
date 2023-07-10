/********************************************************************************
** Form generated from reading UI file 'Form_SystemSettings.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SYSTEMSETTINGS_H
#define UI_FORM_SYSTEMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_SystemSettings
{
public:

    void setupUi(QWidget *Form_SystemSettings)
    {
        if (Form_SystemSettings->objectName().isEmpty())
            Form_SystemSettings->setObjectName("Form_SystemSettings");
        Form_SystemSettings->resize(800, 600);

        retranslateUi(Form_SystemSettings);

        QMetaObject::connectSlotsByName(Form_SystemSettings);
    } // setupUi

    void retranslateUi(QWidget *Form_SystemSettings)
    {
        Form_SystemSettings->setWindowTitle(QCoreApplication::translate("Form_SystemSettings", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_SystemSettings: public Ui_Form_SystemSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SYSTEMSETTINGS_H
