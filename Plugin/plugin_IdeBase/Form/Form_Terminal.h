#ifndef FORM_TERMINAL_H
#define FORM_TERMINAL_H

#include <QWidget>
#include "QProcess"
#include "util/InputList.h"

#define HISRORYLEN 30


namespace Ui {
class Form_Terminal;
}

class Form_Terminal : public QWidget
{
    Q_OBJECT

public:
    enum OSType{
        WINDOWS,
        MACOS,
        LINUX,
        NON
    }runOsType = NON;

public:
    explicit Form_Terminal(QWidget *parent = nullptr);
    explicit Form_Terminal(QString runPath,QWidget *parent = nullptr);
    ~Form_Terminal();

private slots:
    void on_textEdit_textChanged(); //文本改变
    void on_btn_start_clicked();    //开始按钮被按下
    void on_btn_kill_clicked();     //停止按钮被按下

private:
    Ui::Form_Terminal *ui;
    QProcess* process;
    QString lastStr; //上一行的文本
    QString newStr; //新输入的文本
    QString lastHtml; //上一次的Html

    QString execPath; //运行路径

    //历史容器
    InputList inputLsit;

    //外部调用的消息记录
    QString runCommand;

public:
    bool runProcess(QString command);     //运行命令
    bool isRunning();                     //检测终端是否有程序正在运行
    void killProcess();                   //结束程序
    QString getRunCommand();              //获取外部调用命令行

private:

    void init(QString runPath = "");    //初始化基本设置
    void initOsType();                  //初始化操作系统类型

    QString getRunPath();               //获取运行路径
    QString delStrDouble(QString str,QString oneChar);  //去除字符串中出现的双连字符，类似于将  // 替换为 /
    QString parsePath(QString pathStr, QString runPath); //解析一个跳转的路径


    void printNomal(QString str);       //打印默认字符
    void printError(QString str);       //打印错误字符
    void normalLoad(int type = 0,QString startStr = "");    //默认加载,类型 -1为清屏加载，0为正常加载，1为错误加载。  开始文本 空为默认

    bool onKeyDown(QKeyEvent *e);                       //按钮被按下（返回true，则允许触发）
    bool onInputMethodEvent(QInputMethodEvent *e);      //数入发事件触发（返回true，则允许触发）
    void onStreamIput(QString inputStr);                //控制台新命令输入

private:
    void readyReadStandardOutput();     //状态输出
    void readyReadStandardError();      //错误输出

    void errorOccurred(QProcess::ProcessError error);       //出现错误
    void stateChanged(QProcess::ProcessState state);        //程序状态改变
    void finished(int exitCode, QProcess::ExitStatus exitStatus = QProcess::NormalExit);    //程序执行完毕
};

#endif // FORM_TERMINAL_H
