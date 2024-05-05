#ifndef FORM_ROI_H
#define FORM_ROI_H

#include <QWidget>
#include "GlobalMsg.h"
#include "QPoint"

class Form_EditorSpace; //插件编辑器指针

namespace Ui {
class Form_Roi;
}

class Form_Roi : public QWidget
{
    Q_OBJECT


private:
    Ui::Form_Roi *ui;

//    QWidget* parentBase = nullptr;              //基础父空间组件，用于定位基础组件的位置
//    QWidget* editorSpaceWidget = nullptr;       //编辑定位的基础组件,用于确定基础父控件的偏移

    Form_EditorSpace* editorSpaceForm = nullptr;    //编辑器空间

//    QList<widgetMsg>* widgets; //roi矩形组
    QColor roiColor = QColor(0,0,128); //选区颜色
    QColor roiBorderLineColor = QColor(202, 204, 207);        //描边线条颜色
    QColor roiMoveLineColor = QColor(100,100,100);          //移动轮廓线条颜色
    QColor roiPositionLineColor = QColor(83, 138, 237);      //距离指示器线条颜色
    QColor positionSignTextColor = QColor(75, 123, 236);     //位置标记文本颜色
    QColor regionBoxColor = QColor(83, 138, 237,100);          //鼠标框选区域填充
    QColor packSignColor = QColor(83, 138, 237,40);          //容器标记颜色
    QColor packSignOldColor = QColor(26, 155, 52);          //老容器描边颜色
    QColor packSignTextColor = QColor(6, 82, 221);          //容器标记颜色

    int roiWidth = 6; //边框点的尺寸
    QPixmap* formPixmap = nullptr; //窗口绘画内容

    int offsetX = 0;    //X位置的偏移
    int offsetY = 0;    //Y位置的偏移


    bool startOnBase = false; //开始点击的位置是否实在最底层的parendBase窗口上面
    QPoint startPoint;  //鼠标按下的开始坐标
    QPoint movePoint;   //鼠标正在移动的坐标

    bool ctrlDown = false;  //ctrl控制多选，判断是否为多选，false为假多选
    bool mouseDown = false; //鼠标是否按下

    QWidget* nowSelectWidget = nullptr; //当前选择的Widget指针
    int nowSelectWidgetType = -1;       //当前选择Widget的方位
    widgetMsg nowSelectPackMsg;         //当前选择的容器
    QRect nowSelectPackLocation;        //当前选择的容器位置

    QRect afterRect;    //控件调整后的尺寸

public:
    explicit Form_Roi(QWidget *parent);
    ~Form_Roi();


public:
//    void roi_setSpaceWidget(QWidget* spaceEdit);    //设置空间组件，绘画都是以这个为定位
//    void roi_setParentBaseWidget(QWidget* parent);    //设置描述父空间组件
//    void roi_setWidgetMsgListPtr(QList<widgetMsg>* widgetMsgs); //添加组件列表指针
    void roi_setStyle(QColor roiColor,int wid = 6); //设置选取样式
    QList<widgetMsg> roi_getSelectWidgetMsgs();     //取出控件组中被选中的控件
    void roi_setWidgetSelect(QWidget* widget, bool isSelect = true);   //设置某个组件被选中的状态
    void roi_setWidgetSelectReversal(QWidget* widget);   //设置某个组件选中反转
    void roi_selectRectWidget(QRect rect);  //选择在此范围内的所有控件
    void roi_setWidgetDeleteAllSelect();    //设置组件全都不被选中
    void roi_setWidgetDeleteAllSelectforParent(QWidget* parent);    //设置某个父组件下的子组件全都不被选中

private:
    void drawPix(); //画选区
    void drawArrowLine(QPainter* painter,int x1,int y1,int x2,int y2,bool drawRangeText = true); //绘制带箭头的线条，并且显示距离文本
    void drawRulerLine(QPainter* painter,QPoint start,int length,bool isRows); //绘制测量标线
    void getArrowPosition(QPoint begin,QPoint end,QPoint& arrow1,QPoint& arrow2,int arrowLineLength = 4);   //根据起始与中止点的坐标计算出箭头中止点的坐标
    bool isListWidget(QWidget* widget,widgetMsg*& msg); //判断当前控件是否为控件列表中的控件
    QWidget* getExistWidget(QWidget* widget);   //获取widget在列表中存在的widget
    void adjustSelect(QWidget* parentWidget); //调整选取选择项，父类和子类都被选择，则主动放弃子类
    void adjustMouseStyle(int mouseX,int mouseY);    //调整鼠标的样式
    int getWidgetLocationState(int x,int y,widgetMsg& msg); //获取组件的位置状态，位置方位为1-8，-1为错误。widgetMsg为引用，若正常，则包含组件信息
    bool hasPack(int x,int y,widgetMsg& retMsg,QRect& retRect); //判断在当前位置是否存在容器
    bool isSubWidget(QWidget* parent,QWidget* subWidget);   //判断subWidget是否为parent的子控件

protected:
    void mousePressEvent(QMouseEvent *event) override; //鼠标按下
    void mouseReleaseEvent(QMouseEvent *event) override; //鼠标放开
    void mouseDoubleClickEvent(QMouseEvent *event) override; //鼠标双击
    void mouseMoveEvent(QMouseEvent *event) override; //鼠标移动

    void paintEvent(QPaintEvent *event) override; //重写绘制方法
    void resizeEvent(QResizeEvent *event) override; //尺寸改变

    void keyPressEvent(QKeyEvent *event) override;      //按键被按下
    void keyReleaseEvent(QKeyEvent *event) override;    //按键被放开

signals:
    void onWidgetBaseGeometryChanged(QRect rect);   //当基础窗口尺寸被改变
    void onWidgetSelected(QList<QWidget*> widgets); //当控件被选择，参数：选择的控件列表
    void onWidgetGeometryChanged(QWidget* widget);  //当控件尺寸被改变
    void onWidgetMove(QList<QWidget*> widgets);     //当控件位置移动
    void onSubWidgetsChanged(QWidget* parentWidget);   //当控件有子控件加入


};

#endif // FORM_ROI_H
