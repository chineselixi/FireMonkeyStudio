#ifndef PLUGIN_CODEEDITORINTERFACE_H
#define PLUGIN_CODEEDITORINTERFACE_H

#include "QString"
#include "QWidget"

class QsciScintilla;




//代码编辑器的接口类
class Plugin_CodeEditorInterface
{
//public:
//    Plugin_CodeEditorInterface();


//代码编辑器接口事件
public:
    virtual void onSave(){};    //保存文件
    virtual void onThemeChange(QString themeSign){};  //主题已经改变(主题标记)

public:
    virtual QString getCodeText(){return "";} //获取编辑器内的代码
    virtual QString getSavePath(){return "";} //获取文件保存的路径
    virtual QsciScintilla* getSciCodeEditor(){return nullptr;} //获取火花代码编辑器指针


};

#endif // PLUGIN_CODEEDITORINTERFACE_H
