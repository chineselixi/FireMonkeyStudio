#include "Widget_Button_ModHistoryItem.h"
#include "ui_Widget_Button_ModHistoryItem.h"

Widget_Button_ModHistoryItem::Widget_Button_ModHistoryItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Button_ModHistoryItem)
{
    ui->setupUi(this);
    //this->setAttribute(Qt::WA_StyledBackground);
}

Widget_Button_ModHistoryItem::Widget_Button_ModHistoryItem(QPixmap ico,QString title,QString modStr,QString date,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Button_ModHistoryItem)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
    this->SetIcon(ico);
    this->SetTitle(title);
    this->SetModStr(modStr);
}


Widget_Button_ModHistoryItem::~Widget_Button_ModHistoryItem()
{
    delete ui;
}



//设置图标
void Widget_Button_ModHistoryItem::SetIcon(QPixmap pixmap,QSize icoSize)
{
    ui->label_img->setPixmap(pixmap.scaled(icoSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

}

//设置主标题
void Widget_Button_ModHistoryItem::SetTitle(QString text)
{
    ui->label_title->setText(text);
}

//设置副标题
void Widget_Button_ModHistoryItem::SetModStr(QString text)
{
    if(text.isEmpty()){
        ui->label_mod->setHidden(true);
    }
    else{
        ui->label_mod->setHidden(false);
    }
    ui->label_mod->setText(text);
    ui->label_mod->adjustSize();
}



//当按钮被按下
void Widget_Button_ModHistoryItem::mousePressEvent(QMouseEvent *event)
{
    this->onDown();//调用信号
}
