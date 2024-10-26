/********************************************************************************
** Form generated from reading UI file 'Form_Index.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_INDEX_H
#define UI_FORM_INDEX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Index
{
public:
    QLabel *label;

    void setupUi(QWidget *Form_Index)
    {
        if (Form_Index->objectName().isEmpty())
            Form_Index->setObjectName("Form_Index");
        Form_Index->resize(890, 500);
        Form_Index->setMinimumSize(QSize(890, 500));
        Form_Index->setMaximumSize(QSize(890, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/WidgetIcon/icon/WidgetIcon/logo/Logo_128.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Form_Index->setWindowIcon(icon);
        Form_Index->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Form_Index);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 890, 500));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Image/Index/icon/index/index.png")));

        retranslateUi(Form_Index);

        QMetaObject::connectSlotsByName(Form_Index);
    } // setupUi

    void retranslateUi(QWidget *Form_Index)
    {
        Form_Index->setWindowTitle(QCoreApplication::translate("Form_Index", "FireMonkeyStudio", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form_Index: public Ui_Form_Index {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_INDEX_H
