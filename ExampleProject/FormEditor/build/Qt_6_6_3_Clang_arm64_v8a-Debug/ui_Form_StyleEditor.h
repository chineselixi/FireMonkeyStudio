/********************************************************************************
** Form generated from reading UI file 'Form_StyleEditor.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_STYLEEDITOR_H
#define UI_FORM_STYLEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Form_StyleEditor
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Form_StyleEditor)
    {
        if (Form_StyleEditor->objectName().isEmpty())
            Form_StyleEditor->setObjectName("Form_StyleEditor");
        Form_StyleEditor->resize(449, 349);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo/icon/Logo/Logo_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        Form_StyleEditor->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Form_StyleEditor);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        plainTextEdit = new QPlainTextEdit(Form_StyleEditor);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout->addWidget(plainTextEdit);

        buttonBox = new QDialogButtonBox(Form_StyleEditor);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setMaximumSize(QSize(16777215, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Form_StyleEditor);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Form_StyleEditor, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Form_StyleEditor, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Form_StyleEditor);
    } // setupUi

    void retranslateUi(QDialog *Form_StyleEditor)
    {
        Form_StyleEditor->setWindowTitle(QCoreApplication::translate("Form_StyleEditor", "\346\240\267\345\274\217\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_StyleEditor: public Ui_Form_StyleEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_STYLEEDITOR_H
