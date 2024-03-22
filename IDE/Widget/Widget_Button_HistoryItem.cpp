#include "Widget_Button_HistoryItem.h"
#include "ui_Widget_Button_HistoryItem.h"

Widget_Button_HistoryItem::Widget_Button_HistoryItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Button_HistoryItem)
{
    ui->setupUi(this);
    ui->pushButton_close->hide();
}

Widget_Button_HistoryItem::~Widget_Button_HistoryItem()
{
    delete ui;
}


//设置item信息
void Widget_Button_HistoryItem::setMsg(QPixmap ico, QString title, QString tip, QString path)
{
    ui->label_ico->setPixmap(ico);
    ui->label_mainTip->setText(title);
    ui->label_secTip->setText(tip);
    this->setWindowTitle(path);
}


void Widget_Button_HistoryItem::on_pushButton_clicked()
{
    this->itemClose(this->windowTitle());
    qDebug() <<this->windowTitle();
}


//进入QWidget瞬间事件
void Widget_Button_HistoryItem::enterEvent(QEnterEvent *event)
{
    ui->pushButton_close->show();
}

//离开QWidget瞬间事件
void Widget_Button_HistoryItem::leaveEvent(QEvent *)
{
    ui->pushButton_close->hide();
}

//摁住鼠标事件
void Widget_Button_HistoryItem::mousePressEvent(QMouseEvent *event)
{
    this->itemClick(this->windowTitle());
}

//关闭被点击
void Widget_Button_HistoryItem::on_pushButton_close_clicked()
{
    this->itemClose(this->windowTitle());
}

