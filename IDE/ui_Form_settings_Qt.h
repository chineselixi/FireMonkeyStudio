/********************************************************************************
** Form generated from reading UI file 'Form_settings_Qt.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SETTINGS_QT_H
#define UI_FORM_SETTINGS_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_settings_Qt
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTreeWidget *treeWidget;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Form_settings_Qt)
    {
        if (Form_settings_Qt->objectName().isEmpty())
            Form_settings_Qt->setObjectName("Form_settings_Qt");
        Form_settings_Qt->resize(800, 709);
        gridLayout = new QGridLayout(Form_settings_Qt);
        gridLayout->setObjectName("gridLayout");
        scrollArea = new QScrollArea(Form_settings_Qt);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 776, 685));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(90, 16777215));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(200, 0));
        comboBox->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(comboBox);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName("checkBox");

        horizontalLayout_2->addWidget(checkBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_3->addWidget(pushButton_2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setOpenExternalLinks(true);

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setOpenExternalLinks(true);

        horizontalLayout_4->addWidget(label_5);

        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName("checkBox_2");

        horizontalLayout_4->addWidget(checkBox_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(0, 330));
        groupBox_2->setMaximumSize(QSize(16777215, 330));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        treeWidget = new QTreeWidget(groupBox_2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/CompileTip/icon/compileTip/ok.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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

        gridLayout_2->addWidget(treeWidget, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 111, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Form_settings_Qt);

        QMetaObject::connectSlotsByName(Form_settings_Qt);
    } // setupUi

    void retranslateUi(QWidget *Form_settings_Qt)
    {
        Form_settings_Qt->setWindowTitle(QCoreApplication::translate("Form_settings_Qt", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Form_settings_Qt", "Qt\347\216\257\345\242\203", nullptr));
        label->setText(QCoreApplication::translate("Form_settings_Qt", "Qt\347\216\257\345\242\203\350\267\257\345\276\204\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("Form_settings_Qt", "\351\200\211\346\213\251", nullptr));
        label_2->setText(QCoreApplication::translate("Form_settings_Qt", "Qt\345\267\245\344\275\234\347\211\210\346\234\254\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Form_settings_Qt", "\351\273\230\350\256\244(\345\201\234\347\224\250Qt\344\276\235\350\265\226)", nullptr));

        checkBox->setText(QCoreApplication::translate("Form_settings_Qt", "\345\274\272\345\210\266\344\275\277\347\224\250\346\255\244\347\211\210\346\234\254\346\236\204\345\273\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form_settings_Qt", "\345\210\267\346\226\260Qt\347\216\257\345\242\203\344\277\241\346\201\257", nullptr));
        label_4->setText(QCoreApplication::translate("Form_settings_Qt", "<a href=\"https://www.qt.io/\">\344\272\206\350\247\243Qt\346\241\206\346\236\266</a>", nullptr));
        label_5->setText(QCoreApplication::translate("Form_settings_Qt", "<a href=\"https://www.superlsp.com/\">FMS\345\205\215\350\264\243\345\215\217\350\256\256</a>", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Form_settings_Qt", "\345\220\214\346\204\217FMS\345\205\215\350\264\243\345\215\217\350\256\256", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Form_settings_Qt", "Qt\346\250\241\345\235\227", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("Form_settings_Qt", "\350\267\257\345\276\204", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("Form_settings_Qt", "\345\244\207\346\263\250", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("Form_settings_Qt", "\346\250\241\345\235\227", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Form_settings_Qt", "\347\212\266\346\200\201", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(3, QCoreApplication::translate("Form_settings_Qt", "D:/QT/6.5.0/mingw_64/include/QtCore", nullptr));
        ___qtreewidgetitem1->setText(2, QCoreApplication::translate("Form_settings_Qt", "Qt\346\240\270\345\277\203\345\237\272\347\241\200\346\250\241\345\235\227", nullptr));
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("Form_settings_Qt", "QtCore", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Form_settings_Qt: public Ui_Form_settings_Qt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SETTINGS_QT_H
