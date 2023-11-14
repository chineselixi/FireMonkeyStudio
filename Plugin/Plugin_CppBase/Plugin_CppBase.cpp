#include "Plugin_CppBase.h"
#include "QFile"
#include "QFileInfo"
#include "QMessageBox"
#include "QDir"
#include "QFileInfo"
#include "../../QScintilla/src/Qsci/qsciscintilla.h" //注意，这里是外部的QSciscintilla库，引入此文件需要在Pro文件中静态对应的dll与lib
#include "Form/Form_CodeEditor.h"
#include "Form/Form_Attributee.h""
#include "Form/settingForm/Form_settings_Compile.h"
#include "QCoreApplication"
#include "../../IDE/SwSystem/System_UtilFun.h" //获取系统工具类


Plugin_CppBase::Plugin_CppBase()
{
    /*
* 注意，此时内部所有指针都是nullptr，不允许调用ide能力，当event_onModLoadFinish加载完毕后相关指针与模块才加载完毕
* 注意：调用指针的时候也需要判断调用的指针是否为空指针，在某些场景下，ide内部会置空某些模块内的指针
* 注意：插件内部函数都已经经过安全封装，多次调用或者是在不合时宜的情况下调用不会出现异常
*/
    this->self_BaseMsg.name = "C++基础编码能力"; //支持库信息
    this->self_BaseMsg.version = "0.0.0.1 Dev";  //支持库显示版本
    this->self_BaseMsg.versionNumber = 1; //支持库数字版本
    this->self_BaseMsg.sign = "Cpp_Base"; //插件标记，插件之间的通信需要的标记。注意，插件的标记可以相同，管理器将通过这些标记进行数据传输
    this->self_BaseMsg.note = "用于支持C++语言在FMS平台的基础工程开发，注意：若本插件未被启用，则将丧失C++语言的编程能力。C++工程将由其他插件进行代理。";
    this->self_BaseMsg.loadTip = "";//加载时输出的文字信息，可以作为加载成功的提示
    this->self_BaseMsg.level = 100; //排序级别范围：0-65535，默认为最低级别，相同的级别系统将随机分配，自定义插件建议高于0
}



//当工程被加载完毕(参数1:工程的目录   参数2:工程的多个语言标记   参数3:工程类型标记)
bool Plugin_CppBase::event_onPorjectLoad(QString proPath, QString proLangs, QString proNoteClass)
{
    static QAction* t_actionAttribute = nullptr; //属性菜单
    std::function<void()> t_attributeFun = [this,proPath](){
        this->event_attribute(proPath);
    };

    if(this->checkIsCppProject(proLangs)){ //检查是否为Cpp对象
        this->closeWorkSpaceAllAction(); //关闭所有ACTION
        this->setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::run,true); //允许运行
        this->setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::compile,true); //允许编译
        this->setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::staticCompile,true); //允许静态编译
        this->setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::onlineCompile,true); //允许在线编译

        //添加属性到工程菜单
        t_actionAttribute = new QAction("属性");
        t_actionAttribute->connect(t_actionAttribute,&QAction::triggered,t_attributeFun);
        this->addProMangerMenu(PluginGlobalMsg::proMangerMenuType::Project,t_actionAttribute);
        return false; //阻止消息传递
    }

    //删除菜单
    if(t_actionAttribute!=nullptr){
        t_actionAttribute->disconnect();
        delete t_actionAttribute;
    }

    return true;
}


//当工具栏内部按钮被按下(参数1:激发按钮类型   参数2:工程的目录   参数3:工程的多个语言标记   参数4:工程类型标记)
bool Plugin_CppBase::event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction actionType, QString proPath, QString proLangs, QString proNoteClass)
{
    if(!this->checkIsCppProject(proLangs)){
        return true; //不是C++工程则组织，继续触发别的插件消息
    }

    if(actionType == PluginGlobalMsg::toolBarAction::reRun || //重新编译
        actionType == PluginGlobalMsg::toolBarAction::run || //运行
        actionType == PluginGlobalMsg::toolBarAction::compile || //编译
        actionType == PluginGlobalMsg::toolBarAction::staticCompile //静态编译
        )
    {
        QVector<QString> t_srcList;
        t_srcList.reserve(50);//先设置容量为50个长度，防止多次扩容
        this->findSource(proPath,t_srcList);//扫描文件
        QVector<QString> t_changeFile = this->getChangeFileList(t_srcList); //扫描文件是否被更改

        switch (actionType){
        default:
        case PluginGlobalMsg::toolBarAction::reRun:{ //重新编译
            this->event_stop(); //停止
        }
        case PluginGlobalMsg::toolBarAction::run:{ //运行
            this->event_run(t_srcList,t_changeFile,proPath + "/out");
            break;
        }
        case PluginGlobalMsg::toolBarAction::compile:{ //编译
            this->event_compile(t_srcList,t_changeFile,proPath + "/out");
            break;
        }
        case PluginGlobalMsg::toolBarAction::staticCompile:{ //静态编译
            this->event_compile(t_srcList,t_changeFile,proPath + "/out"); //静态编译暂时没实现，使用普通编译
            break;
        }
        }
    }
    else if(actionType == PluginGlobalMsg::toolBarAction::stop){
        this->event_stop(); //停止
    }



}


//文件被加载，阻止消息继续触发
bool Plugin_CppBase::event_onFileOpen(QString filePath)
{
    filePath = filePath.toLower();
    if(stringRight(filePath,".h") ||
        stringRight(filePath,".cpp") ||
        stringRight(filePath,".hpp") ||
        stringRight(filePath,".c") ||
        stringRight(filePath,".cc")){

        QIcon t_ico(":/tabIco/resources/unKnowFile.png"); //图标文件
        if(stringRight(filePath,".cpp")) t_ico = QIcon(":/tabIco/resources/CPP_16x.png");
        if(stringRight(filePath,".h")) t_ico = QIcon(":/tabIco/resources/CPPHeaderFile_16x.png");
        if(stringRight(filePath,".c")) t_ico = QIcon(":/tabIco/resources/CFile_16x_color.png");


        if(this->hasTab(filePath,true)) return false; //如果文件已经在Tab里面，则不再重复打开。并且激活TAB（第二个参数为是否激活已经存在此sign的Tab）

        Form_CodeEditor* editor = new Form_CodeEditor();
        if(!editor->loadForFile(filePath)){
            QMessageBox::warning(nullptr,QObject::tr("文件异常"),QObject::tr("无法打开文件，文件不存在或通道被占用！"));
        }

        this->addTabWindow(QFileInfo(filePath).fileName(),editor,filePath,t_ico,PluginGlobalMsg::TabType::codeEditor); //添加到Tab
        return false;
    }
    return true;
}


//插件加载完毕加载信息
void Plugin_CppBase::event_onLoading()
{
    //加载设置信息
    Form_settings_Compile::loadSetting(System_File::readFile(OUTSETFILE)); //加载设置信息
    return;
}


//切换为了自己的Form
void Plugin_CppBase::event_onTabFormActivation(QWidget *form)
{

}


//Form即将被关闭
bool Plugin_CppBase::event_onTabFormCloseRequested(QWidget *form)
{
    return true;
}


//加载设置组件
void Plugin_CppBase::event_onLoadSettingsWidget(settingMsgList &msgList)
{
    //设置创建设置信息
    settingWidgetMsg setWidgetMsg;
    setWidgetMsg.ico_32px = QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/comple.png");
    setWidgetMsg.title = QObject::tr("GCC生成");
    setWidgetMsg.settingWidget = new Form_settings_Compile(this,nullptr); //创建设置窗口，传递本对象

    //加载设置到列表
    msgList.append(setWidgetMsg);

    return;
}


//判断是否拥有这个后缀
bool Plugin_CppBase::stringRight(QString str, QString suffix)
{
    if(str.right(suffix.length()) != suffix){
        return false;
    }
    return true;
}


//根据语言标记，判断此工程是否为Cpp工程
bool Plugin_CppBase::checkIsCppProject(QString langSign)
{
    langSign = langSign.toLower();
    if(langSign.indexOf("c++") != -1){
        return true;
    }
    return false;
}


//查找源码文件
void Plugin_CppBase::findSource(QString projectPath, QVector<QString> &retSrcList)
{
    QDir dir(projectPath);
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::AllDirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);
    for(QFileInfo fileInfo : list)
    {
        QString filePath = fileInfo.absoluteFilePath();
        if(fileInfo.isDir())
        {
            this->findSource(filePath,retSrcList); //内部递归遍历文件夹
        }
        else if(fileInfo.isFile())
        {
            QString suffix = fileInfo.suffix();
            suffix = suffix.toLower();
            if(suffix == "c" || suffix == "cpp"){
                retSrcList.append(filePath);
            }
        }
    }

}


//根据历史记录对比提供的文件是否已经被更改
QVector<QString> Plugin_CppBase::getChangeFileList(QVector<QString> nowList)
{
    QVector<fileSign> t_newHisList;
    fileSign t_tSign;

    for(QString newItem : nowList){
        t_tSign.filePath = newItem;
        QFileInfo t_info(newItem);
        if(!t_info.exists()){continue;}
        t_tSign.timeStamp = t_info.lastModified().toSecsSinceEpoch(); //获取文件更改的时间戳

        for(fileSign hItem : this->hostryFileSignList){
            if(t_tSign.filePath == hItem.filePath){    //判断是否为同一个文件
                if(t_tSign.timeStamp != hItem.timeStamp){ //判断最后的时间戳是否一致
                    t_newHisList.append(t_tSign);
                }
                goto RETBREAK;
            }
        }

        t_newHisList.append(t_tSign); //没有找到这个文件，则这个文件是新的文件，保存入列表
        RETBREAK: //文件相等，并且最后更改的时间戳也相等，则直接跳转到末尾
        continue;
    }

    this->hostryFileSignList = t_newHisList;  //保存新的历史文件信息

    //数据转换为字符组
    QVector<QString> t_retList;
    for(fileSign hItem : this->hostryFileSignList){
        t_retList.append(hItem.filePath);
    }
    return t_retList;
}


//清空历史文件列表
void Plugin_CppBase::clearHostryFileList()
{
    this->hostryFileSignList.clear();
}


//打开属性
void Plugin_CppBase::event_attribute(QString proPath)
{
    QString t_attrFile = proPath + "/config.json";

//    qDebug() << "配置文件：" << t_attrFile;

    this->addTabWindow("属性",new Form_Attribute(),t_attrFile,QIcon(),PluginGlobalMsg::TabType::form);


    QFile t_configFile(t_attrFile);
    if(!t_configFile.exists()){
        return;
    }

}



//停止当前运行的进程
void Plugin_CppBase::event_stop()
{

}


//运行程序（compileFiles编译的文件组，changeFiles文件组中改变的文件）
void Plugin_CppBase::event_run(QVector<QString> compileFiles, QVector<QString> changeFiles, QString outPath)
{

}

//编译（compileFiles编译的文件组，changeFiles文件组中改变的文件）
void Plugin_CppBase::event_compile(QVector<QString> compileFiles, QVector<QString> changeFiles, QString outPath)
{

}


