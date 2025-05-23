/********************************************************************************
** Form generated from reading UI file 'Widget_Button_Start.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BUTTON_START_H
#define UI_WIDGET_BUTTON_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Button_Start
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_img;
    QVBoxLayout *verticalLayout;
    QLabel *label_main;
    QLabel *label_tip;

    void setupUi(QWidget *Widget_Button_Start)
    {
        if (Widget_Button_Start->objectName().isEmpty())
            Widget_Button_Start->setObjectName("Widget_Button_Start");
        Widget_Button_Start->resize(350, 71);
        Widget_Button_Start->setStyleSheet(QString::fromUtf8("#Widget_Button_Start{\n"
"	background-color: rgb(238, 235, 235);\n"
"}\n"
"\n"
"#label_main{\n"
"	color: rgb(28, 28, 28);\n"
"}\n"
"\n"
"#label_tip{\n"
"	color: rgb(79, 79, 79);\n"
"}"));
        horizontalLayout = new QHBoxLayout(Widget_Button_Start);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 7, 7, 7);
        label_img = new QLabel(Widget_Button_Start);
        label_img->setObjectName("label_img");
        label_img->setMinimumSize(QSize(48, 48));
        label_img->setMaximumSize(QSize(48, 48));
        label_img->setPixmap(QPixmap(QString::fromUtf8(":/WidgetIcon/icon/WidgetIcon/newCreate/open1.png")));

        horizontalLayout->addWidget(label_img);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_main = new QLabel(Widget_Button_Start);
        label_main->setObjectName("label_main");
        label_main->setMinimumSize(QSize(0, 28));
        label_main->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(14);
        label_main->setFont(font);

        verticalLayout->addWidget(label_main);

        label_tip = new QLabel(Widget_Button_Start);
        label_tip->setObjectName("label_tip");
        label_tip->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_tip->setWordWrap(true);

        verticalLayout->addWidget(label_tip);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Widget_Button_Start);

        QMetaObject::connectSlotsByName(Widget_Button_Start);
    } // setupUi

    void retranslateUi(QWidget *Widget_Button_Start)
    {
        Widget_Button_Start->setWindowTitle(QCoreApplication::translate("Widget_Button_Start", "Form", nullptr));
        label_img->setText(QString());
        label_main->setText(QCoreApplication::translate("Widget_Button_Start", "\351\273\230\350\256\244\346\214\211\351\222\256\346\240\207\351\242\230", nullptr));
        label_tip->setText(QCoreApplication::translate("Widget_Button_Start", "\345\211\257\346\240\207\351\242\230\357\274\214\347\224\250\344\272\216\346\255\244\346\214\211\351\222\256\346\216\247\344\273\266\347\232\204\345\212\237\350\203\275\350\247\243\351\207\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Button_Start: public Ui_Widget_Button_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BUTTON_START_H
