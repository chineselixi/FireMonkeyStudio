#ifndef PLUGIN_IDEBASE_H
#define PLUGIN_IDEBASE_H

#include "plugin_IdeBase_global.h"
#include "../../IDE/Plugin/Plugin_Base.cpp"




class Plugin_IdeBase : public Plugin_Base
{
public:
    Plugin_IdeBase();
    //libMsg getBaseMsg() override;//获取基础的系统指针



public: //不可阻止事件
    void event_onWorkSpaceFinish() override; //工作空间加载完毕


public: //返回true则继续触发其他插件的同类型时间，返回false则阻止触发其他插件
    bool event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction actionType, QString proPath,QString proLangs,QString proNoteClass) override;//当工具栏内部按钮被按下(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)
};






extern "C" PLUGIN_IDEBASE_EXPORT Plugin_IdeBase* GetInstance(){
    return new Plugin_IdeBase;
};


#endif // PLUGIN_IDEBASE_H
