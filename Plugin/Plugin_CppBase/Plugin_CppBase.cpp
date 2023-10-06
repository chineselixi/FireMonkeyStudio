#include "Plugin_CppBase.h"

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
    proLangs = proLangs.toLower();
    if(proLangs.indexOf("cpp") != -1){



        return false; //阻止消息传递
    }
    return true;
}
