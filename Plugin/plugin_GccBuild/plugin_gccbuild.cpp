
#include "plugin_gccbuild.h"
#include "QFileInfo"
#include "QDir"
#include "QProcess"
#include "Form_CheckGCC.h"


Plugin_GccBuild::Plugin_GccBuild()
{
/*
* 注意，此时内部所有指针都是nullptr，不允许调用ide能力，当event_onModLoadFinish加载完毕后相关指针与模块才加载完毕
* 注意：调用指针的时候也需要判断调用的指针是否为空指针，在某些场景下，ide内部会置空某些模块内的指针
*/
    this->self_BaseMsg.name = "GCC编译支持(C++)";
    this->self_BaseMsg.version = "0.0.0.1 Dev";
    this->self_BaseMsg.versionNumber = 1;
    this->self_BaseMsg.sign = "GCC";
    this->self_BaseMsg.note = "FireMenkeyStudio编译插件，使用GCC编译器进行构建。\n注意：若IDE存在其他的C++编译器插件，请立即停用并且重启IDE，否则可能会出现编译冲突";
    this->self_BaseMsg.loadTip = "GCC支持插件加载完毕！";
}


//获取基础的系统指针
Plugin_Base::libMsg Plugin_GccBuild::getBaseMsg()
{
    return self_BaseMsg;
}


//工作空间加载完毕
void Plugin_GccBuild::event_onWorkSpaceFinish()
{
    QAction* t_menu = new QAction;
    WorkSpace_AddMenu_ToolBar_Tool(t_menu);
    t_menu->setText("验证GCC编译器");
    t_menu->setIcon(QIcon(":/form_img/img/Module_16x.png"));
    QAction::connect(t_menu,&QAction::triggered,[this](){
        Form_CheckGCC* t_form = new Form_CheckGCC;
        t_form->setAttribute(Qt::WA_ShowModal, true);
        t_form->show();
    });
}


//当运行按钮被按下
bool Plugin_GccBuild::event_onRunDown(QString proPath, QString proLangs, QString proNoteClass)
{
    proLangs = proLangs.toLower();
    if(proLangs.indexOf("c++") != -1 || proLangs.indexOf("cpp") != -1){
        WorkSpace_PrintOut_List_Clear(); //清空列表
        WorkSpace_PrintOut_List("","开始准备GCC编译器",proPath,"",0,PluginGlobalMsg::printIcoType::ok,QColor(0,0,0));
        if(Form_CheckGCC::gccExist().isEmpty()){
            WorkSpace_PrintOut_List("","GCC编译器不存在",proPath,"",0,PluginGlobalMsg::printIcoType::error,QColor(255,0,0));
            return true; //不阻止消息继续传播，可以让其他消息进行
        }

        if(!QFile(proPath + "/main.cpp").exists()){
            WorkSpace_PrintOut_List("","当前工程中不存在重要的源文件（main.cpp）,编译被迫终止！",proPath,"",0,PluginGlobalMsg::printIcoType::error,QColor(255,0,0));
            return true;
        }


        QString t_path = proPath;
        switch(thisCompileType){
        default:{t_path += "/debug";}
        case PluginGlobalMsg::compileType::debug:{t_path += "/debug"; break;}
        case PluginGlobalMsg::compileType::release:{t_path += "/release"; break;}
        }

        QDir t_dir;
        if(!t_dir.mkpath(t_path)){
            WorkSpace_PrintOut_List("","目录创建失败："+t_path,proPath,"",0,PluginGlobalMsg::printIcoType::error,QColor(255,0,0));
            return true; //不阻止消息继续传播，可以让其他消息进行
        }

        WorkSpace_PrintOut_List("","开始编译...",proPath,"",0,PluginGlobalMsg::printIcoType::tip,QColor(0,0,0));
        QProcess t_p;
        t_p.start("g++",{"-o",t_path + "/test",proPath + "/main.cpp"});
        t_p.waitForFinished();
        QString t_error = t_p.readAllStandardError();
        QString t_normal = t_p.readAllStandardOutput();
        if(!t_error.isEmpty()){WorkSpace_PrintOut_List("",t_error,proPath,"",0,PluginGlobalMsg::printIcoType::error,QColor(255,0,0));}
        if(!t_normal.isEmpty()){WorkSpace_PrintOut_List("",t_normal,proPath,"",0,PluginGlobalMsg::printIcoType::tip,QColor(0,0,0));}
        WorkSpace_PrintOut_List("","完成：" + t_path,"","",0,PluginGlobalMsg::printIcoType::ok,QColor(0,0,0));
        return false; //编译完成，不传递信息
    }
    return false;
}


//当停止按钮被按下
bool Plugin_GccBuild::event_onStopDown(QString proPath, QString proLangs, QString proNoteClass)
{
    return false;
}


//当工程被加载完毕
bool Plugin_GccBuild::event_onPorjectLoad(QString proPath, QString proLangs, QString proNoteClass)
{
    proLangs = proLangs.toLower();
    if(proLangs.indexOf("c++") != -1 || proLangs.indexOf("cpp") != -1){
        WorkSpace_Action_setEnable(PluginGlobalMsg::ActionType::run,true); //运行按钮状态
        WorkSpace_Action_setEnable(PluginGlobalMsg::ActionType::stop,false); //停止按钮状态
        WorkSpace_Action_setEnable(PluginGlobalMsg::ActionType::rerun,false); //重新运行按钮状态
        return false; //阻断消息传递
    }
    return true;
}



//当编译模式被改变
bool Plugin_GccBuild::event_onCompileTypeChanged(PluginGlobalMsg::compileType type)
{
    thisCompileType = type; //记录编译模式的改变
    return true;
}

