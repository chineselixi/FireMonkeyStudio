/********************************************************************************
** Form generated from reading UI file 'Form_About.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_ABOUT_H
#define UI_FORM_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_About
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_img;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;

    void setupUi(QWidget *Form_About)
    {
        if (Form_About->objectName().isEmpty())
            Form_About->setObjectName("Form_About");
        Form_About->resize(308, 568);
        verticalLayout = new QVBoxLayout(Form_About);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(Form_About);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(0, 100));
        frame->setMaximumSize(QSize(16777215, 100));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_img = new QLabel(frame);
        label_img->setObjectName("label_img");
        label_img->setMinimumSize(QSize(64, 64));
        label_img->setMaximumSize(QSize(64, 64));
        label_img->setPixmap(QPixmap(QString::fromUtf8(":/WidgetIcon/icon/WidgetIcon/logo/Logo_64.png")));

        horizontalLayout->addWidget(label_img);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout->addWidget(frame);

        label = new QLabel(Form_About);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 60));
        label->setMaximumSize(QSize(16777215, 60));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(Form_About);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 30));
        label_2->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(Form_About);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_4->setWordWrap(true);

        verticalLayout->addWidget(label_4);

        label_3 = new QLabel(Form_About);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 40));
        label_3->setMaximumSize(QSize(16777215, 40));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);


        retranslateUi(Form_About);

        QMetaObject::connectSlotsByName(Form_About);
    } // setupUi

    void retranslateUi(QWidget *Form_About)
    {
        Form_About->setWindowTitle(QCoreApplication::translate("Form_About", "\345\205\263\344\272\216", nullptr));
        label_img->setText(QString());
        label->setText(QCoreApplication::translate("Form_About", "FireMonkey Studio 2025", nullptr));
        label_2->setText(QCoreApplication::translate("Form_About", "\345\206\205\351\203\250\347\211\210\346\234\254\345\217\267  #0.0.1 DEV", nullptr));
        label_4->setText(QCoreApplication::translate("Form_About", "<html><head/><body><p>        \350\255\246\345\221\212: \346\234\254\350\256\241\347\256\227\346\234\272\347\250\213\345\272\217\345\217\227\350\221\227\344\275\234\346\235\203\346\263\225\345\222\214\345\233\275\351\231\205\345\205\254\347\272\246\347\232\204\344\277\235\346\212\244\357\274\214\346\234\252\347\273\217\346\216\210\346\235\203\346\223\205\350\207\252\345\244\215\345\210\266\346\210\226\346\225\243\345\270\203\346\234\254\347\250\213\345\272\217\347\232\204\351\203\250\345\210\206\346\210\226\345\205\250\351\203\250\357\274\214\345\260\206\346\211\277\345\217\227\344\270\245\345\216\211\347\232\204\346\260\221\344\272\213\345\222\214\345\210\221\344\272\213\345\244\204\347\275\232\357\274\214\345\257\271\345\267\262\347\237\245\347\232\204\350\277\235\345\217\215\350\200\205\345\260\206\347\273\231\344\272\210\346\263\225\345\276\213\350\214\203\345\233\264\345\206\205\347\232\204\345\205\250\351\235\242\345\210\266\350\243\201\343\200\202</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Form_About", "Copyright \302\251 2020\342\200\2232025 \347\201\253\347\214\264\345\233\242\351\230\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_About: public Ui_Form_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_ABOUT_H
