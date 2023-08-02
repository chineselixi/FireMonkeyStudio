#include "Form_settings_Git.h"
#include "ui_Form_settings_Git.h"
#include "SwSystem/System_GlobalVar.h"
#include "SwSystem/system_systemsetting.h"

Form_settings_Git::Form_settings_Git(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_settings_Git)
{
    ui->setupUi(this);
    this->Init();

    process = new QProcess;
}

Form_settings_Git::~Form_settings_Git()
{
    delete ui;
    delete process;
}

void Form_settings_Git::Init()
{
    //静态加载
    Form_settings_Git::loadSettings();


    //初始化Path
    ui->lineEdit_gitPath->setText(Setting::git_path);
    ui->lineEdit_master->setText(Setting::git_branch);//读取branch


    ui->checkBox_track->setChecked(Setting::git_track);
    ui->checkBox_outMsg->setChecked(Setting::git_outMsg);
    ui->checkBox_pushAddDate->setChecked(Setting::git_pushAddDate);
}


//静态加载设置
void Form_settings_Git::loadSettings()
{
    //初始化Path
    Setting::git_path = Setting::sys_setting->getSettingValue("Git","path").toString(); //读取GitPath
    Setting::git_branch = Setting::sys_setting->getSettingValue("Git","branch").toString(); //读取branch

    Setting::git_track = Setting::sys_setting->getSettingValue("Git","track").toBool(); //读取
    Setting::git_outMsg = Setting::sys_setting->getSettingValue("Git","outMsg").toBool(); //读取
    Setting::git_pushAddDate = Setting::sys_setting->getSettingValue("Git","pushAddDate").toBool(); //读取

}



void Form_settings_Git::Event_use()
{
    Setting::git_path = ui->lineEdit_gitPath->text();
    Setting::sys_setting->changeSetting("Git","path",ui->lineEdit_gitPath->text()); //保存gitPth

    Setting::git_branch = ui->lineEdit_master->text();
    Setting::sys_setting->changeSetting("Git","branch",ui->lineEdit_master->text()); //保存分支

    Setting::git_track = (ui->checkBox_track->checkState() == 2); //git自动跟踪
    Setting::sys_setting->changeSetting("Git","track",Setting::git_track); //保存track

    Setting::git_pushAddDate = (ui->checkBox_pushAddDate->checkState() == 2); //git添加日期
    Setting::sys_setting->changeSetting("Git","pushAddDate",Setting::git_pushAddDate); //保存添加日期

    Setting::git_outMsg = (ui->checkBox_outMsg->checkState() == 2); //git输出日志
    Setting::sys_setting->changeSetting("Git","outMsg",Setting::git_outMsg); //保存输出日志

}

void Form_settings_Git::Event_Ok()
{

}

void Form_settings_Git::Event_cancel()
{
    return;
}


