
#ifndef SYSTEM_GLOBALVAR_H
#define SYSTEM_GLOBALVAR_H
#include "QString"
#include "QVector"

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
namespace Manger{
extern Plugin_Manger* pluginManger; //插件管理器
extern System_EnvVar* EnvVar; //环境变量管理器
}


//历史列表
class System_History;
namespace HistoryList{
extern System_History* sys_proHistory; //项目历史列表
extern System_History* sys_modHistory; //工程模板历史列表
extern System_History* sys_pluginHistory; //插件开启的列表
}


//设置记录器
class System_systemSetting;
namespace Setting{
extern System_systemSetting* sys_setting;

extern QString git_path; //Git路径
extern QString git_branch; //Git默认分支
extern bool git_track; //git自动跟踪
extern bool git_pushAddDate; //git添加日期
extern bool git_outMsg; //git输出日志

}




//字符串处理
namespace Str{
QString getSubStr(QString srcStr, QString start, QString endStr);
}






#endif // SYSTEM_GLOBALVAR_H
