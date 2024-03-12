#include "Form_CodeEditor.h"
#include "ui_Form_CodeEditor.h"
#include "QFile"
#include "../../../IDE/SwSystem/System_UtilFun.h"
#include "../../QScintilla/src/Qsci/qscilexercpp.h"
#include "../../../IDE/SwSystem/System_UtilFun.h"
//#include "../Plugin_CppBase.h"

Form_CodeEditor::Form_CodeEditor(Plugin_Base* plg,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_CodeEditor),
    cppPlgPtr(plg)
{
    ui->setupUi(this);
    this->intiCodeEditor(); //初始化代码编辑器

    //绑定Timer
    connect(&saveTimer,&QTimer::timeout,this,&Form_CodeEditor::event_timer_textChanged);
}

Form_CodeEditor::~Form_CodeEditor()
{
    //保存信息
    this->event_timer_textChanged();
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



//    //创建标记线条索引
    signLineIndex_squiggle = ui->sciEditor->indicatorDefine(QsciScintilla::IndicatorStyle::SquigglePixmapIndicator); //定义波浪指示器
    signLineIndex_straight = ui->sciEditor->indicatorDefine(QsciScintilla::IndicatorStyle::PlainIndicator); //定义直线指示器

//    //全局字体效果
//    QFont font("Consolas", 12, QFont::Normal);

//    //高亮解析器
//    QsciLexer *textLexer = new QsciLexerCPP;
//    textLexer->setFont(font);
//    textLexer->setColor(QColor("#008000"),QsciLexerCPP::Comment); //备注颜色
//    textLexer->setColor(QColor("#ff0000"),QsciLexerCPP::Number); //数字颜色
//    textLexer->setColor(QColor("#008000"),QsciLexerCPP::CommentLineDoc); //行备注颜色
//    textLexer->setColor(QColor("#008000"),QsciLexerCPP::DoubleQuotedString); //双引号字符串颜色
//    textLexer->setColor(QColor("#ff00ff"),QsciLexerCPP::SingleQuotedString); //单引号字符串颜色
//    textLexer->setColor(QColor("#003bba"),QsciLexerCPP::Keyword); //关键字颜色
//    textLexer->setColor(QColor("#dbab00"),QsciLexerCPP::KeywordSet2); //第二套关键字
//    textLexer->setColor(QColor("#0041c4"),QsciLexerCPP::PreProcessor); //预处理器颜色
//    textLexer->setColor(QColor("#a1edaa"),QsciLexerCPP::VerbatimString); //未闭合的字符串
//    textLexer->setColor(QColor("#0066d6"),QsciLexerCPP::Regex); //正则表达式



//    ui->sciEditor->setLexer(textLexer);//给QsciScintilla设置词法分析器

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
    //ui->sciEditor->setCaretForegroundColor(Qt::darkCyan);  //光标颜色
    ui->sciEditor->setCaretLineVisible(true); //是否高亮显示光标所在行
    //ui->sciEditor->setCaretLineBackgroundColor(QColor("#e0e0e0"));//光标所在行背景颜色

    //选择区块的颜色
    //ui->sciEditor->setSelectionBackgroundColor(QColor("#99c9ef"));//选中文本背景色
    //ui->sciEditor->setSelectionForegroundColor(Qt::gray);//选中文本前景色

    //如果正在使用指示器，则会忽略它。默认值为蓝色。
    //ui->sciEditor->setUnmatchedBraceForegroundColor(Qt::red); //设置不匹配的大括号前景颜色
    ui->sciEditor->setBraceMatching(QsciScintilla::SloppyBraceMatch);//括号匹配
    ui->sciEditor->setIndentationsUseTabs(false); //使用空格，而不是tab占位符
    ui->sciEditor->setTabWidth(4);

    //自动填充
    //Acs[None|All|Document|APIs]
    //禁用自动补全提示功能|所有可用的资源|当前文档中出现的名称都自动补全提示|使用QsciAPIs类加入的名称都自动补全提示
    ui->sciEditor->setAutoCompletionSource(QsciScintilla::AcsAll);//自动补全。对于所有Ascii字符
    //editor->setAutoCompletionCaseSensitivity(false);//大小写敏感度，设置lexer可能会更改，不过貌似没啥效果
    ui->sciEditor->setAutoCompletionThreshold(1);//设置每输入一个字符就会出现自动补全的提示



    //0边栏，行号
//    QFontMetrics fontmetrics(font);
//    ui->sciEditor->setMarginWidth(0, fontmetrics.horizontalAdvance("0000"));
    ui->sciEditor->setMarginLineNumbers(0, true);
    //ui->sciEditor->setMarginsFont(font);//设置页边字体
    ui->sciEditor->setMarginType(0,QsciScintilla::NumberMargin);//设置标号为0的页边显示行号
    //ui->sciEditor->setMarginsBackgroundColor(QColor("#43577b"));//显示行号背景颜色
    //ui->sciEditor->setMarginsForegroundColor(QColor("#6ac916"));//行号颜色


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
    //ui->sciEditor->setFoldMarginColors(QColor("#F0F0F0"),QColor("#F0F0F0"));//折叠栏颜色，默认#808080
    ui->sciEditor->setFolding(QsciScintilla::FoldStyle::BoxedTreeFoldStyle,3); //设置为折叠栏

    //注册标记
    QImage t_sign_error = QImage(":/editorSign/resources/editorSign/error.png");
    QImage t_sign_warning = QImage(":/editorSign/resources/editorSign/warning.png");
    QImage t_sign_ok = QImage(":/editorSign/resources/editorSign/ok.png");
    QImage t_sign_rightArrow = QImage(":/editorSign/resources/editorSign/arrow.png");


    ui->sciEditor->markerDefine(QsciScintilla::MarkerSymbol::Circle,0); //定义0号为断点标记
    //ui->sciEditor->SendScintilla(QsciScintilla::SCI_MARKERSETBACK, 0,QColor(Qt::red)); //断点标记背景色为红色
    ui->sciEditor->markerDefine(t_sign_rightArrow,1); //定义1号为右箭头标记
    ui->sciEditor->markerDefine(t_sign_error,2); //定义2号为错误标记
    ui->sciEditor->markerDefine(t_sign_warning,3); //定义3号为警告标记
    ui->sciEditor->markerDefine(t_sign_ok,4); //定义4号为正确标记



    //设置边缘能够显示的标记                                         正确  警告  错误  右箭  断点
    ui->sciEditor->setMarginMarkerMask(1,0b00001); //1号为断点边距     0    0     0    0    1
    ui->sciEditor->setMarginMarkerMask(2,0b11110); //2号为提示边距     1    1     1    1    0

}



//设置主题颜色
void Form_CodeEditor::setCodeEditorThemeColor(
        QString fontName,                       //字体名称
        QColor Normal,                          //默认文本颜色
        QColor Paper,                           //整个编辑器背景颜色
        QColor Comment,                         //备注颜色
        QColor Number,                          //数字颜色
        QColor DoubleQuotedString,              //双引号字符串颜色
        QColor SingleQuotedString,              //单引号字符串颜色
        QColor Keyword,                         //关键字颜色
        QColor KeywordSet2,                     //第二套关键字
        QColor PreProcessor,                    //预处理器颜色
        QColor VerbatimString,                  //未闭合的字符串
        QColor Regex,                           //正则表达式
        QColor CaretForeground,                 //光标前景色
        QColor CaretLineBackground,             //光标行背景色
        QColor SelectionBackground,             //选中文本背景色
        QColor SelectionForeground,             //选中文本前景色
        QColor UnmatchedBraceForeground,        //设置不匹配的大括号前景颜色
        QColor MarginsBackground,               //显示行号背景颜色
        QColor MarginsForeground,               //行号颜色
        QColor FoldMarginFore,                  //折叠栏前景色，默认#808080
        QColor FoldMarginBack,                  //折叠栏背景色，默认#808080
        QColor Breakpoint                       //断点标记背景色为红色
    )
{
    //全局字体效果
    QFont font(fontName, 12, QFont::Normal);
    ui->sciEditor->setMarginsFont(font);//设置页边字体
    QFontMetrics fontmetrics(font);
    ui->sciEditor->setMarginWidth(0, fontmetrics.horizontalAdvance("0000"));

    //高亮解析器
    QsciLexer *textLexer = new QsciLexerCPP;
    textLexer->setFont(font);

    textLexer->setColor(Normal);
    textLexer->setPaper(Paper);         //文本背景颜色
    textLexer->setDefaultPaper(Paper);  //编辑器背景颜色
    textLexer->setColor(Comment,QsciLexerCPP::Comment); //备注颜色
    textLexer->setColor(Comment,QsciLexerCPP::InactiveComment); //备注颜色
    textLexer->setColor(Comment,QsciLexerCPP::CommentLine); //备注颜色
    textLexer->setColor(Comment,QsciLexerCPP::InactiveCommentLine); //备注颜色
    textLexer->setColor(Comment,QsciLexerCPP::CommentDoc); //备注颜色
    textLexer->setColor(Comment,QsciLexerCPP::InactiveCommentDoc); //备注颜色
    textLexer->setColor(Comment,QsciLexerCPP::CommentLineDoc); //备注颜色
    textLexer->setColor(Comment,QsciLexerCPP::InactiveCommentLineDoc); //备注颜色
    textLexer->setColor(Number,QsciLexerCPP::Number); //数字颜色
    textLexer->setColor(DoubleQuotedString,QsciLexerCPP::DoubleQuotedString); //双引号字符串颜色
    textLexer->setColor(SingleQuotedString,QsciLexerCPP::SingleQuotedString); //单引号字符串颜色
    textLexer->setColor(Keyword,QsciLexerCPP::Keyword); //关键字颜色
    textLexer->setColor(KeywordSet2,QsciLexerCPP::KeywordSet2); //第二套关键字
    textLexer->setColor(PreProcessor,QsciLexerCPP::PreProcessor); //预处理器颜色
    textLexer->setColor(VerbatimString,QsciLexerCPP::VerbatimString); //未闭合的字符串
    textLexer->setColor(Regex,QsciLexerCPP::Regex); //正则表达式
    ui->sciEditor->setLexer(textLexer);//给QsciScintilla设置词法分析器

    ui->sciEditor->setCaretForegroundColor(CaretForeground);  //光标颜色
    ui->sciEditor->setCaretLineBackgroundColor(CaretLineBackground);//光标所在行背景颜色
    ui->sciEditor->setSelectionBackgroundColor(SelectionBackground);//选中文本背景色
    ui->sciEditor->setSelectionForegroundColor(SelectionForeground);//选中文本前景色
    ui->sciEditor->setUnmatchedBraceForegroundColor(UnmatchedBraceForeground); //设置不匹配的大括号前景颜色
    ui->sciEditor->setMarginsBackgroundColor(MarginsBackground);//显示行号背景颜色
    ui->sciEditor->setMarginsForegroundColor(MarginsForeground);//行号颜色
    ui->sciEditor->setFoldMarginColors(FoldMarginFore,FoldMarginBack);//折叠栏颜色，默认#808080
    ui->sciEditor->SendScintilla(QsciScintilla::SCI_MARKERSETBACK, 0,Breakpoint); //断点标记背景色为红色

}



//从文件加载代码
bool Form_CodeEditor::loadForFile(QString fileName)
{
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly) == false) return false;
    this->setText(file.readAll()); //从本地加载文件
    file.close();
    this->nowOpenFilePath = fileName; //保存当前打开的文件名
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
void Form_CodeEditor::addMarginSign(uint16_t line, int markerNumber)
{
    ui->sciEditor->markerAdd(line,markerNumber);

}

//删除所有标记，-1为全部标记，1为右箭头  2错误标记  3警告标记  4正确标记
void Form_CodeEditor::delMarginAllSign(int markerNumber)
{
    if(markerNumber == -1 || markerNumber == 0){
        debugsSign.clear(); //删除所有调试标记记录
    }
    ui->sciEditor->markerDeleteAll(markerNumber);
}


//添加波浪线
void Form_CodeEditor::addLineSquiggle(uint16_t line, uint16_t startPos, uint16_t endPos, QColor color)
{
    ui->sciEditor->setIndicatorForegroundColor(color,signLineIndex_squiggle);   //设置指示器颜色
    ui->sciEditor->setIndicatorDrawUnder(false,signLineIndex_squiggle);
    ui->sciEditor->fillIndicatorRange(line,startPos,line,endPos,signLineIndex_squiggle); //设置指示器范围
}


//添加笔直线条
void Form_CodeEditor::addLineStraight(uint16_t line, uint16_t startPos, uint16_t endPos, QColor color)
{
    ui->sciEditor->setIndicatorForegroundColor(color,signLineIndex_straight);   //设置指示器颜色
    ui->sciEditor->setIndicatorDrawUnder(false,signLineIndex_straight);
    ui->sciEditor->fillIndicatorRange(line,startPos,line,endPos,signLineIndex_straight); //设置指示器范围
}


//删除所有标记
void Form_CodeEditor::delAllLineSign()
{
    ui->sciEditor->clearIndicatorRange(0,0,ui->sciEditor->lines(),0,signLineIndex_squiggle);
    ui->sciEditor->clearIndicatorRange(0,0,ui->sciEditor->lines(),0,signLineIndex_straight);
}


//选择标记文本
void Form_CodeEditor::selectCodeText(uint16_t line, uint16_t lineIndex, uint16_t len)
{
    ui->sciEditor->setSelection(line,lineIndex,line,lineIndex + len);
}



//事件：文本发生改变
void Form_CodeEditor::event_textChanged()
{
    //三秒自动保存
    this->saveTimer.stop();
    this->saveTimer.start(UPDATETIME);
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
    if(margin == 1 || margin == 2){
        this->setDebugSign(line,true,true);
    }
}


//事件：缩放被改变
void Form_CodeEditor::event_zoomChanged()
{
    //qDebug() << ui->sciEditor->SendScintilla(QsciScintillaBase::SCI_GETZOOM); //获取缩放级别
}


//定时器文件被改变
void Form_CodeEditor::event_timer_textChanged()
{
    this->saveTimer.stop();
    System_File::writeFile(this->getSavePath(),ui->sciEditor->text().toUtf8());
    this->onTimeOut(); //激发外部定时器消息
}


//保存文件
void Form_CodeEditor::onSave()
{
    this->event_timer_textChanged();
}


//主题已经改变(主题标记)
void Form_CodeEditor::onThemeChange(QString themeSign)
{
    if(themeSign == "White"){
        this->setCodeEditorThemeColor(
            "Consolas",                 //字体名称
            QColor("#080000"),          //默认颜色
            QColor("#ffffff"),          //文本区域和编辑器默认颜色
            QColor("#008000"),          //备注颜色
            QColor("#ff0000"),          //数字颜色
            QColor("#008000"),          //双引号字符串颜色
            QColor("#ff00ff"),          //单引号字符串颜色
            QColor("#0000ff"),          //关键字颜色
            QColor("#dbab00"),          //第二套关键字
            QColor("#0041c4"),          //预处理器颜色
            QColor("#a1edaa"),          //未闭合的字符串
            QColor("#0066d6"),          //正则表达式
            Qt::darkCyan,               //光标前景色
            QColor("#e0e0e0"),          //光标行背景色
            QColor("#99c9ef"),          //选中文本背景色
            Qt::gray,                   //选中文本前景色
            Qt::red,                    //设置不匹配的大括号前景颜色
            QColor("#e6e7e8"),          //显示行号背景颜色
            QColor("#7b829d"),          //行号颜色
            QColor("#ffffff"),          //折叠栏前景色，默认#808080
            QColor("#ffffff"),          //折叠栏背景色，默认#808080
            QColor(Qt::red)             //断点标记背景色为红色
            );
    }
    else if(themeSign == "Dark"){
        this->setCodeEditorThemeColor(
            "Consolas",                 //字体名称
            QColor("#dccca6"),          //默认颜色
            QColor("#262626"),          //文本区域和编辑器默认颜色
            QColor("#348546"),          //备注颜色
            QColor("#b5ce9a"),          //数字颜色
            QColor("#d69d85"),          //双引号字符串颜色
            QColor("#d69d85"),          //单引号字符串颜色
            QColor("#2a6ac3"),          //关键字颜色
            QColor("#d6a0df"),          //第二套关键字
            QColor("#bcbcba"),          //预处理器颜色
            QColor("#d69d85"),          //未闭合的字符串
            QColor("#0066d6"),          //正则表达式
            QColor("#a4b4aa"),          //光标前景色
            QColor("#1d545c"),          //光标行背景色
            QColor("#264f78"),          //选中文本背景色
            Qt::gray,                   //选中文本前景色
            Qt::red,                    //设置不匹配的大括号前景颜色
            QColor("#1e1e1e"),          //显示行号背景颜色
            QColor("#8a8775"),          //行号颜色
            QColor("#1e1e1e"),          //折叠栏前景色，默认#808080
            QColor("#1e1e1e"),          //折叠栏背景色，默认#808080
            QColor(Qt::red)             //断点标记背景色为红色
            );
    }
    else{   //Blue
        this->setCodeEditorThemeColor(
            "Consolas",                 //字体名称
            QColor("#080000"),          //默认颜色
            QColor("#fafafa"),          //文本区域和编辑器默认颜色
            QColor("#008000"),          //备注颜色
            QColor("#ff0000"),          //数字颜色
            QColor("#008000"),          //双引号字符串颜色
            QColor("#ff00ff"),          //单引号字符串颜色
            QColor("#003bba"),          //关键字颜色
            QColor("#dbab00"),          //第二套关键字
            QColor("#0041c4"),          //预处理器颜色
            QColor("#a1edaa"),          //未闭合的字符串
            QColor("#0066d6"),          //正则表达式
            Qt::darkCyan,               //光标前景色
            QColor("#e0e0e0"),          //光标行背景色
            QColor("#99c9ef"),          //选中文本背景色
            Qt::gray,                   //选中文本前景色
            Qt::red,                    //设置不匹配的大括号前景颜色
            QColor("#43577b"),          //显示行号背景颜色
            QColor("#6ac916"),          //行号颜色
            QColor("#F0F0F0"),          //折叠栏前景色，默认#808080
            QColor("#F0F0F0"),          //折叠栏背景色，默认#808080
            QColor(Qt::red)             //断点标记背景色为红色
            );
    }
}


//获取编辑器内的代码
QString Form_CodeEditor::getCodeText()
{
    return ui->sciEditor->text();
}


//获取文件保存的路径
QString Form_CodeEditor::getSavePath()
{
    return nowOpenFilePath;
}

//获取火花代码编辑器指针
QsciScintilla *Form_CodeEditor::getSciCodeEditor()
{
    return ui->sciEditor;
}


//文件被保存事件
void Form_CodeEditor::event_onFilePathChanged(QString newFilePath)
{
    this->nowOpenFilePath = newFilePath;
}

