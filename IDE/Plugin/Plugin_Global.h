
#ifndef PLUGIN_GLOBAL_H
#define PLUGIN_GLOBAL_H

#include "QWidget"
#include "functional"

namespace PluginGlobalMsg{

//tab内容的类型
enum TabType{
    none = 0, //无效信息
    web = 1, //网页类型
    codeEditor = 2, //代码编辑器
    form = 3 //窗口
};


//编译模式
enum compileType{
    debug = 0,
    release = 1,
};


//Action类型
enum ActionType{
    run = 0, //运行
    stop = 1, //停止
    rerun = 2, //重新运行
    compile_normal = 3,//默认编译
    compile_static = 4,//静态编译
    compile_online = 5,//在线编译
};




//函数指针类型
typedef std::function<void(QAction* act)> menuFun;  //添加菜单到menu
typedef std::function<void(QString title, QWidget *form, QString sign, QIcon titeIco,PluginGlobalMsg::TabType type)> addTabViewPth; //添加TabView函数指针类型
typedef std::function<void(ActionType actionType,bool enable)> workSpace_Action_setEnableFun; //设置Action启用函数


//代码编辑器函数类型
typedef std::function<QWidget*(std::function<void(QString leftText,QString rightText,QString lineText,QWidget* codeEditor)> onTipEventFun)> editorFun_create; //创建QWidget函数指针,其中参数包含代码编辑器的提示事件
typedef std::function<void(QWidget* editor,QVector<QString> keys,int index)> editorFun_addKetWord; //创建添加关键字信息
typedef std::function<QString(QWidget*)> editorFun_getStr; //获取内容
typedef std::function<void(QWidget* editor,QString str)> editorFun_addStr; //添加内容





//插件管理器通信
typedef std::function<QString(QString pluginSign,QString pustMsg)> pluginFun_post; //插件投递函数




//typedef std::function<QWidget(std::function<void(QString inputStr)> event_onStrInput)> codeEditorPtr;  //添加菜单到menu


}







#endif // PLUGIN_GLOBAL_H
