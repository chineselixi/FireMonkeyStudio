#include "mainwindow.h"
//#include "CodeEditor/CodeEditor.h"

#include "SwSystem/System_GlobalVar.h"



#include "Window/Form_WorkSpace.h"

//#include <QtWebView/QtWebView>


#include "Window/Form_New.h"


#include "Window/Form_ProjectManger.h"
#include "Window/Form_WindowTab.h"
#include "Window/Form_PluginManger.h""

#include "Plugin/Plugin_Manger.h"

#include "SwSystem/System_History.h"
#include "SwSystem/system_systemsetting.h"
#include "SwSystem/System_EnvVar.h"

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
    QString t_execRunPath = QCoreApplication::applicationDirPath(); //获取程序的运行目录

    //加载工程历史配置文件
    HistoryList::sys_proHistory = new System_History;
    HistoryList::sys_proHistory->Init(t_execRunPath + "/config/proHisList.ini");

    //加载工程历史模板
    HistoryList::sys_modHistory = new System_History;
    HistoryList::sys_modHistory->Init(t_execRunPath + "/config/modHisList.ini");

    //加载插件记录信息
    HistoryList::sys_pluginHistory = new System_History;
    HistoryList::sys_pluginHistory->Init(t_execRunPath + "/config/plugin.ini");

    //管理器
    Manger::pluginManger = new Plugin_Manger; //加载插件管理器
    Manger::pluginManger->initPlugin(t_execRunPath + "/plg","dll");

    //环境变量
    Manger::EnvVar = new System_EnvVar;//创建环境变量管理器


//    //打开插件管理器
    //Form_PluginManger* t_pluginManger = new Form_PluginManger;
    //t_pluginManger->show();

    //MainWindow w;
    //w.show();

    Form_WorkSpace ws;
    ws.show();

    //Form_New n;
    //n.show();

    //Form_ProjectManger pro;
    //pro.show();


    //Form_WindowTab ft;
    //ft.show();

    //Widget_Button_PluginItem wp;
    //wp.show();


//    QVariant v;
//    qDebug() << v.isNull();




    return a.exec();
}


//加载设置信息
void loadSettings(){
    //初始化设置加载器
    Setting::sys_setting = new System_systemSetting(QCoreApplication::applicationDirPath() + "/config/systemSetting.ini");
    Form_settings_Git::loadSettings(); //加载git设置
    Form_settings_Color::loadSettings(); //加载颜色
}


