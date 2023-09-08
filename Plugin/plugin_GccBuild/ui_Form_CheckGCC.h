/********************************************************************************
** Form generated from reading UI file 'Form_CheckGCC.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_CHECKGCC_H
#define UI_FORM_CHECKGCC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_CheckGCC
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_img;
    QLabel *label_tip;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *But_check;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Form_CheckGCC)
    {
        if (Form_CheckGCC->objectName().isEmpty())
            Form_CheckGCC->setObjectName("Form_CheckGCC");
        Form_CheckGCC->resize(310, 315);
        verticalLayout = new QVBoxLayout(Form_CheckGCC);
        verticalLayout->setObjectName("verticalLayout");
        label_img = new QLabel(Form_CheckGCC);
        label_img->setObjectName("label_img");
        label_img->setPixmap(QPixmap(QString::fromUtf8(":/form_img/img/error.png")));
        label_img->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_img);

        label_tip = new QLabel(Form_CheckGCC);
        label_tip->setObjectName("label_tip");
        QFont font;
        font.setPointSize(14);
        label_tip->setFont(font);
        label_tip->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_tip);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        But_check = new QPushButton(Form_CheckGCC);
        But_check->setObjectName("But_check");
        But_check->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(But_check);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Form_CheckGCC);

        QMetaObject::connectSlotsByName(Form_CheckGCC);
    } // setupUi

    void retranslateUi(QWidget *Form_CheckGCC)
    {
        Form_CheckGCC->setWindowTitle(QCoreApplication::translate("Form_CheckGCC", "GCC\347\274\226\350\257\221\345\231\250\351\252\214\350\257\201", nullptr));
        label_img->setText(QString());
        label_tip->setText(QCoreApplication::translate("Form_CheckGCC", "GCC\347\274\226\350\257\221\345\231\250\344\270\215\345\255\230\345\234\250", nullptr));
        But_check->setText(QCoreApplication::translate("Form_CheckGCC", "\351\207\215\346\226\260\346\243\200\346\237\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_CheckGCC: public Ui_Form_CheckGCC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_CHECKGCC_H
