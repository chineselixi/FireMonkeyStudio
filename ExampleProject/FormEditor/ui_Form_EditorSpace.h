/********************************************************************************
** Form generated from reading UI file 'Form_EditorSpace.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_EDITORSPACE_H
#define UI_FORM_EDITORSPACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "Widgets/Widget_MdiArea.h"

QT_BEGIN_NAMESPACE

class Ui_Form_EditorSpace
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    Widget_MdiArea *mdiArea;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *Form_EditorSpace)
    {
        if (Form_EditorSpace->objectName().isEmpty())
            Form_EditorSpace->setObjectName("Form_EditorSpace");
        Form_EditorSpace->resize(907, 559);
        Form_EditorSpace->setStyleSheet(QString::fromUtf8("/*\346\233\264\346\224\271\351\273\230\350\256\244\350\203\214\346\231\257\n"
"#Form_EditorSpace,#editorScrollSpace,#scrollAreaWidgetContents{\n"
"	background-color: rgb(160,160,160);\n"
"	border:0px;\n"
"}\n"
"*/\n"
"\n"
"#mdiArea QScrollBar{\n"
"height:15px;\n"
"width:15px;\n"
"}"));
        gridLayout = new QGridLayout(Form_EditorSpace);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(Form_EditorSpace);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        mdiArea = new Widget_MdiArea(splitter);
        mdiArea->setObjectName("mdiArea");
        mdiArea->setMinimumSize(QSize(500, 0));
        splitter->addWidget(mdiArea);
        treeWidget = new QTreeWidget(splitter);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setSelectionMode(QAbstractItemView::ContiguousSelection);
        splitter->addWidget(treeWidget);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(Form_EditorSpace);

        QMetaObject::connectSlotsByName(Form_EditorSpace);
    } // setupUi

    void retranslateUi(QWidget *Form_EditorSpace)
    {
        Form_EditorSpace->setWindowTitle(QCoreApplication::translate("Form_EditorSpace", "\347\252\227\345\217\243\347\274\226\350\276\221\345\231\250", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("Form_EditorSpace", "\347\261\273", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Form_EditorSpace", "\345\257\271\350\261\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_EditorSpace: public Ui_Form_EditorSpace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_EDITORSPACE_H
