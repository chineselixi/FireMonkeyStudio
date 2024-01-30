#include "Form_New.h"
#include "ui_Form_New.h"

#include "../Widget/Widget_Button_ListItem.h"
#include "../Widget/Widget_Button_ModHistoryItem.h"
#include "../Widget/Widget_Button_ModItem.h"
#include "../Window/Form_WorkSpace.h"

#include "../SwSystem/System_History.h"
#include "../SwSystem/System_GlobalVar.h"
#include "../SwSystem/System_UtilFun.h"

#include "QStandardPaths"
#include "QDir"
#include "QFileDialog"
#include "QMessageBox"
#include "QJsonDocument"
#include "QJsonObject"

Form_New::Form_New(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_New)
{
    ui->setupUi(this);
    //this->setFixedHeight(782);
    //this->setFixedWidth(1113);

    //选择第一个界面
    ui->stackedWidget->setCurrentIndex(0);


    ui->Btn_OpenProject->SetIcon(QPixmap(":/WidgetIcon/icon/WidgetIcon/newCreate/open1.png"));
    ui->Btn_OpenProject->SetTitle("打开项目或解决方案");
    ui->Btn_OpenProject->SetTip("打开本地的FireMonkey项目或.fmp文件");

    ui->Btn_OpenDir->SetIcon(QPixmap(":/WidgetIcon/icon/WidgetIcon/newCreate/dir1.png"));
    ui->Btn_OpenDir->SetTitle("打开本地文件夹");
    ui->Btn_OpenDir->SetTip("导航和编辑任何文件夹中的代码");

    ui->Btn_CreateProject->SetIcon(QPixmap(":/WidgetIcon/icon/WidgetIcon/newCreate/create1.png"));
    ui->Btn_CreateProject->SetTitle("创建项目");
    ui->Btn_CreateProject->SetTip("从模板中创建具有基础框架的项目");

    ui->Btn_FromGit->SetIcon(QPixmap(":/WidgetIcon/icon/WidgetIcon/newCreate/clone1.png"));
    ui->Btn_FromGit->SetTitle("从存储库构建");
    ui->Btn_FromGit->SetTip("从GitHub或Gitee等联机存储库获取代码");


    //使用信号槽机制绑定按钮
    connect(ui->Btn_OpenProject,&Widget_Button_Start::onDown,this,&Form_New::OnBtnOpenDuwn);
    connect(ui->Btn_OpenDir,&Widget_Button_Start::onDown,this,&Form_New::OnBtnOpenDirDuwn);
    connect(ui->Btn_CreateProject,&Widget_Button_Start::onDown,this,&Form_New::OnBtnCreateDuwn);
    connect(ui->Btn_FromGit,&Widget_Button_Start::onDown,this,&Form_New::OnBtnGitDown);



    //初始文本框显示的路径
    QStringList t_docPaths = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation);
    QString t_docPath = t_docPaths.isEmpty() ? QDir::homePath() : t_docPaths.first();
    ui->lineEdit_Path->setText(t_docPath);
    ui->lineEdit_Path_3->setText(t_docPath);


    //鼠标点击了标签，使用事件过滤器
    ui->label_Jump->installEventFilter(this);


    //最近列表的项目被按下
//    connect(ui->listWidget_ProjectList,&QListWidget::itemClicked,[this](QListWidgetItem * item){

//        //
//    });

    //历史工程检索，信息倒装，最后的信息在最前面显示
    if(HistoryList::sys_proHistory == nullptr) return;
    auto t_hisList = HistoryList::sys_proHistory->getHisList();
    for(int a = t_hisList.length()-1;a>=0;a--){
        if(!QFile(t_hisList[a].filePath).exists()){
            HistoryList::sys_proHistory->removeProHisList(t_hisList[a].filePath);
            continue;//如果文件不存在，则直接跳过
        }

        QListWidgetItem* listItem = new QListWidgetItem(ui->listWidget_ProjectList);
        Widget_Button_ListItem* itemWidget = new Widget_Button_ListItem(ui->listWidget_ProjectList);
        itemWidget->SetTitle(t_hisList[a].showName);
        itemWidget->SetTip(t_hisList[a].filePath);
        itemWidget->SetDate(t_hisList[a].other);
        itemWidget->SetIcon(QPixmap(t_hisList[a].showIco));
        ui->listWidget_ProjectList->addItem(listItem);
        listItem->setSizeHint(QSize(100,65));
        ui->listWidget_ProjectList->setItemWidget(listItem,itemWidget);

        QString t_path = t_hisList[a].filePath;
        connect(itemWidget,&Widget_Button_ListItem::onDown,this,[t_path,this](){
            ProjectOpen::projectPath = t_path; //工程路径
            if(Window::workSpace == nullptr){
                Window::workSpace = new Form_WorkSpace;
                Window::workSpace->show();
            }
            Window::workSpace->loadProject(); //加载工程
            this->close(); //关闭当前窗口
        });
    }




    //最近模板检索
    auto t_modHisList = HistoryList::sys_modHistory->getHisList();
    //加入最近模板列表,模板信息倒装，最后的信息在最前面
    for(int a = t_modHisList.length()-1;a>=0;a--){
        if(!QFile(t_modHisList[a].filePath.replace("<modPath>",QCoreApplication::applicationDirPath())).exists()){
            HistoryList::sys_modHistory->removeProHisList(t_modHisList[a].filePath);
            continue;//如果文件不存在，则直接跳过
        }

        //创建模板历史项目
        QListWidgetItem* t_listItem = new QListWidgetItem(ui->listWidget_ModHistory);
        Widget_Button_ModHistoryItem* t_itemWidget = new Widget_Button_ModHistoryItem(ui->listWidget_ModHistory);
        ui->listWidget_ModHistory->addItem(t_listItem);
        ui->listWidget_ModHistory->setItemWidget(t_listItem,t_itemWidget);
        t_listItem->setSizeHint(QSize(100,42));

        //将相对目录替换为自身目录
        QString t_modFilePath = t_modHisList[a].filePath;
        t_modFilePath = t_modFilePath.replace("<modPath>",QCoreApplication::applicationDirPath());

        //读取历史模板的信息
        t_itemWidget->SetIcon(QPixmap(QPixmap(QFileInfo(t_modFilePath).path() + "/ico.png")));
        t_itemWidget->SetTitle(t_modHisList[a].showName);
        t_itemWidget->SetModStr(t_modHisList[a].other); //这里显示的是编程语言

        connect(t_itemWidget,&Widget_Button_ModHistoryItem::onDown,this,[t_modFilePath,this,t_listItem](){
            this->modFilePath = t_modFilePath;
            QJsonDocument t_jsonDoc = QJsonDocument::fromJson(System_File::readFile(this->modFilePath));
            QJsonObject t_jsonObj = t_jsonDoc.object();
            this->modName = t_jsonObj.value("proName").toString("SystemError"); //模板名称（也是默认的工程名称）
            this->modLang = t_jsonObj.value("proLanguage").toString("other"); //模板语言

            ui->pushButton_next_toCreate->setEnabled(true); //允许工程创建工程文件
            t_listItem->setSelected(true);
            ui->listWidget_ModList->clearSelection(); //清空模板所有的选项
        });
    }


    //扫描本地模板
    QVector<QString> t_profileList;
    QString t_path = QCoreApplication::applicationDirPath() + "/proModel";
    t_profileList.clear(); //清理数据
    this->findMod(t_path,t_profileList); //查找信息
    QVector<QString> t_mod_system; //系统模块列表
    QVector<QString> t_mod_lang; //语言分类列表
    QVector<QString> t_mod_noteClass; //其他分类列表

    this->modMsgList.clear();//清空模块列表

    //加入模板列表
    for(int a = 0;a<t_profileList.length();a++){
        modListMsg t_modMsg;
        t_modMsg.fmpPath = t_profileList[a]; //配置文件名

        QJsonDocument t_jsonDoc = QJsonDocument::fromJson(System_File::readFile(t_modMsg.fmpPath));
        QJsonObject t_jsonObj = t_jsonDoc.object();

        t_modMsg.modNmae = t_jsonObj.value("proName").toString(); //模板名称（也是默认的工程名称）
        t_modMsg.modTip = t_jsonObj.value("proNote").toString(); //模板提示，也是工程提示
        t_modMsg.modLang = t_jsonObj.value("proLanguage").toString(); //模板语言
        t_modMsg.modSystem = t_jsonObj.value("proSystem").toString(); //模板系统
        t_modMsg.modNoteClass = t_jsonObj.value("proNoteClass").toString(); //模板其他分类
        this->modMsgList.append(t_modMsg); //加入工程模板信息


        QListWidgetItem* t_listItem = new QListWidgetItem(ui->listWidget_ModList);
        Widget_Button_ModItem* t_itemWidget = new Widget_Button_ModItem(ui->listWidget_ModList);
        ui->listWidget_ModList->addItem(t_listItem);
        ui->listWidget_ModList->setItemWidget(t_listItem,t_itemWidget);
        t_listItem->setSizeHint(QSize(300,74));

        t_itemWidget->SetIcon(QPixmap(QFileInfo(t_modMsg.fmpPath).path() + "/ico.png")); //图标文件
        t_itemWidget->SetTitle(t_modMsg.modNmae);
        t_itemWidget->SetTip(t_modMsg.modTip);
        t_itemWidget->SetOsTip(t_modMsg.modSystem);
        t_itemWidget->SetLangTip(t_modMsg.modLang);
        t_itemWidget->SetOtherTip(t_modMsg.modNoteClass);

        connect(t_itemWidget,&Widget_Button_ModItem::onDown,this,[t_modMsg,this,t_listItem](){ //模板文件
            this->modFilePath = t_modMsg.fmpPath;

            QJsonDocument t_jsonDoc = QJsonDocument::fromJson(System_File::readFile(this->modFilePath));
            QJsonObject t_jsonObj = t_jsonDoc.object();
            this->modName = t_jsonObj.value("proName").toString("SystemError"); //模板名称（也是默认的工程名称）
            this->modLang = t_jsonObj.value("proLanguage").toString("other"); //模板语言

            ui->pushButton_next_toCreate->setEnabled(true); //允许工程创建工程文件
            t_listItem->setSelected(true);
            ui->listWidget_ModHistory->clearSelection(); //清空模板所有的选项
        });

        //配置分类信息
        QStringList t_list;
        t_list = t_modMsg.modLang.split(' ');
        for(int a = 0;a<t_list.length();a++) t_mod_lang.append(t_list[a]);
        t_list = t_modMsg.modSystem.split(' ');
        for(int a = 0;a<t_list.length();a++) t_mod_system.append(t_list[a]);
        t_list = t_modMsg.modNoteClass.split(' ');
        for(int a = 0;a<t_list.length();a++) t_mod_noteClass.append(t_list[a]);
    }
    this->removeRepeat(t_mod_lang); //清除分类的重复信息
    this->removeRepeat(t_mod_system);
    this->removeRepeat(t_mod_noteClass);

    //加入工程分类配置信息
    for(int a=0;a<t_mod_lang.length();a++) if(!t_mod_lang[a].isEmpty()){ui->comboBox_lang->addItem(t_mod_lang[a]);}
    for(int a=0;a<t_mod_system.length();a++) if(!t_mod_system[a].isEmpty()){ui->comboBox_os->addItem(t_mod_system[a]);}
    for(int a=0;a<t_mod_noteClass.length();a++) if(!t_mod_noteClass[a].isEmpty()){ui->comboBox_other->addItem(t_mod_noteClass[a]);}

    this->showItemForClass("","","",""); //筛选信息
}

Form_New::~Form_New()
{   HistoryList::sys_proHistory->clearRepeat();
    HistoryList::sys_proHistory->saveHisList(); //保存工程历史记录
    HistoryList::sys_modHistory->clearRepeat();
    HistoryList::sys_modHistory->saveHisList(); //保存模板历史记录
    delete ui;
}


//事件过滤器，用于判定是否点击了标签
bool Form_New::eventFilter(QObject *obj, QEvent *event)
{
    if(qobject_cast<QLabel*>(obj) == ui->label_Jump && event->type() == QEvent::MouseButtonRelease)
    {
        if(Window::workSpace == nullptr){
            Window::workSpace = new Form_WorkSpace;
            Window::workSpace->show();
        }
        this->close();
        return true;
    }
    return false;
}


//查找模块信息
void Form_New::findMod(QString path, QVector<QString>& retList)
{
    QDir t_dir(path);
    if(!t_dir.exists()) return;
    QFileInfoList t_infoListDir = t_dir.entryInfoList(QDir::Dirs|QDir::NoDotAndDotDot); //只检查有多少目录
    for(int a = 0;a<t_infoListDir.length();a++){
        if(t_infoListDir[a].exists()){
            QDir t_dirFiles(t_infoListDir[a].filePath());
            QFileInfoList t_infoListFile = t_dirFiles.entryInfoList(QDir::Files|QDir::NoDotAndDotDot); //只检查有多少文件
            for(int b = 0;b<t_infoListFile.length();b++){
                if(t_infoListFile[b].isFile() && t_infoListFile[b].fileName() == "pro.fmp"){ //判断是否为工程模板文件
                    retList.append(t_infoListFile[b].absoluteFilePath());
                }
            }
        }
    }
}


//去除列表的重复
void Form_New::removeRepeat(QVector<QString> &strList)
{
    for(int a=strList.length() - 1;a >= 0;a--){
        for (int b = 0; b < a; b++) {
            if(strList[a] == strList[b]){
                strList.removeAt(a);
                break;
            }
        }
    }
}


//筛选item信息
void Form_New::showItemForClass(QString lang, QString os, QString other,QString keyWord)
{
    for(int a = 0;a<this->modMsgList.length();a++){
        ui->listWidget_ModList->item(a)->setHidden(true); //默认为隐藏
        if(!lang.isEmpty()){
            if(this->modMsgList[a].modLang.indexOf(lang,0, Qt::CaseInsensitive) == -1){
                continue;
            }
        }
        if(!os.isEmpty()){
            if(this->modMsgList[a].modSystem.indexOf(os,0, Qt::CaseInsensitive) == -1){
                continue;
            }
        }
        if(!other.isEmpty()){
            if(this->modMsgList[a].modNoteClass.indexOf(other,0, Qt::CaseInsensitive) == -1){
                continue;
            }
        }
        if(!keyWord.isEmpty()){
            if(this->modMsgList[a].modNmae.indexOf(keyWord,0, Qt::CaseInsensitive) == -1 && this->modMsgList[a].modTip.indexOf(keyWord,0, Qt::CaseInsensitive) == -1){
                continue;
            }
        }
        ui->listWidget_ModList->item(a)->setHidden(false); //条件满足则显示
    }
}


//遍历复制文件夹
void Form_New::copyFolder(QString sourceFolder, QString destinationFolder)
{
    QDir sourceDir(sourceFolder);
    QDir destinationDir(destinationFolder);

    if (!destinationDir.exists()) {
        destinationDir.mkpath(destinationFolder); //创建文件夹
    }

    foreach (QFileInfo fileInfo, sourceDir.entryInfoList(QDir::Files)) { //遍历所有文件
        QString destinationFile = destinationFolder + "/" + fileInfo.fileName();
        QFile::copy(fileInfo.filePath(), destinationFile); //复制文件
    }

    foreach (QFileInfo fileInfo, sourceDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) { //遍历所有子文件夹
        QString subFolder = sourceFolder + "/" + fileInfo.fileName();
        QString destinationSubFolder = destinationFolder + "/" + fileInfo.fileName();
        copyFolder(subFolder, destinationSubFolder); //递归复制子文件夹
    }
}


//打开文件被按下
void Form_New::OnBtnOpenDuwn()
{
    QString t_path = QFileDialog::getOpenFileName(this,tr("打开工程文件"),"/Home","工程文件(*.fmp);;所有文件(*.*)");
    if(t_path.isEmpty()) return;
    ProjectOpen::projectPath = t_path; //工程路径

    if(Window::workSpace == nullptr){
        Window::workSpace = new Form_WorkSpace;
        Window::workSpace->show();
    }
    Window::workSpace->loadProject(); //加载工程
    this->close(); //关闭当前窗口
}

//打开文件夹被按下
void Form_New::OnBtnOpenDirDuwn()
{
    QString t_path = QFileDialog::getExistingDirectory(this, tr("选择工程文件夹"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(t_path.isEmpty()) return;
    ProjectOpen::projectPath = t_path; //工程路径
    if(Window::workSpace == nullptr){
        Window::workSpace = new Form_WorkSpace;
        Window::workSpace->show();
    }
    Window::workSpace->loadProject(); //加载工程
    this->close(); //关闭当前窗口
}

//创建项目被按下
void Form_New::OnBtnCreateDuwn()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->comboBox_findMod->setFocus();//获取激活焦点
}

//Git按下
void Form_New::OnBtnGitDown()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit_URL->setFocus();//获取激活焦点
}





//从Git跳转到主界面
void Form_New::on_pushButton_back_toStart_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//从模板列表跳转到主界面
void Form_New::on_pushButton_back_toMain2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//从完成项目创建到转到模板列表
void Form_New::on_pushButton_back_toModList_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



//git路径选择
void Form_New::on_pushButton_git_path_clicked()
{
    QString t_path = QFileDialog::getExistingDirectory(this, tr("选择路径"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(t_path.isEmpty()) return;
    ui->lineEdit_Path->setText(t_path);
}


//根据语言分类
void Form_New::on_comboBox_lang_activated(int index)
{
    if(index <= 0){
        classify_lang = "";
    }
    else{
        classify_lang = ui->comboBox_lang->itemText(index);
    }
    this->showItemForClass(classify_lang,classify_os,classify_other,classify_keyWord);
}

//根据os分类
void Form_New::on_comboBox_os_activated(int index)
{
    if(index <= 0){
        classify_os = "";
    }
    else{
        classify_os = ui->comboBox_os->itemText(index);
    }
    this->showItemForClass(classify_lang,classify_os,classify_other,classify_keyWord);
}

//根据其他信息分类
void Form_New::on_comboBox_other_activated(int index)
{
    if(index <= 0){
        classify_other = "";
    }
    else{
        classify_other = ui->comboBox_other->itemText(index);
    }
    this->showItemForClass(classify_lang,classify_os,classify_other,classify_keyWord);
}


//根据搜索内容改变信息
void Form_New::on_comboBox_findMod_editTextChanged(const QString &arg1)
{
    this->classify_keyWord = arg1;
    this->showItemForClass(classify_lang,classify_os,classify_other,classify_keyWord);
}

//开始构建项目
void Form_New::on_pushButton_next_toCreate_clicked()
{
    if(!QFile(modFilePath).exists()){
        QMessageBox::critical(this,"Error",tr("工程模板文件不存在，无法使用创建项目！"));
        return;
    }

    ui->stackedWidget->setCurrentIndex(3);
    ui->lineEdit_projectName->setFocus();//获取激活焦点
}

//选择文件夹路径
void Form_New::on_pushButton_path_3_clicked()
{
    QString t_path = QFileDialog::getExistingDirectory(this, tr("保存的路径"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(t_path.isEmpty()) return;
    ui->lineEdit_Path_3->setText(t_path);

    if(t_path.isEmpty()){
        ui->pushButton_createProject->setEnabled(false);
    }
    else{
        ui->pushButton_createProject->setEnabled(true);
    }
    ui->label_createTip->setText("");
}

//项目名被改变
void Form_New::on_lineEdit_projectName_textEdited(const QString &arg1)
{
    ui->lineEdit_pathName->setText(arg1);

    if(arg1.isEmpty()){
        ui->pushButton_createProject->setEnabled(false);
    }
    else{
        ui->pushButton_createProject->setEnabled(true);
    }
    ui->label_createTip->setText("");
}

//创建工程按钮被点击
void Form_New::on_pushButton_createProject_clicked()
{
    QString t_modName = QFileInfo(this->modFilePath).fileName(); //基础文件名
    QString t_modPath = QFileInfo(this->modFilePath).path(); //模板工程目录
    QString t_newPath = ui->lineEdit_Path_3->text() + "/" + ui->lineEdit_pathName->text();

    if(ui->lineEdit_projectName->text().isEmpty()){
        ui->label_createTip->setText(tr("工程名不能为空！"));
        return;
    }

    QDir t_dir;
    if(t_dir.mkpath(t_newPath) == false){
        ui->label_createTip->setText(tr("无法创建工程目录！"));
        return;
    }
    Form_New::copyFolder(t_modPath,t_newPath);//创建的工程文件夹


    QString t_proPath = t_newPath + "/" + t_modName;//工程文件的启动文件
    //更改启动文件名称，已废弃，强制要求文件为pro.fmp
    //if(QFile::rename(t_newPath + "/" + t_modName,t_newPath + "/" + ui->lineEdit_projectName->text() + ".fmp")){
    //    t_proPath = t_newPath + "/" + ui->lineEdit_projectName->text() + ".fmp"; //文件修改成功则更名文件信息
    //}


    //更改配置信息
    QJsonDocument t_jsonDoc = QJsonDocument::fromJson(System_File::readFile(t_proPath));
    QJsonObject t_jsonObj = t_jsonDoc.object();
    t_jsonObj.remove("proName");
    t_jsonObj.insert("proName",ui->lineEdit_projectName->text()); //更改工程名
    t_jsonDoc.setObject(t_jsonObj);
    System_File::writeFile(t_proPath,t_jsonDoc.toJson()); //保存Json信息

    //打开工程向导
    QString t_wizard = t_jsonObj.value("proWizard").toString();
    t_wizard = t_wizard.replace("{pwd}",QCoreApplication::applicationDirPath()); //将特程序预先目录替换
    if(!t_wizard.isEmpty()){ //向导存在，不是空白，则运行向导
        if(!QFile(t_wizard).exists()){
            QMessageBox::warning(this, tr("注意"),tr("此工程应该存在工程向导，但是IDE无法找到此向导。工程构建信息可能不可信！"));
        }
        else{ //存在则运行
            QProcess t_pro;
            if(t_pro.execute(t_wizard,{t_proPath}) != 0){ //运行程序
                QMessageBox::warning(this, tr("注意"),tr("工程向导未正常退出，工程构建信息可能不可信！"));
            }
        }
    }

    //工作空间开始加载工程
    ProjectOpen::projectPath = t_proPath; //工程路径，在工作空间加载时读取这个参数
    if(Window::workSpace == nullptr){               //若工作空间窗口未打开，则打开窗口
        Window::workSpace = new Form_WorkSpace;
        Window::workSpace->show();
    }
    Window::workSpace->loadProject(); //加载工程，读取ProjectOpen::projectPath工程


    //保存历史记录
    //保存工程历史
    HistoryList::sys_proHistory->addMsg(ui->lineEdit_projectName->text(),t_newPath + "/ico.png",t_proPath,QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm"));
    HistoryList::sys_proHistory->saveHisList(); //保存历史记录
    //保存模板历史
    QString t_abModPath = t_modPath.replace(QCoreApplication::applicationDirPath(),"<modPath>"); //模板工程的记录采用相对路径
    HistoryList::sys_modHistory->addMsg(this->modName,t_abModPath + "ico.png",this->modFilePath,this->modLang);
    HistoryList::sys_modHistory->clearRepeat(); //清理重复数据
    HistoryList::sys_modHistory->saveHisList(); //保存模板历史记录

    this->close(); //关闭当前窗口
}



//当前界面已经切换事件
void Form_New::on_stackedWidget_currentChanged(int arg1)
{
    if(arg1 == 3){  //如果为新建工程，则默认的标题配置则为工程模板的名称
        QJsonDocument t_jsonDoc = QJsonDocument::fromJson(System_File::readFile(this->modFilePath));
        QJsonObject t_jsonObj = t_jsonDoc.object();
        ui->label_proTitle->setText(t_jsonObj.value("proName").toString(tr("未知的工程配置")));
    }
}

