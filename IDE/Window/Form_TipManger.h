#ifndef FORM_TIPMANGER_H
#define FORM_TIPMANGER_H

#include <QWidget>
#include "QListWidgetItem"
#include "QTimer"
#include "../Widget/Widget_TipItem.h"

namespace Ui {
class Form_TipManger;
}

class Form_TipManger : public QWidget
{
    Q_OBJECT

    struct TipNode{
        uint16_t id;                //列表ID
        Widget_TipItem* widget;     //列表项目自定义控件
        QListWidgetItem* item;      //列表项目
        QTimer timer;               //定时器
        qint64 closeTime = 0;     //关闭的时间戳
    };

    std::list<TipNode*> TipNodeList;     //通知列表

public:
    typedef PluginGlobalMsg::TipType TipType;    //取别名

public:
    explicit Form_TipManger(QWidget *parent = nullptr);
    ~Form_TipManger();

    uint16_t addTip(QString title = "", QString tip = "", qint64 showTime = 5000, TipType type = TipType::None, QPixmap pixmap = QPixmap(), bool canClose = true);       //添加一个提示消息
    void closeTip(uint16_t id);                             //关闭一个提示
    void closeAll();                                        //关闭所有提示
    bool hasTip(uint16_t id);                               //是否还存在此提示
    void adjustWindowRec();                                 //调整窗口尺寸
    void moveToRT(int x,int y);                             //提供右下角坐标，将窗口右下角移动到给定点

    void setTipTitle(uint16_t id, QString title);           //设置提示标题
    void setTipText(uint16_t id, QString text);             //设置提示文本
    void setTipType(uint16_t id, PluginGlobalMsg::TipType type);                 //设置提示类型
    void setTipPixmap(uint16_t id, QPixmap pixmap);         //设置提示图片
    void setTipCanClose(uint16_t id, bool canClose);        //设置提示能够关闭
    void setTipShowTime(uint16_t id, qint64 showTime);      //设置提示时间

//protected:
//    bool event(QEvent *event) override;     //事件接口

private:
    Ui::Form_TipManger *ui;

    uint16_t index = 0;         //自增索引


};

#endif // FORM_TIPMANGER_H
