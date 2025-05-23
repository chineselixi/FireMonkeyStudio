/********************************************************************************
** Form generated from reading UI file 'Widget_Statusbar.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_STATUSBAR_H
#define UI_WIDGET_STATUSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Statusbar
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QProgressBar *progressBar;
    QToolButton *toolButton_Tip;
    QToolButton *toolButton_1;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;

    void setupUi(QWidget *Widget_Statusbar)
    {
        if (Widget_Statusbar->objectName().isEmpty())
            Widget_Statusbar->setObjectName("Widget_Statusbar");
        Widget_Statusbar->resize(440, 23);
        horizontalLayout = new QHBoxLayout(Widget_Statusbar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        progressBar = new QProgressBar(Widget_Statusbar);
        progressBar->setObjectName("progressBar");
        progressBar->setMaximumSize(QSize(16777215, 12));
        progressBar->setFocusPolicy(Qt::NoFocus);
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"	border:1px solid #FFFFFF;\n"
"	border-radius:4px;\n"
"	text-align:center;\n"
"}"));
        progressBar->setValue(88);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        horizontalLayout->addWidget(progressBar);

        toolButton_Tip = new QToolButton(Widget_Statusbar);
        toolButton_Tip->setObjectName("toolButton_Tip");
        toolButton_Tip->setArrowType(Qt::UpArrow);

        horizontalLayout->addWidget(toolButton_Tip);

        toolButton_1 = new QToolButton(Widget_Statusbar);
        toolButton_1->setObjectName("toolButton_1");
        toolButton_1->setPopupMode(QToolButton::DelayedPopup);
        toolButton_1->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_1->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton_1);

        toolButton_2 = new QToolButton(Widget_Statusbar);
        toolButton_2->setObjectName("toolButton_2");
        toolButton_2->setPopupMode(QToolButton::DelayedPopup);
        toolButton_2->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_2->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(Widget_Statusbar);
        toolButton_3->setObjectName("toolButton_3");
        toolButton_3->setPopupMode(QToolButton::DelayedPopup);
        toolButton_3->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_3->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(Widget_Statusbar);
        toolButton_4->setObjectName("toolButton_4");
        toolButton_4->setPopupMode(QToolButton::DelayedPopup);
        toolButton_4->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_4->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(Widget_Statusbar);
        toolButton_5->setObjectName("toolButton_5");
        toolButton_5->setPopupMode(QToolButton::DelayedPopup);
        toolButton_5->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_5->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(Widget_Statusbar);
        toolButton_6->setObjectName("toolButton_6");
        toolButton_6->setPopupMode(QToolButton::DelayedPopup);
        toolButton_6->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_6->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton_6);


        retranslateUi(Widget_Statusbar);

        QMetaObject::connectSlotsByName(Widget_Statusbar);
    } // setupUi

    void retranslateUi(QWidget *Widget_Statusbar)
    {
        Widget_Statusbar->setWindowTitle(QCoreApplication::translate("Widget_Statusbar", "Form", nullptr));
        toolButton_Tip->setText(QString());
        toolButton_1->setText(QString());
        toolButton_2->setText(QString());
        toolButton_3->setText(QString());
        toolButton_4->setText(QString());
        toolButton_5->setText(QString());
        toolButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget_Statusbar: public Ui_Widget_Statusbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_STATUSBAR_H
