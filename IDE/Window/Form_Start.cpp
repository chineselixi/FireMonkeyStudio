#include "Form_Start.h"
#include "ui_Form_Start.h"

#include "QMessageBox"
#include "../SwSystem/System_GlobalVar.h"
#include "../Window/Form_WorkSpace.h"

Form_Start::Form_Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Start)
{
    ui->setupUi(this);
    connect(ui->widget_historyList,&Widget_HistoryList::event_onProjectOpen,this,&Form_Start::onProjectOpen); //连接打开信号槽
}

Form_Start::~Form_Start()
{
    delete ui;
}


//当工程被打开
void Form_Start::onProjectOpen(QString path)
{
    ProjectOpen::projectPath = path; //工程路径
    if(Window::workSpace != nullptr)
    Window::workSpace->loadProject();
}

//新建被点击
void Form_Start::on_pushButton_new_clicked()
{
    if(Window::workSpace != nullptr)
    Window::workSpace->on_action_file_newCreate_triggered();
}

//打开被点击
void Form_Start::on_pushButton_open_clicked()
{
    if(Window::workSpace != nullptr)
    Window::workSpace->on_action_file_open_triggered();
}

//商店被点击
void Form_Start::on_pushButton_store_clicked()
{
    QMessageBox::warning(Window::workSpace,tr("未开放"),tr("源码商城在此版本中不受支持，请更新到最新版本！"));
}

//设置被点击
void Form_Start::on_pushButton_set_clicked()
{
    if(Window::workSpace != nullptr)
    Window::workSpace->on_action_systemSettings_triggered();
}

