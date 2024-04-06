#include "FunUtil.h"
#include "QWidget"


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
