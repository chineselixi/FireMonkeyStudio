#ifndef WIDGET_SCICODEEDITOR_H
#define WIDGET_SCICODEEDITOR_H

#include "../../../QScintilla/src/Qsci/qsciscintilla.h"
#include "../../../IDE/Plugin/Plugin_Base.h"

class Widget_SciCodeEditor : public QsciScintilla
{
private:
    Plugin_Base* pluginPtr = nullptr;

public:
    explicit Widget_SciCodeEditor(QWidget* parent = nullptr,Plugin_Base* plugin = nullptr);
    ~Widget_SciCodeEditor();

    void setPluginPtr(Plugin_Base* plugin = nullptr);   //设置插件指针


};

#endif // WIDGET_SCICODEEDITOR_H
