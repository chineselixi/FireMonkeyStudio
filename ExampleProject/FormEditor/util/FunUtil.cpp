#include "FunUtil.h"
#include "QWidget"
#include "QString"
#include "QLocale"

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
QString FunUtil::rectToString(QRectF rect)
{
    return QString::number(rect.x(),'f',0) + "|" + QString::number(rect.y(),'f',0) + "|" + QString::number(rect.width(),'f',0) + "|" + QString::number(rect.height(),'f',0);
}

//将QString转换为QRect
QRectF FunUtil::stringToRect(QString str)
{
    QRect t_rect;
    QStringList t_sl = str.split("|");
    if(t_sl.length() == 4){
        t_rect.setRect(t_sl[0].toInt(),t_sl[1].toInt(),t_sl[2].toInt(),t_sl[3].toInt());
    }
    return t_rect;
}

//将QSize转换为字符串
QString FunUtil::sizeToString(QSizeF size)
{
    return QString::number(size.width(),'f',0) + "|" + QString::number(size.height(),'f',0);
}

//将QString转换为QSize
QSizeF FunUtil::stringToSize(QString str)
{
    QSize t_size;
    QStringList t_sl = str.split("|");
    if(t_sl.length() == 2){
        t_size.setWidth(t_sl[0].toDouble());
        t_size.setHeight(t_sl[1].toDouble());
    }
    return t_size;
}

//位置转字符串
QString FunUtil::pointToString(QPointF point)
{
    return QString::number(point.x(),'f',0) + "|" + QString::number(point.y(),'f',0);
}

//字符串转位置
QPointF FunUtil::stringToPoint(QString str)
{
    QPointF t_point;
    QStringList t_sl = str.split("|");
    if(t_sl.length() == 2){
        t_point.setX(t_sl[0].toInt());
        t_point.setY(t_sl[1].toInt());
    }
    return t_point;
}

//地域转字符串
QString FunUtil::localeToString(QLocale locale)
{
    return locale.name();
}

//字符串转地域
QLocale FunUtil::stringToLocale(QString str)
{
    return QLocale(str);
}

//尺寸策略转字符串
QString FunUtil::SizePolicyToString(QSizePolicy SizePolicy)
{
    return QString::number(SizePolicy.horizontalPolicy(),'f',0) + "|" +
           QString::number(SizePolicy.verticalPolicy(),'f',0) + "|" +
           QString::number(SizePolicy.horizontalStretch(),'f',0) + "|" +
           QString::number(SizePolicy.verticalStretch(),'f',0);
}

//字符串转尺寸策略
QSizePolicy FunUtil::stringToSizePolicy(QString str)
{
    QSizePolicy t_sizePolicy;
    QStringList t_sl = str.split("|");
    if(t_sl.length() == 4){
        t_sizePolicy.setHorizontalPolicy(QSizePolicy::Policy(t_sl[0].toInt()));
        t_sizePolicy.setVerticalPolicy(QSizePolicy::Policy(t_sl[1].toInt()));
        t_sizePolicy.setHorizontalStretch(t_sl[2].toInt());
        t_sizePolicy.setVerticalStretch(t_sl[3].toInt());
    }
    return t_sizePolicy;
}

//光标信息转字符串
QString FunUtil::cursorToString(QCursor cursor)
{
    return QString::number(cursor.shape(),'f',0);
}

//字符串转光标信息
QCursor FunUtil::stringToSizeCursor(QString str)
{
    QCursor t_cur;
    t_cur.setShape(Qt::CursorShape(str.toInt()));
    return t_cur;
}

//将QSize转换为QColor
QString FunUtil::colorToString(QColor color)
{
    return color.name();
}

//将QString转换为QColor
QColor FunUtil::stringToColor(QString str)
{
    return QColor(str);
}
