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
#include "SwSystem/System_SystemSetting.h"
#include "SwSystem/System_UtilFun.h"
#include "SwSystem/System_CodeEditorManger.h"

#include "Window/settingWindow/Form_settings_Git.h"
#include "Window/settingWindow/Form_settings_Color.h"


#include <QApplication>
#include <QDir>
#include "QMessageBox"

//load setting information 
void loadSettings(); //加载设置信息


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QApplication::setAttribute(Qt::AA_Use96Dpi);
    //a.setFont(QFont("Microsoft HaHei UI"));

    //load setting information
    qDebug() << "test1";

    //加载设置信息
    loadSettings();

    qDebug() << "test2";

    //save this program object 
    //保存本程序对象
    Setting::sys_app = &a;
    QString t_execRunPath = System_OS::getaApplicationDirPath_EX(); //获取程序的运行目录
    //a.setStyleSheet("QTextEdit{background-color: rgb(233, 238, 255);}");

    qDebug() << "test3";

    //load history config file of project 
    //加载工程历史配置文件
    HistoryList::sys_proHistory = new System_History;
    HistoryList::sys_proHistory->Init(t_execRunPath + "/config/proHisList.json");

    qDebug() << "test4";

    //load history template of project 
    //加载工程历史模板
    HistoryList::sys_modHistory = new System_History;
    HistoryList::sys_modHistory->Init(t_execRunPath + "/config/modHisList.json");

    qDebug() << "test5";

    //load log info of plugin 
    //加载插件记录信息
    HistoryList::sys_pluginHistory = new System_History;
    HistoryList::sys_pluginHistory->Init(t_execRunPath + "/config/plugin.json");

    qDebug() << "test6";

    //plugin manager 
    //插件管理器
    Manger::pluginManger = new Plugin_Manger; //加载插件管理器
    Manger::pluginManger->initPlugin(t_execRunPath + "/plg",System_OS::getDynamicLibrarySuffix());

    qDebug() << "test7";

    //code editor manager 
    //代码编辑器管理器
    Manger::codeEditorManger = new System_CodeEditorManger();

    Form_Index* wi = new Form_Index(); //index窗口将加载工作空间
    wi->show();

    qDebug() << "test2";


//    a.setFont(QFont("微软雅黑"));
    return a.exec();
}

//load setting information
//加载设置信息
void loadSettings(){
    //移动端是否需要复制到外部目录

    //未移动到外部目录，则工具平台移动到外部目录
    if(!QFile::exists(System_OS::getaApplicationDirPath_EX() + "/README.txt")){
        if(System_OS::getOsType() == System_OS::OSType::Android){   //如果是安卓系统，复制文件到外部目录
            QString assetPath = "assets:/";
            if(System_File::copyPath(assetPath,System_OS::getaApplicationDirPath_EX()) == false){
                QMessageBox* t_messagebox = new QMessageBox(QMessageBox::Warning,QObject::tr("资源加载失败"),QObject::tr("无法写出文件到外部目录") + "\n" + System_OS::getaApplicationDirPath_EX());
            }

            //写出标记文件
            QFile::copy(":/resFile/res/README.txt",System_OS::getaApplicationDirPath_EX() + "/README.txt");
        }
    }


    //initialize settings loader
    //初始化设置加载器
    Setting::sys_setting = new System_SystemSetting(System_OS::getaApplicationDirPath_EX() + "/config/systemSetting.ini");
    //load git setting 
    Form_settings_Git::loadSettings(); //加载git设置
    //load color 
    Form_settings_Color::loadSettings(); //加载颜色
}


