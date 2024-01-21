#include "Plugin_IdeBase.h"

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
}


bool Plugin_IdeBase::event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction actionType, QString proPath, QString proLangs, QString proNoteClass)
{
    if(actionType == PluginGlobalMsg::toolBarAction::bookmarkMainMenuTabitem){
        Dialog_Index* di = new Dialog_Index();
        di->show();
    }
    return true; //阻止消息传递
}

