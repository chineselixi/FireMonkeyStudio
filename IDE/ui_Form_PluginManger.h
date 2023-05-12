/********************************************************************************
** Form generated from reading UI file 'Form_PluginManger.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_PLUGINMANGER_H
#define UI_FORM_PLUGINMANGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_PluginManger
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_plugin;
    QVBoxLayout *verticalLayout;
    QLabel *label_tip2;
    QLabel *label_signTip;

    void setupUi(QWidget *Form_PluginManger)
    {
        if (Form_PluginManger->objectName().isEmpty())
            Form_PluginManger->setObjectName("Form_PluginManger");
        Form_PluginManger->resize(900, 600);
        Form_PluginManger->setStyleSheet(QString::fromUtf8("/*\344\270\273\350\203\214\346\231\257\345\222\214\345\210\227\350\241\250\350\203\214\346\231\257*/\n"
"#Form_PluginManger,QListWidget{\n"
"	background-color: rgb(245, 245, 245);\n"
"}\n"
"\n"
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
"}\n"
"\n"
"/*\350\256\276\345\256\232\345\210\227\350\241\250\350\276\271\346\241\206*/\n"
"/*\345\210\227\350\241\250\346\240\267\345\274\217*/\n"
"QListWidget{\n"
"	border:0px;\n"
"}\n"
"QListWidget::item:selected{\n"
"    background-color: #B5E7FF;\n"
"    color: black;\n"
"}"));
        horizontalLayout = new QHBoxLayout(Form_PluginManger);
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName("horizontalLayout");
        listWidget_plugin = new QListWidget(Form_PluginManger);
        listWidget_plugin->setObjectName("listWidget_plugin");
        listWidget_plugin->setSelectionBehavior(QAbstractItemView::SelectItems);

        horizontalLayout->addWidget(listWidget_plugin);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName("verticalLayout");
        label_tip2 = new QLabel(Form_PluginManger);
        label_tip2->setObjectName("label_tip2");
        label_tip2->setMinimumSize(QSize(250, 30));
        label_tip2->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        label_tip2->setFont(font);
        label_tip2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label_tip2);

        label_signTip = new QLabel(Form_PluginManger);
        label_signTip->setObjectName("label_signTip");
        label_signTip->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_signTip->setWordWrap(true);

        verticalLayout->addWidget(label_signTip);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Form_PluginManger);

        QMetaObject::connectSlotsByName(Form_PluginManger);
    } // setupUi

    void retranslateUi(QWidget *Form_PluginManger)
    {
        Form_PluginManger->setWindowTitle(QCoreApplication::translate("Form_PluginManger", "\346\217\222\344\273\266\347\256\241\347\220\206\345\231\250", nullptr));
        label_tip2->setText(QCoreApplication::translate("Form_PluginManger", "\346\217\222\344\273\266\350\257\246\346\203\205\344\277\241\346\201\257", nullptr));
        label_signTip->setText(QCoreApplication::translate("Form_PluginManger", "<html><head/><body><p>\346\217\222\344\273\266\347\256\241\347\220\206\345\231\250\357\274\214\347\224\250\344\272\216\346\213\223\345\261\225IDE\347\232\204\345\237\272\347\241\200\345\212\237\350\203\275\343\200\202\346\217\222\344\273\266\347\232\204\350\256\276\347\275\256\345\217\230\345\212\250\351\234\200\350\246\201\351\207\215\345\220\257IDE\346\211\215\350\203\275\346\255\243\345\270\270\345\267\245\344\275\234\343\200\202</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_PluginManger: public Ui_Form_PluginManger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_PLUGINMANGER_H
