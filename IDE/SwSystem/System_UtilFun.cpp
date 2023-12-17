#include "System_UtilFun.h"
#include "QFile"
#include "QFileInfo"
#include "QApplication"
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
