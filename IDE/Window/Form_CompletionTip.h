#ifndef FORM_COMPLETIONTIP_H
#define FORM_COMPLETIONTIP_H

#include <QWidget>
#include "QListWidgetItem"
#include "../Widget/Widget_Button_CompletionItem.h"

namespace Ui {
class Form_CompletionTip;
}

class Form_CompletionTip : public QWidget
{
    Q_OBJECT

private:
    struct TipNode{
        int kind = 12;              //提示类型
        QString filterText;         //过滤文本
        QString insertText;         //插入文本
        int insertTextFormat;       //插入类型
        QString label;              //提示的文本
        double score;               //排序值，越大越前面
        QString sortText;           //排序文本
        QString newText;            //要替换的文本
        uint16_t startLine = 0;     //开始行
        uint16_t startCharacter = 0;//开始文本列
        uint16_t endLine = 0;       //结束行
        uint16_t endCharacter = 0;  //结束文本列

        Widget_Button_CompletionItem* widget;     //列表项目自定义控件
        QListWidgetItem* item;      //列表项目
    };


    typedef std::function<void(
                uint16_t startLine,         //替换的开始行
                uint16_t startCharacter,    //替换的开始列
                uint16_t endLine,           //替换的结束行
                uint16_t endCharacter,      //替换的结束列
                QString newText)>
        TipSelectFunction;

    QList<TipNode> TipNodeList;     //通知列表
    QPoint showPoint;   //显示的位置
    TipSelectFunction selectItemFun = nullptr;


public:
    explicit Form_CompletionTip(QWidget *parent = nullptr);
    ~Form_CompletionTip();

    //添加一个提示消息
    void addTip(
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
    );

    //关闭所有提示
    void clearAll();

    //显示菜单（左上角位置）
    void showMenu(QPoint point, TipSelectFunction tipFun);

    //调整菜单尺寸和位置
    void adjustWindowRec();

    //选择选项
    void selectItem(TipSelectFunction tipFun);

    //选择上一个
    void up();

    //选择下一个
    void down();


protected:
    //窗口隐藏
    void hideEvent(QHideEvent *event) override;

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::Form_CompletionTip *ui;

    uint16_t index = 0;         //自增索引


};


#endif // FORM_COMPLETIONTIP_H
