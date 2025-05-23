/********************************************************************************
** Form generated from reading UI file 'Form_Content.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_CONTENT_H
#define UI_FORM_CONTENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Content
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Form_Content)
    {
        if (Form_Content->objectName().isEmpty())
            Form_Content->setObjectName("Form_Content");
        Form_Content->resize(800, 600);
        menubar = new QMenuBar(Form_Content);
        menubar->setObjectName("menubar");
        Form_Content->setMenuBar(menubar);
        centralwidget = new QWidget(Form_Content);
        centralwidget->setObjectName("centralwidget");
        Form_Content->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Form_Content);
        statusbar->setObjectName("statusbar");
        Form_Content->setStatusBar(statusbar);

        retranslateUi(Form_Content);

        QMetaObject::connectSlotsByName(Form_Content);
    } // setupUi

    void retranslateUi(QMainWindow *Form_Content)
    {
        Form_Content->setWindowTitle(QCoreApplication::translate("Form_Content", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_Content: public Ui_Form_Content {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_CONTENT_H
