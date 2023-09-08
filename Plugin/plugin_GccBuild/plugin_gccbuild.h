
#ifndef PLUGIN_GCCBUILD_H
#define PLUGIN_GCCBUILD_H

#include "plugin_GccBuild_global.h"
#include "../../IDE/Plugin/Plugin_Base.h"



class Plugin_GccBuild : public Plugin_Base
{
public:
    Plugin_GccBuild();
    libMsg getBaseMsg() override;//获取基础的系统指针


public:
    PluginGlobalMsg::compileType thisCompileType = PluginGlobalMsg::compileType::debug;


public:
    void event_onWorkSpaceFinish() override; //工作空间加载完毕

    //返回false则停止消息投递，当工具栏action被触发
    bool event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction actionType, QString proPath,QString proLangs,QString proNoteClass) override;
    bool event_onPorjectLoad(QString proPath,QString proLangs,QString proNoteClass) override; //当工程被加载完毕(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)
    bool event_onCompileTypeChanged(PluginGlobalMsg::compileType type) override; //当编译模式被改变

private:

    bool onRunDown(QString proPath,QString proLangs,QString proNoteClass); //当运行按钮被按下(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)
    bool onStopDown(QString proPath,QString proLangs,QString proNoteClass); //当停止按钮被按下(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)




public:



};



extern "C" PLUGIN_GCCBUILD_EXPORT Plugin_GccBuild* GetInstance(){
    return new Plugin_GccBuild;
};


#endif // PLUGIN_GCCBUILD_H
