
#include "System_GlobalVar.h"


//工程文件目录
QString ProjectOpen::projectPath = "";//工程项目文件记录


//窗口指针信息组
Form_WorkSpace* Window::workSpace = nullptr;


//管理器
Plugin_Manger* Manger::pluginManger = nullptr;//插件管理器


//历史列表
System_History* HistoryList::sys_proHistory = nullptr; //项目历史列表
System_History* HistoryList::sys_modHistory = nullptr; //工程模板历史列表
System_History* HistoryList::sys_pluginHistory = nullptr; //插件开启的列表
