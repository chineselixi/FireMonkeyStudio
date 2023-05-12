#include "Widget_Button_PluginItem.h"
#include "ui_Widget_Button_PluginItem.h"

#include "QImage"
#include "QPainter"


Widget_Button_PluginItem::Widget_Button_PluginItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Button_PluginItem)
{
    ui->setupUi(this);
    this->SetIcon(ui->label_img->pixmap());

}

Widget_Button_PluginItem::Widget_Button_PluginItem(QPixmap ico, QString title, QString filePathTip, QString pluginSign,QString pluginVersion,QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget_Button_PluginItem)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
    this->SetIcon(ico);
    this->SetTitle(title);
    this->SetFilePathTip(filePathTip);
    this->SetPluginSign(pluginSign);
    this->SetPluginVerTip(pluginVersion);
}

Widget_Button_PluginItem::~Widget_Button_PluginItem()
{
    delete ui;
}



//设置图标
void Widget_Button_PluginItem::SetIcon(QPixmap pixmap,QSize icoSize)
{
    ui->label_img->setPixmap(pixmap.scaled(icoSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    pixmap_normal = pixmap;

    pixmap_unEnable = pixmap;
    pixmap_unEnable.fill(Qt::transparent);
    QPainter painter(&pixmap_unEnable);
    painter.setOpacity(0.3);
    painter.drawPixmap(0, 0, pixmap_normal);
    painter.end();
}


//设置主标题
void Widget_Button_PluginItem::SetTitle(QString text)
{
    ui->label_pluginName->setText(text);
    ui->label_pluginName->adjustSize();
}




//设置文件路径提示
void Widget_Button_PluginItem::SetFilePathTip(QString text)
{
    ui->label_filePath->setText(text);
}




//设置插件标记提示
void Widget_Button_PluginItem::SetPluginSign(QString text)
{
    if(text.isEmpty()){
        ui->label_sign->setHidden(true);
    }
    else{
        ui->label_sign->setHidden(false);
    }
    ui->label_sign->setText(text);
    ui->label_sign->adjustSize();
}




//设置插件的版本
void Widget_Button_PluginItem::SetPluginVerTip(QString ver)
{
    if(ver.isEmpty()){
        ui->label_version->setHidden(true);
    }
    else{
        ui->label_version->setHidden(false);
    }
    ui->label_version->setText(ver);
    ui->label_version->adjustSize();
}




//设置启用
void Widget_Button_PluginItem::SetEnableStyle(bool enable)
{
    if(enable){
        ui->But_enable->setText("禁用");
        ui->label_pluginName->setStyleSheet("color:rgb(0,0,0);");
        ui->label_filePath->setStyleSheet("color:rgb(79,79,79);");
        ui->label_sign->setStyleSheet("color:rgb(0,0,0);");
        ui->label_version->setStyleSheet("color:rgb(0,0,0);");
        ui->label_img->setPixmap(pixmap_normal);
        this->event_onPluginEnable(true);
    }
    else{
        ui->But_enable->setText("启用");
        ui->label_pluginName->setStyleSheet("color:rgb(200,200,200);");
        ui->label_filePath->setStyleSheet("color:rgb(220,220,220);");
        ui->label_sign->setStyleSheet("color:rgb(200,200,200);");
        ui->label_version->setStyleSheet("color:rgb(200,200,200);");
        ui->label_img->setPixmap(pixmap_unEnable);
        this->event_onPluginEnable(false);
    }
}



//启用或者禁用插件
void Widget_Button_PluginItem::on_But_enable_clicked()
{
    this->SetEnableStyle(ui->But_enable->text() == "启用");
}

//卸载插件
void Widget_Button_PluginItem::on_But_unload_clicked()
{
    this->event_onPluginUnload(); //卸载插件信息
}


//当按钮被按下
void Widget_Button_PluginItem::mousePressEvent(QMouseEvent *event)
{
    this->event_onDown();
}
