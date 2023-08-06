#include "QFile"
#include "QFileDialog"

#include "Form_settings_Git.h"
#include "ui_Form_settings_Git.h"
#include "SwSystem/System_GlobalVar.h"
#include "SwSystem/system_systemsetting.h"
#include "SwSystem/System_EnvVar.h"

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
    ui->lineEdit_gitPath->setText(Setting::git_path);//读取GitPath路径信息
    ui->lineEdit_master->setText(Setting::git_branch);//读取branch

    //将变量信息添加到界面
    ui->checkBox_track->setChecked(Setting::git_track); //自动跟踪
    ui->checkBox_outMsg->setChecked(Setting::git_outMsg); //输出信息
    ui->checkBox_pushAddDate->setChecked(Setting::git_pushAddDate); //添加日期


    //判断环境变量中是否已经存在Git
    if(Setting::git_path.isEmpty()){
        Setting::git_path = Manger::EnvVar->getProgramPathForEnvVar("git"); //获取git的路径
    }

    //测试Git是否存在
    this->on_btn_test_clicked();
}


//静态加载设置
void Form_settings_Git::loadSettings()
{
    //初始化Path
    Setting::git_path = Setting::sys_setting->getSettingValue("Git","path").toString(); //读取GitPath路径信息
    Setting::git_branch = Setting::sys_setting->getSettingValue("Git","branch").toString(); //读取branch信息

    Setting::git_track = Setting::sys_setting->getSettingValue("Git","track").toBool(); //自动跟踪
    Setting::git_outMsg = Setting::sys_setting->getSettingValue("Git","outMsg").toBool(); //输出信息
    Setting::git_pushAddDate = Setting::sys_setting->getSettingValue("Git","pushAddDate").toBool(); //添加日期

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


    //保存用户设置
    QProcess t_process;
    t_process.start(Setting::git_path,{"config","--global","user.name",ui->lineEdit_userName->text()}); //保存用户名
    t_process.waitForFinished();
    t_process.start(Setting::git_path,{"config","--global","user.email",ui->lineEdit_email->text()}); //保存邮箱
    t_process.waitForFinished();
    t_process.start(Setting::git_path,{"config","--global","user.password",ui->lineEdit_psw->text()}); //保存密码
    t_process.waitForFinished();
}

void Form_settings_Git::Event_Ok()
{
    return;
}

void Form_settings_Git::Event_cancel()
{
    return;
}


//选择路径
void Form_settings_Git::on_btn_select_clicked()
{//QFileDialog::getExistingDirectory(this, tr("选择Git目录"), Setting::git_path, QFileDialog::ShowDirsOnly);
    QString t_dirpath = QFileDialog::getOpenFileName(this,tr("文件对话框！"),Setting::git_path);
    ui->lineEdit_gitPath->setText(t_dirpath);
    Setting::git_path = t_dirpath;
    //测试Git是否存在
    this->on_btn_test_clicked();
}



//测试Git是否存在
void Form_settings_Git::on_btn_test_clicked()
{
    //判断可执行文件是否存在
    QPalette t_pe;
    QProcess t_process;
    if(!QFile::exists(Setting::git_path)){
        t_pe.setColor(QPalette::WindowText,Qt::red);
        ui->label_tips->setPalette(t_pe);
        ui->label_tips->setText(tr("无法查询到有效程序，Git版本控制不可用！"));//Git版本：未知的版本
        return;
    }
    else{
        //运行Git，查看版本
        t_process.start(Setting::git_path,{"--version"}); //运行 git --version
        t_process.waitForFinished();
        QString t_normalPut = t_process.readAllStandardOutput();

        if(t_normalPut.isEmpty()){
            t_pe.setColor(QPalette::WindowText,Qt::red);
            ui->label_tips->setPalette(t_pe);
            ui->label_tips->setText(tr("Git程序不可用，请选择有效的版本！"));//Git版本：未知的版本
            return;
        }
        else{
            if(t_normalPut.left(QString("git version").length()) == "git version"){
                t_pe.setColor(QPalette::WindowText,Qt::blue);
                ui->label_tips->setPalette(t_pe);
                ui->label_tips->setText(tr("Git版本：") + Str::getSubStr(t_normalPut,"git version",""));//Git版本：未知的版本
                ui->lineEdit_gitPath->setText(Setting::git_path); //设置读取的有效路径信息


                //读取全局信息
                t_process.start(Setting::git_path,{"config","--list"});
                t_process.waitForFinished();
                QString t_normalPut = t_process.readAllStandardOutput();

                ui->lineEdit_userName->setText(Str::getSubStr(t_normalPut,"user.name=","\n"));//读取用户名
                ui->lineEdit_email->setText(Str::getSubStr(t_normalPut,"user.email=","\n"));//读取邮箱
                ui->lineEdit_psw->setText(Str::getSubStr(t_normalPut,"user.password=","\n"));//读取密码
                ui->lineEdit_master->setText(Str::getSubStr(t_normalPut,"init.defaultbranch=","\n"));//读取分支
            }
        }
    }




}


void Form_settings_Git::on_checkBox_showPsw_stateChanged(int arg1)
{
    //2是勾选，0是未勾选
    if(arg1 == 0){
        ui->lineEdit_psw->setEchoMode(QLineEdit::EchoMode::Password);
    }
    else{
        ui->lineEdit_psw->setEchoMode(QLineEdit::EchoMode::Normal);
    }
}

