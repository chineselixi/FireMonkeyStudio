/********************************************************************************
** Form generated from reading UI file 'Widget_Button_WidgetItem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BUTTON_WIDGETITEM_H
#define UI_WIDGET_BUTTON_WIDGETITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Button_WidgetItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_img;
    QLabel *label_title;

    void setupUi(QWidget *Widget_Button_WidgetItem)
    {
        if (Widget_Button_WidgetItem->objectName().isEmpty())
            Widget_Button_WidgetItem->setObjectName("Widget_Button_WidgetItem");
        Widget_Button_WidgetItem->resize(100, 32);
        Widget_Button_WidgetItem->setStyleSheet(QString::fromUtf8("#label_title{\n"
"	color:rgb(39, 33, 46);\n"
"}"));
        horizontalLayout = new QHBoxLayout(Widget_Button_WidgetItem);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 6, 10, 6);
        label_img = new QLabel(Widget_Button_WidgetItem);
        label_img->setObjectName("label_img");
        label_img->setMinimumSize(QSize(20, 20));
        label_img->setMaximumSize(QSize(20, 20));
        label_img->setPixmap(QPixmap(QString::fromUtf8(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CursorFile_16x.png")));

        horizontalLayout->addWidget(label_img);

        label_title = new QLabel(Widget_Button_WidgetItem);
        label_title->setObjectName("label_title");
        QFont font;
        font.setPointSize(9);
        label_title->setFont(font);
        label_title->setScaledContents(false);
        label_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_title->setWordWrap(false);
        label_title->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        horizontalLayout->addWidget(label_title);


        retranslateUi(Widget_Button_WidgetItem);

        QMetaObject::connectSlotsByName(Widget_Button_WidgetItem);
    } // setupUi

    void retranslateUi(QWidget *Widget_Button_WidgetItem)
    {
        Widget_Button_WidgetItem->setWindowTitle(QCoreApplication::translate("Widget_Button_WidgetItem", "Form", nullptr));
        label_img->setText(QString());
        label_title->setText(QCoreApplication::translate("Widget_Button_WidgetItem", "\346\214\207\351\222\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Button_WidgetItem: public Ui_Widget_Button_WidgetItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BUTTON_WIDGETITEM_H
