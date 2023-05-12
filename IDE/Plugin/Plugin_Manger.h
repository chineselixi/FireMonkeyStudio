
#ifndef PLUGIN_MANGER_H
#define PLUGIN_MANGER_H

#include "QLibrary"
#include "Plugin/Plugin_Base.h"

class Plugin_Manger
{
public:
    Plugin_Manger();
    ~Plugin_Manger();

    //插件信息
    struct PluginMsg{
        QString filePath = ""; //插件文件名
        Plugin_Base* plgPth = nullptr; //插件对象指针，禁止或未加载的指针是nullptr
        QLibrary* qLibPth = nullptr;
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

//    bool enablePlugin(QString filePath); //启用插件
//    bool disablePlugin(QString filePath); //禁用插件


    //初始化菜单

    void workSpace_init_Menu(PluginGlobalMsg::menuFun toolBar_tool,PluginGlobalMsg::menuFun toolBar_set,PluginGlobalMsg::menuFun toolBar_help,PluginGlobalMsg::menuFun toolBar_view,
                            PluginGlobalMsg::menuFun toolBar_extend,PluginGlobalMsg::menuFun toolBar_db,PluginGlobalMsg::menuFun toolBar_comple,PluginGlobalMsg::menuFun toolBar_insert,PluginGlobalMsg::menuFun toolBar_file,
                            PluginGlobalMsg::menuFun ProManger_project,PluginGlobalMsg::menuFun ProManger_newFile,PluginGlobalMsg::menuFun ProManger_proNormal); //workSpace添加插件菜单
    void workSpace_init_tabView(PluginGlobalMsg::addTabViewPth pth);//添加workSpace的tabView接口
    void workSpace_init_codeEditor(PluginGlobalMsg::editorFun_create createPth,PluginGlobalMsg::editorFun_addKetWord addWordPth,
                                   PluginGlobalMsg::editorFun_getStr getStrPth,PluginGlobalMsg::editorFun_addStr addStrPth); //添加workSpace的代码编辑器接口
    void workSpace_init_actionEnable(PluginGlobalMsg::workSpace_Action_setEnableFun enableFun); //初始化设置action的启用接口

    void pluginManger_init_building(); //插件接口绑定



public:

    void event_onModLoadFinish();//当模块加载完毕，将第一时间激发模块事件
    void event_onCompileTypeChanged(PluginGlobalMsg::compileType type); //当编译模式被改变激发模块事件
    void event_onFileOpen(QString filePath); //当文件被打开，激发模块事件
    void event_onFileOpenFinish(QString filePath); //当前文件已经被打开，所有的文件被打开都会激发模块事件
    void event_onFileClose(QString filePath); //当文件被删除或者关闭
    void event_onPorjectLoad(QString proPath,QString proLangs,QString proNoteClass); //当工程被加载完毕，或者切换的工程已经被改变

    void event_onWorkSpaceFinish(); //工作空间创建完毕事件，此事件不可阻止，，但是可以阻塞，将为每一个插件提供事件响应
    void event_onWorkSpaceClose();  //工作空间正在被关闭，不可被阻止，但是可以阻塞，将为每一个插件提供事件响应

    void event_onRunDown(QString proPath,QString proLangs,QString proNoteClass); //当运行按钮被按下
    void event_onStopDown(QString proPath,QString proLangs,QString proNoteClass); //当通知按钮被按下
};








#endif // PLUGIN_MANGER_H
