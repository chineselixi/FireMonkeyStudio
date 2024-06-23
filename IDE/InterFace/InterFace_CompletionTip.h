#ifndef INTERFACE_COMPLETIONTIP_H
#define INTERFACE_COMPLETIONTIP_H

#include "QString"
#include "QPoint"

class InterFace_CompletionTip{

public:
    typedef std::function<void(uint16_t startLine,uint16_t startCharacter,uint16_t endLine,uint16_t endCharacter, QString newText)> TipSelectFunction;  //回调方法

public:
    //添加一个提示消息
    virtual void addTip(
        int kind,                       //提示类型
        QString filterText,             //过滤文本
        QString insertText,             //插入文本
        int insertTextFormat,           //插入类型
        QString label,                  //提示的文本
        double score,                   //排序值，越大越前面
        QString sortText,               //排序文本
        QString newText,                //要替换的文本
        uint16_t startLine = 0,         //开始行
        uint16_t startCharacter = 0,    //开始文本列
        uint16_t endLine = 0,           //结束行
        uint16_t endCharacter = 0       //结束文本列
        ) = 0;

    //关闭所有提示
    virtual void clearAll() = 0;

    //显示菜单（左上角位置）
    virtual void showMenu(QPoint point, TipSelectFunction tipFun) = 0;

    //隐藏菜单
    virtual void hidden() = 0;

    //调整菜单尺寸和位置
    virtual void adjustWindowRec() = 0;

    //选择选项
    virtual void selectItem(TipSelectFunction tipFun = nullptr) = 0;

    //选择上一个
    virtual void up() = 0;

    //选择下一个
    virtual void down() = 0;

};

#endif // INTERFACE_COMPLETIONTIP_H
