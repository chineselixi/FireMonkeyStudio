#ifndef WIDGET_TEXTEDIT_H
#define WIDGET_TEXTEDIT_H

#include <QTextEdit>

class Widget_TextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit Widget_TextEdit(QWidget *parent = nullptr);


protected:
    virtual void keyPressEvent(QKeyEvent *e)override; //按钮按下
    virtual void inputMethodEvent(QInputMethodEvent *e) override; //输入事件



signals:

    bool onKeyDown(QKeyEvent *e);
    bool onInputMethodEvent(QInputMethodEvent *e);

};

#endif // WIDGET_TEXTEDIT_H
