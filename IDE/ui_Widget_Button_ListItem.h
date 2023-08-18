/********************************************************************************
** Form generated from reading UI file 'Widget_Button_ListItem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BUTTON_LISTITEM_H
#define UI_WIDGET_BUTTON_LISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Button_ListItem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_img;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_main;
    QLabel *label_time;
    QLabel *label_tip;

    void setupUi(QWidget *Widget_Button_ListItem)
    {
        if (Widget_Button_ListItem->objectName().isEmpty())
            Widget_Button_ListItem->setObjectName("Widget_Button_ListItem");
        Widget_Button_ListItem->resize(400, 83);
        Widget_Button_ListItem->setStyleSheet(QString::fromUtf8("#Widget_Button_Start{\n"
"	background-color: rgb(238, 235, 235);\n"
"}\n"
"\n"
"#label_main{\n"
"	color: rgb(28, 28, 28);\n"
"}\n"
"\n"
"#label_tip{\n"
"	color: rgb(79, 79, 79);\n"
"}\n"
"\n"
"#label_time{\n"
"	color: rgb(79, 79, 79);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(Widget_Button_ListItem);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(5, 15, 5, 15);
        label_img = new QLabel(Widget_Button_ListItem);
        label_img->setObjectName("label_img");
        label_img->setMinimumSize(QSize(32, 32));
        label_img->setMaximumSize(QSize(32, 32));
        label_img->setPixmap(QPixmap(QString::fromUtf8(":/WidgetIcon/icon/WidgetIcon/newCreate/open1.png")));

        horizontalLayout_2->addWidget(label_img);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_main = new QLabel(Widget_Button_ListItem);
        label_main->setObjectName("label_main");
        label_main->setMinimumSize(QSize(0, 0));
        label_main->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_main->setFont(font);

        horizontalLayout->addWidget(label_main);

        label_time = new QLabel(Widget_Button_ListItem);
        label_time->setObjectName("label_time");
        label_time->setMaximumSize(QSize(120, 16777215));
        QFont font1;
        font1.setPointSize(9);
        label_time->setFont(font1);
        label_time->setScaledContents(false);
        label_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_time->setWordWrap(false);
        label_time->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        horizontalLayout->addWidget(label_time);


        verticalLayout->addLayout(horizontalLayout);

        label_tip = new QLabel(Widget_Button_ListItem);
        label_tip->setObjectName("label_tip");
        label_tip->setFont(font1);
        label_tip->setScaledContents(false);
        label_tip->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_tip->setWordWrap(false);
        label_tip->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        verticalLayout->addWidget(label_tip);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(Widget_Button_ListItem);

        QMetaObject::connectSlotsByName(Widget_Button_ListItem);
    } // setupUi

    void retranslateUi(QWidget *Widget_Button_ListItem)
    {
        Widget_Button_ListItem->setWindowTitle(QCoreApplication::translate("Widget_Button_ListItem", "Form", nullptr));
        label_img->setText(QString());
        label_main->setText(QCoreApplication::translate("Widget_Button_ListItem", "ProJect1.fmo", nullptr));
        label_time->setText(QCoreApplication::translate("Widget_Button_ListItem", "1949/10/10 12:00", nullptr));
        label_tip->setText(QCoreApplication::translate("Widget_Button_ListItem", "C:/Users/Admin/Documents/src", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Button_ListItem: public Ui_Widget_Button_ListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BUTTON_LISTITEM_H
