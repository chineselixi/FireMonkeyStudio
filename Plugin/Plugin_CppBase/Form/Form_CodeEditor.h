#ifndef FORM_CODEEDITOR_H
#define FORM_CODEEDITOR_H

#include <QWidget>

namespace Ui {
class Form_CodeEditor;
}

class Form_CodeEditor : public QWidget
{
    Q_OBJECT


private:
    void intiCodeEditor(); //初始化代码编辑器


public:
    explicit Form_CodeEditor(QWidget *parent = nullptr);
    ~Form_CodeEditor();

    bool loadForFile(QString fileName); //从文件加载代码
    void setText(QString str); //添加代码到编辑器
    void append(QString str); //添加代码
    QString getText(); //获取代码内容

    void setDebugSign(uint16_t line,bool sign); //设置调试标记
    bool hasDebugSign(uint16_t line); //获取是否调试标记


public slots:
    void event_textChanged(); //文本发生改变
    void event_cursorPositionChanged(int line, int index); //光标位置发生改变
    void event_customContextMenuRequested(const QPoint &pos); //上下文菜单被请求
    void event_marginClicked(int margin, int line, Qt::KeyboardModifiers state); //边缘标记区域被点击


private:
    Ui::Form_CodeEditor *ui;
};

#endif // FORM_CODEEDITOR_H
