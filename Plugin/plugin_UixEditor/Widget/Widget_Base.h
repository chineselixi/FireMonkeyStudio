
#ifndef WIDGET_BASE_H
#define WIDGET_BASE_H

#include "QWidget"
#include "QVector"

class Widget_Base
{
public:

    //设置接口
    enum setType{
        String,
        Number,
        CheckBox,
        file,
        color,
    };

    //设置子项信息
    struct setItemMsg{
        QString name = "";                      //属性名称
        setType type = setType::String;         //属性类型
        QString value = "";                     //属性值
        QString valueList = "@";                //属性值的列表
        bool enable = false;                    //属性是否启用
        QString sign = "基础属性";               //标记，可以用于重名的属性区分
    };


public:
    Widget_Base();


private:
    QString name;




public:
    bool container = false; //是否为容器
    QVector<setItemMsg> setItemList;  //设置属性的列表


public:
    virtual QWidget* getWidgetInstance() = 0; //获取控件实例

    void setObjectName(QString objName);    //设置对象名
    QString getObjectName();                //获取对象名
    QString getBaseName();                  //获取基础名称

};

#endif // WIDGET_BASE_H
