
#ifndef PLUGIN_IDEBASIC_H
#define PLUGIN_IDEBASIC_H

#include "plugin_ideBasic_global.h"
#include "../../IDE/Plugin/Plugin_Base.h"






class Plugin_ideBasic : public Plugin_Base
{
public:
    Plugin_ideBasic();

    libMsg getBaseMsg() override;//获取基础的系统指针

    void event_onWorkSpaceFinish() override; //工作空间加载完毕


    bool event_onFileOpen(QString filePath); //当文件被打开
};




extern "C" PLUGIN_IDEBASIC_EXPORT Plugin_ideBasic* GetInstance(){
    return new Plugin_ideBasic;
};




#endif // PLUGIN_IDEBASIC_H
