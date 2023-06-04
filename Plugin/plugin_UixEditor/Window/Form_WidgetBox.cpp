#include "Form_WidgetBox.h"
#include "ui_Form_WidgetBox.h"
#include "Widget/Widget_Button_WidgetItem.h"

Form_WidgetBox::Form_WidgetBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_WidgetBox)
{
    ui->setupUi(this);
    //ui->listWidget->setViewMode(QListWidget::ViewMode::IconMode); //图像模式
    //ui->listWidget->setResizeMode(QListView::Adjust); //自动对其

    //连接按钮被按下
    connect(ui->listWidget,&QListWidget::itemClicked,[this](QListWidgetItem * item){
        Widget_Button_WidgetItem* t_widget = (Widget_Button_WidgetItem*)ui->listWidget->itemWidget(item);
        QString t_title = t_widget->GetTitle();
        QString t_sign = t_widget->GetSign();
        onItemDown(t_title,t_sign);
    });

}

Form_WidgetBox::~Form_WidgetBox()
{
    delete ui;
}


QSize Form_WidgetBox::sizeHint() const
{
    return QSize(180, 900); /* 在这里定义dock的初始大小 */
}


//添加项目
void Form_WidgetBox::addItem(QPixmap pixmap, QString title, QString sign)
{
    QListWidgetItem* t_item = new QListWidgetItem(ui->listWidget);
    Widget_Button_WidgetItem* t_widget = new Widget_Button_WidgetItem(pixmap,title,sign,ui->listWidget);
    t_item->setSizeHint(QSize(150,32));
    ui->listWidget->addItem(t_item);
    ui->listWidget->setItemWidget(t_item,t_widget);
    //ui->listWidget->setMovement(QListWidget::Static); //防止手动移动改变了位置，已经在UI编辑器里面设置
}
