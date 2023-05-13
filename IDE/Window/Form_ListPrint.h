#ifndef FORM_LISTPRINT_H
#define FORM_LISTPRINT_H

#include <QWidget>
#include "Plugin/Plugin_Global.h"


namespace Ui {
class Form_ListPrint;
}

class Form_ListPrint : public QWidget
{
    Q_OBJECT

public:
    explicit Form_ListPrint(QWidget *parent = nullptr);
    ~Form_ListPrint();

private:
    Ui::Form_ListPrint *ui;

public:
    //添加提示内容
    void addMsg(QString code,QString text,QString project,QString file,int row,PluginGlobalMsg::printIcoType type = PluginGlobalMsg::printIcoType::tip,QColor textColor = qRgb(0,0,0));

    //删除所有内容
    void clearMsg();



protected:
    void resizeEvent(QResizeEvent *event) override; //重写尺寸改变
};

#endif // FORM_LISTPRINT_H
