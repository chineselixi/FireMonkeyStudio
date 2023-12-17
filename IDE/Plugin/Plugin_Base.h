
#ifndef PLUGIN_BASE_H
#define PLUGIN_BASE_H

#include "Plugin_Global.h"
#include "../module/mod_settingsFormBase.h"
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
        QWidget* settingWidget = nullptr;
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


    //操作编译模式
    PluginGlobalMsg::compileMod_changeFun WorkSpace_CompileMod_Add = nullptr; //添加编译模式
    PluginGlobalMsg::compileMod_changeFun WorkSpace_CompileMod_Del = nullptr; //删除编译模式
    PluginGlobalMsg::compileMod_changeFun WorkSpace_CompileMod_Sel = nullptr; //选择编译模式
    PluginGlobalMsg::fun_void WorkSpace_CompileMod_Cls = nullptr; //删除全部编译模式
    PluginGlobalMsg::fun_str WorkSpace_CompileMod_GetNow = nullptr; //获取当前编译模式

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

    //选项卡TAB添加窗口接口
    PluginGlobalMsg::addTabViewPth TabSpace_addTabWindow = nullptr; //添加窗口到Tab
    PluginGlobalMsg::tab_hasTab_Sign TabSpace_hasTab_Sign = nullptr; //根据sign判断是否存在Tab
    PluginGlobalMsg::tab_hasTab_WidgetPtr TabSpace_hasTab_WidgetPtr = nullptr; //根据widget指针判断是否存在Tab
    PluginGlobalMsg::tab_getSign TabSpace_getTabSign = nullptr; //根据Widget获取sign
    PluginGlobalMsg::tab_getWidget TabSpace_getTabSWidget = nullptr; //根据sign获取widget

    //主题获取
    PluginGlobalMsg::theme_setFunPtr Theme_set = nullptr; //主题设置
    PluginGlobalMsg::theme_getFunPtr Theme_get = nullptr; //主题获取
    //插件消息投递
    PluginGlobalMsg::pluginFun_post PluginManger_PostMsg = nullptr; //使用插件管理器投递信息，每一个有效插件都将接收到收到这个信息，但是需要注意发送方的身份

    //WorkSpace中的Dock操作
    PluginGlobalMsg::dockWidgetFun_add WorkSpace_DockWidget_Add = nullptr; //添加DockWidget
    PluginGlobalMsg::dockWidgetFun_rm WorkSpace_DockWidget_remove = nullptr; //删除DockWidget

    //设置操作接口
    PluginGlobalMsg::setPtr_addFun setFun_add = nullptr; //添加或变更一个设置
    PluginGlobalMsg::setPtr_getFun setFun_get = nullptr; //获取一个设置信息
    PluginGlobalMsg::setPtr_deleteFun setFun_del = nullptr; //删除一个设置信息

    //通知提示管理器（也在状态栏实现）
    PluginGlobalMsg::funStr_void WorkSpace_postMsg = nullptr; //在状态栏左下角显示一个信息

    //状态栏功能
    PluginGlobalMsg::tipFun_postStr tipsFun_addPost = nullptr; //投递字符串到状态栏
    PluginGlobalMsg::tipFun_addTip tipsFun_addTip = nullptr; //添加一个消息到通知管理器中
    PluginGlobalMsg::tipFun_hasTip tipsFun_hasTip = nullptr; //判断消息是否存在
    PluginGlobalMsg::tipFun_setTipTitle tipsFun_setTitle = nullptr; //设置提示标题
    PluginGlobalMsg::tipFun_setTipText tipsFun_setText = nullptr; //设置提示文本
    PluginGlobalMsg::tipFun_setTipType tipsFun_setType = nullptr; //设置提示类型
    PluginGlobalMsg::tipFun_setTipPixmap tipsFun_setPix = nullptr; //设置提示图片
    PluginGlobalMsg::tipFun_setTipCanClose tipsFun_setCanClose = nullptr; //设置提示能够关闭
    PluginGlobalMsg::tipFun_setTipShowTime  tipsFun_changeShowTime = nullptr; //设置提示时间

    //状态栏输出通知，和状态栏按钮操作
    PluginGlobalMsg::statusbarFun_setProgressIndex statusFun_changedProgressIndex = nullptr; //设置状态栏进度条进度
    PluginGlobalMsg::statusbarFun_setButton statusFun_setBtn = nullptr; //设置状态栏按钮，funPtr为nullptr时，隐藏
    PluginGlobalMsg::statusbarFun_hideAllBtn statusFun_hideAllBtn = nullptr; //隐藏所有的按钮




    //插件管理器
    PluginGlobalMsg::projectManger_getProMsgBase ProjectManger_getBase = nullptr; //插件管理器获取基础信息

public:
    //初始化信息，由IDE侧载，可复写
    virtual libMsg getBaseMsg(){return self_BaseMsg;}; //获取基础的类信息


public: //插件的基础方法
    void addToolBarMenu(PluginGlobalMsg::toolBarMenuType menuType,QAction* action); //添加菜单到工具栏菜单
    void addProMangerMenu(PluginGlobalMsg::proMangerMenuType menuType,QAction* action); //添加菜单到项目管理器
    void setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction actionType,bool isEnable); //设置工作空间Action启用
    void closeWorkSpaceAllAction(); //关闭所有的工作控件子菜单
    void addToolBarToWs(QToolBar* toolBar); //添加工具栏到工作空间

    QString getThemeSign();                //获取主题标记
    void setThemeSign(QString sign);       //设置主题标记

    void addCompileMod(QString signName); //添加编译模式
    void delCompileMod(QString signName); //删除编译模式
    void selectCompileMod(QString signName); //选择编译模式
    void clearAllCompileMod(); //清空所有编译模式
    QString getCompileModSignName(); //获取当前编译模式标记名称

    void printList(QString code, QString text,QString project,QString file,int row,PluginGlobalMsg::printIcoType type,QColor textColor); //在列表输出中输出一行文本
    void clearList(); //清理行的所有行文本
    void printTextSpace(QColor color,QString printText); //在文本窗口输出文本
    void printTextSpaceLine(QColor color,QString printText); //在文本窗口输出文本
    void clearTextSpace(); //清理文本窗口所有的文本

    QString postPluginMessage(QString pluginSign,QString pustMsg); //插件内投递消息
    void addDockWidget(Qt::DockWidgetArea area,QDockWidget* dockWidget); //添加DockWidget
    void removeDockWidget(QDockWidget* dockWidget); //移除DockWidget

    void addTabWindow(QString title, QWidget *form, QString sign, QIcon titeIco,PluginGlobalMsg::TabType type); //在Tab添加窗口
    bool hasTab(QString sign,bool select); //根据sign标记查找是否存在Tab，如果存在，是否选择。此方法可由于查找和选择
    bool hasTab(QWidget* widget,bool select); //根据QWidget指针查找是否存在Tab，如果存在，是否选择。此方法可由于查找和选择
    QWidget* getTabWidget(QString sign); //根据sign获取Widget指针
    QString getTabSign(QWidget* widget); //根据widget指针获取sign信息

    void addMark(QString mark,QString value); //添加一个设置标记
    QVariant getMark(QString mark,QString normal=""); //获取一个设置标记内容
    void delMark(QString mark);//删除设置一个标记


    void postTipStr(QString str,int showTime); //投递字符串到状态栏
    uint16_t addTip(QString title, QString tip, PluginGlobalMsg::TipType type, QPixmap pixmap, bool canClose, qint64 showTime); //添加通知到通知管理器中
    bool hasTip(uint16_t index); //判断是否存在这个通知
    void setTipTitle(uint16_t index, QString title);//设置提示标题
    void setTipText(uint16_t index, QString text);//设置提示文本
    void setTipType(uint16_t index, PluginGlobalMsg::TipType type); //设置提示类型
    void setTipPixmap(uint16_t index, QPixmap pixmap); //设置提示图片
    void setCanClose(uint16_t index, bool canClose); //设置提示能够关闭
    void setTipShowTime(uint16_t index, qint64 newShowTime); //设置提示时间

    //状态栏输出通知，和状态栏按钮操作
    void setChangedProgressIndex(int index); //设置状态栏进度条进度
    void setStatusButton(int btnIndex,QString title,QIcon ico_32x,QString sign,std::function<void(QString sign)> funPtr); //设置状态栏按钮，funPtr为nullptr时，隐藏.index的范围为1-6
    void setStatusHideAll(); //隐藏所有的按钮




    PluginGlobalMsg::projectMsgBase getProjectMsgBase(QString proPath); //获取工程的基础信息

public: //(可阻拦事件)事件触发，返回true则继续触发其他插件的同类型时间，返回false则阻止触发其他插件
    virtual bool event_onModLoadFinish(){return true;};//当模块加载完毕，将第一时间激发此插件，禁止在获取实例处获得
    virtual bool event_onCompileTypeChanged(QString signName){return true;}; //当编译模式被改变
    virtual bool event_onFileOpen(QString filePath){return true;}; //当文件被打开，注意：仅限于IDE无法打开之外的文件才激发此事件
    virtual bool event_onFileOpenFinish(QString filePath){return true;}; //当前文件已经被打开，所有的文件被打开都会激发此事件
    virtual bool event_onFileClose(QString filePath){return true;}; //当前文件被删除或者关闭之前就发送的信息
    virtual bool event_onFileSave(QString filePath){return true;}; //当文件被保存激发事件
    virtual bool event_onFileSaveAll(){return true;}; //当全部保存被激发
    virtual bool event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction actionType, QString proPath,QString proLangs,QString proNoteClass){return true;};//当工具栏内部按钮被按下(参数1:激发按钮类型   参数2:工程的目录   参数3:工程的多个语言标记   参数4:工程类型标记)
    virtual bool event_onPorjectLoad(QString proPath,QString proLangs,QString proNoteClass){return true;}; //当工程被加载完毕(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)


public: //(不可阻拦事件)事件触发，将激发每一个插件的事件
    virtual void event_onThemeChanged(QString themeSign){return;}; //当主题改变，返回主题标记。常用Blue(蓝)，White(白)，Dark(黑)
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
