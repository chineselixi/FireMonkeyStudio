#ifndef FORM_PROPERTYEDITOR_H
#define FORM_PROPERTYEDITOR_H

#include <QWidget>
#include "GlobalMsg.h"
#include "Plugins/Plugin_Base.h"
//#include "../qtpropertybrowser/qttreepropertybrowser.h"
#include "../qtpropertybrowser/qtvariantproperty.h"
#include "../qtpropertybrowser/qteditorfactory.h"



#define NORMALGROUP "FIREMONKEYPROPERTY"


class Form_EditorSpace; //编辑器指针，用于通知对象名

namespace Ui {
class Form_PropertyEditor;
}

class Form_PropertyEditor : public QWidget
{
    Q_OBJECT

private:

    //记录属性节点
    struct property{
        QtProperty* propertyPtr = nullptr;
        AttributeNode attrNode;
    };

public:
    explicit Form_PropertyEditor(QWidget *parent = nullptr);
    ~Form_PropertyEditor();

private:
    Ui::Form_PropertyEditor *ui;

    QtVariantPropertyManager* variantPropertyManger = nullptr;  //抽象普通属性管理器
    QtEnumPropertyManager* enumPropertyMsnger= nullptr;         //抽象枚举属性管理器

    QtVariantEditorFactory * variantPropertyFactory = nullptr;  //抽象工厂
    QtEnumEditorFactory* enumPropertyFactory = nullptr;         //枚举工厂

    QWidget* editorBaseWidget = nullptr;   //当前选择的编辑器文本标记（可能存在多个编辑器）
    widgetMsg* nowSelectWidgetMsg;    //当前选择的信息
    QList<property> propertyList;   //属性节点组

public:
    void showWidgetsAttr(QWidget* signBaseWidget, widgetMsg* selectWidget); //显示控件组的属性

private:

    QtProperty* addProperty(AttributeNode an);    //添加属性信息
    QList<property*> getPropertyMsgByGroup(QString group);  //根据组获取属性节点信息
    AttributeNode* getAttr(QtProperty* property);  //根据QtProperty指针获取attr
    void getListDifference(QStringList oldStrList,QStringList newStrList,QStringList& retSame,QStringList& retLack,QStringList& retNew); //两个字符串列表，返回两个元素系统部分，新较少的缺少部分和增加部分
    void showBaseProperty(QWidget* widget); //显示基础的属性信息

signals:
    void onWidgetNameChange(QWidget* signBaseWidget,widgetMsg* updateWidgetMessage,QString& newName); //控件名称被改变事件
    void onWidgetUpdate(QWidget* signBaseWidget,widgetMsg* updateWidgetMessage); //控件属性被改变事件

public slots:
    void PropertyValueChanged(QtProperty *property, const QVariant &value); //编辑的内容被改变
    void EnumValueChanged(QtProperty *property, int val); //编辑器枚举被改变

};

#endif // FORM_PROPERTYEDITOR_H
