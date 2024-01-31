#ifndef PLUGIN_CPPBASE_GLOBAL_H
#define PLUGIN_CPPBASE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PLUGIN_CPPBASE_LIBRARY)
#  define PLUGIN_CPPBASE_EXPORT Q_DECL_EXPORT
#else
#  define PLUGIN_CPPBASE_EXPORT Q_DECL_IMPORT
#endif

//QCoreApplication::applicationDirPath() + "/config/

#include "QString"
#include "QObject"

#define OUTSETFILE QCoreApplication::applicationDirPath() + "/config/gccSetting.json"

namespace settingNamespace {

//编译器搜索信息
struct compileMsg{
    QString fp_gcc;
    QString fp_gpp;
    QString fp_make;
    QString fp_gdb;
    QString fp_gdbServer;
    QString fp_windres;
    QVector<QString> folderList;
};



//设置节点
struct settingNode{
    //======基本设置信息======
    QString name = QObject::tr("新的方案");

    //======选项卡：基本选项======
    bool s1_usingStatic = true; //使用静态链接方式链接库文件
    bool s1_usCompile = false; //编译时加入下列信息
    QString s1_otherCompile; //编译附加信息
    bool s1_usLink = false; //链接时加入下列选项
    QString s1_otherLinke; //链接附加信息

    //======选项卡：编译/链接选项 -> 代码生成======
    QString s21_opLevel; //优化级别
    QString s21_cppStd; //Cpp语言标准
    QString s21_cStd; //C语言标准
    QString s21_specificInstruct; //启用特定指令集
    QString s21_bit; //使用特定指针大小编译，64位或32位
    QString s21_compileMod; //编译的模
    bool s21_tepOpt = true; //快速编译，默认开启
    bool s21_enableThread = false; //多线程编译

    //======选项卡：编译/链接选项 -> 代码警告======
    bool s22_ignoreAllWaring = false;//忽略所有警告信息
    bool s22_wall = false; //启用常见问题警告
    bool s22_wextra = false; //启用更多问题警告
    bool s22_checkComplyIsoCppStd = false; //检查是否严格遵守ISO C/C++标准
    bool s22_werror = false; //将警告视为错误处理
    bool s22_wfatalErrors = false; //遇到第一个错误后立即中止编译
    QString s22_fstackProtector; //检查栈溢出错误

    //======选项卡：编译/链接选项 -> 链接器======
    bool s23_pipe = true; //编译时使用管道而不是临时文件
    bool s23_nostdlib = false; //不适用标准库和系统启动文件
    bool s23_mwindows = false; //不产生控制台窗口
    bool s23_s = true; //剥除附加信息

    //======选项卡：环境文件夹======
    QVector<QString> s31_sourceFolders; //源文件夹
    QVector<QString> s32_staticFolders; //静态文件夹

    //======选项卡：编译套件信息======
    compileMsg s4_compileMsg;

    //======选项卡：输出======
    bool s5_rbPreprocessingOnly = false; //在完成预处理后停止编译
    bool s5_rbCompilationProperOnly = false; //在生成汇编代码后停止
    bool s5_rbGenerateExecutable = true; //链接得到可执行文件
    QString s5_txtPreprocessingSuffix; //预处理输出后缀
    QString s5_txtCompilationSuffix; //汇编输出后缀
    QString s5_txtExecutableSuffix; //可执行文件后缀
    QString s5_cbBinarySuffix; //二进制文件类型
};


extern QVector<settingNode> settingList;//设置信息列表
extern int compilerIndex; //编译器索引
}



namespace cppAttributeNamespace {
//工程属性
struct projectAttribute{
    QString programName = "";                           //程序名称
    QString copyright = QObject::tr("FMS 开发");            //版权信息
    QString versionCode = "0.0.1.0";                    //版本信息
    QString outPath = "${projectPath}/out";                 //输出文件目录
    QString tempPath = "${projectPath}/out/temp";           //临时文件目录
    bool    useFmsTerminal = false;                         //使用FMS内置终端
    QString runArgs = "";                                   //程序启动参数
    QString icoPath ="${projectPath}/ico.ico";              //图标路径
    QString programNote = QObject::tr("本程序由FMS开发！");   //程序备注说明
    QString srcName = "";                                   //原始名称
    QString orgName = QObject::tr("火猴开发社区");            //公司社区名称
};
}










#endif // PLUGIN_CPPBASE_GLOBAL_H
