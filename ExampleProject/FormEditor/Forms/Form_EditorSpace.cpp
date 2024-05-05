#include "Form_EditorSpace.h"

#include "QMdiSubWindow"
#include "QKeyEvent"
#include "QMenu"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"
#include "QFile"
#include "util/FunUtil.h"

#include "Plugins/Plugin_MainWindow.h"
#include "Form_PropertyEditor.h"
#include "Form_WidgetBox.h"


#include "GlobalMsg.h"
#include "QScrollBar"

Form_EditorSpace::Form_EditorSpace(QWidget *parent,QString jsonPath) :
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
    if(jsonPath.isEmpty()){
        //没有配置文件，直接创建基础窗口
        Plugin_MainWindow* plgMW = new Plugin_MainWindow();
        this->baseWidget = plgMW->createWidgetInstance({0,0,450,320});
        this->baseWidget.objectName = "主窗口";//对象名
        this->baseWidget.pluginPtr = plgMW;//处理的插件指针
        this->baseWidget.widget->setObjectName(this->baseWidget.objectName);
        this->baseWidget.isSelect = true;//是否选择
        this->baseWidget.isPack = true;//是否为容器
        this->widgets.append(this->baseWidget); //加入到控件列表
        this->buildTreeWidgetItem(this->baseWidget,true);
    }
    else{
        //根据配置文件读取json数据
        QFile t_file(jsonPath);
        t_file.open(QIODevice::ReadOnly);
        this->jsonBuildWidgetMsgs(t_file.readAll());
        t_file.close();
    }




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
    this->adjustTreeItem();     //调整树item

    //显示属性
    this->showProperty();

    //创建右键菜单
    mouseRightMenu = new QMenu(this);
    menuActionRaise = mouseRightMenu->addAction("到最顶层");
    menuActionLower = mouseRightMenu->addAction("到最底层");
    mouseRightMenu->addSeparator();
    menuActionCat = mouseRightMenu->addAction("剪切");
    menuActionCopy = mouseRightMenu->addAction("复制");
    menuActionPaste = mouseRightMenu->addAction("粘贴");
    mouseRightMenu->addSeparator();
    menuActionDel = mouseRightMenu->addAction("删除");
    mouseRightMenu->addSeparator();
    menuActionStyle = mouseRightMenu->addAction("更改样式表");
    connect(mouseRightMenu,&QMenu::triggered,this,&Form_EditorSpace::on_menuTriggered); //事件激发
}



Form_EditorSpace::~Form_EditorSpace()
{
    if(Form::PropertyEditorPtr) Form::PropertyEditorPtr->showWidgetsAttr(nullptr,nullptr);
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
    //t_createMsg.pluginSign = pluginPtr->pluginSign; //插件类型
    parentPluginPtr->subWidgetEnter(parentWidget,t_createMsg.widget); //激活容器组件插件的组件进入方法
    this->widgets.append(t_createMsg); //添加到控件列表信息
    t_createMsg.widget->show();

    this->setSyncDeleteWidget(t_createMsg.widget);  //绑定同步删除方法

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

//弹出菜单
void Form_EditorSpace::showMenu(QWidget* widget, QPoint pos)
{
    this->menuSelectWidget = widget;
    if(!this->menuSelectWidget) return;
    this->mouseRightMenu->exec(pos);
}

//获取当前以及子项目的widgetMsg信息组
QList<widgetMsg> Form_EditorSpace::getFamilyWidgetMsg(QWidget *parent)
{
    QList<widgetMsg> t_retSubs;
    for(widgetMsg w : this->widgets){
        if(w.widget == parent){
            t_retSubs.append(w);
            QList<QWidget*> t_parentChilds = parent->findChildren<QWidget*>(Qt::FindChildrenRecursively);
            for(QWidget* child : t_parentChilds){
                for(widgetMsg wi : this->widgets){
                    if(wi.widget == child){
                        t_retSubs.append(wi);
                        break;
                    }
                }
            }
            break;
        }
    }
    return t_retSubs;
}




//保存配置信息
QString Form_EditorSpace::widgetMsgsToJson(QList<widgetMsg> widgetList)
{
    QJsonDocument t_doc;
    QJsonObject t_jsonObj;
    QJsonArray t_jsonArray;

    t_jsonObj.insert("version",1);                                          //版本
    t_jsonObj.insert("develop","DEV");                                      //开发渠道
    t_jsonObj.insert("baseName",this->baseWidget.widget->objectName());     //基础名字
    for(widgetMsg msgItem : widgetList){
        QJsonObject t_itemJsonObj;
        t_itemJsonObj.insert("objName",msgItem.objectName);                                         //对象名
        t_itemJsonObj.insert("geometry",FunUtil::rectToString(msgItem.widget->geometry()));         //矩形区域
        t_itemJsonObj.insert("minimumSize",FunUtil::sizeToString(msgItem.widget->minimumSize()));   //最小尺寸
        t_itemJsonObj.insert("maximumSize",FunUtil::sizeToString(msgItem.widget->maximumSize()));   //最大尺寸
        t_itemJsonObj.insert("pluginSign",msgItem.pluginPtr->pluginSign);                                      //类标记
        t_itemJsonObj.insert("isPack",msgItem.isPack);                                              //是否为尺寸
        t_itemJsonObj.insert("attrs",Plugin_Base::attributesToJson(msgItem.attrs));                 //属性标记
        t_itemJsonObj.insert("style",QString(msgItem.widget->styleSheet().toUtf8().toHex()));       //样式表
        t_itemJsonObj.insert("config",msgItem.pluginPtr->getConfigure(msgItem));                    //自定义配置信息
        t_jsonArray.append(t_itemJsonObj);
    }
    t_jsonObj.insert("widgets",t_jsonArray);
    t_doc.setObject(t_jsonObj);
    return t_doc.toJson();
}


//根据Json文本构建对象
bool Form_EditorSpace::jsonBuildWidgetMsgs(QString jsonString)
{
    this->widgets.clear();
    this->treeMsgList.clear();

    QJsonDocument t_jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());
    QJsonObject t_jsonObj = t_jsonDoc.object();

    int t_version = t_jsonObj.value("varsion").toInt(1);
    QString t_develop = t_jsonObj.value("develop").toString("DEV");
    QString t_baseName = t_jsonObj.value("baseName").toString();

    struct t_widgetMsgAttach{
        widgetMsg wmsg;
        QJsonArray attrJson;
        QString styleSheet;
        QJsonValue config;
    };

    //根据配置文件创建信息
    QList<t_widgetMsgAttach> t_tempWidgetMsgs;  //临时存放对象列表
    QJsonArray t_jsonArray = t_jsonObj.value("widgets").toArray();
    for(QJsonValue t_jsonValue : t_jsonArray){
        QJsonObject t_itemJsonObj = t_jsonValue.toObject();
        if(!Form::widgetBoxPtr) return false;

        QString t_pluginSign = t_itemJsonObj.value("pluginSign").toString();
        Plugin_Base* t_plugin = Form::widgetBoxPtr->findPluginBySign(t_pluginSign); //根据插件标记获取插件
        if(!t_plugin)return false;

        QRect t_geometry = FunUtil::stringToRect(t_itemJsonObj.value("geometry").toString()).toRect();  //矩形区域

        //直接初始化的信息
        t_widgetMsgAttach t_wma;
        t_wma.wmsg = t_plugin->createWidgetInstance(t_geometry); //获取控件信息
        t_wma.wmsg.isPack = t_itemJsonObj.value("isPack").toBool();        //包标记
        t_wma.wmsg.objectName = t_itemJsonObj.value("objName").toString(); //设置对象名
        t_wma.wmsg.widget->setObjectName(t_wma.wmsg.objectName);
        t_wma.wmsg.widget->setMinimumSize(FunUtil::stringToSize(t_itemJsonObj.value("minimumSize").toString()).toSize());  //最小尺寸
        t_wma.wmsg.widget->setMaximumSize(FunUtil::stringToSize(t_itemJsonObj.value("maximumSize").toString()).toSize());  //最大尺寸

        //暂时不能初始化的信息
        t_wma.attrJson = t_itemJsonObj.value("attrs").toArray();  //设置属性
        t_wma.styleSheet = QByteArray::fromHex(t_itemJsonObj.value("style").toString().toUtf8());    //设置样式表
        t_wma.config = t_itemJsonObj.value("config");   //自定义配置信息

        //保存基础base
        if(t_wma.wmsg.objectName == t_baseName){
            this->baseWidget = t_wma.wmsg;
        }

        t_tempWidgetMsgs.append(t_wma);
    }

    //获取组件方法
    Fun_Get_Widget fun_getWidget = [&](QString objName)->QWidget*{
        for(t_widgetMsgAttach& wmaItem : t_tempWidgetMsgs){
            if(wmaItem.wmsg.objectName == objName){
                return wmaItem.wmsg.widget;
            }
        }
        return nullptr;
    };

    //全局加入到父窗口信息
    for(t_widgetMsgAttach& wmaItem : t_tempWidgetMsgs){
        if(this->baseWidget.widget && wmaItem.wmsg.widget != this->baseWidget.widget){  //设置默认父组件
            wmaItem.wmsg.widget->setParent(this->baseWidget.widget);
            this->setSyncDeleteWidget(wmaItem.wmsg.widget); //绑定同步删除配置信息
        }
        //创建树信息
        this->buildTreeWidgetItem(wmaItem.wmsg,false);
    }

    //调整属性与配置文件
    for(t_widgetMsgAttach& wmaItem : t_tempWidgetMsgs){
        wmaItem.wmsg.attrs = Plugin_Base::jsonArrayToAttrs(wmaItem.attrJson);   //以json更新attr
        wmaItem.wmsg.pluginPtr->adjustWidget(wmaItem.wmsg.widget,wmaItem.wmsg.attrs);   //更新属性
        wmaItem.wmsg.widget->setStyleSheet(wmaItem.styleSheet); //更新style
        wmaItem.wmsg.pluginPtr->configAdjustWidgetMsg(wmaItem.wmsg,wmaItem.config,fun_getWidget);   //更新配置文件

        this->widgets.append(wmaItem.wmsg); //保存组件信息
    }
    return true;
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
        if(t_ws.length() > 0){
            widgetMsg* t_wm = this->getWidgetMsg(t_ws[0].widget);
            Form::PropertyEditorPtr->showWidgetsAttr(this->baseWidget.widget,t_wm);
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


//绑定同步删除
void Form_EditorSpace::setSyncDeleteWidget(QWidget *widget)
{
    //同步组件删除
    connect(widget,&QWidget::destroyed,[=](){

        qDebug() << "删除Widget信息" << widget;

        //移除widget信息
        for(qsizetype i = this->widgets.length() - 1; i >= 0; i--){
            if(this->widgets[i].widget == widget){
                this->widgets.removeAt(i);
                break;
            }
        }

        //移除treeItem信息
        for(qsizetype i = this->treeMsgList.length() - 1; i >= 0; i--){
            if(this->treeMsgList[i].msg.widget == widget){
                //移除子树
                for(int a = this->treeMsgList[i].treeItem->childCount() - 1; a>=0; a--){
                    this->treeMsgList[i].treeItem->removeChild(this->treeMsgList[i].treeItem->child(a));
                }
                //回收本对象
                delete this->treeMsgList[i].treeItem;
                this->treeMsgList.removeAt(i);
                break;
            }
        }

        //关闭对象属性
        if(Form::PropertyEditorPtr) Form::PropertyEditorPtr->showWidgetsAttr(nullptr,nullptr);
    });
}


//复制组件
void Form_EditorSpace::copyWidgets()
{
    this->copyList.clear();
    for(widgetMsg witem : this->widgets){
        if(witem.isSelect){ //如果是选择的话

        }
    }
}


//菜单触发
void Form_EditorSpace::on_menuTriggered(QAction *action)
{
    widgetMsg* t_msg = this->getWidgetMsg(this->menuSelectWidget);
    if(!t_msg) return;

    //到最顶层
    if(action == menuActionRaise){
        t_msg->widget->raise();
    }
    //到最底层
    else if(action == menuActionLower){
        t_msg->widget->lower();
    }
    //剪切
    else if(action == menuActionCat){
        qDebug().noquote() << this->widgetMsgsToJson(this->widgets);
    }
    //复制
    else if(action == menuActionCopy){

    }
    //粘贴
    else if(action == menuActionPaste){

    }
    //删除
    else if(action == menuActionDel){
        if(t_msg->widget != this->baseWidget.widget)
        delete t_msg->widget;
    }
    //样式表
    else if(action == menuActionStyle){
        t_msg->widget->lower();
    }
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
    if(this->baseWidget.widget) this->baseWidget.widget->setGeometry(0,0,rect.width(),rect.height());
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
void Form_EditorSpace::PRO_onWidgetNameChange(QWidget* widgetBase, widgetMsg *updateWidgetMessage, QString& newName)
{
    if(widgetBase != this->baseWidget.widget || updateWidgetMessage == nullptr) return;
    newName = this->getUniqueName(newName);
}

//控件属性被更新
void Form_EditorSpace::PRO_onWidgetUpdate(QWidget* widgetBase, widgetMsg *updateWidgetMessage)
{
    if(widgetBase != this->getEditorSpaceWidgetPtr())return;
    if(updateWidgetMessage->widget == this->baseWidget.widget){ //如果是底层窗口改变
        this->ROI_onWidgetBaseGeometryChanged(this->baseWidget.widget->geometry());
    }

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
                this->showProperty();
                break;
            }
        }
    }
    this->roiWidget->update();
}

//控件树右键被点击
void Form_EditorSpace::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    this->showMenu(getWidgetToItem(ui->treeWidget->currentItem()),QCursor().pos());
}

