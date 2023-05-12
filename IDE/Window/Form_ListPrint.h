#ifndef FORM_LISTPRINT_H
#define FORM_LISTPRINT_H

#include <QWidget>

namespace Ui {
class Form_ListPrint;
}

class Form_ListPrint : public QWidget
{
    Q_OBJECT
public:
    //图标类型
    enum icoType{
        tip = 0,
        ok = 1,
        error = 2,
        warning = 3
    };


public:
    explicit Form_ListPrint(QWidget *parent = nullptr);
    ~Form_ListPrint();

private:
    Ui::Form_ListPrint *ui;

public:
    //添加提示内容
    void addMsg(QString code,QString text,QString project,QString file,int row,icoType type = icoType::tip,QColor textColor = qRgb(0,0,0));

    //删除所有内容
    void clearMsg();



protected:
    void resizeEvent(QResizeEvent *event) override; //重写尺寸改变
};

#endif // FORM_LISTPRINT_H
