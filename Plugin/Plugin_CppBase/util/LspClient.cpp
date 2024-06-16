#include "LspClient.h"

#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"


LspClient::LspClient(QString clangdPath,QString language)
{
    this->langSign = language;
    this->isRun = false;
    process = new QProcess;
    connect(process,&QProcess::readyReadStandardError,this,&LspClient::onErrorPrint);
    connect(process,&QProcess::readyReadStandardOutput,this,&LspClient::onNormalPrint);
    connect(process,&QProcess::stateChanged,this,&LspClient::onNormalPrint);
    run(clangdPath); //运行程序
}

LspClient::~LspClient()
{
    process->kill();    //结束子引用
    delete process;
}

//获取lsp服务实例
LspClient *LspClient::getLspClientInstance(QString clangdPath,QString language)
{
    if(!LspClientInstance){
        LspClientInstance = new LspClient(clangdPath,language);
    }
    return LspClientInstance;
}

//开始运行
bool LspClient::run(QString clangdPath)
{
    if(!clangdPath.isEmpty()){
        clangdExecPath = clangdPath;
    }
    process->start(clangdExecPath); //运行clangd程序
    isRun = process->waitForReadyRead();
    return isRun;
}


//初始化
void LspClient::initialize()
{
    QJsonObject jsonObj;
    jsonObj.insert("jsonrpc","2.0");
    jsonObj.insert("id",(int)LspId::initialize);
    jsonObj.insert("method","initialize");

    QJsonObject jsonParams;
    jsonParams.insert("capabilities",QJsonObject());
    jsonParams.insert("initializationOptions",QJsonObject());
    jsonParams.insert("trace","off");
    jsonObj.insert("params",jsonParams);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    process->write(buildRpcJson(jsonDoc.toJson()));
}

//打开文件
void LspClient::didOpen(QString filePath,QString content)
{
    QJsonObject jsonObj;
    jsonObj.insert("jsonrpc","2.0");
    jsonObj.insert("method","textDocument/didOpen");

    QJsonObject jsonTextDocument;
    jsonTextDocument.insert("uri",QString("file:///%1").arg(filePath));
    jsonTextDocument.insert("languageId",langSign);
    jsonTextDocument.insert("version",1);
    jsonTextDocument.insert("text",content);

    QJsonObject jsonParams;
    jsonParams.insert("textDocument",jsonTextDocument);
    jsonObj.insert("params",jsonParams);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    process->write(buildRpcJson(jsonDoc.toJson()));
}

//通知服务器文档已关闭
void LspClient::didClose(QString filePath)
{
    QJsonObject jsonObj;
    jsonObj.insert("jsonrpc","2.0");
    jsonObj.insert("method","textDocument/didClose");

    QJsonObject jsonTextDocument;
    jsonTextDocument.insert("uri",QString("file:///%1").arg(filePath));

    QJsonObject jsonParams;
    jsonParams.insert("textDocument",jsonTextDocument);
    jsonObj.insert("params",jsonParams);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    process->write(buildRpcJson(jsonDoc.toJson()));
}

//通知服务器文档内容已经改变
void LspClient::didChange(QString filePath, QString content)
{
    static int t_version = 1;
    t_version++;//增加版本号

    QJsonObject jsonObj;
    jsonObj.insert("jsonrpc","2.0");
//    jsonObj.insert("id",(int)LspId::didChange);
    jsonObj.insert("method","textDocument/didChange");

    QJsonObject jsonTextDocument;
    jsonTextDocument.insert("uri",QString("file:///%1").arg(filePath));
    jsonTextDocument.insert("version",t_version);

    QJsonArray jsonContentChanges;
    QJsonObject jsonTemp;
    jsonTemp.insert("text",content);
    jsonContentChanges.append(jsonTemp);

    QJsonObject jsonParams;
    jsonParams.insert("textDocument",jsonTextDocument);
    jsonParams.insert("contentChanges",jsonContentChanges);

    jsonObj.insert("params",jsonParams);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    process->write(buildRpcJson(jsonDoc.toJson()));
}


//请求语法提示
void LspClient::completion(QString filePath, uint16_t line, uint16_t character)
{
    QJsonObject jsonObj;
    jsonObj.insert("jsonrpc","2.0");
    jsonObj.insert("id",(int)LspId::completion);
    jsonObj.insert("method","textDocument/completion");

    QJsonObject jsonTextDocument;
    jsonTextDocument.insert("uri",QString("file:///%1").arg(filePath));

    QJsonObject jsonPosition;
    jsonPosition.insert("line",line);
    jsonPosition.insert("character",character);

    QJsonObject jsonContext;
    jsonContext.insert("triggerKind",1);

    QJsonObject jsonParams;
    jsonParams.insert("textDocument",jsonTextDocument);
    jsonParams.insert("position",jsonPosition);
    jsonParams.insert("context",jsonContext);

    jsonObj.insert("params",jsonParams);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    process->write(buildRpcJson(jsonDoc.toJson()));
}

//请求当前位置的悬停信息
void LspClient::hover(QString filePath, uint16_t line, uint16_t character)
{
    QJsonObject jsonObj;
    jsonObj.insert("jsonrpc","2.0");
    jsonObj.insert("id",(int)LspId::hover);
    jsonObj.insert("method","textDocument/hover");

    QJsonObject jsonTextDocument;
    jsonTextDocument.insert("uri",QString("file:///%1").arg(filePath));

    QJsonObject jsonPosition;
    jsonPosition.insert("line",line);
    jsonPosition.insert("character",character);

    QJsonObject jsonParams;
    jsonParams.insert("textDocument",jsonTextDocument);
    jsonParams.insert("position",jsonPosition);

    jsonObj.insert("params",jsonParams);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    process->write(buildRpcJson(jsonDoc.toJson()));
}

//获取特定符号的所有引用
void LspClient::references(QString filePath, uint16_t line, uint16_t character)
{
    QJsonObject jsonObj;
    jsonObj.insert("jsonrpc","2.0");
    jsonObj.insert("id",(int)LspId::references);
    jsonObj.insert("method","textDocument/references");

    QJsonObject jsonTextDocument;
    jsonTextDocument.insert("uri",QString("file:///%1").arg(filePath));

    QJsonObject jsonPosition;
    jsonPosition.insert("line",line);
    jsonPosition.insert("character",character);

    QJsonObject jsonParams;
    jsonParams.insert("textDocument",jsonTextDocument);
    jsonParams.insert("position",jsonPosition);

    jsonObj.insert("params",jsonParams);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    process->write(buildRpcJson(jsonDoc.toJson()));
}

//通知Clangd文档已保存
void LspClient::didSave(QString filePath)
{
    QJsonObject jsonObj;
    jsonObj.insert("jsonrpc","2.0");
    jsonObj.insert("method","textDocument/didSave");

    QJsonObject jsonTextDocument;
    jsonTextDocument.insert("uri",QString("file:///%1").arg(filePath));

    QJsonObject jsonParams;
    jsonParams.insert("textDocument",jsonTextDocument);
    jsonObj.insert("params",jsonParams);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    process->write(buildRpcJson(jsonDoc.toJson()));
}

//请求跳转到符号（如函数、变量等）的定义位置
void LspClient::definition(QString filePath, uint16_t line, uint16_t character)
{
    QJsonObject jsonObj;
    jsonObj.insert("jsonrpc","2.0");
    jsonObj.insert("id",(int)LspId::definition);
    jsonObj.insert("method","textDocument/definition");

    QJsonObject jsonTextDocument;
    jsonTextDocument.insert("uri",QString("file:///%1").arg(filePath));

    QJsonObject jsonPosition;
    jsonPosition.insert("line",line);
    jsonPosition.insert("character",character);

    QJsonObject jsonParams;
    jsonParams.insert("textDocument",jsonTextDocument);
    jsonParams.insert("position",jsonPosition);

    jsonObj.insert("params",jsonParams);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    process->write(buildRpcJson(jsonDoc.toJson()));
}

//获取文档中特定位置的语法高亮信息
void LspClient::documentHighlight(QString filePath, uint16_t line, uint16_t character)
{
    QJsonObject jsonObj;
    jsonObj.insert("jsonrpc","2.0");
    jsonObj.insert("id",(int)LspId::documentHighlight);
    jsonObj.insert("method","textDocument/documentHighlight");

    QJsonObject jsonTextDocument;
    jsonTextDocument.insert("uri",QString("file:///%1").arg(filePath));

    QJsonObject jsonPosition;
    jsonPosition.insert("line",line);
    jsonPosition.insert("character",character);

    QJsonObject jsonParams;
    jsonParams.insert("textDocument",jsonTextDocument);
    jsonParams.insert("position",jsonPosition);

    jsonObj.insert("params",jsonParams);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    process->write(buildRpcJson(jsonDoc.toJson()));
}

//获取文档中的符号信息，如函数、变量等
void LspClient::documentSymbol(QString filePath)
{
    QJsonObject jsonObj;
    jsonObj.insert("jsonrpc","2.0");
    jsonObj.insert("id",(int)LspId::documentSymbol);
    jsonObj.insert("method","textDocument/documentSymbol");

    QJsonObject jsonTextDocument;
    jsonTextDocument.insert("uri",QString("file:///%1").arg(filePath));

    QJsonObject jsonParams;
    jsonParams.insert("textDocument",jsonTextDocument);
    jsonObj.insert("params",jsonParams);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    process->write(buildRpcJson(jsonDoc.toJson()));
}

//创建RPC-JSON文本
QByteArray LspClient::buildRpcJson(QString jsonStr)
{
    QString str = jsonStr;
    str = QString("Content-Length: %1\r\n\r\n%2").arg(str.length()).arg(str);
    //qDebug().noquote() << str;
    return str.toUtf8();
}

//当收到数据
void LspClient::onLspResponse(QString data)
{
    //qDebug().noquote() << "rpc返回的数据" << data;

    if(data.left(QString("Content-Length:").length()) == "Content-Length:"){
        int t_startIndex = data.indexOf("{");
        if(t_startIndex == -1) return;
        QString t_jsonStr = data.right(data.length() - t_startIndex);
        QJsonDocument jsonDoc = QJsonDocument::fromJson(t_jsonStr.toUtf8());
        if(jsonDoc.isObject()){
            QJsonObject rpcObj = jsonDoc.object();      //RPC根对象
            int rpcId = rpcObj.value("id").toInt(-1);   //RPC的回复ID

            //补全代码类型
            if(rpcId == (int)LspId::completion){
                QJsonObject result = rpcObj.value("result").toObject();
                QJsonArray items = result.value("items").toArray();

                QList<CompletionNode> completionNodes;
                for(QJsonValue item : items){
                    QJsonObject itemObj = item.toObject();
                    CompletionNode cNode;
                    cNode.detail = itemObj.value("detail").toString();
                    cNode.filterText = itemObj.value("filterText").toString();
                    cNode.insertText = itemObj.value("insertText").toString();
                    cNode.insertTextFormat = itemObj.value("insertTextFormat").toInt();
                    cNode.kind = itemObj.value("kind").toInt();
                    cNode.label = itemObj.value("label").toString();
                    cNode.score = itemObj.value("score").toDouble();
                    cNode.sortText = itemObj.value("sortText").toString();
                    cNode.kind = itemObj.value("kind").toInt();

                    QJsonObject textEdit = itemObj.value("textEdit").toObject();
                    if(!textEdit.isEmpty()){
                        cNode.newText = textEdit.value("newText").toString();
                        QJsonObject range = textEdit.value("range").toObject();
                        QJsonObject start = range.value("start").toObject();
                        QJsonObject end = range.value("end").toObject();
                        cNode.startLine = start.value("line").toInt();
                        cNode.startCharacter = start.value("character").toInt();
                        cNode.endLine = end.value("line").toInt();
                        cNode.endCharacter = end.value("character").toInt();
                    }
                    completionNodes.append(cNode);
                }
                this->onCompletion(completionNodes);    //激发补全完成事件
            }
        }
    }
}

//错误输出
void LspClient::onErrorPrint()
{
    onLspResponse(process->readAllStandardError());
}

//默认输出
void LspClient::onNormalPrint()
{
    onLspResponse(process->readAllStandardOutput());
}

//进程状态改变
void LspClient::onProcessStateChange(QProcess::ProcessState state)
{
    isRun = (state == QProcess::ProcessState::Running);
}
