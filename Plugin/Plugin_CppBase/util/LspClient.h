#ifndef LSPCLIENT_H
#define LSPCLIENT_H

#include "QObject"
#include "QProcess"

class LspClient;
static LspClient* LspClientInstance = nullptr;

class LspClient : public QObject
{
    Q_OBJECT

private:
    enum class LspId:int{
        initialize = 1,         //初始化
//        didChange = 2,          //通知服务器文档内容已经改变
        completion = 3,         //客户端发送该请求以获取代码补全建议
        hover = 4,              //请求当前位置的悬停信息
        references = 5,         //获取特定符号的所有引用
//        save = 6,           //通知Clangd文档已保存
        definition = 6,         //请求跳转到符号（如函数、变量等）的定义位置
        documentHighlight = 7,  //获取文档中特定位置的语法高亮信息
        documentSymbol = 8,     //获取文档中的符号信息，如函数、变量等
        codeAction = 9,         //获取针对文档中特定问题的可能解决方案（代码操作）
    };

private:
    QString clangdExecPath;     //clangd程序的目录
    QProcess* process;
    bool isRun = false;
    QString langSign = "cpp";   //语言标记

public:
    struct CompletionNode{
        int kind;                       //提示类型
        QString detail;                 //细节信息
        QString filterText;             //过滤文本
        QString insertText;             //插入文本
        int insertTextFormat;           //插入类型
        QString label;                  //提示的文本
        double score;                   //排序值，越大越前面
        QString sortText;               //排序文本
        QString newText;                //要替换的文本
        uint16_t startLine = 0;         //开始行
        uint16_t startCharacter = 0;    //开始文本列
        uint16_t endLine = 0;           //结束行
        uint16_t endCharacter = 0;      //结束文本列
    };


private:
    LspClient(QString clangdPath = "",QString language = "cpp");
    ~LspClient();

public:
    //获取lsp服务实例
    static LspClient *getLspClientInstance(QString clangdPath = "",QString language = "cpp");

    //开始运行
    bool run(QString clangdPath = "");
    //初始化
    void initialize();
    //通知服务器有文档已经打开/加载
    void didOpen(QString filePath,QString content);
    //通知服务器文档已关闭
    void didClose(QString filePath);
    //通知服务器文档内容已经改变
    void didChange(QString filePath,QString content);
    //客户端发送该请求以获取代码补全建议
    void completion(QString filePath,uint16_t line,uint16_t character);
    //请求当前位置的悬停信息
    void hover(QString filePath,uint16_t line,uint16_t character);
    //获取特定符号的所有引用
    void references(QString filePath,uint16_t line,uint16_t character);
    //通知Clangd文档已保存
    void didSave(QString filePath);
    //请求跳转到符号（如函数、变量等）的定义位置
    void definition(QString filePath,uint16_t line,uint16_t character);
    //获取文档中特定位置的语法高亮信息
    void documentHighlight(QString filePath,uint16_t line,uint16_t character);
    //获取文档中的符号信息，如函数、变量等
    void documentSymbol(QString filePath);
    //获取针对文档中特定问题的可能解决方案（代码操作）
    //void codeAction();

private:
    //创建RPC-JSON文本
    QByteArray buildRpcJson(QString jsonStr);
    void onLspResponse(QString data);   //当收到数据

private slots:
    void onErrorPrint();
    void onNormalPrint();
    void onProcessStateChange(QProcess::ProcessState state);

signals:
    void onCompletion(QList<CompletionNode> completionNodes);   //补全提示信息

};

#endif // LSPCLIENT_H
