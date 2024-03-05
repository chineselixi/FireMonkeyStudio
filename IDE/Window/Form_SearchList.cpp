#include "Form_SearchList.h"
#include "ui_Form_SearchList.h"
#include "QResizeEvent"

Form_SearchList::Form_SearchList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_SearchList)
{
    ui->setupUi(this);
    this->clearMsg();
}

Form_SearchList::~Form_SearchList()
{
    delete ui;
}

void Form_SearchList::addMsg(QString codeText, QString file, QString project, uint16_t line,uint16_t lineIndex,uint16_t len)
{
    QTreeWidgetItem* t_item = new QTreeWidgetItem;
    t_item->setText(0,codeText);
    t_item->setText(1,file);
    t_item->setText(2,project);
    t_item->setText(3,QString::number(line));
    t_item->setText(4,QString::number(lineIndex));

    ui->treeWidget->addTopLevelItem(t_item);
    ui->treeWidget->scrollToBottom(); //总是显示最后一行
    this->nodeList.append({t_item,codeText,file,project,line,lineIndex,len});
}


//删除所有内容
void Form_SearchList::clearMsg()
{
    this->nodeList.clear();
    ui->treeWidget->clear();

//    for(int a = ui->treeWidget->topLevelItemCount()-1; a>=0; a--){
//        delete ui->treeWidget->topLevelItem(a);
//    }
}


//尺寸被改变，动态绑定
void Form_SearchList::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    int t_width = event->size().width();
    if(t_width < 355){
        return;
    }

    ui->treeWidget->setColumnWidth(4,40);
    ui->treeWidget->setColumnWidth(3,40);
    ui->treeWidget->setColumnWidth(2,100);
    ui->treeWidget->setColumnWidth(1,100);
    ui->treeWidget->setColumnWidth(0,t_width - 300);
}


//被双击
void Form_SearchList::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    for(qsizetype i = 0; i < this->nodeList.length(); i++){
        if(this->nodeList[i].item == item){
            if(!this->nodeList[i].filePath.isEmpty() && this->nodeList[i].len > 0){

                this->onFileOpen(this->nodeList[i].filePath,this->nodeList[i].line,this->nodeList[i].lineIndex,this->nodeList[i].len);
            }
            break;
        }
    }
}


