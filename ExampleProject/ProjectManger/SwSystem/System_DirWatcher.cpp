#include "System_DirWatcher.h"
#include "QDir"


System_DirWatcher::System_DirWatcher()
{
//    QVector<QString> list = this->scanDirectory("C:/Users/31914/Desktop/test");
//    foreach (const QString s, list) {
//        qDebug() << s;
//    }

    this->addPath("C:/Users/31914/Desktop/test");
//    this->addPath("C:/Users/31914/Desktop/test/testProject/out");


    qDebug() << "开始运行";
}

System_DirWatcher::~System_DirWatcher()
{
    if(watcher != nullptr){delete watcher;}
}


//扫描指定目录的所有子层级的目录（不包含文件）
QVector<QString> System_DirWatcher::scanDirectory(QString directoryPath)
{
    QVector<QString> fileList;
    QDir directory(directoryPath);
    directory.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList fileInfoList = directory.entryInfoList();
    foreach (const QFileInfo& fileInfo, fileInfoList) {
        fileList.append(fileInfo.filePath()); //加入文件夹
        QVector<QString> subDirectoryFiles = scanDirectory(fileInfo.filePath());
        fileList.append(subDirectoryFiles);
    }
    return fileList;
}

//扫描某个目录下的所有文件和文件夹（不包含子目录下级的信息）
QVector<QString> System_DirWatcher::scanFileAndDir(QString directoryPath)
{
    QVector<QString> fileList;
    QDir directory(directoryPath);
    directory.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
    QFileInfoList fileInfoList = directory.entryInfoList();
    foreach (const QFileInfo& fileInfo, fileInfoList) {
        fileList.append(fileInfo.filePath()); //加入文件/文件夹
    }
    return fileList;
}


//添加根节点
bool System_DirWatcher::initRootDirPath(QString rootPath)
{
    if(!QDir(rootPath).exists()) return false;

    //初始化信息
    this->infoList.clear();
    if(watcher != nullptr){delete watcher;}
    watcher = new QFileSystemWatcher;
    connect(watcher,&QFileSystemWatcher::directoryChanged,this,&System_DirWatcher::directoryChanged);
    this->infoList.clear(); //关闭

    //扫描信息
    QVector<QString> t_paths;
    t_paths.reserve(100); //先申请以一个最少100的容量

    t_paths = this->scanDirectory(rootPath); //扫描所有子文件夹
    t_paths.append(rootPath);

    //整理集合信息
    foreach (auto item, t_paths) {
        dirInfoSet t_info;
        t_info.dirPath = item;
        t_info.subPath = this->scanFileAndDir(t_info.dirPath);
        this->infoList.append(t_info);
    }

    //添加监视信息
    this->watcher->addPaths(t_paths);
    return true;
}

//添加其他文件夹，若是在工程根类，则自动增加
void System_DirWatcher::addPath(QString dirPath)
{
    if(this->watcher == nullptr){
        return;
    }

    //找出所有子目录（包含本身）
    QVector<QString> t_path;
    t_path.reserve(50);
    t_path.append(dirPath);
    t_path.append(this->scanDirectory(dirPath));

    //加入目录，并且判断是否在内部已经存在
    for(int a = 0;a < t_path.length(); a++){
        dirInfoSet t_info;
        for(int b = 0; b < this->infoList.length(); b++){
            if(this->infoList[b].dirPath == t_path[a]){ //内部存在则重新扫描
                t_info.dirPath = t_path[a];
                t_info.subPath = this->scanFileAndDir(t_path[a]);
                this->infoList[b] = t_info;
                goto BACK;
            }
        }
        t_info.dirPath = t_path[a];
        t_info.subPath = this->scanFileAndDir(t_path[a]);
        this->watcher->addPath(t_info.dirPath);
        this->infoList.append(t_info);
    BACK:
        continue;
    }
}

//删除其他文件夹
void System_DirWatcher::delPath(QString dirPath)
{
    if(this->watcher == nullptr){
        return;
    }

    this->watcher->removePath(dirPath);

    for(int i = 0; i < this->infoList.length(); i++){
        if(this->infoList[i].dirPath == dirPath){
            this->watcher->addPath(this->infoList[i].dirPath);
            this->infoList.remove(i);
            return;
        }
    }
}


//判断是否存在监视
bool System_DirWatcher::hasPath(QString dirPath)
{
    foreach (auto item, this->infoList) {
        if(item.dirPath == dirPath){
            return true;
        }
    }
    return false;
}


//获取初始化后的所有Path,包含子path
QVector<QString> System_DirWatcher::getAllPath()
{
    QVector<QString> t_ret;
    t_ret.reserve(100);
    for(int i = 0; i < this->infoList.length(); i++){
        t_ret.append(this->infoList[i].dirPath);
        t_ret.append(this->infoList[i].subPath);
    }
    return t_ret;
}


//获取集合中左边包含的数据
QVector<QString> System_DirWatcher::getLikeLeftPath(QString dirPath)
{
    QVector<QString> t_ret;
    foreach (auto item, this->infoList) {
        if(item.dirPath.indexOf(dirPath) == 0){
            t_ret.append(item.dirPath);
        }
    }
    return t_ret;
}


//删除集合中左边包含的数据
void System_DirWatcher::delLikeLeftPath(QString dirPath)
{
    if(this->watcher == nullptr){
        return;
    }
    this->watcher->removePath(dirPath);
    for(int i = this->infoList.size() - 1; i >= 0; i--){
        if(this->infoList[i].dirPath.left(dirPath.length()) == dirPath){
            this->watcher->removePath(this->infoList[i].dirPath);
            this->infoList.remove(i);
        }
    }
}


//文件夹改变（用于扫描）
void System_DirWatcher::directoryChanged(const QString &path)
{
    dirInfoSet* t_infoPtr = nullptr; //扫描到的目标指针

    qDebug() << "文件夹内容改变" << path;


    return;


    //定位集合信息
    for(int i = 0; i < this->infoList.length(); i++){
        if(this->infoList[i].dirPath == path){
            t_infoPtr = &this->infoList[i];
            break;
        }
    }

    if(t_infoPtr == nullptr){
        return;
    }

    QVector<QString> t_scanList = this->scanFileAndDir(path); //扫描目录下的文件

    //判断事件类型
    QString t_oldName;
    QString t_newName;

    //扫描的数量小于等于存储数量，则可能删除或改名
    if(t_scanList.length() <= t_infoPtr->subPath.length()){
        for(int a = 0; a < t_infoPtr->subPath.length(); a++){
            t_oldName = t_infoPtr->subPath[a];
            for(int b = 0; b < t_scanList.length(); b++){
                if(t_infoPtr->subPath[a] == t_scanList[b]){
                    t_oldName.clear();
                    break;
                }
            }
            if(!t_oldName.isEmpty()){
                break;
            }
        }
    }

    //扫描的数量大于等于存储数量，则可能新增或改名
    if(t_scanList.length() >= t_infoPtr->subPath.length()){
        for(int a = 0; a < t_scanList.length() ; a++){
            t_newName = t_scanList[a];
            for(int b = 0; b < t_infoPtr->subPath.length() ; b++){
                if(t_scanList[a] == t_infoPtr->subPath[b]){
                    t_newName.clear();
                    break;
                }
            }
            if(!t_newName.isEmpty()){
                break;
            }
        }
    }



    if(!t_oldName.isEmpty() && t_newName.isEmpty()){ //以前有，现在没有：删除

        if(this->hasPath(t_oldName)){
            this->delLikeLeftPath(t_oldName); //移除老旧的记录
        }
        this->addPath(path); //文件被删除，则重新添加所在文件夹，会重新扫描子信息
        this->onRemove(t_oldName);
    }
    else if(t_oldName.isEmpty() && !t_newName.isEmpty()){ //以前没有，现在有：新增
        QFileInfo t_info(t_newName);
        if(t_info.isDir()){
            this->addPath(path); //父亲重新扫描。会自动添加新出现的目录，已经存在的目录则不添加
        }
        else if(t_info.isFile()){
            this->addPath(t_info.path()); //文件被删除，则重新添加所在文件夹，会重新扫描子信息
        }
        this->onIncrease(t_newName);
    }
    else if(!t_oldName.isEmpty() && !t_newName.isEmpty()){ //以前有，现在有：改名
        QFileInfo t_info(t_newName);
        if(t_info.isDir()){ //如果是文件夹，则重新扫描文件夹以及子夹，更新记录信息
            this->delLikeLeftPath(t_oldName); //移除老旧的记录
            this->addPath(t_newName); //添加新的记录
        }
        else if(t_info.isFile()){
            this->addPath(t_info.path()); //文件被更名，则重新添加所在文件夹，会重新扫描子信息
        }
        this->onNameChanged(t_oldName,t_newName); //激活名称改变事件
    }


//    qDebug() << "old" << t_oldName << "new" << t_newName;

//    //输出内存结构
//    for(i = infoList.begin(); i < infoList.end(); i++){
//        qDebug() << i->dirPath;
//        for(i1 = i->subPath.begin(); i1 < i->subPath.end(); i1++){
//            qDebug() << "------" << *i1;
//        }
//    }
}
