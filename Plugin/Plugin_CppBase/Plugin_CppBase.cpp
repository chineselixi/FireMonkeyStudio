#include "Plugin_CppBase.h"
#include "QFile"
#include "QFileInfo"
#include "QMessageBox"
#include "../../QScintilla/src/Qsci/qsciscintilla.h" //注意，这里是外部的QSciscintilla库，引入此文件需要在Pro文件中静态对应的dll与lib
#include "Form/Form_CodeEditor.h"

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
    qDebug() << proPath << proLangs << proNoteClass;
    proLangs = proLangs.toLower();
    if(proLangs.indexOf("c++") != -1){
        this->closeWorkSpaceAllAction(); //关闭所有ACTION
        this->setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::run,true); //允许运行
        this->setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::compile,true); //允许编译
        this->setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::staticCompile,true); //允许静态编译
        this->setWorkSpaceActionEnable(PluginGlobalMsg::toolBarAction::onlineCompile,true); //允许在线编译
        return false; //阻止消息传递
    }
    return true;
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


//判断是否拥有这个后缀
bool Plugin_CppBase::stringRight(QString str, QString suffix)
{
    if(str.right(suffix.length()) != suffix){
        return false;
    }
    return true;
}
