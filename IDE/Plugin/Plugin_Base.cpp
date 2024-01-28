
#include "Plugin_Base.h"


//添加菜单到工具栏菜单
void Plugin_Base::menu_addToolBarMenu(PluginGlobalMsg::toolBarMenuType menuType, QAction *action)
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
void Plugin_Base::menu_addProMangerMenu(PluginGlobalMsg::proMangerMenuType menuType, QAction *action)
{
    PluginGlobalMsg::menuFun t_fun = nullptr;
    switch (menuType) {
    default:{}
    case PluginGlobalMsg::proMangerMenuType::Normal:{ //默认
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
void Plugin_Base::menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction actionType, bool isEnable)
{
    if(this->WorkSpace_ToolBar_setActionEnable){
        this->WorkSpace_ToolBar_setActionEnable(actionType,isEnable);
    }

}

//关闭所有的工作控件子菜单
void Plugin_Base::menu_closeWorkSpaceAllAction()
{
    if(this->WorkSpace_ToolBar_closeAllAction){
        this->WorkSpace_ToolBar_closeAllAction();
    }
}

//添加工具栏到工作空间
void Plugin_Base::menu_addToolBarToWs(QToolBar *toolBar)
{
    if(this->WorkSpace_ToolBar_addToolBar){
        this->WorkSpace_ToolBar_addToolBar(toolBar);
    }
}

//获取主题标记
QString Plugin_Base::theme_getThemeSign()
{
    if(this->Theme_get){
        return this->Theme_get();
    }
}

//设置主题标记
void Plugin_Base::theme_setThemeSign(QString sign)
{
    if(this->Theme_set){
        this->Theme_set(sign);
    }
}


//添加编译模式
void Plugin_Base::compile_addCompileMod(QString signName)
{
    if(WorkSpace_CompileMod_Add){
        this->WorkSpace_CompileMod_Add(signName);
    }
}

//删除编译模式
void Plugin_Base::compile_delCompileMod(QString signName)
{
    if(WorkSpace_CompileMod_Del){
        this->WorkSpace_CompileMod_Del(signName);
    }
}

//选择编译模式
void Plugin_Base::compile_selectCompileMod(QString signName)
{
    if(WorkSpace_CompileMod_Sel){
        this->WorkSpace_CompileMod_Sel(signName);
    }
}

//清空所有编译模式
void Plugin_Base::compile_clearAllCompileMod()
{
    if(WorkSpace_CompileMod_Cls){
        this->WorkSpace_CompileMod_Cls();
    }
}

//获取当前编译模式标记名称
QString Plugin_Base::compile_getCompileModSignName()
{
    if(WorkSpace_CompileMod_GetNow){
        return this->WorkSpace_CompileMod_GetNow();
    }
    return "";
}

//在列表输出中输出一行文本
void Plugin_Base::print_printList(QString code, QString text, QString project, QString file, int row, PluginGlobalMsg::printIcoType type, QColor textColor)
{
    if(this->WorkSpace_PrintOut_List){
        this->WorkSpace_PrintOut_List(code,text,project,file,row,type,textColor);
    }
}

//清理行的所有行文本
void Plugin_Base::print_clearList()
{
    if(this->WorkSpace_PrintOut_List_Clear){
        this->WorkSpace_PrintOut_List_Clear();
    }
}

//在文本窗口输出文本
void Plugin_Base::print_printTextSpace(QColor color, QString printText)
{
    if(this->WorkSpace_PrintOut_TextSpace_Print){
        this->WorkSpace_PrintOut_TextSpace_Print(color,printText);
    }
}

//在文本窗口输出文本
void Plugin_Base::print_printTextSpaceLine(QColor color, QString printText)
{
    if(this->WorkSpace_PrintOut_TextSpace_PrintLine){
        this->WorkSpace_PrintOut_TextSpace_PrintLine(color,printText);
    }
}

//清理文本窗口所有的文本
void Plugin_Base::print_clearTextSpace()
{
    if(this->WorkSpace_PrintOut_TextSpace_Clear){
        this->WorkSpace_PrintOut_TextSpace_Clear();
    }
}

//插件内投递消息
QString Plugin_Base::plugin_postPluginMessage(QString pluginSign, QString pustMsg)
{
    if(this->PluginManger_PostMsg){
        return this->PluginManger_PostMsg(this->self_BaseMsg.sign,pluginSign,pustMsg);
    }
    return QString();
}

////添加DockWidget
//void Plugin_Base::dockwidget_addDockWidget(Qt::DockWidgetArea area, QDockWidget *dockWidget)
//{
//    if(this->WorkSpace_DockWidget_Add){
//        this->WorkSpace_DockWidget_Add(area,dockWidget);
//    }
//}

////移除DockWidget
//void Plugin_Base::dockwidget_removeDockWidget(QDockWidget *dockWidget)
//{
//    if(this->WorkSpace_DockWidget_remove){
//        this->WorkSpace_DockWidget_remove(dockWidget);
//    }
//}


//在Tab添加窗口
void Plugin_Base::tabWindow_addTabWindow(QString title, QWidget *form, QString sign, QIcon titeIco, PluginGlobalMsg::TabType type)
{
    if(this->TabSpace_addTabWindow){
        this->TabSpace_addTabWindow(this,title,form,sign,titeIco,type);
    }
}


//根据sign标记查找是否存在Tab，如果存在，是否选择。此方法可由于查找和选择
bool Plugin_Base::tabWindow_hasTab(QString sign, bool select)
{
    if(this->TabSpace_hasTab_Sign){
        return this->TabSpace_hasTab_Sign(sign,select);
    }
    return false;
}


//根据QWidget指针查找是否存在Tab，如果存在，是否选择。此方法可由于查找和选择
bool Plugin_Base::tabWindow_hasTab(QWidget *widget, bool select)
{
    if(this->TabSpace_hasTab_WidgetPtr){
        return this->TabSpace_hasTab_WidgetPtr(widget,select);
    }
    return false;
}


//根据sign获取Widget指针
QWidget *Plugin_Base::tabWindow_getTabWidget(QString sign)
{
    if(this->TabSpace_getTabSWidget){
        return this->TabSpace_getTabSWidget(sign);
    }
    return nullptr;
}


//根据widget指针获取sign信息
QString Plugin_Base::tabWindow_getTabSign(QWidget *widget)
{
    if(this->TabSpace_getTabSign){
        return this->TabSpace_getTabSign(widget);
    }
    return "";
}


//添加一个设置标记
void Plugin_Base::mark_addMark(QString mark, QString value)
{
    if(setFun_add)setFun_add(this->self_BaseMsg.name.replace(" ","_").replace("\r","_").replace("\n","_").append(".").append(mark),value);
}

//获取一个标记内容
QVariant Plugin_Base::mark_getMark(QString mark,QString normal)
{
    if(setFun_get) return setFun_get(mark,normal);
}

//删除一个标记
void Plugin_Base::mark_delMark(QString mark)
{
    if(setFun_del) setFun_del(mark);
}

//投递字符串到状态栏
void Plugin_Base::tip_postTipStr(QString str,int showTime)
{
    if(tipsFun_addPost) tipsFun_addPost(str,showTime);
}

//添加通知到通知管理器中
uint16_t Plugin_Base::tip_addTip(QString title, QString tip, qint64 showTime, PluginGlobalMsg::TipType type, QPixmap pixmap, bool canClose)
{
    if(tipsFun_addTip) return tipsFun_addTip(title, tip, type, pixmap, canClose, showTime);
}

//根据ID关闭一个停止，通知不存在则返回false
bool Plugin_Base::tip_closeTip(uint16_t id)
{
    if(tipsFun_closeTip) return tipsFun_closeTip(id);
}

//判断是否存在这个通知
bool Plugin_Base::tip_hasTip(uint16_t index)
{
    if(tipsFun_hasTip) return tipsFun_hasTip(index);
}


//设置提示标题
void Plugin_Base::tip_setTipTitle(uint16_t index, QString title)
{
    if(tipsFun_setTitle) tipsFun_setTitle(index,title);
}

//设置提示文本
void Plugin_Base::tip_setTipText(uint16_t index, QString text)
{
    if(tipsFun_setText) tipsFun_setText(index,text);
}

//设置提示类型
void Plugin_Base::tip_setTipType(uint16_t index, PluginGlobalMsg::TipType type)
{
    if(tipsFun_setType) tipsFun_setType(index,type);
}

//设置提示图片
void Plugin_Base::tip_setTipPixmap(uint16_t index, QPixmap pixmap)
{
    if(tipsFun_setPix) tipsFun_setPix(index,pixmap);
}

//设置提示能够关闭
void Plugin_Base::tip_setCanClose(uint16_t index, bool canClose)
{
    if(tipsFun_setCanClose) tipsFun_setCanClose(index,canClose);
}

//设置提示时间
void Plugin_Base::tip_setTipShowTime(uint16_t index, qint64 newShowTime)
{
    if(tipsFun_changeShowTime) tipsFun_changeShowTime(index,newShowTime);
}

//设置状态栏进度条进度
void Plugin_Base::statusBar_setChangedProgressIndex(int index)
{
    if(statusFun_changedProgressIndex) statusFun_changedProgressIndex(index);
}

//设置状态栏按钮，funPtr为nullptr时，隐藏.index的范围为1-6
void Plugin_Base::statusBar_setStatusButton(int btnIndex, QString title, QIcon ico_32x, QString sign, std::function<void (QString)> funPtr)
{
    if(statusFun_setBtn) statusFun_setBtn(btnIndex,title,ico_32x,sign,funPtr);
}

//隐藏所有的按钮
void Plugin_Base::statusBar_setStatusHideAll()
{
    if(statusFun_hideAllBtn) statusFun_hideAllBtn();
}


//获取工程的基础信息
PluginGlobalMsg::ProjectMsg Plugin_Base::projectManger_getProjectInfo(QString proPath)
{
    PluginGlobalMsg::ProjectMsg t_retBase;
    if(ProjectManger_getBase){
        t_retBase = ProjectManger_getBase(proPath);
    }
    return t_retBase;
}


//添加新建工程文档
void Plugin_Base::projectManger_addBuildFileSign(QString suffix, QString sign, QIcon ico_16, QString normalName, QString content)
{
    if(ProjectManger_addBuildSign){
        ProjectManger_addBuildSign(suffix, sign, ico_16, normalName, content);
    }
}

//删除创建文件标记
void Plugin_Base::projectManger_delBuildFileSign(QString suffix)
{
    if(ProjectManger_delBuildSign){
        ProjectManger_delBuildSign(suffix);
    }
}

//添加类别文件图标
void Plugin_Base::projectManger_addFileIco(QString suffix, QIcon ico)
{
    if(ProjectManger_addFileIco){
        ProjectManger_addFileIco(suffix,ico);
    }
}

//设置目标图标，如果目标为空，则设置类型为non的图标
void Plugin_Base::projectManger_setObjIco(QIcon ico, QString objPath)
{
    if(ProjectManger_setObjIco){
        ProjectManger_setObjIco(ico, objPath);
    }
}


//获取工作空间窗口指针
QMainWindow *Plugin_Base::widget_getWorkSpaceWindowPtr()
{
    if(Widget_getWorkSpaceWindowPtr){
        return (QMainWindow*)Widget_getWorkSpaceWindowPtr();
    }
    return nullptr;
}

//QWidget *Plugin_Base::widget_getSubWidgetPtr(QWidget *parentWidget, QString subObjctName)
//{
//    return System_Widget::getSubWidgetPtr(parentWidget,subObjctName);
//}


