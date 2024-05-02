#include "Plugin_Base.h"
#include "QMenu"
#include "QJsonObject"
#include "QJsonArray"
#include "util/FunUtil.h"

//从列表获取属性指针
AttributeNode *Plugin_Base::getListAttr(QList<AttributeNode> &attrs, QString group, QString attrSign)
{
    for(AttributeNode& item : attrs){
        if(item.group == group && item.attrSign == attrSign){
            return &item;
        }
    }
    return nullptr;
}


//将属性转换为Json对象
QJsonValue Plugin_Base::attributesToJson(QList<AttributeNode> attrs)
{
    QJsonArray t_retJsonArray;
    for(AttributeNode an : attrs){
        QJsonObject t_jsonObj;
        QJsonValue t_v;
        if(an.value.typeId() == QMetaType::Type::Int){
            t_v = an.value.toInt();
        }
        else if(an.value.typeId() == QMetaType::Type::Double){
            t_v = an.value.toDouble();
        }
        else if(an.value.typeId() == QMetaType::Type::Bool){
            t_v = an.value.toBool();
        }
        else if(an.value.typeId() == QMetaType::Type::QString){
            t_v = an.value.toString();
        }
        else if(an.value.typeId() == QMetaType::Type::QDate){
            t_v = an.value.toDate().toString();
        }
        else if(an.value.typeId() == QMetaType::Type::QDateTime){
            t_v = an.value.toDateTime().toString();
        }
        else if(an.value.typeId() == QMetaType::Type::QKeySequence){
            t_v = an.value.value<QKeySequence>().toString();
        }
        else if(an.value.typeId() == QMetaType::Type::QChar){
            t_v = QString(an.value.toChar());
        }
        else if(an.value.typeId() == QMetaType::Type::QLocale){
            t_v = FunUtil::localeToString(an.value.toLocale());
        }
        else if(an.value.typeId() == QMetaType::Type::QPoint){
            t_v = FunUtil::pointToString(an.value.toPoint());
        }
        else if(an.value.typeId() == QMetaType::Type::QPointF){
            t_v = FunUtil::pointToString(an.value.toPointF());
        }
        else if(an.value.typeId() == QMetaType::Type::QSize){
            t_v = FunUtil::sizeToString(an.value.toSize());
        }
        else if(an.value.typeId() == QMetaType::Type::QSizeF){
            t_v = FunUtil::sizeToString(an.value.toSizeF());
        }
        else if(an.value.typeId() == QMetaType::Type::QRect){
            t_v = FunUtil::rectToString(an.value.toRect());
        }
        else if(an.value.typeId() == QMetaType::Type::QRectF){
            t_v = FunUtil::rectToString(an.value.toRectF());
        }
        else if(an.value.typeId() == QMetaType::Type::QColor){
            t_v = FunUtil::colorToString(an.value.value<QColor>());
        }
        else if(an.value.typeId() == QMetaType::Type::QSizePolicy){
            t_v = FunUtil::SizePolicyToString(an.value.value<QSizePolicy>());
        }
        else if(an.value.typeId() == QMetaType::Type::QFont){
            t_v = an.value.value<QFont>().toString();
        }
        else if(an.value.typeId() == QMetaType::Type::QCursor){
            t_v = FunUtil::cursorToString(an.value.value<QCursor>());
        }
        else{
            t_v = an.value.toString();
        }

        QJsonArray t_enumJson;
        for(QString enumItem : an.enums){
            t_enumJson.append(enumItem);
        }
        t_jsonObj.insert("enums",t_enumJson);           //枚举项
        t_jsonObj.insert("canEdit",an.canEdit);         //保存是否编辑
        t_jsonObj.insert("group",an.group);             //组
        t_jsonObj.insert("attrSign",an.attrSign);       //属性标记
        t_jsonObj.insert("title",an.title);             //显示标题
        t_jsonObj.insert("value",t_v);                  //值
        t_jsonObj.insert("valueType",an.value.typeId());//值类型
        t_retJsonArray.append(t_jsonObj);   //保存对象到组
    }
    return t_retJsonArray;
}


//将jsonArray转换为attrs
QList<AttributeNode> Plugin_Base::jsonArrayToAttrs(QJsonArray jsonArray)
{
    QList<AttributeNode> t_attrs;
    for(QJsonValue jsonValue : jsonArray){
        QJsonObject t_jsonObject = jsonValue.toObject();
        AttributeNode t_an;

        QStringList t_sl;
        for(QJsonValue jv : t_jsonObject.value("enums").toArray()){
            t_sl.append(jv.toString());
        }
        t_an.enums = t_sl;
        t_an.canEdit = t_jsonObject.value("canEdit").toBool();
        t_an.group = t_jsonObject.value("group").toString();
        t_an.attrSign = t_jsonObject.value("attrSign").toString();
        t_an.title = t_jsonObject.value("title").toString();
        t_an.value = jsonvalueToVariant(t_jsonObject.value("value"),QMetaType::Type(t_jsonObject.value("valueType").toInt()));
        t_attrs.append(t_an);
    }
    return t_attrs;
}

//将jsonValue转换为QVariant
QVariant Plugin_Base::jsonvalueToVariant(QJsonValue jsonValue, QMetaType::Type type)
{
    QVariant t_retVariant;
    QString t_jsonStr = jsonValue.toString();
    if(type == QMetaType::Type::Int){
        t_retVariant.setValue(jsonValue.toInt());
    }
    else if(type == QMetaType::Type::Double){
        t_retVariant.setValue(jsonValue.toDouble());
    }
    else if(type == QMetaType::Type::Bool){
        t_retVariant.setValue(jsonValue.toBool());
    }
    else if(type == QMetaType::Type::QString){
        t_retVariant.setValue(jsonValue.toString());
    }
    else if(type == QMetaType::Type::QDate){
        t_retVariant.setValue(QDate::fromString(t_jsonStr));
    }
    else if(type == QMetaType::Type::QDateTime){
        t_retVariant.setValue(QDateTime::fromString(t_jsonStr));
    }
    else if(type == QMetaType::Type::QKeySequence){
        t_retVariant.setValue(QKeySequence::fromString(t_jsonStr));
    }
    else if(type == QMetaType::Type::QChar){
        t_retVariant.setValue(t_jsonStr[0]);
    }
    else if(type == QMetaType::Type::QLocale){
        t_retVariant.setValue(FunUtil::stringToLocale(t_jsonStr));
    }
    else if(type == QMetaType::Type::QPoint){
        t_retVariant.setValue(FunUtil::stringToPoint(t_jsonStr).toPoint());
    }
    else if(type == QMetaType::Type::QPointF){
        t_retVariant.setValue(FunUtil::stringToPoint(t_jsonStr));
    }
    else if(type == QMetaType::Type::QSize){
        t_retVariant.setValue(FunUtil::stringToSize(t_jsonStr).toSize());
    }
    else if(type == QMetaType::Type::QSizeF){
        t_retVariant.setValue(FunUtil::stringToSize(t_jsonStr));
    }
    else if(type == QMetaType::Type::QRect){
        t_retVariant.setValue(FunUtil::stringToRect(t_jsonStr).toRect());
    }
    else if(type == QMetaType::Type::QRectF){
        t_retVariant.setValue(FunUtil::stringToRect(t_jsonStr));
    }
    else if(type == QMetaType::Type::QColor){
        t_retVariant.setValue(FunUtil::stringToColor(t_jsonStr));
    }
    else if(type == QMetaType::Type::QSizePolicy){
        t_retVariant.setValue(FunUtil::stringToSizePolicy(t_jsonStr));
    }
    else if(type == QMetaType::Type::QFont){
        QFont t_font;
        t_font.fromString(t_jsonStr);
        t_retVariant.setValue(t_font);
    }
    else if(type == QMetaType::Type::QCursor){
        t_retVariant.setValue(FunUtil::stringToSizeCursor(t_jsonStr));
    }
    else{
        t_retVariant.setValue(t_jsonStr);
    }
    return t_retVariant;
}


//子控件进入(参数1为容器控件，是本插件插件的。参数2为进入的子控件)
void Plugin_Base::subWidgetEnter(QWidget *packWidget, QWidget *subWidget)
{

}

//系统获取插件的右键菜单
QList<QAction *> Plugin_Base::getMenuAction()
{
    return QList<QAction *>();
}

//菜单选项被按下
void Plugin_Base::onMenuActionClick(QAction* action,widgetMsg* widget)
{

}

//组件创建返回的代码
QString Plugin_Base::code_onWidgetBuild(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}

//组件属性赋值返回的代码
QString Plugin_Base::code_onAttributeBuild(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}

//组件销毁返回的代码
QString Plugin_Base::code_onWidgetClose(QWidget *widget, QList<AttributeNode> attrs, QList<EventNode> events)
{
    return "";
}
