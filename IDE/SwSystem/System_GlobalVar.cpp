
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

//设置加载
System_systemSetting* Setting::sys_setting = nullptr;
QString Setting::git_path = "";
QString Setting::git_branch = "";
bool Setting::git_track = true; //git自动跟踪
bool Setting::git_pushAddDate = false; //git添加日期
bool Setting::git_outMsg = true; //git输出日志
