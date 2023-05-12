#include "Widget_Button_ModItem.h"
#include "ui_Widget_Button_ModItem.h"

Widget_Button_ModItem::Widget_Button_ModItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Button_ModItem)
{
    ui->setupUi(this);
}

Widget_Button_ModItem::Widget_Button_ModItem(QPixmap ico, QString title, QString tip, QString langTip, QString osTip, QString otherTip, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Button_ModItem)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
    this->SetIcon(ico);
    this->SetTitle(title);
    this->SetTip(tip);
    this->SetLangTip(langTip);
    this->SetOsTip(osTip);
    this->SetOtherTip(otherTip);
}

Widget_Button_ModItem::~Widget_Button_ModItem()
{
    delete ui;
}



//设置图标
void Widget_Button_ModItem::SetIcon(QPixmap pixmap,QSize icoSize)
{
    ui->label_img->setPixmap(pixmap.scaled(icoSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

}

//设置主标题
void Widget_Button_ModItem::SetTitle(QString text)
{
    ui->label_main->setText(text);
}

//设置副标题
void Widget_Button_ModItem::SetTip(QString text)
{
    ui->label_tip->setText(text);
}

//设置语言提示文本
void Widget_Button_ModItem::SetLangTip(QString text)
{
    if(text.isEmpty()){
        ui->label_lang->setHidden(true);
    }
    else{
        ui->label_lang->setHidden(false);
    }
    ui->label_lang->setText(text);
    ui->label_lang->adjustSize();
}

//设置OS提示文本
void Widget_Button_ModItem::SetOsTip(QString text)
{
    if(text.isEmpty()){
        ui->label_os->setHidden(true);
    }
    else{
        ui->label_os->setHidden(false);
    }
    ui->label_os->setText(text);
    ui->label_os->adjustSize();
}

//设置其他提示文本
void Widget_Button_ModItem::SetOtherTip(QString text)
{
    if(text.isEmpty()){
        ui->label_other->setHidden(true);
    }
    else{
        ui->label_other->setHidden(false);
    }
    ui->label_other->setText(text);
    ui->label_other->adjustSize();
}



//当按钮被按下
void Widget_Button_ModItem::mousePressEvent(QMouseEvent *event)
{
    this->onDown();//调用信号
}
