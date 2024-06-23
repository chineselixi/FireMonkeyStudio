#ifndef FORM_CODEEDITOR_H
#define FORM_CODEEDITOR_H

#include "../../../IDE/Plugin/Plugin_CodeEditorInterface.h"
#include <QWidget>
#include "QTimer"
#include "../../../IDE/Plugin/Plugin_Base.h"
#include "../util/LspClient.h"

#define UPDATETIME 2000
#define COMPLETION 500

namespace Ui {
class Form_CodeEditor;
}

class Form_CodeEditor : public QWidget,public Plugin_CodeEditorInterface
{
    Q_OBJECT

private:
    Ui::Form_CodeEditor *ui;

    Plugin_Base* pluginPtr = nullptr; //cpp插件指针

    QVector<int> debugsSign; //调试标记
    QString nowOpenFilePath; //当前打开的文件路径
    QTimer saveTimer;    //保存定时器
    QTimer completionTimer;     //自动补全定时器

    //标记线索引
    int signLineIndex_squiggle = -1; //波浪线
    int signLineIndex_straight = -1; //直线

    //是否为第一次设置文本(避免检查弹窗)
    bool isFirstText = true;

    //自身指针索引
    //static QList<Form_CodeEditor*> formList;

    //编辑框光标位置
    int cursorLine = 0;     //所在行
    int cursorIndex = 0;    //所在行索引
    QPoint cursorPos;       //所在的坐标

public:
    explicit Form_CodeEditor(Plugin_Base* plg,QWidget *parent = nullptr);
    ~Form_CodeEditor();

private:
    void intiCodeEditor();          //初始化代码编辑器
    void setCodeEditorThemeColor(   //设置主题颜色
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
        );



public:


    bool loadForFile(QString fileName); //从文件加载代码
    void setText(QString str); //添加代码到编辑器
    void append(QString str); //添加代码
    QString getText(); //获取代码内容


    //调试标记操作
    void setDebugSign(uint16_t line,bool sign,bool checked = false); //设置调试标记,第三个参数为true则自动选择，第二个参数将无效
    void getDebugSign(uint16_t line,int& mhandle,int& index); //获取当前行是否有调试标记
    QVector<int> getDebugList(); //获取所有的调试断点标记

    //其它标记操作
    void addMarginSign(uint16_t line,int markerNumber); //添加标记，1为右箭头  2错误标记  3警告标记  4正确标记
    void delMarginAllSign(int markerNumber); //删除所有标记，-1为全部标记，1为右箭头  2错误标记  3警告标记  4正确标记

    //设置波浪线标记
    void addLineSquiggle(uint16_t line,uint16_t startPos = 0,uint16_t endPos = 0,QColor color = QColor("#ffa200")); //添加波浪线
    void addLineStraight(uint16_t line,uint16_t startPos = 0,uint16_t endPos = 0,QColor color = QColor("#ff2700")); //添加笔直线条
    void delAllLineSign(); //删除所有标记

    //选择标记文本
    void selectCodeText(uint16_t line = 0,uint16_t lineIndex = 0,uint16_t len = 0); //选择标记文本

public:
    static QList<Form_CodeEditor*> getForms(); //静态获取所有窗口

public slots:
    void event_textChanged(); //文本发生改变
    void event_cursorPositionChanged(int line, int index); //光标位置发生改变
    void event_customContextMenuRequested(const QPoint &pos); //上下文菜单被请求
    void event_marginClicked(int margin, int line, Qt::KeyboardModifiers state); //边缘标记区域被点击
    void event_zoomChanged(); //缩放被改变

    //LSP完成事件激发
    void onCompletion(QList<LspClient::CompletionNode> completionNodes);

    //定时器事件
    void event_timer_autoSave(); //自动保存定时器事件
    void event_timer_completion();  //自动补全完成定时器事件


signals:
    void onTimeOut(); //定时器激发消息


private: //复写Plugin_CodeEditorInterface事件
    void onSave() override;                             //保存文件
    void onThemeChange(QString themeSign) override;     //主题已经改变(主题标记)
    QString getCodeText() override;                     //获取编辑器内的代码
    QsciScintilla* getSciCodeEditor() override;         //获取火花代码编辑器指针
public:
    QString getSavePath() override;                     //获取文件保存的路径

private:
    void event_onFilePathChanged(QString newFilePath) override;         //文件被保存事件




};

#endif // FORM_CODEEDITOR_H
