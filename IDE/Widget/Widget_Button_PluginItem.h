#ifndef WIDGET_BUTTON_PLUGINITEM_H
#define WIDGET_BUTTON_PLUGINITEM_H

#include <QWidget>

namespace Ui {
class Widget_Button_PluginItem;
}

class Widget_Button_PluginItem : public QWidget
{
    Q_OBJECT

private:
    QPixmap pixmap_normal;
    QPixmap pixmap_unEnable;


public:
    explicit Widget_Button_PluginItem(QWidget *parent = nullptr);
    explicit Widget_Button_PluginItem(QPixmap ico,QString title,QString filePathTip,QString pluginSign,QString pluginVersion,QWidget *parent = nullptr);
    ~Widget_Button_PluginItem();

public:
    void SetIcon(QPixmap ico,QSize icoSize = QSize(48,48)); //设置图标样式
    void SetTitle(QString text); //设置主标题
    void SetFilePathTip(QString text); //设置文件路径提示
    void SetPluginSign(QString text);//设置插件标记提示
    void SetPluginVerTip(QString ver); //设置插件的版本

    void SetEnableStyle(bool enable); //设置启用


private slots:
    void on_But_enable_clicked();

    void on_But_unload_clicked();

private:
    Ui::Widget_Button_PluginItem *ui;

    void mousePressEvent(QMouseEvent *event); //被按下

signals:
    //信号
    void event_onPluginEnable(bool enable); //是否启用插件
    void event_onPluginUnload(); //卸载插件
    void event_onDown(); //窗口被按下
};

#endif // WIDGET_BUTTON_PLUGINITEM_H
