#include "Form_settings_Compile.h"
#include "ui_Form_settings_Compile.h"
#include "../../../../IDE/module/mod_settingsFormBase.cpp"
#include "../../../../IDE/SwSystem/System_UtilFun.cpp"
#include "../../../../IDE/SwSystem/System_GlobalVar.cpp"
#include "../../../../IDE/SwSystem/System_UtilFun.h"

#include "thread"
#include "shared_mutex"
#include "QFileDialog"
#include "QInputDialog"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"

std::mutex rw_mutex; //线程读写锁
int threadNum = 0;

Form_settings_Compile::Form_settings_Compile(Plugin_CppBase* pluginP,QWidget *parent) :
    pluginPtr(pluginP),
    QWidget(parent),
    ui(new Ui::Form_settings_Compile)
{
    ui->setupUi(this);
    ui->settingTabs->setCurrentIndex(0); //默认0子夹
    this->updateCompilerUI(); //刷新UI
}

Form_settings_Compile::~Form_settings_Compile()
{
    delete ui;
}



//添加编译器标记
void Form_settings_Compile::addSettingSignNode(settingNamespace::settingNode node)
{
    for(int i = 0; i < settingNamespace::settingList.length(); i++){
        if(settingNamespace::settingList[i].name == node.name){
            settingNamespace::settingList[i] = node;
            return;
        }
    }
    settingNamespace::settingList.append(node);
}


//更新ui界面的编译器信息
void Form_settings_Compile::updateCompilerUI()
{
    bool t_enable = true;

    //检查当前设置标记
    if(settingNamespace::compilerIndex < 0 || settingNamespace::compilerIndex >= settingNamespace::settingList.length()){
        t_enable = false;
        if(settingNamespace::settingList.length() == 0){
            ui->cbCompilerSet->clear();//清理信息
            ui->btnRenameCompilerSet->setEnabled(false);
            ui->btnRemoveCompilerSet->setEnabled(false);
        }
        else{
            settingNamespace::compilerIndex = 0;
            ui->btnRenameCompilerSet->setEnabled(true);
            ui->btnRemoveCompilerSet->setEnabled(true);
            t_enable = true;
        }
    }
    ui->tabGeneral->setEnabled(t_enable);
    ui->tabSettings->setEnabled(t_enable);
    ui->tabDirectories->setEnabled(t_enable);
    ui->tabPrograms->setEnabled(t_enable);
    ui->tabOutput->setEnabled(t_enable);
    if(!t_enable) return;

    //隐藏S4套件版本信息
    ui->label_tip_c->hide();
    ui->label_tip_cpp->hide();
    ui->label_tip_make->hide();
    ui->label_tip_gdb->hide();
    ui->label_tip_gdbServer->hide();
    ui->label_tip_windres->hide();


    //获取当前设置信息
    settingNamespace::settingNode node = settingNamespace::settingList[settingNamespace::compilerIndex];

    //展现不同设置配套信息
    ui->cbCompilerSet->clear();//清理信息
    for(unsigned int a = 0; a<settingNamespace::settingList.length(); a++){ui->cbCompilerSet->addItem(settingNamespace::settingList[a].name);} //加入信息到列表
    ui->cbCompilerSet->setCurrentText(node.name); //选择当前的信息



    //选项卡：基本设置
    ui->s1_usingStatic->setChecked(node.s1_usingStatic);
    ui->s1_usCompile->setChecked(node.s1_usCompile);
    ui->s1_otherCompile->setPlainText(node.s1_otherCompile);
    ui->s1_usLink->setChecked(node.s1_usLink);
    ui->s1_otherLinke->setPlainText(node.s1_otherLinke);

    //选项卡：编译/链接选项 -> 代码生成
    ui->s21_opLevel->setCurrentText(node.s21_opLevel);
    ui->s21_cppStd->setCurrentText(node.s21_cppStd);
    ui->s21_cStd->setCurrentText(node.s21_cStd);
    ui->s21_specificInstruct->setCurrentText(node.s21_specificInstruct);
    ui->s21_bit->setCurrentText(node.s21_bit);
    ui->s21_compileMod->setCurrentText(node.s21_compileMod);
    ui->s21_tepOpt->setChecked(node.s21_tepOpt);
    ui->s21_enableThread->setChecked(node.s21_enableThread);
    //选项卡：编译/链接选项 -> 代码警告
    ui->s22_ignoreAllWaring->setChecked(node.s22_ignoreAllWaring);
    ui->s22_wall->setChecked(node.s22_wall);
    ui->s22_wextra->setChecked(node.s22_wextra);
    ui->s22_checkComplyIsoCppStd->setChecked(node.s22_checkComplyIsoCppStd);
    ui->s22_werror->setChecked(node.s22_werror);
    ui->s22_wfatalErrors->setChecked(node.s22_wfatalErrors);
    ui->s22_fstackProtector->setCurrentText(node.s22_fstackProtector);
    //选项卡：编译/链接选项 -> 链接器
    ui->s23_pipe->setChecked(node.s23_pipe);
    ui->s23_nostdlib->setChecked(node.s23_nostdlib);
    ui->s23_mwindows->setChecked(node.s23_mwindows);
    ui->s23_s->setChecked(node.s23_s);

    //选项卡：环境文件夹
    ui->s31_sourceFolders->setList(node.s31_sourceFolders);
    ui->s32_staticFolders->setList(node.s32_staticFolders);

    //选项卡：编译套件信息
    ui->s4_txtCCompiler->setText(node.s4_compileMsg.fp_gcc);
    ui->s4_txtCppCompiler->setText(node.s4_compileMsg.fp_gpp);
    ui->s4_txtMake->setText(node.s4_compileMsg.fp_make);
    ui->s4_txtGDB->setText(node.s4_compileMsg.fp_gdb);
    ui->s4_txtGDBServer->setText(node.s4_compileMsg.fp_gdbServer);
    ui->s4_txtResourceCompiler->setText(node.s4_compileMsg.fp_windres);


    //选项卡：输出
    ui->s5_rbPreprocessingOnly->setChecked(node.s5_rbPreprocessingOnly);
    ui->s5_rbCompilationProperOnly->setChecked(node.s5_rbCompilationProperOnly);
    ui->s5_rbGenerateExecutable->setChecked(node.s5_rbGenerateExecutable);
    ui->s5_txtPreprocessingSuffix->setText(node.s5_txtPreprocessingSuffix);
    ui->s5_txtCompilationSuffix->setText(node.s5_txtCompilationSuffix);
    ui->s5_txtExecutableSuffix->setText(node.s5_txtExecutableSuffix);
    ui->s5_cbBinarySuffix->setCurrentText(node.s5_cbBinarySuffix);

    //选项卡：步骤
    ui->s61_useComposeBefore->setChecked(node.s61_useComposeBefore);
    ui->s61_useComposeFinish->setChecked(node.s61_useComposeFinish);
    ui->s61_useComposeError->setChecked(node.s61_useComposeError);
    ui->s61_composeBeforeEditor->setPlainText(node.s61_composeBeforeEditor);
    ui->s61_composeFinishEditor->setPlainText(node.s61_composeFinishEditor);
    ui->s61_composeErrorEditor->setPlainText(node.s61_composeErrorEditor);
    ui->s61_useRunBefore->setChecked(node.s61_useRunBefore);
    ui->s61_useRunFinish->setChecked(node.s61_useRunFinish);
    ui->s61_useRunError->setChecked(node.s61_useRunError);
    ui->s61_runBeforeEditor->setPlainText(node.s61_runBeforeEditor);
    ui->s61_runFinishEditor->setPlainText(node.s61_runFinishEditor);
    ui->s61_runErrorEditor->setPlainText(node.s61_runErrorEditor);

}



//查找GCC编译器
void Form_settings_Compile::findGccCompile(QString path, settingNamespace::compileMsg *cMsg)
{
    QDir dir(path);
    bool isFind = false;
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::AllDirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);
    for(QFileInfo fileInfo : list)
    {
        QString filePath = fileInfo.absoluteFilePath();
        if(fileInfo.isDir())
        {
            QString name = fileInfo.baseName();
            if(name != "include"){
                this->findGccCompile(filePath,cMsg); //递归遍历文件夹
            }
            else{
                cMsg->folderList.append(filePath); //文件夹内存在文件后才记录,如果当前目录
            }
        }
        else
        {
            QString suffix = fileInfo.suffix();
            if(suffix == "h" || suffix == "c" || suffix == "cpp"  || suffix == "hpp"){
                isFind = true;
            }
            if(filePath.indexOf("bin") != -1){ //扫描bin目录下的执行文件
                QString name = fileInfo.baseName();
                if(name == "gcc"){
                    cMsg->fp_gcc = filePath;
                }
                else if(name == "g++"){
                    cMsg->fp_gpp = filePath;
                }
                else if(name == "mingw32-make"){
                    cMsg->fp_make = filePath;
                }
                else if(name == "gdb"){
                    cMsg->fp_gdb = filePath;
                }
                else if(name == "gdbserver"){
                    cMsg->fp_gdbServer = filePath;
                }
                else if(name == "windres"){
                    cMsg->fp_windres = filePath;
                }
            }
        }
    }

    if(isFind){
        cMsg->folderList.append(path); //文件夹内存在文件后才记录
    }
}


//根据名称获取设置节点信息
settingNamespace::settingNode *Form_settings_Compile::getSignNode(QString name)
{
    for(int i = 0; i < settingNamespace::settingList.length(); i++){
        if(settingNamespace::settingList[i].name == name){
            return &settingNamespace::settingList[i];
        }
    }
    return nullptr;
}


//获取合适的构建名称
void Form_settings_Compile::getNotRepeatName(QString &name)
{
    settingNamespace::settingNode* node = this->getSignNode(name);
    QString newName = name;
    if(node != nullptr){
        uint16_t num = 1;
        do{
            newName = name + "(" + QString::number(num) + ")";
            num++;
        }
        while(this->getSignNode(newName) != nullptr);
    }
    name = newName;
}



//获取g++信息
QString Form_settings_Compile::getGppMsg(QString gcc_path)
{
    QProcess t_process; //创建子进程对象，获取GCC版本
    t_process.start(gcc_path,{"--version"}); //运行 gcc -v,查询版本
    t_process.waitForReadyRead();
    QString t_normalPut = QString().fromLocal8Bit(t_process.readAllStandardOutput()); //读取控制台信息
    QString name;
    if(!t_normalPut.isEmpty()){
        //name = tr("GCC生成器：") + Str::getSubStr(t_normalPut," ","\r\n");
        name = Str::getSubStr(t_normalPut," ","\r\n"); //编译器名称
    }
    t_process.close(); //关闭进程
    return name;
}


//获取软件版本字符串
QString Form_settings_Compile::getProcessVersion(QString proPath, QString versionCmd, QString startSign, QString endSign)
{
    QFile t_exeFile(proPath);
    if(!t_exeFile.exists()) return "";

    QProcess t_process; //创建子进程对象
    t_process.start(proPath,{versionCmd}); //运行查询版本
    t_process.waitForReadyRead();
    QString t_normalPut = QString().fromLocal8Bit(t_process.readAllStandardOutput()); //读取控制台信息
    QString name;
    if(!t_normalPut.isEmpty()){
        name = Str::getSubStr(t_normalPut,startSign,endSign); //编译器名称
    }
    t_process.close(); //关闭进程
    return name;
}



//进程检查线程
void Form_settings_Compile::processVersionThread(std::function<void ()> thFun)
{
    //查看版本，存在则展现
    std::thread t_cThread([thFun,this](int){
        thFun();
        rw_mutex.lock(); //加锁
        threadNum++;
        if(threadNum == 6){
            ui->s4_check->setEnabled(true);
            ui->s4_check->setText(tr("验证套件"));
        }
        rw_mutex.unlock();
    },0);
    t_cThread.join();//运行线程
}





//获取把属性信息保存为Json数据
QString Form_settings_Compile::buildJson()
{
    if(settingNamespace::compilerIndex < 0 || settingNamespace::compilerIndex >= settingNamespace::settingList.length()){
        return "";
    }

    QJsonDocument t_jsonDocument;
    QJsonObject t_jsonObj;
    QJsonArray t_jsonArray;
    t_jsonObj.insert("version",1);
    t_jsonObj.insert("select",settingNamespace::settingList[settingNamespace::compilerIndex].name); //设置当前选择的标记

    for(unsigned int i = 0; i<settingNamespace::settingList.length(); i++){
        QJsonObject t_obj;
        t_obj.insert("name",settingNamespace::settingList[i].name);
        //======选项卡：基本选项======
        t_obj.insert("s1_usingStatic",settingNamespace::settingList[i].s1_usingStatic); //使用静态链接方式链接库文件
        t_obj.insert("s1_usCompile",settingNamespace::settingList[i].s1_usCompile); //编译时加入下列信息
        t_obj.insert("s1_otherCompile",settingNamespace::settingList[i].s1_otherCompile); //编译附加信息
        t_obj.insert("s1_usLink",settingNamespace::settingList[i].s1_usLink); //链接时加入下列选项
        t_obj.insert("s1_otherLinke",settingNamespace::settingList[i].s1_otherLinke); //链接附加信息

        //======选项卡：编译/链接选项 -> 代码生成======
        t_obj.insert("s21_opLevel",settingNamespace::settingList[i].s21_opLevel); //优化级别
        t_obj.insert("s21_cppStd",settingNamespace::settingList[i].s21_cppStd); //Cpp语言标准
        t_obj.insert("s21_cStd",settingNamespace::settingList[i].s21_cStd); //C语言标准
        t_obj.insert("s21_specificInstruct",settingNamespace::settingList[i].s21_specificInstruct); //启用特定指令集
        t_obj.insert("s21_bit",settingNamespace::settingList[i].s21_bit); //使用特定指针大小编译，64位或32位
        t_obj.insert("s21_compileMod",settingNamespace::settingList[i].s21_compileMod); //编译的模
        t_obj.insert("s21_tepOpt",settingNamespace::settingList[i].s21_tepOpt); //快速编译
        t_obj.insert("s21_enableThread",settingNamespace::settingList[i].s21_enableThread); //多线程编译

        //======选项卡：编译/链接选项 -> 代码警告======
        t_obj.insert("s22_ignoreAllWaring",settingNamespace::settingList[i].s22_ignoreAllWaring);//忽略所有警告信息
        t_obj.insert("s22_wall",settingNamespace::settingList[i].s22_wall); //启用常见问题警告
        t_obj.insert("s22_wextra",settingNamespace::settingList[i].s22_wextra); //启用更多问题警告
        t_obj.insert("s22_checkComplyIsoCppStd",settingNamespace::settingList[i].s22_checkComplyIsoCppStd); //检查是否严格遵守ISO C/C++标准
        t_obj.insert("s22_werror",settingNamespace::settingList[i].s22_werror); //将警告视为错误处理
        t_obj.insert("s22_wfatalErrors",settingNamespace::settingList[i].s22_wfatalErrors); //遇到第一个错误后立即中止编译
        t_obj.insert("s22_fstackProtector",settingNamespace::settingList[i].s22_fstackProtector); //检查栈溢出错误

        //======选项卡：编译/链接选项 -> 链接器======
        t_obj.insert("s23_pipe",settingNamespace::settingList[i].s23_pipe); //编译时使用管道而不是临时文件
        t_obj.insert("s23_nostdlib",settingNamespace::settingList[i].s23_nostdlib); //不适用标准库和系统启动文件
        t_obj.insert("s23_mwindows",settingNamespace::settingList[i].s23_mwindows); //不产生控制台窗口
        t_obj.insert("s23_s",settingNamespace::settingList[i].s23_s); //剥除附加信息

        //======选项卡：环境文件夹======
        QJsonArray t_s31_sourceFolders;
        for(unsigned int a = 0; a<settingNamespace::settingList[i].s31_sourceFolders.length(); a++){
            t_s31_sourceFolders.append(QString(settingNamespace::settingList[i].s31_sourceFolders[a]).replace(System_OS::getaApplicationDirPath_EX(),RUN_PATH_SIGN));
        }
        t_obj.insert("s31_sourceFolders",t_s31_sourceFolders); //源文件夹列表

        QJsonArray t_s32_staticFolders;
        for(unsigned int a = 0; a<settingNamespace::settingList[i].s32_staticFolders.length(); a++){
            t_s32_staticFolders.append(QString(settingNamespace::settingList[i].s32_staticFolders[a]).replace(System_OS::getaApplicationDirPath_EX(),RUN_PATH_SIGN));
        }
        t_obj.insert("s32_staticFolders",t_s32_staticFolders); //源文件夹列表

        //======选项卡：编译套件信息======
        QJsonObject t_s4_compileMsg;
        t_s4_compileMsg.insert("fp_gcc",QString(settingNamespace::settingList[i].s4_compileMsg.fp_gcc).replace(System_OS::getaApplicationDirPath_EX(),RUN_PATH_SIGN));
        t_s4_compileMsg.insert("fp_gpp",QString(settingNamespace::settingList[i].s4_compileMsg.fp_gpp).replace(System_OS::getaApplicationDirPath_EX(),RUN_PATH_SIGN));
        t_s4_compileMsg.insert("fp_make",QString(settingNamespace::settingList[i].s4_compileMsg.fp_make).replace(System_OS::getaApplicationDirPath_EX(),RUN_PATH_SIGN));
        t_s4_compileMsg.insert("fp_gdb",QString(settingNamespace::settingList[i].s4_compileMsg.fp_gdb).replace(System_OS::getaApplicationDirPath_EX(),RUN_PATH_SIGN));
        t_s4_compileMsg.insert("fp_gdbServer",QString(settingNamespace::settingList[i].s4_compileMsg.fp_gdbServer).replace(System_OS::getaApplicationDirPath_EX(),RUN_PATH_SIGN));
        t_s4_compileMsg.insert("fp_windres",QString(settingNamespace::settingList[i].s4_compileMsg.fp_windres).replace(System_OS::getaApplicationDirPath_EX(),RUN_PATH_SIGN));
        t_obj.insert("s4_compileMsg",t_s4_compileMsg);

        //======选项卡：输出======
        t_obj.insert("s5_rbPreprocessingOnly",settingNamespace::settingList[i].s5_rbPreprocessingOnly); //在完成预处理后停止编译
        t_obj.insert("s5_rbCompilationProperOnly",settingNamespace::settingList[i].s5_rbCompilationProperOnly); //在生成汇编代码后停止
        t_obj.insert("s5_rbGenerateExecutable",settingNamespace::settingList[i].s5_rbGenerateExecutable); //链接得到可执行文件
        t_obj.insert("s5_txtPreprocessingSuffix",settingNamespace::settingList[i].s5_txtPreprocessingSuffix); //预处理输出后缀
        t_obj.insert("s5_txtCompilationSuffix",settingNamespace::settingList[i].s5_txtCompilationSuffix); //汇编输出后缀
        t_obj.insert("s5_txtExecutableSuffix",settingNamespace::settingList[i].s5_txtExecutableSuffix); //可执行文件后缀
        t_obj.insert("s5_cbBinarySuffix",settingNamespace::settingList[i].s5_cbBinarySuffix); //二进制文件类型

        //======选项卡：步骤======
        t_obj.insert("s61_useComposeBefore",settingNamespace::settingList[i].s61_useComposeBefore);    //开启编译前命令
        t_obj.insert("s61_useComposeFinish",settingNamespace::settingList[i].s61_useComposeFinish);    //开启编译后命令
        t_obj.insert("s61_useComposeError",settingNamespace::settingList[i].s61_useComposeError);       //开启编译错误时命令
        t_obj.insert("s61_composeBeforeEditor",settingNamespace::settingList[i].s61_composeBeforeEditor); //编译前命令
        t_obj.insert("s61_composeFinishEditor",settingNamespace::settingList[i].s61_composeFinishEditor); //编译后命令
        t_obj.insert("s61_composeErrorEditor",settingNamespace::settingList[i].s61_composeErrorEditor);   //编译错误时命令
        t_obj.insert("s61_useRunBefore",settingNamespace::settingList[i].s61_useRunBefore);    //开启运行前命令
        t_obj.insert("s61_useRunFinish",settingNamespace::settingList[i].s61_useRunFinish);    //开启运行后命令
        t_obj.insert("s61_useRunError",settingNamespace::settingList[i].s61_useRunError);       //开启运行错误时命令
        t_obj.insert("s61_runBeforeEditor",settingNamespace::settingList[i].s61_runBeforeEditor); //运行前命令
        t_obj.insert("s61_runFinishEditor",settingNamespace::settingList[i].s61_runFinishEditor); //运行后命令
        t_obj.insert("s61_runErrorEditor",settingNamespace::settingList[i].s61_runErrorEditor);  //运行错误时命令

        t_jsonArray.append(t_obj);
    }
    t_jsonObj.insert("list",t_jsonArray);
    t_jsonDocument.setObject(t_jsonObj);
    return t_jsonDocument.toJson();
}

//把json文本载入为设置信息
void Form_settings_Compile::loadSetting(QString jsonStr)
{
    QJsonDocument t_jsonDocument = QJsonDocument::fromJson(jsonStr.toUtf8());
    if(t_jsonDocument.isEmpty()) return;
    QJsonObject t_jsonObjRoot = t_jsonDocument.object(); //获取根对象
    QString t_currentSelectStr = t_jsonObjRoot.value("select").toString(); //保存当前的选中
    QJsonArray t_jsonList = t_jsonObjRoot.value("list").toArray();
    if(t_jsonList.isEmpty() || t_currentSelectStr.isEmpty()){
        settingNamespace::settingList.clear(); //删除全部列表内容，从json重新载入
        return;
    }

    //读取并且载入设置信息
    for(QJsonValue value : t_jsonList){
        QJsonObject t_obj = value.toObject();
        settingNamespace::settingNode t_node;

        //读取并且载入设置信息
        t_node.name = t_obj.value("name").toString();


        //======选项卡：基本选项======
        t_node.s1_usingStatic = t_obj.value("s1_usingStatic").toBool(false); //使用静态链接方式链接库文件
        t_node.s1_usCompile = t_obj.value("s1_usCompile").toBool(false); //编译时加入下列信息
        t_node.s1_otherCompile = t_obj.value("s1_otherCompile").toString(""); //编译附加信息
        t_node.s1_usLink = t_obj.value("s1_usLink").toBool(false); //链接时加入下列选项
        t_node.s1_otherLinke = t_obj.value("s1_otherLinke").toString(""); //链接附加信息

        //======选项卡：编译/链接选项 -> 代码生成======
        t_node.s21_opLevel = t_obj.value("s21_opLevel").toString(""); //优化级别
        t_node.s21_cppStd = t_obj.value("s21_cppStd").toString(""); //Cpp语言标准
        t_node.s21_cStd = t_obj.value("s21_cStd").toString(""); //C语言标准
        t_node.s21_specificInstruct = t_obj.value("s21_specificInstruct").toString(""); //启用特定指令集
        t_node.s21_bit = t_obj.value("s21_bit").toString(""); //使用特定指针大小编译，64位或32位
        t_node.s21_compileMod = t_obj.value("s21_compileMod").toString("Debug"); //编译的模
        t_node.s21_tepOpt = t_obj.value("s21_tepOpt").toBool(true); //快速编译
        t_node.s21_enableThread = t_obj.value("s21_enableThread").toBool(true); //多线程编译

        //======选项卡：编译/链接选项 -> 代码警告======
        t_node.s22_ignoreAllWaring = t_obj.value("s22_ignoreAllWaring").toBool(false);//忽略所有警告信息
        t_node.s22_wall = t_obj.value("s22_wall").toBool(false); //启用常见问题警告
        t_node.s22_wextra = t_obj.value("s22_wextra").toBool(false); //启用更多问题警告
        t_node.s22_checkComplyIsoCppStd = t_obj.value("s22_checkComplyIsoCppStd").toBool(false); //检查是否严格遵守ISO C/C++标准
        t_node.s22_werror = t_obj.value("s22_werror").toBool(false); //将警告视为错误处理
        t_node.s22_wfatalErrors = t_obj.value("s22_wfatalErrors").toBool(false); //遇到第一个错误后立即中止编译
        t_node.s22_fstackProtector = t_obj.value("s22_fstackProtector").toString(""); //检查栈溢出错误

        //======选项卡：编译/链接选项 -> 链接器======
        t_node.s23_pipe = t_obj.value("s23_pipe").toBool(false); //编译时使用管道而不是临时文件
        t_node.s23_nostdlib = t_obj.value("s23_nostdlib").toBool(false); //不适用标准库和系统启动文件
        t_node.s23_mwindows = t_obj.value("s23_mwindows").toBool(false); //不产生控制台窗口
        t_node.s23_s = t_obj.value("s23_s").toBool(false); //剥除附加信息

        //======选项卡：环境文件夹======
        QJsonArray t_s31_sourceFolders = t_obj.value("s31_sourceFolders").toArray(); //源文件夹列表
        for(unsigned int a = 0; a<t_s31_sourceFolders.size(); a++){
            t_node.s31_sourceFolders.append(t_s31_sourceFolders.at(a).toString().replace(RUN_PATH_SIGN,System_OS::getaApplicationDirPath_EX()));
        }

        QJsonArray t_s32_staticFolders = t_obj.value("s32_staticFolders").toArray(); //静态文件夹列表
        for(unsigned int a = 0; a<t_s32_staticFolders.size(); a++){
            t_node.s32_staticFolders.append(t_s32_staticFolders.at(a).toString().replace(RUN_PATH_SIGN,System_OS::getaApplicationDirPath_EX()));
        }

        //======选项卡：编译套件信息======
        QJsonObject t_s4_compileMsg = t_obj.value("s4_compileMsg").toObject();

        t_node.s4_compileMsg.fp_gcc = t_s4_compileMsg.value("fp_gcc").toString().replace(RUN_PATH_SIGN,System_OS::getaApplicationDirPath_EX());
        t_node.s4_compileMsg.fp_gpp = t_s4_compileMsg.value("fp_gpp").toString().replace(RUN_PATH_SIGN,System_OS::getaApplicationDirPath_EX());
        t_node.s4_compileMsg.fp_make = t_s4_compileMsg.value("fp_make").toString().replace(RUN_PATH_SIGN,System_OS::getaApplicationDirPath_EX());
        t_node.s4_compileMsg.fp_gdb = t_s4_compileMsg.value("fp_gdb").toString().replace(RUN_PATH_SIGN,System_OS::getaApplicationDirPath_EX());
        t_node.s4_compileMsg.fp_gdbServer = t_s4_compileMsg.value("fp_gdbServer").toString().replace(RUN_PATH_SIGN,System_OS::getaApplicationDirPath_EX());
        t_node.s4_compileMsg.fp_windres = t_s4_compileMsg.value("fp_windres").toString().replace(RUN_PATH_SIGN,System_OS::getaApplicationDirPath_EX());

        //======选项卡：输出======
        t_node.s5_rbPreprocessingOnly = t_obj.value("s5_rbPreprocessingOnly").toBool(false); //在完成预处理后停止编译
        t_node.s5_rbCompilationProperOnly = t_obj.value("s5_rbCompilationProperOnly").toBool(false); //在生成汇编代码后停止
        t_node.s5_rbGenerateExecutable = t_obj.value("s5_rbGenerateExecutable").toBool(true); //链接得到可执行文件
        t_node.s5_txtPreprocessingSuffix = t_obj.value("s5_txtPreprocessingSuffix").toString(); //预处理输出后缀
        t_node.s5_txtCompilationSuffix = t_obj.value("s5_txtCompilationSuffix").toString(); //汇编输出后缀
        t_node.s5_txtExecutableSuffix = t_obj.value("s5_txtExecutableSuffix").toString(); //可执行文件后缀
        t_node.s5_cbBinarySuffix = t_obj.value("s5_cbBinarySuffix").toString(); //二进制文件类型

        //======选项卡：步骤======
        t_node.s61_useComposeBefore = t_obj.value("s61_useComposeBefore").toBool(false);    //开启编译前命令
        t_node.s61_useComposeFinish = t_obj.value("s61_useComposeFinish").toBool(false);    //开启编译后命令
        t_node.s61_useComposeError = t_obj.value("s61_useComposeError").toBool(true);       //开启编译错误时命令
        t_node.s61_composeBeforeEditor = t_obj.value("s61_composeBeforeEditor").toString(); //编译前命令
        t_node.s61_composeFinishEditor = t_obj.value("s61_composeFinishEditor").toString(); //编译后命令
        t_node.s61_composeErrorEditor = t_obj.value("s61_composeErrorEditor").toString();   //编译错误时命令
        t_node.s61_useRunBefore = t_obj.value("s61_useRunBefore").toBool(false);    //开启运行前命令
        t_node.s61_useRunFinish = t_obj.value("s61_useRunFinish").toBool(false);    //开启运行后命令
        t_node.s61_useRunError = t_obj.value("s61_useRunError").toBool(true);       //开启运行错误时命令
        t_node.s61_runBeforeEditor = t_obj.value("s61_runBeforeEditor").toString(); //运行前命令
        t_node.s61_runFinishEditor = t_obj.value("s61_runFinishEditor").toString(); //运行后命令
        t_node.s61_runErrorEditor  = t_obj.value("s61_runErrorEditor").toString();  //运行错误时命令

        settingNamespace::settingList.append(t_node);
    }

    if(!t_currentSelectStr.isEmpty()){
        for(uint16_t i = 0; i < settingNamespace::settingList.length(); i++){
            if(settingNamespace::settingList[i].name == t_currentSelectStr){
                settingNamespace::compilerIndex = i;
                break;
            }
        }
    }
}



//获取当前的编译节点信息
settingNamespace::settingNode Form_settings_Compile::getNowCompilerNode()
{
    if(settingNamespace::compilerIndex < 0 || settingNamespace::compilerIndex >= settingNamespace::settingList.length()){
        return settingNamespace::settingNode();
    }
    return settingNamespace::settingList[settingNamespace::compilerIndex];
}



//查找编译器是否存在
void Form_settings_Compile::on_btnFindCompilers_clicked()
{
    QString gcc_path = System_Env::getProgramPathForEnvVar("g++");
    if(!gcc_path.isEmpty()){
        QString t_name = this->getGppMsg(gcc_path);
        if(!t_name.isEmpty()){
            QString t_path = QFileInfo(gcc_path).path(); //保存文件夹路径
            QDir dir(t_path);
            if(dir.cdUp()){  //退到上级目录，扫描GCC编译文件
                 t_path = dir.absolutePath();
            }
            settingNamespace::settingNode node;
            this->findGccCompile(t_path,&node.s4_compileMsg); //这里根据路径再次扫描了
            node.name = t_name;
            node.s31_sourceFolders = node.s4_compileMsg.folderList; //将信息传递给源文件夹列表保存
            node.s4_compileMsg.folderList.clear(); //清理扫描的列表
            this->addSettingSignNode(node);
            this->updateCompilerUI();
        }
    }
}


//选择文件夹，查询编译器
void Form_settings_Compile::on_btnAddCompilerSetByFolder_clicked()
{
    QString t_dirPath = QFileDialog::getExistingDirectory(this, tr("选择编译器根目录"), "", QFileDialog::ShowDirsOnly);
    if(t_dirPath.isEmpty()) return;

    settingNamespace::compileMsg t_msg;
    this->findGccCompile(t_dirPath,&t_msg); //查找GCC编译套件
    if(t_msg.fp_gpp.isEmpty() || t_msg.fp_gcc.isEmpty()) return; //如果无法扫描编译器，则直接返回

    settingNamespace::settingNode node;
    node.s4_compileMsg = t_msg;
    node.name = this->getGppMsg(t_msg.fp_gpp);
    this->getNotRepeatName(node.name); //去除重名
    node.s31_sourceFolders = node.s4_compileMsg.folderList; //将信息传递给源文件夹列表保存
    node.s4_compileMsg.folderList.clear(); //清理扫描的列表
    this->addSettingSignNode(node);
    this->updateCompilerUI();
}


//更改套件名称
void Form_settings_Compile::on_btnRenameCompilerSet_clicked()
{
    if(settingNamespace::compilerIndex < 0 || settingNamespace::compilerIndex >= settingNamespace::settingList.length()){return;}
    QString t_newNAme = QInputDialog::getText(this, tr("方案名称"), tr("新的方案名称:"), QLineEdit::Normal, settingNamespace::settingList[settingNamespace::compilerIndex].name);
    if(!t_newNAme.isEmpty()){
        this->getNotRepeatName(t_newNAme);
        settingNamespace::settingList[settingNamespace::compilerIndex].name = t_newNAme;
    }
    this->updateCompilerUI();
}

//移除编译套件
void Form_settings_Compile::on_btnRemoveCompilerSet_clicked()
{
    if(settingNamespace::compilerIndex < 0 || settingNamespace::compilerIndex >= settingNamespace::settingList.length()){return;}
    settingNamespace::settingList.remove(settingNamespace::compilerIndex);
    settingNamespace::compilerIndex = settingNamespace::settingList.length() - 1; //选择新的套件索引
    this->updateCompilerUI();
}

//添加新的套件
void Form_settings_Compile::on_btnAddBlankCompilerSet_clicked()
{
    settingNamespace::settingNode node;
    node.name = tr("新构建方案");
    this->getNotRepeatName(node.name);
    this->addSettingSignNode(node);
    settingNamespace::compilerIndex = settingNamespace::settingList.length() - 1; //选择新的套件索引
    this->updateCompilerUI();
}


//更改当前索引,使用代码更改index不会激发
void Form_settings_Compile::on_cbCompilerSet_activated(int index)
{
    //隐藏版本信息
    ui->label_tip_c->hide();
    ui->label_tip_cpp->hide();
    ui->label_tip_make->hide();
    ui->label_tip_gdb->hide();
    ui->label_tip_gdbServer->hide();
    ui->label_tip_windres->hide();

    settingNamespace::compilerIndex = index;
    if(settingNamespace::compilerIndex < 0 || settingNamespace::compilerIndex >= settingNamespace::settingList.length()){
        ui->cbCompilerSet->setCurrentIndex(0);
        return;
    }
    this->updateCompilerUI(); //刷新UI
}

//验证GCC套件
void Form_settings_Compile::on_s4_check_clicked()
{
    QString t_v;

    //隐藏版本信息
    ui->label_tip_c->hide();
    ui->label_tip_cpp->hide();
    ui->label_tip_make->hide();
    ui->label_tip_gdb->hide();
    ui->label_tip_gdbServer->hide();
    ui->label_tip_windres->hide();

    threadNum = 0;//当前线程完成数为0
    ui->s4_check->setEnabled(false);
    ui->s4_check->setText(tr("正在验证"));

    //查看版本,多线程检查
    this->processVersionThread([this](){
        QString t_v = this->getProcessVersion(ui->s4_txtCCompiler->text());
        if(!t_v.isEmpty()){ui->label_tip_c->setText(t_v);ui->label_tip_c->show();}
    });

    this->processVersionThread([this](){
        QString t_v = this->getProcessVersion(ui->s4_txtCppCompiler->text());
        if(!t_v.isEmpty()){ui->label_tip_cpp->setText(t_v);ui->label_tip_cpp->show();}
    });

    this->processVersionThread([this](){
        QString t_v = this->getProcessVersion(ui->s4_txtMake->text());
        if(!t_v.isEmpty()){ui->label_tip_make->setText(t_v);ui->label_tip_make->show();}
    });

    this->processVersionThread([this](){
        QString t_v = this->getProcessVersion(ui->s4_txtGDB->text());
        if(!t_v.isEmpty()){ui->label_tip_gdb->setText(t_v);ui->label_tip_gdb->show();}
    });

    this->processVersionThread([this](){
        QString t_v = this->getProcessVersion(ui->s4_txtGDBServer->text());
        if(!t_v.isEmpty()){ui->label_tip_gdbServer->setText(t_v);ui->label_tip_gdbServer->show();}
    });

    this->processVersionThread([this](){
        QString t_v = this->getProcessVersion(ui->s4_txtResourceCompiler->text());
        if(!t_v.isEmpty()){ui->label_tip_windres->setText(t_v);ui->label_tip_windres->show();}
    });
}


//确认键被按下，会率先激发应用事件
void Form_settings_Compile::Event_Ok()
{
    //保存文件
    QString t_out = buildJson();
    if(!t_out.isEmpty()){
        System_File::writeFile(OUTSETFILE,t_out.toUtf8());
    }
}

//取消键被按下
void Form_settings_Compile::Event_cancel()
{

}

//应用键被按下
void Form_settings_Compile::Event_use()
{
    if(settingNamespace::compilerIndex < 0 || settingNamespace::compilerIndex >= settingNamespace::settingList.length()){
        return;
    }
    settingNamespace::settingNode node = settingNamespace::settingList[settingNamespace::compilerIndex]; //获取当前的节点信息

    //选项卡：基本设置
    node.s1_usingStatic = ui->s1_usingStatic->isChecked();
    node.s1_usCompile = ui->s1_usCompile->isChecked();
    node.s1_otherCompile = ui->s1_otherCompile->toPlainText();
    node.s1_usLink = ui->s1_usLink->isChecked();
    node.s1_otherLinke = ui->s1_otherLinke->toPlainText();

    //选项卡：编译/链接选项 -> 代码生成
    node.s21_opLevel = ui->s21_opLevel->currentText();
    node.s21_cppStd = ui->s21_cppStd->currentText();
    node.s21_cStd = ui->s21_cStd->currentText();
    node.s21_specificInstruct = ui->s21_specificInstruct->currentText();
    node.s21_bit = ui->s21_bit->currentText();
    node.s21_compileMod = ui->s21_compileMod->currentText();
    node.s21_tepOpt = ui->s21_tepOpt->isChecked();
    node.s21_enableThread = ui->s21_enableThread->isChecked();
    //选项卡：编译/链接选项 -> 代码警告
    node.s22_ignoreAllWaring = ui->s22_ignoreAllWaring->isChecked();
    node.s22_wall = ui->s22_wall->isChecked();
    node.s22_wextra = ui->s22_wextra->isChecked();
    node.s22_checkComplyIsoCppStd = ui->s22_checkComplyIsoCppStd->isChecked();
    node.s22_werror = ui->s22_werror->isChecked();
    node.s22_wfatalErrors = ui->s22_wfatalErrors->isChecked();
    node.s22_fstackProtector = ui->s22_fstackProtector->currentText();
    //选项卡：编译/链接选项 -> 链接器
    node.s23_pipe = ui->s23_pipe->isChecked();
    node.s23_nostdlib = ui->s23_nostdlib->isChecked();
    node.s23_mwindows = ui->s23_mwindows->isChecked();
    node.s23_s = ui->s23_s->isChecked();

    //选项卡：环境文件夹
    node.s31_sourceFolders = ui->s31_sourceFolders->getList();
    node.s32_staticFolders = ui->s32_staticFolders->getList();

    //选项卡：编译套件信息
    node.s4_compileMsg.fp_gcc = ui->s4_txtCCompiler->text();
    node.s4_compileMsg.fp_gpp = ui->s4_txtCppCompiler->text();
    node.s4_compileMsg.fp_make = ui->s4_txtMake->text();
    node.s4_compileMsg.fp_gdb = ui->s4_txtGDB->text();
    node.s4_compileMsg.fp_gdbServer = ui->s4_txtGDBServer->text();
    node.s4_compileMsg.fp_windres = ui->s4_txtResourceCompiler->text();

    //选项卡：输出
    node.s5_rbPreprocessingOnly = ui->s5_rbPreprocessingOnly->isChecked();
    node.s5_rbCompilationProperOnly = ui->s5_rbCompilationProperOnly->isChecked();
    node.s5_rbGenerateExecutable = ui->s5_rbGenerateExecutable->isChecked();
    node.s5_txtPreprocessingSuffix = ui->s5_txtPreprocessingSuffix->text();
    node.s5_txtCompilationSuffix = ui->s5_txtCompilationSuffix->text();
    node.s5_txtExecutableSuffix = ui->s5_txtExecutableSuffix->text();
    node.s5_cbBinarySuffix = ui->s5_cbBinarySuffix->currentText();

    //选项卡：步骤
    node.s61_useComposeBefore = ui->s61_useComposeBefore->isChecked();          //开启编译前命令
    node.s61_useComposeFinish = ui->s61_useComposeFinish->isChecked();          //开启编译后命令
    node.s61_useComposeError = ui->s61_useComposeError->isChecked();            //开启编译错误时命令
    node.s61_composeBeforeEditor = ui->s61_composeBeforeEditor->toPlainText();  //编译前命令
    node.s61_composeFinishEditor = ui->s61_composeFinishEditor->toPlainText();  //编译后命令
    node.s61_composeErrorEditor = ui->s61_composeErrorEditor->toPlainText();    //编译错误时命令
    node.s61_useRunBefore = ui->s61_useRunBefore->isChecked();          //开启运行前命令
    node.s61_useRunFinish = ui->s61_useRunFinish->isChecked();          //开启运行后命令
    node.s61_useRunError =  ui->s61_useRunError->isChecked();           //开启运行错误时命令
    node.s61_runBeforeEditor = ui->s61_runBeforeEditor->toPlainText();; //运行前命令
    node.s61_runFinishEditor = ui->s61_runFinishEditor->toPlainText();; //运行后命令
    node.s61_runErrorEditor = ui->s61_runErrorEditor->toPlainText();;   //运行错误时命令

    //重新应用更改
    settingNamespace::settingList[settingNamespace::compilerIndex] = node; //重新应用更改
}


//C编译器选择
void Form_settings_Compile::on_s4_btnChooseCCompiler_clicked()
{
    QString t_fileName = QFileDialog::getOpenFileName(nullptr, tr("选择程序"), "", tr("所有文件 (*)"));
    if(t_fileName.isEmpty()) return;
    ui->s4_txtCCompiler->setText(t_fileName);
}

//CPP编译器选择
void Form_settings_Compile::on_s4_btnChooseCppCompiler_clicked()
{
    QString t_fileName = QFileDialog::getOpenFileName(nullptr, tr("选择程序"), "", tr("所有文件 (*)"));
    if(t_fileName.isEmpty()) return;
    ui->s4_txtCppCompiler->setText(t_fileName);
}

//Make选择
void Form_settings_Compile::on_s4_btnChooseMake_clicked()
{
    QString t_fileName = QFileDialog::getOpenFileName(nullptr, tr("选择程序"), "", tr("所有文件 (*)"));
    if(t_fileName.isEmpty()) return;
    ui->s4_txtMake->setText(t_fileName);
}

//Gdb选择
void Form_settings_Compile::on_s4_btnChooseGDB_clicked()
{
    QString t_fileName = QFileDialog::getOpenFileName(nullptr, tr("选择程序"), "", tr("所有文件 (*)"));
    if(t_fileName.isEmpty()) return;
    ui->s4_txtGDB->setText(t_fileName);
}

//GdbServer选择
void Form_settings_Compile::on_s4_btnChooseGDBServer_clicked()
{
    QString t_fileName = QFileDialog::getOpenFileName(nullptr, tr("选择程序"), "", tr("所有文件 (*)"));
    if(t_fileName.isEmpty()) return;
    ui->s4_txtGDBServer->setText(t_fileName);
}

//ResourceCompiler选择
void Form_settings_Compile::on_s4_btnChooseResourceCompiler_clicked()
{
    QString t_fileName = QFileDialog::getOpenFileName(nullptr, tr("选择程序"), "", tr("所有文件 (*)"));
    if(t_fileName.isEmpty()) return;
    ui->s4_txtResourceCompiler->setText(t_fileName);
}

