
#ifndef PLUGIN_BASE_H
#define PLUGIN_BASE_H

#include "Plugin_Global.h"

//class QMainWindow; //声明QMainWindow
class Form_settings_Basic;


class Plugin_Base
{
public:

    struct libMsg{
        QString name = "NULL";         //支持库信息
        QString version = "1.0.0.1";  //支持库显示版本
        int versionNumber = 1; //支持库数字版本
        QString sign = ""; //插件标记，插件之间的通信需要的标记。注意，插件的标记可以相同，管理器将通过这些标记进行数据传输
        QString note = "Plugin for FireMonkey Studio";
        QString loadTip = "";//加载时输出的文字信息，可以作为加载成功的提示
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

public:
    //初始化信息，由IDE侧载，可复写
    virtual libMsg getBaseMsg(){return self_BaseMsg;}; //获取基础的类信息


protected: //插件的基础方法
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
    virtual void event_onLoading(){return;}; //初次加载事件，插件被成功加载完成以后第一次通知的事件，注意：此时其他插件可能并没有加载完成
    virtual void event_onLoadSettingsWidget(settingMsgList& msgList){return;}; //当加载设置组件的时候


public:
    //插件管理器接口
    virtual QString event_onPluginReceive(QString sendPluginSign,QString msg){return "";}; //参数（发送者标记，发送信息），返回值（当返回的信息不是空则第一时间返回），当插件接收到发送的信息

};
#endif // PLUGIN_BASE_H
