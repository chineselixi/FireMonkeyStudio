#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include "module/mod_HeighLightEditor.h"
#include "module/mod_TipList.h"


QT_BEGIN_NAMESPACE
class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
QT_END_NAMESPACE

class LineNumberArea;



//代码编辑器类
class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

private:
    int Width_LineNumber = 10; //行号区域的宽度
    int Width_Sign = 10; //标记区域的宽度
    int Width_Fold = 10; //折叠区域的宽度

    int Width_padding_LineNumber = 4;//行号区域的左右填充
    int Width_padding_Sign = 4; //标记区域的左右填充
    int Width_padding_Fold = 4; //折叠区域的左右填充

    QFont Font_Normal = QFont("Monaco",16);
    QFont Font_LineNomber = QFont("Monaco",16);

    QRect Persion_CursorRect = QRect(-100,-100,0,0);//光标所在位置
public:
    QColor Color_CodeEditorBackGround = QColor::fromRgb(255, 255, 255);  //代码编辑框背景
    QColor Color_NormalText = QColor::fromRgb(0, 0, 0);                  //默认文字颜色
    QColor Color_LineNumberBackground = QColor::fromRgb(67, 87, 123);    //行号显示区域颜色
    QColor Color_LineNumber = QColor::fromRgb(118, 224, 0);        //行号颜色
    QColor Color_SignBackground = QColor::fromRgb(0, 128, 128);               //标记显示区域颜色
    QColor Color_NowLineBackground = QColor::fromRgb(220,220,220);


public:
    CodeEditor(QWidget *parent = nullptr);
    ~CodeEditor();

    void lineNumberAreaPaintEvent(QPaintEvent *event);  //由子项调用重绘事件
    int GetLeftSpaceWidth();                            //计算左边区域的宽度
    void SetLineFont(QFont font);                       //设置编辑器字体
    void Updata_Color();                                //更新颜色值
    void Updata_Init();                                 //初始化


    mod_HeighLightEditor* GetModel_HeighLight();        //获取高亮模块
    mod_TipList *GetModel_Tips();                       //获取智能提示模块
    void GetCursorString(QString& leftStr,QString& rightStr,QString& lineStr);        //获取光标处的文本,如果参数为真，则获取光标所在词汇的的文本
    QRect GetCursorPersion();                           //获取光标位置


    void event_onTipOut(QString tipStr); //当提示文本被激发,提示模块向文本编辑器输入
    void event_onTextChanged(); //当文本被改变
    void event_showTip(QString src); //展示提示信息

public:
    void keyPressEvent(QKeyEvent *event);       //按钮按下信息

private:
    QWidget* LeftSpaceWidget;                      //行号窗体
    mod_HeighLightEditor* Model_HeighLight;        //高亮模块
    mod_TipList* Model_TipList;                    //智能提示模块
//    QTextDocument* textDecument;                   //文档流，用于模块的控制，在初始化


private slots:
    void updateLineNumberAreaWidth(int newBlockCount);      //更新行号显示区域的宽度
    void HighLightCurrentLine();                            //高亮行区域
    void ChangeLeftSpace(const QRect &rect, int dy);        //改变左边区域的宽度

protected:
    void resizeEvent(QResizeEvent *event) override;         //重写改变



signals:
    void event_onTipWillShow(QString leftText,QString rightText,QString lineText); //当提示即将提示

};






//绘制窗体类
class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeEditor *editor) : QWidget(editor), codeEditor(editor)
    {}

    QSize sizeHint() const override
    {
        return QSize(codeEditor->GetLeftSpaceWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEditor *codeEditor;
};


#endif
