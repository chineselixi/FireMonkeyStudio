/********************************************************************************
** Form generated from reading UI file 'Form_SearchList.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SEARCHLIST_H
#define UI_FORM_SEARCHLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_SearchList
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *Form_SearchList)
    {
        if (Form_SearchList->objectName().isEmpty())
            Form_SearchList->setObjectName("Form_SearchList");
        Form_SearchList->resize(987, 207);
        Form_SearchList->setStyleSheet(QString::fromUtf8("QTreeWidget{\n"
"	background-color: rgb(230, 231, 232);\n"
"}\n"
"\n"
"QHeaderView::section{  \n"
"border:1px solid #94a6ca; \n"
"background-color:rgb(204, 213, 240);\n"
"padding-left:10px;\n"
"}"));
        gridLayout = new QGridLayout(Form_SearchList);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(Form_SearchList);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeWidget->setUniformRowHeights(false);
        treeWidget->setHeaderHidden(false);
        treeWidget->header()->setVisible(true);
        treeWidget->header()->setDefaultSectionSize(125);
        treeWidget->header()->setProperty("showSortIndicator", QVariant(false));
        treeWidget->header()->setStretchLastSection(true);

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);


        retranslateUi(Form_SearchList);

        QMetaObject::connectSlotsByName(Form_SearchList);
    } // setupUi

    void retranslateUi(QWidget *Form_SearchList)
    {
        Form_SearchList->setWindowTitle(QCoreApplication::translate("Form_SearchList", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("Form_SearchList", "\345\210\227", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("Form_SearchList", "\350\241\214", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("Form_SearchList", "\351\241\271\347\233\256", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("Form_SearchList", "\346\226\207\344\273\266", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Form_SearchList", "\344\273\243\347\240\201\346\226\207\346\234\254", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(4, QCoreApplication::translate("Form_SearchList", "5", nullptr));
        ___qtreewidgetitem1->setText(3, QCoreApplication::translate("Form_SearchList", "20", nullptr));
        ___qtreewidgetitem1->setText(2, QCoreApplication::translate("Form_SearchList", "\346\265\213\350\257\225\351\241\271\347\233\256", nullptr));
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("Form_SearchList", "C:/Users/31914/Desktop/testProject/src/main.cpp", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("Form_SearchList", "\346\265\213\350\257\225\344\273\243\347\240\201", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Form_SearchList: public Ui_Form_SearchList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SEARCHLIST_H
