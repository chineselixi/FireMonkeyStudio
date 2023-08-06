#include "System_EnvVar.h"
#include "QFile"
#include "QApplication"


System_EnvVar::System_EnvVar()
{

}


//在环境变量中获取文件路径
QString System_EnvVar::getFilePathForEnvVar(QString fileName, QString suffix)
{
    QString t_fileName = fileName;
    if(!suffix.isEmpty())
        t_fileName += "." + suffix;

    QString t_paths = QProcessEnvironment::systemEnvironment().value("path");
    QStringList t_list = t_paths.split(";");
    for(QStringList::Iterator i = t_list.begin(); i < t_list.end();i++){
        QString t_filePath = *i + "/" + t_fileName;
        if(QFile::exists(t_filePath)){
            return t_filePath;
        }
    }
    return "";
}


//在环境变量中获取可执行文件
QString System_EnvVar::getProgramPathForEnvVar(QString programName)
{
    QString t_proPath = QCoreApplication::applicationFilePath();
    t_proPath = t_proPath.right(t_proPath.length() - t_proPath.lastIndexOf(".") - 1);
    return this->getFilePathForEnvVar(programName,t_proPath);
}
