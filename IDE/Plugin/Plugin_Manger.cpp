
#include "Plugin_Manger.h"
#include "Plugin_Funs.h"

#include "QDir"
#include "QFileInfo"
#include "SwSystem/System_GlobalVar.h""
#include "SwSystem/System_History.h"
#include "QCoreApplication"

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
        if(HistoryList::sys_pluginHistory->has(t_pathList[a].replace(QCoreApplication::applicationDirPath(),"<pluginPath>"))){ //检查插件是否已经启用
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



    //插件初始化以后，直接绑定插件管理器
    pluginManger_init_building(); //绑定插件管理器
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
                                        PluginGlobalMsg::menuFun ProManger_project, PluginGlobalMsg::menuFun ProManger_newFile, PluginGlobalMsg::menuFun ProManger_proNormal)
{
    PluginFuns::WorkSpace_AddMenu_ToolBar_Tool = toolBar_tool;
    PluginFuns::WorkSpace_AddMenu_ToolBar_Setting = toolBar_set;
    PluginFuns::WorkSpace_AddMenu_ToolBar_Helps = toolBar_help;
    PluginFuns::WorkSpace_AddMenu_ToolBar_View = toolBar_view;
    PluginFuns::WorkSpace_AddMenu_ToolBar_Extend = toolBar_extend;
    PluginFuns::WorkSpace_AddMenu_ToolBar_DataBase = toolBar_db;
    PluginFuns::WorkSpace_AddMenu_ToolBar_Compile = toolBar_comple;
    PluginFuns::WorkSpace_AddMenu_ToolBar_Insert = toolBar_insert;
    PluginFuns::WorkSpace_AddMenu_ToolBar_File = toolBar_file;
    PluginFuns::WorkSpace_AddMenu_ProManger_Project = ProManger_project;
    PluginFuns::WorkSpace_AddMenu_ProManger_NewFile = ProManger_newFile;
    PluginFuns::WorkSpace_AddMenu_ProManger_ProNormal = ProManger_proNormal;
}



//添加workSpace的Tab窗口
void Plugin_Manger::workSpace_init_tabView(PluginGlobalMsg::addTabViewPth pth)
{
    PluginFuns::WorkSpace_addTabWindow = pth;
}



////添加workSpace的代码编辑器接口
//void Plugin_Manger::workSpace_init_codeEditor(PluginGlobalMsg::editorFun_create createPth,
//                                              PluginGlobalMsg::editorFun_addKetWord addWordPth,
//                                              PluginGlobalMsg::editorFun_getStr getStrPth,
//                                              PluginGlobalMsg::editorFun_addStr addStrPth)
//{
//    for(int a = 0;a < List_plg.length();a++){
//        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
//        PluginFuns::CodeEditorFunPtr_Create = createPth;
//        PluginFuns::CodeEditorFunPtr_AddkeyWord = addWordPth;
//        PluginFuns::CodeEditorFunPtr_GetCode = getStrPth;
//        PluginFuns::CodeEditorFunPtr_AddStr = addStrPth;
//    }
//}




//设置工具栏内控件的启用与关闭,添加工具栏
void Plugin_Manger::workSpace_init_toolBarFuns(PluginGlobalMsg::toolBar_action_setEnable toolBar_setActionEnableFunPtr,PluginGlobalMsg::fun_void toolBar_clearAllActionFunPtr,PluginGlobalMsg::toolBarFun toolBar_addToolBarFunPtr)
{
    PluginFuns::WorkSpace_ToolBar_setActionEnable = toolBar_setActionEnableFunPtr;
    PluginFuns::WorkSpace_ToolBar_closeAllAction = toolBar_clearAllActionFunPtr;
    PluginFuns::WorkSpace_ToolBar_addToolBar = toolBar_addToolBarFunPtr;
}





//初始化提示输出接口
void Plugin_Manger::workSpace_init_tipPrint(PluginGlobalMsg::printFun_printList fun_printList,
                                            PluginGlobalMsg::printFun_printTextSpace fun_printText,
                                            PluginGlobalMsg::printFun_printTextSpace fun_printTextLine,
                                            PluginGlobalMsg::printFun_clear fun_clearPrintList,
                                            PluginGlobalMsg::printFun_clear fun_clearTextSpace)
{
    PluginFuns::WorkSpace_PrintOut_List = fun_printList;
    PluginFuns::WorkSpace_PrintOut_TextSpace_Print = fun_printText;
    PluginFuns::WorkSpace_PrintOut_TextSpace_PrintLine = fun_printTextLine;
    PluginFuns::WorkSpace_PrintOut_List_Clear = fun_clearPrintList;
    PluginFuns::WorkSpace_PrintOut_TextSpace_Clear = fun_clearTextSpace;
}




//插件接口绑定
void Plugin_Manger::pluginManger_init_building()
{
    PluginFuns::PluginManger_PostMsg = [this](QString selfSign,QString pluginSign,QString pustMsg)->QString{
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


//浮动窗格绑定
void Plugin_Manger::workSpace_init_dockWidget(PluginGlobalMsg::dockWidgetFun_add addFun,PluginGlobalMsg::dockWidgetFun_rm rmFun)
{
    PluginFuns::WorkSpace_DockWidget_Add = addFun;
    PluginFuns::WorkSpace_DockWidget_remove = rmFun;
}




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
void Plugin_Manger::event_onCompileTypeChanged(PluginGlobalMsg::generateType type)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].plgPth->event_onCompileTypeChanged(type) == false){ //若插件阻止触发，则跳出
            break;
        }
    }
}

//当文件被打开，激发模块事件
void Plugin_Manger::event_onFileOpen(QString filePath)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].plgPth->event_onFileOpen(filePath) == false){ //若插件阻止触发，则跳出
            break;
        }
    }
}

//当前文件已经被打开，所有的文件被打开都会激发模块事件
void Plugin_Manger::event_onFileOpenFinish(QString filePath)
{
    for(int a = 0;a < List_plg.length();a++){
        if(List_plg[a].plgPth == nullptr){continue;} //如果插件未载入，则不操作
        if(List_plg[a].plgPth->event_onFileOpenFinish(filePath) == false){ //若插件阻止触发，则跳出
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
        if(List_plg[a].plgPth->event_onPorjectLoad(proPath,proLangs,proNoteClass) == false){ //若插件阻止触发，则跳出
            break;
        }
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



