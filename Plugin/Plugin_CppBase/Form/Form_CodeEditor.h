#ifndef FORM_CODEEDITOR_H
#define FORM_CODEEDITOR_H

#include "../../../IDE/Plugin/Plugin_CodeEditorInterface.h"
#include <QWidget>
#include "QTimer"


namespace Ui {
class Form_CodeEditor;
}

class Form_CodeEditor : public QWidget,public Plugin_CodeEditorInterface
{
    Q_OBJECT

private:
    Ui::Form_CodeEditor *ui;

    QVector<int> debugsSign; //调试标记
    QString nowOpenFilePath; //当前打开的文件路径
    QTimer saveTimer;

private:
    void intiCodeEditor();          //初始化代码编辑器
    void setCodeEditorThemeColor(   //设置主题颜色
        QString fontName,                       //字体名称
        QColor Normal,                          //默认文本颜色
        QColor Paper,                           //整个编辑器背景颜色
        QColor Comment,                         //备注颜色
        QColor Number,                          //数字颜色
        QColor CommentLineDoc,                  //行备注颜色
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
    explicit Form_CodeEditor(QWidget *parent = nullptr);
    ~Form_CodeEditor();

    bool loadForFile(QString fileName); //从文件加载代码
    void setText(QString str); //添加代码到编辑器
    void append(QString str); //添加代码
    QString getText(); //获取代码内容


    //调试标记操作
    void setDebugSign(uint16_t line,bool sign,bool checked = false); //设置调试标记,第三个参数为true则自动选择，第二个参数将无效
    void getDebugSign(uint16_t line,int& mhandle,int& index); //获取当前行是否有调试标记
    QVector<int> getDebugList(); //获取所有的调试标记

    //其它标记操作
    void addSign(uint16_t line,int markerNumber); //添加标记，1为右箭头  2错误标记  3警告标记  4正确标记
    void deleteAllSign(int markerNumber); //删除所有标记，-1为全部标记，1为右箭头  2错误标记  3警告标记  4正确标记

public slots:
    void event_textChanged(); //文本发生改变
    void event_cursorPositionChanged(int line, int index); //光标位置发生改变
    void event_customContextMenuRequested(const QPoint &pos); //上下文菜单被请求
    void event_marginClicked(int margin, int line, Qt::KeyboardModifiers state); //边缘标记区域被点击
    void event_zoomChanged(); //缩放被改变

    //定时器事件
    void event_timer_textChanged(); //定时器文件被改变


private: //复写Plugin_CodeEditorInterface事件
    void onSave() override;                             //保存文件
    void onThemeChange(QString themeSign) override;     //主题已经改变(主题标记)
    QString getCodeText() override;                     //获取编辑器内的代码
    QString getSavePath() override;                     //获取文件保存的路径
    QsciScintilla* getSciCodeEditor() override;         //获取火花代码编辑器指针

};

#endif // FORM_CODEEDITOR_H
