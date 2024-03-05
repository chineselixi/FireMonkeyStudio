
#include "System_GlobalVar.h"


//工程文件目录
QString ProjectOpen::projectPath = "";//工程项目文件记录


//窗口指针信息组
Form_WorkSpace* Window::workSpace = nullptr;


//管理器
Plugin_Manger* Manger::pluginManger = nullptr;//插件管理器
Form_TipManger* Manger::workspace_tipManger = nullptr;//通知消息管理器
Form_ProjectManger* Manger::workspace_projectManger = nullptr;//工程管理器
Form_WindowTab* Manger::workspace_winTabManger = nullptr; //工程TAB管理器
System_CodeEditorManger* Manger::codeEditorManger = nullptr;//代码编辑器管理器


//历史列表
System_History* HistoryList::sys_proHistory = nullptr; //项目历史列表
System_History* HistoryList::sys_modHistory = nullptr; //工程模板历史列表
System_History* HistoryList::sys_pluginHistory = nullptr; //插件开启的列表

//设置加载
System_SystemSetting* Setting::sys_setting = nullptr; //设置对象
QApplication* Setting::sys_app = nullptr; //本程序对象
QString Setting::git_path = "";
QString Setting::git_branch = "";
bool Setting::git_track = true; //git自动跟踪
bool Setting::git_pushAddDate = false; //git添加日期
bool Setting::git_outMsg = true; //git输出日志
QString Setting::style_themeName = "Blue"; //主题名
bool Setting::style_themeIsAuto = false; //自动更改主题
QFont Setting::style_font; //字体名称
bool Setting::style_dailyTips = true; //每日一贴





//获取两个字符之间的字符,如果左边或右边不存在，则直接返回空。
QString Str::getSubStr(QString srcStr, QString startStr, QString endStr){
    int t_start = 0,t_end = srcStr.length();
    if(!startStr.isEmpty()){
        t_start = srcStr.indexOf(startStr,0);
        if(t_start != - 1){
            t_start += startStr.length();
        }
        else{
            return "";
        }
    }
    if(!endStr.isEmpty()){
        t_end = srcStr.indexOf(endStr,t_start);
        if(t_end == -1){
            return "";
        }
    }
    return srcStr.mid(t_start,t_end - t_start);
}
