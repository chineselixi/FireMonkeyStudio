#ifndef GLOBALMSG_H
#define GLOBALMSG_H

#include "QWidget"


class Plugin_Base;


//属性节点结构体
struct AttributeNode{
    QString title;          //属性显示标题
    QString group;          //分组标记
    QString attrSign;       //属性标记
    QVariant value;         //属性值
    QList<QString> enums;  //附加的枚举，如果此项目长度大于0，则该属性为枚举属性
    bool canEdit = true;    //是否可编辑

private:
    bool equals(const AttributeNode& t_attr){
        if(this->title == t_attr.title &&
            this->group == t_attr.group &&
            this->attrSign == t_attr.attrSign &&
            this->enums == t_attr.enums){
            return true;
        }
        return false;
    }
public:
    bool operator==(const AttributeNode& t_attr){
        return equals(t_attr) && this->value == t_attr.value;
    }
    bool operator ^(const AttributeNode& t_attr){
        return equals(t_attr);
    }
    bool operator!=(const AttributeNode& t_attr){
        return !equals(t_attr);
    }
};

//事件节点结构体
struct EventNode{
    QString eventTitle;         //事件显示的标题
    QString attrName;           //对象事件的名字
    QString eventLambda;        //事件的Labbda表达式
};


//控件信息组
struct widgetMsg{
    QString objectName = "null";        //对象名
    Plugin_Base* pluginPtr = nullptr;   //处理的插件指针
    QWidget* widget = nullptr;          //控件指针
    QString classSign = "NULL";         //类标记
    bool isSelect = false;              //是否选择
    bool isPack = false;                //是否为容器
    QList<AttributeNode> attrs;         //属性列表
    QList<EventNode> events;            //事件列表
};



class Form_WidgetBox;
class Form_PropertyEditor;
class Plugin_Base;

namespace Form {
extern Form_WidgetBox* widgetBoxPtr; // 组件盒子指针
extern Form_PropertyEditor* PropertyEditorPtr;  //控件属性编辑器指针
}

namespace Plugin{
extern Plugin_Base* nowSelectPlugin;    //当前选择的插件
}


#endif // GLOBALMSG_H
