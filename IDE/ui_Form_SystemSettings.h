/********************************************************************************
** Form generated from reading UI file 'Form_SystemSettings.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SYSTEMSETTINGS_H
#define UI_FORM_SYSTEMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_SystemSettings
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_title;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_use;

    void setupUi(QWidget *Form_SystemSettings)
    {
        if (Form_SystemSettings->objectName().isEmpty())
            Form_SystemSettings->setObjectName("Form_SystemSettings");
        Form_SystemSettings->resize(897, 619);
        Form_SystemSettings->setStyleSheet(QString::fromUtf8("#listWidget{\n"
"	background-color:rgb(247, 249, 254);\n"
"	outline:0px; /*\346\270\205\346\245\232\351\200\211\344\270\255\347\232\204\350\231\232\347\272\277*/\n"
"}\n"
"\n"
"\n"
"/*\345\210\227\350\241\250\346\214\211\351\222\256\346\240\267\345\274\217\357\274\214\346\263\250\346\204\217\357\274\214\345\217\252\346\230\257\351\222\210\345\257\271\345\210\227\350\241\250\346\234\211\346\225\210\343\200\202\344\275\206\346\230\257\345\257\271\345\233\276\346\240\207\346\250\241\345\274\217\344\270\213\346\227\240\346\225\210\n"
".Widget_Button_Start{\n"
"	background-color: rgb(238, 235, 235);\n"
"}\n"
".Widget_Button_Start:hover{\n"
"	background-color: rgb(208, 231, 248);\n"
"}\n"
"*/\n"
"\n"
" /*\345\255\220\351\241\271\346\240\267\345\274\217*/\n"
"#listWidget::item{\n"
"	background-color:rgb(247, 249, 254);\n"
"}\n"
"#listWidget::item:hover{\n"
"	border: 1px solid rgb(93, 107, 153);\n"
"}\n"
"#listWidget::item:selected {\n"
"	background-color:rgb(196, 213, 255)\n"
"}\n"
"#listWidget::item:selected:!active"
                        "{\n"
"	background-color: rgb(196, 213, 255);\n"
"}\n"
"\n"
"\n"
"/*\345\216\273\351\231\244Frame\350\276\271\346\241\206*/\n"
".QFrame{\n"
"	border:0px;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(Form_SystemSettings);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        frame = new QFrame(Form_SystemSettings);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(200, 0));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(0, 0));
        lineEdit->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(lineEdit);

        listWidget = new QListWidget(frame);
        listWidget->setObjectName("listWidget");
        listWidget->setMinimumSize(QSize(0, 0));
        listWidget->setMaximumSize(QSize(16777215, 16777215));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setMovement(QListView::Static);
        listWidget->setResizeMode(QListView::Adjust);
        listWidget->setViewMode(QListView::IconMode);

        verticalLayout->addWidget(listWidget);


        horizontalLayout->addWidget(frame);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_title = new QLabel(Form_SystemSettings);
        label_title->setObjectName("label_title");
        label_title->setMinimumSize(QSize(0, 24));
        label_title->setMaximumSize(QSize(16777215, 24));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_title->setFont(font);

        verticalLayout_2->addWidget(label_title);

        stackedWidget = new QStackedWidget(Form_SystemSettings);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        widget = new QWidget(page);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 10, 611, 361));
        stackedWidget->addWidget(page);

        verticalLayout_2->addWidget(stackedWidget);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_ok = new QPushButton(Form_SystemSettings);
        pushButton_ok->setObjectName("pushButton_ok");
        pushButton_ok->setMinimumSize(QSize(90, 0));
        pushButton_ok->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_2->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(Form_SystemSettings);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setMinimumSize(QSize(90, 0));
        pushButton_cancel->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_2->addWidget(pushButton_cancel);

        pushButton_use = new QPushButton(Form_SystemSettings);
        pushButton_use->setObjectName("pushButton_use");
        pushButton_use->setMinimumSize(QSize(90, 0));
        pushButton_use->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_2->addWidget(pushButton_use);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(Form_SystemSettings);

        QMetaObject::connectSlotsByName(Form_SystemSettings);
    } // setupUi

    void retranslateUi(QWidget *Form_SystemSettings)
    {
        Form_SystemSettings->setWindowTitle(QCoreApplication::translate("Form_SystemSettings", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Form_SystemSettings", "\350\277\207\346\273\244\345\231\250", nullptr));
        label_title->setText(QCoreApplication::translate("Form_SystemSettings", "\350\256\276\347\275\256", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("Form_SystemSettings", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("Form_SystemSettings", "\345\217\226\346\266\210", nullptr));
        pushButton_use->setText(QCoreApplication::translate("Form_SystemSettings", "\345\272\224\347\224\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_SystemSettings: public Ui_Form_SystemSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SYSTEMSETTINGS_H
