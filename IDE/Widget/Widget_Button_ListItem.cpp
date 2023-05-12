#include "Widget_Button_ListItem.h"
#include "ui_Widget_Button_ListItem.h"

Widget_Button_ListItem::Widget_Button_ListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Button_ListItem)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
    this->SetIcon(ui->label_img->pixmap());
}

Widget_Button_ListItem::Widget_Button_ListItem(QPixmap ico,QString title,QString text,QString date,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Button_ListItem)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
    this->SetIcon(ico);
    this->SetTitle(title);
    this->SetTip(text);
}

Widget_Button_ListItem::~Widget_Button_ListItem()
{
    delete ui;
}



//设置图标
void Widget_Button_ListItem::SetIcon(QPixmap pixmap,QSize icoSize)
{
    ui->label_img->setPixmap(pixmap.scaled(icoSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

}

//设置主标题
void Widget_Button_ListItem::SetTitle(QString text)
{
    ui->label_main->setText(text);
}

//设置副标题
void Widget_Button_ListItem::SetTip(QString text)
{
    ui->label_tip->setText(text);
}

//设置日期
void Widget_Button_ListItem::SetDate(QString date)
{
    ui->label_time->setText(date);
}

//获取标题
QString Widget_Button_ListItem::GetTitle()
{
    return ui->label_main->text();
}

//获取提示信息
QString Widget_Button_ListItem::GetTip()
{
    return ui->label_tip->text();
}

QString Widget_Button_ListItem::GetDate()
{
    return ui->label_time->text();
}


//当按钮被按下
void Widget_Button_ListItem::mousePressEvent(QMouseEvent *event)
{
    this->onDown();//调用信号
}
