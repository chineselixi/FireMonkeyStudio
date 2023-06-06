
#include "Plugin_ideBasic.h"
#include "QFileInfo"

Plugin_ideBasic::Plugin_ideBasic()
{
/*
* 注意，此时内部所有指针都是nullptr，不允许调用ide能力，当event_onModLoadFinish加载完毕后相关指针与模块才加载完毕
* 注意：调用指针的时候也需要判断调用的指针是否为空指针，在某些场景下，ide内部会置空某些模块内的指针
*/
    this->self_BaseMsg.name = "C++代码编辑插件";
    this->self_BaseMsg.version = "0.0.0.1 Dev";
    this->self_BaseMsg.versionNumber = 1;
    this->self_BaseMsg.sign = "FireMonkeyStudio C++";
    this->self_BaseMsg.note = "FireMenkeyStudio基础功能插件，提供基本的C++代码编辑能力！";
    this->self_BaseMsg.loadTip = "基础支持插件加载完毕，提供C++代码编辑能力！";
}

//获取基础的插件信息
Plugin_Base::libMsg Plugin_ideBasic::getBaseMsg()
{
    return self_BaseMsg;
}


//工作空间加载完毕
void Plugin_ideBasic::event_onWorkSpaceFinish()
{
//    QAction* t_act = new QAction;
//    t_act->setText("基础插件测试");

//    QWidget::connect(t_act, &QAction::triggered,[](){
//        qDebug() << "插件菜单测试，插件事件输出完成";
//    });

//    this->WorkSpace_AddMenu_ToolBar_Extend(t_act); //添加到工具栏
}


//当文件被打开
bool Plugin_ideBasic::event_onFileOpen(QString filePath)
{
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
    return true; //不满足条件，则允许插件管理器继续激发其他插件的事件
}

