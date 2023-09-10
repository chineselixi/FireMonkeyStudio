
#ifndef PLUGIN_CPPBASIC_H
#define PLUGIN_CPPBASIC_H

#include "plugin_cppBasic_global.h"
#include "../../../../IDE/Plugin/Plugin_Base.h"


class Plugin_cppBasic : public Plugin_Base
{
public:
    Plugin_cppBasic();

    libMsg getBaseMsg() override;//获取基础的系统指针

private:
    PluginGlobalMsg::compileType thisCompileType = PluginGlobalMsg::compileType::debug;
    bool isCppProject = false;

public:
    void event_onWorkSpaceFinish() override; //工作空间加载完毕

    //返回false则停止消息投递，当工具栏action被触发
    bool event_onPorjectLoad(QString proPath,QString proLangs,QString proNoteClass) override; //当工程被加载完毕(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)
    bool event_onCompileTypeChanged(PluginGlobalMsg::compileType type) override; //当编译模式被改变
    bool event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction actionType, QString proPath,QString proLangs,QString proNoteClass) override;


private:

    void onRunDown(QString proPath,QString proLangs,QString proNoteClass); //当运行按钮被按下(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)
    void onStopDown(QString proPath,QString proLangs,QString proNoteClass); //当停止按钮被按下(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)
};




extern "C" PLUGIN_CPPBASIC_EXPORT Plugin_cppBasic* GetInstance(){
    return new Plugin_cppBasic;
};




#endif // PLUGIN_CPPBASIC_H
