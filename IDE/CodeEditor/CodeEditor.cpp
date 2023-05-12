#include "CodeEditor.h"

#include <QPainter>
#include <QTextBlock>



CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{

    LeftSpaceWidget = new LineNumberArea(this);
    Model_HeighLight = new mod_HeighLightEditor(this->document());
    //this->document()->setDocumentLayout(new QPlainTextDocumentLayout(textDecument));


    this->Model_TipList = new mod_TipList(this,QSize(16,16)); //激发当前的事件
    connect(this->Model_TipList,&mod_TipList::onTipOut,this,&CodeEditor::event_onTipOut); //绑定提示信息
    //this->Model_TipList->AddListMsg(Model_TipList->KeyWordList,{"char","int","string","char","inteee","in","bbbi","aina"});
    this->Model_TipList->setHidden(true);


    this->Updata_Init(); //初始化
}

CodeEditor::~CodeEditor()
{
    delete Model_HeighLight; //回收
}


//初始化
void CodeEditor::Updata_Init()
{
    this->Updata_Color(); //初始化颜色
    this->setFont(Font_Normal);


    connect(this, &CodeEditor::blockCountChanged, this, &CodeEditor::updateLineNumberAreaWidth);  //行数更改，检索行数区域的宽度
    connect(this, &CodeEditor::updateRequest, this, &CodeEditor::ChangeLeftSpace);                //更新左边的行号区域，若焦点存在则持续刷新
    connect(this, &CodeEditor::cursorPositionChanged, this, &CodeEditor::HighLightCurrentLine);   //光标位置更改，检索左边区域宽度

    connect(this, &CodeEditor::textChanged, this, &CodeEditor::event_onTextChanged);   //当编辑器输入内容事件


    this->updateLineNumberAreaWidth(0);
    this->HighLightCurrentLine();         //行高亮颜色设置
}




//获取高亮模块
mod_HeighLightEditor *CodeEditor::GetModel_HeighLight()
{
    return Model_HeighLight;
}




//获取智能提示模块
mod_TipList *CodeEditor::GetModel_Tips()
{
    return this->Model_TipList;
}



//获取光标处的文本,如果参数为真，则获取光标左右处的文本
void CodeEditor::GetCursorString(QString& leftStr,QString& rightStr,QString& lineStr)
{
    QTextCursor t_textCursor = this->textCursor(); //获取文本光标位置
    int lineNumber = t_textCursor.blockNumber();
    int columnNumber = t_textCursor.positionInBlock();

    lineStr = this->document()->findBlockByLineNumber(lineNumber).text();
    QString List_Sign = QString("— !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~");

    leftStr = "";
    rightStr = "";

    //检索文本左边
    for(int a=columnNumber;a > 0;a--){
        for(int b = 0;b < List_Sign.length(); b++){
            if(lineStr[a - 1] == List_Sign[b]){
                leftStr = lineStr.mid(a,columnNumber - a);
                goto LEFT_BREAK;
            }
        }
    }
    leftStr = lineStr.mid(0,columnNumber);
    LEFT_BREAK:

    //检索文本右边
    int a=columnNumber;
    for(a=columnNumber;a < lineStr.length();a++){
        for(int b = 0;b < List_Sign.length(); b++){
            if(lineStr[a] == List_Sign[b]){
                rightStr = lineStr.mid(columnNumber,a - columnNumber);
                return;
            }
        }
    }
    rightStr = lineStr.mid(columnNumber,a - columnNumber);
    //t_rightStr = t_linStr.mid(columnNumber,t_linStr.length() - columnNumber);
}



//获取光标位置
QRect CodeEditor::GetCursorPersion()
{
    QRect t_persion = this->Persion_CursorRect;
    t_persion.setLeft(t_persion.left() + GetLeftSpaceWidth());

    //当前行高
    QFontMetrics t_fontMetrics(this->font());
    int t_lineHegiht = t_fontMetrics.lineSpacing();

    t_persion.setTop(t_persion.top() + t_fontMetrics.lineSpacing());
    t_persion.setWidth(200);
    t_persion.setHeight(300);

    if(t_persion.left() + t_persion.width() > this->rect().width()){
        t_persion.setLeft(t_persion.left() - t_persion.width());
        t_persion.setWidth(200);
    }
    if(t_persion.top() + t_persion.height() > this->rect().height()){
        int t_top = t_persion.top() - t_persion.height() - t_lineHegiht;
        if(t_top > 0){
            t_persion.setTop(t_persion.top() - t_persion.height() - t_lineHegiht);
        }
        t_persion.setHeight(300);
    }
    return t_persion;
}



//当提示被激发
void CodeEditor::event_onTipOut(QString tipStr)
{
    QString t_left,t_right,t_line;
    this->GetCursorString(t_left,t_right,t_line);

    QString t_insertStr = tipStr;

    if(tipStr.left(t_left.length()) == t_left){
        t_insertStr = tipStr.right(tipStr.length() - t_left.length());
    }
    this->insertPlainText(t_insertStr);
}



//文本被改变
void CodeEditor::event_onTextChanged()
{
    static int t_textSize = 0;
    int t_newTextSize = this->toPlainText().length();
    this->Model_TipList->setHidden(true);

    QString t_left,t_right,t_line;
    if(t_textSize < t_newTextSize){
        this->GetCursorString(t_left,t_right,t_line);
        this->event_onTipWillShow(t_left,t_right,t_line); //激活当提示即将提示
        this->event_showTip(t_left);
    }
    t_textSize = t_newTextSize;
    //this->Model_TipList->
}



//展示提示信息
void CodeEditor::event_showTip(QString src)
{
    this->Model_TipList->ShowTips(src,this->GetCursorPersion());
}


//按钮按下信息
void CodeEditor::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() == Qt::NoModifier){
        if(!this->Model_TipList->isHidden()){

            if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Down ||  event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
                this->Model_TipList->keyPressEvent(event);
                return;
            }
        }

        if(event->key() == Qt::Key_Tab){
            this->insertPlainText("    ");//Tab等于4个空格
            return;
        }
    }




    QPlainTextEdit::keyPressEvent(event);
}




//获取行宽度
int CodeEditor::GetLeftSpaceWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    QFontMetricsF t_fm(Font_LineNomber);
    this->Width_LineNumber = t_fm.size(0,"9").width() * digits + Width_padding_LineNumber * 2;
    this->Width_Sign = t_fm.height();
    return this->Width_LineNumber + this->Width_Sign + this->Width_Fold;
}

//设置行号字体
void CodeEditor::SetLineFont(QFont font)
{
    Font_LineNomber = font;
}


//更新行宽度
void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    this->setViewportMargins(GetLeftSpaceWidth(), 0, 0, 0);
}



//更新左边的行号区域
void CodeEditor::ChangeLeftSpace(const QRect &rect, int dy)
{
    if (dy)
        LeftSpaceWidget->scroll(0, dy);
    else
        LeftSpaceWidget->update(0, rect.y(), LeftSpaceWidget->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}



//自动铺满尺寸
void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);
    LeftSpaceWidget->setGeometry(0, 0, GetLeftSpaceWidth(), this->height()); //左边区域的宽度
}


//光标位置已更改，绘制当前行的的黄颜色背景
void CodeEditor::HighLightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;
    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        selection.format.setBackground(Color_NowLineBackground);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }
    setExtraSelections(extraSelections);

    //更新光标信息
    Persion_CursorRect = this->cursorRect();
}



//绘制行号
void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(LeftSpaceWidget);
    QPen pen(Color_NormalText);        //画笔
    QBrush brush(Color_LineNumberBackground); //刷子

    //填充背景
    pen.setStyle(Qt::PenStyle::SolidLine);
    pen.setColor(Color_LineNumber);//默认头文字颜色
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    brush.setColor(Color_LineNumberBackground);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.setFont(Font_LineNomber);
    painter.drawRect(0, 0, LeftSpaceWidget->width(), LeftSpaceWidget->height());//填充背景


    //开始绘制行号
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = qRound(blockBoundingGeometry(block).translated(contentOffset()).top());
    int bottom = top + qRound(blockBoundingRect(block).height());

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            //painter.setPen(Qt::black);
            painter.drawText(0, top, Width_LineNumber, this->fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + qRound(blockBoundingRect(block).height());
        ++blockNumber;
    }
}


//更新颜色值
void CodeEditor::Updata_Color()
{
    QPalette t_pl = this->palette();     // 获取textEdit的调色板
    t_pl.setColor(QPalette::Base, Color_LineNumberBackground);    // 设置背景色为黑色
    t_pl.setColor(QPalette::Text, Color_NormalText);    // 设置文本颜色为绿色

    LeftSpaceWidget->setPalette(t_pl);              // 设置调色板
}


