
#ifndef PLUGIN_CPPBASIC_H
#define PLUGIN_CPPBASIC_H




#include "plugin_cppBasic_global.h"
#include "../../../../IDE/Plugin/Plugin_Base.h"


class Plugin_cppBasic : public Plugin_Base
{
public:
    Plugin_cppBasic();

    libMsg getBaseMsg() override;//获取基础的系统指针

    void event_onWorkSpaceFinish() override; //工作空间加载完毕
    bool event_onFileOpen(QString filePath); //当文件被打开
};




extern "C" PLUGIN_CPPBASIC_EXPORT Plugin_cppBasic* GetInstance(){
    return new Plugin_cppBasic;
};




#endif // PLUGIN_CPPBASIC_H
