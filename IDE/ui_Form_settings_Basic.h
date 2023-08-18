/********************************************************************************
** Form generated from reading UI file 'Form_settings_Basic.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SETTINGS_BASIC_H
#define UI_FORM_SETTINGS_BASIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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

class Ui_Form_settings_Basic
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QLabel *label_2;
    QCheckBox *checkBox_3;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox_8;
    QLabel *label_8;

    void setupUi(QWidget *Form_settings_Basic)
    {
        if (Form_settings_Basic->objectName().isEmpty())
            Form_settings_Basic->setObjectName("Form_settings_Basic");
        Form_settings_Basic->resize(800, 835);
        gridLayout = new QGridLayout(Form_settings_Basic);
        gridLayout->setObjectName("gridLayout");
        scrollArea = new QScrollArea(Form_settings_Basic);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 776, 811));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setSpacing(20);
        verticalLayout_5->setObjectName("verticalLayout_5");
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(0, 130));
        groupBox_2->setMaximumSize(QSize(16777215, 130));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(100, 0));
        pushButton_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(100, 0));
        pushButton_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(pushButton_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setOpenExternalLinks(true);

        verticalLayout_2->addWidget(label_4);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(0, 200));
        groupBox->setMaximumSize(QSize(16777215, 200));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName("checkBox");
        checkBox->setMinimumSize(QSize(120, 0));
        checkBox->setMaximumSize(QSize(120, 16777215));
        checkBox->setChecked(true);

        horizontalLayout->addWidget(checkBox);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(150, 0));
        comboBox->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setMinimumSize(QSize(120, 0));
        checkBox_2->setMaximumSize(QSize(120, 16777215));
        checkBox_2->setChecked(true);

        horizontalLayout_2->addWidget(checkBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(100, 0));
        pushButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(pushButton);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_3);

        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setChecked(true);

        verticalLayout->addWidget(checkBox_3);


        verticalLayout_5->addWidget(groupBox);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setMinimumSize(QSize(0, 135));
        groupBox_4->setMaximumSize(QSize(16777215, 135));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(160, 24));
        label_5->setMaximumSize(QSize(160, 24));

        horizontalLayout_7->addWidget(label_5);

        lineEdit = new QLineEdit(groupBox_4);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(60, 24));
        lineEdit->setMaximumSize(QSize(60, 24));

        horizontalLayout_7->addWidget(lineEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(160, 24));
        label_6->setMaximumSize(QSize(160, 24));

        horizontalLayout_8->addWidget(label_6);

        lineEdit_2 = new QLineEdit(groupBox_4);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(60, 24));
        lineEdit_2->setMaximumSize(QSize(60, 24));

        horizontalLayout_8->addWidget(lineEdit_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName("label_7");
        label_7->setMinimumSize(QSize(160, 24));
        label_7->setMaximumSize(QSize(160, 24));

        horizontalLayout_9->addWidget(label_7);

        lineEdit_3 = new QLineEdit(groupBox_4);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setMinimumSize(QSize(60, 24));
        lineEdit_3->setMaximumSize(QSize(60, 24));

        horizontalLayout_9->addWidget(lineEdit_3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout_9);


        verticalLayout_5->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName("groupBox_3");
        horizontalLayout_5 = new QHBoxLayout(groupBox_3);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setMinimumSize(QSize(114, 24));
        checkBox_4->setMaximumSize(QSize(114, 24));
        checkBox_4->setChecked(true);

        horizontalLayout_5->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(groupBox_3);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setMinimumSize(QSize(99, 24));
        checkBox_5->setMaximumSize(QSize(99, 24));
        checkBox_5->setChecked(true);

        horizontalLayout_5->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(groupBox_3);
        checkBox_6->setObjectName("checkBox_6");
        checkBox_6->setMinimumSize(QSize(84, 24));
        checkBox_6->setMaximumSize(QSize(84, 24));

        horizontalLayout_5->addWidget(checkBox_6);

        checkBox_7 = new QCheckBox(groupBox_3);
        checkBox_7->setObjectName("checkBox_7");
        checkBox_7->setMinimumSize(QSize(114, 24));
        checkBox_7->setMaximumSize(QSize(114, 24));

        horizontalLayout_5->addWidget(checkBox_7);

        horizontalSpacer_4 = new QSpacerItem(290, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_5->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_5->setObjectName("groupBox_5");
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName("verticalLayout_4");
        checkBox_8 = new QCheckBox(groupBox_5);
        checkBox_8->setObjectName("checkBox_8");

        verticalLayout_4->addWidget(checkBox_8);

        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName("label_8");
        label_8->setTextFormat(Qt::AutoText);
        label_8->setScaledContents(false);
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_8->setWordWrap(true);
        label_8->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        verticalLayout_4->addWidget(label_8);


        verticalLayout_5->addWidget(groupBox_5);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Form_settings_Basic);

        QMetaObject::connectSlotsByName(Form_settings_Basic);
    } // setupUi

    void retranslateUi(QWidget *Form_settings_Basic)
    {
        Form_settings_Basic->setWindowTitle(QCoreApplication::translate("Form_settings_Basic", "Form", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Form_settings_Basic", "\350\264\246\346\210\267", nullptr));
        label_3->setText(QCoreApplication::translate("Form_settings_Basic", "\346\234\252\347\231\273\345\275\225FMS\350\264\246\346\210\267\357\274\214\344\272\221\346\234\215\345\212\241\344\270\215\345\217\257\347\224\250", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form_settings_Basic", "\347\231\273\345\275\225", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Form_settings_Basic", "\346\263\250\345\206\214", nullptr));
        label_4->setText(QCoreApplication::translate("Form_settings_Basic", "<a href=\"https://www.superlsp.com/\">\350\256\277\351\227\256FireMonkeyStudio\345\256\230\346\226\271\347\275\221\347\253\231</a>", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Form_settings_Basic", "\347\211\210\346\234\254", nullptr));
        label->setText(QCoreApplication::translate("Form_settings_Basic", "\345\275\223\345\211\215\347\211\210\346\234\254\357\274\232FMS 1.0 DEV    2023\345\271\2646\346\234\21010\346\227\245", nullptr));
        checkBox->setText(QCoreApplication::translate("Form_settings_Basic", "\350\207\252\345\212\250\346\233\264\346\226\260IDE", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Form_settings_Basic", "\347\250\263\345\256\232\347\211\210\346\234\254", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Form_settings_Basic", "\345\274\200\345\217\221\350\200\205\351\242\204\350\247\210\347\211\210\346\234\254", nullptr));
        comboBox->setItemText(2, QString());

        checkBox_2->setText(QCoreApplication::translate("Form_settings_Basic", "\346\243\200\346\237\245\346\217\222\344\273\266\346\233\264\346\226\260", nullptr));
        pushButton->setText(QCoreApplication::translate("Form_settings_Basic", "\346\243\200\346\237\245\346\233\264\346\226\260", nullptr));
        label_2->setText(QCoreApplication::translate("Form_settings_Basic", "\344\270\212\346\254\241\346\243\200\346\237\245\357\274\2321\345\271\264\344\273\245\345\211\215", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Form_settings_Basic", "IDE\346\233\264\346\226\260\345\220\216\346\217\220\347\244\272\346\226\260\345\212\237\350\203\275", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Form_settings_Basic", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        label_5->setText(QCoreApplication::translate("Form_settings_Basic", "\346\234\200\350\277\221\351\241\271\347\233\256\347\232\204\346\234\200\345\244\247\346\225\260\351\207\217\357\274\232", nullptr));
        lineEdit->setText(QCoreApplication::translate("Form_settings_Basic", "50", nullptr));
        label_6->setText(QCoreApplication::translate("Form_settings_Basic", "\346\234\200\350\277\221\346\250\241\346\235\277\347\232\204\346\234\200\345\244\247\346\225\260\351\207\217\357\274\232", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("Form_settings_Basic", "50", nullptr));
        label_7->setText(QCoreApplication::translate("Form_settings_Basic", "\346\227\245\345\277\227\350\256\260\345\275\225\347\232\204\346\234\200\345\244\247\346\225\260\351\207\217\357\274\232", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("Form_settings_Basic", "10000", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Form_settings_Basic", "\345\256\236\346\227\266\344\277\241\346\201\257", nullptr));
        checkBox_4->setText(QCoreApplication::translate("Form_settings_Basic", "\347\211\210\346\234\254\346\233\264\346\226\260\345\205\254\345\221\212", nullptr));
        checkBox_5->setText(QCoreApplication::translate("Form_settings_Basic", "\345\274\200\345\217\221\350\200\205\346\226\260\351\227\273", nullptr));
        checkBox_6->setText(QCoreApplication::translate("Form_settings_Basic", "\350\265\233\344\272\213\344\277\241\346\201\257", nullptr));
        checkBox_7->setText(QCoreApplication::translate("Form_settings_Basic", "\344\274\230\347\247\200\350\265\204\346\272\220\346\216\250\350\215\220", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Form_settings_Basic", "\346\225\260\346\215\256\345\205\261\344\272\253", nullptr));
        checkBox_8->setText(QCoreApplication::translate("Form_settings_Basic", "\345\217\221\351\200\201\344\275\277\347\224\250\347\273\237\350\256\241\344\277\241\346\201\257", nullptr));
        label_8->setText(QCoreApplication::translate("Form_settings_Basic", "\351\200\232\350\277\207\345\217\221\351\200\201\345\214\277\345\220\215\346\225\260\346\215\256\345\270\256\345\212\251FMS\345\274\200\345\217\221\350\200\205\346\224\271\350\277\233\345\205\266\344\272\247\345\223\201\344\275\277\347\224\250\347\232\204\345\212\237\350\203\275\345\222\214\346\217\222\344\273\266\357\274\214\347\241\254\344\273\266\345\222\214\350\275\257\344\273\266\351\205\215\347\275\256\357\274\214\347\273\237\350\256\241\345\205\263\344\272\216\346\226\207\344\273\266\347\261\273\345\236\213\343\200\201\346\257\217\344\270\252\351\241\271\347\233\256\347\232\204\346\226\207\344\273\266\346\225\260\351\207\217\347\255\211\343\200\202\350\257\267\346\263\250\346\204\217\357\274\214\350\277\231\344\270\215\345\214\205\346\213\254\344\270\252\344\272\272\346\225\260\346\215\256\346\210\226\344\273\273\344\275\225\346\225\217\346\204\237\344\277\241\346\201\257\344\277\241\346\201\257\357\274\214\345\246\202\346\272\220\344\273\243\347\240\201\343\200\201\346\226\207\344\273\266\345\220\215\347"
                        "\255\211\343\200\202\345\217\221\351\200\201\347\232\204\346\225\260\346\215\256\347\254\246\345\220\210\344\270\216\351\232\220\347\247\201\346\224\277\347\255\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_settings_Basic: public Ui_Form_settings_Basic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SETTINGS_BASIC_H
