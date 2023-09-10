


#include "Plugin_cppBasic.h"

#include "../QScintilla/src/Qsci/qsciscintilla.h"
#include "../QScintilla/src/Qsci/qscicommand.h"
#include "../QScintilla/src/Qsci/qscilexercpp.h"
#include "../QScintilla/src/Qsci/qsciapis.h"

#include "QFileInfo"





Plugin_cppBasic::Plugin_cppBasic()
{
/*
* 注意，此时内部所有指针都是nullptr，不允许调用ide能力，当event_onModLoadFinish加载完毕后相关指针与模块才加载完毕
* 注意：调用指针的时候也需要判断调用的指针是否为空指针，在某些场景下，ide内部会置空某些模块内的指针
*/
    this->self_BaseMsg.name = "C++基础功能插件";
    this->self_BaseMsg.version = "0.0.0.1 Dev";
    this->self_BaseMsg.versionNumber = 1;
    this->self_BaseMsg.sign = "FireMonkeyStudio C++";
    this->self_BaseMsg.note = "FireMenkeyStudio基础功能插件，提供基本的C++代码编辑能力！";
    this->self_BaseMsg.loadTip = "基础支持插件加载完毕，提供C++语言的基础开发功能！";
}

//获取基础的插件信息
Plugin_Base::libMsg Plugin_cppBasic::getBaseMsg()
{
    return self_BaseMsg;
}


//工作空间加载完毕
void Plugin_cppBasic::event_onWorkSpaceFinish()
{
    //工作空间加载完毕，关闭所有按钮
    WorkSpace_ToolBar_closeAllAction(); //关闭工具栏所有的可用Action
    qDebug() << "关闭全部的Action";
    //这里应该加载一个菜单
}


//工程加载完毕
bool Plugin_cppBasic::event_onPorjectLoad(QString proPath, QString proLangs, QString proNoteClass)
{
    proLangs = proLangs.toLower();
    WorkSpace_ToolBar_closeAllAction(); //关闭工具栏所有的可用Action

    if(proLangs.indexOf("c++") != -1 || proLangs.indexOf("cpp") != -1){
        WorkSpace_ToolBar_setActionEnable(PluginGlobalMsg::toolBarAction::compleMode,true); //模式选择器
        WorkSpace_ToolBar_setActionEnable(PluginGlobalMsg::toolBarAction::run,true); //运行开
        WorkSpace_ToolBar_setActionEnable(PluginGlobalMsg::toolBarAction::compile,true); //运行按钮状态
        WorkSpace_ToolBar_setActionEnable(PluginGlobalMsg::toolBarAction::staticCompile,true); //停止按钮状态
        this->isCppProject = true; //是C++工程，记录
        return false; //阻断消息传递
    }
    return true;
}


//编译模式被改变
bool Plugin_cppBasic::event_onCompileTypeChanged(PluginGlobalMsg::compileType type)
{
    if(this->isCppProject){
        this->thisCompileType = type;
        return false; //返回假，阻止消息继续投递
    }
    else{
        return true;
    }
}


//当工具栏按钮被按下
bool Plugin_cppBasic::event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction actionType, QString proPath, QString proLangs, QString proNoteClass)
{
    if(actionType == PluginGlobalMsg::toolBarAction::run){
        qDebug() << "运行被按下";
    }
    if(actionType == PluginGlobalMsg::toolBarAction::stop){
        qDebug() << "停止被按下";
    }

    return false;
}


//运行按钮被按下，注意：此函数不是重写事件
void Plugin_cppBasic::onRunDown(QString proPath, QString proLangs, QString proNoteClass)
{

}


//停止按钮被按下，注意：此函数不是重写函数
void Plugin_cppBasic::onStopDown(QString proPath, QString proLangs, QString proNoteClass)
{

}


////当文件被打开
//bool Plugin_cppBasic::event_onFileOpen(QString filePath)
//{
//    QString t_fileSuffix = QFileInfo(filePath).suffix();
//    if(t_fileSuffix == "h" || t_fileSuffix == "cpp"){
//        CodeEditor* t_codeEditor = new CodeEditor;

//        //设置关键字
//        mod_HeighLightEditor * t_heighKightMod = t_codeEditor->GetModel_HeighLight();
//        t_heighKightMod->addKeyWordMsg({"int","char","double","flat","string","void","if","else","break","for","while","do","continue","return","namespace","using","include","function"},0);
//        t_heighKightMod->addKeyWordMsg({"main","NULL"},1);


//        //设置颜色
//        QTextCharFormat t_format;
//        t_format.setForeground(QColor(0, 0, 255));
//        t_heighKightMod->SetKeyWordFormat(mod_HeighLightEditor::KeyWord1,t_format);
//        t_format.setForeground(QColor(255, 0, 0));
//        t_heighKightMod->SetKeyWordFormat(mod_HeighLightEditor::KeyWord2,t_format);
//        t_format.setForeground(QColor(0, 161, 0));
//        t_heighKightMod->SetKeyWordFormat(mod_HeighLightEditor::String,t_format);
//        t_format.setForeground(QColor(26, 26, 255));
//        t_heighKightMod->SetKeyWordFormat(mod_HeighLightEditor::Sign,t_format);
//        t_format.setForeground(QColor(12, 134, 12));
//        t_heighKightMod->SetKeyWordFormat(mod_HeighLightEditor::Note,t_format);

//        //设置字体
//        t_codeEditor->setFont(QFont("Consolas",16));
//        t_codeEditor->SetLineFont(QFont("Consolas",16));

//        //载入文件
//        QFile t_file(filePath); //读取文件并且载入IDE的
//        t_file.open(QIODevice::ReadOnly);
//        t_codeEditor->appendPlainText(t_file.readAll());
//        t_file.close();

//        //将代码编辑器窗口添加到Tab
//        this->WorkSpace_addTabWindow(QFileInfo(filePath).fileName(),t_codeEditor,filePath,QIcon(":/fileIcon/icon/fileIcon/Namespace_16x.png"),PluginGlobalMsg::TabType::codeEditor);

//        return false;//阻止继续的事件激发
//    }
//    return true; //不满足条件，则允许插件管理器继续激发其他插件的事件
//}

