/********************************************************************************
** Form generated from reading UI file 'Form_ProjectManger.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_PROJECTMANGER_H
#define UI_FORM_PROJECTMANGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_ProjectManger
{
public:
    QAction *action_AddFolder;
    QAction *action_AddForm;
    QAction *action_AddNewFile;
    QAction *action_AddHasFile;
    QVBoxLayout *verticalLayout;
    QToolBar *widget;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *Form_ProjectManger)
    {
        if (Form_ProjectManger->objectName().isEmpty())
            Form_ProjectManger->setObjectName("Form_ProjectManger");
        Form_ProjectManger->resize(200, 586);
        Form_ProjectManger->setStyleSheet(QString::fromUtf8("/*\345\267\245\345\205\267\346\240\217*/\n"
"QToolBar{\n"
"	background-color:rgb(204, 213, 240);\n"
"	border:0px;\n"
"}\n"
"\n"
"/*\345\267\245\345\205\267\346\240\217\345\210\206\351\232\224\347\254\246*/\n"
"QToolBar::separator { \n"
"	width: 1px;\n"
"	border:0px;\n"
"	margin:5px 0px;\n"
"    background-image: url(:/Theme/icon/Theme/Blue/Image/ToolBar/Separator.png);\n"
" }\n"
"\n"
"/*\346\240\221\346\241\206*/\n"
"#treeWidget{\n"
"	background-color: rgb(247, 249, 254);\n"
"	border:0px;\n"
"}\n"
"\n"
"\n"
"/*\345\217\263\351\224\256\350\217\234\345\215\225*/\n"
"QMenu{\n"
"	background-color: rgb(233, 238, 255);\n"
"	border:1px solid rgb(148, 166, 202);\n"
"	padding:2px;\n"
"}\n"
"QMenu::item{\n"
"	color: rgb(30, 30, 31);\n"
"}\n"
"QMenu::item:selected{\n"
"	color: rgb(30, 30, 31);\n"
"	background-color: rgb(177, 197, 255);\n"
"}\n"
"QMenu::separator{\n"
"	background:#bbbbbb;\n"
"    height:1px;\n"
"	margin:5px 10px;\n"
"}\n"
"/*\345\217\263\351\224\256\350\217\234\345\215\225\350\242\253\347\246\201\347\224\250"
                        "*/\n"
"QMenu::item:disabled {\n"
"	color: rgb(181, 194, 202);\n"
"}"));
        action_AddFolder = new QAction(Form_ProjectManger);
        action_AddFolder->setObjectName("action_AddFolder");
        action_AddFolder->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ProjectView/icon/Theme/Blue/Image/ProJectView/ToolBar/NewSolutionFolder_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_AddFolder->setIcon(icon);
        action_AddForm = new QAction(Form_ProjectManger);
        action_AddForm->setObjectName("action_AddForm");
        action_AddForm->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ProjectView/icon/Theme/Blue/Image/ProJectView/ToolBar/AddForm_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_AddForm->setIcon(icon1);
        action_AddNewFile = new QAction(Form_ProjectManger);
        action_AddNewFile->setObjectName("action_AddNewFile");
        action_AddNewFile->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ProjectView/icon/Theme/Blue/Image/ProJectView/ToolBar/AddNamespace_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_AddNewFile->setIcon(icon2);
        action_AddHasFile = new QAction(Form_ProjectManger);
        action_AddHasFile->setObjectName("action_AddHasFile");
        action_AddHasFile->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ProjectView/icon/Theme/Blue/Image/ProJectView/ToolBar/AddClass_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_AddHasFile->setIcon(icon3);
        verticalLayout = new QVBoxLayout(Form_ProjectManger);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QToolBar(Form_ProjectManger);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 32));
        widget->setMaximumSize(QSize(16777215, 32));

        verticalLayout->addWidget(widget);

        treeWidget = new QTreeWidget(Form_ProjectManger);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setEditTriggers(QAbstractItemView::CurrentChanged|QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
        treeWidget->header()->setVisible(false);

        verticalLayout->addWidget(treeWidget);


        widget->addAction(action_AddFolder);
        widget->addSeparator();
        widget->addAction(action_AddForm);
        widget->addSeparator();
        widget->addAction(action_AddNewFile);
        widget->addAction(action_AddHasFile);

        retranslateUi(Form_ProjectManger);

        QMetaObject::connectSlotsByName(Form_ProjectManger);
    } // setupUi

    void retranslateUi(QWidget *Form_ProjectManger)
    {
        Form_ProjectManger->setWindowTitle(QCoreApplication::translate("Form_ProjectManger", "\345\267\245\347\250\213\347\256\241\347\220\206", nullptr));
        action_AddFolder->setText(QCoreApplication::translate("Form_ProjectManger", "\346\267\273\345\212\240\346\226\207\344\273\266\345\244\271", nullptr));
#if QT_CONFIG(tooltip)
        action_AddFolder->setToolTip(QCoreApplication::translate("Form_ProjectManger", "\346\267\273\345\212\240\346\226\207\344\273\266\345\244\271", nullptr));
#endif // QT_CONFIG(tooltip)
        action_AddForm->setText(QCoreApplication::translate("Form_ProjectManger", "\345\210\233\345\273\272\346\226\260\347\252\227\345\217\243", nullptr));
#if QT_CONFIG(tooltip)
        action_AddForm->setToolTip(QCoreApplication::translate("Form_ProjectManger", "\345\210\233\345\273\272\346\226\260\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        action_AddNewFile->setText(QCoreApplication::translate("Form_ProjectManger", "\346\267\273\345\212\240\346\226\260\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        action_AddNewFile->setToolTip(QCoreApplication::translate("Form_ProjectManger", "\346\267\273\345\212\240\346\226\260\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        action_AddHasFile->setText(QCoreApplication::translate("Form_ProjectManger", "\346\267\273\345\212\240\347\216\260\346\234\211\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        action_AddHasFile->setToolTip(QCoreApplication::translate("Form_ProjectManger", "\346\267\273\345\212\240\347\216\260\346\234\211\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Form_ProjectManger", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_ProjectManger: public Ui_Form_ProjectManger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_PROJECTMANGER_H
