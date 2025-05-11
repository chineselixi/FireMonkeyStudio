/********************************************************************************
** Form generated from reading UI file 'Widget_Button_CompletionItem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BUTTON_COMPLETIONITEM_H
#define UI_WIDGET_BUTTON_COMPLETIONITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Button_CompletionItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_img;
    QLabel *label_title;

    void setupUi(QWidget *Widget_Button_CompletionItem)
    {
        if (Widget_Button_CompletionItem->objectName().isEmpty())
            Widget_Button_CompletionItem->setObjectName("Widget_Button_CompletionItem");
        Widget_Button_CompletionItem->resize(173, 24);
        Widget_Button_CompletionItem->setMinimumSize(QSize(0, 20));
        Widget_Button_CompletionItem->setMaximumSize(QSize(16777215, 24));
        horizontalLayout = new QHBoxLayout(Widget_Button_CompletionItem);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        label_img = new QLabel(Widget_Button_CompletionItem);
        label_img->setObjectName("label_img");
        label_img->setMinimumSize(QSize(20, 20));
        label_img->setMaximumSize(QSize(20, 20));
        label_img->setPixmap(QPixmap(QString::fromUtf8(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CursorFile_16x.png")));

        horizontalLayout->addWidget(label_img);

        label_title = new QLabel(Widget_Button_CompletionItem);
        label_title->setObjectName("label_title");
        QFont font;
        font.setPointSize(9);
        label_title->setFont(font);
        label_title->setScaledContents(false);
        label_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_title->setWordWrap(false);
        label_title->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        horizontalLayout->addWidget(label_title);


        retranslateUi(Widget_Button_CompletionItem);

        QMetaObject::connectSlotsByName(Widget_Button_CompletionItem);
    } // setupUi

    void retranslateUi(QWidget *Widget_Button_CompletionItem)
    {
        Widget_Button_CompletionItem->setWindowTitle(QCoreApplication::translate("Widget_Button_CompletionItem", "Form", nullptr));
        label_img->setText(QString());
        label_title->setText(QCoreApplication::translate("Widget_Button_CompletionItem", "\346\214\207\351\222\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Button_CompletionItem: public Ui_Widget_Button_CompletionItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BUTTON_COMPLETIONITEM_H
