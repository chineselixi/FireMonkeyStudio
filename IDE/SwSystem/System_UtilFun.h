#ifndef SYSTEM_UTILFUN_H
#define SYSTEM_UTILFUN_H
#include "QProcessEnvironment"
#include "QPoint"

namespace System_Env
{
    extern QString getFilePathForEnvVar(QString fileName,QString suffix); //在环境变量中获取文件路径
    extern QString getProgramPathForEnvVar(QString programName); //在环境变量中获取可执行文件
};


namespace System_File {
    extern QByteArray readFile(QString filePath); //读取文件
    extern bool writeFile(QString filePath, QByteArray fileByte); //写出文件
    extern void scanDirectory(const QString& path, QVector<QString>& folders, QVector<QString>& files); //扫描全部文件及文件夹
    extern bool copyPath(QString srcPath, QString newPath, std::function<bool(int progress)> indexFun = nullptr); //复制文件夹
}


namespace System_Widget{
    extern QPoint getWidgetRelPos(QWidget *widget, QWidget *parent); //获取指定Widget在祖先Widget的相对位置
    extern QWidget* getSubWidgetPtr(QWidget* parentWidget, QString subObjctName); //获取父类指针下指定名称控件的窗口指针
}


namespace System_OS {
    enum class OSType{
        WINDOWS,
        MACOS,
        LINUX,
        NON
    };
    extern OSType getOsType(); //获取当前操作系统类型
    extern QString getSoftwareSuffix(); //获取可执行文件后缀
    extern QString getDynamicLibrarySuffix(); //获取动态库后缀
    extern QString getaApplicationDirPath_EX(); //获取当前程序运行程序的文件的路径

}
#endif // SYSTEM_UTILFUN_H
