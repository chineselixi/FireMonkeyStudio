#include "Form_Terminal.h"
#include "ui_Form_Terminal.h"


#include "QKeyEvent"
#include "QInputMethodEvent"
#include "QFileInfo"
#include "QDir"




Form_Terminal::Form_Terminal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Terminal)
{
    this->init(this->getRunPath());
}

Form_Terminal::Form_Terminal(QString runPath, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Terminal)
{
    this->init(runPath);
}

Form_Terminal::~Form_Terminal()
{
    delete ui;
    delete process;
}


//初始化基本设置
void Form_Terminal::init(QString runPath)
{
    this->initOsType(); //初始化OS类型

    ui->setupUi(this);

    //初始化基本设置
    this->execPath = runPath;

    //文本编辑器钩子信号
    connect(ui->textEdit,&Widget_TextEdit::onKeyDown,this,&Form_Terminal::onKeyDown);
    connect(ui->textEdit,&Widget_TextEdit::onInputMethodEvent,this,&Form_Terminal::onInputMethodEvent);


    //程序操作对象钩子信号
    process = new QProcess();

    process->setReadChannel(QProcess::StandardOutput);

    connect(process,SIGNAL(readyReadStandardOutput()),this, SLOT(readyReadStandardOutput()));
    connect(process,&QProcess::readyReadStandardOutput,this,&Form_Terminal::readyReadStandardOutput);
    connect(process,&QProcess::readyReadStandardError,this,&Form_Terminal::readyReadStandardError);

    connect(process,&QProcess::started,this,&Form_Terminal::start);
    connect(process,&QProcess::stateChanged,this,&Form_Terminal::stateChanged);
    connect(process,&QProcess::errorOccurred,this,&Form_Terminal::errorOccurred);
    connect(process,&QProcess::finished,this,&Form_Terminal::finished);

    //加载默认
    this->normalLoad(-1); //清理屏幕加载
}

//初始化操作系统类型
void Form_Terminal::initOsType()
{
#if defined(Q_OS_WIN)
    this->runOsType = OSType::WINDOWS;
#elif defined(Q_OS_MAC)
    this->runOsType = OSType::MACOS;
#elif defined(Q_OS_LINUX)
    this->runOsType = OSType::LINUX;
#else
    this->runOsType = OSType::NON;
#endif
}


//获取运行路径
QString Form_Terminal::getRunPath()
{
    if(this->execPath.isEmpty()){
        this->execPath = QCoreApplication::applicationDirPath();
    }
    else{
        QDir t_dir(this->execPath);
        if(!t_dir.exists()){
            this->execPath = QCoreApplication::applicationDirPath();
            return this->execPath;
        }
    }
    return execPath;
}


//去除字符串中出现的双连字符，类似于将 // 替换为 /
QString Form_Terminal::delStrDouble(QString str,QString oneChar)
{
    QString t_douStr = oneChar + oneChar;
    do{
        str.replace(t_douStr,oneChar);
    }
    while (str.indexOf(t_douStr) != -1);
    return str;
}


//解析一个跳转的路径
QString Form_Terminal::parsePath(QString pathStr, QString runPath)
{
    //去除运行目录后面的斜杠
    if(runPath.length() > 1 && runPath.right(1) == '/'){
        runPath = runPath.left(runPath.length() - 1);
    }

    //判断运行路径是否存在，不存在返回空
    if(!QDir(runPath).exists()){
        return "";
    }
    QString retPath = ""; //返回的路径

    //判断是否为绝对路径
    if(QDir(pathStr).exists() && pathStr.left(1) != '.' && (pathStr.indexOf(":") != -1 || pathStr.indexOf("/") != -1)){
        retPath = pathStr;
    }

    //如果不是绝对路径。那么整理相对路径
    if(retPath.isEmpty()){
        QStringList t_parseList = runPath.split("/"); //拆分当前运行吗，目录

        pathStr = pathStr.replace("\\","/");
        this->delStrDouble(pathStr,"/");

        QStringList t_strLsit = pathStr.split("/"); //分割文本
        for(QString pathNode : t_strLsit){
            if(pathNode == "."){
                continue;
            }
            else if(pathNode == ".."){
                t_parseList.pop_back(); //上一级，删除这一个
            }
            else{
                t_parseList.append(pathNode);
            }
        }
        retPath = t_parseList.join("/"); //融合路径

        //如果不是Windows，那么在前加入/标记
        if(this->runOsType != OSType::WINDOWS){
            retPath = "/" + retPath;
        }
    }
    retPath = this->delStrDouble(retPath,"/");

    //去除末尾的斜杠
    if(retPath.length() > 1 && retPath.right(1) == '/'){
        retPath = retPath.left(retPath.length() - 1);
    }

    if(QDir(retPath).exists()){
        return retPath;
    }
    return "";
}



//默认加载,类型 -1为清屏加载，0为正常加载，1为错误加载。  开始文本 空为默认
void Form_Terminal::normalLoad(int type,QString startStr)
{
    if(type == -1){
        ui->textEdit->setText("");
        this->lastStr = "";
        this->lastHtml = "";
    }

    if(!startStr.isEmpty()){
        if(type == 0){
            this->printNomal(startStr);
        }
        else if(type == 1){
            this->printError(startStr);
        }
    }


    QString t_terminal = "";
    switch (this->runOsType) {
    case OSType::WINDOWS:{
        //t_terminal = "cmd.exe";   //使用内置功能
        break;
    }
    case OSType::LINUX:{
        //t_terminal = "gnome-terminal"; //在Linux下执行此命令会跳出终端，默认注销，使用内置终端
        break;
    }
    case OSType::MACOS:{
        //t_terminal = "open";      //使用内置功能
        break;
    }
    default:{
        t_terminal = "";
        break;
    }
    }

    //工具不同平台，启动不同终端
    if(t_terminal.isEmpty()){
        QString t_prefix = "";

        if(!this->ui->textEdit->toPlainText().isEmpty()){
            t_prefix = "\n";
        }
        this->printNomal(t_prefix + "PS " + this->getRunPath() + ">");
    }
    else{
        this->onStreamIput(t_terminal);
    }


}




//按钮被按下（返回true，则允许触发）
bool Form_Terminal::onKeyDown(QKeyEvent *e)
{
    //如果为删除键，并且编辑器内容为上一次保存内容，则不删除
    QString t_nowStr = ui->textEdit->toPlainText();
    if(e->key() == 16777219 || e->key() == 16777223){
        if(t_nowStr == this->lastStr || ui->textEdit->textCursor().position() <= this->lastStr.length()){
            return false;
        }
    }

    //只允许在非上一次内容区域的地方输入或打印
    if(ui->textEdit->textCursor().position() <= this->lastStr.length()){
        if(e->key() == 16777234){
            return false;
        }

        if(ui->textEdit->textCursor().position() < this->lastStr.length()){
            if(e->key() < 16777234 || e->key() > 16777237){
                return false;
            }
        }
    }

    //如果使用回车按钮
    if(e->key() == 16777220){
        if(!ui->textEdit->isReadOnly()){
            this->onStreamIput(this->newStr);
            return false;
        }
    }

    //按钮上，历史上一个
    if(e->key() == 16777235){
        ui->textEdit->setHtml(this->lastHtml);
        QTextCursor tc = ui->textEdit->textCursor();
        tc.movePosition(QTextCursor::End);
        QString str = "<span style='color: orange;'>" + this->inputLsit.getLast() + "</span>";
        tc.insertHtml(str);
        tc.movePosition(QTextCursor::End);
        ui->textEdit->setTextCursor(tc);
        return false;
    }

    //按钮下，历史下一个
    if(e->key() == 16777237){
        ui->textEdit->setHtml(this->lastHtml);
        QTextCursor tc = ui->textEdit->textCursor();
        tc.movePosition(QTextCursor::End);
        QString str = "<span style='color: orange;'>" + this->inputLsit.getNext() + "</span>";
        tc.insertHtml(str);
        tc.movePosition(QTextCursor::End);
        ui->textEdit->setTextCursor(tc);
        return false;
    }

    //设置tab补全
    if(e->key() == 16777217){
        QStringList t_strList = this->newStr.split(" ");
        if(t_strList.length() == 0) return true;


        return false;
    }

    return true;
}


//数入发事件触发
bool Form_Terminal::onInputMethodEvent(QInputMethodEvent *e)
{
    if(ui->textEdit->textCursor().position() < this->lastStr.length()){
        return false;
    }
    return true;
}


//文本编辑器内容改变
void Form_Terminal::on_textEdit_textChanged()
{
    QString t_nowStr = ui->textEdit->toPlainText();

    if(t_nowStr.isEmpty()){
        return;
    }


    if(t_nowStr.length() < this->lastStr.length()){
        ui->textEdit->setText(this->lastStr);
        QTextCursor t_cursor = ui->textEdit->textCursor();
        t_cursor.setPosition(this->lastStr.length());
        ui->textEdit->setTextCursor(t_cursor);
        //ui->textEdit->textCursor().movePosition(QTextCursor::End);
        t_nowStr = this->lastStr;
    }
    this->newStr = t_nowStr.right(t_nowStr.length() - this->lastStr.length()); //新多出来的文本
    if(this->newStr.isEmpty()){
        ui->textEdit->textCursor().setPosition(ui->textEdit->toPlainText().length());
    }


}


//运行命令
bool Form_Terminal::runProcess(QString command)
{
    this->onStreamIput(command);
    this->runCommand = command;   //记录外部输入的信息
    return this->isRunning();
}

//检测终端是否有程序正在运行
bool Form_Terminal::isRunning()
{
    return this->process->state() != QProcess::ProcessState::NotRunning;
}

//结束程序
void Form_Terminal::killProcess()
{
    if(this->process){
        this->process->kill(); //强制关闭程序
        //this->finished(-1,QProcess::ExitStatus::NormalExit); //激发异常退出信号
    }
}

//获取外部调用命令行
QString Form_Terminal::getRunCommand()
{
    return this->runCommand;
}


//打印默认字符
void Form_Terminal::printNomal(QString str)
{
    ui->textEdit->setTextColor(QColor("#ababab"));
    ui->textEdit->insertPlainText(str);

    this->lastStr = ui->textEdit->toPlainText();
    this->lastHtml = ui->textEdit->toHtml();

    ui->textEdit->moveCursor(QTextCursor::End);
    this->newStr = "";
}

//打印错误字符
void Form_Terminal::printError(QString str)
{
    ui->textEdit->setTextColor(QColor("red"));
    ui->textEdit->insertPlainText(str);

    this->lastStr = ui->textEdit->toPlainText();
    this->lastHtml = ui->textEdit->toHtml();

    ui->textEdit->moveCursor(QTextCursor::End);
    this->newStr = "";
}



//控制台新命令输入
void Form_Terminal::onStreamIput(QString inputStr)
{
    switch(this->runOsType){
        case OSType::WINDOWS:{
            if(inputStr == "cls"){
                this->normalLoad(-1);return;
            }
            break;}
        case OSType::LINUX:
        case OSType::MACOS:{
            if(inputStr == "clear"){
                this->normalLoad(-1);return;
            }
            break;}
        default:{
            break;
        }
    }

    inputStr = inputStr.trimmed();
    if(inputStr.isEmpty() || inputStr == "\n"){
        this->normalLoad(0);
        return;
    }
    this->inputLsit.add(inputStr); //加入历史记录信息

    //特定字符命令截取
    if(inputStr.left(3) == "cd "){
        QString t_movPath = inputStr.right(inputStr.length() - inputStr.indexOf(" ") - 1);
        t_movPath = this->parsePath(t_movPath,this->getRunPath());
        if(t_movPath.isEmpty()){
                this->printError('\n' + tr("跳转的路径不存在！") + '\n');
                t_movPath = this->getRunPath();
        }
        this->execPath = t_movPath;
        this->normalLoad();
        return;
    }



    //运行程序或者执行命令
    this->printNomal("\n");
    if(process->state() != QProcess::Running){
        process->setWorkingDirectory(this->getRunPath());
        process->startCommand(inputStr);

        //启用控制按钮
        ui->btn_start->setEnabled(false);
        ui->btn_kill->setEnabled(true);
    }
    else{
        process->write(QString(inputStr + "\n").toUtf8());
    }
}

//程序默认信息准备就绪
void Form_Terminal::readyReadStandardOutput()
{
    QString t_outNor = QString::fromLocal8Bit(process->readAllStandardOutput());
    if(!t_outNor.isEmpty()){

        this->printNomal(t_outNor);
    }
    ui->textEdit->setReadOnly(false);
    if(process->canReadLine()){
        ui->textEdit->setReadOnly(false);
    }

}


//程序错误信息准备就绪
void Form_Terminal::readyReadStandardError()
{
    QString t_outErr =  QString::fromLocal8Bit(process->readAllStandardError());
    if(!t_outErr.isEmpty()){this->printError(t_outErr);}
    if(process->canReadLine()){
        ui->textEdit->setReadOnly(false);
    }
}


//程序启动完成
void Form_Terminal::start()
{
    this->sig_start(this->runCommand);
}


//出现错误
void Form_Terminal::errorOccurred(QProcess::ProcessError error)
{
    QString t_errorStr;
    switch (error){
    case QProcess::ProcessError::FailedToStart:{
        t_errorStr = tr("无法执行此命令，请检查命令是否合法！");
        break;
    }
    case QProcess::ProcessError::Crashed:{
        t_errorStr = tr("程序奔溃！");
        break;
    }
    case QProcess::ProcessError::Timedout:{
        t_errorStr = tr("程序运行超时！");
        break;
    }
    case QProcess::ProcessError::ReadError:{
        t_errorStr = tr("程序读取错误！");
        break;
    }
    case QProcess::ProcessError::WriteError:{
        t_errorStr = tr("程序写入错误");
        break;
    }
    default:
    case QProcess::ProcessError::UnknownError:{
        t_errorStr = tr("未知错误");
        break;
    }
    }
    //this->stateChanged(QProcess::ProcessState::NotRunning);
    this->normalLoad(1,t_errorStr + "\n");
    this->sig_error(this->runCommand,t_errorStr);
}


//程序状态改变
void Form_Terminal::stateChanged(QProcess::ProcessState state)
{
    if(state == QProcess::ProcessState::Running){           //运行状态
        ui->btn_start->setEnabled(false);
        ui->btn_kill->setEnabled(true);
    }
    else if(state == QProcess::ProcessState::NotRunning){   //停止状态
        ui->btn_start->setEnabled(true);
        ui->btn_kill->setEnabled(false);
    }
    else if(state == QProcess::ProcessState::Starting){     //启动状态
        ui->btn_start->setEnabled(false);
        ui->btn_kill->setEnabled(false);
    }
}


//程序执行完毕
void Form_Terminal::finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    QString t_out = tr("程序已经退出，退出代码为：");
    if(exitCode != 0){
        t_out = tr("程序异常退出，退出代码为：");
    }
    t_out += QString::number(exitCode);

    //输出控制消息，非0表示异常退出
    if(exitCode != 0){
        this->printError('\n' + t_out + '\n');
    }
    this->normalLoad(0);

    this->sig_finish(this->runCommand,exitCode);
}


//开始按钮被按下
void Form_Terminal::on_btn_start_clicked()
{
    QString t_comm = this->getRunCommand();
    if(!t_comm.isEmpty()){
        this->runProcess(t_comm);
    }
}


//停止按钮被按下
void Form_Terminal::on_btn_kill_clicked()
{
    this->killProcess();
}

