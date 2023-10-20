
#include "Plugin_Base.h"


//添加菜单到工具栏菜单
void Plugin_Base::addToolBarMenu(PluginGlobalMsg::toolBarMenuType menuType, QAction *action)
{
    PluginGlobalMsg::menuFun t_fun = nullptr;
    switch (menuType) {
    default:{}
    case PluginGlobalMsg::toolBarMenuType::extendType:{ //拓展菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_Extend;break;
    }
    case PluginGlobalMsg::toolBarMenuType::toolType:{ //工具菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_Tool;break;
    }
    case PluginGlobalMsg::toolBarMenuType::settingType:{ //设置菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_Setting;break;
    }
    case PluginGlobalMsg::toolBarMenuType::helpsType:{ //帮助菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_Helps;break;
    }
    case PluginGlobalMsg::toolBarMenuType::viewType:{ //视图菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_View;break;
    }
    case PluginGlobalMsg::toolBarMenuType::compileType:{ //编译菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_Compile;break;
    }
    case PluginGlobalMsg::toolBarMenuType::dataBaseType:{ //数据库菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_DataBase;break;
    }
    case PluginGlobalMsg::toolBarMenuType::insertType:{ //插入菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_Insert;break;
    }
    case PluginGlobalMsg::toolBarMenuType::fileType:{ //文件菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_File;break;
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
        t_fun = this->WorkSpace_AddMenu_ProManger_NewFile;break;
    }
    case PluginGlobalMsg::proMangerMenuType::ProNormal:{ //默认
        t_fun = this->WorkSpace_AddMenu_ProManger_ProNormal;break;
    }
    case PluginGlobalMsg::proMangerMenuType::Project:{ //工程列表
        t_fun = this->WorkSpace_AddMenu_ProManger_Project;break;
    }
    }
    if(t_fun != nullptr){ //指针有效
        t_fun(action);
    }
}

//设置工作空间Action启用
void Plugin_Base::setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction actionType, bool isEnable)
{
    if(this->WorkSpace_ToolBar_setActionEnable){
        this->WorkSpace_ToolBar_setActionEnable(actionType,isEnable);
    }

}

//关闭所有的工作控件子菜单
void Plugin_Base::closeWorkSpaceAllAction()
{
    if(this->WorkSpace_ToolBar_closeAllAction){
        this->WorkSpace_ToolBar_closeAllAction();
    }
}

//添加工具栏到工作空间
void Plugin_Base::addToolBarToWs(QToolBar *toolBar)
{
    if(this->WorkSpace_ToolBar_addToolBar){
        this->WorkSpace_ToolBar_addToolBar(toolBar);
    }
}

//在列表输出中输出一行文本
void Plugin_Base::printList(QString code, QString text, QString project, QString file, int row, PluginGlobalMsg::printIcoType type, QColor textColor)
{
    if(this->WorkSpace_PrintOut_List){
        this->WorkSpace_PrintOut_List(code,text,project,file,row,type,textColor);
    }
}

//清理行的所有行文本
void Plugin_Base::clearList()
{
    if(this->WorkSpace_PrintOut_List_Clear){
        this->WorkSpace_PrintOut_List_Clear();
    }
}

//在文本窗口输出文本
void Plugin_Base::printTextSpace(QColor color, QString printText)
{
    if(this->WorkSpace_PrintOut_TextSpace_Print){
        this->WorkSpace_PrintOut_TextSpace_Print(color,printText);
    }
}

//在文本窗口输出文本
void Plugin_Base::printTextSpaceLine(QColor color, QString printText)
{
    if(this->WorkSpace_PrintOut_TextSpace_PrintLine){
        this->WorkSpace_PrintOut_TextSpace_PrintLine(color,printText);
    }
}

//清理文本窗口所有的文本
void Plugin_Base::clearTextSpace()
{
    if(this->WorkSpace_PrintOut_TextSpace_Clear){
        this->WorkSpace_PrintOut_TextSpace_Clear();
    }
}

//在Tab添加窗口
void Plugin_Base::addTabWindow(QString title, QWidget *form, QString sign, QIcon titeIco, PluginGlobalMsg::TabType type)
{
    if(this->TabSpace_addTabWindow){
        this->TabSpace_addTabWindow(this,title,form,sign,titeIco,type);
    }
}


//根据sign标记查找是否存在Tab，如果存在，是否选择。此方法可由于查找和选择
bool Plugin_Base::hasTab(QString sign, bool select)
{
    if(this->TabSpace_hasTab_Sign){
        return this->TabSpace_hasTab_Sign(sign,select);
    }
    return false;
}


//根据QWidget指针查找是否存在Tab，如果存在，是否选择。此方法可由于查找和选择
bool Plugin_Base::hasTab(QWidget *widget, bool select)
{
    if(this->TabSpace_hasTab_WidgetPtr){
        return this->TabSpace_hasTab_WidgetPtr(widget,select);
    }
    return false;
}


//根据sign获取Widget指针
QWidget *Plugin_Base::getTabWidget(QString sign)
{
    if(this->TabSpace_getTabSWidget){
        return this->TabSpace_getTabSWidget(sign);
    }
    return nullptr;
}


//根据widget指针获取sign信息
QString Plugin_Base::getTabSign(QWidget *widget)
{
    if(this->TabSpace_getTabSign){
        return this->TabSpace_getTabSign(widget);
    }
    return "";
}

//插件内投递消息
QString Plugin_Base::postPluginMessage(QString pluginSign, QString pustMsg)
{
    if(this->PluginManger_PostMsg){
        return this->PluginManger_PostMsg(this->self_BaseMsg.sign,pluginSign,pustMsg);
    }
    return QString();
}

//添加DockWidget
void Plugin_Base::addDockWidget(Qt::DockWidgetArea area, QDockWidget *dockWidget)
{
    if(this->WorkSpace_DockWidget_Add){
        this->WorkSpace_DockWidget_Add(area,dockWidget);
    }
}

//移除DockWidget
void Plugin_Base::removeDockWidget(QDockWidget *dockWidget)
{
    if(this->WorkSpace_DockWidget_remove){
        this->WorkSpace_DockWidget_remove(dockWidget);
    }
}
