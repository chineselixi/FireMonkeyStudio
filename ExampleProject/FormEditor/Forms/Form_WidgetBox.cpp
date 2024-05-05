#include "QDir"
#include "QFileInfo"

#include "GlobalMsg.h"
#include "Form_WidgetBox.h"
#include "ui_Form_WidgetBox.h"
#include "Widgets/Widget_Button_WidgetItem.h"


#include "Plugins/Plugin_MainWindow.h"
#include "Plugins/Plugin_Button.h"
#include "Plugins/Plugin_Label.h"
#include "Plugins/Plugin_TabWidget.h"


Form_WidgetBox::Form_WidgetBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_WidgetBox)
{
    ui->setupUi(this);
    Form::widgetBoxPtr = this;

    this->List_widgetPlg.append({
        nullptr,
        this->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Cursor_16x.png"),"指针","此选项不包含任何控件")
    });

    this->addPlguin(new Plugin_Label);
    this->addPlguin(new Plugin_TabWidget);
    this->addPlguin(new Plugin_Button);
    this->addPlguin(new Plugin_MainWindow);


    //ui->listWidget->setViewMode(QListWidget::ViewMode::IconMode); //图像模式
    //ui->listWidget->setResizeMode(QListView::Adjust); //自动对其
}

Form_WidgetBox::~Form_WidgetBox()
{
    delete ui;
    Form::widgetBoxPtr = nullptr;
}


//添加插件信息
void Form_WidgetBox::addPlguin(Plugin_Base *plg)
{
    //已经添加过的插件就不要重复添加了
    for(widgetPluginMsg item : List_widgetPlg){
        if(item.plg == plg){
            return;
        }
    }

    widgetPluginMsg t_plgMsg;
    t_plgMsg.plg = plg;
    t_plgMsg.widgetItem = this->addItem(plg->pluginIco,plg->pluginTitle,plg->pluginTip);
    this->List_widgetPlg.append(t_plgMsg);
}


//根据sign查找插件
Plugin_Base *Form_WidgetBox::findPluginBySign(QString sign)
{
    for(widgetPluginMsg item : List_widgetPlg){
        if(item.plg != nullptr && item.plg->pluginSign == sign){
            return item.plg;
        }
    }
    return nullptr;
}


QSize Form_WidgetBox::sizeHint() const
{
    return QSize(180, 900); /* 在这里定义dock的初始大小 */
}



//查找寻找插件文件
void Form_WidgetBox::findPlugin(QString path, QVector<QString> &retFiles, QString plgSuffix)
{
    QDir t_dir(path);
    if(!t_dir.exists()) return;
    QFileInfoList t_infoListDir = t_dir.entryInfoList(QDir::Dirs|QDir::NoDotAndDotDot); //只检查有多少目录
    for(int a = 0;a<t_infoListDir.length();a++){
        if(t_infoListDir[a].exists()){
            QDir t_dirFiles(t_infoListDir[a].filePath());
            QFileInfoList t_infoListFile = t_dirFiles.entryInfoList(QDir::Files|QDir::NoDotAndDotDot); //只检查有多少文件
            for(int b = 0;b<t_infoListFile.length();b++){
                if(t_infoListFile[b].isFile() && t_infoListFile[b].suffix() == plgSuffix){ //判断是否为工程模板文件
                    retFiles.append(t_infoListFile[b].absoluteFilePath());
                }
            }
        }
    }
}





//添加项目
QListWidgetItem* Form_WidgetBox::addItem(QPixmap pixmap, QString title, QString sign)
{
    QListWidgetItem* t_item = new QListWidgetItem(ui->listWidget);
    Widget_Button_WidgetItem* t_widget = new Widget_Button_WidgetItem(pixmap,title,sign,ui->listWidget);
    t_item->setSizeHint(QSize(150,32));
    t_item->setToolTip(sign);
    ui->listWidget->addItem(t_item);
    ui->listWidget->setItemWidget(t_item,t_widget);
    return t_item;
}


//Item被点击,改变了当前的插件
void Form_WidgetBox::on_listWidget_itemClicked(QListWidgetItem *item)
{
    Plugin::nowSelectPlugin = nullptr;
    for(widgetPluginMsg wMsgItem : List_widgetPlg){
        if(wMsgItem.widgetItem == item){
            Plugin::nowSelectPlugin = wMsgItem.plg;
            break;
        }
    }
    this->onPluginSelectChanged(Plugin::nowSelectPlugin);
}

