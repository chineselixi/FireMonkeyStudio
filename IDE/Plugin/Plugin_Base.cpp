
#include "Plugin_Base.h"

//add menu to toolbar menu 
//添加菜单到工具栏菜单
void Plugin_Base::menu_addMenuBarMenu(PluginGlobalMsg::MenuBarType menuType, QAction *action)
{
    PluginGlobalMsg::menuFun t_fun = nullptr;
    switch (menuType) {
    default:{}
    //extend menu 
    case PluginGlobalMsg::MenuBarType::extendType:{ //拓展菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_Extend;break;
    }
    //tool menu 
    case PluginGlobalMsg::MenuBarType::toolType:{ //工具菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_Tool;break;
    }
    //setting menu
    case PluginGlobalMsg::MenuBarType::settingType:{ //设置菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_Setting;break;
    }
    //help menu
    case PluginGlobalMsg::MenuBarType::helpsType:{ //帮助菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_Helps;break;
    }
    //view menu
    case PluginGlobalMsg::MenuBarType::viewType:{ //视图菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_View;break;
    }
    //compile menu
    case PluginGlobalMsg::MenuBarType::compileType:{ //编译菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_Compile;break;
    }
    //database menu
    case PluginGlobalMsg::MenuBarType::dataBaseType:{ //数据库菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_DataBase;break;
    }
    //insert menu
    case PluginGlobalMsg::MenuBarType::insertType:{ //插入菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_Insert;break;
    }
    //file menu
    case PluginGlobalMsg::MenuBarType::fileType:{ //文件菜单
        t_fun = this->WorkSpace_AddMenu_ToolBar_File;break;
    }
    }

    //pointer available 
    if(t_fun != nullptr){ //指针有效
        t_fun(action);
    }
}
//add menu to project manager 
//添加菜单到项目管理器
void Plugin_Base::menu_addProMangerMenu(PluginGlobalMsg::proMangerMenuType menuType, QAction *action)
{
    PluginGlobalMsg::menuFun t_fun = nullptr;
    switch (menuType) {
    default:{}
    //default 
    case PluginGlobalMsg::proMangerMenuType::Normal:{ //默认
        t_fun = this->WorkSpace_AddMenu_ProManger_ProNormal;break;
    }
    //project list 
    case PluginGlobalMsg::proMangerMenuType::Project:{ //工程列表
        t_fun = this->WorkSpace_AddMenu_ProManger_Project;break;
    }
    }
    //pointer available 
    if(t_fun != nullptr){ //指针有效
        t_fun(action);
    }
}
//setting work space action enabled 
//设置工作空间Action启用
void Plugin_Base::menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction actionType, bool isEnable)
{
    if(this->WorkSpace_ToolBar_setActionEnable){
        this->WorkSpace_ToolBar_setActionEnable(actionType,isEnable);
    }

}
//close all sub menu of working components 
//关闭所有的工作控件子菜单
void Plugin_Base::menu_closeWorkSpaceAllAction()
{
    if(this->WorkSpace_ToolBar_closeAllAction){
        this->WorkSpace_ToolBar_closeAllAction();
    }
}
//add toolbar to work space 
//添加工具栏到工作空间
void Plugin_Base::menu_addToolBarToWs(QToolBar *toolBar)
{
    if(this->WorkSpace_ToolBar_addToolBar){
        this->WorkSpace_ToolBar_addToolBar(toolBar);
    }
}
//get main theme mark 
//获取主题标记
QString Plugin_Base::theme_getThemeSign()
{
    if(this->Theme_get){
        return this->Theme_get();
    }
    return "";
}
//set main theme mark
//设置主题标记
void Plugin_Base::theme_setThemeSign(QString sign)
{
    if(this->Theme_set){
        this->Theme_set(sign);
    }
}

//add compilation mode 
//添加编译模式
void Plugin_Base::compile_addCompileMod(QString signName)
{
    if(WorkSpace_CompileMod_Add){
        this->WorkSpace_CompileMod_Add(signName);
    }
}
//delete compilation mode
//删除编译模式
void Plugin_Base::compile_delCompileMod(QString signName)
{
    if(WorkSpace_CompileMod_Del){
        this->WorkSpace_CompileMod_Del(signName);
    }
}
//select compilation mode
//选择编译模式
void Plugin_Base::compile_selectCompileMod(QString signName)
{
    if(WorkSpace_CompileMod_Sel){
        this->WorkSpace_CompileMod_Sel(signName);
    }
}
//clear all compilation mode
//清空所有编译模式
void Plugin_Base::compile_clearAllCompileMod()
{
    if(WorkSpace_CompileMod_Cls){
        this->WorkSpace_CompileMod_Cls();
    }
}
//get current name of compilation mode mark
//获取当前编译模式标记名称
QString Plugin_Base::compile_getCompileModSignName()
{
    if(WorkSpace_CompileMod_GetNow){
        return this->WorkSpace_CompileMod_GetNow();
    }
    return "";
}

//output a single line of text to output list
//在列表输出中输出一行文本
void Plugin_Base::print_printList(QString code, QString text, QString project, QString file, uint16_t line, uint16_t lineIndex, uint16_t len, PluginGlobalMsg::printIcoType type, QColor textColor)
{
    if(this->WorkSpace_PrintOut_List){
        this->WorkSpace_PrintOut_List(code,text,project,file,line,lineIndex,len,type,textColor);
    }
}
//clear all line text of line 
//清理行的所有行文本
void Plugin_Base::print_clearList()
{
    if(this->WorkSpace_PrintOut_List_Clear){
        this->WorkSpace_PrintOut_List_Clear();
    }
}
//output text to text window 
//在文本窗口输出文本
void Plugin_Base::print_printTextSpace(QColor color, QString printText)
{
    if(this->WorkSpace_PrintOut_TextSpace_Print){
        this->WorkSpace_PrintOut_TextSpace_Print(color,printText);
    }
}
//output text to text window 
//在文本窗口输出文本
void Plugin_Base::print_printTextSpaceLine(QColor color, QString printText)
{
    if(this->WorkSpace_PrintOut_TextSpace_PrintLine){
        this->WorkSpace_PrintOut_TextSpace_PrintLine(color,printText);
    }
}
//clear all text of text window 
//清理文本窗口所有的文本
void Plugin_Base::print_clearTextSpace()
{
    if(this->WorkSpace_PrintOut_TextSpace_Clear){
        this->WorkSpace_PrintOut_TextSpace_Clear();
    }
}
//post message in plugin 
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

//add window in tab
//在Tab添加窗口
void Plugin_Base::tabWindow_addTabWindow(QString title, QWidget *form, QString sign, QIcon titeIco, PluginGlobalMsg::TabType type,bool autoMangement)
{
    if(this->TabSpace_addTabWindow){
        this->TabSpace_addTabWindow(this,title,form,sign,titeIco,type,autoMangement);
    }
}

//query tab if exsit according to sign mark,if exsit ,choose it or not.
//this method can be used to query and select 
//根据sign标记查找是否存在Tab，如果存在，是否选择。此方法可由于查找和选择
bool Plugin_Base::tabWindow_hasTab(QString sign, bool select)
{
    if(this->TabSpace_hasTab_Sign){
        return this->TabSpace_hasTab_Sign(sign,select);
    }
    return false;
}

//query tab if exsit according to QWidget pointer,if exsit ,choose it or not.
//this method can be used to query and select 
//根据QWidget指针查找是否存在Tab，如果存在，是否选择。此方法可由于查找和选择
bool Plugin_Base::tabWindow_hasTab(QWidget *widget, bool select)
{
    if(this->TabSpace_hasTab_WidgetPtr){
        return this->TabSpace_hasTab_WidgetPtr(widget,select);
    }
    return false;
}

//get Widget pointer according to sign
//根据sign获取Widget指针
QWidget *Plugin_Base::tabWindow_getTabWidget(QString sign)
{
    if(this->TabSpace_getTabSWidget){
        return this->TabSpace_getTabSWidget(sign);
    }
    return nullptr;
}

//get sign information according to widget pointer
//根据widget指针获取sign信息
QString Plugin_Base::tabWindow_getTabSign(QWidget *widget)
{
    if(this->TabSpace_getTabSign){
        return this->TabSpace_getTabSign(widget);
    }
    return "";
}

//get current Widget component 
//获取当前的Widget控件
QWidget *Plugin_Base::tabWindow_getNowWidget()
{
    if(TabSpace_getNowWidget){
        return TabSpace_getNowWidget();
    }
    return nullptr;
}

//get current widget pointer 
//获取当前Widget指针
QString Plugin_Base::tabWindow_getNowSign()
{
    if(TabSpace_getNowSign){
        return TabSpace_getNowSign();
    }
    return "";
}

//add a setting mark
//添加一个设置标记
void Plugin_Base::mark_addMark(QString mark, QString value)
{
    if(setFun_add)setFun_add(this->self_BaseMsg.name.replace(" ","_").replace("\r","_").replace("\n","_").append(".").append(mark),value);
}
//get a mark content 
//获取一个标记内容
QVariant Plugin_Base::mark_getMark(QString mark,QString normal)
{
    if(setFun_get) return setFun_get(mark,normal);
    return QVariant();
}
//delete a mark
//删除一个标记
void Plugin_Base::mark_delMark(QString mark)
{
    if(setFun_del) setFun_del(mark);
}
//post strings to status bar
//投递字符串到状态栏
void Plugin_Base::tip_postTipStr(QString str,int showTime)
{
    if(tipsFun_addPost) tipsFun_addPost(str,showTime);
}
//add notification to notification manager 
//添加通知到通知管理器中
uint16_t Plugin_Base::tip_addTip(QString title, QString tip, qint64 showTime, PluginGlobalMsg::TipType type, QPixmap pixmap, bool canClose)
{
    if(tipsFun_addTip) return tipsFun_addTip(title, tip, type, pixmap, canClose, showTime);
    return 0;
}
//close a notification according to id ,if notification is not exsiting,return false 
//根据ID关闭一个通知，通知不存在则返回false
bool Plugin_Base::tip_closeTip(uint16_t id)
{
    if(tipsFun_closeTip) return tipsFun_closeTip(id);
    return false;
}
//judge if this notification exsiting 
//判断是否存在这个通知
bool Plugin_Base::tip_hasTip(uint16_t index)
{
    if(tipsFun_hasTip) return tipsFun_hasTip(index);
    return false;
}

//set tip title 
//设置提示标题
void Plugin_Base::tip_setTipTitle(uint16_t index, QString title)
{
    if(tipsFun_setTitle) tipsFun_setTitle(index,title);
}
//set tip text
//设置提示文本
void Plugin_Base::tip_setTipText(uint16_t index, QString text)
{
    if(tipsFun_setText) tipsFun_setText(index,text);
}
//set tip type 
//设置提示类型
void Plugin_Base::tip_setTipType(uint16_t index, PluginGlobalMsg::TipType type)
{
    if(tipsFun_setType) tipsFun_setType(index,type);
}
//set tip picture 
//设置提示图片
void Plugin_Base::tip_setTipPixmap(uint16_t index, QPixmap pixmap)
{
    if(tipsFun_setPix) tipsFun_setPix(index,pixmap);
}
//set tip is able to close 
//设置提示能够关闭
void Plugin_Base::tip_setCanClose(uint16_t index, bool canClose)
{
    if(tipsFun_setCanClose) tipsFun_setCanClose(index,canClose);
}
//set tip time 
//设置提示时间
void Plugin_Base::tip_setTipShowTime(uint16_t index, qint64 newShowTime)
{
    if(tipsFun_changeShowTime) tipsFun_changeShowTime(index,newShowTime);
}
//set the progress of progress bar of status bar
//设置状态栏进度条进度
void Plugin_Base::statusBar_setChangedProgressIndex(int index)
{
    if(statusFun_changedProgressIndex) statusFun_changedProgressIndex(index);
}
//set status bar button ,when funptr is nullptr,hide the range of .index to 1-6
//设置状态栏按钮，funPtr为nullptr时，隐藏.index的范围为1-6
void Plugin_Base::statusBar_setStatusButton(int btnIndex, QString title, QIcon ico_32x, QString sign, std::function<void (QString)> funPtr)
{
    if(statusFun_setBtn) statusFun_setBtn(btnIndex,title,ico_32x,sign,funPtr);
}
//hide all buttons 
//隐藏所有的按钮
void Plugin_Base::statusBar_setStatusHideAll()
{
    if(statusFun_hideAllBtn) statusFun_hideAllBtn();
}

//get basic info of project 
//获取工程的基础信息
PluginGlobalMsg::ProjectMsg Plugin_Base::projectManger_getProjectInfo(QString proPath)
{
    PluginGlobalMsg::ProjectMsg t_retBase;
    if(ProjectManger_getBase){
        t_retBase = ProjectManger_getBase(proPath);
    }
    return t_retBase;
}

//add document of creating new project  
//添加新建工程文档
void Plugin_Base::projectManger_addBuildFileSign(QString suffix, QString sign, QIcon ico_16, QString normalName, QString content)
{
    if(ProjectManger_addBuildSign){
        ProjectManger_addBuildSign(suffix, sign, ico_16, normalName, content);
    }
}
//delete creating file mark
//删除创建文件标记
void Plugin_Base::projectManger_delBuildFileSign(QString suffix)
{
    if(ProjectManger_delBuildSign){
        ProjectManger_delBuildSign(suffix);
    }
}
//add category file icon 
//添加类别文件图标
void Plugin_Base::projectManger_addFileIco(QString suffix, QIcon ico)
{
    if(ProjectManger_addFileIco){
        ProjectManger_addFileIco(suffix,ico);
    }
}
//set directory icon,if target is none,set type to non icon
//设置目标图标，如果目标为空，则设置类型为non的图标
void Plugin_Base::projectManger_setObjIco(QIcon ico, QString objPath)
{
    if(ProjectManger_setObjIco){
        ProjectManger_setObjIco(ico, objPath);
    }
}

//get project name which contains this file
//获取一个文件的所在的工程名字
QString Plugin_Base::projectManger_getFileProName(QString filePath)
{
    if(ProjectManger_getFileProName){
        return ProjectManger_getFileProName(filePath);
    }
    return "";
}

//get window pointer of workspace 
//获取工作空间窗口指针
QMainWindow *Plugin_Base::widget_getWorkSpaceWindowPtr()
{
    if(Widget_getWorkSpaceWindowPtr){
        return (QMainWindow*)Widget_getWorkSpaceWindowPtr();
    }
    return nullptr;
}

//save the code of specified path
//保存指定路径的代码
void Plugin_Base::codeEditor_save(QString pathSign)
{
    if(CodeEditor_save){
        CodeEditor_save(pathSign);
    }
}

//save all codes 
//保存全部代码
void Plugin_Base::codeEditor_saveAll()
{
    if(CodeEditor_saveAll){
        CodeEditor_saveAll();
    }
}

//add it to editor manager ,notice please ,if object is destroyed ,it will be deleted automatically 
//添加到编辑器管理器当中，注意，若对象销毁，则自动删除
bool Plugin_Base::codeEditor_addToManger(QObject *obj)
{
    if(CodeEditor_addToMangerPtr){
        return CodeEditor_addToMangerPtr(obj);
    }
    return false;
}

//delete from editor manager 
//从编辑器管理器删除
bool Plugin_Base::codeEditor_removeForManger(QObject *obj)
{
    if(CodeEditor_removeForMangerPtr){
        return CodeEditor_removeForMangerPtr(obj);
    }
    return false;
}

//QWidget *Plugin_Base::widget_getSubWidgetPtr(QWidget *parentWidget, QString subObjctName)
//{
//    return System_Widget::getSubWidgetPtr(parentWidget,subObjctName);
//}


