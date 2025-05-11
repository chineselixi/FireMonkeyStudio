/********************************************************************************
** Form generated from reading UI file 'Form_settings_DataBase.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SETTINGS_DATABASE_H
#define UI_FORM_SETTINGS_DATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_settings_DataBase
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Form_settings_DataBase)
    {
        if (Form_settings_DataBase->objectName().isEmpty())
            Form_settings_DataBase->setObjectName("Form_settings_DataBase");
        Form_settings_DataBase->resize(800, 577);
        verticalLayout_3 = new QVBoxLayout(Form_settings_DataBase);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBox = new QGroupBox(Form_settings_DataBase);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setMinimumSize(QSize(75, 0));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(lineEdit_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(75, 0));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout_2->addWidget(lineEdit_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(75, 0));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");

        horizontalLayout_3->addWidget(lineEdit_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(75, 0));

        horizontalLayout_4->addWidget(label_5);

        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(lineEdit_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(93, 0));
        pushButton->setMaximumSize(QSize(93, 16777215));

        horizontalLayout_5->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setEnabled(false);
        pushButton_2->setMinimumSize(QSize(93, 0));
        pushButton_2->setMaximumSize(QSize(93, 16777215));

        horizontalLayout_5->addWidget(pushButton_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Form_settings_DataBase);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName("checkBox");

        horizontalLayout_6->addWidget(checkBox);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");

        horizontalLayout_6->addWidget(label_7);

        lineEdit_6 = new QLineEdit(groupBox_2);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setMinimumSize(QSize(60, 0));
        lineEdit_6->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_6->addWidget(lineEdit_6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(30);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setChecked(true);

        horizontalLayout_7->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setChecked(true);

        horizontalLayout_7->addWidget(checkBox_3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_3->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 177, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(Form_settings_DataBase);

        QMetaObject::connectSlotsByName(Form_settings_DataBase);
    } // setupUi

    void retranslateUi(QWidget *Form_settings_DataBase)
    {
        Form_settings_DataBase->setWindowTitle(QCoreApplication::translate("Form_settings_DataBase", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Form_settings_DataBase", "ODBC", nullptr));
        label->setText(QCoreApplication::translate("Form_settings_DataBase", "\344\270\273\346\234\272\345\220\215\357\274\232", nullptr));
        lineEdit->setText(QCoreApplication::translate("Form_settings_DataBase", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("Form_settings_DataBase", "    \347\253\257\345\217\243\357\274\232", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("Form_settings_DataBase", "3306", nullptr));
        label_3->setText(QCoreApplication::translate("Form_settings_DataBase", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("Form_settings_DataBase", "LocalDB", nullptr));
        label_4->setText(QCoreApplication::translate("Form_settings_DataBase", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("Form_settings_DataBase", "root", nullptr));
        label_5->setText(QCoreApplication::translate("Form_settings_DataBase", "\345\257\206\347\240\201\357\274\232", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("Form_settings_DataBase", "root", nullptr));
        pushButton->setText(QCoreApplication::translate("Form_settings_DataBase", "\350\277\236\346\216\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form_settings_DataBase", "\346\265\213\350\257\225", nullptr));
        label_6->setText(QCoreApplication::translate("Form_settings_DataBase", "\346\225\260\346\215\256\345\272\223\347\212\266\346\200\201\357\274\232\346\234\252\345\210\235\345\247\213\345\214\226\346\225\260\346\215\256\345\272\223\351\223\276\346\216\245", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Form_settings_DataBase", "\346\225\260\346\215\256\345\272\223\345\270\270\350\247\204", nullptr));
        checkBox->setText(QCoreApplication::translate("Form_settings_DataBase", "\345\220\257\345\212\250\350\207\252\345\212\250\351\223\276\346\216\245\346\225\260\346\215\256\345\272\223", nullptr));
        label_7->setText(QCoreApplication::translate("Form_settings_DataBase", "          \350\207\252\345\212\250\345\260\235\350\257\225\346\254\241\346\225\260\357\274\232", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("Form_settings_DataBase", "3", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Form_settings_DataBase", "\345\234\250\346\217\220\347\244\272\345\231\250\351\207\214\351\235\242\350\276\223\345\207\272\351\224\231\350\257\257\344\277\241\346\201\257", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Form_settings_DataBase", "\350\256\260\345\275\225\346\225\260\346\215\256\345\272\223\351\224\231\350\257\257\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_settings_DataBase: public Ui_Form_settings_DataBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SETTINGS_DATABASE_H
