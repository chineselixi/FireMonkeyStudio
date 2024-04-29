#include "Form_Roi.h"
#include "ui_Form_Roi.h"
#include "QPainter"
#include "QMouseEvent"
#include "util/FunUtil.h"
#include "Plugins/Plugin_Base.h"
#include "Forms/Form_EditorSpace.h"

Form_Roi::Form_Roi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_Roi)
{
    ui->setupUi(this);

    //保存父类控件
    this->editorSpaceForm = (Form_EditorSpace*)parent;

    //根据出口尺寸，创建新的位图信息
    this->formPixmap = new QPixmap(this->width(),this->height());

    //设置焦点策略,这样tab和ctrl才有响应
    this->setFocusPolicy(Qt::StrongFocus);

    //允许鼠标移动策略
    this->setMouseTracking(true);
}

Form_Roi::~Form_Roi()
{
    delete ui;
}


////设置空间组件，绘画都是以这个为定位
//void Form_Roi::roi_setSpaceWidget(QWidget *spaceEdit)
//{
//    this->editorSpaceForm->getEditorSpaceWidgetPtr() = spaceEdit;
//}

////设置描述父空间组件
//void Form_Roi::roi_setthis->editorSpaceForm->getBaseWidgetMsg().widgetWidget(QWidget *parent)
//{
//    this->editorSpaceForm->getBaseWidgetMsg().widget = parent;
//}


////添加组件列表指针
//void Form_Roi::roi_setWidgetMsgListPtr(QList<widgetMsg> *widgetMsgs)
//{
//    this->editorSpaceForm->getWidgetMsgs() = widgetMsgs;
//}


//设置选取样式
void Form_Roi::roi_setStyle(QColor roiColor, int wid)
{
    this->roiColor = roiColor;
    this->roiWidth = wid;
}


//取出控件组中被选中的控件
QList<widgetMsg> Form_Roi::roi_getSelectWidgetMsgs()
{
    QList<widgetMsg> t_retMsg;
    for(widgetMsg t_widget : this->editorSpaceForm->getWidgetMsgs()){
        if(t_widget.isSelect){
            t_retMsg.append(t_widget);
        }
    }
    return t_retMsg;
}


//设置某个组件被选中的状态
void Form_Roi::roi_setWidgetSelect(QWidget *widget, bool isSelect)
{
    for(widgetMsg& item : this->editorSpaceForm->getWidgetMsgs()){
        if(item.widget == widget){
            item.isSelect = isSelect;
            return;
        }
    }

    //如果当前控件不在列表中，则搜索其父控件
    widget = widget->parentWidget();
    if(widget){
        roi_setWidgetSelect(widget,isSelect);
    }
}


//选择在此范围内的所有控件
void Form_Roi::roi_selectRectWidget(QRect rect)
{
    //调整选择区域的数值，让宽高不为负数
    int x,y,w,h;
    x = rect.x();
    y = rect.y();
    w = rect.width();
    h = rect.height();
    if(w < 0){x += w;}
    if(h < 0){y += h;}
    w = abs(rect.width());
    h = abs(rect.height());
    QRect t_newRect(x,y,w,h);


    //根据范围，选择范围内的控件
    for(widgetMsg& item : this->editorSpaceForm->getWidgetMsgs()){
        if(this->editorSpaceForm->getEditorSpaceWidgetPtr()){
            QRect t_wRect;
            if(FunUtil::getWidgetRelativePosition(item.widget,this->editorSpaceForm->getEditorSpaceWidgetPtr(),t_wRect)){
                if((t_wRect.left() > t_newRect.left() && t_wRect.left() < t_newRect.right()) ||
                    (t_wRect.right() < t_newRect.right() && t_wRect.right() > t_newRect.left())){
                    if((t_wRect.top() > t_newRect.top() && t_wRect.top() < t_newRect.bottom()) ||
                        (t_wRect.bottom() < t_newRect.bottom() && t_wRect.bottom() > t_newRect.top())){
                        item.isSelect = true;
                        continue;
                    }

                }
            }
        }
        item.isSelect = false;
    }
}


//设置组件全都不被选中
void Form_Roi::roi_setWidgetDeleteAllSelect()
{
    for(widgetMsg& item : this->editorSpaceForm->getWidgetMsgs()){
        item.isSelect = false;
    }
}


//设置某个父组件下的子组件全都不被选中
void Form_Roi::roi_setWidgetDeleteAllSelectforParent(QWidget* parent)
{
    QList<QWidget*> childrens = parent->findChildren<QWidget*>();
    for(QWidget* c : childrens){
        for(widgetMsg& item : this->editorSpaceForm->getWidgetMsgs()){
            if(item.widget == c){
                item.isSelect = false;
            }
        }
    }
}


//画选区
void Form_Roi::drawPix()
{
    //获取主窗口相对于编辑空间的偏移
    if(!(this->editorSpaceForm->getBaseWidgetMsg().widget && this->editorSpaceForm->getEditorSpaceWidgetPtr())) return;
    QRect t_pRec;
    if(FunUtil::getWidgetRelativePosition(this->editorSpaceForm->getBaseWidgetMsg().widget,this->editorSpaceForm->getEditorSpaceWidgetPtr(),t_pRec)){
        this->offsetX = t_pRec.left();
        this->offsetY = t_pRec.top();
    }
    else{
        return;
    }


    //取出选中的控件
    QList<widgetMsg> t_selectWidgets = this->roi_getSelectWidgetMsgs();


    //开始绘制
    QPainter t_painter(formPixmap);
    t_painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing); //抗锯齿
    formPixmap->fill(Qt::transparent); //透明色填充

    if(this->editorSpaceForm->getWidgetMsgs().length() == 0)return;
    //绘制描边虚线
    QPen t_pen(Qt::DashLine);
    QBrush t_brush;
    QFont t_font;

    t_pen.setWidth(1);
    t_pen.setColor(roiBorderLineColor);
    t_brush.setStyle(Qt::BrushStyle::NoBrush);
    t_font.setPixelSize(12);
    t_painter.setPen(t_pen);
    t_painter.setBrush(t_brush);
    t_painter.setFont(t_font);
    t_painter.setRenderHint(QPainter::Antialiasing, true);  // 可选，抗锯齿设置
    QList<QRect> t_rosRecs;
    for(widgetMsg t_widget : t_selectWidgets){
        QRect t_rect;    //获取矩形
        if(!FunUtil::getWidgetRelativePosition(t_widget.widget,this->editorSpaceForm->getBaseWidgetMsg().widget,t_rect)){
            return;
        }

        t_rosRecs.append({
            t_rect.left() + this->offsetX - this->roiWidth / 2,
            t_rect.top() + this->offsetY - this->roiWidth / 2,
            t_rect.width() + this->roiWidth,
            t_rect.height() + this->roiWidth
        });
    }
    t_painter.drawRects(t_rosRecs); //画出描边虚线


    //绘制四周定位矩形
    t_pen.setStyle(Qt::PenStyle::NoPen);
    t_brush.setStyle(Qt::BrushStyle::SolidPattern);
    t_brush.setColor(this->roiColor);
    t_painter.setPen(t_pen);
    t_painter.setBrush(t_brush);
    t_rosRecs.clear();
    for(widgetMsg t_widget : t_selectWidgets){
        /*
         * 1 2 3
         * 4   5
         * 6 7 8
        */
        QRect t_rect;    //获取矩形
        if(!FunUtil::getWidgetRelativePosition(t_widget.widget,this->editorSpaceForm->getBaseWidgetMsg().widget,t_rect)){
            return;
        }

        t_rosRecs.append({  //填充一个矩形的各个点位
            {
                t_rect.left() + this->offsetX - this->roiWidth,
                t_rect.top() + this->offsetY - this->roiWidth,
                this->roiWidth,
                this->roiWidth
            },  //1
            {
                t_rect.left() + this->offsetX + (t_rect.width() - this->roiWidth) / 2,
                t_rect.top() + this->offsetY - this->roiWidth,
                this->roiWidth,
                this->roiWidth
            },  //2
            {
                t_rect.left() + this->offsetX + t_rect.width(),
                t_rect.top() + this->offsetY - this->roiWidth,
                this->roiWidth,
                this->roiWidth
            },  //3
            {
                t_rect.left() + this->offsetX - this->roiWidth,
                t_rect.top() + this->offsetY + (t_rect.height() - this->roiWidth) / 2,
                this->roiWidth,
                this->roiWidth
            },  //4
            {
                t_rect.left() + this->offsetX + t_rect.width(),
                t_rect.top() + this->offsetY + (t_rect.height() - this->roiWidth) / 2,
                this->roiWidth,
                this->roiWidth
            },  //5
            {
                t_rect.left() + this->offsetX - this->roiWidth,
                t_rect.top() + this->offsetY + t_rect.height(),
                this->roiWidth,
                this->roiWidth
            },  //6
            {
                t_rect.left() + this->offsetX + (t_rect.width() - this->roiWidth) / 2,
                t_rect.top() + this->offsetY + t_rect.height(),
                this->roiWidth,
                this->roiWidth
            },  //7
            {
                t_rect.left() + this->offsetX + t_rect.width(),
                t_rect.top() + this->offsetY + t_rect.height(),
                this->roiWidth,
                this->roiWidth
            },  //8
        });
    }
    t_painter.drawRects(t_rosRecs); //画出定位矩形


    //画出定位虚线（只是一个控件的前提下才绘制定位虚线）
    if(t_selectWidgets.length() == 1 && this->mouseDown && Plugin::nowSelectPlugin == nullptr){
        t_brush.setStyle(Qt::BrushStyle::NoBrush);
        t_painter.setBrush(t_brush);

        QWidget* t_objWidget = t_selectWidgets[0].widget;
        if(t_objWidget != this->editorSpaceForm->getBaseWidgetMsg().widget){    //不是底层窗口才开启定位
            QRect t_objRect;
            if(!FunUtil::getWidgetRelativePosition(t_objWidget,this->editorSpaceForm->getBaseWidgetMsg().widget,t_objRect)){
                return;
            }

            QWidget* t_parentWidget = t_objWidget->parentWidget();
            if(t_parentWidget != nullptr){ //存在父窗口，查询子窗口
                if(t_parentWidget == this->editorSpaceForm->getEditorSpaceWidgetPtr()){
                    t_parentWidget = this->editorSpaceForm->getBaseWidgetMsg().widget;
                }

                QRect t_parentRect;
                if(!FunUtil::getWidgetRelativePosition(t_parentWidget,this->editorSpaceForm->getBaseWidgetMsg().widget,t_parentRect)){  //父窗口矩形
                    return;
                }

                //绘制与父窗口相对的定位线条
                t_pen.setColor(roiPositionLineColor);
                t_painter.setPen(t_pen);
                int x,y;

                //画顶边和底边的线条
                x = t_objRect.left() + t_objRect.width() / 2;
                this->drawArrowLine(&t_painter,x + this->offsetX,t_objRect.top() + this->offsetY,x + this->offsetX,t_parentRect.y() + this->offsetY); //顶边的线条
                this->drawArrowLine(&t_painter,x + this->offsetX,t_objRect.bottom() + this->offsetY,x + this->offsetX,t_parentRect.bottom() + this->offsetY,false); //底边的线条

                //画左边和右边的线条
                y = t_objRect.top() + t_objRect.height() / 2;
                this->drawArrowLine(&t_painter,t_objRect.left() + this->offsetX,y + this->offsetY,t_parentRect.x() + this->offsetX,y + this->offsetY); //左边的线条
                this->drawArrowLine(&t_painter,t_objRect.right() + this->offsetX,y + this->offsetY,t_parentRect.right() + this->offsetX,y + this->offsetY,false); //右边的线条


                //画测量标线
                //横测量线
                this->drawRulerLine(&t_painter,QPoint(t_objRect.left() + this->offsetX,t_objRect.bottom() + this->offsetY),t_objRect.width(),true);
                //竖测量线
                this->drawRulerLine(&t_painter,QPoint(t_objRect.right() + this->offsetX,t_objRect.top() + this->offsetY),t_objRect.height(),false);


                //如果不是在this->editorSpaceForm->getBaseWidgetMsg().widget容器内的最底层控件，则控件还根据this->editorSpaceForm->getBaseWidgetMsg().widget再次渲染距离
                if(this->editorSpaceForm->getBaseWidgetMsg().widget != nullptr && t_parentWidget != this->editorSpaceForm->getBaseWidgetMsg().widget){
                    QRect t_widgetParentRect;
                    if(FunUtil::getWidgetRelativePosition(t_parentWidget,this->editorSpaceForm->getEditorSpaceWidgetPtr(),t_widgetParentRect)){

                        t_pen.setStyle(Qt::PenStyle::SolidLine);
                        t_pen.setWidth(1);
                        t_pen.setColor(roiBorderLineColor);
                        t_painter.setPen(t_pen);
                        t_painter.drawRect(t_widgetParentRect);
                    }

                }
            }
        }
    }






    //绘制鼠标选框(如果起始是在this->editorSpaceForm->getBaseWidgetMsg().widget且不在定位标记，或没有选择当前插件)
    if(((this->startOnBase && this->nowSelectWidgetType == -1) || Plugin::nowSelectPlugin != nullptr) && this->mouseDown){
        t_pen.setStyle(Qt::PenStyle::NoPen);
        t_brush.setStyle(Qt::BrushStyle::SolidPattern);
        t_brush.setColor(regionBoxColor);
        t_painter.setPen(t_pen);
        t_painter.setBrush(t_brush);
        t_painter.drawRect(QRect(this->startPoint.x(),this->startPoint.y(),this->movePoint.x() - this->startPoint.x(),this->movePoint.y() - this->startPoint.y()));
    }
    else{
        //绘制移动标记框（鼠标按下，存在组件被选择）
        if(this->mouseDown && t_selectWidgets.length() > 0){
            t_rosRecs.clear();
            int t_x = 0,t_y = 0; //x与y轴的差值

            //当控件大小被调整的时候（控件调整的位置ID范围为1-8，对应从左到右，从上到下的8个点）
            if(this->nowSelectWidgetType >= 1 && this->nowSelectWidgetType <= 8){
                QRect t_nowRect;
                if(FunUtil::getWidgetRelativePosition(this->nowSelectWidget,this->editorSpaceForm->getBaseWidgetMsg().widget,t_nowRect)){
                    t_rosRecs.clear();
                    t_nowRect = QRect(t_nowRect.left() + offsetX,t_nowRect.top() + offsetY,t_nowRect.width(),t_nowRect.height());
                    switch(this->nowSelectWidgetType){  //1-8都为缩放效果
                    case 1:{
                        t_nowRect.setLeft(this->movePoint.x());
                        if(this->movePoint.x() > t_nowRect.right() - 16)t_nowRect.setLeft(t_nowRect.right() - 16);
                        t_nowRect.setTop(this->movePoint.y());
                        if(this->movePoint.y() > t_nowRect.bottom() - 16)t_nowRect.setTop(t_nowRect.bottom() - 16);
                        break;
                    }
                    case 2:{
                        t_nowRect.setTop(this->movePoint.y());
                        if(this->movePoint.y() > t_nowRect.bottom() - 16)t_nowRect.setTop(t_nowRect.bottom() - 16);
                        break;
                    }
                    case 3:{
                        t_nowRect.setRight(this->movePoint.x());
                        if(this->movePoint.x() < t_nowRect.left() + 16)t_nowRect.setRight(t_nowRect.left() + 16);
                        t_nowRect.setTop(this->movePoint.y());
                        if(this->movePoint.y() > t_nowRect.bottom() - 16)t_nowRect.setTop(t_nowRect.bottom() - 16);
                        break;
                    }
                    case 4:{
                        t_nowRect.setLeft(this->movePoint.x());
                        if(this->movePoint.x() > t_nowRect.right() - 16)t_nowRect.setLeft(t_nowRect.right() - 16);
                        break;
                    }
                    case 5:{
                        t_nowRect.setRight(this->movePoint.x());
                        if(this->movePoint.x() < t_nowRect.left() + 16)t_nowRect.setRight(t_nowRect.left() + 16);
                        break;
                    }
                    case 6:{
                        t_nowRect.setLeft(this->movePoint.x());
                        if(this->movePoint.x() > t_nowRect.right() - 16)t_nowRect.setLeft(t_nowRect.right() - 16);
                        t_nowRect.setBottom(this->movePoint.y());
                        if(this->movePoint.y() < t_nowRect.top() + 16)t_nowRect.setBottom(t_nowRect.top() + 16);
                        break;
                    }
                    case 7:{
                        t_nowRect.setBottom(this->movePoint.y());
                        if(this->movePoint.y() < t_nowRect.top() + 16)t_nowRect.setBottom(t_nowRect.top() + 16);
                        break;
                    }
                    case 8:{
                        t_nowRect.setRight(this->movePoint.x());
                        if(this->movePoint.x() < t_nowRect.left() + 16)t_nowRect.setRight(t_nowRect.left() + 16);
                        t_nowRect.setBottom(this->movePoint.y());
                        if(this->movePoint.y() < t_nowRect.top() + 16)t_nowRect.setBottom(t_nowRect.top() + 16);
                        break;
                    }
                    default:{
                        break;
                    }
                    }
                    t_rosRecs.append(t_nowRect);
                    this->afterRect = t_nowRect;    //保存控件调整后的尺寸
                }
            }
            else{
                //控件被移动的描边框
                if(!this->startOnBase){
                    //列举出移动预先描边位置
                    for(widgetMsg t_widget : t_selectWidgets){
                        QRect t_rect;    //获取矩形
                        if(!FunUtil::getWidgetRelativePosition(t_widget.widget,this->editorSpaceForm->getBaseWidgetMsg().widget,t_rect)){
                            break;
                        }
                        t_x = t_rect.x() + (this->movePoint.x() - this->startPoint.x()) + this->offsetX;
                        t_y = t_rect.y() + (this->movePoint.y() - this->startPoint.y()) + this->offsetY;
                        t_rosRecs.append({t_x,
                                          t_y,
                                          t_rect.width(),
                                          t_rect.height()});
                    }


                    //判断当前位置是否存在其他容器
                    widgetMsg t_packm;
                    QRect t_packRect;
                    if(hasPack(this->movePoint.x(),this->movePoint.y(),t_packm,t_packRect) && this->nowSelectPackMsg.widget != nullptr){
                        //判断是否是老的容器,并且起始组件不是容器
                        if(t_packm.widget != this->nowSelectPackMsg.widget){
                            //填充新容器矩形
                            t_pen.setStyle(Qt::PenStyle::NoPen);
                            t_brush.setStyle(Qt::BrushStyle::SolidPattern);
                            t_brush.setColor(packSignColor);
                            t_painter.setPen(t_pen);
                            t_painter.setBrush(t_brush);
                            t_painter.drawRect(t_packRect); //填充新容器矩形

                            //绘制出提示文字
                            t_pen.setStyle(Qt::PenStyle::SolidLine);
                            t_pen.setColor(packSignTextColor);
                            t_brush.setStyle(Qt::BrushStyle::NoBrush);
                            t_painter.setPen(t_pen);
                            t_painter.setBrush(t_brush);
                            t_painter.drawText(this->movePoint,tr("移动到此容器")); //画出容器矩形

                            //绘制出老容器的位置
                            t_pen.setStyle(Qt::PenStyle::DashLine);
                            t_pen.setColor(packSignOldColor);
                            t_painter.setPen(t_pen);
                            t_painter.drawRect(this->nowSelectPackLocation);
                        }
                    }
                }
            }

            t_pen.setStyle(Qt::PenStyle::SolidLine);
            t_pen.setColor(roiPositionLineColor);
            t_brush.setStyle(Qt::BrushStyle::NoBrush);
            t_painter.setPen(t_pen);
            t_painter.setBrush(t_brush);
            t_painter.drawRects(t_rosRecs); //画出定位矩形
        }
    }




    //绘制移动虚线
//    if(virRect.width() != 0 && virRect.height() != 0){
//        t_pen.setStyle(Qt::PenStyle::DashLine);
//        t_pen.setColor(roiMoveLineColor);
//        t_pen.setWidth(1);
//        t_brush.setStyle(Qt::BrushStyle::NoBrush);
//        t_painter.setPen(t_pen);
//        t_painter.setBrush(t_brush);
//        t_painter.drawRect(virRect);
//    }

}


//绘制带箭头的线条，并且显示距离文本
void Form_Roi::drawArrowLine(QPainter *painter, int x1, int y1, int x2, int y2, bool drawRangeText)
{
    int sx,sy,subX,subY;
    sx = x1<x2?x1:x2; //选取最小值
    sy = y1<y2?y1:y2;
    subX = sx + abs(x1 - x2) / 2;
    subY = sy + abs(y1 - y2) / 2;

    QPen t_p = painter->pen(); //备份原来的pen

    //开始画主线
    QPoint t_begin(x1,y1),t_end(x2,y2);
    QPen t_pen;
    t_pen.setCapStyle(Qt::RoundCap);
    t_pen.setStyle(Qt::SolidLine);
    t_pen.setWidth(1);
    t_pen.setColor(this->roiPositionLineColor);
    painter->setPen(t_pen);
    painter->drawLine(t_begin,t_end);

    //画箭头两边线
    QPoint arrP1,arrP2;
    this->getArrowPosition(t_begin,t_end,arrP1,arrP2);
    painter->drawLine(t_end,arrP1);
    painter->drawLine(t_end,arrP2);

    //画文字
    if(drawRangeText){
        t_pen.setColor(this->positionSignTextColor);
        painter->setPen(t_pen);
        painter->drawText(subX,subY,QString::number(sqrt(pow(x1-x2,2)+pow(y1-y2,2))).append("px")); //左边
    }


    painter->setPen(t_p);//还原Pen
}

//绘制测量标线
void Form_Roi::drawRulerLine(QPainter *painter, QPoint start, int length, bool isRows)
{
    QPen t_p = painter->pen(); //备份原来的pen
    int t_pointOffset = 10; //像素偏差

    //开始画主线
    QPen t_pen;
    t_pen.setCapStyle(Qt::RoundCap);
    t_pen.setStyle(Qt::SolidLine);
    t_pen.setWidth(1);
    t_pen.setColor(this->roiPositionLineColor);
    painter->setPen(t_pen);

    QLine t_r1,t_r2,t_r3;
    painter->setCompositionMode(QPainter::CompositionMode_Source);
    if(isRows){
        //是横着测量
        start.setY(start.y() + t_pointOffset);
        t_r1 = QLine(start.x(),start.y()+5,start.x() + length,start.y()+5);
        t_r2 = QLine(start.x(),start.y(),start.x(),start.y()+10);
        t_r3 = QLine(start.x() + length,start.y(),start.x() + length,start.y()+10);
        painter->fillRect(QRect(start.x(),start.y(),length,10), Qt::transparent);
    }
    else{
        start.setX(start.x() + t_pointOffset);
        t_r1 = QLine(start.x() + 5,start.y(),start.x() + 5,start.y()+ length);
        t_r2 = QLine(start.x(),start.y(),start.x(),start.y()+10);
        t_r2 = QLine(start.x(),start.y(),start.x()+10,start.y());
        t_r3 = QLine(start.x(),start.y() + length,start.x()+10,start.y() + length);
        painter->fillRect(QRect(start.x(),start.y(),10,length), Qt::transparent);
    }
    painter->drawLines(QList<QLine>({t_r1,t_r2,t_r3}));


    QFontMetrics fm = painter->fontMetrics();
    int fontHeigh = fm.ascent()+fm.descent();
    //画文字
    if(isRows){
        start.setY(start.y() + 10 + fontHeigh);
    }
    else{
        start.setX(start.x() + 10);
        start.setY(start.y() + fontHeigh);
    }
    t_pen.setColor(this->positionSignTextColor);
    painter->setPen(t_pen);
    painter->drawText(start.x(),start.y(),QString::number(length).append("px")); //左边
    //fm.horizontalAdvance("123"); //测量的文本宽度

    painter->setPen(t_p);//还原Pen
}


//根据起始与中止点的坐标计算出箭头中止点的坐标
void Form_Roi::getArrowPosition(QPoint begin, QPoint end, QPoint &arrow1, QPoint &arrow2, int arrowLineLength)
{
    float x1 = begin.x();
    float y1 = begin.y();
    float x2 = end.x();
    float y2 = end.y();

    double angle = atan2(y2-y1,x2-x1);//计算线段的夹角
    float l = 6;//箭头边的长度
    float a = 0.785398;//箭头与线段的夹角

    arrow1.setX(x2 - l * cos( angle - a));
    arrow1.setY(y2 - l * sin( angle - a));
    arrow2.setX(x2 - l * cos( angle + a));
    arrow2.setY(y2 - l * sin( angle + a));
}


//判断当前控件是否为控件列表中的控件
bool Form_Roi::isListWidget(QWidget *widget,widgetMsg*& msg)
{
    for(widgetMsg& item : this->editorSpaceForm->getWidgetMsgs()){
        if(item.widget == widget){
            msg = &item;
            return true;
        }
    }
    return false;
}


//调整选取选择项，父类和子类都被选择，则主动放弃子类
void Form_Roi::adjustSelect(QWidget* parent)
{
    QList<QWidget*> subs = parent->findChildren<QWidget*>();

    for(QWidget* item : subs){
        widgetMsg* subMsg = nullptr;
        if(this->isListWidget(item,subMsg)){    //如果当前widget是控件列表的widget，且是选择状态，则取消选择所有子组件
            if(subMsg->isSelect){
                this->roi_setWidgetDeleteAllSelectforParent(subMsg->widget);
            }
        }
    }
}


//调整鼠标的样式
void Form_Roi::adjustMouseStyle(int mouseX, int mouseY)
{
    this->setCursor(Qt::ArrowCursor); //默认鼠标指针
    widgetMsg t_wMsg;
    int t_lType = this->getWidgetLocationState(mouseX,mouseY,t_wMsg);
    this->nowSelectWidget = t_wMsg.widget;
    this->nowSelectWidgetType = t_lType;
    switch(t_lType){
    case 1:
    case 8:{this->setCursor(Qt::SizeFDiagCursor); break;}
    case 2:
    case 7:{this->setCursor(Qt::SizeVerCursor); break;}
    case 3:
    case 6:{this->setCursor(Qt::SizeBDiagCursor); break;}
    case 4:
    case 5:{this->setCursor(Qt::SizeHorCursor); break;}
    default:{
        this->setCursor(Qt::ArrowCursor); break;
        this->nowSelectWidget = nullptr;
        this->nowSelectWidgetType = -1;
    }
    }
}



//获取组件的位置状态，位置方位为1-8，-1为错误。widgetMsg为引用，若正常，则包含组件信息
int Form_Roi::getWidgetLocationState(int x, int y, widgetMsg &msg)
{
    QList<widgetMsg> t_widgets = this->roi_getSelectWidgetMsgs();

    //控件信息和位置结构体
    struct msgRect{
        widgetMsg widget;
        QRect rect;
    };

    QList<msgRect> t_selectRect;    //控件信息与方位列表

    QRect t_wRect; //方位信息
    for(widgetMsg msgItem : t_widgets){
        if(FunUtil::getWidgetRelativePosition(msgItem.widget,this->editorSpaceForm->getEditorSpaceWidgetPtr(),t_wRect)){
            t_selectRect.append({msgItem,t_wRect});
        }
    }


    for(msgRect mrItem : t_selectRect){
        /*
        * 1 2 3
        * 4   5
        * 6 7 8
        */
        msg = mrItem.widget;
        int t_wm = mrItem.rect.left() + mrItem.rect.width() / 2; //一半宽度位置
        int t_hm = mrItem.rect.top() + mrItem.rect.height() / 2; //一半高度位置
        if(y < mrItem.rect.top() && y > mrItem.rect.top() - roiWidth){ //判断是否在 1、2、3 的范围内
            if(x < mrItem.rect.left() && x > mrItem.rect.left() - roiWidth){return 1;} //是在1的范围
            if(x > t_wm - roiWidth / 2 && x < t_wm + roiWidth / 2){return 2;} //是在2的范围
            if(x > mrItem.rect.right() && x < mrItem.rect.right() + roiWidth){return 3;} //是在3的范围
        }
        if(y < t_hm + roiWidth / 2 && y > t_hm - roiWidth / 2){ //判断是否在 4、5 的范围内
            if(x < mrItem.rect.left() && x > mrItem.rect.left() - roiWidth){return 4;} //是在4的范围
            if(x > mrItem.rect.right() && x < mrItem.rect.right() + roiWidth){return 5;} //是在5的范围
        }
        if(y < mrItem.rect.bottom() + roiWidth && y > mrItem.rect.bottom()){ //判断是否在 6、7、8 的范围内
            if(x < mrItem.rect.left() && x > mrItem.rect.left() - roiWidth){return 6;} //是在6的范围
            if(x > t_wm - roiWidth / 2 && x < t_wm + roiWidth / 2){return 7;} //是在7的范围
            if(x > mrItem.rect.right() && x < mrItem.rect.right() + roiWidth){return 8;} //是在8的范围
        }
    }
    return -1;
}


//判断在当前位置是否存在容器(存在返回真，并且retMsg返回信息)
bool Form_Roi::hasPack(int x, int y, widgetMsg &retMsg, QRect &retRect)
{
    QWidget* t_chWidget = this->editorSpaceForm->getEditorSpaceWidgetPtr()->childAt(x,y); //获取子组件
    if(t_chWidget == nullptr){
        return false;
    }

    do{
        for(widgetMsg t_widget : this->editorSpaceForm->getWidgetMsgs()){   //遍历所有组件
            if(t_chWidget == t_widget.widget && t_widget.isPack){   //查看当前组件是否为容器
                QRect t_rec;
                if(FunUtil::getWidgetRelativePosition(t_chWidget,this->editorSpaceForm->getEditorSpaceWidgetPtr(),t_rec)){
                    if(t_rec.contains(x,y)){    //此控件为容器控件，且此控件包含当前坐标
                        retMsg = t_widget;
                        retRect = t_rec;
                        return true;
                    }
                }
            }
        }
        t_chWidget = t_chWidget->parentWidget();
    }
    while(t_chWidget != nullptr);
    return false;
}


//判断subWidget是否为parent的子控件
bool Form_Roi::isSubWidget(QWidget *parent, QWidget *subWidget)
{
    if(parent == subWidget) return true;
    if(parent){
        QList<QWidget*> t_sub = parent->findChildren<QWidget*>();
        for(QWidget* item : t_sub){
            if(item == subWidget){
                return true;
            }
        }
    }
    return false;
}





//鼠标按下
void Form_Roi::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){ //鼠标左键被按下
        this->startPoint = event->pos(); //获取按下的坐标
        this->mouseDown = true; //鼠标是按下的

        //获取保存当前的容器信息
        if(!hasPack(event->pos().x(),event->pos().y(),this->nowSelectPackMsg,this->nowSelectPackLocation)){
            this->nowSelectPackMsg = widgetMsg();   //容器获取失败，制空容器内容
            this->nowSelectPackLocation = QRect();
        }
        else{
            //当前容器存在，且为组件输入，则只选择输入的父容器
            if(Plugin::nowSelectPlugin){
                this->roi_setWidgetDeleteAllSelect(); //清空所有的选择
                this->roi_setWidgetSelect(this->nowSelectPackMsg.widget,true);
            }
        }

        //判断是否点击到了最底层基础窗口，如果是，按住数百哦移动的时候绘制选区
        if(this->editorSpaceForm->getEditorSpaceWidgetPtr()){
            QWidget* t_atChild = this->editorSpaceForm->getEditorSpaceWidgetPtr()->childAt(this->startPoint);
            this->startOnBase = (t_atChild == this->editorSpaceForm->getBaseWidgetMsg().widget); //是否从基础主窗口开始绘制的
        }

        //    //根据鼠标放开的坐标确定选择单个组件
        //    if(!this->ctrlDown){
        //        this->roi_setWidgetDeleteAllSelect();
        //        this->roi_setWidgetSelect(this->editorSpaceForm->getEditorSpaceWidgetPtr()->childAt(event->pos()),true); //将某个组件设置为选中，如果这个组件不存在，则扫描其服组件
        //    }

        this->update();
    }



}

//鼠标移动
void Form_Roi::mouseMoveEvent(QMouseEvent *event)
{
    this->movePoint = event->pos(); //获取鼠标移动的坐标
    if(Plugin::nowSelectPlugin == nullptr){ //如果没有选择插件，也就是鼠标为普通指针状态
        //鼠标是否按下
        if(this->mouseDown){
            //鼠标按下操作
            //如果不是调整，则执行选区操作，
            if(this->nowSelectWidgetType == -1){
                //如果是从base窗口开始移动的，则绘制选框,这里是判断选框范围内有多少组件，并且将他们设置为选中状态
                if(this->startOnBase){
                    this->roi_selectRectWidget(QRect(this->startPoint.x(),
                                                     this->startPoint.y(),
                                                     this->movePoint.x() - this->startPoint.x(),
                                                     this->movePoint.y() - this->startPoint.y()));  //选择在此范围内的所有控件
                }
            }
        }
        else{
            //鼠标没有按下，只是简单的移动，则根据位置调整鼠标指针样式
            this->adjustMouseStyle(this->movePoint.x(),this->movePoint.y());
        }
    }
    else{   //当前是选择了插件的状态
        this->setCursor(Qt::CrossCursor);
    }
    this->update();
}

//鼠标放开
void Form_Roi::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){ //鼠标左键被按下
        QPoint t_endPoint = event->pos();   //结束坐标
        if(Plugin::nowSelectPlugin == nullptr){ //当前如果没有选择插件
            //判断开始位置与结束位置
            if(event->pos() == this->startPoint){
                //开始位置与结束位置相同，则是点击
                if(!this->ctrlDown){    //如果不是多选，则删除全部选择后再次选择
                    this->roi_setWidgetDeleteAllSelect(); //删除所有选择
                }
                //根据鼠标放开的坐标确定选择单个组件
                QWidget* t_selectChildWidget = this->editorSpaceForm->getEditorSpaceWidgetPtr()->childAt(event->pos());
                if(t_selectChildWidget != this->editorSpaceForm->getBaseWidgetMsg().widget){
                    t_selectChildWidget = this->editorSpaceForm->getBaseWidgetMsg().widget->childAt(event->pos());
                }

                //存在子组件才选中
                if(t_selectChildWidget != nullptr){ //没有选择任何组件
                    this->roi_setWidgetSelect(t_selectChildWidget,true); //将某个组件设置为选中，如果这个组件不存在，则扫描其服组件
                    //激活控件被选择事件
                    QList<QWidget*> t_wList;
                    for(widgetMsg item : this->roi_getSelectWidgetMsgs()){t_wList.append(item.widget);}
                    this->onWidgetSelected(t_wList);
                }

            }
            else{
                //开始位置与结束位置不同，则是拖动
                if(this->nowSelectWidgetType >= 1 && this->nowSelectWidgetType <= 8){ //拖动尺寸改变大小
                    QRect t_rect;
                    if(FunUtil::getWidgetRelativePosition(this->nowSelectWidget,this->editorSpaceForm->getEditorSpaceWidgetPtr(),t_rect)){
                        int x,y,w,h;
                        x = this->nowSelectWidget->x() + this->afterRect.x() - t_rect.x();
                        y = this->nowSelectWidget->y() + this->afterRect.y() - t_rect.y();
                        w = this->afterRect.width();
                        h = this->afterRect.height();

                        //判断是否选中了基础窗口
                        if(this->nowSelectWidget != this->editorSpaceForm->getBaseWidgetMsg().widget){
                            //没有选中基础窗口
                            this->nowSelectWidget->setGeometry({x,y,w,h});
                            this->onWidgetGeometryChanged(this->nowSelectWidget); //控件尺寸被改变
                        }
                        else{
                            //选中了基础窗口
                            this->editorSpaceForm->getBaseWidgetMsg().widget->setGeometry({0,0,w,h});
                            this->onWidgetBaseGeometryChanged(this->editorSpaceForm->getBaseWidgetMsg().widget->geometry()); //通知base窗口大小被改变
                        }
                    }
                }
                else if(!this->startOnBase){ //改变位置
                    widgetMsg t_packm;  //临时容器组件信息
                    QRect t_packr;      //容器位置信息
                    QList<widgetMsg> t_selWidget = this->roi_getSelectWidgetMsgs(); //获取选择的控件列表
                    //基础窗口不允许移动，去除基础窗口的信息
                    QList<widgetMsg>::Iterator i;
                    for(i = t_selWidget.begin(); i < t_selWidget.end(); i++){
                        if(i->widget == this->editorSpaceForm->getBaseWidgetMsg().widget){  //删除元素并且跳出
                            t_selWidget.erase(i);
                            break;
                        }
                    }
                    if(this->hasPack(t_endPoint.x(),t_endPoint.y(),t_packm,t_packr)){ //获取当前放开组件的容器
                        if(t_packm.widget == this->nowSelectPackMsg.widget){    //如果是在同一个容器内，则只改变坐标位置
                            int t_x = t_endPoint.x() - this->startPoint.x();
                            int t_y = t_endPoint.y() - this->startPoint.y();
                            QList<QWidget*> t_ws;
                            for(widgetMsg item : t_selWidget){
                                item.widget->setGeometry(
                                    item.widget->x() + t_x,
                                    item.widget->y() + t_y,
                                    item.widget->width(),
                                    item.widget->height()
                                    );
                                t_ws.append(item.widget);   //加入移动列表
                            }
                            this->onWidgetMove(t_ws);   //激活组件移动事件
                        }
                        else{   //不在同一个容器里面，则需要对每个组件重新定位
                            QList<QWidget*> t_ws;
                            for(widgetMsg item : t_selWidget){
                                if(!this->isSubWidget(item.widget,t_packm.widget)){ //不是子项目才移动进去，不然造成，父窗口移到子窗口的错误
                                    QRect t_itemRect;
                                    //判断并获取组件相对于父组件的位置
                                    if(FunUtil::getWidgetRelativePosition(item.widget,this->editorSpaceForm->getEditorSpaceWidgetPtr(),t_itemRect)){
                                        int x,y,w,h;

                                        x = t_itemRect.x() - t_packr.x() + t_endPoint.x() - this->startPoint.x();
                                        y = t_itemRect.y() - t_packr.y() + t_endPoint.y() - this->startPoint.y();
                                        w = t_itemRect.width();
                                        h = t_itemRect.height();

                                        bool t_isHidden = item.widget->isHidden();
                                        item.widget->setParent(t_packm.widget); //提前设置父项目位置
                                        item.widget->setGeometry({x,y,w,h});  //根据新的容器
                                        t_packm.pluginPtr->subWidgetEnter(t_packm.widget,item.widget); //通知插件子控件进入信息
                                        item.widget->setHidden(t_isHidden);
                                        t_ws.append(item.widget);   //加入移动列表
                                    }
                                }
                            }
                            if(t_ws.length() > 0) this->onWidgetMove(t_ws); //激活组件移动事件
                            this->onSubWidgetsChanged(t_packm.widget);      //这个容器有控件加入
                        }
                    }
                }
            }
        }
        else{
            //是插件进入,创建插件信息
            if(this->nowSelectPackMsg.pluginPtr){
                int x,y,w,h;
                x = this->startPoint.x() - this->nowSelectPackLocation.x();
                y = this->startPoint.y() - this->nowSelectPackLocation.y();
                w = t_endPoint.x() - this->startPoint.x();
                h = t_endPoint.y() - this->startPoint.y();

                if(w < 0){
                    x += w;
                    w = abs(w);
                }
                if(h < 0){
                    y += h;
                    h = abs(h);
                }

                //创建组件到列表
                QWidget* t_newCreateWidget = this->editorSpaceForm->createWidgetMsgToList(Plugin::nowSelectPlugin,
                                                                                          {x,y,w,h},
                                                                                          this->nowSelectPackMsg.pluginPtr,
                                                                                          this->nowSelectPackMsg.widget);

                //只选择当前加入的控件
                this->roi_setWidgetDeleteAllSelect();
                this->roi_setWidgetSelect(t_newCreateWidget,true);
                this->onWidgetSelected({t_newCreateWidget});
            }

            if(!this->ctrlDown){    //如果Ctrl没有被按下，那么就自动恢复指针
                Plugin::nowSelectPlugin = nullptr;
            }
        }

        this->startOnBase = false;  //取消从base的标记
        this->mouseDown = false;    //取消鼠标按下标记
        this->adjustSelect(this->editorSpaceForm->getEditorSpaceWidgetPtr()); //调整：若父类被选择，则自动抛弃所有子类
        this->adjustMouseStyle(event->pos().x(),event->pos().y());  //调整鼠标样式
        this->update();


    }
    else if (event->button() == Qt::RightButton){   //鼠标右键被放开
        if(editorSpaceForm){
            editorSpaceForm->showMenu(this->nowSelectWidget,QCursor().pos());   //弹出右键菜单
        }
    }
}


//鼠标双击
void Form_Roi::mouseDoubleClickEvent(QMouseEvent *event)
{
    // this->update();
    // qDebug() << "mouseDoubleClickEvent";
}


//重写绘制方法
void Form_Roi::paintEvent(QPaintEvent *event)
{
    //在内存绘制新的位图信息
    this->drawPix();
    //在窗口绘制新的图形
    QPainter t_painter(this);
    t_painter.drawPixmap(0,0,*formPixmap);
    QWidget::paintEvent(event);
}


//尺寸改变
void Form_Roi::resizeEvent(QResizeEvent *event)
{
    //根据出口尺寸，创建新的位图信息
    QPixmap* t_pix = new QPixmap(this->width(),this->height());
    //设置透明背景填充
    t_pix->fill(Qt::transparent);
    //将老的位图信息保存到新的位图
    QPainter t_painter(t_pix);
    t_painter.drawPixmap(0,0,*formPixmap);
    delete formPixmap;
    formPixmap = t_pix;
}

//按键被按下
void Form_Roi::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Control) {
        this->ctrlDown = true;
    } else {
        QWidget::keyPressEvent(event);
    }
}

//按键被放开
void Form_Roi::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Control) {
        this->ctrlDown = false;
    } else {
        QWidget::keyPressEvent(event);
    }
}


