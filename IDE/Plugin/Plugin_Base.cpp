
#include "Plugin_Base.h"
#include "Plugin_Funs.h"


//添加菜单到工具栏菜单
void Plugin_Base::addToolBarMenu(PluginGlobalMsg::toolBarMenuType menuType, QAction *action)
{
    PluginGlobalMsg::menuFun t_fun = nullptr;
    switch (menuType) {
    default:{}
    case PluginGlobalMsg::toolBarMenuType::extendType:{ //拓展菜单
        t_fun = PluginFuns::WorkSpace_AddMenu_ToolBar_Extend;break;
    }
    case PluginGlobalMsg::toolBarMenuType::toolType:{ //工具菜单
        t_fun = PluginFuns::WorkSpace_AddMenu_ToolBar_Tool;break;
    }
    case PluginGlobalMsg::toolBarMenuType::settingType:{ //设置菜单
        t_fun = PluginFuns::WorkSpace_AddMenu_ToolBar_Setting;break;
    }
    case PluginGlobalMsg::toolBarMenuType::helpsType:{ //帮助菜单
        t_fun = PluginFuns::WorkSpace_AddMenu_ToolBar_Helps;break;
    }
    case PluginGlobalMsg::toolBarMenuType::viewType:{ //视图菜单
        t_fun = PluginFuns::WorkSpace_AddMenu_ToolBar_View;break;
    }
    case PluginGlobalMsg::toolBarMenuType::compileType:{ //编译菜单
        t_fun = PluginFuns::WorkSpace_AddMenu_ToolBar_Compile;break;
    }
    case PluginGlobalMsg::toolBarMenuType::dataBaseType:{ //数据库菜单
        t_fun = PluginFuns::WorkSpace_AddMenu_ToolBar_DataBase;break;
    }
    case PluginGlobalMsg::toolBarMenuType::insertType:{ //插入菜单
        t_fun = PluginFuns::WorkSpace_AddMenu_ToolBar_Insert;break;
    }
    case PluginGlobalMsg::toolBarMenuType::fileType:{ //文件菜单
        t_fun = PluginFuns::WorkSpace_AddMenu_ToolBar_File;break;
    }
    }

    if(t_fun != nullptr){ //指针有效
        t_fun(action);
    }
}

//添加菜单到项目管理器
void Plugin_Base::addProMangerMenu(PluginGlobalMsg::proMangerMenuType menuType, QAction *action)
{
    PluginGlobalMsg::menuFun t_fun = nullptr;
    switch (menuType) {
    default:{}
    case PluginGlobalMsg::proMangerMenuType::NewFile:{ //新文件
        t_fun = PluginFuns::WorkSpace_AddMenu_ProManger_NewFile;break;
    }
    case PluginGlobalMsg::proMangerMenuType::ProNormal:{ //默认
        t_fun = PluginFuns::WorkSpace_AddMenu_ProManger_ProNormal;break;
    }
    case PluginGlobalMsg::proMangerMenuType::Project:{ //工程列表
        t_fun = PluginFuns::WorkSpace_AddMenu_ProManger_Project;break;
    }
    }
    if(t_fun != nullptr){ //指针有效
        t_fun(action);
    }
}

//设置工作空间Action启用
void Plugin_Base::setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction actionType, bool isEnable)
{
    if(PluginFuns::WorkSpace_ToolBar_setActionEnable){
        PluginFuns::WorkSpace_ToolBar_setActionEnable(actionType,isEnable);
    }

}

//关闭所有的工作控件子菜单
void Plugin_Base::closeWorkSpaceAllAction()
{
    if(PluginFuns::WorkSpace_ToolBar_closeAllAction){
        PluginFuns::WorkSpace_ToolBar_closeAllAction();
    }
}

//添加工具栏到工作空间
void Plugin_Base::addToolBarToWs(QToolBar *toolBar)
{
    if(PluginFuns::WorkSpace_ToolBar_addToolBar){
        PluginFuns::WorkSpace_ToolBar_addToolBar(toolBar);
    }
}

//在列表输出中输出一行文本
void Plugin_Base::printList(QString code, QString text, QString project, QString file, int row, PluginGlobalMsg::printIcoType type, QColor textColor)
{
    if(PluginFuns::WorkSpace_PrintOut_List){
        PluginFuns::WorkSpace_PrintOut_List(code,text,project,file,row,type,textColor);
    }
}

//清理行的所有行文本
void Plugin_Base::clearList()
{
    if(PluginFuns::WorkSpace_PrintOut_List_Clear){
        PluginFuns::WorkSpace_PrintOut_List_Clear();
    }
}

//在文本窗口输出文本
void Plugin_Base::printTextSpace(QColor color, QString printText)
{
    if(PluginFuns::WorkSpace_PrintOut_TextSpace_Print){
        PluginFuns::WorkSpace_PrintOut_TextSpace_Print(color,printText);
    }
}

//在文本窗口输出文本
void Plugin_Base::printTextSpaceLine(QColor color, QString printText)
{
    if(PluginFuns::WorkSpace_PrintOut_TextSpace_PrintLine){
        PluginFuns::WorkSpace_PrintOut_TextSpace_PrintLine(color,printText);
    }
}

//清理文本窗口所有的文本
void Plugin_Base::clearTextSpace()
{
    if(PluginFuns::WorkSpace_PrintOut_TextSpace_Clear){
        PluginFuns::WorkSpace_PrintOut_TextSpace_Clear();
    }
}

//在Tab添加窗口
void Plugin_Base::addTabWindow(QString title, QWidget *form, QString sign, QIcon titeIco, PluginGlobalMsg::TabType type)
{
    if(PluginFuns::WorkSpace_addTabWindow){
        PluginFuns::WorkSpace_addTabWindow(title,form,sign,titeIco,type);
    }
}

//插件内投递消息
QString Plugin_Base::postPluginMessage(QString pluginSign, QString pustMsg)
{
    if(PluginFuns::PluginManger_PostMsg){
        return PluginFuns::PluginManger_PostMsg(this->self_BaseMsg.sign,pluginSign,pustMsg);
    }
    return QString();
}

//添加DockWidget
void Plugin_Base::addDockWidget(Qt::DockWidgetArea area, QDockWidget *dockWidget)
{
    if(PluginFuns::WorkSpace_DockWidget_Add){
        PluginFuns::WorkSpace_DockWidget_Add(area,dockWidget);
    }
}

//移除DockWidget
void Plugin_Base::removeDockWidget(QDockWidget *dockWidget)
{
    if(PluginFuns::WorkSpace_DockWidget_remove){
        PluginFuns::WorkSpace_DockWidget_remove(dockWidget);
    }
}
