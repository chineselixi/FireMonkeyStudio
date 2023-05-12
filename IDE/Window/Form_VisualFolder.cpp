#include "Form_VisualFolder.h"
#include "ui_Form_VisualFolder.h"
#include "QMessageBox"


Form_VisualFolder::Form_VisualFolder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_VisualFolder)
{
    ui->setupUi(this);
}

Form_VisualFolder::~Form_VisualFolder()
{
    delete ui;
}

void Form_VisualFolder::setFun(std::function<void (QString,QString,int)> fun)
{
    Fun = fun;
}


//关闭窗口
void Form_VisualFolder::on_pushButton_close_clicked()
{
    this->close();
}

//确认信息
void Form_VisualFolder::on_pushButton_OK_clicked()
{
    if(Fun == nullptr) return;
    if(ui->lineEdit_folderName->text().isEmpty() || ui->lineEdit_folderSign->text().isEmpty()){
        QMessageBox::warning(this,tr("警告"),tr("分类信息不能够为空！"));
        return;
    }
    Fun(ui->lineEdit_folderName->text(),ui->lineEdit_folderSign->text(),ui->comboBox_modSelect->currentIndex());//调用外部函数
    this->close(); //关闭自身
}


//文本标记改变
void Form_VisualFolder::on_lineEdit_folderSign_textChanged(const QString &arg1)
{
    int t_index = ui->comboBox_modSelect->currentIndex();
    switch (t_index){
    case 0:{
        ui->label_nameTip->setText("XXXX" + ui->lineEdit_folderSign->text());
        break;
    }
    case 1:{
        ui->label_nameTip->setText(ui->lineEdit_folderSign->text() + "XXXX");
        break;
    }
    case 2:{
        ui->label_nameTip->setText("*" + ui->lineEdit_folderSign->text() + "*");
        break;
    }
    default:{
        ui->label_nameTip->setText("XXXX" + ui->lineEdit_folderSign->text());
        break;
    }
    }
}


void Form_VisualFolder::on_comboBox_modSelect_currentIndexChanged(int index)
{
    this->on_lineEdit_folderSign_textChanged("");
}

