#ifndef SYSTEM_ENVVAR_H
#define SYSTEM_ENVVAR_H
#include "QProcessEnvironment"


class System_EnvVar
{
private:


public:
    System_EnvVar();

    QString getFilePathForEnvVar(QString fileName,QString suffix); //在环境变量中获取文件路径
    QString getProgramPathForEnvVar(QString programName); //在环境变量中获取可执行文件

};

#endif // SYSTEM_ENVVAR_H
