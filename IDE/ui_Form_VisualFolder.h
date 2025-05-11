/********************************************************************************
** Form generated from reading UI file 'Form_VisualFolder.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_VISUALFOLDER_H
#define UI_FORM_VISUALFOLDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_VisualFolder
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_modSelect;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_folderSign;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_folderName;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_img;
    QSpacerItem *horizontalSpacer;
    QLabel *label_nameTip;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_close;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Form_VisualFolder)
    {
        if (Form_VisualFolder->objectName().isEmpty())
            Form_VisualFolder->setObjectName("Form_VisualFolder");
        Form_VisualFolder->resize(365, 222);
        Form_VisualFolder->setStyleSheet(QString::fromUtf8("\n"
"/*\346\214\211\351\222\256\346\240\267\345\274\217*/\n"
"QPushButton{\n"
"	border-radius:0px;\n"
"	border:1px solid rgb(133, 145, 162);\n"
"	background-color: rgb(242, 245, 252);\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(196, 213, 255);\n"
"}\n"
"QPushButton:!enabled{\n"
"	color:rgb(162, 164, 165);\n"
"	background-color: rgb(223, 231, 243);\n"
"	border:1px solid rgb(162, 164, 165);\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(Form_VisualFolder);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(Form_VisualFolder);
        label->setObjectName("label");
        label->setMinimumSize(QSize(70, 0));
        label->setMaximumSize(QSize(70, 16777215));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        comboBox_modSelect = new QComboBox(Form_VisualFolder);
        comboBox_modSelect->addItem(QString());
        comboBox_modSelect->addItem(QString());
        comboBox_modSelect->addItem(QString());
        comboBox_modSelect->setObjectName("comboBox_modSelect");
        comboBox_modSelect->setMinimumSize(QSize(0, 30));
        comboBox_modSelect->setFont(font);

        horizontalLayout->addWidget(comboBox_modSelect);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(Form_VisualFolder);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(70, 0));
        label_2->setMaximumSize(QSize(70, 16777215));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lineEdit_folderSign = new QLineEdit(Form_VisualFolder);
        lineEdit_folderSign->setObjectName("lineEdit_folderSign");
        lineEdit_folderSign->setMinimumSize(QSize(0, 30));
        lineEdit_folderSign->setFont(font);

        horizontalLayout_2->addWidget(lineEdit_folderSign);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(Form_VisualFolder);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(70, 0));
        label_3->setMaximumSize(QSize(70, 16777215));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        lineEdit_folderName = new QLineEdit(Form_VisualFolder);
        lineEdit_folderName->setObjectName("lineEdit_folderName");
        lineEdit_folderName->setMinimumSize(QSize(0, 30));
        lineEdit_folderName->setFont(font);

        horizontalLayout_3->addWidget(lineEdit_folderName);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        label_img = new QLabel(Form_VisualFolder);
        label_img->setObjectName("label_img");
        label_img->setMinimumSize(QSize(70, 64));
        label_img->setMaximumSize(QSize(70, 64));
        label_img->setPixmap(QPixmap(QString::fromUtf8(":/WidgetIcon/icon/WidgetIcon/visualFolder/folder.png")));

        horizontalLayout_4->addWidget(label_img);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_nameTip = new QLabel(Form_VisualFolder);
        label_nameTip->setObjectName("label_nameTip");
        label_nameTip->setMinimumSize(QSize(100, 30));
        label_nameTip->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        label_nameTip->setFont(font1);
        label_nameTip->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_nameTip);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_5->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 9, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        pushButton_OK = new QPushButton(Form_VisualFolder);
        pushButton_OK->setObjectName("pushButton_OK");
        pushButton_OK->setMinimumSize(QSize(140, 40));

        horizontalLayout_6->addWidget(pushButton_OK);

        pushButton_close = new QPushButton(Form_VisualFolder);
        pushButton_close->setObjectName("pushButton_close");
        pushButton_close->setMinimumSize(QSize(140, 40));

        horizontalLayout_6->addWidget(pushButton_close);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_6);


        retranslateUi(Form_VisualFolder);

        comboBox_modSelect->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form_VisualFolder);
    } // setupUi

    void retranslateUi(QWidget *Form_VisualFolder)
    {
        Form_VisualFolder->setWindowTitle(QCoreApplication::translate("Form_VisualFolder", "\345\210\233\345\273\272\350\231\232\346\213\237\346\226\207\344\273\266\345\244\271", nullptr));
        label->setText(QCoreApplication::translate("Form_VisualFolder", "\345\210\206\347\261\273\347\261\273\345\236\213\357\274\232", nullptr));
        comboBox_modSelect->setItemText(0, QCoreApplication::translate("Form_VisualFolder", "\345\220\216\347\274\200\346\240\207\350\256\260\345\210\206\347\261\273", nullptr));
        comboBox_modSelect->setItemText(1, QCoreApplication::translate("Form_VisualFolder", "\345\211\215\347\274\200\346\240\207\350\256\260\345\210\206\347\261\273", nullptr));
        comboBox_modSelect->setItemText(2, QCoreApplication::translate("Form_VisualFolder", "\345\255\230\345\234\250\346\240\207\350\256\260\345\210\206\347\261\273", nullptr));

        label_2->setText(QCoreApplication::translate("Form_VisualFolder", "\345\210\206\347\261\273\346\240\207\350\256\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Form_VisualFolder", "\345\210\206\347\261\273\345\220\215\347\247\260\357\274\232", nullptr));
        lineEdit_folderName->setText(QCoreApplication::translate("Form_VisualFolder", "\346\226\260\350\231\232\346\213\237\345\210\206\347\261\273", nullptr));
        label_img->setText(QString());
        label_nameTip->setText(QCoreApplication::translate("Form_VisualFolder", "XXXX", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("Form_VisualFolder", "\347\241\256\350\256\244", nullptr));
        pushButton_close->setText(QCoreApplication::translate("Form_VisualFolder", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_VisualFolder: public Ui_Form_VisualFolder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_VISUALFOLDER_H
