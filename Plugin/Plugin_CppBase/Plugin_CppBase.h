#ifndef PLUGIN_CPPBASE_H
#define PLUGIN_CPPBASE_H

#include "Plugin_CppBase_global.h"
#include "../../IDE/Plugin/Plugin_Base.cpp"


class PLUGIN_CPPBASE_EXPORT Plugin_CppBase : public Plugin_Base
{
private:


public:
    Plugin_CppBase();

public: //返回false则阻止触发事件
    bool event_onPorjectLoad(QString proPath,QString proLangs,QString proNoteClass) override; //当工程被加载完毕(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)
    bool event_onFileOpen(QString filePath) override; //文件被加载，阻止消息继续触发，返回false阻止
    void event_onLoading() override; //插件被初次加载

public:
    void event_onTabFormActivation(QWidget* form) override; //当Tab内嵌窗口被选中，被激活时，将会激发此选项
    bool event_onTabFormCloseRequested(QWidget* form) override; //当Tab内嵌窗口即将选择被关闭，但是还未关闭，将激发此选项，返回true则允许关闭



private:
    bool stringRight(QString str,QString suffix); //判断是否拥有这个后缀



};






extern "C" PLUGIN_CPPBASE_EXPORT Plugin_CppBase* GetInstance(){
    return new Plugin_CppBase;
};




#endif // PLUGIN_CPPBASE_H
