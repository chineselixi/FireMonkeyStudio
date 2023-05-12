
#ifndef SYSTEM_HISTORY_H
#define SYSTEM_HISTORY_H
#include "QString"
#include "QVector"


class System_History
{
    struct HistoryMsg{
        QString showName; //显示的名字
        QString showIco; //显示的图标
        QString filePath; //文件路径
        QString other;  //其他信息列表
    };

private:
    QString proHisPath = ""; //工程历史目录配置文件

    QVector<HistoryMsg> His_proList;

public:
    System_History();
    ~System_History();



public:
    bool Init(QString proHisConfigPath); //初始化
    QVector<HistoryMsg> getHisList(); //获取工程历史列表
    bool removeProHisList(QString sign); //移除工程列表历史记录
    void clearRepeat(); //清理重复数据
    void addMsg(QString showName,QString showIco,QString filePath,QString other); //添加字项目
    bool has(QString filePath); //根据路径，检索当前是否存在此历史记录
    void saveHisList(); //保存列表
};

#endif // SYSTEM_HISTORY_H
