#ifndef FUNUTIL_H
#define FUNUTIL_H


class QWidget;
class QRect;
class QRectF;
class QString;
class QSizeF;
class QColor;
class QPointF;
class QLocale;
class QSizePolicy;
class QCursor;

class Plugin_Base;

class FunUtil
{
public:
    ///
    /// \brief 获取组件相对于父组件的位置
    /// \param 需要定位的组件
    /// \param 相对的父组件
    /// \param 返回的相对位置应用
    /// \return 如果不存在此父组件，则返回false
    ///
    static bool getWidgetRelativePosition(QWidget* widget,QWidget* parentWidget,QRect& returnRect);

    //不同转换
    static QString rectToString(QRectF rectf);
    static QRectF stringToRect(QString str);

    static QString sizeToString(QSizeF size);
    static QSizeF stringToSize(QString str);

    static QString pointToString(QPointF point);
    static QPointF stringToPoint(QString str);

    static QString localeToString(QLocale locale);
    static QLocale stringToLocale(QString str);

    static QString SizePolicyToString(QSizePolicy SizePolicy);
    static QSizePolicy stringToSizePolicy(QString str);

    static QString cursorToString(QCursor cursor);
    static QCursor stringToSizeCursor(QString str);

    static QString colorToString(QColor color);
    static QColor stringToColor(QString str);
};

#endif // FUNUTIL_H
