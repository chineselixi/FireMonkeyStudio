/********************************************************************************
** Form generated from reading UI file 'Form_TipManger.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_TIPMANGER_H
#define UI_FORM_TIPMANGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_TipManger
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *Form_TipManger)
    {
        if (Form_TipManger->objectName().isEmpty())
            Form_TipManger->setObjectName("Form_TipManger");
        Form_TipManger->resize(200, 441);
        Form_TipManger->setStyleSheet(QString::fromUtf8("QListWidgetItem{\n"
"	background-color: rgb(0, 255, 255);\n"
"}"));
        verticalLayout = new QVBoxLayout(Form_TipManger);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(Form_TipManger);
        listWidget->setObjectName("listWidget");
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(listWidget);


        retranslateUi(Form_TipManger);

        QMetaObject::connectSlotsByName(Form_TipManger);
    } // setupUi

    void retranslateUi(QWidget *Form_TipManger)
    {
        Form_TipManger->setWindowTitle(QCoreApplication::translate("Form_TipManger", "TipsManger", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_TipManger: public Ui_Form_TipManger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_TIPMANGER_H
