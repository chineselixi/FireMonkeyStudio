/********************************************************************************
** Form generated from reading UI file 'Widget_Button_HistoryItem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BUTTON_HISTORYITEM_H
#define UI_WIDGET_BUTTON_HISTORYITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Button_HistoryItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_ico;
    QVBoxLayout *verticalLayout;
    QLabel *label_mainTip;
    QLabel *label_secTip;
    QPushButton *pushButton_close;

    void setupUi(QWidget *Widget_Button_HistoryItem)
    {
        if (Widget_Button_HistoryItem->objectName().isEmpty())
            Widget_Button_HistoryItem->setObjectName("Widget_Button_HistoryItem");
        Widget_Button_HistoryItem->resize(220, 50);
        Widget_Button_HistoryItem->setMinimumSize(QSize(0, 50));
        Widget_Button_HistoryItem->setMaximumSize(QSize(16777215, 50));
        Widget_Button_HistoryItem->setCursor(QCursor(Qt::PointingHandCursor));
        horizontalLayout = new QHBoxLayout(Widget_Button_HistoryItem);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        label_ico = new QLabel(Widget_Button_HistoryItem);
        label_ico->setObjectName("label_ico");
        label_ico->setMinimumSize(QSize(40, 40));
        label_ico->setMaximumSize(QSize(40, 40));
        label_ico->setPixmap(QPixmap(QString::fromUtf8(":/Other/icon/Other/damage.png")));
        label_ico->setScaledContents(true);

        horizontalLayout->addWidget(label_ico);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        label_mainTip = new QLabel(Widget_Button_HistoryItem);
        label_mainTip->setObjectName("label_mainTip");
        label_mainTip->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(12);
        label_mainTip->setFont(font);

        verticalLayout->addWidget(label_mainTip);

        label_secTip = new QLabel(Widget_Button_HistoryItem);
        label_secTip->setObjectName("label_secTip");

        verticalLayout->addWidget(label_secTip);


        horizontalLayout->addLayout(verticalLayout);

        pushButton_close = new QPushButton(Widget_Button_HistoryItem);
        pushButton_close->setObjectName("pushButton_close");
        pushButton_close->setMinimumSize(QSize(16, 16));
        pushButton_close->setMaximumSize(QSize(26, 26));
        pushButton_close->setFlat(true);

        horizontalLayout->addWidget(pushButton_close);


        retranslateUi(Widget_Button_HistoryItem);

        QMetaObject::connectSlotsByName(Widget_Button_HistoryItem);
    } // setupUi

    void retranslateUi(QWidget *Widget_Button_HistoryItem)
    {
        Widget_Button_HistoryItem->setWindowTitle(QCoreApplication::translate("Widget_Button_HistoryItem", "Form", nullptr));
        label_ico->setText(QString());
        label_mainTip->setText(QCoreApplication::translate("Widget_Button_HistoryItem", "\346\265\213\350\257\225\346\240\207\351\242\230", nullptr));
        label_secTip->setText(QCoreApplication::translate("Widget_Button_HistoryItem", "\350\277\231\346\230\257\345\211\257\346\240\207\351\242\230", nullptr));
        pushButton_close->setText(QCoreApplication::translate("Widget_Button_HistoryItem", "\303\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Button_HistoryItem: public Ui_Widget_Button_HistoryItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BUTTON_HISTORYITEM_H
