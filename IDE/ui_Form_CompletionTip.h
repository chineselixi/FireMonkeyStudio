/********************************************************************************
** Form generated from reading UI file 'Form_CompletionTip.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_COMPLETIONTIP_H
#define UI_FORM_COMPLETIONTIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_CompletionTip
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *Form_CompletionTip)
    {
        if (Form_CompletionTip->objectName().isEmpty())
            Form_CompletionTip->setObjectName("Form_CompletionTip");
        Form_CompletionTip->resize(200, 400);
        Form_CompletionTip->setMinimumSize(QSize(200, 0));
        Form_CompletionTip->setMaximumSize(QSize(600, 16777215));
        Form_CompletionTip->setStyleSheet(QString::fromUtf8("#Form_CompletionTip{\n"
"    border: 2px solid;\n"
"}"));
        verticalLayout = new QVBoxLayout(Form_CompletionTip);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(Form_CompletionTip);
        listWidget->setObjectName("listWidget");
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(listWidget);


        retranslateUi(Form_CompletionTip);

        QMetaObject::connectSlotsByName(Form_CompletionTip);
    } // setupUi

    void retranslateUi(QWidget *Form_CompletionTip)
    {
        Form_CompletionTip->setWindowTitle(QCoreApplication::translate("Form_CompletionTip", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_CompletionTip: public Ui_Form_CompletionTip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_COMPLETIONTIP_H
