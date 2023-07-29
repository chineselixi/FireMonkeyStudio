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

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setFont(QFont("Consolas"));

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

    return a.exec();
}
