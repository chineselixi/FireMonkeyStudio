/********************************************************************************
** Form generated from reading UI file 'Form_ListPrint.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_LISTPRINT_H
#define UI_FORM_LISTPRINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_ListPrint
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *Form_ListPrint)
    {
        if (Form_ListPrint->objectName().isEmpty())
            Form_ListPrint->setObjectName("Form_ListPrint");
        Form_ListPrint->resize(987, 207);
        Form_ListPrint->setStyleSheet(QString::fromUtf8("QTreeWidget{\n"
"	background-color: rgb(230, 231, 232);\n"
"}\n"
"\n"
"QHeaderView::section{  \n"
"border:1px solid #94a6ca; \n"
"background-color:rgb(204, 213, 240);\n"
"padding-left:10px;\n"
"}"));
        gridLayout = new QGridLayout(Form_ListPrint);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(Form_ListPrint);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/CompileTip/icon/compileTip/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem->setIcon(0, icon);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeWidget->setUniformRowHeights(false);
        treeWidget->setHeaderHidden(false);
        treeWidget->header()->setVisible(true);
        treeWidget->header()->setDefaultSectionSize(125);
        treeWidget->header()->setProperty("showSortIndicator", QVariant(false));
        treeWidget->header()->setStretchLastSection(true);

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);


        retranslateUi(Form_ListPrint);

        QMetaObject::connectSlotsByName(Form_ListPrint);
    } // setupUi

    void retranslateUi(QWidget *Form_ListPrint)
    {
        Form_ListPrint->setWindowTitle(QCoreApplication::translate("Form_ListPrint", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("Form_ListPrint", "\350\241\214", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("Form_ListPrint", "\346\226\207\344\273\266", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("Form_ListPrint", "\351\241\271\347\233\256", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("Form_ListPrint", "\350\257\264\346\230\216", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Form_ListPrint", "\344\273\243\347\240\201", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("Form_ListPrint", "\345\210\235\345\247\213\345\214\226\345\212\240\350\275\275\346\210\220\345\212\237", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Form_ListPrint: public Ui_Form_ListPrint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_LISTPRINT_H
