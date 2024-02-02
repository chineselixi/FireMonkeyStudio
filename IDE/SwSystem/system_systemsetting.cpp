#include "System_UtilFun.h"
#include "system_systemsetting.h"
#include "QApplication"


System_systemSetting::System_systemSetting(QString settingFile):objFile(settingFile)
{
    objSetting = new QSettings(settingFile,QSettings::IniFormat);
}

System_systemSetting::~System_systemSetting()
{
    delete objSetting;
}

//添加或者给改变ID
void System_systemSetting::changeSetting(QString className, QString idName, QVariant value)
{
    //objSetting->beginGroup(className);
    objSetting->setValue("/" + className + "/" +idName,value);
}

//获取节点值
QVariant System_systemSetting::getSettingValue(QString className, QString idName,QVariant normalReturn)
{
    //objSetting->beginGroup(className);
    QVariant t_val = objSetting->value("/" + className + "/" +idName);
    if(t_val.isNull()) return normalReturn;
    return t_val;
}

void System_systemSetting::removeValue(QString className, QString idName)
{
    objSetting->remove("/" + className + "/" +idName);
}


//移除ID
void System_systemSetting::removeClass(QString className)
{
    //objSetting->beginGroup(className);
    objSetting->remove("/" + className);
}

//加载主题
QString System_systemSetting::readThemeStyle(QString styleName, QString formName)
{
    if(formName.isEmpty()) formName = "Form_WorkSpace"; //默认加载工作空间类似的主题
    QFile t_qss(System_OS::getaApplicationDirPath_EX() + "/formStyle/" + styleName + "/" + formName + ".style");
    t_qss.open(QFile::ReadOnly);
    QString t_retStyle = t_qss.readAll();
    t_qss.close();
    return t_retStyle;
}
