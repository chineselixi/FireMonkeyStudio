﻿#include "Form_WindowTab.h"
#include "ui_Form_WindowTab.h"
#include "QGridLayout"

#include "QMenu"
#include "QFileInfo"
#include "../SwSystem/System_GlobalVar.h"
#include "../Plugin/Plugin_Manger.h"
#include "../Plugin/Plugin_CodeEditorInterface.h"
#include "../Window/Form_WorkSpace.h"
#include "../Window/Form_WindowTab.h"

Form_WindowTab::Form_WindowTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_WindowTab)
{
    ui->setupUi(this);

    //保存管理器
    Manger::workspace_winTabManger = this;

    //删除自身的信息，本类存在预览选项卡
    for (int i = ui->tabWidget->count() - 1; i >= 0; i--)
    {
        QWidget *page = ui->tabWidget->widget(i);
        ui->tabWidget->removeTab(i);  // 删除选项卡
        delete page;      // 删除子窗口
    }

    //初始化Tab到插件管理器
    PluginGlobalMsg::addTabViewPth t_addTab =
        [this](void* plg, QString title, QWidget *form, QString sign, QIcon titeIco,PluginGlobalMsg::TabType type,bool autoMangement)
    {this->addTabWidget((Plugin_Base*)plg,title,form,sign,titeIco,true,type,autoMangement);};

    PluginGlobalMsg::tab_hasTab_Sign t_hasTabSign = [this](QString sign,bool select){return this->hasTabMsg(sign,select);};
    PluginGlobalMsg::tab_hasTab_WidgetPtr t_hasTabWidget = [this](QWidget* widget,bool select){return this->hasTabMsg(widget,select);};
    PluginGlobalMsg::tab_getSign t_getSign = [this](QWidget* widget){return this->getMsg(widget).signText;};
    PluginGlobalMsg::tab_getWidget t_getWidget = [this](QString sign){return this->getMsg(sign).formPtr;};
    PluginGlobalMsg::tab_getNowWidget t_getNowWidget = [this](){return this->getTopTabMsg().formPtr;};
    PluginGlobalMsg::tab_getNowSign t_getNowSign = [this](){return this->getTopTabMsg().signText;};
    if(Manger::pluginManger) Manger::pluginManger->TabSpace_init_tabView(t_addTab,t_getSign,t_getWidget,t_hasTabSign,t_hasTabWidget,t_getNowWidget,t_getNowSign); //初始化函数指针
}

Form_WindowTab::~Form_WindowTab()
{
    delete ui;
    Manger::workspace_winTabManger = nullptr;
    if(Manger::pluginManger) Manger::pluginManger->TabSpace_init_tabView(nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr); //置空指针
}


//添加窗体到Tab
void Form_WindowTab::addTabWidget(Plugin_Base* plg,QString title, QWidget *form, QString sign, QIcon titeIco, bool select, PluginGlobalMsg::TabType type,bool autoMangement)
{
    QWidget* t_tab = new QWidget(ui->tabWidget);
    QHBoxLayout* t_layout = new QHBoxLayout(t_tab);
    t_layout->setContentsMargins(0,0,0,0); //设置布局边距
    t_layout->setSpacing(0); //设置组件的间距
    t_layout->addWidget(form);
    t_tab->setLayout(t_layout);
    int t_index = ui->tabWidget->addTab(t_tab,titeIco,title);
    this->tabMsgList.append({title,sign,form,t_tab,plg,type,autoMangement}); //添加信息到列表
    if(select) ui->tabWidget->setCurrentIndex(t_index); //把当前窗口提升
}

bool Form_WindowTab::removeTabMsg(QWidget *form)
{
    for(int a = 0;a<this->tabMsgList.length();a++){
        if(this->tabMsgList[a].formPtr == form || this->tabMsgList[a].tabWidgetPtr == form){
            this->tabMsgList.removeAt(a); //删除信息
            return true;
        }
    }
    return false;
}

//根据widget指针标记删除列表信息
bool Form_WindowTab::removeTabMsg(QString sign)
{
    for(int a = 0;a<this->tabMsgList.length();a++){
        if(this->tabMsgList[a].signText == sign){
            this->tabMsgList.removeAt(a); //删除信息
            return true;
        }
    }
    return false;
}

//根据标记更改信息
bool Form_WindowTab::resetTabMsg(QString oldSign, tabMsg newMsg)
{
    for(int a = 0;a<this->tabMsgList.length();a++){
        if(this->tabMsgList[a].signText == oldSign){
            this->tabMsgList[a] = newMsg; //删除信息
            return true;
        }
    }
    return false;
}

//根据窗体指针更改信息
bool Form_WindowTab::resetTabMsg(QWidget *oldWidget, tabMsg newMsg)
{
    for(int a = 0;a<this->tabMsgList.length();a++){
        if(this->tabMsgList[a].formPtr == oldWidget){
            this->tabMsgList[a] = newMsg; //删除信息
            return true;
        }
    }
    return false;
}


//根据标记查看TAB是否已经存在
bool Form_WindowTab::hasTabMsg(QString sign,bool select)
{
    for(int a = 0;a<this->tabMsgList.length();a++){ //检查是否已经存在这个Tab窗体
        if(this->tabMsgList[a].signText == sign){
            if(select) ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(this->tabMsgList[a].tabWidgetPtr));
            return true;
        }
    }
    return false;
}


//根据Widgte指针查看TAB是否已经存在
bool Form_WindowTab::hasTabMsg(QWidget *widget,bool select)
{
    for(int a = 0;a<this->tabMsgList.length();a++){ //检查是否已经存在这个Tab窗体
        if(this->tabMsgList[a].formPtr == widget || this->tabMsgList[a].tabWidgetPtr == widget){
            if(select) ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(this->tabMsgList[a].tabWidgetPtr));
            return true;
        }
    }
    return false;
}








//根据标记获取信息
Form_WindowTab::tabMsg Form_WindowTab::getMsg(QString sign)
{
    tabMsg t_msg;
    for(int a = 0;a<this->tabMsgList.length();a++){
        if(this->tabMsgList[a].signText == sign){
            t_msg = this->tabMsgList[a]; //删除信息
            break;
        }
    }
    return t_msg;
}

//根据窗体指针获取信息
Form_WindowTab::tabMsg Form_WindowTab::getMsg(QWidget *widget)
{
    tabMsg t_msg;
    for(int a = 0;a<this->tabMsgList.length();a++){
        if(this->tabMsgList[a].formPtr == widget){
            t_msg = this->tabMsgList[a]; //删除信息
            break;
        }
    }
    return t_msg;
}


//获取当前顶部选项卡的标记
QString Form_WindowTab::getTopTabSign()
{
    return getTopTabMsg().signText;
}


//保存所有代码文本
void Form_WindowTab::saveAllCode()
{
    for(int a = 0;a<this->tabMsgList.length();a++){
        Plugin_CodeEditorInterface* t_cei = dynamic_cast<Plugin_CodeEditorInterface*>(this->tabMsgList[a].formPtr);
        if(t_cei != nullptr){
            t_cei->onSave(); //保存
        }
    }
}


//获取当前顶部选项卡信息
Form_WindowTab::tabMsg Form_WindowTab::getTopTabMsg()
{
    QWidget* t_widget = ui->tabWidget->currentWidget();
    for(int a = 0;a<this->tabMsgList.length();a++){
        if(this->tabMsgList[a].tabWidgetPtr == t_widget){
            return this->tabMsgList[a];
        }
    }
    return tabMsg();
}


 //这个方法是给WorkSpace，用于自动更改标题与标记文本
void Form_WindowTab::autoMangerment(QString oldPath, QString newPath)
{
    for(int a = 0;a<this->tabMsgList.length();a++){
        if(this->tabMsgList[a].autoMangement && this->tabMsgList[a].signText == oldPath){
            if(QFileInfo(newPath).exists()){
                int t_index = ui->tabWidget->indexOf(this->tabMsgList[a].tabWidgetPtr);
                QString t_newName = QFileInfo(newPath).fileName();

                this->tabMsgList[a].signText = newPath;
                this->tabMsgList[a].tabWidgetPtr->setWindowTitle(t_newName);
                ui->tabWidget->setTabText(t_index,t_newName);

                Plugin_CodeEditorInterface* iface = dynamic_cast<Plugin_CodeEditorInterface*>(this->tabMsgList[a].formPtr);
                if(iface) iface->event_onFilePathChanged(newPath);
            }
            break;
        }
    }
}


//当前窗体已关闭
void Form_WindowTab::on_tabWidget_tabCloseRequested(int index)
{
    QWidget* t_widget = ui->tabWidget->widget(index);
    for(int a = 0;a<this->tabMsgList.length();a++){   //查找当前关闭的窗口
        if(this->tabMsgList[a].tabWidgetPtr == t_widget && this->tabMsgList[a].plg != nullptr){
            if(this->tabMsgList[a].plg->event_onTabFormCloseRequested(t_widget) == false){  //激发插件的关闭事件。让用户确定，是否关闭此窗口
                return;
            }
            break;
        }
    }

    this->removeTabMsg(t_widget);
    ui->tabWidget->removeTab(index); //会关闭子内嵌窗口
    delete t_widget;
}


//当前窗体已切换
void Form_WindowTab::on_tabWidget_currentChanged(int index)
{
    QWidget* t_widget = ui->tabWidget->widget(index);
    for(int a = 0;a<this->tabMsgList.length();a++){   //查找当前关闭的窗口
        if(this->tabMsgList[a].tabWidgetPtr == t_widget && this->tabMsgList[a].plg != nullptr){
            //唤醒插件信息
            this->tabMsgList[a].plg->event_onTabFormActivation(this->tabMsgList[a].formPtr); //激发插件的窗体切换事件
            //判断是否为代码编辑器类型，用于激活编辑菜单
            if(this->tabMsgList[a].type == PluginGlobalMsg::TabType::codeEditor){
                Window::workSpace->getEditorMenu()->setEnabled(true);
            }
            else{
                Window::workSpace->getEditorMenu()->setEnabled(false);
            }
            break;
        }
    }
}

