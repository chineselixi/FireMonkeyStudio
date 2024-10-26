/********************************************************************************
** Form generated from reading UI file 'Form_WindowTab.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_WINDOWTAB_H
#define UI_FORM_WINDOWTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_WindowTab
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QWidget *Form_WindowTab)
    {
        if (Form_WindowTab->objectName().isEmpty())
            Form_WindowTab->setObjectName("Form_WindowTab");
        Form_WindowTab->resize(864, 552);
        Form_WindowTab->setStyleSheet(QString::fromUtf8("/*\351\200\211\346\213\251\346\240\217*/\n"
"QTabBar{\n"
"	border:0px;\n"
"	padding:0px;\n"
"}\n"
"\n"
"QTabWidget{\n"
"	border:0px;\n"
"	padding:0px;\n"
"}\n"
"\n"
"\n"
"/*\351\200\211\346\213\251\345\244\271\347\232\204\345\255\220\345\244\271*/\n"
"QTabBar::tab{\n"
"    background-color: #0B0E11;\n"
"	 /*font-family:Consolas;   \350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\345\255\227\344\275\223*/\n"
"	font-size:8pt;\n"
"	color:rgb(255, 255, 255);    /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\351\242\234\350\211\262*/\n"
"	/*border-top-left-radius: 5px;    \350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\267\246\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	/*border-top-right-radius: 5px;    \350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\217\263\344\270\212\345\234\206\350\247"
                        "\222\357\274\211*/\n"
"	min-width: 100px;\n"
"	margin-right:2px;\n"
"	padding: 5px;\n"
"	background-color: rgb(59, 79, 129);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204tab\350\242\253\351\200\211\344\270\255\346\227\266\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:selected{\n"
"    background-color: rgb(245, 204, 132);\n"
"	color:rgb(58, 52, 42);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255\351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QTabBar\347\232\204tab\344\270\212\357\274\214\344\275\206\346\234\252\351\200\211\344\270\255\350\257\245Tab\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:hover:!selected {\n"
"    background-color: rgb(187, 198, 241);\n"
"	color:rgb(92, 45, 145);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"QTabBar::close-button:selected {\n"
"    image: url(:/DockWidget/icon/Theme/Blue/Image/Pane/menuClose3.png);\n"
"}\n"
"QTabBar::close-button:selected:hover {\n"
"    image: url(:/DockWidget/icon/Theme/Blue/Image/Pane"
                        "/menuClose2.png);\n"
"}\n"
"QTabBar::close-button:!selected {\n"
"    image: url(:/DockWidget/icon/Theme/Blue/Image/Pane/menuClose1.png);\n"
"}\n"
"QTabBar::close-button:!selected:hover {\n"
"    image: url(:/DockWidget/icon/Theme/Blue/Image/Pane/menuClose0.png);\n"
"}\n"
"\n"
""));
        gridLayout = new QGridLayout(Form_WindowTab);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(Form_WindowTab);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setBaseSize(QSize(0, 0));
        tabWidget->setFocusPolicy(Qt::TabFocus);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Form_WindowTab);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Form_WindowTab);
    } // setupUi

    void retranslateUi(QWidget *Form_WindowTab)
    {
        Form_WindowTab->setWindowTitle(QCoreApplication::translate("Form_WindowTab", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Form_WindowTab", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Form_WindowTab", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_WindowTab: public Ui_Form_WindowTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_WINDOWTAB_H
