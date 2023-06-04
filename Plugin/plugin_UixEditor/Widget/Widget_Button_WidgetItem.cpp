#include "Widget_Button_WidgetItem.h"
#include "ui_Widget_Button_WidgetItem.h"

Widget_Button_WidgetItem::Widget_Button_WidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Button_WidgetItem)
{
    ui->setupUi(this);
    //this->setAttribute(Qt::WA_StyledBackground);
}

Widget_Button_WidgetItem::Widget_Button_WidgetItem(QPixmap pixmap, QString title, QString sign, QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget_Button_WidgetItem)
{
    ui->setupUi(this);
    //this->setAttribute(Qt::WA_StyledBackground);
    this->SetIcon(pixmap);
    this->SetTitle(title);
    this->SetSign(sign);
}

Widget_Button_WidgetItem::~Widget_Button_WidgetItem()
{
    delete ui;
}

void Widget_Button_WidgetItem::SetIcon(QPixmap pixmap, QSize icoSize)
{
    ui->label_img->setPixmap(pixmap.scaled(icoSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Widget_Button_WidgetItem::SetTitle(QString text)
{
    ui->label_title->setText(text);
}

void Widget_Button_WidgetItem::SetSign(QString text)
{
    this->Sign = text;
}

QString Widget_Button_WidgetItem::GetTitle()
{
    return ui->label_title->text();
}

QString Widget_Button_WidgetItem::GetSign()
{
    return this->Sign;
}
