#ifndef INTERFACE_COMPLETIONTIP_H
#define INTERFACE_COMPLETIONTIP_H

#include "QString"
#include "QPoint"

class InterFace_CompletionTip{

public:
    typedef std::function<void(uint16_t startLine,uint16_t startCharacter,uint16_t endLine,uint16_t endCharacter, QString newText)> TipSelectFunction;  //回调方法

public:
    //关闭所有提示
    virtual void clearAll() = 0;

    //显示菜单（左上角位置）
    virtual void showMenu(QPoint point, TipSelectFunction tipFun) = 0;

    //调整菜单尺寸和位置
    virtual void adjustWindowRec() = 0;

    //选择选项
    virtual void selectItem(TipSelectFunction tipFun) = 0;

    //选择上一个
    virtual void up() = 0;

    //选择下一个
    virtual void down() = 0;

};

#endif // INTERFACE_COMPLETIONTIP_H
