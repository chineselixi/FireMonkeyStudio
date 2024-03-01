#ifndef PLUGIN_CPPBASE_H
#define PLUGIN_CPPBASE_H


#include "QProcess"
#include "Plugin_CppBase_global.h"
#include "../../IDE/Plugin/Plugin_Base.cpp"


QVector<settingNamespace::settingNode> settingNamespace::settingList;//设置信息列表
int settingNamespace::compilerIndex = -1; //编译器索引


class Form_CodeEditor;

class Plugin_CppBase : public Plugin_Base
{
private:

    struct MapperNode{
        QString filePath = ""; //原始文件路径
        qint64 timeStamp = 0; //最后一次更改时间戳
        QString mapperName = ""; //输出文件的基础名称，不包含路径与后缀
        bool lonelyCompile = false; //是否需要单独编译（当输出文件名与原始文件基础名称不是一致的时候，将单独进行编译）
        bool neadCompile = true; //是否需要重新编译
    };

    struct proConfigMenu{
        QString proPath;
        QAction* menuAction = nullptr;
    };


private:
    QProcess* execProcess = nullptr;        //编译执行的进程
    QProcess* tipProcess = nullptr;         //提示进程


    QVector<proConfigMenu> proConfigMenus; //工程配置菜单列表
    QString runProPath = "";    //当前运行的工程
    bool needClearPrint = false; //是否需要清理输出
    bool needClearMarginSign = false; //是否需要清理边界标记
    bool needClearTextSign = false;   //是否需要清理文本标记

public:
    Plugin_CppBase();

//======================插件事件======================
private: //全局事件：返回false则阻止继续触发事件
    //当工程被加载完毕(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)
    bool event_onProjectActiveChanged(QString proPath,QString proLangs,QString proNoteClass) override;
    //当项目被关闭
    bool event_onProjectClose(QString projectPath) override;
    //当工具栏内部按钮被按下(参数1:激发按钮类型   参数2:工程的目录   参数3:工程的多个语言标记   参数4:工程类型标记)
    bool event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction actionType, QString proPath,QString proLangs,QString proNoteClass);
    //文件被加载，阻止消息继续触发，返回false阻止
    bool event_onFileOpen(QString filePath,uint16_t line = 0,uint16_t lineIndex = 0,uint16_t len = 0) override;



private: //全局事件，不可被阻止
    //当加载设置组件的时候,加载设置组件
    void event_onLoadSettingsWidget(settingMsgList& msgList);
    //工作空间加载完毕
    void event_onWorkSpaceFinish();
    //当文件名称被更改
    void event_onFileRename(QString oldPath, QString newPath);



private: //专有事件（只有本插件本通知的事件）
    //插件被初次加载
    void event_onLoading() override;
    //当Tab内嵌窗口被选中，被激活时，将会激发此选项
    void event_onTabFormActivation(QWidget* form) override;
    //当Tab内嵌窗口即将选择被关闭，但是还未关闭，将激发此选项，返回true则允许关闭
    bool event_onTabFormCloseRequested(QWidget* form) override;



public: //消息投递事件
    //插件管理器接口
    QString event_onPluginReceive(QString sendPluginSign,QString msg); //参数（发送者标记，发送信息），返回值（当返回的信息不是空则第一时间返回），当插件接收到发送的信息


//======================内部方法======================
private:
    //判断是否为cppbase工程应该打开的文件
    bool isCppBaseUseFile(QString filePath);
    //判断是否拥有这个后缀
    bool stringRight(QString str,QString suffix);
    //添加菜单项到工程右键菜单，已存在则不添加
    bool addConfigMenuToProManger(QString proPath);
    //删除菜单项到工程右键菜单
    bool delConfigMenuToProManger(QString proPath);

    //根据语言标记，判断此工程是否为Cpp工程
    bool checkIsCppProject(QString langSign);
    //查找源码文件
    void findSource(QString projectPath,QVector<QString>& retSrcList);
    //编译初始化，用于检测编译器是否存在，返回错误信息，（）
    QString compileInit();


    //根据编译映射文本信息读取编译映射
    QVector<MapperNode> parseCompileMapper(QString mapperContent);
    //根据映射信息转换为文本
    QString compileMapperToString(QVector<MapperNode> mapperList);
    //合并映射信息，自动整理
    QVector<MapperNode> mergeMappers(QVector<MapperNode> m1,QVector<MapperNode>m2);
    //整理Mapper，去除重复文件，优化重名，验证是否单独
    QVector<MapperNode> arrangeMappers(QVector<MapperNode> mappers);
    //提供一个文件列表和原始的映射列表，返回新的编译映射列表
    QVector<MapperNode> getCompileMapper(QVector<QString> srcFiles,QVector<MapperNode> mapperList);

    //关闭有关Action
    void closeRunActions();


    //运行参数调整
    QString attrAdjust(QString commid,settingNamespace::settingNode setNode, cppAttributeNamespace::projectAttribute attr,QString proPath = "",QString execPath = "");
    //参数运行
    void runCommand(QString cmd);

private:
    void event_attribute(QString proPath); //属性被点击
    void event_stop(); //停止当前运行的进程
    void event_run(QString proPath, QVector<QString> compileFiles);//运行
    void event_errorTips(QString errorStr, Form_CodeEditor* codeEditorPtr = nullptr); //错误提示信息
    QString event_compile(QString proPath, QVector<QString> compileFiles); //编译完成，成功返回编译的文件，失败返回空

private:
    void event_runStarted(); //程序开始运行
    void event_runFinished(int exitCode, QProcess::ExitStatus exitStatus = QProcess::ExitStatus::NormalExit); //程序执行完毕
    void event_runError(QProcess::ProcessError error); //程序开始运行

};






extern "C" PLUGIN_CPPBASE_EXPORT Plugin_CppBase* GetInstance(){
    return new Plugin_CppBase;
};




#endif // PLUGIN_CPPBASE_H
