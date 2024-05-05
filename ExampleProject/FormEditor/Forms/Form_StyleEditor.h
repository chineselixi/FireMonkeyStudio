#ifndef FORM_STYLEEDITOR_H
#define FORM_STYLEEDITOR_H

#include <QDialog>

class QAbstractButton;

namespace Ui {
class Form_StyleEditor;
}

class Form_StyleEditor : public QDialog
{
    Q_OBJECT

public:
    explicit Form_StyleEditor(QWidget *parent = nullptr,QWidget* subWidget = nullptr);
    ~Form_StyleEditor();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Form_StyleEditor *ui;
    QWidget* widget;
};

#endif // FORM_STYLEEDITOR_H
