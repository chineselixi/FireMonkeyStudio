#include "Form_SystemSettings.h"
#include "ui_Form_SystemSettings.h"

#include "Window/settingWindow/Form_settings_Basic.h"
#include "Window/settingWindow/Form_settings_Color.h"
#include "Window/settingWindow/Form_settings_Device.h"
#include "Window/settingWindow/Form_settings_DataBase.h"
#include "Window/settingWindow/Form_settings_Compile.h""
#include "Window/settingWindow/Form_settings_Git.h"
#include "Window/settingWindow/Form_settings_Qt.h"

Form_SystemSettings::Form_SystemSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_SystemSettings)
{
    ui->setupUi(this);
    this->addSetItem("基本设置",QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/Logo_b.png"),new Form_settings_Basic(this));
    this->addSetItem("外观",QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/color.png"),new Form_settings_Color(this));
    this->addSetItem("设备",QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/device.png"),new Form_settings_Device(this));
    this->addSetItem("数据库",QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/database.png"),new Form_settings_DataBase(this));
    this->addSetItem("编译器",QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/comple.png"),new Form_settings_Compile(this));
    this->addSetItem("git版本控制",QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/git.png"),new Form_settings_Git(this));
    this->addSetItem("Qt代码库支持",QPixmap(":/WidgetIcon/icon/WidgetIcon/setting/Qt.png"),new Form_settings_Qt(this));


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
                qDebug() << "测试" << i;
                break;
            }
        }
    });

    return t_sign.widgetIndex; //返回widget标记
}



void Form_SystemSettings::on_pushButton_ok_clicked()
{
    for(int i = 0;i < this->setMsgList.length(); i++){
        Form_settings_Basic* t_fb = (Form_settings_Basic*)this->setMsgList[i].form;
        t_fb->Event_Ok(); //执行OK事件
    }
}


void Form_SystemSettings::on_pushButton_cancel_clicked()
{
    for(int i = 0;i < this->setMsgList.length(); i++){
        Form_settings_Basic* t_fb = (Form_settings_Basic*)this->setMsgList[i].form;
        t_fb->Event_cancel(); //执行取消事件
    }
    this->close(); //关闭
}


void Form_SystemSettings::on_pushButton_use_clicked()
{
    for(int i = 0;i < this->setMsgList.length(); i++){
        Form_settings_Basic* t_fb = (Form_settings_Basic*)this->setMsgList[i].form;
        t_fb->Event_use(); //执行应用事件
    }
}

