#include "Plugin_Funs.h"



//工作空间菜单接口，工作空间加载完毕后所有指针都将刷新为可用
PluginGlobalMsg::menuFun PluginFuns::WorkSpace_AddMenu_ToolBar_Tool = nullptr; //添加菜单到工具栏
PluginGlobalMsg::menuFun PluginFuns::WorkSpace_AddMenu_ToolBar_Setting = nullptr; //添加菜单到设置
PluginGlobalMsg::menuFun PluginFuns::WorkSpace_AddMenu_ToolBar_Helps = nullptr; //添加菜单到帮助
PluginGlobalMsg::menuFun PluginFuns::WorkSpace_AddMenu_ToolBar_View = nullptr; //添加菜单到试图
PluginGlobalMsg::menuFun PluginFuns::WorkSpace_AddMenu_ToolBar_Extend = nullptr; //添加菜单到拓展
PluginGlobalMsg::menuFun PluginFuns::WorkSpace_AddMenu_ToolBar_Compile = nullptr; //添加菜单到生成
PluginGlobalMsg::menuFun PluginFuns::WorkSpace_AddMenu_ToolBar_DataBase = nullptr; //添加菜单到数据库
PluginGlobalMsg::menuFun PluginFuns::WorkSpace_AddMenu_ToolBar_Insert = nullptr; //添加菜单到插入
PluginGlobalMsg::menuFun PluginFuns::WorkSpace_AddMenu_ToolBar_File = nullptr; //添加菜单到打开文件

PluginGlobalMsg::menuFun PluginFuns::WorkSpace_AddMenu_ProManger_Project = nullptr;//添加菜单到工程
PluginGlobalMsg::menuFun PluginFuns::WorkSpace_AddMenu_ProManger_NewFile = nullptr;//添加菜单到新建文件
PluginGlobalMsg::menuFun PluginFuns::WorkSpace_AddMenu_ProManger_ProNormal = nullptr;//添加菜单到工程普通文件菜单
//PluginGlobalMsg::menuFun PluginFuns::WorkSpace_Mneu_UnityStyle_SelectAction = nullptr; //设置菜单选择Action的样式，在initPlugin方法里面就完成初始化


//设置ACtion的启用
PluginGlobalMsg::toolBar_action_setEnable PluginFuns::WorkSpace_ToolBar_setActionEnable = nullptr; //设置ToolBar的Action启动禁止
PluginGlobalMsg::fun_void PluginFuns::WorkSpace_ToolBar_closeAllAction = nullptr; //关闭所有的toolbar的Action
PluginGlobalMsg::toolBarFun PluginFuns::WorkSpace_ToolBar_addToolBar = nullptr; //添加ToolBar到WorkSpace


//设置打印接口
PluginGlobalMsg::printFun_printList PluginFuns::WorkSpace_PrintOut_List = nullptr; //在通知列表输出信息
PluginGlobalMsg::printFun_clear PluginFuns::WorkSpace_PrintOut_List_Clear = nullptr;  //清理当前列表
PluginGlobalMsg::printFun_printTextSpace PluginFuns::WorkSpace_PrintOut_TextSpace_Print = nullptr; //输出单个文本不换行
PluginGlobalMsg::printFun_printTextSpace PluginFuns::WorkSpace_PrintOut_TextSpace_PrintLine = nullptr;//输出一行文本
PluginGlobalMsg::printFun_clear PluginFuns::WorkSpace_PrintOut_TextSpace_Clear = nullptr; //清空文本输出

//选项卡添加窗口接口
PluginGlobalMsg::addTabViewPth PluginFuns::WorkSpace_addTabWindow = nullptr; //添加窗口到Tab

//插件消息投递
PluginGlobalMsg::pluginFun_post PluginFuns::PluginManger_PostMsg = nullptr; //使用插件管理器投递信息，每一个有效插件都将接收到收到这个信息，但是需要注意发送方的身份


//获取WorkSpace窗口指针
PluginGlobalMsg::dockWidgetFun_add PluginFuns::WorkSpace_DockWidget_Add = nullptr; //添加DockWidget
PluginGlobalMsg::dockWidgetFun_rm PluginFuns::WorkSpace_DockWidget_remove = nullptr; //删除DockWidget
