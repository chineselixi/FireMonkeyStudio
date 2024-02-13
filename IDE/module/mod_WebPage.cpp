#include "mod_WebPage.h"
#include "QWebChannel"
#include "QMessageBox"
#include "../SwSystem/System_GlobalVar.h"
#include "../Window/Form_WorkSpace.h"
#include "SwSystem/System_History.h"


mod_WebPage::mod_WebPage(QWidget *parent):QWebEngineView(parent)
{
    QWebChannel* t_channel = new QWebChannel(this);
    cppObject* cppObj = new cppObject(t_channel,this->page());
    t_channel->registerObject(QStringLiteral("cppObj"), cppObj);
    this->page()->setWebChannel(t_channel); //设置自定义函数渠道
}





//初始化，加载完成
cppObject::cppObject(QWebChannel *t_channel,QWebEnginePage* t_page)
    :Channel(t_channel),Page(t_page)
{
    //加载主题
    Page->runJavaScript("changeTheme('" + Setting::style_themeName + "')");
}


//初始化，加载完成
void cppObject::event_onLoad()
{
    //Page->runJavaScript("abc()");
    //添加真实工程历史到列表
    QVector<System_History::HistoryMsg> t_list = HistoryList::sys_proHistory->getHisList();//获取历史列表
    for(auto vlaue : t_list){
        QString t_str = QString("addProjectNode('%1','%2','%3')").arg(vlaue.showIco,vlaue.showName,vlaue.filePath);
        Page->runJavaScript(t_str);
    }
    Page->runJavaScript("showProjectList()");


    //加载主题
    Page->runJavaScript("changeTheme('" + Setting::style_themeName + "')");
}

//删除单个记录
void cppObject::event_onCloseSign(QString sign)
{
    HistoryList::sys_proHistory->removeProHisList(sign);
    HistoryList::sys_proHistory->saveHisList(); //保存记录
}

//删除全部记录
void cppObject::event_onClcloseAllSign()
{
    HistoryList::sys_proHistory->clearRepeat();
    HistoryList::sys_proHistory->saveHisList();
}


//新建
void cppObject::event_onNew()
{
    if(Window::workSpace != nullptr)
    Window::workSpace->on_action_file_newCreate_triggered();
}


//打开工程
void cppObject::event_onOpen()
{
    if(Window::workSpace != nullptr)
    Window::workSpace->on_action_file_open_triggered();
}

//源码商城
void cppObject::event_onSourceCodeMall()
{
    QMessageBox::warning(Window::workSpace,tr("未开放"),tr("源码商城在此版本中不受支持，请更新到最新版本！"));
}


//打开设置窗口
void cppObject::event_onSetting()
{
    if(Window::workSpace != nullptr)
    Window::workSpace->on_action_systemSettings_triggered();
}
