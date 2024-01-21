#ifndef FORM_CODEEDITOR_H
#define FORM_CODEEDITOR_H

#include <QWidget>
#include "QTimer"


namespace Ui {
class Form_CodeEditor;
}

class Form_CodeEditor : public QWidget
{
    Q_OBJECT

private:
    Ui::Form_CodeEditor *ui;

    QVector<int> debugsSign; //调试标记
    QString nowOpenFilePath; //当前打开的文件路径
    QTimer saveTimer;

private:
    void intiCodeEditor(); //初始化代码编辑器


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


};

#endif // FORM_CODEEDITOR_H
