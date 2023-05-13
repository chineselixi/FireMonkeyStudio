
#ifndef PLUGIN_BASE_H
#define PLUGIN_BASE_H

#include "QAction"
#include "Plugin_Global.h"




class Plugin_Base
{
public:

    struct libMsg{
        QString name = "NULL";         //支持库信息
        QString version = "1.0.0.1";  //支持库显示版本
        int versionNumber = 1; //支持库数字版本
        QString sign = ""; //插件标记，插件之间的通信需要的标记。注意，插件的标记可以相同，管理器将通过这些标记进行数据传输
        QString note = "Plugin for FireMonkey Studio";
        QString loadTip = "";//加载时输出的文字信息，可以作为加载成功的提示
    };


protected:
    libMsg self_BaseMsg;

public:
    //工作空间菜单接口，工作空间加载完毕后所有指针都将刷新为可用
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Tool = nullptr; //添加菜单到工具栏
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Setting = nullptr; //添加菜单到设置
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Helps = nullptr; //添加菜单到帮助
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_View = nullptr; //添加菜单到试图
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Extend = nullptr; //添加菜单到拓展
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Compile = nullptr; //添加菜单到生成
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_DataBase = nullptr; //添加菜单到数据库
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Insert = nullptr; //添加菜单到插入
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_File = nullptr; //添加菜单到打开文件

    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ProManger_Project = nullptr;//添加菜单到工程
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ProManger_NewFile = nullptr;//添加菜单到新建文件
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ProManger_ProNormal = nullptr;//添加菜单到工程普通文件菜单

    PluginGlobalMsg::workSpace_Action_setEnableFun WorkSpace_Action_setEnable = nullptr; //设置Action是否可用


    PluginGlobalMsg::printFun_printList WorkSpace_PrintOut_List = nullptr; //在通知列表输出信息
    PluginGlobalMsg::printFun_clear WorkSpace_PrintOut_List_Clear = nullptr;  //清理当前列表
    PluginGlobalMsg::printFun_printTextSpace WorkSpace_PrintOut_TextSpace_Print = nullptr; //输出单个文本不换行
    PluginGlobalMsg::printFun_printTextSpace WorkSpace_PrintOut_TextSpace_PrintLine = nullptr;//输出一行文本
    PluginGlobalMsg::printFun_clear WorkSpace_PrintOut_TextSpace_Clear = nullptr; //清空文本输出


    //选项卡添加窗口接口
    PluginGlobalMsg::addTabViewPth WorkSpace_addTabWindow = nullptr; //添加窗口到Tab


    //代码编辑器
    PluginGlobalMsg::editorFun_create CodeEditorFunPtr_Create = nullptr; //创建代码编辑器
    PluginGlobalMsg::editorFun_addKetWord CodeEditorFunPtr_AddkeyWord = nullptr;//添加关键字，0为关键字1，1为关键字2
    PluginGlobalMsg::editorFun_getStr CodeEditorFunPtr_GetCode = nullptr;//获取代码编辑器文本
    PluginGlobalMsg::editorFun_addStr CodeEditorFunPtr_AddStr = nullptr; //编辑器插入文本


    //插件同学
    PluginGlobalMsg::pluginFun_post PluginManger_PostMsg = nullptr; //使用插件管理器投递信息，每一个有效插件都将接收到收到这个信息，但是需要注意发送方的身份


public:
    //初始化信息，由IDE侧载，可复写
//    void initPlugin_toolMenu(PluginGlobalMsg::menuFun tool,PluginGlobalMsg::menuFun set,PluginGlobalMsg::menuFun help,PluginGlobalMsg::menuFun view,PluginGlobalMsg::menuFun add,
//                             PluginGlobalMsg::menuFun compile,PluginGlobalMsg::menuFun db,PluginGlobalMsg::menuFun instert,PluginGlobalMsg::menuFun file);//初始化插件，如果被继承也要先执行此项目信息
//    void initPlugin_proJectMenu(PluginGlobalMsg::menuFun pro,PluginGlobalMsg::menuFun newFile,PluginGlobalMsg::menuFun proNormal); //添加菜单到工程列表
//    void initPlugin_tabView(PluginGlobalMsg::addTabViewPth tabViewPath); //添加Tab指针

    virtual libMsg getBaseMsg(){return self_BaseMsg;}; //获取基础的类信息



public: //(可阻拦事件)事件触发，返回true则继续触发其他插件的同类型时间，返回false则阻止触发其他插件
    virtual bool event_onModLoadFinish(){return true;};//当模块加载完毕，将第一时间激发此插件，禁止在获取实例处获得
    virtual bool event_onCompileTypeChanged(PluginGlobalMsg::compileType type){return true;}; //当编译模式被改变
    virtual bool event_onFileOpen(QString filePath){return true;}; //当文件被打开，注意：仅限于IDE无法打开之外的文件才激发此事件
    virtual bool event_onFileOpenFinish(QString filePath){return true;}; //当前文件已经被打开，所有的文件被打开都会激发此事件
    virtual bool event_onFileClose(QString filePath){return true;}; //当前文件被删除或者关闭之前就发送的信息
    virtual bool event_onRunDown(QString proPath,QString proLangs,QString proNoteClass){return true;}; //当运行按钮被按下(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)
    virtual bool event_onStopDown(QString proPath,QString proLangs,QString proNoteClass){return true;}; //当停止按钮被按下(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)
    virtual bool event_onPorjectLoad(QString proPath,QString proLangs,QString proNoteClass){return true;}; //当工程被加载完毕(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)


public: //(不可阻拦事件)事件触发，将激发每一个插件的事件
    virtual void event_onWorkSpaceFinish(){return;}; //工作空间创建完毕事件，此事件不可阻止，，但是可以阻塞，将为每一个插件提供事件响应
    virtual void event_onWorkSpaceClose(){return;};  //工作空间正在被关闭，不可被阻止，但是可以阻塞，将为每一个插件提供事件响应


public:
    //插件管理器接口
    virtual QString event_onPluginReceive(QString sendPluginSign,QString msg){return "";}; //参数（发送者标记，发送信息），返回值（当返回的信息不是空则第一时间返回），当插件接收到发送的信息

};
#endif // PLUGIN_BASE_H
