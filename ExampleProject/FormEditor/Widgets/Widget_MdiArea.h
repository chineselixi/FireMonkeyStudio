
#ifndef WIDGET_MDIAREA_H
#define WIDGET_MDIAREA_H

#include "QMdiArea"


class Widget_MdiArea : public QMdiArea
{
    Q_OBJECT

public:
    Widget_MdiArea(QWidget *parent = nullptr);


protected:


//    void timerEvent(QTimerEvent *timerEvent) override;
//    void showEvent(QShowEvent *showEvent) override;
//    bool viewportEvent(QEvent *event) override;
    void resizeEvent(QResizeEvent *resizeEvent) override; //尺寸被改变
    void scrollContentsBy(int dx, int dy) override; //滚动条被滚动


signals:
    void event_onScrollBarChange(int dx,int dy);    //当滚动条改变位置
    void event_onResize(QResizeEvent *resizeEvent); //当前尺寸被改变
};

#endif // WIDGET_MDIAREA_H
