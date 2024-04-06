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
    this->roiWidget->roi_setWidgetMsgListPtr(&this->widgets); //设置组件列表指针

    //当基础窗口尺寸被改变
    connect(this->roiWidget,&Form_Roi::onWidgetBaseGeometryChanged,this,&Form_EditorSpace::onParentBaseWidgetGeometryChanged);

//    void onWidgetBaseGeometryChanged(QRect rect);   //当基础窗口尺寸被改变
//    void onWidgetSelected(QList<QWidget*> widgets); //当控件被选择，参数：选择的控件列表
//    void onWidgetGeometryChanged(QWidget* widget);  //当控件尺寸被改变
//    void onSubWidgetsChanged(QWidget* parentWidget);   //当控件有子控件加入

    //初始化MdiArea
    connect(ui->mdiArea,&Widget_MdiArea::event_onResize,this,&Form_EditorSpace::event_onMdiAreaReSize); //链接MdiArea的尺寸改变信息
    connect(ui->mdiArea,&Widget_MdiArea::event_onScrollBarChange,this,&Form_EditorSpace::event_onMdiAreaScrollChange); //链接Mdiarea的滚动条改变


    //创建一个主窗口
    Plugin_MainWindow* plgMW = new Plugin_MainWindow();
    this->baseWidget = plgMW->createWidgetInstance({0,0,450,320});
    this->baseWidget.objectName = "主窗口";//对象名
    this->baseWidget.pluginPtr = new Plugin_MainWindow();//处理的插件指针
    this->baseWidget.isSelect = true;//是否选择
    this->baseWidget.isPack = true;//是否为容器

    //设置最底层窗口为底层编辑窗口
    this->roiWidget->roi_setSpaceWidget(ui->mdiArea);
    this->roiWidget->roi_setParentBaseWidget(this->baseWidget.widget);

    //加入到控件列表
    this->widgets.append(this->baseWidget);

    //创建基础的mdiArea
    this->baseSubWindow = ui->mdiArea->addSubWindow(this->baseWidget.widget); //将底窗口添加到
    this->baseSubWindow->setAttribute(Qt::WA_StyledBackground); //脱离父窗口样式的覆盖
    this->baseSubWindow->setWindowFlags(Qt::FramelessWindowHint); //设置无边框
    this->baseSubWindow->setGeometry(this->baseWidget.widget->geometry()); //设置基础的宽高
    this->baseSubWindow->move(10,10);


    //临时测试代码
    Plugin_Button* plgBtn = new Plugin_Button;
    widgetMsg t_btnMsg = plgBtn->createWidgetInstance({20,30,0,0});
    plgMW->subWidgetEnter(this->baseWidget.widget,t_btnMsg.widget);
    this->widgets.append(t_btnMsg);

    widgetMsg t_wMsg = plgMW->createWidgetInstance({40,20,300,200});
    t_wMsg.isSelect = true;
    plgMW->subWidgetEnter(this->baseWidget.widget,t_wMsg.widget);
    this->widgets.append(t_wMsg);
    t_wMsg.widget->show();

    t_btnMsg = plgBtn->createWidgetInstance({-20,50,200,100});
    plgMW->subWidgetEnter(t_wMsg.widget,t_btnMsg.widget);
    this->widgets.append(t_btnMsg);
    t_btnMsg.widget->show();

/*

    //加载最基础的窗体信息，并且载入到列表
    Plugin_MainWindow* t_mainObj = new Plugin_MainWindow;
    this->widgetClassMsgLsit.append({
        t_mainObj,
        t_mainObj->getWidgetInstance(),
    });



    //操作SubWindow
    this->BaseSubWindow = ui->mdiArea->addSubWindow(t_mainObj->getWidgetInstance()); //将底窗口添加到
    this->BaseSubWindow->setAttribute(Qt::WA_StyledBackground); //脱离父窗口样式的覆盖
    this->BaseSubWindow->setGeometry(t_mainObj->getWidgetInstance()->geometry()); //设置基础的宽高
    this->BaseSubWindow->move(10,10);


    //创建顶部Roi的矩形画框
    this->RoiWidget = new Form_Roi(this);
    this->RoiWidget->raise();



    //将信息插入到列表
    ui->widgetList->addBaseItem(t_mainObj->getWidgetInstance(),QIcon(":/Logo/icon/Logo/Logo_32.png"),"主窗口","QMainWidget");
    connect(ui->widgetList,&Widget_widgetList::event_onItemClick,this,&Form_EditorSpace::event_onTreeItemClick); //连接TreeWidget项目被点击
*/
}



Form_EditorSpace::~Form_EditorSpace()
{
    delete ui;
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

