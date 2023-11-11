/********************************************************************************
** Form generated from reading UI file 'Widget_Button_ModItem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BUTTON_MODITEM_H
#define UI_WIDGET_BUTTON_MODITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Button_ModItem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_img;
    QVBoxLayout *verticalLayout;
    QLabel *label_main;
    QLabel *label_tip;
    QHBoxLayout *horizontalLayout;
    QLabel *label_lang;
    QLabel *label_os;
    QLabel *label_other;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Widget_Button_ModItem)
    {
        if (Widget_Button_ModItem->objectName().isEmpty())
            Widget_Button_ModItem->setObjectName("Widget_Button_ModItem");
        Widget_Button_ModItem->resize(315, 81);
        Widget_Button_ModItem->setStyleSheet(QString::fromUtf8("#Widget_Button_Moditem{\n"
"	background-color: rgb(238, 235, 235);\n"
"}\n"
"\n"
"#label_main{\n"
"	color: rgb(0,0,0);\n"
"}\n"
"\n"
"#label_tip{\n"
"	color: rgb(79, 79, 79);\n"
"}\n"
"\n"
"/*\351\231\204\345\212\240\345\271\263\345\217\260\346\240\207\347\255\276*/\n"
"#label_lang,#label_os,#label_other{\n"
"	color: rgb(28, 28, 28);\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius:8px;\n"
"	padding:4px;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(Widget_Button_ModItem);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 6, -1, 6);
        label_img = new QLabel(Widget_Button_ModItem);
        label_img->setObjectName("label_img");
        label_img->setMinimumSize(QSize(48, 48));
        label_img->setMaximumSize(QSize(48, 48));
        label_img->setPixmap(QPixmap(QString::fromUtf8(":/WidgetIcon/icon/WidgetIcon/newCreate/open1.png")));

        horizontalLayout_2->addWidget(label_img);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        label_main = new QLabel(Widget_Button_ModItem);
        label_main->setObjectName("label_main");
        label_main->setMinimumSize(QSize(0, 20));
        label_main->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(9);
        label_main->setFont(font);

        verticalLayout->addWidget(label_main);

        label_tip = new QLabel(Widget_Button_ModItem);
        label_tip->setObjectName("label_tip");
        label_tip->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_tip->setWordWrap(true);

        verticalLayout->addWidget(label_tip);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        label_lang = new QLabel(Widget_Button_ModItem);
        label_lang->setObjectName("label_lang");
        QFont font1;
        font1.setPointSize(8);
        label_lang->setFont(font1);

        horizontalLayout->addWidget(label_lang);

        label_os = new QLabel(Widget_Button_ModItem);
        label_os->setObjectName("label_os");
        label_os->setFont(font1);

        horizontalLayout->addWidget(label_os);

        label_other = new QLabel(Widget_Button_ModItem);
        label_other->setObjectName("label_other");
        label_other->setFont(font1);

        horizontalLayout->addWidget(label_other);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(Widget_Button_ModItem);

        QMetaObject::connectSlotsByName(Widget_Button_ModItem);
    } // setupUi

    void retranslateUi(QWidget *Widget_Button_ModItem)
    {
        Widget_Button_ModItem->setWindowTitle(QCoreApplication::translate("Widget_Button_ModItem", "Form", nullptr));
        label_img->setText(QString());
        label_main->setText(QCoreApplication::translate("Widget_Button_ModItem", "\351\273\230\350\256\244\346\214\211\351\222\256\346\240\207\351\242\230", nullptr));
        label_tip->setText(QCoreApplication::translate("Widget_Button_ModItem", "\345\211\257\346\240\207\351\242\230\357\274\214\347\224\250\344\272\216\346\255\244\346\214\211\351\222\256\346\216\247\344\273\266\347\232\204\345\212\237\350\203\275\350\247\243\351\207\212", nullptr));
        label_lang->setText(QCoreApplication::translate("Widget_Button_ModItem", "\351\273\230\350\256\244\350\257\255\350\250\200", nullptr));
        label_os->setText(QCoreApplication::translate("Widget_Button_ModItem", "\351\273\230\350\256\244\345\271\263\345\217\260", nullptr));
        label_other->setText(QCoreApplication::translate("Widget_Button_ModItem", "\351\273\230\350\256\244\351\231\204\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Button_ModItem: public Ui_Widget_Button_ModItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BUTTON_MODITEM_H
