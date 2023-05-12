#include "Widget_Button_Start.h"
#include "ui_Widget_Button_Start.h"

Widget_Button_Start::Widget_Button_Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Button_Start)
{
    //this->Init();
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
}

Widget_Button_Start::Widget_Button_Start(QPixmap ico, QString title, QString tip, QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget_Button_Start)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
    this->SetIcon(ico);
    this->SetTitle(title);
    this->SetTip(tip);
}

//初始化
//void Widget_Button_Start::Init()
//{
//    ui->label_main->setAttribute(Qt::WA_TransparentForMouseEvents);
//    ui->label_tip->setAttribute(Qt::WA_TransparentForMouseEvents);
//    ui->label_img->setAttribute(Qt::WA_TransparentForMouseEvents);

//}


Widget_Button_Start::~Widget_Button_Start()
{
    delete ui;
}

//设置图标
void Widget_Button_Start::SetIcon(QPixmap pixmap,QSize icoSize)
{
    ui->label_img->setPixmap(pixmap.scaled(icoSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

}

//设置主标题
void Widget_Button_Start::SetTitle(QString text)
{
    ui->label_main->setText(text);
}

//设置副标题
void Widget_Button_Start::SetTip(QString text)
{
    ui->label_tip->setText(text);
}

////设置按下函数
//void Widget_Button_Start::SetOnClickFunction(void (*ClickFun)())
//{
//    Even_ClickFun = ClickFun;
//}

////设置按下函数
//void Widget_Button_Start::SetOnClickFunction(QWidget *obj, void (QWidget::*fun)())
//{
//    EvenWidget = obj;
//    EvenClickFun = fun;
//}


//当按钮被按下
void Widget_Button_Start::mousePressEvent(QMouseEvent *event)
{
    this->onDown();
}
