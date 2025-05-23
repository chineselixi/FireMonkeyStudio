#include "Form_Search.h"
#include "ui_Form_Search.h"
#include "Form_ProjectManger.h"
#include "QFile"
#include "QFileInfo"
#include "QRegularExpression"
#include "../SwSystem/System_GlobalVar.h"
#include "../SwSystem/System_UtilFun.h"
#include "Form_WindowTab.h"
#include "Form_WorkSpace.h"
#include "Form_SearchList.h"

Form_Search* Form_Search::searchFormPtr = nullptr;

//创建搜索框
Form_Search *Form_Search::create(QWidget *parent)
{
    if(searchFormPtr == nullptr){
        searchFormPtr = new Form_Search(parent);
        searchFormPtr->setAttribute(Qt::WA_DeleteOnClose); //这样关闭后才能执行析构
    }
    return searchFormPtr;
}

Form_Search::Form_Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_Search)
{
    ui->setupUi(this);
    this->init();
}

Form_Search::~Form_Search()
{
    //保存历史
    if(!ui->cbFind->currentText().isEmpty()){his_search.addMsg("","",ui->cbFind->currentText(),"");}
    if(!ui->cbReplace->currentText().isEmpty()){his_replace.addMsg("","",ui->cbReplace->currentText(),"");}
    his_search.clearRepeat(); //清理重复
    his_replace.clearRepeat();
    his_search.saveHisList();   //保存历史
    his_replace.saveHisList();


    searchFormPtr = nullptr;
    delete ui;
}


//初始化工程管理器
void Form_Search::init()
{

    //扫描存在的工程
    if(Manger::workspace_projectManger){ //扫描存在的工程信息
        ui->comboBox_pro->clear();
        QVector<Form_ProjectManger::ProjectNode*> pros = Manger::workspace_projectManger->getProjectAll();
        for(Form_ProjectManger::ProjectNode* item : pros){
            ui->comboBox_pro->addItem(item->proMsg.proName);
        }
    }

    //读取搜索历史
    QString t_execRunPath = System_OS::getaApplicationDirPath_EX(); //获取程序的运行目录
    //a.setStyleSheet("QTextEdit{background-color: rgb(233, 238, 255);}");

    //加载工程历史配置文件
    his_search.Init(t_execRunPath + "/config/his_search.json",6);     //读取历史配置
    his_replace.Init(t_execRunPath + "/config/his_replace.json",6);
    his_search.clearRepeat(); //清理重复
    his_replace.clearRepeat();
    for(qsizetype i = his_search.getHisList().length(); i>0; i--){ //历史倒添加到历史信息
        ui->cbFind->addItem(his_search.getHisList()[i - 1].filePath);
    }
    for(qsizetype i = his_replace.getHisList().length(); i>0; i--){
        ui->cbReplace->addItem(his_replace.getHisList()[i - 1].filePath);
    }

}



//禁用工程选择
void Form_Search::on_rbInProject_toggled(bool checked)
{
    ui->comboBox_pro->setEnabled(checked);
}


//搜索按钮被点击
void Form_Search::on_btnQuery_clicked()
{
    //先保存所有信息
    if(Manger::workspace_winTabManger){
        Manger::workspace_winTabManger->saveAllCode(); //保存所有代码
    }

    //获取所有工程信息
    QVector<Form_ProjectManger::ProjectNode*> pros;
    QStringList suffixList;
    if(Manger::workspace_projectManger){ //扫描存在的工程信息
        pros = Manger::workspace_projectManger->getProjectAll();       //获取工程信息列表
        suffixList = Manger::workspace_projectManger->getSuffixList(); //获取后缀列表
    }


    //获取应该查找的后缀


    //传递参数
    QList<searchAttr> t_attrs;

    if(ui->rbFromCursor->isChecked()){ //搜索当前页
        QString t_path = Manger::workspace_winTabManger->getTopTabSign();
        if(QFile(t_path).exists() && this->hasSuffix(suffixList,t_path)){ //仅仅搜索当前页面
            t_attrs.append({this->getFileProName(t_path),t_path});
        }
    }
    else if(ui->rbEntireScope->isChecked()){ //全部搜索
        for(Form_ProjectManger::ProjectNode* pro:pros){
            for(Form_ProjectManger::ItemNode item : pro->itemNodes){
                if(item.type == Form_ProjectManger::ItemType::File && this->hasSuffix(suffixList,item.path)){
                    t_attrs.append({pro->proMsg.proName,item.path});
                }
            }
        }
    }
    else if(ui->rbInProject->isChecked()){ //指定工程搜索
        QString t_proName = ui->comboBox_pro->currentText();
        if(!t_proName.isEmpty()){
            for(Form_ProjectManger::ProjectNode* pro:pros){
                if(pro->proMsg.proName == t_proName){           //是当前工程才放行
                    for(Form_ProjectManger::ItemNode item : pro->itemNodes){
                        if(item.type == Form_ProjectManger::ItemType::File && this->hasSuffix(suffixList,item.path)){
                            t_attrs.append({pro->proMsg.proName,item.path});
                        }
                    }
                    break;
                }
            }
        }
    }

    //开始查询
    QList<searchMsg> t_ret = this->query(ui->cbFind->currentText(),
                t_attrs,
                ui->chkCaseSensetive,
                ui->chkWholeWord,
                ui->chkRegular);



    //显示搜索输出的dock
    if(Window::workSpace){
        Window::workSpace->showSearchListDock(); //显示搜索列表Dock
        Window::workSpace->getSearchListForm()->clearMsg(); //清理搜索列表
        for(searchMsg item : t_ret){
            Window::workSpace->getSearchListForm()->addMsg(item.LineCode, item.filePath, item.proName, item.line,item.lineIndex,item.len);
        }
    }

    this->on_btnClose_clicked();
}


//根据文件查找
QList<Form_Search::searchMsg> Form_Search::query(QString queryStr, QList<searchAttr> files, bool isCaseSensetive, bool isWholeWord, bool isRegular)
{
    QList<Form_Search::searchMsg> t_retList;
    if(!queryStr.isEmpty()){
        for(searchAttr filem : files){
            if(isRegular){ //正则表达式
                t_retList.append(this->queryReg(filem.filePath,filem.proName,queryStr));
            }
            else{ //一般搜索
                t_retList.append(this->queryIndex(filem.filePath,filem.proName,queryStr,isCaseSensetive,isWholeWord));
            }
        }
    }
    return t_retList;
}


//根据正则表达式查找
QList<Form_Search::searchMsg> Form_Search::queryReg(QString filePath, QString proName, QString regStr)
{
    QList<Form_Search::searchMsg> t_retMsg;

    QString text = System_File::readFile(filePath);
    QRegularExpression re(regStr);

    // 使用QTextStream来模拟按行读取QString，并输出行号和开始位置
    QTextStream stream(&text);
    qsizetype lineNumber = 1;
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        QRegularExpressionMatchIterator i = re.globalMatch(line);
        while (i.hasNext()) {
            QRegularExpressionMatch match = i.next();
            t_retMsg.append({line,filePath,proName,lineNumber,match.capturedStart(0),match.captured(0).length()});
        }
        lineNumber++;
    }
    return t_retMsg;
}


//根据默认文本查找
QList<Form_Search::searchMsg> Form_Search::queryIndex(QString filePath, QString proName, QString searchStr, bool isCaseSensetive, bool isWholeWord)
{
    QList<Form_Search::searchMsg> t_retMsg;
    QString text = System_File::readFile(filePath);

    TOLOW:
    bool t_isLow = false;
    QTextStream stream(&text);
    qsizetype lineNumber = 0;

    QStringList searChars = searchStr.split(" ");

    //判断是否为全字符匹配
    if(isWholeWord){
        searChars = searchStr.split(" ");
    }
    else{
        searChars.append(searchStr);
    }

    //根据分割的字符来搜索
    for(QString searchChar : searChars){
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            qsizetype t_startIndex = 0;
            while(t_startIndex != -1){
                t_startIndex = line.indexOf(searchChar,t_startIndex);
                if(t_startIndex == -1) break;
                t_retMsg.append({
                                 line,
                                 filePath,
                                 proName,
                                 lineNumber,
                                 searchStr.length()});
                t_startIndex++;
            }
            lineNumber++;
        }
    }

    //如果不是小写，则转换为小写后再试
    if(t_isLow == false && isCaseSensetive){
        t_isLow = true;
        QString t_nStr = text;
        text = text.toLower();
        if(t_nStr != text){     //小写后如果相同，则不再搜索
            goto TOLOW;
        }
    }


    return t_retMsg;
}



//获取文件的工程名
QString Form_Search::getFileProName(QString filePath)
{
    if(Manger::workspace_projectManger == nullptr){ //扫描存在的工程信息
        return "";
    }
    return Manger::workspace_projectManger->getFileProName(filePath);
}


//检查是否拥有此后缀
bool Form_Search::hasSuffix(QStringList suffixList, QString filePath)
{
    for(QString item : suffixList){
        if(filePath.right(item.length() + 1) == "." + item){
            return true;
        }
    }
    return false;
}


//退出被点击
void Form_Search::on_btnClose_clicked()
{
    this->close();
}


//查找并替换
void Form_Search::on_btnReplace_clicked()
{

}

