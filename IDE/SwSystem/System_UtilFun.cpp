#include "System_UtilFun.h"
#include "QFile"
#include "QFileInfo"
#include "QApplication"
#include "QDir"
#include "QWidget"


//在环境变量中获取文件路径
QString System_Env::getFilePathForEnvVar(QString fileName, QString suffix)
{
    QString t_fileName = fileName;
    if(!suffix.isEmpty())
        t_fileName += "." + suffix;
    QString t_paths = qgetenv("PATH");
    QString t_sign = (t_paths.indexOf(";")!=-1?";":":");
    QStringList t_list = t_paths.split(t_sign);
    for(QStringList::Iterator i = t_list.begin(); i < t_list.end();i++){
        QString t_filePath = *i + "/" + t_fileName;
        if(QFile::exists(t_filePath)){
            return t_filePath;
        }
    }
    return "";
}


//在环境变量中获取可执行文件
QString System_Env::getProgramPathForEnvVar(QString programName)
{
    QString t_proPath = QCoreApplication::applicationFilePath();
    QFileInfo fileInfo(t_proPath);
    return getFilePathForEnvVar(programName,fileInfo.suffix());
}


//读入文件
QByteArray System_File::readFile(QString filePath)
{
    QFile file(filePath);
    QByteArray bytes;
    if (file.open(QIODevice::ReadOnly)) {
        bytes = file.readAll();
        file.close();
    }
    return bytes;
}


//写出文件
bool System_File::writeFile(QString filePath, QByteArray fileByte)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(fileByte);
        file.close();
        return true;
    }
    return false;
}


//获取指定Widget在祖先Widget的相对位置
QPoint System_Widget::getWidgetRelPos(QWidget *widget, QWidget *parent)
{
    QPoint t_point;
    QWidget* t_widget = widget;
    while(true){
        QPoint t_wpos = t_widget->pos();
        t_point.setX(t_point.x() + t_wpos.x());
        t_point.setY(t_point.y() + t_wpos.y());
        t_widget = t_widget->parentWidget();
        if(t_widget == nullptr){
            break;
        }
        else if(t_widget == parent){
            return t_point;
        }
    }
    return QPoint();
}


//扫描全部文件及文件夹
void System_File::scanDirectory(const QString &path, QVector<QString> &folders, QVector<QString> &files)
{
    QDir dir(path);
    QFileInfoList t_infoList = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    for(QFileInfo t_info : t_infoList){
        if(t_info.isFile()){
            files.append(t_info.absoluteFilePath());
        }
        else if(t_info.isDir()){
            folders.append(t_info.absoluteFilePath());
            scanDirectory(t_info.absoluteFilePath(), folders, files); // 递归遍历子文件夹
        }
    }
}

//复制文件夹
bool System_File::copyPath(QString srcPath, QString newPath, std::function<bool (int)> indexFun)
{
    if(!QDir(srcPath).exists()) return false;

    //扫描文件
    QVector<QString> t_folders;
    QVector<QString> t_files;
    t_folders.append(srcPath); //复制的文件夹包含本身
    scanDirectory(srcPath,t_folders,t_files);

    //创建目标文件夹
    if(t_folders.length() + t_files.length() > 0){
        if(!QDir().mkpath(newPath)) return false;
    }

    //替换相对路径
    for(QString& item : t_folders){item.replace(srcPath,"");}
    for(QString& item : t_files){item.replace(srcPath,"");}

    int t_len = t_folders.length() + t_files.length();
    float t_start = 0;

    //复制文件夹
    for(QString& item : t_folders){

        if(!QDir().mkpath(newPath + item)){
            return false;
        }
        if(indexFun){
            if(!indexFun((++t_start) / t_len * 100)) return false; //如果函数返回假，则立即中止复制
        }
    }

    //复制文件
    for(QString& item : t_files){
        if(!QFile(srcPath + item).copy(newPath + item) && !QFile(newPath + item).exists()){
            return false;
        }
        if(indexFun){
            if(!indexFun((++t_start) / t_len * 100)) return false; //如果函数返回假，则立即中止复制
        }
    }
    return true;
}
