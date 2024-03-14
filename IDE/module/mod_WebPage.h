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

    //initiation ,load completely 
    void event_onLoad(); //初始化，加载完成
    //delete single log
    void event_onCloseSign(QString sign); //删除单个记录
    //delete all log
    void event_onClcloseAllSign(); //删除全部记录
    //create     
    void event_onNew(); //新建
    //open project 
    void event_onOpen(); //打开工程
    //source code shop
    void event_onSourceCodeMall(); //源码商城
    //open setting window
    void event_onSetting(); //打开设置窗口
};







class mod_WebPage:public QWebEngineView
{
    Q_OBJECT
public:
    mod_WebPage(QWidget *parent);
};

#endif // MOD_WEBPAGE_H
