/********************************************************************************
** Form generated from reading UI file 'Widget_TipItem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_TIPITEM_H
#define UI_WIDGET_TIPITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_TipItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_img;
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QLabel *label_tip;
    QProgressBar *tipItem_pgBar;
    QToolButton *btn_close;

    void setupUi(QWidget *Widget_TipItem)
    {
        if (Widget_TipItem->objectName().isEmpty())
            Widget_TipItem->setObjectName("Widget_TipItem");
        Widget_TipItem->resize(186, 61);
        Widget_TipItem->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(Widget_TipItem);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(2, 6, 2, 6);
        label_img = new QLabel(Widget_TipItem);
        label_img->setObjectName("label_img");
        label_img->setMinimumSize(QSize(32, 32));
        label_img->setMaximumSize(QSize(32, 32));
        label_img->setPixmap(QPixmap(QString::fromUtf8(":/WidgetIcon/icon/WidgetIcon/newCreate/open1.png")));

        horizontalLayout->addWidget(label_img);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName("verticalLayout");
        label_title = new QLabel(Widget_TipItem);
        label_title->setObjectName("label_title");
        label_title->setMinimumSize(QSize(0, 0));
        label_title->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_title);

        label_tip = new QLabel(Widget_TipItem);
        label_tip->setObjectName("label_tip");
        QFont font1;
        font1.setPointSize(8);
        label_tip->setFont(font1);
        label_tip->setScaledContents(false);
        label_tip->setAlignment(Qt::AlignCenter);
        label_tip->setWordWrap(false);
        label_tip->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        verticalLayout->addWidget(label_tip);

        tipItem_pgBar = new QProgressBar(Widget_TipItem);
        tipItem_pgBar->setObjectName("tipItem_pgBar");
        tipItem_pgBar->setMinimumSize(QSize(0, 4));
        tipItem_pgBar->setMaximumSize(QSize(16777215, 4));
        QFont font2;
        font2.setPointSize(6);
        tipItem_pgBar->setFont(font2);
        tipItem_pgBar->setFocusPolicy(Qt::NoFocus);
        tipItem_pgBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        tipItem_pgBar->setLayoutDirection(Qt::LeftToRight);
        tipItem_pgBar->setAutoFillBackground(false);
        tipItem_pgBar->setStyleSheet(QString::fromUtf8("#tipItem_pgBar{background-color:#C8C8C8;color:white;}#tipItem_pgBar::chunk{background-color:#2688ff;}\n"
""));
        tipItem_pgBar->setValue(24);
        tipItem_pgBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tipItem_pgBar->setOrientation(Qt::Horizontal);
        tipItem_pgBar->setInvertedAppearance(false);
        tipItem_pgBar->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout->addWidget(tipItem_pgBar);


        horizontalLayout->addLayout(verticalLayout);

        btn_close = new QToolButton(Widget_TipItem);
        btn_close->setObjectName("btn_close");
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        btn_close->setFont(font3);
        btn_close->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayout->addWidget(btn_close);


        retranslateUi(Widget_TipItem);

        QMetaObject::connectSlotsByName(Widget_TipItem);
    } // setupUi

    void retranslateUi(QWidget *Widget_TipItem)
    {
        Widget_TipItem->setWindowTitle(QCoreApplication::translate("Widget_TipItem", "Form", nullptr));
        label_img->setText(QString());
        label_title->setText(QCoreApplication::translate("Widget_TipItem", "NULL", nullptr));
        label_tip->setText(QCoreApplication::translate("Widget_TipItem", "No prompt message", nullptr));
        tipItem_pgBar->setFormat(QString());
        btn_close->setText(QCoreApplication::translate("Widget_TipItem", "\303\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_TipItem: public Ui_Widget_TipItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_TIPITEM_H
