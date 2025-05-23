/********************************************************************************
** Form generated from reading UI file 'Form_settings_Compile.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SETTINGS_COMPILE_H
#define UI_FORM_SETTINGS_COMPILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_settings_Compile
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Form_settings_Compile)
    {
        if (Form_settings_Compile->objectName().isEmpty())
            Form_settings_Compile->setObjectName("Form_settings_Compile");
        Form_settings_Compile->resize(800, 832);
        gridLayout = new QGridLayout(Form_settings_Compile);
        gridLayout->setObjectName("gridLayout");
        scrollArea = new QScrollArea(Form_settings_Compile);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 776, 808));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(140, 0));
        label_2->setMaximumSize(QSize(140, 16777215));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_2->addWidget(lineEdit_2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(140, 0));
        label_4->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_2->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setMinimumSize(QSize(100, 0));
        label_7->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(label_7);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");

        horizontalLayout_4->addWidget(lineEdit_4);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setMinimumSize(QSize(140, 0));
        label_8->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_4->addWidget(label_8);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName("groupBox_2");

        verticalLayout_2->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 577, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Form_settings_Compile);

        QMetaObject::connectSlotsByName(Form_settings_Compile);
    } // setupUi

    void retranslateUi(QWidget *Form_settings_Compile)
    {
        Form_settings_Compile->setWindowTitle(QCoreApplication::translate("Form_settings_Compile", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Form_settings_Compile", "GNU\347\274\226\350\257\221\345\231\250\345\245\227\344\273\266", nullptr));
        label->setText(QCoreApplication::translate("Form_settings_Compile", "C\347\274\226\350\257\221\345\231\250\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Form_settings_Compile", "\347\211\210\346\234\254\357\274\232\346\234\252\347\237\245", nullptr));
        label_3->setText(QCoreApplication::translate("Form_settings_Compile", "C++\347\274\226\350\257\221\345\231\250\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Form_settings_Compile", "\347\211\210\346\234\254\357\274\232\346\234\252\347\237\245", nullptr));
        label_7->setText(QCoreApplication::translate("Form_settings_Compile", "GDB\350\260\203\350\257\225\345\231\250\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("Form_settings_Compile", "\347\211\210\346\234\254\357\274\232\346\234\252\347\237\245", nullptr));
        pushButton->setText(QCoreApplication::translate("Form_settings_Compile", "\345\274\200\345\247\213\351\252\214\350\257\201", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Form_settings_Compile", "\346\236\204\345\273\272\350\277\207\347\250\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_settings_Compile: public Ui_Form_settings_Compile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SETTINGS_COMPILE_H
