/********************************************************************************
** Form generated from reading UI file 'Widget_HistoryList.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_HISTORYLIST_H
#define UI_WIDGET_HISTORYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_HistoryList
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_clear;
    QLabel *label_tip;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_clear;

    void setupUi(QWidget *Widget_HistoryList)
    {
        if (Widget_HistoryList->objectName().isEmpty())
            Widget_HistoryList->setObjectName("Widget_HistoryList");
        Widget_HistoryList->resize(220, 365);
        verticalLayout = new QVBoxLayout(Widget_HistoryList);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(Widget_HistoryList);
        listWidget->setObjectName("listWidget");
        listWidget->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
""));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setMovement(QListView::Snap);

        verticalLayout->addWidget(listWidget);

        horizontalLayout_clear = new QHBoxLayout();
        horizontalLayout_clear->setObjectName("horizontalLayout_clear");
        label_tip = new QLabel(Widget_HistoryList);
        label_tip->setObjectName("label_tip");
        QFont font;
        font.setPointSize(12);
        label_tip->setFont(font);

        horizontalLayout_clear->addWidget(label_tip);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_clear->addItem(horizontalSpacer_2);

        pushButton_clear = new QPushButton(Widget_HistoryList);
        pushButton_clear->setObjectName("pushButton_clear");
        pushButton_clear->setFont(font);
        pushButton_clear->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_clear->setFlat(true);

        horizontalLayout_clear->addWidget(pushButton_clear);


        verticalLayout->addLayout(horizontalLayout_clear);


        retranslateUi(Widget_HistoryList);

        QMetaObject::connectSlotsByName(Widget_HistoryList);
    } // setupUi

    void retranslateUi(QWidget *Widget_HistoryList)
    {
        Widget_HistoryList->setWindowTitle(QCoreApplication::translate("Widget_HistoryList", "Form", nullptr));
        label_tip->setText(QCoreApplication::translate("Widget_HistoryList", "\346\262\241\346\234\211\345\216\206\345\217\262\345\267\245\347\250\213", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("Widget_HistoryList", "\346\270\205\347\251\272\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_HistoryList: public Ui_Widget_HistoryList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_HISTORYLIST_H
