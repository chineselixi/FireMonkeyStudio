#include "Widget_TipItem.h"
#include "ui_Widget_TipItem.h"

Widget_TipItem::Widget_TipItem(uint16_t id,
                               QString title,
                               QString tip,
                               PluginGlobalMsg::TipType type,
                               QPixmap pixmap,
                               bool canClose,
                               std::function<void(uint16_t id)> tikFun,
                               QWidget *parent) :
    QWidget(parent),
    retFun(tikFun),
    thisId(id),
    ui(new Ui::Widget_TipItem)
{
    ui->setupUi(this);

    this->setTipTitle(title);
    this->setTipText(tip);
    this->setTipPixmap(pixmap);
    this->setTipType(type);
    this->setTipCanClose(canClose);
}

Widget_TipItem::~Widget_TipItem()
{
    delete ui;
}


//设置提示标题
void Widget_TipItem::setTipTitle(QString title)
{
    if(title.isEmpty()){
        ui->label_title->hide();
        return;
    }
    ui->label_title->setText(title);
}

//设置提示文本
void Widget_TipItem::setTipText(QString text)
{
    if(text.isEmpty()){
        ui->label_tip->hide();
        return;
    }
    ui->label_tip->setText(text);
}

//设置提示类型
void Widget_TipItem::setTipType(PluginGlobalMsg::TipType type)
{
    switch(type){
    case PluginGlobalMsg::TipType::Custom:{}                 //自定义信息
    default:{
        this->setTipPixmap(this->tipPixmap);
        break;
    }
    case PluginGlobalMsg::TipType::Normal:{                  //默认通知
        this->setTipPixmap(QPixmap(":/TipManger/icon/TipManger/normal.png"),false);
        break;
    }
    case PluginGlobalMsg::TipType::Warning:{                 //警告通知
        this->setTipPixmap(QPixmap(":/TipManger/icon/TipManger/warning.png"),false);
        break;
    }
    case PluginGlobalMsg::TipType::Error:{                   //错误通知
        this->setTipPixmap(QPixmap(":/TipManger/icon/TipManger/error.png"),false);
        break;
    }
    case PluginGlobalMsg::TipType::None:{                    //无图标通知
        this->setTipPixmap(QPixmap(),false);
        break;
    }
    }
}

//设置提示图片
void Widget_TipItem::setTipPixmap(QPixmap pixmap, bool save)
{
    if(pixmap.isNull()){
        ui->label_img->hide();
        return;
    }
    ui->label_img->setPixmap(pixmap);
    ui->label_img->show();              //显示图片
    if(save){
        this->tipPixmap = pixmap;
    }
}

//设置提示能够关闭
void Widget_TipItem::setTipCanClose(bool canClose)
{
    ui->btn_close->setHidden(!canClose);
}


//关闭控件
void Widget_TipItem::on_btn_close_clicked()
{
    this->retFun(thisId);
}

