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

    //当基础窗口尺寸被改变
    connect(this->roiWidget,&Form_Roi::onWidgetBaseGeometryChanged,this,&Form_EditorSpace::onParentBaseWidgetGeometryChanged);

//    void onWidgetBaseGeometryChanged(QRect rect);   //当基础窗口尺寸被改变
//    void onWidgetSelected(QList<QWidget*> widgets); //当控件被选择，参数：选择的控件列表
//    void onWidgetGeometryChanged(QWidget* widget);  //当控件尺寸被改变
//    void onSubWidgetsChanged(QWidget* parentWidget);   //当控件有子控件加入

    //初始化MdiArea
    connect(ui->mdiArea,&Widget_MdiArea::event_onResize,this,&Form_EditorSpace::event_onMdiAreaReSize); //链接MdiArea的尺寸改变信息
    connect(ui->mdiArea,&Widget_MdiArea::event_onScrollBarChange,this,&Form_EditorSpace::event_onMdiAreaScrollChange); //链接Mdiarea的滚动条改变


    //初始化主窗口，创建一个最基础的容器控件
    Plugin_MainWindow* plgMW = new Plugin_MainWindow();
    this->baseWidget = plgMW->createWidgetInstance({0,0,450,320});
    this->baseWidget.objectName = "主窗口";//对象名
    this->baseWidget.pluginPtr = new Plugin_MainWindow();//处理的插件指针
    this->baseWidget.isSelect = true;//是否选择
    this->baseWidget.isPack = true;//是否为容器
    this->widgets.append(this->baseWidget); //加入到控件列表

    //创建并且设置基础的mdiArea
    this->baseSubWindow = ui->mdiArea->addSubWindow(this->baseWidget.widget); //将底窗口添加到MdiArea
    this->baseSubWindow->setAttribute(Qt::WA_StyledBackground); //脱离父窗口样式的覆盖
    this->baseSubWindow->setWindowFlags(Qt::FramelessWindowHint); //设置无边框
    this->baseSubWindow->setGeometry(this->baseWidget.widget->geometry()); //设置基础的宽高
    this->baseSubWindow->move(10,10);


    //临时测试代码
    this->createWidgetMsgToList(new Plugin_Button,{20,30,0,0},this->baseWidget.pluginPtr,this->baseWidget.widget);
    this->createWidgetMsgToList(new Plugin_MainWindow,{40,20,300,200},this->baseWidget.pluginPtr,this->baseWidget.widget);


    //设置为主窗口为选择状态
    this->roiWidget->roi_setWidgetDeleteAllSelect();
    this->roiWidget->roi_setWidgetSelect(this->baseWidget.widget,true);
}



Form_EditorSpace::~Form_EditorSpace()
{
    delete ui;
}


//根据一个初始名字，在列表中获取唯一不重复的名字
QString Form_EditorSpace::getUniqueName(QString baseName)
{
    qsizetype t_startIndex = 0;
    QString t_retNewName;
    RENAME:
    t_startIndex++;
    t_retNewName = baseName+QString::number(t_startIndex);
    for(widgetMsg t_widget : this->widgets){   //遍历所有组件
        if(t_retNewName == t_widget.objectName){
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
    parentPluginPtr->subWidgetEnter(parentWidget,t_createMsg.widget); //激活容器组件插件的组件进入方法
    this->widgets.append(t_createMsg); //添加到控件列表信息
    t_createMsg.widget->show();
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


//窗体尺寸被改变
void Form_EditorSpace::resizeEvent(QResizeEvent *event)
{

}


//分割条比例调整
void Form_EditorSpace::on_splitter_splitterMoved(int pos, int index)
{
    //this->resizeEvent(nullptr);
}


//baseWidget尺寸改变
void Form_EditorSpace::onParentBaseWidgetGeometryChanged(QRect rect)
{
    this->baseSubWindow->setGeometry(this->baseSubWindow->geometry().left(), //设置基础的宽高
                                     this->baseSubWindow->geometry().top(),
                                     rect.width(),
                                     rect.height());



//    this->baseSubWindow->move(10,10);

//    if(baseSubWindow && baseWidget.widget){
//        this->baseWidget.widget->setGeometry({0,0,rect.width(),rect.height()});
//        this->baseSubWindow->setGeometry({10,10,rect.width(),rect.height()});
//    }
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
void Form_EditorSpace::event_onTreeItemClick(QWidget *widget)
{
//    RoiWidget->roi_ClearRec(); //清理矩形
//    if(widget == nullptr) return;
//    QRect t_rec = getWidgetAbsolutePos(widget);
//    RoiWidget->roi_AddRec({
//                           {widget,t_rec},
//                           });
//    this->RoiWidget->update();

//    //加载属性信息
//    QVector<Form_Roi::widgetRecMsg> t_widRecMsg = this->RoiWidget->roi_GetAllWidgetPtrs();
//    QVector<Plugin_Base*> t_objs;
//    for(int a = 0;a<t_widRecMsg.length();a++){
//        WidgetClassMsg t_classMsg = this->getWidgetClassMsg(t_widRecMsg[a].widget);
//        if(t_classMsg.classObj != nullptr){
//            t_objs.append(t_classMsg.classObj);
//        }
//    }
//    PropertyEditorPtr->loadPropertyMsgs(t_objs,this); //加载属性信息
}

