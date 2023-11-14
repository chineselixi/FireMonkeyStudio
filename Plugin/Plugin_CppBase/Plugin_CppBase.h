#ifndef PLUGIN_CPPBASE_H
#define PLUGIN_CPPBASE_H

#include "Plugin_CppBase_global.h"
#include "../../IDE/Plugin/Plugin_Base.cpp"


QVector<settingNamespace::settingNode> settingNamespace::settingList;//设置信息列表
int settingNamespace::compilerIndex = -1; //编译器索引


class PLUGIN_CPPBASE_EXPORT Plugin_CppBase : public Plugin_Base
{
private:
    struct fileSign{
        QString filePath;
        qint64 timeStamp; //最后一次更改事件
    };

    QVector<fileSign> hostryFileSignList; //历史文件信息组

public:
    Plugin_CppBase();

private: //全局事件：返回false则阻止继续触发事件
    bool event_onPorjectLoad(QString proPath,QString proLangs,QString proNoteClass) override; //当工程被加载完毕(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)
    //当工具栏内部按钮被按下(参数1:激发按钮类型   参数2:工程的目录   参数3:工程的多个语言标记   参数4:工程类型标记)
    bool event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction actionType, QString proPath,QString proLangs,QString proNoteClass);
    bool event_onFileOpen(QString filePath) override; //文件被加载，阻止消息继续触发，返回false阻止


private: //全局事件，不可被阻止
    void event_onLoadSettingsWidget(settingMsgList& msgList); //当加载设置组件的时候,加载设置组件



private: //专有事件（只有本插件本通知的事件）
    void event_onLoading() override; //插件被初次加载
    void event_onTabFormActivation(QWidget* form) override; //当Tab内嵌窗口被选中，被激活时，将会激发此选项
    bool event_onTabFormCloseRequested(QWidget* form) override; //当Tab内嵌窗口即将选择被关闭，但是还未关闭，将激发此选项，返回true则允许关闭


private:
    bool stringRight(QString str,QString suffix); //判断是否拥有这个后缀
    bool checkIsCppProject(QString langSign); //根据语言标记，判断此工程是否为Cpp工程
    void findSource(QString projectPath,QVector<QString>& retSrcList); //查找源码文件


    QVector<QString> getChangeFileList(QVector<QString> nowList); //根据一个文件列表获取更改的文件列表
    void clearHostryFileList(); //清空历史文件列表


private:
    void event_attribute(QString proPath); //属性被点击
    void event_stop(); //停止当前运行的进程
    void event_run(QVector<QString> compileFiles,QVector<QString> changeFiles, QString outPath);//运行
    void event_compile(QVector<QString> compileFiles,QVector<QString> changeFiles, QString outPath); //编译

};






extern "C" PLUGIN_CPPBASE_EXPORT Plugin_CppBase* GetInstance(){
    return new Plugin_CppBase;
};




#endif // PLUGIN_CPPBASE_H
