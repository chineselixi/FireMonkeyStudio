#ifndef SYSTEM_CODEEDITORMANGER_H
#define SYSTEM_CODEEDITORMANGER_H

#include "QList"

class System_CodeEditorManger
{
public:
    System_CodeEditorManger();

private:
    QList<QObject*> editors; //代码编辑器对象实例
    QString themeName = "Blue"; //主题名称

public:
    bool addCodeEditor(QObject* plg);        //添加代码编辑器对象
    bool removeCodeEditor(QObject* plg);     //删除代码编辑器对象


public:
    void tipEvent_onThemeChange(QString newThemeName);      //主题被改变激发
    void tipEevent_onSaveCodeText_Path(QString pathSifn);   //代码保存激发,保存只当路径代码
    void tipEevent_onSaveCodeText();                        //代码保存激发，保存全部代码

};

#endif // SYSTEM_CODEEDITORMANGER_H
