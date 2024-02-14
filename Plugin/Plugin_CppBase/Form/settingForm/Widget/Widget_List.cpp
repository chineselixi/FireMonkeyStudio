#include "Widget_List.h"
#include "ui_Widget_List.h"
#include "QFileDialog"




Widget_List::Widget_List(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_List)
{
    ui->setupUi(this);
}

Widget_List::~Widget_List()
{
    delete ui;
}

//添加列表到UI
void Widget_List::setList(QVector<QString> list)
{
    this->list = list;
    this->arrangeList();
    this->flashUI();
}

//获取列表
QVector<QString> Widget_List::getList()
{
    return list;
}

//添加按钮被按下
void Widget_List::on_btnAdd_clicked()
{
    QString t_dirPath = QFileDialog::getExistingDirectory(this, tr("选择编译器根目录"), "", QFileDialog::ShowDirsOnly);
    if(t_dirPath.isEmpty()) return;
    this->addNode(t_dirPath);
    this->arrangeList(); //去重数据
    this->flashUI(); //更新UI
}

//删除按钮被按下
void Widget_List::on_btnDelete_clicked()
{
    QListWidgetItem* t_item = ui->listWidget->currentItem();
    if(t_item){
        this->removeNode(t_item->text());
        this->flashUI(); //更新UI
    }
}

//去重整理
void Widget_List::arrangeList()
{
    for(int i = list.length() - 1;i >= 0;i--){
        for(int a = i - 1;a >= 0;a--){
            if(list[i] == list[a]){
                list.remove(i);
                break;
            }
        }
    }
}

//更新列表
void Widget_List::flashUI()
{
    ui->listWidget->clear();
    for(int i = 0;i < list.length();i++){
        ui->listWidget->addItem(list[i]);
    }
}

//添加信息
void Widget_List::addNode(QString sign)
{
    list.append(sign);
}

//删除信息
void Widget_List::removeNode(QString sign)
{
    //倒删数据
    for(int i = list.length() - 1;i >= 0;i--){
        if(list[i] == sign){
            list.remove(i);
        }
    }
}


