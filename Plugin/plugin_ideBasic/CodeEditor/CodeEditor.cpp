
#include "CodeEditor.h"
#include "Qsci/qscicommand.h"
#include "Qsci/qscilexercpp.h"
#include "Qsci/qsciapis.h"
#include "globalValue.h"

CodeEditor::CodeEditor(QWidget *parent):
    QsciScintilla(parent)
{
    this->setMarginType(0,QsciScintilla::NumberMargin);//设置编号为0的页边显示行号
    this->setMarginLineNumbers(0,true);//对该页边启用行号
    this->setMarginWidth(0,35);//设置页边宽度


    this->setIndentationsUseTabs(false); //如果设置为false，则采用空格缩进；如果设置为true，则采用 Tab 缩进。
    this->setTabWidth(4); //缩进4个字符
    this->setIndentationGuides(true); //显示缩进级别，在缩进处显示一个虚线
    this->setFont(Font_Normal); //编辑器设置字体，可能无效。需要此法分析设置才有效
    this->SendScintilla(QsciScintilla::SCI_SETCODEPAGE,QsciScintilla::SC_CP_UTF8); //设置为UTF-8编码
    this->setAutoIndent(true);

    QsciLexerCPP *textLexer = new QsciLexerCPP; //创建词法分析器

    //设置此法分析的颜色
    textLexer->setPaper(QColor("#909700"), QsciLexerCPP::CommentDoc);      //设置多行备注为浅绿色
    textLexer->setColor(QColor(Qt::gray),QsciLexerCPP::CommentLine);    //设置自带的注释行为灰色
    textLexer->setColor(QColor(Qt::blue),QsciLexerCPP::GlobalClass);   //全局类
    textLexer->setColor(QColor(Qt::blue),QsciLexerCPP::Keyword);    //关键字颜色
    textLexer->setColor(QColor("#df5c00"),QsciLexerCPP::KeywordSet2);   //设置自定义关键字的颜色为橘红色
    textLexer->setColor(QColor(Qt::darkBlue), QsciLexerCPP::PreProcessor); //设置预处理命令颜色
    textLexer->setColor(QColor("#008000"), QsciLexerCPP::SingleQuotedString); //字符颜色
    textLexer->setColor(QColor("#008000"), QsciLexerCPP::DoubleQuotedString); //字符串颜色
    textLexer->setColor(QColor(Qt::darkBlue), QsciLexerCPP::Number); //数字颜色
    textLexer->setColor(QColor("#dd001b"),QsciLexerCPP::Operator); //设置标点为红色



    //设置字体
    textLexer->setFont(Font_Normal); //此法分析设置字体
    this->setLexer(textLexer);


    this->setAutoCompletionSource(QsciScintilla::AcsAll);//设置自动完成所有项
    this->setAutoCompletionCaseSensitivity(true);//设置大小写敏感
    this->setAutoCompletionThreshold(1);//每输入1个字符就出现自动完成的提示
    this->setFolding(QsciScintilla::BoxedTreeFoldStyle); //设置折叠标记
    this->setFoldMarginColors(QColor("#f0f0f0"), QColor("#f0f0f0"));



    this->setAutoIndent(true);//开启自动缩进
    this->setIndentationGuides(QsciScintilla::SC_IV_LOOKBOTH);//设置缩进的显示方式
    this->setCaretLineVisible(true);//显示选中的行号
    this->setCaretLineBackgroundColor(Color_SignBackground);//显示选中行号的背景色
    this->setMarginsBackgroundColor(Color_LineNumberBackground);//左侧行号显示的背景色
    this->setBraceMatching(QsciScintilla::SloppyBraceMatch);//设置括号匹配
    this->setAutoCompletionReplaceWord(true); //此选项选择在选择自动完成时是否覆盖光标右侧的字符（直到到达分隔符）


    //智能提示的关键字
    QsciAPIs *apis = new QsciAPIs(textLexer);
    apis->load(":/apis/res/apis/keyWords.txt"); //添加关键字到智能提示
    apis->load(":/apis/res/apis/clFun.txt"); //添加基本的c语言API到提示
    apis->load(":/apis/res/apis/define.txt"); //添加预处理命令
    apis->prepare();//在这里可以添加自定义的自动完成函数

    //添加关键字
    QPixmap t_pix;
    t_pix.load(":/tipsIcon/res/tipIcon/key.png"); //添加关键字提示图片
    this->registerImage(1,t_pix);
    t_pix.load(":/tipsIcon/res/tipIcon/fun.png"); //添加函数提示图片
    this->registerImage(2,t_pix);
    t_pix.load(":/tipsIcon/res/tipIcon/foresight.png"); //添加预处理图片
    this->registerImage(3,t_pix);




    this->SetSign();
}




void CodeEditor::SetSign()
{
    this->setText("12345678\n21313123131");

    this->SendScintilla(QsciScintilla::SCI_GOTOLINE, 2);



    // 获取当前行号

    //int line_num = this->SendScintilla(QsciScintilla::SCI_LINEFROMPOSITION, this->cursor().pos());


    //this->SendScintilla()

    // 设置标记背景色为黄色
    //this->markerDefine(QsciScintilla::SCI_SETWHITESPACEBACK, QColor(255, 255, 0));
    // 设置标记前景色为透明
    this->SendScintilla(QsciScintilla::SCI_INDICSETFORE, 0, QColor(236, 188, 29));
    // 设置标记样式为波浪线
    this->SendScintilla(QsciScintilla::SCI_INDICSETSTYLE, 0, QsciScintilla::INDIC_SQUIGGLE);
    // 在第35行的14列到25列之间填充标记
    //this->SendScintilla(QsciScintilla::SCI_GOTOLINE, 35);




    int start = this->positionFromLineIndex(0,0);
    int end = this->positionFromLineIndex(0,7);
    //INDICATORFILLRANGE
    this->SendScintilla(QsciScintilla::SCI_INDICATORFILLRANGE, start, end - start);
}
