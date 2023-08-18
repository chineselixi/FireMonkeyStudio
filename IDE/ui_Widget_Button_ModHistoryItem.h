/********************************************************************************
** Form generated from reading UI file 'Widget_Button_ModHistoryItem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BUTTON_MODHISTORYITEM_H
#define UI_WIDGET_BUTTON_MODHISTORYITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Button_ModHistoryItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_img;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer;
    QLabel *label_mod;

    void setupUi(QWidget *Widget_Button_ModHistoryItem)
    {
        if (Widget_Button_ModHistoryItem->objectName().isEmpty())
            Widget_Button_ModHistoryItem->setObjectName("Widget_Button_ModHistoryItem");
        Widget_Button_ModHistoryItem->resize(431, 50);
        Widget_Button_ModHistoryItem->setStyleSheet(QString::fromUtf8("#Widget_Button_ModHistoryItem{\n"
"	background-color: rgb(238, 235, 235);\n"
"}\n"
"\n"
"#label_tip{\n"
"	color: rgb(28, 28, 28);\n"
"}\n"
"\n"
"\n"
"#label_mod{\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(255, 255, 255);\n"
"    border-radius:6px;\n"
"	padding:4px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(Widget_Button_ModHistoryItem);
        horizontalLayout->setObjectName("horizontalLayout");
        label_img = new QLabel(Widget_Button_ModHistoryItem);
        label_img->setObjectName("label_img");
        label_img->setMinimumSize(QSize(20, 20));
        label_img->setMaximumSize(QSize(20, 20));
        label_img->setPixmap(QPixmap(QString::fromUtf8(":/WidgetIcon/icon/WidgetIcon/newCreate/open1.png")));

        horizontalLayout->addWidget(label_img);

        label_title = new QLabel(Widget_Button_ModHistoryItem);
        label_title->setObjectName("label_title");
        QFont font;
        font.setPointSize(9);
        label_title->setFont(font);
        label_title->setScaledContents(false);
        label_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_title->setWordWrap(false);
        label_title->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        horizontalLayout->addWidget(label_title);

        horizontalSpacer = new QSpacerItem(289, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_mod = new QLabel(Widget_Button_ModHistoryItem);
        label_mod->setObjectName("label_mod");
        label_mod->setMinimumSize(QSize(0, 0));
        label_mod->setMaximumSize(QSize(16777215, 16777215));
        label_mod->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_mod);


        retranslateUi(Widget_Button_ModHistoryItem);

        QMetaObject::connectSlotsByName(Widget_Button_ModHistoryItem);
    } // setupUi

    void retranslateUi(QWidget *Widget_Button_ModHistoryItem)
    {
        Widget_Button_ModHistoryItem->setWindowTitle(QCoreApplication::translate("Widget_Button_ModHistoryItem", "Form", nullptr));
        label_img->setText(QString());
        label_title->setText(QCoreApplication::translate("Widget_Button_ModHistoryItem", "\347\251\272\346\250\241\346\235\277", nullptr));
        label_mod->setText(QCoreApplication::translate("Widget_Button_ModHistoryItem", "Python", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Button_ModHistoryItem: public Ui_Widget_Button_ModHistoryItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BUTTON_MODHISTORYITEM_H
