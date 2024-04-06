
#include "Widget_MdiArea.h"

Widget_MdiArea::Widget_MdiArea(QWidget *parent)
    :QMdiArea(parent)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}


//尺寸被改变
void Widget_MdiArea::resizeEvent(QResizeEvent *resizeEvent)
{
    QMdiArea::resizeEvent(resizeEvent);
    this->event_onResize(resizeEvent);
}

void Widget_MdiArea::scrollContentsBy(int dx, int dy)
{
    QMdiArea::scrollContentsBy(dx,dy);
    this->event_onScrollBarChange(dx,dy);
}

