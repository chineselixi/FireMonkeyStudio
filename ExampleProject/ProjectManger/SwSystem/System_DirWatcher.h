#ifndef SYSTEM_System_DirWatcher_H
#define SYSTEM_System_DirWatcher_H

#include <QObject>
#include "QFileSystemWatcher"

class System_DirWatcher : public QObject
{
    Q_OBJECT
public:
    System_DirWatcher();
    ~System_DirWatcher();

private:
    struct dirInfoSet{ //子文件夹信息
        QString dirPath; //当前目录名称
        QVector<QString> subPath; //子(目录/文件)集合
    };



private:
    QFileSystemWatcher* watcher = nullptr; //基础文件监视器指针
    QList<dirInfoSet> infoList; //数据集合

public:
    QVector<QString> scanDirectory(QString directoryPath); //扫描指定目录的所有子层级的目录（不包含文件）
    QVector<QString> scanFileAndDir(QString directoryPath); //扫描某个目录下的所有文件和文件夹（不包含子目录下级的信息）

public:
    bool initRootDirPath(QString rootPath); //添加根节点
    void addPath(QString dirPath); //添加其他文件夹，若是在工程根类，则自动增加
    void delPath(QString dirPath); //删除其他文件夹
    bool hasPath(QString dirPath); //判断是否存在监视

    QVector<QString> getAllPath(); //获取初始化后的所有Path，包含子path

    QVector<QString> getLikeLeftPath(QString dirPath); //获取集合中左边包含的数据
    void delLikeLeftPath(QString dirPath); //删除集合中左边包含的数据

private:
    void directoryChanged(const QString &path); //文件夹改变

signals:
    void onNameChanged(QString oldPathName, QString newPathName); //文件名被改变
    void onIncrease(QString newPathName); //有新增的文件或文件夹
    void onRemove(QString pathName); //删除了某个文件


};

#endif // SYSTEM_System_DirWatcher_H
