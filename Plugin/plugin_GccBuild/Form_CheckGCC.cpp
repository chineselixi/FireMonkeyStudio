#include "Form_CheckGCC.h"
#include "ui_Form_CheckGCC.h"
#include "QProcess"



Form_CheckGCC::Form_CheckGCC(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_CheckGCC)
{
    ui->setupUi(this);
    this->on_But_check_clicked();
}

Form_CheckGCC::~Form_CheckGCC()
{
    delete ui;
}


//检查GCC是否存在
QString Form_CheckGCC::gccExist()
{
    QProcess t_p;
    t_p.start("gcc",{"-v"});
    t_p.waitForFinished();

    QString t_str = t_p.readAllStandardError() + t_p.readAllStandardError();
    QStringList t_strList = t_str.split('\n');
    t_str = t_strList[t_strList.length() - 2];

    int t_start = t_str.indexOf("gcc version ");
    int t_end = t_start;
    if(t_start != -1){
        t_start += QString("gcc version ").length();
        t_end = t_str.indexOf(" ",t_start);
        t_str = t_str.mid(t_start,t_end - t_start);
    }
    else{
        t_str = "";
    }
    return t_str;
}



void Form_CheckGCC::on_But_check_clicked()
{
    QString t_str = this->gccExist();
    if(t_str == ""){
        ui->label_img->setPixmap(QPixmap(":/form_img/img/error.png"));
        ui->label_tip->setText(tr("GCC编译器不存在"));
    }
    else{
        ui->label_img->setPixmap(QPixmap(":/form_img/img/ok.png"));
        ui->label_tip->setText(tr("GCC版本:") + t_str);
    }
    qDebug()<< t_str;
}

