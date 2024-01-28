
#ifndef PLUGIN_MANGER_H
#define PLUGIN_MANGER_H

#include "QLibrary"
#include "Plugin_Base.h"

class Plugin_Manger
{
public:
    Plugin_Manger();
    ~Plugin_Manger();

    //插件信息
    struct PluginMsg{
        QString filePath = ""; //插件文件名
        Plugin_Base* plgPth = nullptr; //插件对象指针，禁止或未加载的指针是nullptr
        QLibrary* qLibPth  = nullptr;   //插件加载器指针
    };

    //菜单信息
    struct actionMsg{
        QString pluginFilePath = ""; //插件文件路径
        QAction* menuAction = nullptr; //菜单对象
    };



protected:
    QVector<PluginMsg> List_plg;  //插件列表信息



//    //工具栏预备列表
//    QVector<actionMsg> menuList_ToolBar_Tool; //添加菜单到工具栏列表
//    QVector<actionMsg> menuList_ToolBar_Setting; //添加菜单到设置列表
//    QVector<actionMsg> menuList_ToolBar_Helps; //添加菜单到帮助列表
//    QVector<actionMsg> menuList_ToolBar_View; //添加菜单到试图列表
//    QVector<actionMsg> menuList_ToolBar_Add; //添加菜单到拓展列表
//    QVector<actionMsg> menuList_ToolBar_Compile; //添加菜单到生成列表
//    QVector<actionMsg> menuList_ToolBar_DataBase; //添加菜单到数据库列表
//    QVector<actionMsg> menuList_ToolBar_Insert; //添加菜单到插入列表
//    QVector<actionMsg> menuList_ToolBar_File; //添加菜单到打开文件列表

//    QVector<actionMsg> menuList_ProManger_Project;//添加菜单到工程列表
//    QVector<actionMsg> menuList_ProManger_NewFile;//添加菜单到新建文件列表
//    QVector<actionMsg> menuList_ProManger_ProNormal;//添加菜单到工程普通文件菜单列表






private:
    void findPlugin(QString path,QVector<QString>& retFiles,QString plgSuffix = "plg"); //查找寻找插件文件


public:
    void initPlugin(QString dirPath,QString plgSuffix = "plg");//根据目录扫描并且添加插件对象
    QVector<PluginMsg> getPluginList(); //获取插件列表信息
    Plugin_Base::libMsg getPluginMsg(QString filePath); //根据文件名获取插件信息
    Plugin_Base::settingMsgList getSettingWidgets(); //获取设置组件列表


    //初始化菜单
    void workSpace_init_Menu(PluginGlobalMsg::menuFun toolBar_tool,PluginGlobalMsg::menuFun toolBar_set,PluginGlobalMsg::menuFun toolBar_help,PluginGlobalMsg::menuFun toolBar_view,
                            PluginGlobalMsg::menuFun toolBar_extend,PluginGlobalMsg::menuFun toolBar_db,PluginGlobalMsg::menuFun toolBar_comple,PluginGlobalMsg::menuFun toolBar_insert,PluginGlobalMsg::menuFun toolBar_file,
                            PluginGlobalMsg::menuFun ProManger_project,PluginGlobalMsg::menuFun ProManger_proNormal); //workSpace添加插件菜单
    void TabSpace_init_tabView(PluginGlobalMsg::addTabViewPth addTabFun,
                                PluginGlobalMsg::tab_getSign getSignFun,PluginGlobalMsg::tab_getWidget getWidgetFun,
                                PluginGlobalMsg::tab_hasTab_Sign hasSignFun,PluginGlobalMsg::tab_hasTab_WidgetPtr hasWidgtFun);//添加workSpace的tabView接口
//    void workSpace_init_codeEditor(PluginGlobalMsg::editorFun_create createPth,PluginGlobalMsg::editorFun_addKetWord addWordPth,
//                                   PluginGlobalMsg::editorFun_getStr getStrPth,PluginGlobalMsg::editorFun_addStr addStrPth); //添加workSpace的代码编辑器接口
    void workSpace_init_toolBarFuns(PluginGlobalMsg::toolBar_action_setEnable toolBar_setActionEnableFunPtr,PluginGlobalMsg::fun_void toolBar_clearAllActionFunPtr,PluginGlobalMsg::toolBarFun toolBar_addToolBarFunPtr); //设置工具栏内控件的启用与关闭,添加工具栏

    //void workSpace_init_toolBarBind();//将工具栏按钮与菜单绑定，按下与禁用时间绑定


    void workSpace_init_tipPrint(PluginGlobalMsg::printFun_printList fun_printList,PluginGlobalMsg::printFun_printTextSpace fun_printText,
                                 PluginGlobalMsg::printFun_printTextSpace fun_printTextLine,PluginGlobalMsg::printFun_clear fun_clearPrintList,
                                 PluginGlobalMsg::printFun_clear fun_clearTextSpace); //初始化提示输出接口

    //void workSpace_init_dockWidget(PluginGlobalMsg::dockWidgetFun_add addFun,PluginGlobalMsg::dockWidgetFun_rm rmFun); //浮动窗格绑定

    void pluginManger_init_building(); //插件接口绑定

    void setting_init_building(); //设置接口绑定

    void themeChanged_init_building(); //主题操作绑定

    void projectManger_init_building(PluginGlobalMsg::projectManger_getProMsgBase ProjectManger_getBaseFun, //工程管理器获取基础信息
                                     PluginGlobalMsg::projectManger_addBuildFileSign ProjectManger_addBuildSignFun, //添加新建工程文档
                                     PluginGlobalMsg::projectManger_delBuildFileSign ProjectManger_delBuildSignFun, //删除创建文件标记
                                     PluginGlobalMsg::projectManger_addFileIco ProjectManger_addFileIcoFun, //添加类别文件图标
                                     PluginGlobalMsg::projectManger_setObjIco ProjectManger_setObjIcoFun); //设置目标图标，如果目标为空，则设置类型为non的图标

    void workSpace_init_compileMod(PluginGlobalMsg::compileMod_changeFun addFun, //添加编译模式
                                   PluginGlobalMsg::compileMod_changeFun delFun, //删除编译模式
                                   PluginGlobalMsg::compileMod_changeFun selectFun, //选择编译模式
                                   PluginGlobalMsg::fun_void clsFun,    //清空编译模式
                                   PluginGlobalMsg::fun_str getNowFun); //获取当前模式，  //初始化编译模式接口

    void workSpace_init_tipsManger(PluginGlobalMsg::tipFun_postStr tipsFun_addPost, //投递字符串到状态栏
                                   PluginGlobalMsg::tipFun_addTip tipsFun_addTip, //添加一个消息到通知管理器中
                                   PluginGlobalMsg::tipFun_closeTip tipsFun_closeTip, //添加一个消息到通知管理器中
                                   PluginGlobalMsg::tipFun_hasTip tipsFun_hasTip, //判断消息是否存在
                                   PluginGlobalMsg::tipFun_setTipTitle tipsFun_setTitle, //设置提示标题
                                   PluginGlobalMsg::tipFun_setTipText tipsFun_setText, //设置提示文本
                                   PluginGlobalMsg::tipFun_setTipType tipsFun_setType, //设置提示类型
                                   PluginGlobalMsg::tipFun_setTipPixmap tipsFun_setPix, //设置提示图片
                                   PluginGlobalMsg::tipFun_setTipCanClose tipsFun_setCanClose, //设置提示能够关闭
                                   PluginGlobalMsg::tipFun_setTipShowTime  tipsFun_changeShowTime //设置提示时间
                                   ); //初始化通知管理器

    void workSpace_init_statusOperate(PluginGlobalMsg::statusbarFun_setProgressIndex statusFun_changedProgressIndex, //设置状态栏进度条进度
                                      PluginGlobalMsg::statusbarFun_setButton statusFun_setBtn, //设置状态栏按钮，funPtr为nullptr时，隐藏
                                      PluginGlobalMsg::statusbarFun_hideAllBtn statusFun_hideAllBtn //隐藏所有的按钮
                                      ); //初始化状态栏操作接口

    void workSpace_init_widget(PluginGlobalMsg::widgetFun_getWidget widget_getMainWindow); //初始化控件

public:

    void event_onModLoadFinish();//当模块加载完毕，将第一时间激发模块事件
    void event_onCompileTypeChanged(QString typeSign); //当编译模式被改变激发模块事件


    void event_onPorjectLoad(QString proPath,QString proLangs,QString proNoteClass); //当工程被加载完毕，或者切换的工程已经被改变
    void event_onProjectBuild(QString projectPath); //工程被构建
    void event_onProjectClear(QString projectPath); //工程被清理

    void event_onFileOpen(QString filePath); //当文件被打开，激发模块事件
    void event_onFileClose(QString filePath); //当文件被删除或者关闭
    void event_onFileRename(QString oldPath, QString newPath); //当文件路径被改变

    void event_onFileSave(QString filePath); //当文件被保存
    void event_onFileSaveAll(); //当文件全部保存

    void event_onThemeChanged(QString themeSign); //当主题标记被改变

    void event_onWorkSpaceFinish(); //工作空间创建完毕事件，此事件不可阻止，，但是可以阻塞，将为每一个插件提供事件响应
    void event_onWorkSpaceClose();  //工作空间正在被关闭，不可被阻止，但是可以阻塞，将为每一个插件提供事件响应

    void event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction actionType, QString proPath,QString proLangs,QString proNoteClass); //当工具栏的Action被触发
};








#endif // PLUGIN_MANGER_H
