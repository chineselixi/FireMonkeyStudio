#ifndef WIDGET_STATUSBAR_H
#define WIDGET_STATUSBAR_H

#include <QWidget>

namespace Ui {
class Widget_Statusbar;
}

class Widget_Statusbar : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Statusbar(QWidget *parent = nullptr);
    ~Widget_Statusbar();


    void hideAll(); //隐藏所有控件
    QWidget* getArrowWidgetPtr(); //获取toolButton_Tip按钮指针
    void setProgress(int a); //设置进度，0-100。如果为负数，则不显示
    void setBtn1(QString title = "",QIcon ico_16x = QIcon(),QString sign = "",std::function<void(QString sign)> funPtr = nullptr);   //设置按钮事件，funPtr若为null，则隐藏
    void setBtn2(QString title = "",QIcon ico_16x = QIcon(),QString sign = "",std::function<void(QString sign)> funPtr = nullptr);   //设置按钮事件，funPtr若为null，则隐藏
    void setBtn3(QString title = "",QIcon ico_16x = QIcon(),QString sign = "",std::function<void(QString sign)> funPtr = nullptr);   //设置按钮事件，funPtr若为null，则隐藏
    void setBtn4(QString title = "",QIcon ico_16x = QIcon(),QString sign = "",std::function<void(QString sign)> funPtr = nullptr);   //设置按钮事件，funPtr若为null，则隐藏
    void setBtn5(QString title = "",QIcon ico_16x = QIcon(),QString sign = "",std::function<void(QString sign)> funPtr = nullptr);   //设置按钮事件，funPtr若为null，则隐藏
    void setBtn6(QString title = "",QIcon ico_16x = QIcon(),QString sign = "",std::function<void(QString sign)> funPtr = nullptr);   //设置按钮事件，funPtr若为null，则隐藏


    //设置弹出按钮
    void setTipArrowType(Qt::ArrowType type);           //设置提示按钮标记向上
    void setTipBtnShow(bool show = false);              //设置提示按钮的显隐
    void setTipBtnFun(std::function<void()> fun);       //设置激活方法


private slots:
    void on_toolButton_Tip_clicked();

private:
    void setBtn(class QToolButton* btnObj,QString title = "",QIcon ico_16x = QIcon(),QString sign = "",std::function<void(QString sign)> funPtr = nullptr); //设置按钮事件，funPtr若为null，则隐藏

private:
    Ui::Widget_Statusbar *ui;
    std::function<void()> tipFun = nullptr;
};

#endif // WIDGET_STATUSBAR_H
