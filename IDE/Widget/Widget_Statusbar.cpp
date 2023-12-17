#include "Widget_Statusbar.h"
#include "ui_Widget_Statusbar.h"

Widget_Statusbar::Widget_Statusbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Statusbar)
{
    ui->setupUi(this);
    this->setGeometry(0,0,10,0);
    this->hideAll();
    //ui->toolButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

}

Widget_Statusbar::~Widget_Statusbar()
{
    delete ui;
}

void Widget_Statusbar::hideAll()
{
    this->setProgress(-1);
    this->setBtn(ui->toolButton_1);
    this->setBtn(ui->toolButton_2);
    this->setBtn(ui->toolButton_3);
    this->setBtn(ui->toolButton_4);
    this->setBtn(ui->toolButton_5);
    this->setBtn(ui->toolButton_6);
}


//获取toolButton_Tip按钮指针
QWidget *Widget_Statusbar::getArrowWidgetPtr()
{
    return ui->toolButton_Tip;
}


//设置进度条
void Widget_Statusbar::setProgress(int a)
{
    if(a < 0){
        ui->progressBar->setValue(0);
        ui->progressBar->hide();
        return;
    }
    if(a >= ui->progressBar->maximum()){
        ui->progressBar->setValue(ui->progressBar->maximum());
    }
    else{
        ui->progressBar->setValue(a);
    }
    ui->progressBar->show();
}

void Widget_Statusbar::setBtn1(QString title, QIcon ico_16x, QString sign, std::function<void (QString)> funPtr)
{
    this->setBtn(ui->toolButton_1,title,ico_16x,sign,funPtr);
}

void Widget_Statusbar::setBtn2(QString title, QIcon ico_16x, QString sign, std::function<void (QString)> funPtr)
{
    this->setBtn(ui->toolButton_2,title,ico_16x,sign,funPtr);
}

void Widget_Statusbar::setBtn3(QString title, QIcon ico_16x, QString sign, std::function<void (QString)> funPtr)
{
    this->setBtn(ui->toolButton_3,title,ico_16x,sign,funPtr);
}

void Widget_Statusbar::setBtn4(QString title, QIcon ico_16x, QString sign, std::function<void (QString)> funPtr)
{
    this->setBtn(ui->toolButton_4,title,ico_16x,sign,funPtr);
}

void Widget_Statusbar::setBtn5(QString title, QIcon ico_16x, QString sign, std::function<void (QString)> funPtr)
{
    this->setBtn(ui->toolButton_5,title,ico_16x,sign,funPtr);
}

void Widget_Statusbar::setBtn6(QString title, QIcon ico_16x, QString sign, std::function<void (QString)> funPtr)
{
    this->setBtn(ui->toolButton_6,title,ico_16x,sign,funPtr);
}

//设置提示按钮标记向上
void Widget_Statusbar::setTipArrowType(Qt::ArrowType type)
{
    ui->toolButton_Tip->setArrowType(type);
}

//设置提示按钮的显隐
void Widget_Statusbar::setTipBtnShow(bool show)
{
    ui->toolButton_Tip->setHidden(!show);
}

//设置激活方法
void Widget_Statusbar::setTipBtnFun(std::function<void ()> fun)
{
    this->tipFun = fun;
}

//设置按钮事件，funPtr若为null，则隐藏
void Widget_Statusbar::setBtn(QToolButton *btnObj, QString title, QIcon ico_16x, QString sign, std::function<void (QString)> funPtr)
{
    if(btnObj == nullptr)return;

    if(funPtr == nullptr){btnObj->hide();return;} //操作指针为空，则隐藏，不做任何操作
    else{btnObj->show();}

    btnObj->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextOnly); //设置操作类型
    if(!ico_16x.isNull()){btnObj->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);}
    if(!title.isEmpty() && !ico_16x.isNull()){btnObj->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);}

    btnObj->setText(title);     //设置标题与图标
    btnObj->setIcon(ico_16x);

    disconnect(btnObj,&QToolButton::clicked,0,0); //此按钮的所有链接
    connect(btnObj,&QToolButton::clicked,[=](){ //链接新的方法
        funPtr(sign);
    });
}

//激活工具提示按钮
void Widget_Statusbar::on_toolButton_Tip_clicked()
{
    if(tipFun != nullptr){
        tipFun();
    }
}

