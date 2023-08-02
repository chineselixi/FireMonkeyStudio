/********************************************************************************
** Form generated from reading UI file 'Form_settings_Git.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SETTINGS_GIT_H
#define UI_FORM_SETTINGS_GIT_H

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

class Ui_Form_settings_Git
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_gitPath;
    QPushButton *btn_select;
    QPushButton *btn_test;
    QLabel *label_tips;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_userName;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_email;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_psw;
    QCheckBox *checkBox_showPsw;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_checkMsg;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_track;
    QCheckBox *checkBox_pushAddDate;
    QCheckBox *checkBox_outMsg;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_master;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Form_settings_Git)
    {
        if (Form_settings_Git->objectName().isEmpty())
            Form_settings_Git->setObjectName("Form_settings_Git");
        Form_settings_Git->resize(800, 723);
        verticalLayout_4 = new QVBoxLayout(Form_settings_Git);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName("verticalLayout_4");
        groupBox = new QGroupBox(Form_settings_Git);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setMinimumSize(QSize(70, 0));
        label->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(label);

        lineEdit_gitPath = new QLineEdit(groupBox);
        lineEdit_gitPath->setObjectName("lineEdit_gitPath");

        horizontalLayout->addWidget(lineEdit_gitPath);

        btn_select = new QPushButton(groupBox);
        btn_select->setObjectName("btn_select");
        btn_select->setMinimumSize(QSize(60, 0));
        btn_select->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(btn_select);

        btn_test = new QPushButton(groupBox);
        btn_test->setObjectName("btn_test");
        btn_test->setMinimumSize(QSize(60, 0));
        btn_test->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(btn_test);


        verticalLayout->addLayout(horizontalLayout);

        label_tips = new QLabel(groupBox);
        label_tips->setObjectName("label_tips");

        verticalLayout->addWidget(label_tips);


        verticalLayout_4->addWidget(groupBox);

        groupBox_3 = new QGroupBox(Form_settings_Git);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(70, 0));
        label_4->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_userName = new QLineEdit(groupBox_3);
        lineEdit_userName->setObjectName("lineEdit_userName");
        lineEdit_userName->setMaximumSize(QSize(360, 16777215));

        horizontalLayout_4->addWidget(lineEdit_userName);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(70, 0));
        label_5->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_email = new QLineEdit(groupBox_3);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setMaximumSize(QSize(360, 16777215));

        horizontalLayout_5->addWidget(lineEdit_email);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(70, 0));
        label_6->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_psw = new QLineEdit(groupBox_3);
        lineEdit_psw->setObjectName("lineEdit_psw");
        lineEdit_psw->setMaximumSize(QSize(360, 16777215));
        lineEdit_psw->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(lineEdit_psw);

        checkBox_showPsw = new QCheckBox(groupBox_3);
        checkBox_showPsw->setObjectName("checkBox_showPsw");

        horizontalLayout_6->addWidget(checkBox_showPsw);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        pushButton_checkMsg = new QPushButton(groupBox_3);
        pushButton_checkMsg->setObjectName("pushButton_checkMsg");
        pushButton_checkMsg->setMinimumSize(QSize(140, 0));
        pushButton_checkMsg->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_7->addWidget(pushButton_checkMsg);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_4->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(Form_settings_Git);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(16);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        checkBox_track = new QCheckBox(groupBox_2);
        checkBox_track->setObjectName("checkBox_track");
        checkBox_track->setCheckable(true);
        checkBox_track->setChecked(true);

        horizontalLayout_2->addWidget(checkBox_track);

        checkBox_pushAddDate = new QCheckBox(groupBox_2);
        checkBox_pushAddDate->setObjectName("checkBox_pushAddDate");

        horizontalLayout_2->addWidget(checkBox_pushAddDate);

        checkBox_outMsg = new QCheckBox(groupBox_2);
        checkBox_outMsg->setObjectName("checkBox_outMsg");
        checkBox_outMsg->setChecked(true);

        horizontalLayout_2->addWidget(checkBox_outMsg);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_master = new QLineEdit(groupBox_2);
        lineEdit_master->setObjectName("lineEdit_master");

        horizontalLayout_3->addWidget(lineEdit_master);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_4->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 262, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        retranslateUi(Form_settings_Git);

        QMetaObject::connectSlotsByName(Form_settings_Git);
    } // setupUi

    void retranslateUi(QWidget *Form_settings_Git)
    {
        Form_settings_Git->setWindowTitle(QCoreApplication::translate("Form_settings_Git", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Form_settings_Git", "Git\347\250\213\345\272\217", nullptr));
        label->setText(QCoreApplication::translate("Form_settings_Git", "\347\250\213\345\272\217\350\267\257\345\276\204\357\274\232", nullptr));
        btn_select->setText(QCoreApplication::translate("Form_settings_Git", "\351\200\211\346\213\251", nullptr));
        btn_test->setText(QCoreApplication::translate("Form_settings_Git", "\346\265\213\350\257\225", nullptr));
        label_tips->setText(QCoreApplication::translate("Form_settings_Git", "Git\347\211\210\346\234\254\357\274\232\346\234\252\347\237\245\347\232\204\347\211\210\346\234\254", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Form_settings_Git", "\345\205\250\345\261\200\344\277\241\346\201\257", nullptr));
        label_4->setText(QCoreApplication::translate("Form_settings_Git", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("Form_settings_Git", "\351\202\256\347\256\261\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("Form_settings_Git", "\345\257\206\347\240\201\357\274\232", nullptr));
        lineEdit_psw->setText(QString());
        checkBox_showPsw->setText(QCoreApplication::translate("Form_settings_Git", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
        pushButton_checkMsg->setText(QCoreApplication::translate("Form_settings_Git", "\346\237\245\347\234\213Git\351\205\215\347\275\256\344\277\241\346\201\257", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Form_settings_Git", "\346\217\220\344\272\244", nullptr));
        checkBox_track->setText(QCoreApplication::translate("Form_settings_Git", "\350\207\252\345\212\250\350\267\237\350\270\252\346\211\200\346\234\211\347\232\204\346\226\207\344\273\266", nullptr));
        checkBox_pushAddDate->setText(QCoreApplication::translate("Form_settings_Git", "\346\217\220\344\272\244\346\227\266\346\267\273\345\212\240\346\217\220\344\272\244\346\227\245\346\234\237", nullptr));
        checkBox_outMsg->setText(QCoreApplication::translate("Form_settings_Git", "\350\276\223\345\207\272\346\217\220\344\272\244\344\277\241\346\201\257", nullptr));
        label_3->setText(QCoreApplication::translate("Form_settings_Git", "\351\273\230\350\256\244\346\217\220\344\272\244\345\210\206\346\224\257\357\274\232", nullptr));
        lineEdit_master->setText(QCoreApplication::translate("Form_settings_Git", "master", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_settings_Git: public Ui_Form_settings_Git {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SETTINGS_GIT_H
