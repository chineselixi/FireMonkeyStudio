#include "Widget_widgetList.h"
#include "ui_Widget_widgetList.h"

Widget_widgetList::Widget_widgetList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_widgetList)
{
    ui->setupUi(this);
    baseItem = new QTreeWidgetItem;
}

Widget_widgetList::~Widget_widgetList()
{
    delete ui;
}


//添加根节点
void Widget_widgetList::addBaseItem(QWidget *widgetItem, QIcon ico, QString title, QString classTitle)
{
    baseItem->setIcon(0,ico); //item信息插入
    baseItem->setText(0,title);
    baseItem->setText(1,classTitle);
    ui->treeWidget->addTopLevelItem(baseItem); //更目录信息
    itemList.append({
        widgetItem,
        baseItem,
        title,
        classTitle
    }); //插入信息到列表
}


//添加项目
void Widget_widgetList::addItem(QWidget *widgetItem, QIcon ico, QString title, QString classTitle)
{
    if(widgetItem->parentWidget() == nullptr) return;

    QTreeWidgetItem* t_item = new QTreeWidgetItem; //创建新的Item
    t_item->setIcon(0,ico);
    t_item->setText(0,title);
    t_item->setText(1,classTitle);

    QTreeWidgetItem* t_parentItem = baseItem;
    for(auto value : itemList){
        if(value.widgetItem == widgetItem->parentWidget()){ //查询父节点
            t_parentItem = value.treeItem;
            break;
        }
    }

    t_parentItem->addChild(t_item);     //添加子节点
    itemList.append({                   //插入信息到列表
        widgetItem,
        t_item,
        title,
        classTitle
    });

    //ui->listWidget->addAction()



}


//移除项目
void Widget_widgetList::removeItem(QWidget *widgetItem)
{
    for(int a = 0;a<itemList.length();a++){
        if(widgetItem == itemList[a].widgetItem){
            delete itemList[a].treeItem;
            itemList.removeAt(a);
            break;
        }
    }
}


//选择Item
void Widget_widgetList::selectItem(QWidget *widgetItem)
{
    ui->treeWidget->clearSelection();
    for(auto value : itemList){
        if(value.widgetItem == widgetItem){ //查询父节点
            value.treeItem->setSelected(true);
            break;
        }
    }
}


//更改项目名称
void Widget_widgetList::changeItemTitle(QWidget *widgetItem, QString newTitle)
{
    for(auto value : itemList){
        if(value.widgetItem == widgetItem){
            value.treeItem->setText(0,newTitle);
            break;
        }
    }
}


//更改类名称
void Widget_widgetList::changeItemClassTitle(QWidget *widgetItem, QString newClassTitle)
{
    for(auto value : itemList){
        if(value.widgetItem == widgetItem){
            value.treeItem->setText(1,newClassTitle);
            break;
        }
    }
}


//Item被点击
void Widget_widgetList::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    for(auto value : itemList){
        if(value.treeItem == item){
            this->event_onItemClick(value.widgetItem);
            break;
        }
    }
}

