/********************************************************************************
** Form generated from reading UI file 'Form_settings_Color.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SETTINGS_COLOR_H
#define UI_FORM_SETTINGS_COLOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_settings_Color
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_theme;
    QCheckBox *checkBox_autoTheme;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QComboBox *comboBox_fonts;
    QLabel *label_2;
    QLineEdit *lineEdit_fontSize;
    QCheckBox *checkBox_bold;
    QCheckBox *checkBox_italic;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox_dailyTips;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Form_settings_Color)
    {
        if (Form_settings_Color->objectName().isEmpty())
            Form_settings_Color->setObjectName("Form_settings_Color");
        Form_settings_Color->resize(870, 628);
        gridLayout = new QGridLayout(Form_settings_Color);
        gridLayout->setObjectName("gridLayout");
        scrollArea = new QScrollArea(Form_settings_Color);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 846, 604));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setSpacing(20);
        verticalLayout_5->setObjectName("verticalLayout_5");
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(0, 104));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setMinimumSize(QSize(40, 0));
        label->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(label);

        comboBox_theme = new QComboBox(groupBox);
        comboBox_theme->addItem(QString());
        comboBox_theme->addItem(QString());
        comboBox_theme->addItem(QString());
        comboBox_theme->setObjectName("comboBox_theme");
        comboBox_theme->setMinimumSize(QSize(160, 0));
        comboBox_theme->setMaximumSize(QSize(160, 16777215));

        horizontalLayout->addWidget(comboBox_theme);

        checkBox_autoTheme = new QCheckBox(groupBox);
        checkBox_autoTheme->setObjectName("checkBox_autoTheme");
        checkBox_autoTheme->setMinimumSize(QSize(160, 0));
        checkBox_autoTheme->setMaximumSize(QSize(160, 16777215));

        horizontalLayout->addWidget(checkBox_autoTheme);

        horizontalSpacer = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setMinimumSize(QSize(40, 0));
        label_7->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(label_7);

        comboBox_fonts = new QComboBox(groupBox);
        comboBox_fonts->setObjectName("comboBox_fonts");
        comboBox_fonts->setEnabled(true);
        comboBox_fonts->setMinimumSize(QSize(190, 0));
        comboBox_fonts->setMaximumSize(QSize(190, 16777215));

        horizontalLayout_2->addWidget(comboBox_fonts);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setEnabled(false);
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_fontSize = new QLineEdit(groupBox);
        lineEdit_fontSize->setObjectName("lineEdit_fontSize");
        lineEdit_fontSize->setEnabled(true);
        lineEdit_fontSize->setMinimumSize(QSize(70, 0));
        lineEdit_fontSize->setMaximumSize(QSize(70, 16777215));
        lineEdit_fontSize->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_fontSize);

        checkBox_bold = new QCheckBox(groupBox);
        checkBox_bold->setObjectName("checkBox_bold");
        checkBox_bold->setMinimumSize(QSize(65, 0));

        horizontalLayout_2->addWidget(checkBox_bold);

        checkBox_italic = new QCheckBox(groupBox);
        checkBox_italic->setObjectName("checkBox_italic");
        checkBox_italic->setMinimumSize(QSize(65, 0));

        horizontalLayout_2->addWidget(checkBox_italic);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        checkBox_dailyTips = new QCheckBox(groupBox);
        checkBox_dailyTips->setObjectName("checkBox_dailyTips");
        checkBox_dailyTips->setEnabled(true);
        checkBox_dailyTips->setCheckable(true);
        checkBox_dailyTips->setChecked(true);

        verticalLayout->addWidget(checkBox_dailyTips);


        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(0, 127));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(40, 0));
        label_3->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(label_3);

        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setMinimumSize(QSize(150, 0));
        comboBox_3->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(comboBox_3);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(140, 0));
        label_4->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_3->addWidget(label_4);

        comboBox_4 = new QComboBox(groupBox_2);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setMinimumSize(QSize(150, 0));
        comboBox_4->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(comboBox_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(0, 50));
        label_5->setWordWrap(true);

        verticalLayout_2->addWidget(label_5);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setMinimumSize(QSize(0, 132));
        groupBox_3->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setMinimumSize(QSize(91, 30));
        checkBox_3->setMaximumSize(QSize(16777215, 30));
        checkBox_3->setChecked(true);

        gridLayout_2->addWidget(checkBox_3, 0, 0, 1, 1);

        checkBox_8 = new QCheckBox(groupBox_3);
        checkBox_8->setObjectName("checkBox_8");
        checkBox_8->setMinimumSize(QSize(91, 30));
        checkBox_8->setMaximumSize(QSize(16777215, 30));
        checkBox_8->setChecked(true);

        gridLayout_2->addWidget(checkBox_8, 0, 1, 1, 1);

        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setMinimumSize(QSize(91, 30));
        checkBox_4->setMaximumSize(QSize(16777215, 30));
        checkBox_4->setChecked(true);

        gridLayout_2->addWidget(checkBox_4, 0, 2, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_3);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setMinimumSize(QSize(91, 30));
        checkBox_5->setMaximumSize(QSize(16777215, 30));
        checkBox_5->setChecked(true);

        gridLayout_2->addWidget(checkBox_5, 0, 3, 1, 1);

        checkBox_6 = new QCheckBox(groupBox_3);
        checkBox_6->setObjectName("checkBox_6");
        checkBox_6->setMinimumSize(QSize(91, 30));
        checkBox_6->setMaximumSize(QSize(16777215, 30));
        checkBox_6->setChecked(true);

        gridLayout_2->addWidget(checkBox_6, 0, 4, 1, 1);

        checkBox_7 = new QCheckBox(groupBox_3);
        checkBox_7->setObjectName("checkBox_7");
        checkBox_7->setMinimumSize(QSize(91, 30));
        checkBox_7->setMaximumSize(QSize(16777215, 30));
        checkBox_7->setChecked(true);

        gridLayout_2->addWidget(checkBox_7, 0, 5, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(0, 50));
        label_6->setWordWrap(true);

        verticalLayout_3->addWidget(label_6);


        verticalLayout_5->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Form_settings_Color);

        QMetaObject::connectSlotsByName(Form_settings_Color);
    } // setupUi

    void retranslateUi(QWidget *Form_settings_Color)
    {
        Form_settings_Color->setWindowTitle(QCoreApplication::translate("Form_settings_Color", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Form_settings_Color", "\346\240\267\345\274\217", nullptr));
        label->setText(QCoreApplication::translate("Form_settings_Color", "\344\270\273\351\242\230\357\274\232", nullptr));
        comboBox_theme->setItemText(0, QCoreApplication::translate("Form_settings_Color", "Blue", nullptr));
        comboBox_theme->setItemText(1, QCoreApplication::translate("Form_settings_Color", "White", nullptr));
        comboBox_theme->setItemText(2, QCoreApplication::translate("Form_settings_Color", "Dark", nullptr));

        checkBox_autoTheme->setText(QCoreApplication::translate("Form_settings_Color", "\350\207\252\345\212\250\350\260\203\346\225\264", nullptr));
        label_7->setText(QCoreApplication::translate("Form_settings_Color", "\345\255\227\344\275\223\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Form_settings_Color", "\345\244\247\345\260\217\357\274\232", nullptr));
        lineEdit_fontSize->setText(QCoreApplication::translate("Form_settings_Color", "12", nullptr));
        checkBox_bold->setText(QCoreApplication::translate("Form_settings_Color", "\345\212\240\347\262\227", nullptr));
        checkBox_italic->setText(QCoreApplication::translate("Form_settings_Color", "\346\226\234\344\275\223", nullptr));
        checkBox_dailyTips->setText(QCoreApplication::translate("Form_settings_Color", "\346\257\217\346\227\245\345\260\217\346\212\200\345\267\247(\346\216\250\351\200\201IDE\347\232\204\344\275\277\347\224\250\344\270\216\345\274\200\345\217\221\346\212\200\345\267\247)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Form_settings_Color", "\346\212\227\351\224\257\351\275\277", nullptr));
        label_3->setText(QCoreApplication::translate("Form_settings_Color", "IDE\357\274\232", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Form_settings_Color", "PreferAntialias", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Form_settings_Color", "NoAntialias", nullptr));

        label_4->setText(QCoreApplication::translate("Form_settings_Color", "    \346\217\222\344\273\266\346\212\227\351\224\257\351\275\277\346\266\210\346\201\257\357\274\232", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("Form_settings_Color", "PreferAntialias", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("Form_settings_Color", "NoAntialias", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("Form_settings_Color", "None", nullptr));

        label_5->setText(QCoreApplication::translate("Form_settings_Color", "\346\263\250\346\204\217\357\274\232\346\217\222\344\273\266\346\212\227\351\224\257\351\275\277\346\266\210\346\201\257\345\260\206\344\274\232\347\273\231\345\267\262\347\273\217\345\220\257\347\224\250\345\271\266\344\270\224\346\255\243\345\270\270\345\212\240\350\275\275\347\232\204\347\232\204\346\217\222\344\273\266\346\212\225\351\200\222\357\274\214\344\275\206\346\234\200\347\273\210\346\230\257\345\220\246\351\201\265\345\276\252\344\273\245\346\217\222\344\273\266\345\206\205\351\203\250\345\256\236\347\216\260\344\270\272\345\207\206\343\200\202\347\263\273\347\273\237\344\270\215\345\274\272\345\210\266\345\272\224\347\224\250\346\255\244\350\256\276\347\275\256", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Form_settings_Color", "\345\220\257\345\212\250\351\273\230\350\256\244\347\252\227\344\275\223", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Form_settings_Color", "\350\265\267\345\247\213\351\241\265", nullptr));
        checkBox_8->setText(QCoreApplication::translate("Form_settings_Color", "\345\267\245\347\250\213\347\256\241\347\220\206", nullptr));
        checkBox_4->setText(QCoreApplication::translate("Form_settings_Color", "\347\274\226\350\257\221\350\276\223\345\207\272", nullptr));
        checkBox_5->setText(QCoreApplication::translate("Form_settings_Color", "\350\277\220\350\241\214\346\217\220\347\244\272", nullptr));
        checkBox_6->setText(QCoreApplication::translate("Form_settings_Color", "\346\226\255\347\202\271\345\240\206\346\240\210", nullptr));
        checkBox_7->setText(QCoreApplication::translate("Form_settings_Color", "\346\220\234\345\257\273\347\273\223\346\236\234", nullptr));
        label_6->setText(QCoreApplication::translate("Form_settings_Color", "\346\263\250\346\204\217\357\274\232\350\213\245\346\255\244\345\244\204\346\262\241\346\234\211\351\234\200\350\246\201\347\232\204\351\273\230\350\256\244\347\252\227\344\275\223\350\256\276\347\275\256\357\274\214\345\210\231\351\234\200\350\246\201\345\234\250\345\257\271\345\272\224\347\232\204\346\217\222\344\273\266\350\256\276\347\275\256\344\270\213\350\277\233\350\241\214\347\233\270\345\272\224\350\256\276\347\275\256(\345\234\250\346\255\244\350\256\276\347\275\256\345\255\230\345\234\250\347\232\204\345\211\215\346\217\220\344\270\213)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_settings_Color: public Ui_Form_settings_Color {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SETTINGS_COLOR_H
