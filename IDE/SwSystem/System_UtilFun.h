#ifndef SYSTEM_UTILFUN_H
#define SYSTEM_UTILFUN_H
#include "QProcessEnvironment"


namespace System_Env
{
    extern QString getFilePathForEnvVar(QString fileName,QString suffix); //在环境变量中获取文件路径
    extern QString getProgramPathForEnvVar(QString programName); //在环境变量中获取可执行文件
};


namespace System_File {
    extern QByteArray readFile(QString filePath); //读取文件
    extern bool writeFile(QString filePath, QByteArray fileByte); //写出文件
}

#endif // SYSTEM_UTILFUN_H
