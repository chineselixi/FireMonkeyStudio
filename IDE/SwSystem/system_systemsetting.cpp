
#include "system_systemsetting.h"

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
QVariant System_systemSetting::getSettingValue(QString className, QString idName)
{
    //objSetting->beginGroup(className);
    return objSetting->value("/" + className + "/" +idName);
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

