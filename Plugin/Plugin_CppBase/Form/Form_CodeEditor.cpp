#include "Form_CodeEditor.h"
#include "ui_Form_CodeEditor.h"
#include "QFile"
#include "../../QScintilla/src/Qsci/qscilexercpp.h"





Form_CodeEditor::Form_CodeEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_CodeEditor)
{
    ui->setupUi(this);
    this->intiCodeEditor(); //初始化代码编辑器
}

Form_CodeEditor::~Form_CodeEditor()
{
    delete ui;
}


//初始化代码编辑器
void Form_CodeEditor::intiCodeEditor()
{
    //事件链接
    connect(ui->sciEditor, SIGNAL(customContextMenuRequested(const QPoint&)),this,SLOT(event_customContextMenuRequested(const QPoint&)));//弹出上下文菜单
    connect(ui->sciEditor, SIGNAL(textChanged()),this, SLOT(event_textChanged()));//文本改变
    connect(ui->sciEditor, SIGNAL(cursorPositionChanged(int,int)),this, SLOT(event_cursorPositionChanged(int,int))); //光标位置改变
    connect(ui->sciEditor, SIGNAL(marginClicked(int,int,Qt::KeyboardModifiers)),this, SLOT(event_marginClicked(int,int,Qt::KeyboardModifiers)));//边缘被点击
    connect(ui->sciEditor, SIGNAL(SCN_ZOOM()),this, SLOT(event_zoomChanged()));//缩放改变

    //全局字体效果
    QFont font("Consolas", 12, QFont::Normal);

    //高亮解析器
    QsciLexer *textLexer = new QsciLexerCPP;
    textLexer->setFont(font);
    textLexer->setColor(QColor("#008000"),QsciLexerCPP::Comment); //备注颜色
    textLexer->setColor(QColor("#ff0000"),QsciLexerCPP::Number); //数字颜色
    textLexer->setColor(QColor("#008000"),QsciLexerCPP::CommentLineDoc); //行备注颜色
    textLexer->setColor(QColor("#008000"),QsciLexerCPP::DoubleQuotedString); //双引号字符串颜色
    textLexer->setColor(QColor("#ff00ff"),QsciLexerCPP::SingleQuotedString); //单引号字符串颜色
    textLexer->setColor(QColor("#003bba"),QsciLexerCPP::Keyword); //关键字颜色
    textLexer->setColor(QColor("#0041c4"),QsciLexerCPP::PreProcessor); //预处理器颜色
    textLexer->setColor(QColor("#a1edaa"),QsciLexerCPP::VerbatimString); //未闭合的字符串
    textLexer->setColor(QColor("#0066d6"),QsciLexerCPP::Regex); //正则表达式
    textLexer->setColor(QColor("#dbab00"),QsciLexerCPP::KeywordSet2); //第二套关键字


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

    //启用或禁用缩进辅助线的显示。
    ui->sciEditor->setIndentationGuides(true);

    //当前光标线条颜色
    ui->sciEditor->setCaretWidth(2);//光标宽度，0表示不显示光标
    ui->sciEditor->setCaretForegroundColor(Qt::darkCyan);  //光标颜色
    ui->sciEditor->setCaretLineVisible(true); //是否高亮显示光标所在行
    ui->sciEditor->setCaretLineBackgroundColor(QColor("#e0e0e0"));//光标所在行背景颜色

    //选择区块的颜色
    ui->sciEditor->setSelectionBackgroundColor(QColor("#99c9ef"));//选中文本背景色
    ui->sciEditor->setSelectionForegroundColor(Qt::gray);//选中文本前景色

    //如果正在使用指示器，则会忽略它。默认值为蓝色。
    ui->sciEditor->setUnmatchedBraceForegroundColor(Qt::red); //设置不匹配的大括号前景颜色
    ui->sciEditor->setBraceMatching(QsciScintilla::SloppyBraceMatch);//括号匹配
    ui->sciEditor->setTabWidth(4);


    //自动填充
    //Acs[None|All|Document|APIs]
    //禁用自动补全提示功能|所有可用的资源|当前文档中出现的名称都自动补全提示|使用QsciAPIs类加入的名称都自动补全提示
    ui->sciEditor->setAutoCompletionSource(QsciScintilla::AcsAll);//自动补全。对于所有Ascii字符
    //editor->setAutoCompletionCaseSensitivity(false);//大小写敏感度，设置lexer可能会更改，不过貌似没啥效果
    ui->sciEditor->setAutoCompletionThreshold(1);//设置每输入一个字符就会出现自动补全的提示



    //0边栏，行号
    QFontMetrics fontmetrics(font);
    ui->sciEditor->setMarginWidth(0, fontmetrics.horizontalAdvance("0000"));
    ui->sciEditor->setMarginLineNumbers(0, true);
    ui->sciEditor->setMarginsFont(font);//设置页边字体
    ui->sciEditor->setMarginType(0,QsciScintilla::NumberMargin);//设置标号为0的页边显示行号
    ui->sciEditor->setMarginsBackgroundColor(QColor("#43577b"));//显示行号背景颜色
    ui->sciEditor->setMarginsForegroundColor(QColor("#6ac916"));//行号颜色


    //1边栏，断点操作
    ui->sciEditor->setMarginType(1,QsciScintilla::SymbolMargin);
    ui->sciEditor->setMarginWidth(1,20);
    ui->sciEditor->setMarginSensitivity(1,true); //设置断点区域可被点击

    //2边栏，运行与提示
    ui->sciEditor->setMarginType(2,QsciScintilla::SymbolMargin);
    ui->sciEditor->setMarginWidth(2,20);
    ui->sciEditor->setMarginSensitivity(2,true); //设置提示区域可被点击，但是由断点效果处理

    //3边栏，代码折叠
    ui->sciEditor->setMarginType(3,QsciScintilla::SymbolMargin);
    ui->sciEditor->setMarginWidth(3,15);
    ui->sciEditor->setFoldMarginColors(QColor("#F0F0F0"),QColor("#F0F0F0"));//折叠栏颜色，默认#808080
    ui->sciEditor->setFolding(QsciScintilla::FoldStyle::BoxedTreeFoldStyle,3); //设置为折叠栏





    //注册标记
    QImage t_sign_error = QImage(":/editorSign/resources/editorSign/error.png");
    QImage t_sign_warning = QImage(":/editorSign/resources/editorSign/warning.png");
    QImage t_sign_ok = QImage(":/editorSign/resources/editorSign/ok.png");
    QImage t_sign_rightArrow = QImage(":/editorSign/resources/editorSign/arrow.png");


    ui->sciEditor->markerDefine(QsciScintilla::MarkerSymbol::Circle,0); //定义0号为断点标记
    ui->sciEditor->SendScintilla(QsciScintilla::SCI_MARKERSETBACK, 0,QColor(Qt::red)); //断点标记背景色为红色
    ui->sciEditor->markerDefine(t_sign_rightArrow,1); //定义1号为右箭头标记
    ui->sciEditor->markerDefine(t_sign_error,2); //定义2号为错误标记
    ui->sciEditor->markerDefine(t_sign_warning,3); //定义3号为警告标记
    ui->sciEditor->markerDefine(t_sign_ok,4); //定义4号为正确标记



    //设置边缘能够显示的标记                                         正确  警告  错误  右箭  断点
    ui->sciEditor->setMarginMarkerMask(1,0b00001); //1号为断点边距     0    0     0    0    1
    ui->sciEditor->setMarginMarkerMask(2,0b11110); //2号为提示边距     1    1     1    1    0

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


//设置调试标记
void Form_CodeEditor:: setDebugSign(uint16_t line, bool sign,bool checked)
{
    int mhandle,index;
    this->getDebugSign(line,mhandle,index);

    if(checked){
        sign = (index == -1?true:false);
    }

    if(sign){
        if(index == -1){
            int mh = ui->sciEditor->markerAdd(line,0); //添加sign标记
            this->debugsSign.append(mh); //添加行号句柄标记
        }
    }
    else{
        if(index != -1){
            //this->debugsSign.removeAt(signNum);
            ui->sciEditor->markerDeleteHandle(mhandle);
            if(index >= 0 && index < this->debugsSign.length()) this->debugsSign.remove(index);
        }
    }
}


//获取是否调试标记
void Form_CodeEditor::getDebugSign(uint16_t line,int& mhandle,int& index)
{
    for(int i = 0; i < this->debugsSign.length(); i++){
        if(ui->sciEditor->markerLine(this->debugsSign[i]) == line){
            mhandle = this->debugsSign[i];
            index = i;
            return;
        }
    }
    index = -1;
}


//添加标记，1为右箭头  2错误标记  3警告标记  4正确标记
void Form_CodeEditor::addSign(uint16_t line, int markerNumber)
{
    ui->sciEditor->markerAdd(line,markerNumber);
}

//删除所有标记，-1为全部标记，1为右箭头  2错误标记  3警告标记  4正确标记
void Form_CodeEditor::deleteAllSign(int markerNumber)
{
    if(markerNumber == -1 || markerNumber == 0){
        debugsSign.clear(); //删除所有调试标记记录
    }
    ui->sciEditor->markerDeleteAll(markerNumber);
}



//事件：文本发生改变
void Form_CodeEditor::event_textChanged()
{

}

//事件：光标位置发生改变
void Form_CodeEditor::event_cursorPositionChanged(int line, int index)
{

}

//事件：上下文菜单被请求
void Form_CodeEditor::event_customContextMenuRequested(const QPoint &pos)
{

}

//事件：边缘标记区域被点击
void Form_CodeEditor::event_marginClicked(int margin, int line, Qt::KeyboardModifiers state)
{
    qDebug() << "margin:" << margin << " line:" << line;
    if(margin == 1 || margin == 2){
        this->setDebugSign(line,true,true);
        this->addSign(line,1);
    }
}


//事件：缩放被改变
void Form_CodeEditor::event_zoomChanged()
{
    //qDebug() << ui->sciEditor->SendScintilla(QsciScintillaBase::SCI_GETZOOM); //获取缩放级别
}
