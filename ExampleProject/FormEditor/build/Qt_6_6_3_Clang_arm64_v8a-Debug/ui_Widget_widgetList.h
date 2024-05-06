/********************************************************************************
** Form generated from reading UI file 'Widget_widgetList.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_WIDGETLIST_H
#define UI_WIDGET_WIDGETLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_widgetList
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *Widget_widgetList)
    {
        if (Widget_widgetList->objectName().isEmpty())
            Widget_widgetList->setObjectName("Widget_widgetList");
        Widget_widgetList->resize(300, 615);
        Widget_widgetList->setMinimumSize(QSize(200, 0));
        Widget_widgetList->setMaximumSize(QSize(600, 16777215));
        Widget_widgetList->setStyleSheet(QString::fromUtf8("#Widget_widgetList{\n"
"	border:0px;\n"
"}"));
        gridLayout = new QGridLayout(Widget_widgetList);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(Widget_widgetList);
        treeWidget->setObjectName("treeWidget");

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);


        retranslateUi(Widget_widgetList);

        QMetaObject::connectSlotsByName(Widget_widgetList);
    } // setupUi

    void retranslateUi(QWidget *Widget_widgetList)
    {
        Widget_widgetList->setWindowTitle(QCoreApplication::translate("Widget_widgetList", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("Widget_widgetList", "\347\261\273", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Widget_widgetList", "\345\257\271\350\261\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_widgetList: public Ui_Widget_widgetList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_WIDGETLIST_H
