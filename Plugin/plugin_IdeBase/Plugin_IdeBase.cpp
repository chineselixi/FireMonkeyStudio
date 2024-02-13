#include "Plugin_IdeBase.h"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"
#include "QProcess"
#include "QMainWindow"
#include "Dialog/Dialog_Index.h"



////设置工作空间Action启用
//void Plugin_Base::setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction actionType, bool isEnable)
//{


//}



Plugin_IdeBase::Plugin_IdeBase()
{
/*
* 注意，此时内部所有指针都是nullptr，不允许调用ide能力，当event_onModLoadFinish加载完毕后相关指针与模块才加载完毕
* 注意：调用指针的时候也需要判断调用的指针是否为空指针，在某些场景下，ide内部会置空某些模块内的指针
* 注意：插件内部函数都已经经过安全封装，多次调用或者是在不合时宜的情况下调用不会出现异常
*/
    this->self_BaseMsg.name = "IDE基础支持"; //支持库信息
    this->self_BaseMsg.version = "0.0.0.1 Dev";  //支持库显示版本
    this->self_BaseMsg.versionNumber = 1; //支持库数字版本
    this->self_BaseMsg.sign = "IDE_Base"; //插件标记，插件之间的通信需要的标记。注意，插件的标记可以相同，管理器将通过这些标记进行数据传输
    this->self_BaseMsg.note = "本插件为IDE基础功能插件，不提供语言支持能力。当无任何自定义插件处理事件时本插件将处理最终的激发事件，这是静默执行，且不会阻止插件信息的进一步传递。";
    this->self_BaseMsg.loadTip = "欢迎使用FMS！";//加载时输出的文字信息，可以作为加载成功的提示
    this->self_BaseMsg.level = 05; //排序级别范围：0-65535，默认为最低级别，相同的级别系统将随机分配，自定义插件建议高于0
}

void Plugin_IdeBase::event_onWorkSpaceFinish()
{
    //添加文件类型图标
    this->projectManger_addFileIco("c",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CFile_16x_color.png"));
    this->projectManger_addFileIco("cpp",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CPP_16x.png"));
    this->projectManger_addFileIco("h",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CPPHeaderFile_16x.png"));
    this->projectManger_addFileIco("css",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CSSLink_16x.png"));
    this->projectManger_addFileIco("ec",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/ec.png"));
    this->projectManger_addFileIco("html",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/HTMLFile_16x.png"));
    this->projectManger_addFileIco("ico",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/IconFile_16x.png"));
    this->projectManger_addFileIco("jar",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/JARFile_16x.png"));
    this->projectManger_addFileIco("java",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/JavaFile_16x.png"));
    this->projectManger_addFileIco("js",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/JS_16x.png"));
    this->projectManger_addFileIco("json",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/JSONFile_16x.png"));
    this->projectManger_addFileIco("link",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/LinkFile_16x.png"));
    this->projectManger_addFileIco("obj",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/NoncompilableFile_16x.png"));
    this->projectManger_addFileIco("php",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/PHPFile_16x.png"));
    this->projectManger_addFileIco("png",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/pic.png"));
    this->projectManger_addFileIco("jpg",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/pic.png"));
    this->projectManger_addFileIco("bmp",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/pic.png"));
    this->projectManger_addFileIco("py",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/PY_16x.png"));
    this->projectManger_addFileIco("sql",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/SQLFile_16x.png"));
    this->projectManger_addFileIco("text",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/TextFile_16x.png"));
    this->projectManger_addFileIco("xml",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/XMLFile_16x.png"));
    this->projectManger_addFileIco("zip",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/ZipFile_16x.png"));
    this->projectManger_addFileIco("rar",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/ZipFile_16x.png"));
    this->projectManger_addFileIco("7z",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/ZipFile_16x.png"));


    //初始化基本参数
    this->print_clearList();
    this->menu_closeWorkSpaceAllAction(); //禁用所有Action
    this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::bookmarkMainMenuTabitem,true); //启用书签主菜单

    //添加菜单
    QAction* t_terminalAction = new QAction();
    t_terminalAction->setText(tr("创建新终端"));

    //创建菜单，用于菜单创建终端
    connect(t_terminalAction,&QAction::triggered,[=](){
        static int t_id = 0; t_id++;
        this->createTerminalWidget("Terminal" + QString::number(t_id));
    });

    this->menu_addMenuBarMenu(PluginGlobalMsg::MenuBarType::toolType,t_terminalAction);
}


bool Plugin_IdeBase::event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction actionType, QString proPath, QString proLangs, QString proNoteClass)
{
    if(actionType == PluginGlobalMsg::toolBarAction::bookmarkMainMenuTabitem){
        Dialog_Index* di = new Dialog_Index();
        di->show();
    }
    return true; //阻止消息传递
}


//base插件收到消息
QString Plugin_IdeBase::event_onPluginReceive(QString sendPluginSign, QString msg)
{
    qDebug() << "IDE sendPluginSign===" << sendPluginSign;


    //获取消息对象
    QJsonDocument t_jsonDoc = QJsonDocument::fromJson(msg.toUtf8());
    QJsonObject t_jsonObj = t_jsonDoc.object();
    if(t_jsonObj.isEmpty()) return "";

    //获取消息类型
    QString t_msgType = t_jsonObj.value("type").toString();
    if(t_msgType.isEmpty()) return "";

    if(t_msgType == "runProcess"){
        QString t_command = t_jsonObj.value("command").toString();
        if(t_command.isEmpty()) return ""; //若没有运行的命令，则停止

        //获取终端，并且运行
        Form_Terminal* t_terminal = this->createTerminalWidget(t_command);
        t_terminal->disconnect();
        Form_Terminal::connect(t_terminal,&Form_Terminal::sig_start,[this,sendPluginSign](QString comm){//终端程序开始运行
            QMap<QString,QJsonValue> t_map;
            t_map.insert("sign","terminal");
            t_map.insert("comm",comm);
            t_map.insert("state","start");
            t_map.insert("error","");
            this->postJson(sendPluginSign,t_map);
        });
        Form_Terminal::connect(t_terminal,&Form_Terminal::sig_error,[this,sendPluginSign](QString comm,QString errorMsg){ //终端程序出现错误
            QMap<QString,QJsonValue> t_map;
            t_map.insert("sign","terminal");
            t_map.insert("comm",comm);
            t_map.insert("state","error");
            t_map.insert("error",errorMsg);
            this->postJson(sendPluginSign,t_map);
        });
        Form_Terminal::connect(t_terminal,&Form_Terminal::sig_finish,[this,sendPluginSign](QString comm, int exitCode){ //终端程序停止运行
            QMap<QString,QJsonValue> t_map;
            t_map.insert("sign","terminal");
            t_map.insert("comm",comm);
            t_map.insert("state","finish");
            t_map.insert("exitCode",exitCode);
            this->postJson(sendPluginSign,t_map);
        });


        if(t_terminal->isRunning()) t_terminal->killProcess(); //停止已经运行的程序
        t_terminal->runProcess(t_command); //运行新的命令
        t_terminal->raise(); //提升到当前选择项
        return this->ret_JsonOK(true);
    }

    return this->ret_JsonOK(false);
}

//创建终端窗口
Form_Terminal *Plugin_IdeBase::createTerminalWidget(QString command)
{
    for(Form_Terminal* item : terminalList){
        if(item && item->getRunCommand() == command){
            return item;
        }
    }

    //创建新的终端窗口
    Form_Terminal* t_terminal = new Form_Terminal();
    Form_Terminal::connect(t_terminal,&QWidget::destroyed,[=]{  //终端窗口被关闭，绑定自动删除
        this->deleteTerminalWidget(t_terminal);
    });

    terminalList.append(t_terminal);
    //t_terminal->runProcess(command);

    //将终端加入IDE
    QMainWindow* t_mainWindow = this->widget_getWorkSpaceWindowPtr();
    if(t_mainWindow){  //获取工作控件窗口
        QDockWidget* t_dockWidget = nullptr;
        QList<QDockWidget*> t_docks = t_mainWindow->findChildren<QDockWidget*>("IdeBase_Dock_Terminal");  //查找运行与提示Dock
        if(t_docks.length() == 0){
            t_docks = t_mainWindow->findChildren<QDockWidget*>("dockWidget_print");  //查找运行与提示Dock
        }

        //取最后一个DockWidget
        if(t_docks.length() > 0) t_dockWidget = t_docks[t_docks.length() - 1];

        //将新的终端加入到IDE中
        if(t_dockWidget != nullptr){
            QDockWidget* dock = new QDockWidget;
            dock->setWindowTitle(tr("终端"));
            dock->setWidget(t_terminal);
            t_mainWindow->tabifyDockWidget(t_dockWidget,dock);

            //设置可见，并且提升，相当于选择这个
            dock->setVisible(true);
            dock->raise();
        }
    }
    return t_terminal;
}


//删除终端窗口
void Plugin_IdeBase::deleteTerminalWidget(Form_Terminal *widget)
{
    for(qsizetype i = 0; i < this->terminalList.length(); i ++){
        if(this->terminalList[i] == widget){
            terminalList.remove(i);
            return;
        }
    }
}


//Json返回信息
QString Plugin_IdeBase::ret_JsonOK(bool isOK)
{
    return this->ret_budJson({
                       {"sign","terminal"},
                       {"isOK",isOK}
    });
}


//构建Json信息
QString Plugin_IdeBase::ret_budJson(QMap<QString, QJsonValue> map)
{
    QJsonDocument t_jsonDoc;
    QJsonObject t_jsonObj;
    QMap<QString, QJsonValue>::Iterator i;
    for(i = map.begin(); i != map.end(); ++i)
    {
        t_jsonObj.insert(i.key(),i.value());
    }
    t_jsonDoc.setObject(t_jsonObj);
    return t_jsonDoc.toJson();
}


//插件消息投递
QString Plugin_IdeBase::postJson(QString pluginName, QMap<QString, QJsonValue> map)
{
    return this->plugin_postPluginMessage(pluginName,this->ret_budJson(map));
}

