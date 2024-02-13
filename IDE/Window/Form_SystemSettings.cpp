#include "Form_SystemSettings.h"
#include "ui_Form_SystemSettings.h"

#include "Window/settingWindow/Form_settings_Basic.h"
#include "Window/settingWindow/Form_settings_Color.h"
#include "Window/settingWindow/Form_settings_Device.h"
#include "Window/settingWindow/Form_settings_DataBase.h"
#include "Window/settingWindow/Form_settings_Git.h"
#include "Window/settingWindow/Form_settings_Qt.h"

#include "SwSystem/System_GlobalVar.h"
#include "SwSystem/System_Systemsetting.h"
#include "SwSystem/System_CodeEditorManger.h"
#include "Window/Form_WorkSpace.h"
#include "Plugin/Plugin_Manger.h"

Form_SystemSettings::Form_SystemSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_SystemSettings)
{
    ui->setupUi(this);
    this->addSetItem("基本设置",QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/Logo_b.png"),new Form_settings_Basic(this));
    this->addSetItem("外观",QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/color.png"),new Form_settings_Color(this));
    this->addSetItem("设备",QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/device.png"),new Form_settings_Device(this));
    this->addSetItem("数据库",QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/database.png"),new Form_settings_DataBase(this));
    this->addSetItem("git版本控制",QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/git.png"),new Form_settings_Git(this));
    this->addSetItem("Qt代码库支持",QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/Qt.png"),new Form_settings_Qt(this));


    //加载第三方设置控件
    Plugin_Base::settingMsgList t_widgetList = Manger::pluginManger->getSettingWidgets();
    for(Plugin_Base::settingMsgList::iterator i = t_widgetList.begin(); i < t_widgetList.end(); i++){
        this->addSetItem(i->title,i->ico_32px,i->settingWidget);
    }

    //选择第一个设置
    this->ui->label_title->setText(this->setMsgList[0].btn_sign->GetTitle());
    this->ui->stackedWidget->setCurrentIndex(setMsgList[0].widgetIndex);
}

Form_SystemSettings::~Form_SystemSettings()
{
    delete ui;
}


//将Widget添加到设置项
int Form_SystemSettings::addSetItem(QString title, QPixmap pixmap, QWidget *widget)
{
    if(widget == nullptr) return -1;
    Widget_Button_WidgetItem* t_btnPtr = new Widget_Button_WidgetItem(this);
    t_btnPtr->SetIcon(pixmap,QSize(16,16));
    t_btnPtr->SetTitle(title);
    QListWidgetItem* t_item = new QListWidgetItem(ui->listWidget);
    t_item->setSizeHint(QSize(198,32));
    ui->listWidget->addItem(t_item);
    ui->listWidget->setItemWidget(t_item,t_btnPtr);
    set_sign t_sign = {t_btnPtr,t_item,widget,ui->stackedWidget->addWidget(widget)};
    this->setMsgList.append(t_sign);

    connect(ui->listWidget,&QListWidget::itemClicked,[this](QListWidgetItem * item){
        for(int i = 0;i < setMsgList.length();i++){
            if(setMsgList[i].listWidget == item){
                this->ui->label_title->setText(this->setMsgList[i].btn_sign->GetTitle());
                this->ui->stackedWidget->setCurrentIndex(setMsgList[i].widgetIndex);
                break;
            }
        }
    });
    return t_sign.widgetIndex; //返回widget标记
}


//确认被按下，（执行顺序：应用->确认->取消）
void Form_SystemSettings::on_pushButton_ok_clicked()
{
    this->on_pushButton_use_clicked(); //率先执行应用后确认
    for(int i = 0;i < this->setMsgList.length(); i++){
        Form_settings_Basic* t_fb = (Form_settings_Basic*)this->setMsgList[i].form;
        t_fb->Event_Ok(); //执行OK事件
    }
    this->on_pushButton_cancel_clicked();
}

//取消被按下
void Form_SystemSettings::on_pushButton_cancel_clicked()
{
    for(int i = 0;i < this->setMsgList.length(); i++){
        Form_settings_Basic* t_fb = (Form_settings_Basic*)this->setMsgList[i].form;
        t_fb->Event_cancel(); //执行取消事件
    }
    this->close(); //关闭
}

//应用被按下
void Form_SystemSettings::on_pushButton_use_clicked()
{
    for(int i = 0;i < this->setMsgList.length(); i++){
        Form_settings_Basic* t_fb = (Form_settings_Basic*)this->setMsgList[i].form;
        t_fb->Event_use(); //执行应用事件
    }
}





//改变主题
void Form_SystemSettings::changeThream(QString styleName)
{
    Setting::style_themeName = styleName;
    if(Window::workSpace != nullptr){
        //加载其他部件的QSS样式表
        Setting::sys_app->setStyleSheet(Setting::sys_setting->readThemeStyle(styleName,"NormalStyle"));
        Window::workSpace->setStyleSheet(Setting::sys_setting->readThemeStyle(styleName,"Form_WorkSpace")); //加载工作空间样式表
        Window::workSpace->setPorMangerStyle(Setting::sys_setting->readThemeStyle(styleName,"Form_ProjectManger")); //加载工程管理样式表
        Window::workSpace->setCompilePrintStyle(Setting::sys_setting->readThemeStyle(styleName,"Form_ListPrint")); //加载编译样式表
        Window::workSpace->setPrintStyle(Setting::sys_setting->readThemeStyle(styleName,"Form_TextPrint")); //加载文本打印样式表
        Window::workSpace->setTipMangerStyle(Setting::sys_setting->readThemeStyle(styleName,"Form_TipManger")); //加载通知管理器样式表

        //设定选项样式
        Window::workSpace->setTheme(styleName);

        //加载主题不同的图片
        QFile t_themeFile(":/resFile/res/ThemeTemplate.txt"); //加载本地图标信息模板，并且替换模板信息
        t_themeFile.open(QIODevice::ReadOnly);
        QString t_themeTemplateStr = t_themeFile.readAll();
        t_themeTemplateStr.replace("${theme}",styleName);
        t_themeFile.close();

        //检索工作空间窗体的所有子Action，并且加载样式表
        QList<QAction*> t_al = Window::workSpace->findChildren<QAction*>();
        for(QList<QAction*>::Iterator t_i = t_al.begin();t_i < t_al.end();t_i++){
            if((*t_i)->objectName().isEmpty()) continue; //未命名的Action则跳过
            QString t_nor = Str::getSubStr(t_themeTemplateStr,(*t_i)->objectName() + "::Normal=","\r");
            QString t_dis = Str::getSubStr(t_themeTemplateStr,(*t_i)->objectName() + "::Disabled=","\r");
            QIcon t_ico = (*t_i)->icon();
            t_ico.addFile(t_nor, QSize(), QIcon::Normal, QIcon::Off);
            t_ico.addFile(t_dis, QSize(), QIcon::Disabled, QIcon::Off);
            (*t_i)->setIcon(t_ico); //设置新图标
        }

        //插件管理器通知事件改变
        if(Manger::pluginManger != nullptr) Manger::pluginManger->event_onThemeChanged(styleName);

        if(Manger::codeEditorManger != nullptr) Manger::codeEditorManger->tipEvent_onThemeChange(styleName);
    }
}
