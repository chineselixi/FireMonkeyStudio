#include "System_UtilFun.h"
#include "System_SystemSetting.h"
#include "QApplication"
#include "QMessageBox"

System_SystemSetting::System_SystemSetting(QString settingFile):objFile(settingFile)
{
    objSetting = new QSettings(settingFile,QSettings::IniFormat);
}

System_SystemSetting::~System_SystemSetting()
{
    delete objSetting;
}

//添加或者给改变ID
void System_SystemSetting::changeSetting(QString className, QString idName, QVariant value)
{
    //objSetting->beginGroup(className);
    objSetting->setValue("/" + className + "/" +idName,value);
}

//获取节点值
QVariant System_SystemSetting::getSettingValue(QString className, QString idName,QVariant normalReturn)
{
    //objSetting->beginGroup(className);
    QVariant t_val = objSetting->value("/" + className + "/" +idName);
    if(t_val.isNull()) return normalReturn;
    return t_val;
}

void System_SystemSetting::removeValue(QString className, QString idName)
{
    objSetting->remove("/" + className + "/" +idName);
}


//移除ID
void System_SystemSetting::removeClass(QString className)
{
    //objSetting->beginGroup(className);
    objSetting->remove("/" + className);
}

//加载主题
QString System_SystemSetting::readThemeStyle(QString styleName, QString formName)
{
    if(formName.isEmpty()) formName = "Form_WorkSpace"; //默认加载工作空间类似的主题
    QString t_styleFilePath = System_OS::getaApplicationDirPath_EX() + "/formStyle/" + styleName + "/" + formName + ".style";
    QFile t_qss(t_styleFilePath);
    t_qss.open(QFile::ReadOnly);
    QString t_retStyle = t_qss.readAll();
    t_qss.close();
//    QMessageBox::information(nullptr,"",t_styleFilePath);
    return t_retStyle;
}
