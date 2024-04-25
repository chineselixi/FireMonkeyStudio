#include "Form_EditorSpace.h"

#include "QMdiSubWindow"
#include "QKeyEvent"

#include "Plugins/Plugin_MainWindow.h"
#include "Form_PropertyEditor.h"


#include "Plugins/Plugin_MainWindow.h"
#include "Plugins/Plugin_Button.h"


#include "GlobalMsg.h"
#include "QScrollBar"

Form_EditorSpace::Form_EditorSpace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_EditorSpace)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground); //脱离父窗口样式的覆盖

    //创建Roi
    this->roiWidget = new Form_Roi(this);
    //this->roiWidget->roi_setWidgetMsgListPtr(&this->widgets); //设置组件列表指针

    //绑定ROI
    connect(this->roiWidget,&Form_Roi::onWidgetBaseGeometryChanged,this,&Form_EditorSpace::ROI_onWidgetBaseGeometryChanged);//当基础窗口尺寸被改变
    connect(this->roiWidget,&Form_Roi::onWidgetGeometryChanged,this,&Form_EditorSpace::ROI_onWidgetGeometryChanged);//当组件尺寸被改变
    connect(this->roiWidget,&Form_Roi::onSubWidgetsChanged,this,&Form_EditorSpace::ROI_onSubWidgetsChanged);    //子控件被选择
    connect(this->roiWidget,&Form_Roi::onWidgetSelected,this,&Form_EditorSpace::ROI_onWidgetSelected);          //子控件被选择
    connect(this->roiWidget,&Form_Roi::onWidgetMove,this,&Form_EditorSpace::ROI_onWidgetMove);                  //子控件位置移动

    //初始化MdiArea
    connect(ui->mdiArea,&Widget_MdiArea::event_onResize,this,&Form_EditorSpace::event_onMdiAreaReSize); //链接MdiArea的尺寸改变信息
    connect(ui->mdiArea,&Widget_MdiArea::event_onScrollBarChange,this,&Form_EditorSpace::event_onMdiAreaScrollChange); //链接Mdiarea的滚动条改变

    //绑定属性编辑器
    if(Form::PropertyEditorPtr != nullptr){
        connect(Form::PropertyEditorPtr,&Form_PropertyEditor::onWidgetNameChange,this,&Form_EditorSpace::PRO_onWidgetNameChange);   //对象名称被改变
        connect(Form::PropertyEditorPtr,&Form_PropertyEditor::onWidgetUpdate,this,&Form_EditorSpace::PRO_onWidgetUpdate);           //属性更新
    }


    //初始化主窗口，创建一个最基础的容器控件
    Plugin_MainWindow* plgMW = new Plugin_MainWindow();
    this->baseWidget = plgMW->createWidgetInstance({0,0,450,320});
    this->baseWidget.objectName = "主窗口";//对象名
    this->baseWidget.pluginPtr = plgMW;//处理的插件指针
    this->baseWidget.widget->setObjectName(this->baseWidget.objectName);
    this->baseWidget.isSelect = true;//是否选择
    this->baseWidget.isPack = true;//是否为容器
    this->widgets.append(this->baseWidget); //加入到控件列表
    this->buildTreeWidgetItem(this->baseWidget,true);

    //创建并且设置基础的mdiArea
    this->baseSubWindow = ui->mdiArea->addSubWindow(this->baseWidget.widget); //将底窗口添加到MdiArea
    this->baseSubWindow->setAttribute(Qt::WA_StyledBackground); //脱离父窗口样式的覆盖
    this->baseSubWindow->setWindowFlags(Qt::FramelessWindowHint); //设置无边框
    this->baseSubWindow->setGeometry(this->baseWidget.widget->geometry()); //设置基础的宽高
    this->baseSubWindow->move(10,10);

    //设置为主窗口为选择状态
    this->roiWidget->roi_setWidgetDeleteAllSelect();
    this->roiWidget->roi_setWidgetSelect(this->baseWidget.widget,true);
    this->setRootTreeItem(this->baseWidget.widget);
}



Form_EditorSpace::~Form_EditorSpace()
{
    if(Form::PropertyEditorPtr) Form::PropertyEditorPtr->showWidgetsAttr("",nullptr);
    delete ui;
}


//根据一个初始名字，在列表中获取唯一不重复的名字
QString Form_EditorSpace::getUniqueName(QString baseName)
{
    qsizetype t_startIndex = 0;
    QString t_retNewName = baseName;
    RENAME:
    for(widgetMsg t_widget : this->widgets){   //遍历所有组件
        if(t_retNewName == t_widget.objectName){
            t_startIndex++;
            t_retNewName = baseName+QString::number(t_startIndex); //更新名字
            goto RENAME;
        }
    }
    return t_retNewName;
}


//创建插件，并且加入到列表
QWidget *Form_EditorSpace::createWidgetMsgToList(Plugin_Base* pluginPtr,          //预创建插件的指针
                                                 QRect geometry,                  //需要创建控件的矩形
                                                 Plugin_Base* parentPluginPtr,    //父插件的的指针
                                                 QWidget* parentWidget)           //父控件的指针
{
    //pluginPtr->createWidgetInstance(geometry)
    widgetMsg t_createMsg = pluginPtr->createWidgetInstance(geometry);
    t_createMsg.widget->setParent(parentWidget); //默认先把基础组件设置为父类
    t_createMsg.objectName = this->getUniqueName(t_createMsg.objectName); //修改为唯一名称
    t_createMsg.widget->setObjectName(t_createMsg.objectName);  //同时修改控件的唯一名称
    t_createMsg.classSign = pluginPtr->pluginSign; //插件类型
    parentPluginPtr->subWidgetEnter(parentWidget,t_createMsg.widget); //激活容器组件插件的组件进入方法
    this->widgets.append(t_createMsg); //添加到控件列表信息
    t_createMsg.widget->show();

    //同步组件删除
    connect(t_createMsg.widget,&QWidget::destroyed,[=](){
        //移除widget信息
        for(qsizetype i = this->widgets.length() - 1; i >= 0; i--){
            if(this->widgets[i].widget == t_createMsg.widget){
                this->widgets.removeAt(i);
                break;
            }
        }

        //移除treeItem信息
        for(qsizetype i = this->treeMsgList.length() - 1; i >= 0; i--){
            if(this->treeMsgList[i].msg.widget == t_createMsg.widget){
                delete this->treeMsgList[i].treeItem;
                this->treeMsgList.removeAt(i);
                break;
            }
        }
    });

    //插件Tree信息
    this->buildTreeWidgetItem(t_createMsg);

    return t_createMsg.widget;
}


//获取控件信息列表
QList<widgetMsg>& Form_EditorSpace::getWidgetMsgs()
{
    return this->widgets;
}

//获取编辑容器控件指针
QWidget *Form_EditorSpace::getEditorSpaceWidgetPtr()
{
    return ui->mdiArea;
}

//获取基础控件信息
widgetMsg &Form_EditorSpace::getBaseWidgetMsg()
{
    return this->baseWidget;
}


//创建树组件节点
void Form_EditorSpace::buildTreeWidgetItem(widgetMsg msg,bool isRoot)
{
    QTreeWidgetItem* t_treeItem = new QTreeWidgetItem();
    t_treeItem->setText(0,msg.objectName);
    t_treeItem->setText(1,msg.classSign);

    if(isRoot) ui->treeWidget->addTopLevelItem(t_treeItem);
    this->treeMsgList.append({msg,t_treeItem});

    adjustTreeItem();
}



//根据treeItem获取关联Widget信息
QWidget *Form_EditorSpace::getWidgetToItem(QTreeWidgetItem *item)
{
    for(treeNode node : treeMsgList){
        if(node.treeItem == item){
            return node.msg.widget;
        }
    }
    return nullptr;
}

//设置树根
void Form_EditorSpace::setRootTreeItem(QWidget *baseParent)
{
    for(treeNode node : treeMsgList){
        if(node.msg.widget == baseParent){
            ui->treeWidget->addTopLevelItem(node.treeItem);
            ui->treeWidget->show();
        }
    }
}


//获取Widget父组件的treeItem指针
QTreeWidgetItem *Form_EditorSpace::getWidgetParentTreeItemPtr(QWidget *widget)
{
    QWidget* t_parentWidget = widget;
    STARTFOR:
    t_parentWidget = t_parentWidget->parentWidget();
    if(t_parentWidget != nullptr){
        for(treeNode node : this->treeMsgList){
            if(t_parentWidget == node.msg.widget){
                return node.treeItem;
            }
        }
        goto STARTFOR;
    }
    return nullptr;
}


//调整树item
void Form_EditorSpace::adjustTreeItem()
{
    for(treeNode treeItem : this->treeMsgList){
        if(treeItem.msg.widget != this->baseWidget.widget){
            QTreeWidgetItem* t_ParentTreeItem = this->getWidgetParentTreeItemPtr(treeItem.msg.widget);
            if(t_ParentTreeItem != nullptr && treeItem.treeItem != nullptr){

                //上一个父移除才能设置新父
                QTreeWidgetItem* t_parent = treeItem.treeItem->parent();
                if(t_parent != nullptr){
                    t_parent->removeChild(treeItem.treeItem);
                }

                //添加到新父
                t_ParentTreeItem->addChild(treeItem.treeItem);
                treeItem.treeItem->setExpanded(true);
            }
        }
    }
}


//根据组件列表选择对于的treeItem
void Form_EditorSpace::selectTreeItem(QList<QWidget *> widgets)
{
    for(treeNode treeItem : this->treeMsgList){
        treeItem.treeItem->setSelected(false);
        for(QWidget* widgetItem : widgets){
            if(treeItem.msg.widget == widgetItem){
                treeItem.treeItem->setSelected(true);
                break;
            }
        }
    }
}


//根据组件列表选择对于的treeItem
void Form_EditorSpace::selectTreeItem(QList<widgetMsg> widgets)
{
    for(treeNode treeItem : this->treeMsgList){
        treeItem.treeItem->setSelected(false);
        for(widgetMsg widgetItem : widgets){
            if(treeItem.msg.widget == widgetItem.widget){
                treeItem.treeItem->setSelected(true);
                break;
            }
        }
    }
}


//显示属性
void Form_EditorSpace::showProperty()
{
    if(Form::PropertyEditorPtr){
        QList<widgetMsg> t_ws = this->roiWidget->roi_getSelectWidgetMsgs();
        if(widgets.length() > 0){
            widgetMsg* t_wm = this->getWidgetMsg(t_ws[0].widget);
            Form::PropertyEditorPtr->showWidgetsAttr("",t_wm);
        }
    }
}


//获取Widget信息指针
widgetMsg *Form_EditorSpace::getWidgetMsg(QWidget *widget)
{
    for(qsizetype i = 0; i<widgets.length() ; i++){
        if(this->widgets[i].widget == widget){
            return &this->widgets[i];
        }
    }
    return nullptr;
}


//窗体尺寸被改变
void Form_EditorSpace::resizeEvent(QResizeEvent *event)
{

}


//分割条比例调整
void Form_EditorSpace::on_splitter_splitterMoved(int pos, int index)
{
    //this->resizeEvent(nullptr);
}



//当ROI控件有子控件加入
void Form_EditorSpace::ROI_onSubWidgetsChanged(QWidget *parentWidget)
{
    this->adjustTreeItem();
    this->selectTreeItem(this->roiWidget->roi_getSelectWidgetMsgs());
    this->showProperty();
}

//当ROI控件被选择，参数：选择的控件列表
void Form_EditorSpace::ROI_onWidgetSelected(QList<QWidget *> widgets)
{
    //选择树列表项目
    this->selectTreeItem(widgets);
    //显示属性
    this->showProperty();
}


//当控件移动
void Form_EditorSpace::ROI_onWidgetMove(QList<QWidget *> widgets)
{
    //显示属性
    this->showProperty();
}


//baseWidget尺寸改变
void Form_EditorSpace::ROI_onWidgetBaseGeometryChanged(QRect rect)
{
    this->baseSubWindow->setGeometry(this->baseSubWindow->geometry().left(), //设置基础的宽高
                                     this->baseSubWindow->geometry().top(),
                                     rect.width(),
                                     rect.height());
    //显示属性
    this->showProperty();
}


//组件尺寸改变
void Form_EditorSpace::ROI_onWidgetGeometryChanged(QWidget* widget)
{
    //显示属性
    this->showProperty();
}


//目标控件对象名称被改变
void Form_EditorSpace::PRO_onWidgetNameChange(QString editorSpaceSign, widgetMsg *updateWidgetMessage, QString& newName)
{
    if(editorSpaceSign != this->editorSpaceSign || updateWidgetMessage == nullptr) return;
    newName = this->getUniqueName(newName);
}

//控件属性被更新
void Form_EditorSpace::PRO_onWidgetUpdate(QString editorSpaceSign, widgetMsg *updateWidgetMessage)
{
    this->roiWidget->update();  //如果位置改变，则更改选取样式
}


//当绘画层的滚动条被改变，则立即刷新选区的位置
void Form_EditorSpace::event_onMdiAreaScrollChange(int dx, int dy)
{
    //this->roiWidget->roi_changeRecTopLeft(dx,-dy);
    //this->RoiWidget->roi_ChangeRecTopLeft(dx,dy);
    //this->RoiWidget->update();
}

//MdiArea尺寸改变，修正上面绘画层的选区尺寸
void Form_EditorSpace::event_onMdiAreaReSize(QResizeEvent *resizeEvent)
{
    if(this->roiWidget){
        this->roiWidget->setGeometry(0,0,ui->mdiArea->width() - ui->mdiArea->verticalScrollBar()->width(),ui->mdiArea->height() - ui->mdiArea->horizontalScrollBar()->height()); //调整矩形绘图尺寸
        this->roiWidget->update();  //重画刷新
    }

}





//当TreeItem被点击
void Form_EditorSpace::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    this->roiWidget->roi_setWidgetDeleteAllSelect();
    QList<QTreeWidgetItem*> t_selectedItemList = ui->treeWidget->selectedItems();
    for(treeNode treeItem : this->treeMsgList){
        for(QTreeWidgetItem* si : t_selectedItemList){
            if(treeItem.treeItem == si){
                this->roiWidget->roi_setWidgetSelect(treeItem.msg.widget,true);
                break;
            }
        }
    }
    this->roiWidget->update();
}

