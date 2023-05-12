#ifndef FORM_TEXTPRINT_H
#define FORM_TEXTPRINT_H

#include <QWidget>

namespace Ui {
class Form_TextPrint;
}

class Form_TextPrint : public QWidget
{
    Q_OBJECT

public:
    explicit Form_TextPrint(QWidget *parent = nullptr);
    ~Form_TextPrint();

    QSize sizeHint() const; //重写获取尺寸的函数，这样在QDockWidget下就可以自定义宽高了

public:
    void clearTextEditor(); //清理文本编辑器
    void addLineText(QString text,QColor color = qRgb(0,0,0)); //添加行文本
    void addText(QString text,QColor color = qRgb(0,0,0)); //添加文本


private:
    Ui::Form_TextPrint *ui;
};

#endif // FORM_TEXTPRINT_H
