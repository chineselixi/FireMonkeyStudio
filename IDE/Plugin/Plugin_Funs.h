#ifndef PLUGIN_FUNS_H
#define PLUGIN_FUNS_H

#include "Plugin_Global.h"


namespace PluginFuns{

//工作空间菜单接口，工作空间加载完毕后所有指针都将刷新为可用
extern PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Tool; //添加菜单到工具栏
extern PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Setting; //添加菜单到设置
extern PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Helps; //添加菜单到帮助
extern PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_View; //添加菜单到试图
extern PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Extend; //添加菜单到拓展
extern PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Compile; //添加菜单到生成
extern PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_DataBase; //添加菜单到数据库
extern PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Insert; //添加菜单到插入
extern PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_File; //添加菜单到打开文件

extern PluginGlobalMsg::menuFun WorkSpace_AddMenu_ProManger_Project;//添加菜单到工程
extern PluginGlobalMsg::menuFun WorkSpace_AddMenu_ProManger_NewFile;//添加菜单到新建文件
extern PluginGlobalMsg::menuFun WorkSpace_AddMenu_ProManger_ProNormal;//添加菜单到工程普通文件菜单
//PluginGlobalMsg::menuFun WorkSpace_Mneu_UnityStyle_SelectAction; //设置菜单选择Action的样式，在initPlugin方法里面就完成初始化


//设置ACtion的启用
extern PluginGlobalMsg::toolBar_action_setEnable WorkSpace_ToolBar_setActionEnable; //设置ToolBar的Action启动禁止
extern PluginGlobalMsg::fun_void WorkSpace_ToolBar_closeAllAction; //关闭所有的toolbar的Action
extern PluginGlobalMsg::toolBarFun WorkSpace_ToolBar_addToolBar; //添加ToolBar到WorkSpace



//设置打印接口
extern PluginGlobalMsg::printFun_printList WorkSpace_PrintOut_List; //在通知列表输出信息
extern PluginGlobalMsg::printFun_clear WorkSpace_PrintOut_List_Clear;  //清理当前列表
extern PluginGlobalMsg::printFun_printTextSpace WorkSpace_PrintOut_TextSpace_Print; //输出单个文本不换行
extern PluginGlobalMsg::printFun_printTextSpace WorkSpace_PrintOut_TextSpace_PrintLine;//输出一行文本
extern PluginGlobalMsg::printFun_clear WorkSpace_PrintOut_TextSpace_Clear; //清空文本输出


//选项卡添加窗口接口
extern PluginGlobalMsg::addTabViewPth WorkSpace_addTabWindow; //添加窗口到Tab


//设置

//    //代码编辑器
//    extern PluginGlobalMsg::editorFun_create CodeEditorFunPtr_Create; //创建代码编辑器
//    extern PluginGlobalMsg::editorFun_addKetWord CodeEditorFunPtr_AddkeyWord;//添加关键字，0为关键字1，1为关键字2
//    extern PluginGlobalMsg::editorFun_getStr CodeEditorFunPtr_GetCode;//获取代码编辑器文本
//    extern PluginGlobalMsg::editorFun_addStr CodeEditorFunPtr_AddStr; //编辑器插入文本


//插件消息投递
extern PluginGlobalMsg::pluginFun_post PluginManger_PostMsg; //使用插件管理器投递信息，每一个有效插件都将接收到收到这个信息，但是需要注意发送方的身份


//获取WorkSpace窗口指针
extern PluginGlobalMsg::dockWidgetFun_add WorkSpace_DockWidget_Add; //添加DockWidget
extern PluginGlobalMsg::dockWidgetFun_rm WorkSpace_DockWidget_remove; //删除DockWidget


}





#endif // PLUGIN_FUNS_H
