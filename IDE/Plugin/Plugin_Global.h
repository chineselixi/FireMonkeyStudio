
#ifndef PLUGIN_GLOBAL_H
#define PLUGIN_GLOBAL_H

#include "QWidget"
#include "QDockWidget"
#include "QToolBar"
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
enum generateType{
    debug = 0,
    release = 1,
};



//输出的Ico
enum printIcoType{
    tip = 0,
    ok = 1,
    error = 2,
    warning = 3
};

//工具栏Action对象类型
enum toolBarAction{
    cut, //剪切
    copy, //复制
    paste, //粘贴
    undo, //撤销
    redo, //重做
    compile, //编译
    staticCompile, //静态编译
    onlineCompile, //在线编译
    find, //查找
    run, //运行
    stop, //停止运行
    Rerun, //重新运行
    toggleAllBreakpoints, //切换所有断点
    clearBreakpointGroup, //清除断点
    debugFind, //调试查找
    stepForward, //调试前进
    stepOver, //调试跳过
    stepIn, //调试进入
    stepOut, //调试跳出
    toolTip, //工具提示
    bookmark, //书签
    previousBookmark, //上一个书签
    nextBookmark, //下一个书签
    bookmarkMainMenuTabitem, //书签主菜单
    config, //配置
    compleMode, //编译模式选择器
};


//工具栏分类
enum toolBarMenuType{
    toolType, //添加菜单到工具栏
    settingType, //添加菜单到设置
    helpsType, //添加菜单到帮助
    viewType, //添加菜单到试图
    extendType, //添加菜单到拓展
    compileType, //添加菜单到生成
    dataBaseType, //添加菜单到数据库
    insertType, //添加菜单到插入
    fileType, //添加菜单到打开文件
};



//编程接口
enum langType{
    normal, //默认没有任何语言
    cpp, //C++语言
    html,
    javaScript,
};




//工程管理
enum proMangerMenuType{
    Project,NewFile,ProNormal
};







//默认基础函数类型
typedef std::function<void()> fun_void; //基础函数类型，空返回


//函数指针类型
//class Plugin_Base; //插件类声明
typedef std::function<void(QAction* act)> menuFun;  //添加菜单到menu
typedef std::function<void(QToolBar* toolBar)> toolBarFun;


//Tab窗体操作
typedef std::function<void(void* plg, QString title, QWidget *form, QString sign, QIcon titeIco,PluginGlobalMsg::TabType type)> addTabViewPth; //添加TabView函数指针类型
typedef std::function<bool(QString sign,bool select)> tab_hasTab_Sign; //根据sign查找判断tab是否存在
typedef std::function<bool(QWidget* sign,bool select)> tab_hasTab_WidgetPtr; //根据窗体指针判断Tab是否存在
typedef std::function<QString(QWidget*)> tab_getSign; //根据Widget获取sign
typedef std::function<QWidget*(QString)> tab_getWidget; //根据sign获取Widget



//代码编辑器函数类型
typedef std::function<void(int line, int index)> editorEvent_cursorPositionChanged; //光标移动事件
typedef std::function<void()> editorEvent_textChanged; //文本改变事件

//创建QWidget函数指针,参数为事件参数（光标位置改变，内容改变，）
//typedef std::function<QWidget*(editorEvent_cursorPositionChanged,editorEvent_textChanged,langType)> editorFun_create;
//typedef std::function<void(QWidget* editor,QVector<QString> keys,int index)> editorFun_addKetWord; //创建添加关键字信息
//typedef std::function<QString(QWidget*)> editorFun_getStr; //获取内容
//typedef std::function<void(QWidget* editor,QString str)> editorFun_addStr; //添加内容




//输出容器
typedef std::function<void(QString code, QString text,QString project,QString file,int row,PluginGlobalMsg::printIcoType type,QColor textColor)> printFun_printList;
typedef std::function<void()> printFun_clear;
typedef std::function<void(QColor color,QString printText)> printFun_printTextSpace;

//插件管理器通信
typedef std::function<QString(QString selfSign,QString pluginSign,QString pustMsg)> pluginFun_post; //插件投递函数

//Dock操作
typedef std::function<void(Qt::DockWidgetArea area,QDockWidget* dockWidget)> dockWidgetFun_add;//添加Dock
typedef std::function<void(QDockWidget* dockWidget)> dockWidgetFun_rm;//移除Dock

//ToolBar操作
typedef std::function<void(toolBarAction actionType,bool isEnable)> toolBar_action_setEnable; //设置工具栏的action是否启用

//设置操作
typedef std::function<void(QString key,QVariant value)> setPtr_addFun;//添加设置
typedef std::function<QVariant(QString key,QString normal)> setPtr_getFun; //获取设置
typedef std::function<void(QString key)> setPtr_deleteFun; //删除设置
}







#endif // PLUGIN_GLOBAL_H
