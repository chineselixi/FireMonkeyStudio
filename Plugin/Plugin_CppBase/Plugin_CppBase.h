#ifndef PLUGIN_CPPBASE_H
#define PLUGIN_CPPBASE_H

#include "Plugin_CppBase_global.h"
#include "../../IDE/Plugin/Plugin_Base.cpp"


class PLUGIN_CPPBASE_EXPORT Plugin_CppBase : public Plugin_Base
{
public:
    Plugin_CppBase();








public: //返回false则阻止触发事件
    bool event_onPorjectLoad(QString proPath,QString proLangs,QString proNoteClass) override; //当工程被加载完毕(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)



};






extern "C" PLUGIN_CPPBASE_EXPORT Plugin_CppBase* GetInstance(){
    return new Plugin_CppBase;
};




#endif // PLUGIN_CPPBASE_H
