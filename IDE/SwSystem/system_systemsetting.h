
#ifndef SYSTEM_SYSTEMSETTING_H
#define SYSTEM_SYSTEMSETTING_H
#include "QSettings"
#include "QFile"


class System_systemSetting
{
private:
    QString objFile; //设置保存的文件
    QSettings* objSetting;

public:
    System_systemSetting(QString settingFile);
    ~System_systemSetting();

    void changeSetting(QString className,QString idName,QVariant value); //添加或者给改变ID
    QVariant getSettingValue(QString className,QString idName,QVariant normalReturn = QVariant()); //获取节点值
    void removeClass(QString className); //移除ID
    void removeValue(QString className,QString idName); //删除值


    QString readThemeStyle(QString styleName = "Blue",QString formName = ""); //加载主题

};

#endif // SYSTEM_SYSTEMSETTING_H
