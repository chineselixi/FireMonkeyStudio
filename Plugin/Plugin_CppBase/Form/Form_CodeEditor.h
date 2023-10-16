#ifndef FORM_CODEEDITOR_H
#define FORM_CODEEDITOR_H

#include <QWidget>

namespace Ui {
class Form_CodeEditor;
}

class Form_CodeEditor : public QWidget
{
    Q_OBJECT

public:
    explicit Form_CodeEditor(QWidget *parent = nullptr);
    ~Form_CodeEditor();

    bool loadForFile(QString fileName); //从文件加载代码
    void setText(QString str); //添加代码到编辑器
    void append(QString str); //添加代码
    QString getText(); //获取代码内容

private:
    Ui::Form_CodeEditor *ui;
};

#endif // FORM_CODEEDITOR_H
