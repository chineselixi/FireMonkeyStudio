
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
namespace Manger{
extern Plugin_Manger* pluginManger; //插件管理器
}


//历史列表
class System_History;
namespace HistoryList{
extern System_History* sys_proHistory; //项目历史列表
extern System_History* sys_modHistory; //工程模板历史列表
extern System_History* sys_pluginHistory; //插件开启的列表
}











#endif // SYSTEM_GLOBALVAR_H
