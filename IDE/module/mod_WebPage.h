#ifndef MOD_WEBPAGE_H
#define MOD_WEBPAGE_H
#include "QWebEngineView"



class mod_WebPage:public QWebEngineView
{
    Q_OBJECT
public:
    mod_WebPage(QWidget *parent);
};

#endif // MOD_WEBPAGE_H
