#include "Form_PluginManger.h"
#include "ui_Form_PluginManger.h"

#include "SwSystem/System_GlobalVar.h"
#include "SwSystem/System_History.h"
#include "SwSystem/System_UtilFun.h"

#include "Plugin/Plugin_Manger.h"



#include "QFile"
#include "QFileInfo"

#include "Widget/Widget_Button_PluginItem.h"



Form_PluginManger::Form_PluginManger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_PluginManger)
{
    ui->setupUi(this);

    QVector<Plugin_Manger::PluginMsg> t_pluginList = Manger::pluginManger->getPluginList(); //获取插件列表
    for(int a = 0;a<t_pluginList.length();a++){
        QListWidgetItem* listItem = new QListWidgetItem(ui->listWidget_plugin);
        Widget_Button_PluginItem* itemWidget = new Widget_Button_PluginItem(ui->listWidget_plugin);
        QString t_note = "";
        QString t_filePath = t_pluginList[a].filePath;

        //加载信息
        QFileInfo t_fileInfo(t_pluginList[a].filePath);
        QString t_icoPath = t_pluginList[a].filePath.left(t_pluginList[a].filePath.length() - t_fileInfo.suffix().length() - 1) + ".png";
        if(!QFileInfo(t_icoPath).exists()){
            t_icoPath = ":/WidgetIcon/icon/WidgetIcon/plugin/pluginNormal.png"; //图标不存在则使用默认图标
        }
        itemWidget->SetIcon(QPixmap(t_icoPath));

        if(t_pluginList[a].plgPth != nullptr){ //如果插件载入，则使用插件载入的信息
            Plugin_Base::libMsg t_plgMsg = t_pluginList[a].plgPth->getBaseMsg();
            itemWidget->SetTitle(t_plgMsg.name);
            itemWidget->SetFilePathTip(t_pluginList[a].filePath);
            itemWidget->SetPluginSign(t_plgMsg.sign);
            itemWidget->SetPluginVerTip(t_plgMsg.version);
            t_note = t_plgMsg.note;
            itemWidget->SetEnableStyle(true); //设置启用主题
        }
        else{ //没有载入的插件
            QFileInfo t_fileInfo(t_pluginList[a].filePath);
            itemWidget->SetTitle(t_fileInfo.baseName());
            itemWidget->SetFilePathTip(t_fileInfo.absoluteFilePath());
            itemWidget->SetPluginSign(tr("未加载"));
            itemWidget->SetPluginVerTip("");
            t_note = tr("ide未加载此插件，启用插件后需要重启IDE才能够正常加载。若加载失败，请与插件开发者联系。");
            itemWidget->SetEnableStyle(false); //设置禁用主题
        }

        ui->listWidget_plugin->addItem(listItem);
        listItem->setSizeHint(QSize(100,62));
        ui->listWidget_plugin->setItemWidget(listItem,itemWidget);

        //插件列表被点击
        connect(itemWidget,&Widget_Button_PluginItem::event_onDown,[this,t_note](){
            ui->label_signTip->setText(t_note);
        });

        //插件启用与禁用
        connect(itemWidget,&Widget_Button_PluginItem::event_onPluginEnable,[this,t_filePath](bool enable){
            //t_filePath.

            QString t_path = t_filePath;
            t_path = t_path.replace(System_OS::getaApplicationDirPath_EX(),"<pluginPath>");
            if(enable){
               HistoryList::sys_pluginHistory->addMsg("","",t_path,"");
            }
            else{
               HistoryList::sys_pluginHistory->removeProHisList(t_path);
            }
            HistoryList::sys_pluginHistory->clearRepeat(); //清楚重复
            HistoryList::sys_pluginHistory->saveHisList(); //保存历史记录
        });

        //插件卸载
        connect(itemWidget,&Widget_Button_PluginItem::event_onPluginUnload,[this](){


        });



    }













}

Form_PluginManger::~Form_PluginManger()
{
    delete ui;
}
