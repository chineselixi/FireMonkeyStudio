
#ifndef CODEEDITOR_H
#define CODEEDITOR_H
#include "Qsci/qsciscintilla.h"

class CodeEditor:public QsciScintilla
{
public:
    CodeEditor(QWidget* parent);

private:
    //QFont codeFont =

public:
    void SetSign();


};

#endif // CODEEDITOR_H
