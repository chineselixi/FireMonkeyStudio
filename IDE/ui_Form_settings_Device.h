/********************************************************************************
** Form generated from reading UI file 'Form_settings_Device.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SETTINGS_DEVICE_H
#define UI_FORM_SETTINGS_DEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_settings_Device
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *Form_settings_Device)
    {
        if (Form_settings_Device->objectName().isEmpty())
            Form_settings_Device->setObjectName("Form_settings_Device");
        Form_settings_Device->resize(800, 635);
        gridLayout = new QGridLayout(Form_settings_Device);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(Form_settings_Device);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(Form_settings_Device);

        QMetaObject::connectSlotsByName(Form_settings_Device);
    } // setupUi

    void retranslateUi(QWidget *Form_settings_Device)
    {
        Form_settings_Device->setWindowTitle(QCoreApplication::translate("Form_settings_Device", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form_settings_Device", "\346\255\244\347\211\210\346\234\254\346\232\202\344\270\215\346\224\257\346\214\201\350\256\276\345\244\207\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_settings_Device: public Ui_Form_settings_Device {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SETTINGS_DEVICE_H
