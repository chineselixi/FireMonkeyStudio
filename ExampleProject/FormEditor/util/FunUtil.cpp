#include "FunUtil.h"
#include "QWidget"
#include "QString"

//获取组件相对于父组件的位置
bool FunUtil::getWidgetRelativePosition(QWidget *widget, QWidget* parentWidget, QRect &returnRect)
{
    if(parentWidget == nullptr || widget == nullptr) return false;
    if(parentWidget == widget){ //是最高父类自身
        returnRect = widget->rect();
        return true;
    }

    QRect t_rec = widget->geometry();
    int x,y,w,h;
    x = t_rec.x();
    y = t_rec.y();
    w = t_rec.width();
    h = t_rec.height();
    QWidget* t_w = widget;
    do{
        t_w = t_w->parentWidget();
        if(t_w == nullptr){
            return false;
        }
        if(t_w == parentWidget){
            returnRect = QRect(x,y,w,h);
            return true;
        }
        x = x + t_w->geometry().x();
        y = y + t_w->geometry().y();
    }
    while(t_w != nullptr);
    return false;
}


//将QRect转换为字符串
QString FunUtil::rectToString(QRect rect)
{
    return QString::number(rect.x()) + "|" + QString::number(rect.y()) + "|" + QString::number(rect.width()) + "|" + QString::number(rect.height());
}

//将QString转换为QRect
QRect FunUtil::stringToRect(QString str)
{
    QRect t_rect;
    QStringList t_sl = str.split("|");
    if(t_sl.length() == 4){
        t_rect.setRect(t_sl[0].toInt(),t_sl[1].toInt(),t_sl[2].toInt(),t_sl[3].toInt());
    }
    return t_rect;
}

//将QSize转换为字符串
QString FunUtil::sizeToString(QSize size)
{
    return QString::number(size.width()) + "|" + QString::number(size.height());
}

//将QString转换为QSize
QSize FunUtil::stringToSize(QString str)
{
    QSize t_size;
    QStringList t_sl = str.split("|");
    if(t_sl.length() == 4){
        t_size.setWidth(t_sl[0].toInt());
        t_size.setHeight(t_sl[1].toInt());
    }
    return t_size;
}
