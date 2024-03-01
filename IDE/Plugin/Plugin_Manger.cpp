
#include "Plugin_Manger.h"

#include "QDir"
#include "QFileInfo"
#include "SwSystem/System_GlobalVar.h"
#include "SwSystem/System_History.h"
#include "SwSystem/System_SystemSetting.h"
#include "SwSystem/System_UtilFun.h"

#include "QCoreApplication"

#include "QMessageBox"

Plugin_Manger::Plugin_Manger()
{

}

Plugin_Manger::~Plugin_Manger()
{
    for(int a=0;a<List_plg.length();a++){ //关闭所有回收对象
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        List_plg[a].qLibPth->unload();
        delete List_plg[a].qLibPth;
    }
}


//查找插件文件
void Plugin_Manger::findPlugin(QString path, QVector<QString>& retFiles,QString plgSuffix)
{
    QDir t_dir(path);
    if(!t_dir.exists()) return;
    QFileInfoList t_infoListDir = t_dir.entryInfoList(QDir::Dirs|QDir::NoDotAndDotDot); //只检查有多少目录
    for(int a = 0;a<t_infoListDir.length();a++){
        if(t_infoListDir[a].exists()){
            QDir t_dirFiles(t_infoListDir[a].filePath());
            QFileInfoList t_infoListFile = t_dirFiles.entryInfoList(QDir::Files|QDir::NoDotAndDotDot); //只检查有多少文件
            for(int b = 0;b<t_infoListFile.length();b++){
                if(t_infoListFile[b].isFile() && t_infoListFile[b].suffix() == plgSuffix){ //判断是否为工程模板文件
                    retFiles.append(t_infoListFile[b].absoluteFilePath());
                }
            }
        }
    }
}



//根据目录扫描并且添加插件对象
void Plugin_Manger::initPlugin(QString dirPath,QString plgSuffix)
{
    QVector<QString> t_pathList;
    this->findPlugin(dirPath,t_pathList,plgSuffix); //扫描plg插件

    for(int a=0;a<t_pathList.length();a++){
        PluginMsg t_plgMsg; //插件信息
        t_plgMsg.filePath = t_pathList[a];

        if(HistoryList::sys_pluginHistory->has(t_pathList[a].replace(System_OS::getaApplicationDirPath_EX(),"<pluginPath>"))){ //检查插件是否已经启用
            QLibrary* t_lib = new QLibrary(t_plgMsg.filePath); //加载插件（以动态库的形式加载插件，插件本身就是一个动态库）
            if(t_lib->load()){
                typedef Plugin_Base* (*fun)();
                fun t_getIns = (fun)t_lib->resolve("GetInstance"); //加载实例对象
                if(t_getIns != nullptr){
                    //已经获取了实例
                    t_plgMsg.plgPth = t_getIns(); //保存实例对象
                    t_plgMsg.qLibPth = t_lib; //保存当前的QLibrary对象
                    t_plgMsg.plgPth->event_onLoading(); //模块加载完成，通知当前加载模块信息
                    goto ADDMSG;
                }
            }
            delete t_lib;
        }
    ADDMSG:
        this->List_plg.append(t_plgMsg); //添加实例插件
    }


    //将未载入的插件排序到后面
    int t_endIndex = this->List_plg.length() - 1;
    for(int a=this->List_plg.length() - 1; a>=0; a--){
        for(; t_endIndex>=0; t_endIndex--){
            if(List_plg[t_endIndex].plgPth == nullptr){
                PluginMsg t_plgMsg = List_plg[t_endIndex];
                List_plg[t_endIndex] = List_plg[a];
                List_plg[a] = t_plgMsg;
                break;
            }
        }
    }

    //插件优先级排序,优先级从大到小排序
    for(int a=0;a<this->List_plg.length() - 1;a++){
        if(this->List_plg[a].plgPth == nullptr){ //遇到空插件则立即跳出
            break;
        }
        for(int b=0;b<this->List_plg.length() - 1 - a;b++){
            if(this->List_plg[b].plgPth == nullptr){ //遇到空插件则立即跳出
                break;
            }
            if(this->List_plg[b].plgPth->self_BaseMsg.level < this->List_plg[b + 1].plgPth->self_BaseMsg.level){
                PluginMsg t_plgMsg = this->List_plg[b];
                this->List_plg[b] = this->List_plg[b+1];
                this->List_plg[b+1] = t_plgMsg;
            }
        }
    }

    //插件初始化以后，直接绑定插件管理器
    this->pluginManger_init_building(); //绑定插件管理器

    //绑定设置接口
    this->setting_init_building();//加载设置接口

    //初始化主题操作接口
    this->themeChanged_init_building(); //设置主题设置获取接口
}



//获取插件列表信息
QVector<Plugin_Manger::PluginMsg> Plugin_Manger::getPluginList()
{
    //    QVector<PluginMsg> t_list;
    //    for(auto value : List_plg){
    //        if(value.plgPth != nullptr){
    //            t_list.append(value);
    //        }
    //    }
    return List_plg;
}


//根据文件名获取插件信息
Plugin_Base::libMsg Plugin_Manger::getPluginMsg(QString filePath)
{
    Plugin_Base::libMsg t_msg;
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].filePath == filePath){
            t_msg = this->List_plg[a].plgPth->getBaseMsg();
            break;
        }
    }
    return t_msg;
}



//获取设置组件列表
Plugin_Base::settingMsgList Plugin_Manger::getSettingWidgets()
{
    Plugin_Base::settingMsgList t_retList;
    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            Plugin_Base::settingMsgList t_l;
            this->List_plg[a].plgPth->event_onLoadSettingsWidget(t_l);
            t_retList.append(t_l);
        }
    }
    return t_retList;
}




//初始化workSpace的插件菜单
void Plugin_Manger::workSpace_init_Menu(PluginGlobalMsg::menuFun toolBar_tool, PluginGlobalMsg::menuFun toolBar_set, PluginGlobalMsg::menuFun toolBar_help, PluginGlobalMsg::menuFun toolBar_view,
                                        PluginGlobalMsg::menuFun toolBar_extend, PluginGlobalMsg::menuFun toolBar_db, PluginGlobalMsg::menuFun toolBar_comple, PluginGlobalMsg::menuFun toolBar_insert, PluginGlobalMsg::menuFun toolBar_file,
                                        PluginGlobalMsg::menuFun ProManger_project, PluginGlobalMsg::menuFun ProManger_proNormal)
{
    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            this->List_plg[a].plgPth->WorkSpace_AddMenu_ToolBar_Tool = toolBar_tool;
            this->List_plg[a].plgPth->WorkSpace_AddMenu_ToolBar_Setting = toolBar_set;
            this->List_plg[a].plgPth->WorkSpace_AddMenu_ToolBar_Helps = toolBar_help;
            this->List_plg[a].plgPth->WorkSpace_AddMenu_ToolBar_View = toolBar_view;
            this->List_plg[a].plgPth->WorkSpace_AddMenu_ToolBar_Extend = toolBar_extend;
            this->List_plg[a].plgPth->WorkSpace_AddMenu_ToolBar_DataBase = toolBar_db;
            this->List_plg[a].plgPth->WorkSpace_AddMenu_ToolBar_Compile = toolBar_comple;
            this->List_plg[a].plgPth->WorkSpace_AddMenu_ToolBar_Insert = toolBar_insert;
            this->List_plg[a].plgPth->WorkSpace_AddMenu_ToolBar_File = toolBar_file;
            this->List_plg[a].plgPth->WorkSpace_AddMenu_ProManger_Project = ProManger_project;
            this->List_plg[a].plgPth->WorkSpace_AddMenu_ProManger_ProNormal = ProManger_proNormal;
        }
    }
}



//添加workSpace的Tab窗口
void Plugin_Manger::TabSpace_init_tabView(PluginGlobalMsg::addTabViewPth addTabFun,
                                           PluginGlobalMsg::tab_getSign getSignFun,PluginGlobalMsg::tab_getWidget getWidgetFun,
                                           PluginGlobalMsg::tab_hasTab_Sign hasSignFun,PluginGlobalMsg::tab_hasTab_WidgetPtr hasWidgtFun,
                                           PluginGlobalMsg::tab_getNowWidget getNowWidget,PluginGlobalMsg::tab_getNowSign getNowSign)
{
    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            this->List_plg[a].plgPth->TabSpace_addTabWindow = addTabFun;
            this->List_plg[a].plgPth->TabSpace_getTabSign = getSignFun;
            this->List_plg[a].plgPth->TabSpace_getTabSWidget = getWidgetFun;
            this->List_plg[a].plgPth->TabSpace_hasTab_Sign = hasSignFun;
            this->List_plg[a].plgPth->TabSpace_hasTab_WidgetPtr = hasWidgtFun;
            this->List_plg[a].plgPth->TabSpace_getNowWidget = getNowWidget;
            this->List_plg[a].plgPth->TabSpace_getNowSign = getNowSign;
        }
    }
}



////添加workSpace的代码编辑器接口
//void Plugin_Manger::workSpace_init_codeEditor(PluginGlobalMsg::editorFun_create createPth,
//                                              PluginGlobalMsg::editorFun_addKetWord addWordPth,
//                                              PluginGlobalMsg::editorFun_getStr getStrPth,
//                                              PluginGlobalMsg::editorFun_addStr addStrPth)
//{
//    for(int a = 0;a < List_plg.length();a++){
//        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
//        this->List_plg[a].plgPth->CodeEditorFunPtr_Create = createPth;
//        this->List_plg[a].plgPth->CodeEditorFunPtr_AddkeyWord = addWordPth;
//        this->List_plg[a].plgPth->CodeEditorFunPtr_GetCode = getStrPth;
//        this->List_plg[a].plgPth->CodeEditorFunPtr_AddStr = addStrPth;
//    }
//}




//设置工具栏内控件的启用与关闭,添加工具栏
void Plugin_Manger::workSpace_init_toolBarFuns(PluginGlobalMsg::toolBar_action_setEnable toolBar_setActionEnableFunPtr,PluginGlobalMsg::fun_void toolBar_clearAllActionFunPtr,PluginGlobalMsg::toolBarFun toolBar_addToolBarFunPtr)
{
    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            this->List_plg[a].plgPth->WorkSpace_ToolBar_setActionEnable = toolBar_setActionEnableFunPtr;
            this->List_plg[a].plgPth->WorkSpace_ToolBar_closeAllAction = toolBar_clearAllActionFunPtr;
            this->List_plg[a].plgPth->WorkSpace_ToolBar_addToolBar = toolBar_addToolBarFunPtr;
        }
    }
}





//初始化提示输出接口
void Plugin_Manger::workSpace_init_tipPrint(PluginGlobalMsg::printFun_printList fun_printList,
                                            PluginGlobalMsg::printFun_printTextSpace fun_printText,
                                            PluginGlobalMsg::printFun_printTextSpace fun_printTextLine,
                                            PluginGlobalMsg::printFun_clear fun_clearPrintList,
                                            PluginGlobalMsg::printFun_clear fun_clearTextSpace)
{
    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            this->List_plg[a].plgPth->WorkSpace_PrintOut_List = fun_printList;
            this->List_plg[a].plgPth->WorkSpace_PrintOut_TextSpace_Print = fun_printText;
            this->List_plg[a].plgPth->WorkSpace_PrintOut_TextSpace_PrintLine = fun_printTextLine;
            this->List_plg[a].plgPth->WorkSpace_PrintOut_List_Clear = fun_clearPrintList;
            this->List_plg[a].plgPth->WorkSpace_PrintOut_TextSpace_Clear = fun_clearTextSpace;
        }
    }
}




//插件接口绑定
void Plugin_Manger::pluginManger_init_building()
{
    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            this->List_plg[a].plgPth->PluginManger_PostMsg = [this](QString selfSign,QString pluginSign,QString pustMsg)->QString{
                QString t_plgMsg = "";
                for(int b = 0;b < List_plg.length();b++){
                    if(pluginSign == List_plg[b].plgPth->getBaseMsg().sign){ //如果查找到当前的插件标记则开始信息投递
                        QString t_retMsg = List_plg[b].plgPth->event_onPluginReceive(selfSign,pustMsg); //投递信息
                        if(!t_retMsg.isEmpty()){
                            t_plgMsg = t_retMsg;
                            break;
                        }
                    }
                }
                return t_plgMsg; //返回最后一个信息投递的有效返回信息
            };
        }
    }

}


//设置接口绑定
void Plugin_Manger::setting_init_building()
{
    PluginGlobalMsg::setPtr_addFun addPtr = [](QString maker,QVariant value){
        Setting::sys_setting->changeSetting("PluginSetting",maker,value);
    };

    PluginGlobalMsg::setPtr_deleteFun delPtr = [](QString maker){
        Setting::sys_setting->removeValue("PluginSetting",maker);
    };

    PluginGlobalMsg::setPtr_getFun getPtr = [](QString maker,QString normal)->QVariant{
        return Setting::sys_setting->getSettingValue("PluginSetting",maker,normal);
    };

    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            this->List_plg[a].plgPth->setFun_add = addPtr;
            this->List_plg[a].plgPth->setFun_del = delPtr;
            this->List_plg[a].plgPth->setFun_get = getPtr;
        }
    }
}

//声明主题改变
class Form_SystemSettings{
public:
    static void changeThream(QString styleName = "Blue");
};
//主题操作绑定
void Plugin_Manger::themeChanged_init_building()
{
    PluginGlobalMsg::theme_setFunPtr t_setPtr = [](QString sign){
        Setting::style_themeName = sign;
        Form_SystemSettings::changeThream(sign);
    };

    PluginGlobalMsg::theme_getFunPtr t_getPtr = []()->QString{
        return Setting::style_themeName;
    };


    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            this->List_plg[a].plgPth->Theme_get = t_getPtr;
            this->List_plg[a].plgPth->Theme_set = t_setPtr;
        }
    }
}


//代码编辑器管理器绑定
void Plugin_Manger::codeEditorManger_init_building(
    PluginGlobalMsg::funStr_void CodeEditor_save,     //保存指定路径代码编辑器内的代码
    PluginGlobalMsg::fun_void CodeEditor_saveAll,     //保存全部已打开代码
    PluginGlobalMsg::codeEditorFun CodeEditor_addToMangerPtr,    //将代码编辑器添加到管理器
    PluginGlobalMsg::codeEditorFun CodeEditor_removeForMangerPtr    //将代码编辑器从管理器移除
)
{
    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            this->List_plg[a].plgPth->CodeEditor_save = CodeEditor_save;
            this->List_plg[a].plgPth->CodeEditor_saveAll = CodeEditor_saveAll;
            this->List_plg[a].plgPth->CodeEditor_addToMangerPtr = CodeEditor_addToMangerPtr;
            this->List_plg[a].plgPth->CodeEditor_removeForMangerPtr = CodeEditor_removeForMangerPtr;
        }
    }
}

//工程管理器绑定
void Plugin_Manger::projectManger_init_building(PluginGlobalMsg::projectManger_getProMsgBase ProjectManger_getBaseFun,
                                                PluginGlobalMsg::projectManger_addBuildFileSign ProjectManger_addBuildSignFun,
                                                PluginGlobalMsg::projectManger_delBuildFileSign ProjectManger_delBuildSignFun,
                                                PluginGlobalMsg::projectManger_addFileIco ProjectManger_addFileIcoFun,
                                                PluginGlobalMsg::projectManger_setObjIco ProjectManger_setObjIcoFun)
{
    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            this->List_plg[a].plgPth->ProjectManger_getBase = ProjectManger_getBaseFun;
            this->List_plg[a].plgPth->ProjectManger_addBuildSign = ProjectManger_addBuildSignFun;
            this->List_plg[a].plgPth->ProjectManger_delBuildSign = ProjectManger_delBuildSignFun;
            this->List_plg[a].plgPth->ProjectManger_addFileIco = ProjectManger_addFileIcoFun;
            this->List_plg[a].plgPth->ProjectManger_setObjIco = ProjectManger_setObjIcoFun;
        }
    }
}


//初始化编译模式接口
void Plugin_Manger::workSpace_init_compileMod(PluginGlobalMsg::compileMod_changeFun addFun,
                                              PluginGlobalMsg::compileMod_changeFun delFun,
                                              PluginGlobalMsg::compileMod_changeFun selectFun,
                                              PluginGlobalMsg::fun_void clsFun,
                                              PluginGlobalMsg::fun_str getNowFun)
{
    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            this->List_plg[a].plgPth->WorkSpace_CompileMod_Add = addFun;
            this->List_plg[a].plgPth->WorkSpace_CompileMod_Del = delFun;
            this->List_plg[a].plgPth->WorkSpace_CompileMod_Sel = selectFun;
            this->List_plg[a].plgPth->WorkSpace_CompileMod_Cls = clsFun;
            this->List_plg[a].plgPth->WorkSpace_CompileMod_GetNow = getNowFun;
        }
    }
}


//初始化通知管理器
void Plugin_Manger::workSpace_init_tipsManger(PluginGlobalMsg::tipFun_postStr tipsFun_addPost,
                                              PluginGlobalMsg::tipFun_addTip tipsFun_addTip,
                                              PluginGlobalMsg::tipFun_closeTip tipsFun_closeTip,
                                              PluginGlobalMsg::tipFun_hasTip tipsFun_hasTip,
                                              PluginGlobalMsg::tipFun_setTipTitle tipsFun_setTitle,
                                              PluginGlobalMsg::tipFun_setTipText tipsFun_setText,
                                              PluginGlobalMsg::tipFun_setTipType tipsFun_setType,
                                              PluginGlobalMsg::tipFun_setTipPixmap tipsFun_setPix,
                                              PluginGlobalMsg::tipFun_setTipCanClose tipsFun_setCanClose,
                                              PluginGlobalMsg::tipFun_setTipShowTime tipsFun_changeShowTime)
{
    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            this->List_plg[a].plgPth->tipsFun_addPost = tipsFun_addPost;
            this->List_plg[a].plgPth->tipsFun_addTip = tipsFun_addTip;
            this->List_plg[a].plgPth->tipsFun_closeTip = tipsFun_closeTip;
            this->List_plg[a].plgPth->tipsFun_hasTip = tipsFun_hasTip;
            this->List_plg[a].plgPth->tipsFun_setTitle = tipsFun_setTitle;
            this->List_plg[a].plgPth->tipsFun_setText = tipsFun_setText;
            this->List_plg[a].plgPth->tipsFun_setType = tipsFun_setType;
            this->List_plg[a].plgPth->tipsFun_setPix = tipsFun_setPix;
            this->List_plg[a].plgPth->tipsFun_setCanClose = tipsFun_setCanClose;
            this->List_plg[a].plgPth->tipsFun_changeShowTime = tipsFun_changeShowTime;
        }
    }
}


//初始化状态栏操作接口
void Plugin_Manger::workSpace_init_statusOperate(PluginGlobalMsg::statusbarFun_setProgressIndex statusFun_changedProgressIndex,
                                                 PluginGlobalMsg::statusbarFun_setButton statusFun_setBtn,
                                                 PluginGlobalMsg::statusbarFun_hideAllBtn statusFun_hideAllBtn)
{
    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            this->List_plg[a].plgPth->statusFun_changedProgressIndex = statusFun_changedProgressIndex;
            this->List_plg[a].plgPth->statusFun_setBtn = statusFun_setBtn;
            this->List_plg[a].plgPth->statusFun_hideAllBtn = statusFun_hideAllBtn;
        }
    }
}


//初始化控件
void Plugin_Manger::workSpace_init_widget(PluginGlobalMsg::widgetFun_getWidget widget_getMainWindow)
{
    for(int a = 0;a < List_plg.length();a++){
        if(this->List_plg[a].plgPth != nullptr){
            this->List_plg[a].plgPth->Widget_getWorkSpaceWindowPtr = widget_getMainWindow;
        }
    }
}


//浮动窗格绑定
//void Plugin_Manger::workSpace_init_dockWidget(PluginGlobalMsg::dockWidgetFun_add addFun,PluginGlobalMsg::dockWidgetFun_rm rmFun)
//{
//    for(int a = 0;a < List_plg.length();a++){
//        if(this->List_plg[a].plgPth != nullptr){
//            this->List_plg[a].plgPth->WorkSpace_DockWidget_Add = addFun;
//            this->List_plg[a].plgPth->WorkSpace_DockWidget_remove = rmFun;
//        }
//    }
//}




//当模块加载完毕，将第一时间激发模块事件
void Plugin_Manger::event_onModLoadFinish()
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].plgPth->event_onModLoadFinish() == false){ //若插件阻止触发，则跳出
            break;
        }
    }
}

//当编译模式被改变激发模块事件
void Plugin_Manger::event_onCompileTypeChanged(QString typeSign)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].plgPth->event_onCompileTypeChanged(typeSign) == false){ //若插件阻止触发，则跳出
            break;
        }
    }
}

//当文件被打开，激发模块事件
void Plugin_Manger::event_onFileOpen(QString filePath,uint16_t line,uint16_t lineIndex,uint16_t len)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].plgPth->event_onFileOpen(filePath,line,lineIndex,len) == false){ //若插件阻止触发，则跳出
            break;
        }
    }
}


//当文件被删除或者关闭事件激发
void Plugin_Manger::event_onFileClose(QString filePath)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].plgPth->event_onFileClose(filePath) == false){ //若插件阻止触发，则跳出
            break;
        }
    }
}



//当文件被保存
void Plugin_Manger::event_onFileSave(QString filePath)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].plgPth->event_onFileSave(filePath) == false){ //若插件阻止触发，则跳出
            break;
        }
    }
}


//当文件全部保存
void Plugin_Manger::event_onFileSaveAll()
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].plgPth->event_onFileSaveAll() == false){ //若插件阻止触发，则跳出
            break;
        }
    }
}



//当工程被加载完毕，或者切换的工程已经被改变
void Plugin_Manger::event_onPorjectLoad(QString proPath, QString proLangs, QString proNoteClass)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].plgPth->event_onProjectActiveChanged(proPath,proLangs,proNoteClass) == false){ //若插件阻止触发，则跳出
            break;
        }
    }
}


//工程被构建
void Plugin_Manger::event_onProjectBuild(QString projectPath)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].plgPth->event_onProjectBuild(projectPath) == false){ //若插件阻止触发，则跳出
            break;
        }
    }
}


//工程被清理
void Plugin_Manger::event_onProjectClear(QString projectPath)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].plgPth->event_onProjectClear(projectPath) == false){ //若插件阻止触发，则跳出
            break;
        }
    }
}


//工程被关闭
void Plugin_Manger::event_onProjectClose(QString projectPath)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].plgPth->event_onProjectClose(projectPath) == false){ //若插件阻止触发，则跳出
            break;
        }
    }
}


//当文件路径被改变
void Plugin_Manger::event_onFileRename(QString oldPath, QString newPath)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        List_plg[a].plgPth->event_onFileRename(oldPath,newPath);
    }
}


//当主题标记被改变
void Plugin_Manger::event_onThemeChanged(QString themeSign)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        List_plg[a].plgPth->event_onThemeChanged(themeSign);
    }
}



//工作空间创建完毕事件，此事件不可阻止，，但是可以阻塞，将为每一个插件提供事件响应
void Plugin_Manger::event_onWorkSpaceFinish()
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        List_plg[a].plgPth->event_onWorkSpaceFinish();
    }
}

//工作空间正在被关闭，不可被阻止，但是可以阻塞，将为每一个插件提供事件响应
void Plugin_Manger::event_onWorkSpaceClose()
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        List_plg[a].plgPth->event_onWorkSpaceClose();
    }
}



//当工具栏的Action被触发
void Plugin_Manger::event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction actionType, QString proPath, QString proLangs, QString proNoteClass)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth != nullptr){ //只对加载的插件进行绑定
            if(List_plg[a].plgPth->event_onToolBarActionTriggered(actionType,proPath,proLangs,proNoteClass) == false){
                break;
            }
        }
    }
}



