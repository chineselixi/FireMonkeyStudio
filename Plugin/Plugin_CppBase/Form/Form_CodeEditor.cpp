#include "Form_CodeEditor.h"
#include "ui_Form_CodeEditor.h"
#include "QFile"
#include "../../QScintilla/src/Qsci/qscilexercpp.h"

Form_CodeEditor::Form_CodeEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_CodeEditor)
{
    ui->setupUi(this);

    QFont font("Consolas", 12, QFont::Normal); //全局字体效果


    QsciLexer *textLexer = new QsciLexerCPP;
    textLexer->setFont(font);
    textLexer->setColor(QColor("#008000"),QsciLexerCPP::Comment);
    textLexer->setColor(QColor("#ff0000"),QsciLexerCPP::Number);
    textLexer->setColor(QColor("#008000"),QsciLexerCPP::CommentLineDoc);
    textLexer->setColor(QColor("#008000"),QsciLexerCPP::DoubleQuotedString);
    textLexer->setColor(QColor("#ff00ff"),QsciLexerCPP::SingleQuotedString);
    textLexer->setColor(QColor("#0055ff"),QsciLexerCPP::Keyword);
    textLexer->setColor(QColor("#0055ff"),QsciLexerCPP::PreProcessor);

    ui->sciEditor->setLexer(textLexer);//给QsciScintilla设置词法分析器

    //代码提示
//    QsciAPIs *apis = new QsciAPIs(textLexer);
//    apis->prepare();

    //    this->setFont(font1);

    ui->sciEditor->setAutoCompletionSource(QsciScintilla::AcsAll);   //设置源，自动补全所有地方出现的
    ui->sciEditor->setAutoCompletionCaseSensitivity(true);   //设置自动补全大小写敏感
    ui->sciEditor->setAutoCompletionThreshold(1);    //设置每输入2个字符就会出现自动补全的提示

    //设置自动缩进
    ui->sciEditor->setAutoIndent(true);

    //Enables or disables, according to enable, this display of indentation guides.
    ui->sciEditor->setIndentationGuides(true);

    //current line color
    ui->sciEditor->setCaretWidth(2);//光标宽度，0表示不显示光标
    ui->sciEditor->setCaretForegroundColor(QColor("darkCyan"));  //光标颜色
    ui->sciEditor->setCaretLineVisible(true); //是否高亮显示光标所在行
    ui->sciEditor->setCaretLineBackgroundColor(QColor("#e0e0e0"));//光标所在行背景颜色

    //selection color
    ui->sciEditor->setSelectionBackgroundColor(QColor("#99c9ef"));//选中文本背景色
    ui->sciEditor->setSelectionForegroundColor(Qt::gray);//选中文本前景色

    //It is ignored if an indicator is being used. The default is blue.
    ui->sciEditor->setUnmatchedBraceForegroundColor(Qt::blue);


    ui->sciEditor->setBraceMatching(QsciScintilla::SloppyBraceMatch);

    //设置左侧行号栏宽度等
    QFontMetrics fontmetrics(font);
    ui->sciEditor->setMarginWidth(0, fontmetrics.horizontalAdvance("0000"));
    ui->sciEditor->setMarginLineNumbers(0, true);
    ui->sciEditor->setBraceMatching(QsciScintilla::SloppyBraceMatch);//括号匹配
    ui->sciEditor->setTabWidth(4);


    ui->sciEditor->setMarginsFont(font);//设置页边字体
    ui->sciEditor->setMarginType(0,QsciScintilla::NumberMargin);//设置标号为0的页边显示行号
    //editor->setMarginMarkerMask(0,QsciScintilla::Background);//页边掩码
    //editor->setMarginSensitivity(0,true);//设置是否可以显示断点,注册通知事件，当用户点击边栏时，scintilla会通知我们
    //textEdit->setMarginsBackgroundColor(QColor("#bbfaae"));
    //    this->setMarginLineNumbers(0,true);//设置第0个边栏为行号边栏，True表示显示
    //    this->setMarginWidth(0,15);//设置0边栏宽度
    ui->sciEditor->setMarginsBackgroundColor(QColor("#43577b"));//显示行号背景颜色
    ui->sciEditor->setMarginsForegroundColor(QColor("#6ac916"));//行号颜色

    ui->sciEditor->setFolding(QsciScintilla::BoxedTreeFoldStyle);//折叠样式
    ui->sciEditor->setFoldMarginColors(QColor("#808080"),QColor("#808080"));//折叠栏颜色

    //auto complete
    //Acs[None|All|Document|APIs]
    //禁用自动补全提示功能|所有可用的资源|当前文档中出现的名称都自动补全提示|使用QsciAPIs类加入的名称都自动补全提示
    ui->sciEditor->setAutoCompletionSource(QsciScintilla::AcsAll);//自动补全。对于所有Ascii字符
    //editor->setAutoCompletionCaseSensitivity(false);//大小写敏感度，设置lexer可能会更改，不过貌似没啥效果
    ui->sciEditor->setAutoCompletionThreshold(3);//设置每输入一个字符就会出现自动补全的提示



}

Form_CodeEditor::~Form_CodeEditor()
{
    delete ui;
}


//从文件加载代码
bool Form_CodeEditor::loadForFile(QString fileName)
{
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly) == false) return false;
    this->setText(file.readAll()); //从本地加载文件
    file.close();
    return true;
}


//添加代码到编辑器
void Form_CodeEditor::setText(QString str)
{
    ui->sciEditor->setText(str);

}

//添加代码
void Form_CodeEditor::append(QString str)
{
    ui->sciEditor->append(str);
}

//获取代码内容
QString Form_CodeEditor::getText()
{
    return ui->sciEditor->text();
}
