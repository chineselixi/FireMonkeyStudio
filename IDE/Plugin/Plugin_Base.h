
#ifndef PLUGIN_BASE_H
#define PLUGIN_BASE_H

#include "Plugin_Global.h"
//#include "../../QScintilla/src/Qsci/qsciscintilla.h"

//class QMainWindow; //声明QMainWindow
class Form_settings_Basic;


class Plugin_Base
{
public:
    friend class Plugin_Manger;
    //friend class Form_WorkSpace;


    struct libMsg{
        QString name = "NULL";         //支持库信息
        QString version = "1.0.0.1";  //支持库显示版本
        int versionNumber = 1; //支持库数字版本
        QString sign = ""; //插件标记，插件之间的通信需要的标记。注意，插件的标记可以相同，管理器将通过这些标记进行数据传输
        QString note = "Plugin for FireMonkey Studio";
        QString loadTip = "";//加载时输出的文字信息，可以作为加载成功的提示
        uint16_t level = 0; //排序级别范围：0-65535，默认为最低级别，相同的级别系统将随机分配，自定义插件建议高于0
    };

    //设置组件信息
    struct settingWidgetMsg{
        QString title = QAction::tr("new setting");
        QPixmap ico_32px;
        Form_settings_Basic* settingWidget = nullptr;
    };


public:
    typedef QList<settingWidgetMsg> settingMsgList;

protected:
    libMsg self_BaseMsg;


private:
    //工作空间菜单接口，工作空间加载完毕后所有指针都将刷新为可用
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Tool = nullptr; //添加菜单到工具栏
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Setting = nullptr; //添加菜单到设置
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Helps = nullptr; //添加菜单到帮助
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_View = nullptr; //添加菜单到试图
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Extend = nullptr; //添加菜单到拓展
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Compile = nullptr; //添加菜单到生成
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_DataBase = nullptr; //添加菜单到数据库
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_Insert = nullptr; //添加菜单到插入
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ToolBar_File = nullptr; //添加菜单到打开文件

    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ProManger_Project = nullptr;//添加菜单到工程
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ProManger_NewFile = nullptr;//添加菜单到新建文件
    PluginGlobalMsg::menuFun WorkSpace_AddMenu_ProManger_ProNormal = nullptr;//添加菜单到工程普通文件菜单
    //PluginGlobalMsg::menuFun WorkSpace_Mneu_UnityStyle_SelectAction = nullptr; //设置菜单选择Action的样式，在initPlugin方法里面就完成初始化

    //设置ACtion的启用
    PluginGlobalMsg::toolBar_action_setEnable WorkSpace_ToolBar_setActionEnable = nullptr; //设置ToolBar的Action启动禁止
    PluginGlobalMsg::fun_void WorkSpace_ToolBar_closeAllAction = nullptr; //关闭所有的toolbar的Action
    PluginGlobalMsg::toolBarFun WorkSpace_ToolBar_addToolBar = nullptr; //添加ToolBar到WorkSpace

    //设置打印接口
    PluginGlobalMsg::printFun_printList WorkSpace_PrintOut_List = nullptr; //在通知列表输出信息
    PluginGlobalMsg::printFun_clear WorkSpace_PrintOut_List_Clear = nullptr;  //清理当前列表
    PluginGlobalMsg::printFun_printTextSpace WorkSpace_PrintOut_TextSpace_Print = nullptr; //输出单个文本不换行
    PluginGlobalMsg::printFun_printTextSpace WorkSpace_PrintOut_TextSpace_PrintLine = nullptr;//输出一行文本
    PluginGlobalMsg::printFun_clear WorkSpace_PrintOut_TextSpace_Clear = nullptr; //清空文本输出

    //选项卡添加窗口接口
    PluginGlobalMsg::addTabViewPth WorkSpace_addTabWindow = nullptr; //添加窗口到Tab

    //插件消息投递
    PluginGlobalMsg::pluginFun_post PluginManger_PostMsg = nullptr; //使用插件管理器投递信息，每一个有效插件都将接收到收到这个信息，但是需要注意发送方的身份

    //获取WorkSpace窗口指针
    PluginGlobalMsg::dockWidgetFun_add WorkSpace_DockWidget_Add = nullptr; //添加DockWidget
    PluginGlobalMsg::dockWidgetFun_rm WorkSpace_DockWidget_remove = nullptr; //删除DockWidget


public:
    //初始化信息，由IDE侧载，可复写
    virtual libMsg getBaseMsg(){return self_BaseMsg;}; //获取基础的类信息


public: //插件的基础方法
    void addToolBarMenu(PluginGlobalMsg::toolBarMenuType menuType,QAction* action); //添加菜单到工具栏菜单
    void addProMangerMenu(PluginGlobalMsg::proMangerMenuType menuType,QAction* action); //添加菜单到项目管理器
    void setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction actionType,bool isEnable); //设置工作空间Action启用
    void closeWorkSpaceAllAction(); //关闭所有的工作控件子菜单
    void addToolBarToWs(QToolBar* toolBar); //添加工具栏到工作空间
    void printList(QString code, QString text,QString project,QString file,int row,PluginGlobalMsg::printIcoType type,QColor textColor); //在列表输出中输出一行文本
    void clearList(); //清理行的所有行文本
    void printTextSpace(QColor color,QString printText); //在文本窗口输出文本
    void printTextSpaceLine(QColor color,QString printText); //在文本窗口输出文本
    void clearTextSpace(); //清理文本窗口所有的文本
    void addTabWindow(QString title, QWidget *form, QString sign, QIcon titeIco,PluginGlobalMsg::TabType type); //在Tab添加窗口
    QString postPluginMessage(QString pluginSign,QString pustMsg); //插件内投递消息
    void addDockWidget(Qt::DockWidgetArea area,QDockWidget* dockWidget); //添加DockWidget
    void removeDockWidget(QDockWidget* dockWidget); //移除DockWidget


public: //(可阻拦事件)事件触发，返回true则继续触发其他插件的同类型时间，返回false则阻止触发其他插件
    virtual bool event_onModLoadFinish(){return true;};//当模块加载完毕，将第一时间激发此插件，禁止在获取实例处获得
    virtual bool event_onCompileTypeChanged(PluginGlobalMsg::generateType type){return true;}; //当编译模式被改变
    virtual bool event_onFileOpen(QString filePath){return true;}; //当文件被打开，注意：仅限于IDE无法打开之外的文件才激发此事件
    virtual bool event_onFileOpenFinish(QString filePath){return true;}; //当前文件已经被打开，所有的文件被打开都会激发此事件
    virtual bool event_onFileClose(QString filePath){return true;}; //当前文件被删除或者关闭之前就发送的信息
    virtual bool event_onFileSave(QString filePath){return true;}; //当文件被保存激发事件
    virtual bool event_onFileSaveAll(){return true;}; //当全部保存被激发
    virtual bool event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction actionType, QString proPath,QString proLangs,QString proNoteClass){return true;};//当工具栏内部按钮被按下(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)
    virtual bool event_onPorjectLoad(QString proPath,QString proLangs,QString proNoteClass){return true;}; //当工程被加载完毕(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)


public: //(不可阻拦事件)事件触发，将激发每一个插件的事件
    virtual void event_onWorkSpaceFinish(){return;}; //工作空间创建完毕事件，此事件不可阻止，，但是可以阻塞，将为每一个插件提供事件响应
    virtual void event_onWorkSpaceClose(){return;};  //工作空间正在被关闭，不可被阻止，但是可以阻塞，将为每一个插件提供事件响应
    virtual void event_onLoadSettingsWidget(settingMsgList& msgList){return;}; //当加载设置组件的时候


public: //专有事件，仅仅通知注册需要的插件
    virtual void event_onLoading(){return;}; //初次加载事件，插件被成功加载完成以后第一次通知的事件，注意：此时其他插件可能并没有加载完成
    virtual void event_onTabFormActivation(QWidget* form){return;}; //当Tab内嵌窗口被选中，被激活时，将会激发此选项
    virtual bool event_onTabFormCloseRequested(QWidget* form){return true;}; //当Tab内嵌窗口即将选择被关闭，但是还未关闭，将激发此选项，返回true则允许关闭，false则阻止关闭


public:
    //插件管理器接口
    virtual QString event_onPluginReceive(QString sendPluginSign,QString msg){return "";}; //参数（发送者标记，发送信息），返回值（当返回的信息不是空则第一时间返回），当插件接收到发送的信息

};
#endif // PLUGIN_BASE_H
