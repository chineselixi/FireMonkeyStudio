#include "Widget_HistoryList.h"
#include "ui_Widget_HistoryList.h"
#include "QListWidgetItem"
#include "../Widget/Widget_Button_HistoryItem.h"


#include "../SwSystem/System_GlobalVar.h"
#include "SwSystem/System_History.h"

Widget_HistoryList::Widget_HistoryList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_HistoryList)
{
    ui->setupUi(this);
    ui->listWidget->clear(); //清理全部项目

    QVector<System_History::HistoryMsg> t_list = HistoryList::sys_proHistory->getHisList();//获取历史列表
    for(auto vlaue : t_list){
        this->addItem({vlaue.showIco,vlaue.showName,vlaue.filePath,vlaue.filePath});
    }

    this->adjustListWidgetHeigh(); //调整列表高度
}

Widget_HistoryList::~Widget_HistoryList()
{
    delete ui;
}

void Widget_HistoryList::addItem(itemMsg item)
{
    ui->label_tip->hide();
    ui->pushButton_clear->show();

    Widget_Button_HistoryItem* itemWidget = new Widget_Button_HistoryItem();
    itemWidget->setMsg(item.ico,item.title,item.tip,item.path);

    QListWidgetItem* listItem = new QListWidgetItem(ui->listWidget);
    listItem->setSizeHint(QSize(200,50));

    ui->listWidget->addItem(listItem);
    ui->listWidget->setItemWidget(listItem,itemWidget);

    //工程历史被点击
    connect(itemWidget,&Widget_Button_HistoryItem::itemClick,[=](QString path){
        event_onProjectOpen(path); //被点击信号
    });

    //工程关闭被点击
    connect(itemWidget,&Widget_Button_HistoryItem::itemClose,[=](QString path){
        delete listItem;    //关闭当前行
        deleteItem(path);
    });

    this->adjustListWidgetHeigh(); //调整列表高度
}


//添加多个item
void Widget_HistoryList::addItems(QList<itemMsg> items)
{
    for(itemMsg item : items){
        this->addItem(item);
    }
}


//根据path删除item
void Widget_HistoryList::deleteItem(QString path)
{
    if(HistoryList::sys_proHistory){
        HistoryList::sys_proHistory->removeProHisList(path); //删除单个记录
        HistoryList::sys_proHistory->saveHisList(); //保存记录
    }
    this->adjustListWidgetHeigh(); //调整列表高度
}


//删除所有的item
void Widget_HistoryList::deleteAll()
{
    ui->listWidget->clear();
    ui->pushButton_clear->hide();
    ui->label_tip->show();

    HistoryList::sys_proHistory->clearRepeat();
    HistoryList::sys_proHistory->saveHisList();
    this->adjustListWidgetHeigh(); //调整列表高度
}


//调整列表框高度
void Widget_HistoryList::adjustListWidgetHeigh()
{
    //调整关键按钮的可视化
    if(ui->listWidget->count() == 0){
        ui->pushButton_clear->hide();
        ui->label_tip->show();
        ui->listWidget->hide();
    }
    else{
        ui->pushButton_clear->show();
        ui->label_tip->hide();
        QRect t_rec = ui->listWidget->geometry();
        ui->listWidget->setGeometry(t_rec.x(),t_rec.y() * ui->listWidget->count(),200,t_rec.y());
        ui->listWidget->show();
    }


}

//清理全部被点击
void Widget_HistoryList::on_pushButton_clear_clicked()
{
    deleteAll();
}

