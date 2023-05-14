
#ifndef PLUGIN_UIXEDITOR_H
#define PLUGIN_UIXEDITOR_H

#include "plugin_UixEditor_global.h"
#include "../../IDE/Plugin/Plugin_Base.h"

#include "Window/Form_WidgetBox.h"
#include "Window/Form_EditorSpace.h"

class Plugin_UixEditor : public Plugin_Base
{
public:
    Plugin_UixEditor();
//    libMsg getBaseMsg() override;//获取基础的系统指针

public:
    Form_WidgetBox* itemBox = nullptr;
//    Form_EditorSpace* editorSpace = nullptr;


public:
    void event_onWorkSpaceFinish() override; //工作空间加载完毕
    bool event_onFileOpen(QString filePath); //当文件被打开


};




extern "C" PLUGIN_UIXEDITOR_EXPORT Plugin_UixEditor* GetInstance(){
    return new Plugin_UixEditor;
};





#endif // PLUGIN_UIXEDITOR_H
