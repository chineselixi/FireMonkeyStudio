/********************************************************************************
** Form generated from reading UI file 'Form_EditorSpace.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_EDITORSPACE_H
#define UI_FORM_EDITORSPACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_EditorSpace
{
public:
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;

    void setupUi(QWidget *Form_EditorSpace)
    {
        if (Form_EditorSpace->objectName().isEmpty())
            Form_EditorSpace->setObjectName("Form_EditorSpace");
        Form_EditorSpace->resize(748, 511);
        Form_EditorSpace->setStyleSheet(QString::fromUtf8("/*\346\233\264\346\224\271\351\273\230\350\256\244\350\203\214\346\231\257\n"
"#Form_EditorSpace,#editorScrollSpace,#scrollAreaWidgetContents{\n"
"	background-color: rgb(160,160,160);\n"
"	border:0px;\n"
"}\n"
"*/"));
        gridLayout = new QGridLayout(Form_EditorSpace);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mdiArea = new QMdiArea(Form_EditorSpace);
        mdiArea->setObjectName("mdiArea");
        mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        QBrush brush(QColor(160, 160, 160, 255));
        brush.setStyle(Qt::SolidPattern);
        mdiArea->setBackground(brush);

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);


        retranslateUi(Form_EditorSpace);

        QMetaObject::connectSlotsByName(Form_EditorSpace);
    } // setupUi

    void retranslateUi(QWidget *Form_EditorSpace)
    {
        Form_EditorSpace->setWindowTitle(QCoreApplication::translate("Form_EditorSpace", "\347\252\227\345\217\243\347\274\226\350\276\221\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_EditorSpace: public Ui_Form_EditorSpace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_EDITORSPACE_H
