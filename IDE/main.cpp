#include "mainwindow.h"
//#include "CodeEditor/CodeEditor.h"

#include "SwSystem/System_GlobalVar.h"


#include "Window/Form_Index.h"
//#include "Window/Form_New.h"
//#include "Window/Form_ProjectManger.h"
//#include "Window/Form_WindowTab.h"
//#include "Window/Form_PluginManger.h"
//#include "Window/Form_WorkSpace.h"


#include "Plugin/Plugin_Manger.h"

#include "SwSystem/System_History.h"
#include "SwSystem/System_Systemsetting.h"
#include "SwSystem/System_UtilFun.h"
#include "SwSystem/System_CodeEditorManger.h"

#include "Window/settingWindow/Form_settings_Git.h"
#include "Window/settingWindow/Form_settings_Color.h"


#include <QApplication>

void loadSettings(); //加载设置信息


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setFont(QFont("Consolas"));

    //加载设置信息
    loadSettings();

    //保存本程序对象
    Setting::sys_app = &a;
    QString t_execRunPath = System_OS::getaApplicationDirPath_EX(); //获取程序的运行目录
    //a.setStyleSheet("QTextEdit{background-color: rgb(233, 238, 255);}");

    //加载工程历史配置文件
    HistoryList::sys_proHistory = new System_History;
    HistoryList::sys_proHistory->Init(t_execRunPath + "/config/proHisList.json");

    //加载工程历史模板
    HistoryList::sys_modHistory = new System_History;
    HistoryList::sys_modHistory->Init(t_execRunPath + "/config/modHisList.json");

    //加载插件记录信息
    HistoryList::sys_pluginHistory = new System_History;
    HistoryList::sys_pluginHistory->Init(t_execRunPath + "/config/plugin.json");

    //插件管理器
    Manger::pluginManger = new Plugin_Manger; //加载插件管理器
    Manger::pluginManger->initPlugin(t_execRunPath + "/plg",System_OS::getDynamicLibrarySuffix());

    //代码编辑器管理器
    Manger::codeEditorManger = new System_CodeEditorManger();

    Form_Index* wi = new Form_Index(); //index窗口将加载工作空间
    wi->show();

    return a.exec();
}


//加载设置信息
void loadSettings(){
    //初始化设置加载器
    Setting::sys_setting = new System_SystemSetting(System_OS::getaApplicationDirPath_EX() + "/config/systemSetting.ini");
    Form_settings_Git::loadSettings(); //加载git设置
    Form_settings_Color::loadSettings(); //加载颜色
}


