
#include "plugin_gccbuild.h"
#include "QFileInfo"
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
    qDebug() << "运行按钮被点击";

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

