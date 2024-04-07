#ifndef FUNUTIL_H
#define FUNUTIL_H


class QWidget;
class QRect;

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
};

#endif // FUNUTIL_H
