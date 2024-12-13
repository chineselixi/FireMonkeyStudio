#ifndef WIDGET_TIPITEM_H
#define WIDGET_TIPITEM_H

#include <QWidget>
#include <QTimer>
#include "../Plugin/Plugin_Global.h"

namespace Ui {
class Widget_TipItem;
}

class Widget_TipItem : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_TipItem(uint16_t id = 0,
                            QString title = "",
                            QString tip = "",
                            PluginGlobalMsg::TipType type = PluginGlobalMsg::TipType::Normal,
                            QPixmap pixmap = QPixmap(),
                            bool canClose = true,
                            std::function<void(uint16_t id)> tikFun = nullptr,
                            QWidget *parent = nullptr);
    ~Widget_TipItem();


public:
    void setTipTitle(QString title);           //设置提示标题
    void setTipText(QString title);            //设置提示文本
    void setTipType(PluginGlobalMsg::TipType type);              //设置提示类型
    void setTipPixmap(QPixmap pixmap, bool save = true);         //设置提示图片
    void setTipCanClose(bool canClose);     //设置提示能够关闭
    void setProgressIndex(short index);     //设置进度条进度，-1为不显示
    bool progressIsShow();  //进度条是否显示
    int getProgressIndex(); //获取进度


private slots:
    void on_btn_close_clicked();    //关闭控件


private:
    Ui::Widget_TipItem *ui;
    std::function<void(uint16_t id)> retFun = nullptr;  //回调方法指针
    uint16_t thisId = 0;                                //当前通知的ID
    QPixmap tipPixmap;                                  //通知的自定义图标
};

#endif // WIDGET_TIPITEM_H
