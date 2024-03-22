#ifndef FORM_START_H
#define FORM_START_H

#include <QWidget>

namespace Ui {
class Form_Start;
}

class Form_Start : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Start(QWidget *parent = nullptr);
    ~Form_Start();

private slots:
    void onProjectOpen(QString path);       //当工程被打开

    void on_pushButton_new_clicked();       //新建被点击
    void on_pushButton_open_clicked();      //打开被点击
    void on_pushButton_store_clicked();     //商店被点击
    void on_pushButton_set_clicked();       //设置被点击

private:
    Ui::Form_Start *ui;
};

#endif // FORM_START_H
