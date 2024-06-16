#include "Form_CompletionTip.h"
#include "ui_Form_CompletionTip.h"
#include "../Widget/Widget_Button_CompletionItem.h"
#include "QFocusEvent"

Form_CompletionTip::Form_CompletionTip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_CompletionTip)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Form_CompletionTip::~Form_CompletionTip()
{
    delete ui;
}

void Form_CompletionTip::addTip(
        int kind,                   //提示类型
        QString filterText,         //过滤文本
        QString insertText,         //插入文本
        int insertTextFormat,       //插入类型
        QString label,              //提示的文本
        double score,               //排序值，越大越前面
        QString sortText,           //排序文本
        QString newText,            //要替换的文本
        uint16_t startLine,         //开始行
        uint16_t startCharacter,    //开始文本列
        uint16_t endLine,           //结束行
        uint16_t endCharacter       //结束文本列
    )
{
    TipNode t_node;
    t_node.item = new QListWidgetItem(ui->listWidget);

    t_node.widget = new Widget_Button_CompletionItem(label,QPixmap());
    t_node.item->setSizeHint(QSize(184,24));        //设置每一个项目的高度
    ui->listWidget->addItem(t_node.item);
    ui->listWidget->setItemWidget(t_node.item,t_node.widget);   //将item与widget绑定

    //保存数据到TipNodeList
    t_node.kind = kind;
    t_node.filterText = filterText;
    t_node.insertText = insertText;
    t_node.insertTextFormat = insertTextFormat;
    t_node.label = label;
    t_node.score = score;
    t_node.sortText = sortText;
    t_node.newText = newText;
    t_node.startLine = startLine ;
    t_node.startCharacter = startCharacter;
    t_node.endLine = endLine;
    t_node.endCharacter = endCharacter;
    TipNodeList.append(t_node);
}




//关闭所有提示
void Form_CompletionTip::clearAll()
{
//    QList<TipNode>::iterator i;
//    for(i = TipNodeList.begin(); i != TipNodeList.end(); i++){
//        delete i->widget;
//        delete i->item;
//    }
    ui->listWidget->clear();
    TipNodeList.clear(); //清楚所有信息
    this->adjustWindowRec();    //调整窗口大小
}

//显示菜单（左上角位置）
void Form_CompletionTip::showMenu(QPoint point, TipSelectFunction tipFun)
{
    this->showPoint = point;
    this->selectItemFun = tipFun;
    this->adjustWindowRec();
    ui->listWidget->setCurrentRow(0);
    this->show();
    this->setFocus();
}


//调整菜单尺寸和位置
void Form_CompletionTip::adjustWindowRec()
{
    //高度高了的话就更改位置
    int t_heigh = TipNodeList.length() * 24;
    if(TipNodeList.length() > 20){
        t_heigh = 480;
    }

    QRect t_rect = this->geometry();
    t_rect.setHeight(t_heigh);


    t_rect.setX(this->showPoint.x());
    t_rect.setY(this->showPoint.y());
    this->setGeometry(t_rect);
}

//选择选项
void Form_CompletionTip::selectItem(TipSelectFunction tipFun)
{
    this->selectItemFun = tipFun;
}

//选择上一个
void Form_CompletionTip::up()
{
    ui->listWidget->setCurrentRow(ui->listWidget->currentRow() - 1);
}

//选择下一个
void Form_CompletionTip::down()
{
    ui->listWidget->setCurrentRow(ui->listWidget->currentRow() + 1);
}


//窗口隐藏
void Form_CompletionTip::hideEvent(QHideEvent *event)
{
    this->selectItemFun = nullptr;
}


//item被点击
void Form_CompletionTip::on_listWidget_itemClicked(QListWidgetItem *item)
{
    for(int i = 0; i < TipNodeList.length(); i++){
        if(TipNodeList[i].item == item){
            if(this->selectItemFun){
                this->selectItemFun(TipNodeList[i].startLine,
                                    TipNodeList[i].startCharacter,
                                    TipNodeList[i].endLine,
                                    TipNodeList[i].endCharacter,
                                    TipNodeList[i].newText);
            }
            break;
        }
    }
    this->close();
}

