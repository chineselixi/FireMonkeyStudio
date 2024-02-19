#ifndef FORM_SETTINGS_COMPILE_H
#define FORM_SETTINGS_COMPILE_H

#include <QWidget>
#include "../../IDE/module/mod_settingsFormBase.h"
#include "../../Plugin_CppBase_global.h"


#define RUN_PATH_SIGN "${runPath}"

class Plugin_CppBase;

namespace Ui {
class Form_settings_Compile;
}

class Form_settings_Compile : public QWidget,public mod_settingsFormBase
{
    Q_OBJECT
private:
    Ui::Form_settings_Compile *ui;
    Plugin_CppBase* pluginPtr;


public:
    explicit Form_settings_Compile(Plugin_CppBase* pluginP,QWidget *parent = nullptr);
    ~Form_settings_Compile();

    //基本事件
    void Event_Ok() override; //确认键被按下
    void Event_cancel() override; //取消键被按下
    void Event_use() override; //应用键被按下


private:
    void addSettingSignNode(settingNamespace::settingNode node); //添加设置标记
    void updateCompilerUI(); //更新ui界面的编译器信息
    void findGccCompile(QString path, settingNamespace::compileMsg *cMsg); //查找GCC编译器
    settingNamespace::settingNode* getSignNode(QString name); //根据名称获取设置节点信息
    void getNotRepeatName(QString& name); //获取合适的构建名称
    QString getGppMsg(QString gcc_path); //获取g++信息
    QString getProcessVersion(QString proPath,QString versionCmd = "--version",QString startSign = "",QString endSign = "\n"); //获取软件版本字符串
    void processVersionThread(std::function<void()> thFun); //进程检查线程

public:
    static QString buildJson(); //获取把属性信息保存为Json数据
    static void loadSetting(QString jsonStr); //把json文本载入为设置信息
    static settingNamespace::settingNode getNowCompilerNode(); //获取当前的编译节点信息

private slots:
    void on_s4_btnChooseCCompiler_clicked();
    void on_btnFindCompilers_clicked(); //查找编译器是否存在
    void on_btnAddCompilerSetByFolder_clicked(); //选择文件夹，查询编译器
    void on_btnRenameCompilerSet_clicked(); //更改套件名称
    void on_btnRemoveCompilerSet_clicked(); //移除编译套件
    void on_btnAddBlankCompilerSet_clicked(); //添加新的套件
    void on_cbCompilerSet_activated(int index); //更改当前索引,使用代码更改index不会激发
    void on_s4_check_clicked(); //验证GCC基础套件
    void on_s4_btnChooseCppCompiler_clicked(); //CPP编译器选择
    void on_s4_btnChooseMake_clicked(); //Make选择
    void on_s4_btnChooseGDB_clicked(); //Gdb选择
    void on_s4_btnChooseGDBServer_clicked(); //GdbServer选择
    void on_s4_btnChooseResourceCompiler_clicked(); //ResourceCompiler选择
};

#endif // FORM_SETTINGS_COMPILE_H
