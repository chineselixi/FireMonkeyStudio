
#ifndef SYSTEM_GLOBALVAR_H
#define SYSTEM_GLOBALVAR_H
#include "QString"
#include "QList"
#include "QFont"
//#include "SwSystem/System_History.h"


//工程项目文件信息
namespace ProjectOpen{
extern QString projectPath;//工程项目文件记录
}


//所有的窗口指针
class Form_WorkSpace;
namespace Window{
extern Form_WorkSpace* workSpace; //工作窗口
}



//管理器
class Plugin_Manger;
class System_EnvVar;
class Form_TipManger;
class Form_ProjectManger;
class Form_WindowTab;
class System_CodeEditorManger;
namespace Manger{
extern Plugin_Manger* pluginManger; //插件管理器
extern Form_TipManger* workspace_tipManger; //提示管理器
extern Form_ProjectManger* workspace_projectManger; //工程管理器
extern Form_WindowTab* workspace_winTabManger; //工程TAB管理器
extern System_CodeEditorManger* codeEditorManger; //代码编辑器管理器
}


//历史列表
class System_History;
namespace HistoryList{
extern System_History* sys_proHistory; //项目历史列表
extern System_History* sys_modHistory; //工程模板历史列表
extern System_History* sys_pluginHistory; //插件开启的列表
}


//设置记录器
class System_SystemSetting;
class QApplication;
namespace Setting{
extern System_SystemSetting* sys_setting;
extern QApplication* sys_app; //本程序对象

extern QString git_path; //Git路径
extern QString git_branch; //Git默认分支
extern bool git_track; //git自动跟踪
extern bool git_pushAddDate; //git添加日期
extern bool git_outMsg; //git输出日志

extern QString style_themeName; //主题名
extern bool style_themeIsAuto; //自动更改主题
extern QFont style_font; //字体名称
extern bool style_dailyTips; //每日一贴

//extern QList<>

}




//字符串处理
namespace Str{
QString getSubStr(QString srcStr, QString start, QString endStr); //获取两个字符之间的字符,如果开始字符串为空，则默认从0开始，如果结束字符串为空，则默认到字符串结尾
}






#endif // SYSTEM_GLOBALVAR_H
