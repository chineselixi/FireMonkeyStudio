
#include "Widget_Base.h"
//#include


Widget_Base::Widget_Base()
{

    QWidget* w;
    w->setGeometry()

    QString classStr;
    classStr = "对象";
    setItemList.append(
        {
            {"对象名",setType::Number,"0","",true,classStr},
            {"启用",setType::Number,"0","",true,classStr},
        });

    classStr = "基本尺寸";
    setItemList.append(
        {
            {"左边",setType::Number,"0","",true,classStr},
            {"顶边",setType::Number,"0","",true,classStr},
            {"宽度",setType::Number,"0","",true,classStr},
            {"高度",setType::Number,"0","",true,classStr},
        });

    classStr = "最小尺寸";
    setItemList.append(
        {
            {"宽度",setType::Number,"0","",true,classStr},
            {"高度",setType::Number,"0","",true,classStr},
        });

    classStr = "最大尺寸";
    setItemList.append(
        {
            {"宽度",setType::Number,"0","",true,classStr},
            {"高度",setType::Number,"0","",true,classStr},
        });
}

