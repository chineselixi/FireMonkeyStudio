#ifndef FORM_WIDGETBOX_H
#define FORM_WIDGETBOX_H

#include <QWidget>
#include "QLibrary"
#include "QListWidgetItem"
#include "Plugins/Plugin_Base.h"

namespace Ui {
class Form_WidgetBox;
}

class Form_WidgetBox : public QWidget
{
    Q_OBJECT

public:
    explicit Form_WidgetBox(QWidget *parent = nullptr);
    ~Form_WidgetBox();


    struct widgetPluginMsg{
        Plugin_Base* plg = nullptr;
        QListWidgetItem* widgetItem = nullptr;
    };

    QVector<widgetPluginMsg> List_widgetPlg;  //控件插件列表信息


public:
    void addPlguin(Plugin_Base* plg); //添加插件
    void Init(QString dirPath,QString plgSuffix = "dll"); //初始化Widget
    void selectItem(int index); //选择项目
    Plugin_Base* findPluginBySign(QString sign);    //根据sign查找插件

private:
    void findPlugin(QString path,QVector<QString>& retFiles,QString plgSuffix = "wgt"); //查找寻找插件文件


private:
    Ui::Form_WidgetBox *ui;

public:
    QSize sizeHint() const; //重写获取尺寸的函数，这样在QDockWidget下就可以自定义宽高了

private:
    QListWidgetItem* addItem(QPixmap pixmap,QString title,QString sign); //添加项目

signals://使用signals声明信号函数，访问级别为protected
    void onPluginSelectChanged(Plugin_Base* plg);//当插件选择改变

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item); //Item被点击
};

#endif // FORM_WIDGETBOX_H
