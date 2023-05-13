#ifndef FORM_CHECKGCC_H
#define FORM_CHECKGCC_H

#include <QWidget>

namespace Ui {
class Form_CheckGCC;
}

class Form_CheckGCC : public QWidget
{
    Q_OBJECT

public:
    explicit Form_CheckGCC(QWidget *parent = nullptr);
    ~Form_CheckGCC();


    static QString gccExist(); //检查GCC是否存在



private slots:
    void on_But_check_clicked();

private:
    Ui::Form_CheckGCC *ui;
};

#endif // FORM_CHECKGCC_H
