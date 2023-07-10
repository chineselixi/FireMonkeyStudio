#ifndef MOD_WEBPAGE_H
#define MOD_WEBPAGE_H
#include "QWebEngineView"




class cppObject : public QObject{
    Q_OBJECT

public:
    QWebChannel* Channel;
    QWebEnginePage* Page;
    cppObject(QWebChannel* t_channel,QWebEnginePage* t_page);
public slots:
    void event_onLoad(); //初始化，加载完成
    void event_onCloseSign(QString sign); //删除单个记录
    void event_onClcloseAllSign(); //删除全部记录
    void event_onNew(); //新建
    void event_onOpen(); //打开工程
    void event_onSourceCodeMall(); //源码商城
    void event_onSetting(); //打开设置窗口
};







class mod_WebPage:public QWebEngineView
{
    Q_OBJECT
public:
    mod_WebPage(QWidget *parent);
};

#endif // MOD_WEBPAGE_H
