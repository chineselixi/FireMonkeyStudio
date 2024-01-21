#include "Plugin_CppBase.h"
#include "QFile"
#include "QMessageBox"
#include "QDir"
#include "QFileInfo"
#include "QJsonDocument"
#include "QJsonArray"
#include "QJsonObject"
#include "QElapsedTimer"

#include "../../QScintilla/src/Qsci/qsciscintilla.h" //注意，这里是外部的QSciscintilla库，引入此文件需要在Pro文件中静态对应的dll与lib
#include "Form/Form_CodeEditor.h"
#include "Form/Form_Attributee.h""
#include "Form/settingForm/Form_settings_Compile.h"
#include "QCoreApplication"
#include "../../IDE/SwSystem/System_UtilFun.h" //获取系统工具类
#include "../../IDE/SwSystem/System_GlobalVar.h"

#define MOD_DEBUG "Debug (调试)"
#define MOD_RELEASE "Release (发布)"

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
bool Plugin_CppBase::event_onProjectActiveChanged(QString proPath, QString proLangs, QString proNoteClass)
{
    static QAction* t_actionAttribute = nullptr; //属性菜单
    std::function<void()> t_attributeFun = [this,proPath](){
        this->event_attribute(proPath); //执行属性菜单
    };

    if(this->checkIsCppProject(proLangs)){ //检查是否为Cpp对象
        this->menu_closeWorkSpaceAllAction(); //关闭所有ACTION
        this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::compleMode,true); //允许模式选择
        this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::run,true); //允许运行
        this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::compile,true); //允许编译
        this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::staticCompile,true); //允许静态编译
        this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::onlineCompile,true); //允许在线编译

        //添加属性到工程菜单
        t_actionAttribute = new QAction(QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Constant_16x.png"),QObject::tr("配置"));
        t_actionAttribute->connect(t_actionAttribute,&QAction::triggered,t_attributeFun);
        this->menu_addProMangerMenu(PluginGlobalMsg::proMangerMenuType::Project,t_actionAttribute);


        //重构编译模式
        this->compile_clearAllCompileMod(); //清空编译模式
        this->compile_addCompileMod(MOD_RELEASE); //删除调试编译模式
        this->compile_addCompileMod(MOD_DEBUG); //添加调试编译模式
        this->compile_selectCompileMod(MOD_DEBUG); //选择调试编译模式
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
        //保存当前的代码
        //this->saveCode();

        //扫描工程的文件，开始编译
        QVector<QString> t_srcList;
        t_srcList.reserve(50);//先设置容量为50个长度，防止多次扩容
        this->findSource(proPath,t_srcList);//扫描文件
//        QVector<QString> t_changeFile = this->getChangeFileList(t_srcList); //扫描文件是否被更改

        switch (actionType){
        default:
        case PluginGlobalMsg::toolBarAction::reRun:{ //重新编译
            this->event_stop(); //停止
        }
        case PluginGlobalMsg::toolBarAction::run:{ //运行
            this->event_run(proPath,t_srcList);
            break;
        }
        case PluginGlobalMsg::toolBarAction::compile:{ //编译
            this->event_compile(proPath,t_srcList); //默认输出路径：proPath + "/out"
            this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::run,true); //允许运行
            this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::compile,true); //允许编译
            this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::staticCompile,true); //允许静态编译
            this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::onlineCompile,true); //允许在线编译
            break;
        }
        case PluginGlobalMsg::toolBarAction::staticCompile:{ //静态编译
            this->event_compile(proPath,t_srcList); //静态编译暂时没实现，使用普通编译
            this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::run,true); //允许运行
            this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::compile,true); //允许编译
            this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::staticCompile,true); //允许静态编译
            this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::onlineCompile,true); //允许在线编译
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


        if(this->tabWindow_hasTab(filePath,true)) return false; //如果文件已经在Tab里面，则不再重复打开。并且激活TAB（第二个参数为是否激活已经存在此sign的Tab）

        Form_CodeEditor* editor = new Form_CodeEditor();
        //QObject::connect(this,&Plugin_CppBase::saveCode,editor,&Form_CodeEditor::event_timer_textChanged); //绑定此方法，在按钮被点击的时候。立即保存
        if(!editor->loadForFile(filePath)){
            QMessageBox::warning(nullptr,QObject::tr("文件异常"),QObject::tr("无法打开文件，文件不存在或通道被占用！"));
        }

        this->tabWindow_addTabWindow(QFileInfo(filePath).fileName(),editor,filePath,t_ico,PluginGlobalMsg::TabType::codeEditor); //添加到Tab
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


//工作空间加载完毕
void Plugin_CppBase::event_onWorkSpaceFinish()
{
    //加载文件图标
//    this->projectManger_addFileIco("cpp",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CPP_16x.png"));
//    this->projectManger_addFileIco("c",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CFile_16x_color.png"));
//    this->projectManger_addFileIco("h",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CPPHeaderFile_16x.png"));

    //添加新建文件类型
    this->projectManger_addBuildFileSign("h",
                                         QObject::tr("头文件(h)"),
                                         QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CPPHeaderFile_16x.png"),
                                         QObject::tr("头文件"),
                                         "#pragma once\n\n\n\n");
    this->projectManger_addBuildFileSign("c",
                                         QObject::tr("C源文件(c)"),
                                         QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CFile_16x_color.png"),
                                         QObject::tr("C源"),
                                         "");
    this->projectManger_addBuildFileSign("cpp",
                                         QObject::tr("C++源文件(cpp)"),
                                         QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CPP_16x.png"),
                                         QObject::tr("Cpp源"),
                                         "");

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


//根据编译映射文本信息读取编译映射
QVector<Plugin_CppBase::MapperNode> Plugin_CppBase::parseCompileMapper(QString mapperContent)
{
    QVector<Plugin_CppBase::MapperNode> retMappers;
    retMappers.reserve(32); //率先申请32个容量，防止多次扩容

    QJsonDocument t_jsonDoc = QJsonDocument().fromJson(mapperContent.toUtf8());
    QJsonArray t_jsonArray = t_jsonDoc.array(); //读取信息组
    for(QJsonValueRef node : t_jsonArray){
        QJsonObject t_jsonObj = node.toObject();
        Plugin_CppBase::MapperNode t_mapper;

        //读取本地的映射信息组
        t_mapper.filePath = t_jsonObj.value("filePath").toString();
        if(t_mapper.filePath.isEmpty()) continue; //如果输出路径为空，则直接忽略这个文件
        t_mapper.timeStamp = t_jsonObj.value("timeStamp").toInteger();
        t_mapper.mapperName = t_jsonObj.value("mapperName").toString();
        t_mapper.lonelyCompile = t_jsonObj.value("lonelyCompile").toBool(false);
        t_mapper.neadCompile = t_jsonObj.value("neadCompile").toBool(true);
        retMappers.append(t_mapper);
    }
    return retMappers;
}


//根据映射信息转换为文本
QString Plugin_CppBase::compileMapperToString(QVector<MapperNode> mapperList)
{
    QJsonDocument t_jsonDoc;
    QJsonArray t_jsonArray;
    for(MapperNode node : mapperList){
        QJsonObject t_jsonObj;
        t_jsonObj.insert("filePath",node.filePath);
        t_jsonObj.insert("timeStamp",node.timeStamp);
        t_jsonObj.insert("mapperName",node.mapperName);
        t_jsonObj.insert("lonelyCompile",node.lonelyCompile);
        t_jsonObj.insert("neadCompile",node.neadCompile);
        t_jsonArray.append(t_jsonObj);
    }
    t_jsonDoc.setArray(t_jsonArray);
    return t_jsonDoc.toJson();
}


//整理Mapper，去除重复文件，去除名称重名
QVector<Plugin_CppBase::MapperNode> Plugin_CppBase::arrangeMappers(QVector<MapperNode> mappers)
{
    QVector<Plugin_CppBase::MapperNode> retMappers;
    retMappers.reserve(32);

    //去除文件路径名重名
    for(unsigned int x = 0; x < mappers.length(); x++){
        for(unsigned int y = x + 1; y < mappers.length(); y++){
            if(mappers[x].filePath == mappers[y].filePath){
                goto BREAK;
            }
        }
        retMappers.append(mappers[x]);
        BREAK:
        continue;
    }

    int* t_arraySign = new int[retMappers.length()](); //重名映射列表，如果为非0，则需要文件名+数字
    //去除映射文件基础名称重名
    CHECKNAME:
    for(unsigned int x = 0; x < retMappers.length(); x++){
        for(unsigned int y = x + 1; y < retMappers.length(); y++){
            QString name1 = retMappers[x].mapperName + (t_arraySign[x]==0?"":QString::number(t_arraySign[x]));
            QString name2 = retMappers[y].mapperName + (t_arraySign[y]==0?"":QString::number(t_arraySign[y]));
            if(name1 == name2){
                t_arraySign[y]++;
                goto CHECKNAME; //重新检查是否重名
            }
        }
    }

    //整合文件的重名信息
    for(unsigned int x = 0; x < retMappers.length(); x++){
        retMappers[x].mapperName = retMappers[x].mapperName + (t_arraySign[x]==0?"":QString::number(t_arraySign[x]));
    }

    //检查是否需要单独编译
    for(unsigned int x = 0; x < retMappers.length(); x++){
        QFileInfo t_filrInfro(retMappers[x].filePath);
        retMappers[x].lonelyCompile = (t_filrInfro.baseName() != retMappers[x].mapperName); //设置是否需要单独编译
    }

    delete t_arraySign;
    return retMappers;
}




//提供一个文件列表和原始的映射列表，返回新的编译映射列表
QVector<Plugin_CppBase::MapperNode> Plugin_CppBase::getCompileMapper(QVector<QString> srcFiles, QVector<MapperNode> mapperList)
{
    QVector<Plugin_CppBase::MapperNode> retMappers;
    for(QString file : srcFiles){
        QFileInfo t_info(file);
        if(!t_info.exists()) continue; //文件不存在，则忽略
        MapperNode mapperNode;
        mapperNode.filePath = file;
        mapperNode.mapperName = t_info.baseName();
        mapperNode.neadCompile = true; //默认设置需要重新编译
        mapperNode.timeStamp = t_info.lastModified().toSecsSinceEpoch(); //获取文件的最后修改事件
        for(MapperNode mapper : mapperList){
            if(file == mapper.filePath){
                //mapperNode = mapper; //存在于原来的映射表中，则使用原来的映射表信息，暂时弃用，因为可能会造成多项目都出现个单独编译的问题
                if(mapperNode.timeStamp == mapper.timeStamp){
                    mapperNode.neadCompile = false; //设置为不需要重新编译
                    break;
                }
            }
        }
        retMappers.append(mapperNode);
    }
    return retMappers;
}


//关闭相关Action
void Plugin_CppBase::closeRunActions()
{
    this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::run,false); //禁止运行
    this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::stop,false); //禁止停止
    this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::compile,false); //禁止编译
    this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::staticCompile,false); //禁止静态编译
    this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::onlineCompile,false); //禁止在线编译
}




//合并映射信息
QVector<Plugin_CppBase::MapperNode> Plugin_CppBase::mergeMappers(QVector<MapperNode> m1, QVector<MapperNode> m2)
{
    QVector<Plugin_CppBase::MapperNode> retMappers;
    retMappers.append(m1);
    for(MapperNode node1 : m2){ //把m2多出的Node加入到列表
        for(MapperNode node2 : retMappers){
            if(node1.filePath == node2.filePath){
                goto BREAK;
            }
        }
        retMappers.append(node1);
        BREAK:
        continue;
    }

    //整理并且返回Node
    return this->arrangeMappers(retMappers);
}





//打开属性
void Plugin_CppBase::event_attribute(QString proPath)
{
    QString t_attrFile = proPath + "/config.json";
    if(this->tabWindow_hasTab(t_attrFile,true) == false){
        QString t_proName = this->projectManger_getProjectInfo(proPath).proName; //获取工程名
        this->tabWindow_addTabWindow(QObject::tr("配置") + (t_proName.isEmpty()?"":"(" + t_proName + ")"),new Form_Attribute(nullptr,t_attrFile,this->projectManger_getProjectInfo(proPath).proName),t_attrFile,QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Constant_16x.png"),PluginGlobalMsg::TabType::form);
    }
}



//停止当前运行的进程
void Plugin_CppBase::event_stop()
{

}


//运行程序（compileFiles编译的文件组，changeFiles文件组中改变的文件）
void Plugin_CppBase::event_run(QString proPath, QVector<QString> compileFiles)
{
    //编译
    QString t_exeFile = this->event_compile(proPath,compileFiles);
    QString t_proName = this->projectManger_getProjectInfo(proPath).proName; //获取工程名称
    //运行程序
    if(!t_exeFile.isEmpty()){
        this->statusBar_setStatusHideAll();
        this->tip_addTip(tr("通知"),tr("编译成功"),2000,PluginGlobalMsg::TipType::Normal);

        if(execProcess == nullptr) execProcess = new QProcess;

        execProcess->kill();        //结束以前的程序
        execProcess->disconnect();  //断开全部的链接
        connect(execProcess,&QProcess::started,this,&Plugin_CppBase::event_runStarted);     //程序开始运行
        connect(execProcess,&QProcess::finished,this,&Plugin_CppBase::event_runFinished);   //程序运行完毕

        this->closeRunActions();

        //t_exeFile.append(".exe");
        if(execProcess->startDetached(t_exeFile,{})){
            this->print_printList("",QObject::tr("运行: ") + t_exeFile,t_proName,"",-1,PluginGlobalMsg::printIcoType::ok,QColor());
        }
        else{
            this->print_printList("",QObject::tr("失败: ") + t_exeFile,t_proName,"",-1,PluginGlobalMsg::printIcoType::error,QColor("red"));
            this->tip_addTip(tr("停止"),tr("运行失败"),5000,PluginGlobalMsg::TipType::Error);
        }

        return;
    }
    this->tip_addTip(tr("停止"),tr("运行失败"),5000,PluginGlobalMsg::TipType::Error);
    this->print_printList("",QObject::tr("运行失败"),t_proName,"",-1,PluginGlobalMsg::printIcoType::error,QColor("red"));

}

//编译（compileFiles编译的文件组，changeFiles文件组中改变的文件）
QString Plugin_CppBase::event_compile(QString proPath, QVector<QString> compileFiles)
{
    QString t_proName = this->projectManger_getProjectInfo(proPath).proName; //获取工程名称

    QElapsedTimer t_runTime;
    t_runTime.restart();

    //判断输入参数是否合法
    if(compileFiles.length() == 0){
        this->print_printList("",QObject::tr("需要编译的文件为空，不存在编译信息"),t_proName,"",-1,PluginGlobalMsg::printIcoType::error,QColor("red"));
        this->tip_addTip(tr("失败"),tr("需要编译的文件为空，不存在编译信息"),5000,PluginGlobalMsg::TipType::Error);
        return "";
    }
    if(!QDir(proPath).exists()){
        this->print_printList("",QObject::tr("工程不存在"),t_proName,proPath,-1,PluginGlobalMsg::printIcoType::error,QColor("red"));
        this->tip_addTip(tr("失败"),tr("工程不存在"),5000,PluginGlobalMsg::TipType::Error);
        return "";
    }


    this->print_clearList(); //清空输出列表
    this->print_clearTextSpace(); //清理空间信息

    //读取设置信息
    settingNamespace::settingNode t_settingMsg = Form_settings_Compile::getNowCompilerNode(); //获取当前设置信息（包含s4编译器信息）


    //运行参数==============================
    QStringList t_runPar;
    QString t_sPar;
    //设置优化级别
    if(!t_settingMsg.s21_opLevel.isEmpty()){
        t_sPar = Str::getSubStr(t_settingMsg.s21_opLevel,"(",")");
        if(!t_sPar.isEmpty() && t_sPar.left(2) == "-O"){
            t_runPar.append(t_sPar);
        }
    }

    //设置语言标准 ISO C++98
    if(!t_settingMsg.s21_cppStd.isEmpty()){
        t_sPar = Str::getSubStr(t_settingMsg.s21_cppStd,"ISO ","");
        if(t_sPar.isEmpty()){
            t_sPar = Str::getSubStr(t_settingMsg.s21_cppStd,"GNU C","");
            if(!t_sPar.isEmpty()){
                t_sPar = "gnu" + t_sPar;
            }
        }
        if(!t_sPar.isEmpty()){
            t_sPar = "-std=" + t_sPar.toLower(); //转换为小写参数
            t_runPar.append(t_sPar);
        }
    }

    //启用特殊指令集
    if(!t_settingMsg.s21_specificInstruct.isEmpty()){
        t_sPar = t_settingMsg.s21_specificInstruct;
        t_sPar = t_sPar.replace(" ","").toLower();
        t_sPar = "-m" + t_sPar;
        t_runPar.append(t_sPar);
    }

    //使用指定指针
    if(!t_settingMsg.s21_bit.isEmpty()){
        t_sPar = Str::getSubStr(t_sPar,"","bit").toLower();
        if(!t_sPar.isEmpty()){
            t_sPar = "-m" + t_sPar;
            t_runPar.append(t_sPar);
        }
    }

    //使用发行或者调试
    if(!t_settingMsg.s21_compileMod.isEmpty()){
        t_sPar = Str::getSubStr(t_sPar,"(",")").toLower();
        if(t_sPar.left(2) == "-g"){
            t_runPar.append(t_sPar);
        }
    }
    else{ //设置编译模式
        t_sPar = this->compile_getCompileModSignName(); //获取编译模式
        if(t_sPar == MOD_DEBUG){
            t_sPar = "-g";
            t_runPar.append(t_sPar);
        }
    }

    //多线程编译
    if(t_settingMsg.s21_enableThread){
        t_sPar = "-fopenmp";
        t_runPar.append(t_sPar);
    }



    //优化文件名，防止文件名异常
    if(t_proName.isEmpty()){
        this->print_printList("",QObject::tr("工程名为空，无法编译！"),t_proName,"",-1,PluginGlobalMsg::printIcoType::error,QColor("red"));
        return "";
    }
    t_proName = t_proName.replace("*","_").replace("\\","_").replace("/","_").replace(":","_").replace("?","_").replace("\"","_").replace("<","_").replace(">","_").replace("|","_").replace(":","_");

    this->print_printList("",QObject::tr("开始编译..."),t_proName,"",-1,PluginGlobalMsg::printIcoType::tip,QColor("blue"));
    if(t_settingMsg.s4_compileMsg.fp_gpp.isEmpty()){ //判断编译器是否存在
        this->print_printList("",QObject::tr("没有发现合适的编译器，工程无法编译！"),t_proName,"",-1,PluginGlobalMsg::printIcoType::error,QColor("red"));
        return "";
    }

    //读取本地属性信息
    QString t_attrFile = proPath + "/config.json";
    cppAttributeNamespace::projectAttribute t_attr = Form_Attribute::loadAttribute(System_File::readFile(t_attrFile)); //尝试读取属性文件
    if(t_attr.programName.isEmpty()) t_attr.programName = t_proName; //如果没有指定输出内容，则用工程名
    t_attr.outPath.replace("${projectPath}",proPath); //最终编译输出内容
    t_attr.tempPath.replace("${projectPath}",proPath); //临时文件输出内容


    //验证输出目录与临时目录
    if(!QDir().mkpath(t_attr.outPath) || !QDir().mkpath(t_attr.tempPath)){
        this->print_printList("",QObject::tr("无法创建输出目录或临时目录，指定的输出路径无效！"),t_proName,"",-1,PluginGlobalMsg::printIcoType::error,QColor("red"));
        return "";
    }

    //读取高速编译缓存配置信息
    QString t_compileCacheJsonPath = t_attr.tempPath + "/compileCache.json"; //编译缓存映射路径
    QVector<MapperNode> t_staticCompileMappers; //快读编译静态映射缓存

    if(t_settingMsg.s21_tepOpt){ //静态映射缓存（快速编译）启用
        this->print_printList("",QObject::tr("已启用静态缓存加速编译"),t_proName,"",-1,PluginGlobalMsg::printIcoType::tip,QColor());
        t_staticCompileMappers = this->parseCompileMapper(System_File::readFile(t_compileCacheJsonPath));
        for(MapperNode& node : t_staticCompileMappers){
            node.filePath.replace("${projectPath}",proPath); //文件名符号转换，用于相对路径文件信息整理
        }
        if(t_staticCompileMappers.length() == 0){ //判断是否成功读入静态缓存
            this->print_printList("",QObject::tr("没有静态缓存支持，首次编译事件可能较长"),t_proName,"",-1,PluginGlobalMsg::printIcoType::warning,QColor("yellow"));
        }
    }
    else{
        this->print_printList("",QObject::tr("未开启快速编译（缓存优化）"),t_proName,"",-1,PluginGlobalMsg::printIcoType::warning,QColor("yellow"));
    }



    QVector<MapperNode> t_compileMapper = this->getCompileMapper(compileFiles,t_staticCompileMappers); //获取需要编译构建的文件信息
    t_compileMapper = this->arrangeMappers(t_compileMapper); //整理Mapper


    //开始编译
    QProcess t_process; //进程对象
    //开始编译
    t_process.setWorkingDirectory(t_attr.tempPath); //设置工作目录
    QStringList t_parameterList; //设置参数列表
    t_parameterList.append("-c"); //-c ：编译和汇编，但不链接。
    qsizetype t_compileFileNum = 0; //编译的文件数量
    for(qsizetype i = 0; i<t_compileMapper.length(); i++){
        if(t_compileMapper[i].lonelyCompile == false){ //不需要单独编译
            if(t_compileMapper[i].neadCompile || !t_settingMsg.s21_tepOpt){ //需要编译（编译没有缓存的mapper）  或 关闭了快速编译
                this->print_printTextSpaceLine(QColor(),QObject::tr("编译文件：") + t_compileMapper[i].filePath);
                t_parameterList.append(t_compileMapper[i].filePath); //插入文件编译信息
                t_compileFileNum++; //记录直接编译的文件数量
            }
        }
    }
    if(t_compileFileNum > 0){ //是否存在需要编译的文件
        t_parameterList.append(t_runPar); //添加附加编译选项
        t_process.start(t_settingMsg.s4_compileMsg.fp_gpp,t_parameterList); //编译为目标文件
        t_process.waitForReadyRead(); //等待输出
        QString t_normalPut = QString().fromLocal8Bit(t_process.readAllStandardOutput()); //读取控制台信息
        QString t_errorPut = QString().fromLocal8Bit(t_process.readAllStandardError()); //读取错误信息
        this->print_printTextSpaceLine(QColor(),t_normalPut); //输出到运行空间
        this->print_printTextSpaceLine(QColor("red"),t_errorPut);
        if(!t_errorPut.isEmpty()){
            this->print_printTextSpaceLine(QColor("red"),t_errorPut);
            this->print_printList("",QObject::tr("编译出错！详情信息请请查看输出！"),t_proName,"",-1,PluginGlobalMsg::printIcoType::error,QColor("red"));
            t_process.close();
            return "";
        }
    }
    else{
        this->print_printList("",QObject::tr("存在加速缓存,跳过编译..."),t_proName,"",-1,PluginGlobalMsg::printIcoType::warning,QColor("orange"));
    }


    //单独编译（用于单独的重名文件输出）
    t_process.close();
    t_process.setWorkingDirectory(t_attr.tempPath); //设置工作目录

    qsizetype t_compileFileNumRedirect = 0; //重定向编译的文件数量
    for(qsizetype i = 0; i<t_compileMapper.length(); i++){
        //需要单独编译，但是需要编译（编译没有缓存的mapper）
        if(t_compileMapper[i].lonelyCompile == true){
            if(t_compileMapper[i].neadCompile || !t_settingMsg.s21_tepOpt){ //需要编译（编译没有缓存的mapper）  或 关闭了快速编译
                this->print_printList("",QObject::tr("发现重名的源文件，已处理为：") + t_compileMapper[i].mapperName,
                                t_proName,                      //工程名称
                                t_compileMapper[i].filePath,    //源文件路径
                                -1,                             //行号
                                PluginGlobalMsg::printIcoType::warning, //提示图标
                                QColor()); //颜色
                this->print_printTextSpaceLine(QColor("yellow"),QObject::tr("重定向编译：") + t_compileMapper[i].filePath);

                t_parameterList.clear();//清空参数列表
                t_parameterList.append({"-c",t_compileMapper[i].filePath,"-o",t_compileMapper[i].mapperName + ".o"});//重新构建编译信息
                t_parameterList.append(t_runPar); //添加附加编译选项

                t_process.start(t_settingMsg.s4_compileMsg.fp_gpp,t_parameterList); //单独编译文件
                t_process.waitForReadyRead(); //等待输出
                QString t_normalPut = QString().fromLocal8Bit(t_process.readAllStandardOutput()); //读取控制台信息
                QString t_errorPut = QString().fromLocal8Bit(t_process.readAllStandardError()); //读取错误信息
                this->print_printTextSpaceLine(QColor(),t_normalPut); //输出到运行空间
                this->print_printTextSpaceLine(QColor("red"),t_errorPut);
                t_process.close(); //关闭文件
                if(!t_errorPut.isEmpty()){
                    this->print_printList("",QObject::tr("编译出现错误，详情请查看输出！"),t_proName,t_compileMapper[i].filePath,-1,PluginGlobalMsg::printIcoType::error,QColor("red"));
                    return "";
                }

                t_compileFileNumRedirect++; //记录单独编译的文件数量
            }
        }
    }


    //开始进行静态链接
    this->print_printList("",QObject::tr("完成目标文件编译，等待链接..."),t_proName,"",-1,PluginGlobalMsg::printIcoType::ok,QColor("green"));
    this->print_printList("",QObject::tr("开始静态链接..."),t_proName,"",-1,PluginGlobalMsg::printIcoType::tip,QColor("blue"));


    //静态链接
    t_process.close();
    t_process.setWorkingDirectory(t_attr.outPath); //设置工作目录
    t_parameterList.clear();//清空参数列表

    //若没有需要编译的文件，且启用了快速编译，则直接返回
    if(t_compileFileNum + t_compileFileNumRedirect == 0 && t_settingMsg.s21_tepOpt){
        this->print_printList("",QObject::tr("快速编译：未改动代码"),t_proName,"",-1,PluginGlobalMsg::printIcoType::tip,QColor("green"));
    }
    else{
        for(qsizetype i = 0; i<t_compileMapper.length(); i++){
            t_parameterList.append(t_attr.tempPath + "/" + t_compileMapper[i].mapperName + ".o"); //获取目标文件
        }
        t_parameterList.append("-o");
        t_parameterList.append(t_attr.programName);
        t_process.start(t_settingMsg.s4_compileMsg.fp_gpp,t_parameterList); //开始编译
        t_process.waitForReadyRead(); //等待输出
        QString t_normalPut = QString().fromLocal8Bit(t_process.readAllStandardOutput()); //读取控制台信息
        QString t_errorPut = QString().fromLocal8Bit(t_process.readAllStandardError()); //读取错误信息
        this->print_printTextSpaceLine(QColor(),t_normalPut); //输出到运行空间
        this->print_printTextSpaceLine(QColor("red"),t_errorPut);
        if(!t_errorPut.isEmpty()){
            this->print_printList("",QObject::tr("链接文件出现问题！"),t_proName,"",-1,PluginGlobalMsg::printIcoType::error,QColor("red"));
            t_process.close();
            return "";
        }
        t_process.close(); //关闭进程
    }


    //文件输出
    this->print_printList("",QObject::tr("编译完成！用时：") + QString::number(t_runTime.elapsed() / 1000,'f',3) + QObject::tr("秒"),t_proName,"",-1,PluginGlobalMsg::printIcoType::ok,QColor("green"));

    //重新保存映射缓存配置文件
    if(!t_settingMsg.s21_tepOpt){ //没有开启快速编译，则手动读取静态映射缓存文件
        t_staticCompileMappers = this->parseCompileMapper(System_File::readFile(t_compileCacheJsonPath));
    }
    QVector<MapperNode> t_outMappers = this->mergeMappers(t_compileMapper,t_staticCompileMappers); //合并映射信息
    for(MapperNode& node : t_outMappers){node.filePath.replace(proPath, "${projectPath}");} //将相对路径转换为标识符
    System_File::writeFile(t_compileCacheJsonPath,this->compileMapperToString(t_outMappers).toUtf8()); //重新写出配置文件

    return t_attr.outPath + "/" + t_attr.programName; //返回完成的程序文件路径
}


//程序开始运行
void Plugin_CppBase::event_runStarted()
{
    this->closeRunActions();
    this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::stop,true); //允许停止
    qDebug() << "程序运行开始，允许停止";
}

//程序运行完毕
void Plugin_CppBase::event_runFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    this->closeRunActions();
    this->menu_setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::run,true); //允许运行
    qDebug() << "程序停止，允许允许";
}


