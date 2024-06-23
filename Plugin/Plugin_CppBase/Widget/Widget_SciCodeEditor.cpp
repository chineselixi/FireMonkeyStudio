#include "Widget_SciCodeEditor.h"

Widget_SciCodeEditor::Widget_SciCodeEditor(QWidget *parent,Plugin_Base* plugin)
    :QsciScintilla(parent)
{
    this->pluginPtr = plugin;
}

Widget_SciCodeEditor::~Widget_SciCodeEditor()
{
    if(this->pluginPtr){
        this->pluginPtr->suggest_getCompletionInstance()->hidden();
    }
}

//设置插件指针
void Widget_SciCodeEditor::setPluginPtr(Plugin_Base *plugin)
{
    this->pluginPtr = plugin;
}

