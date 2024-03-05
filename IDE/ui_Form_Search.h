/********************************************************************************
** Form generated from reading UI file 'Form_Search.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SEARCH_H
#define UI_FORM_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Search
{
public:
    QVBoxLayout *dialogLayout;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QComboBox *cbFind;
    QLabel *lblFind;
    QComboBox *cbReplace;
    QLabel *lbReplace;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QGroupBox *grpOptions;
    QGridLayout *gridLayout_2;
    QCheckBox *chkRegular;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *chkCaseSensetive;
    QCheckBox *chkWholeWord;
    QGroupBox *grpOrigin;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *rbFromCursor;
    QRadioButton *rbEntireScope;
    QRadioButton *rbInProject;
    QComboBox *comboBox_pro;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QPushButton *btnQuery;
    QPushButton *btnReplace;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnClose;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Form_Search)
    {
        if (Form_Search->objectName().isEmpty())
            Form_Search->setObjectName("Form_Search");
        Form_Search->setWindowModality(Qt::NonModal);
        Form_Search->resize(478, 238);
        Form_Search->setMaximumSize(QSize(621, 370));
        Form_Search->setModal(false);
        dialogLayout = new QVBoxLayout(Form_Search);
        dialogLayout->setObjectName("dialogLayout");
        dialogLayout->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(Form_Search);
        widget_5->setObjectName("widget_5");
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName("widget_4");
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(7);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_4);
        widget->setObjectName("widget");
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        cbFind = new QComboBox(widget);
        cbFind->setObjectName("cbFind");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbFind->sizePolicy().hasHeightForWidth());
        cbFind->setSizePolicy(sizePolicy);
        cbFind->setEditable(true);
        cbFind->setInsertPolicy(QComboBox::InsertAtTop);

        gridLayout_3->addWidget(cbFind, 1, 1, 1, 1);

        lblFind = new QLabel(widget);
        lblFind->setObjectName("lblFind");

        gridLayout_3->addWidget(lblFind, 1, 0, 1, 1);

        cbReplace = new QComboBox(widget);
        cbReplace->setObjectName("cbReplace");
        sizePolicy.setHeightForWidth(cbReplace->sizePolicy().hasHeightForWidth());
        cbReplace->setSizePolicy(sizePolicy);
        cbReplace->setEditable(true);
        cbReplace->setInsertPolicy(QComboBox::InsertAtTop);
        cbReplace->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        gridLayout_3->addWidget(cbReplace, 2, 1, 1, 1);

        lbReplace = new QLabel(widget);
        lbReplace->setObjectName("lbReplace");

        gridLayout_3->addWidget(lbReplace, 2, 0, 1, 1);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName("widget_2");
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        grpOptions = new QGroupBox(widget_2);
        grpOptions->setObjectName("grpOptions");
        gridLayout_2 = new QGridLayout(grpOptions);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(7, 7, 7, 7);
        chkRegular = new QCheckBox(grpOptions);
        chkRegular->setObjectName("chkRegular");

        gridLayout_2->addWidget(chkRegular, 2, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 3, 0, 1, 1);

        chkCaseSensetive = new QCheckBox(grpOptions);
        chkCaseSensetive->setObjectName("chkCaseSensetive");
        chkCaseSensetive->setEnabled(true);
        chkCaseSensetive->setChecked(true);

        gridLayout_2->addWidget(chkCaseSensetive, 0, 0, 1, 1);

        chkWholeWord = new QCheckBox(grpOptions);
        chkWholeWord->setObjectName("chkWholeWord");
        chkWholeWord->setChecked(true);

        gridLayout_2->addWidget(chkWholeWord, 1, 0, 1, 1);


        gridLayout->addWidget(grpOptions, 0, 0, 2, 1);

        grpOrigin = new QGroupBox(widget_2);
        grpOrigin->setObjectName("grpOrigin");
        verticalLayout_3 = new QVBoxLayout(grpOrigin);
        verticalLayout_3->setObjectName("verticalLayout_3");
        rbFromCursor = new QRadioButton(grpOrigin);
        rbFromCursor->setObjectName("rbFromCursor");
        rbFromCursor->setEnabled(true);
        rbFromCursor->setChecked(false);

        verticalLayout_3->addWidget(rbFromCursor);

        rbEntireScope = new QRadioButton(grpOrigin);
        rbEntireScope->setObjectName("rbEntireScope");

        verticalLayout_3->addWidget(rbEntireScope);

        rbInProject = new QRadioButton(grpOrigin);
        rbInProject->setObjectName("rbInProject");
        rbInProject->setCheckable(true);
        rbInProject->setChecked(true);

        verticalLayout_3->addWidget(rbInProject);

        comboBox_pro = new QComboBox(grpOrigin);
        comboBox_pro->setObjectName("comboBox_pro");
        comboBox_pro->setEnabled(true);

        verticalLayout_3->addWidget(comboBox_pro);


        gridLayout->addWidget(grpOrigin, 0, 1, 2, 1);


        verticalLayout_2->addWidget(widget_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_4->addWidget(widget_4);

        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName("widget_3");
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnQuery = new QPushButton(widget_3);
        btnQuery->setObjectName("btnQuery");

        verticalLayout->addWidget(btnQuery);

        btnReplace = new QPushButton(widget_3);
        btnReplace->setObjectName("btnReplace");
        btnReplace->setEnabled(false);

        verticalLayout->addWidget(btnReplace);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        btnClose = new QPushButton(widget_3);
        btnClose->setObjectName("btnClose");

        verticalLayout->addWidget(btnClose);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_4->addWidget(widget_3);


        dialogLayout->addWidget(widget_5);


        retranslateUi(Form_Search);

        btnQuery->setDefault(true);


        QMetaObject::connectSlotsByName(Form_Search);
    } // setupUi

    void retranslateUi(QDialog *Form_Search)
    {
        Form_Search->setWindowTitle(QCoreApplication::translate("Form_Search", "\346\237\245\346\211\276", nullptr));
        cbFind->setCurrentText(QString());
        lblFind->setText(QCoreApplication::translate("Form_Search", "\350\246\201\346\237\245\346\211\276\347\232\204\345\255\227\347\254\246:", nullptr));
        lbReplace->setText(QCoreApplication::translate("Form_Search", "\346\233\277\346\215\242\344\270\272:", nullptr));
        grpOptions->setTitle(QCoreApplication::translate("Form_Search", "\351\200\211\351\241\271:", nullptr));
        chkRegular->setText(QCoreApplication::translate("Form_Search", "\344\275\277\347\224\250\346\255\243\345\210\231\350\241\250\350\276\276\345\274\217", nullptr));
        chkCaseSensetive->setText(QCoreApplication::translate("Form_Search", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        chkWholeWord->setText(QCoreApplication::translate("Form_Search", "\345\205\250\345\255\227\347\254\246\345\214\271\351\205\215\346\237\245\346\211\276", nullptr));
        grpOrigin->setTitle(QCoreApplication::translate("Form_Search", "\350\214\203\345\233\264:", nullptr));
        rbFromCursor->setText(QCoreApplication::translate("Form_Search", "\345\275\223\345\211\215\351\241\265", nullptr));
        rbEntireScope->setText(QCoreApplication::translate("Form_Search", "\346\225\264\344\270\252\350\214\203\345\233\264", nullptr));
        rbInProject->setText(QCoreApplication::translate("Form_Search", "\346\214\207\345\256\232\344\270\200\344\270\252\345\267\245\347\250\213", nullptr));
        btnQuery->setText(QCoreApplication::translate("Form_Search", "\346\220\234\347\264\242", nullptr));
        btnReplace->setText(QCoreApplication::translate("Form_Search", "\346\237\245\346\211\276\345\271\266\346\233\277\346\215\242", nullptr));
        btnClose->setText(QCoreApplication::translate("Form_Search", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_Search: public Ui_Form_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SEARCH_H
