/********************************************************************************
** Form generated from reading UI file 'Form_Start.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_START_H
#define UI_FORM_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Widget/Widget_HistoryList.h"

QT_BEGIN_NAMESPACE

class Ui_Form_Start
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaMain;
    QVBoxLayout *verticalLayout;
    QWidget *widget_title;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_title1;
    QLabel *label_title2;
    QWidget *widget_body;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_left;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_start;
    QPushButton *pushButton_new;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_open;
    QPushButton *pushButton_store;
    QPushButton *pushButton_set;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_history;
    Widget_HistoryList *widget_historyList;
    QWidget *widget_right;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_Notice;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_notice;
    QLabel *label;
    QWidget *widget_news;
    QLabel *label_news;

    void setupUi(QWidget *Form_Start)
    {
        if (Form_Start->objectName().isEmpty())
            Form_Start->setObjectName("Form_Start");
        Form_Start->resize(841, 663);
        Form_Start->setStyleSheet(QString::fromUtf8("#Form_Start{\n"
"	background-color: #f2f2f2;\n"
"}\n"
"\n"
"#widget_title{\n"
"	background-color: rgb(92, 45, 145);\n"
"}\n"
"\n"
"#label_title1,#label_title2{\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"#label_start,#label_history,#label_notice,#label_news{\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QPushButton{\n"
"	padding:0px;\n"
"}\n"
"\n"
"#pushButton_new,#pushButton_open,#pushButton_store,#pushButton_set,#label_history_tip,#widget_historyList>#label_tip,#widget_historyList>#pushButton_clear{\n"
"	color: royalblue;\n"
"}\n"
""));
        gridLayout_2 = new QGridLayout(Form_Start);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(Form_Start);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaMain = new QWidget();
        scrollAreaMain->setObjectName("scrollAreaMain");
        scrollAreaMain->setGeometry(QRect(0, 0, 841, 663));
        verticalLayout = new QVBoxLayout(scrollAreaMain);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(scrollAreaMain);
        widget_title->setObjectName("widget_title");
        widget_title->setMinimumSize(QSize(0, 160));
        widget_title->setMaximumSize(QSize(16777215, 160));
        verticalLayout_2 = new QVBoxLayout(widget_title);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(40, 40, 0, 40);
        label_title1 = new QLabel(widget_title);
        label_title1->setObjectName("label_title1");
        QFont font;
        font.setPointSize(32);
        font.setBold(true);
        label_title1->setFont(font);

        verticalLayout_2->addWidget(label_title1);

        label_title2 = new QLabel(widget_title);
        label_title2->setObjectName("label_title2");
        QFont font1;
        font1.setPointSize(14);
        label_title2->setFont(font1);

        verticalLayout_2->addWidget(label_title2);


        verticalLayout->addWidget(widget_title);

        widget_body = new QWidget(scrollAreaMain);
        widget_body->setObjectName("widget_body");
        horizontalLayout = new QHBoxLayout(widget_body);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_left = new QWidget(widget_body);
        widget_left->setObjectName("widget_left");
        widget_left->setMinimumSize(QSize(300, 0));
        widget_left->setMaximumSize(QSize(300, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_left);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(40, 40, 40, 40);
        widget = new QWidget(widget_left);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 170));
        widget->setMaximumSize(QSize(16777215, 250));
        QFont font2;
        font2.setPointSize(12);
        widget->setFont(font2);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_start = new QLabel(widget);
        label_start->setObjectName("label_start");
        label_start->setMinimumSize(QSize(0, 36));
        label_start->setMaximumSize(QSize(16777215, 40));
        QFont font3;
        font3.setPointSize(22);
        font3.setBold(true);
        label_start->setFont(font3);

        gridLayout->addWidget(label_start, 0, 0, 1, 1);

        pushButton_new = new QPushButton(widget);
        pushButton_new->setObjectName("pushButton_new");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_new->sizePolicy().hasHeightForWidth());
        pushButton_new->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setUnderline(false);
        font4.setStrikeOut(false);
        font4.setKerning(true);
        pushButton_new->setFont(font4);
        pushButton_new->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_new->setFocusPolicy(Qt::StrongFocus);
        pushButton_new->setLayoutDirection(Qt::LeftToRight);
        pushButton_new->setInputMethodHints(Qt::ImhNone);
        pushButton_new->setFlat(true);

        gridLayout->addWidget(pushButton_new, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(153, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 2, 1);

        pushButton_open = new QPushButton(widget);
        pushButton_open->setObjectName("pushButton_open");
        sizePolicy.setHeightForWidth(pushButton_open->sizePolicy().hasHeightForWidth());
        pushButton_open->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setPointSize(12);
        font5.setKerning(true);
        pushButton_open->setFont(font5);
        pushButton_open->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_open->setLayoutDirection(Qt::LeftToRight);
        pushButton_open->setFlat(true);

        gridLayout->addWidget(pushButton_open, 2, 0, 1, 1);

        pushButton_store = new QPushButton(widget);
        pushButton_store->setObjectName("pushButton_store");
        sizePolicy.setHeightForWidth(pushButton_store->sizePolicy().hasHeightForWidth());
        pushButton_store->setSizePolicy(sizePolicy);
        pushButton_store->setFont(font5);
        pushButton_store->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_store->setLayoutDirection(Qt::LeftToRight);
        pushButton_store->setFlat(true);

        gridLayout->addWidget(pushButton_store, 3, 0, 1, 1);

        pushButton_set = new QPushButton(widget);
        pushButton_set->setObjectName("pushButton_set");
        sizePolicy.setHeightForWidth(pushButton_set->sizePolicy().hasHeightForWidth());
        pushButton_set->setSizePolicy(sizePolicy);
        pushButton_set->setFont(font5);
        pushButton_set->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_set->setLayoutDirection(Qt::LeftToRight);
        pushButton_set->setFlat(true);

        gridLayout->addWidget(pushButton_set, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);


        verticalLayout_3->addWidget(widget);

        widget_2 = new QWidget(widget_left);
        widget_2->setObjectName("widget_2");
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_history = new QLabel(widget_2);
        label_history->setObjectName("label_history");
        label_history->setMinimumSize(QSize(0, 36));
        label_history->setMaximumSize(QSize(16777215, 40));
        label_history->setFont(font3);

        verticalLayout_5->addWidget(label_history);

        widget_historyList = new Widget_HistoryList(widget_2);
        widget_historyList->setObjectName("widget_historyList");

        verticalLayout_5->addWidget(widget_historyList);


        verticalLayout_3->addWidget(widget_2);


        horizontalLayout->addWidget(widget_left);

        widget_right = new QWidget(widget_body);
        widget_right->setObjectName("widget_right");
        verticalLayout_6 = new QVBoxLayout(widget_right);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(40, 40, 40, 40);
        widget_Notice = new QWidget(widget_right);
        widget_Notice->setObjectName("widget_Notice");
        widget_Notice->setMinimumSize(QSize(0, 170));
        widget_Notice->setMaximumSize(QSize(16777215, 250));
        verticalLayout_7 = new QVBoxLayout(widget_Notice);
        verticalLayout_7->setSpacing(10);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_notice = new QLabel(widget_Notice);
        label_notice->setObjectName("label_notice");
        label_notice->setMinimumSize(QSize(0, 36));
        label_notice->setMaximumSize(QSize(16777215, 40));
        label_notice->setFont(font3);

        verticalLayout_7->addWidget(label_notice);

        label = new QLabel(widget_Notice);
        label->setObjectName("label");
        label->setFont(font2);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_7->addWidget(label);


        verticalLayout_6->addWidget(widget_Notice);

        widget_news = new QWidget(widget_right);
        widget_news->setObjectName("widget_news");
        widget_news->setMinimumSize(QSize(0, 0));
        widget_news->setMaximumSize(QSize(16777215, 16777215));
        label_news = new QLabel(widget_news);
        label_news->setObjectName("label_news");
        label_news->setGeometry(QRect(0, 0, 461, 40));
        label_news->setMinimumSize(QSize(0, 36));
        label_news->setMaximumSize(QSize(16777215, 40));
        label_news->setFont(font3);

        verticalLayout_6->addWidget(widget_news);


        horizontalLayout->addWidget(widget_right);


        verticalLayout->addWidget(widget_body);

        scrollArea->setWidget(scrollAreaMain);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Form_Start);

        pushButton_new->setDefault(false);
        pushButton_open->setDefault(false);
        pushButton_store->setDefault(false);
        pushButton_set->setDefault(false);


        QMetaObject::connectSlotsByName(Form_Start);
    } // setupUi

    void retranslateUi(QWidget *Form_Start)
    {
        Form_Start->setWindowTitle(QCoreApplication::translate("Form_Start", "Form", nullptr));
        label_title1->setText(QCoreApplication::translate("Form_Start", "FireMonkey Studio 2024 Dev", nullptr));
        label_title2->setText(QCoreApplication::translate("Form_Start", "\350\267\250\345\271\263\345\217\260\351\233\206\346\210\220\345\274\200\345\217\221\347\216\257\345\242\203", nullptr));
        label_start->setText(QCoreApplication::translate("Form_Start", "\345\274\200\345\247\213", nullptr));
        pushButton_new->setText(QCoreApplication::translate("Form_Start", "\346\226\260\345\273\272\345\267\245\347\250\213", nullptr));
        pushButton_open->setText(QCoreApplication::translate("Form_Start", "\346\211\223\345\274\200\345\267\245\347\250\213", nullptr));
        pushButton_store->setText(QCoreApplication::translate("Form_Start", "\346\272\220\347\240\201\345\225\206\345\237\216", nullptr));
        pushButton_set->setText(QCoreApplication::translate("Form_Start", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        label_history->setText(QCoreApplication::translate("Form_Start", "\346\234\200\350\277\221\345\267\245\347\250\213", nullptr));
        label_notice->setText(QCoreApplication::translate("Form_Start", "\345\205\254\345\221\212", nullptr));
        label->setText(QCoreApplication::translate("Form_Start", "\346\227\240\345\206\205\345\256\271", nullptr));
        label_news->setText(QCoreApplication::translate("Form_Start", "\345\274\200\345\217\221\350\200\205\346\226\260\351\227\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_Start: public Ui_Form_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_START_H
