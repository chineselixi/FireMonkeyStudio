/********************************************************************************
** Form generated from reading UI file 'Form_WidgetBox.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_WIDGETBOX_H
#define UI_FORM_WIDGETBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_WidgetBox
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *Form_WidgetBox)
    {
        if (Form_WidgetBox->objectName().isEmpty())
            Form_WidgetBox->setObjectName("Form_WidgetBox");
        Form_WidgetBox->resize(329, 615);
        Form_WidgetBox->setStyleSheet(QString::fromUtf8("#listWidget{\n"
"	background-color:rgb(247, 249, 254);\n"
"	outline:0px; /*\346\270\205\346\245\232\351\200\211\344\270\255\347\232\204\350\231\232\347\272\277*/\n"
"}\n"
"\n"
"\n"
"/*\345\210\227\350\241\250\346\214\211\351\222\256\346\240\267\345\274\217\357\274\214\346\263\250\346\204\217\357\274\214\345\217\252\346\230\257\351\222\210\345\257\271\345\210\227\350\241\250\346\234\211\346\225\210\343\200\202\344\275\206\346\230\257\345\257\271\345\233\276\346\240\207\346\250\241\345\274\217\344\270\213\346\227\240\346\225\210\n"
".Widget_Button_Start{\n"
"	background-color: rgb(238, 235, 235);\n"
"}\n"
".Widget_Button_Start:hover{\n"
"	background-color: rgb(208, 231, 248);\n"
"}\n"
"*/\n"
"\n"
" /*\345\255\220\351\241\271\346\240\267\345\274\217*/\n"
"#listWidget::item{\n"
"	background-color:rgb(247, 249, 254);\n"
"}\n"
"#listWidget::item:hover{\n"
"	border: 1px solid rgb(93, 107, 153);\n"
"}\n"
"#listWidget::item:selected {\n"
"	background-color:rgb(196, 213, 255)\n"
"}\n"
"\n"
"#listWidget::item:selected:!a"
                        "ctive{\n"
"	background-color: rgb(196, 213, 255);\n"
"}"));
        gridLayout = new QGridLayout(Form_WidgetBox);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(Form_WidgetBox);
        listWidget->setObjectName("listWidget");
        listWidget->setMovement(QListView::Static);
        listWidget->setResizeMode(QListView::Adjust);
        listWidget->setViewMode(QListView::IconMode);

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);


        retranslateUi(Form_WidgetBox);

        QMetaObject::connectSlotsByName(Form_WidgetBox);
    } // setupUi

    void retranslateUi(QWidget *Form_WidgetBox)
    {
        Form_WidgetBox->setWindowTitle(QCoreApplication::translate("Form_WidgetBox", "\346\216\247\344\273\266\347\256\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_WidgetBox: public Ui_Form_WidgetBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_WIDGETBOX_H
