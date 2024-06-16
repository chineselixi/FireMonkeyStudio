#include "Widget_Button_CompletionItem.h"
#include "ui_Widget_Button_CompletionItem.h"

Widget_Button_CompletionItem::Widget_Button_CompletionItem(QString title, QPixmap pixmap, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Button_CompletionItem)
{
    ui->setupUi(this);
    this->setTipTitle(title);
    this->setTipPixmap(pixmap);
}


Widget_Button_CompletionItem::~Widget_Button_CompletionItem()
{
    delete ui;
}

//设置提示标题
void Widget_Button_CompletionItem::setTipTitle(QString title)
{
    if(title.isEmpty()){
        ui->label_title->hide();
        return;
    }
    ui->label_title->setText(title);
}


//设置提示图片
void Widget_Button_CompletionItem::setTipPixmap(QPixmap pixmap)
{
    if(pixmap.isNull()){
        ui->label_img->hide();
        return;
    }
    ui->label_img->setPixmap(pixmap);
    ui->label_img->show();              //显示图片
}
