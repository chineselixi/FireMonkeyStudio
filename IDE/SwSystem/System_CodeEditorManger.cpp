#include "System_CodeEditorManger.h"
#include "QObject"
#include "QColor"
#include "../Plugin/Plugin_Manger.h"
#include "../Plugin/Plugin_CodeEditorInterface.h"
#include "../SwSystem/System_GlobalVar.h"



//初始化时，绑定插件管理器
System_CodeEditorManger::System_CodeEditorManger()
{
    if(Manger::pluginManger){
        Manger::pluginManger->codeEditorManger_init_building(
            [=](QString path){
                this->tipEevent_onSaveCodeText_Path(path);
            },
            [=](){
                this->tipEevent_onSaveCodeText();
            },
            [=](QObject* obj)->bool{
                return this->addCodeEditor(obj);
            },
            [=](QObject* obj)->bool{
                return this->removeCodeEditor(obj);
            }
            );
    }
}


//添加代码编辑器对象
bool System_CodeEditorManger::addCodeEditor(QObject *plg)
{
    Plugin_CodeEditorInterface* t_Cobj = dynamic_cast<Plugin_CodeEditorInterface*>(plg);
    if(!t_Cobj) return false;   //必须得是QObject对象的子类才能够转换

    QObject::connect(plg,&QObject::destroyed,[=](){ //对象销毁了，自动回收对象
        this->removeCodeEditor(plg);
    });

    editors.append(plg);
    t_Cobj->onThemeChange(this->themeName);    //激活主题更改
    return true;
}


//删除代码编辑器对象
bool System_CodeEditorManger::removeCodeEditor(QObject *plg)
{
    for (int i = 0; i < editors.length(); ++i) {
        if(editors[i] == plg){
            editors.remove(i);
            return true;
        }
    }
    return false;
}


//主题被改变激发
void System_CodeEditorManger::tipEvent_onThemeChange(QString newThemeName)
{
    this->themeName = newThemeName;
    for (int i = 0; i < editors.length(); ++i) {
        Plugin_CodeEditorInterface* t_Cobj = dynamic_cast<Plugin_CodeEditorInterface*>(editors[i]);
        if(!t_Cobj) continue;   //必须得是Plugin_CodeEditorInterface对象的子类才能够转换
        t_Cobj->onThemeChange(newThemeName);
    }
}


//代码保存激发,保存只当路径代码
void System_CodeEditorManger::tipEevent_onSaveCodeText_Path(QString pathSign)
{
    for (int i = 0; i < editors.length(); ++i) {
        Plugin_CodeEditorInterface* t_Cobj = dynamic_cast<Plugin_CodeEditorInterface*>(editors[i]);
        if(!t_Cobj) continue;   //必须得是Plugin_CodeEditorInterface对象的子类才能够转换
        if(t_Cobj->getSavePath() == pathSign){
            t_Cobj->onSave();
        }
    }
}


//代码保存激发
void System_CodeEditorManger::tipEevent_onSaveCodeText()
{
    for (int i = 0; i < editors.length(); ++i) {
        Plugin_CodeEditorInterface* t_Cobj = dynamic_cast<Plugin_CodeEditorInterface*>(editors[i]);
        if(!t_Cobj) continue;   //必须得是Plugin_CodeEditorInterface对象的子类才能够转换
        t_Cobj->onSave();
    }
}
