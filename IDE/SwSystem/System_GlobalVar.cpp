
#include "System_GlobalVar.h"


//工程文件目录
QString ProjectOpen::projectPath = "";//工程项目文件记录


//窗口指针信息组
Form_WorkSpace* Window::workSpace = nullptr;


//管理器
Plugin_Manger* Manger::pluginManger = nullptr;//插件管理器
System_EnvVar* Manger::EnvVar = nullptr;//环境变量管理器


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



//获取两个字符之间的字符
QString Str::getSubStr(QString srcStr, QString startStr, QString endStr){
    int t_start = 0,t_end = srcStr.length();
    if(!startStr.isEmpty()){
        t_start = srcStr.indexOf(startStr,0);
        if(t_start != - 1){
            t_start += startStr.length();
        }
        else{
            t_start = 0;
        }
    }
    if(!endStr.isEmpty()){
        t_end = srcStr.indexOf(endStr,t_start + 1);
        if(t_end == - 1){
            t_end = srcStr.length() - 1;
        }
    }
    return srcStr.mid(t_start,t_end - t_start);
}
