#include "Widget_TextEdit.h"

Widget_TextEdit::Widget_TextEdit(QWidget* parent)
    :QTextEdit(parent)
{

}


//按钮按下
void Widget_TextEdit::keyPressEvent(QKeyEvent *e)
{
    if(this->onKeyDown(e)){
        QTextEdit::keyPressEvent(e);
    }
}

//输入事件
void Widget_TextEdit::inputMethodEvent(QInputMethodEvent *e)
{
    if(this->onInputMethodEvent(e)){
        QTextEdit::inputMethodEvent(e);
    }
}


