#ifndef FORM_PROPERTYEDITOR_H
#define FORM_PROPERTYEDITOR_H

#include <QWidget>
#include "GlobalMsg.h"
#include "Plugins/Plugin_Base.h"
#include "../qtpropertybrowser/qttreepropertybrowser.h"
#include "../qtpropertybrowser/qtvariantproperty.h"
#include "../qtpropertybrowser/qteditorfactory.h"



class Form_EditorSpace; //编辑器指针，用于通知对象名

namespace Ui {
class Form_PropertyEditor;
}

class Form_PropertyEditor : public QWidget
{
    Q_OBJECT

public:
    explicit Form_PropertyEditor(QWidget *parent = nullptr);
    ~Form_PropertyEditor();

private:
    Ui::Form_PropertyEditor *ui;
    QtVariantPropertyManager* propertyManger = nullptr; //创建抽象属性管理器
    QtVariantEditorFactory * propertyFactory = nullptr;
    QtEnumPropertyManager* propertyEnumMsnger= nullptr;
    QtEnumEditorFactory* propertyEnumFactory = nullptr;

    //Plugin_Base* showWidgetObject = nullptr;//显示的窗口对象

    QVector<Plugin_Base*> widgetObjects; //属性对象列表
    Form_EditorSpace* editorObj = nullptr;

public:
    //void loadProertyMsg(Plugin_Base* obj); //加载控件对象

    void loadPropertyMsgs(QVector<Plugin_Base*> objs,Form_EditorSpace* editor); //加载对象组
    void removeProertyMsg_obj(Plugin_Base* obj); //移除控件对象，若不移除，则可能出现奔溃
    void removeProertyMsg_editor(Form_EditorSpace* editor); //根据编辑器指针移除全部属性信息

    void showProertyMsg(); //显示属性信息

    template<class T>
    QVector<T> uniqueMsgList(QVector<T> v); //去除重复数据


public slots:
    void PropertyValueChanged(QtProperty *property, const QVariant &value); //编辑的内容被改变
    void EnumValueChanged(QtProperty *property, int val); //编辑器枚举被改变

};

#endif // FORM_PROPERTYEDITOR_H
