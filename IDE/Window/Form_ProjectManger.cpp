#include "Form_ProjectManger.h"
#include "qdir.h"
#include "ui_Form_ProjectManger.h"

#include "QFile"
#include "QFileInfo"
#include "QSettings"
#include "QMenu"
#include "QFileDialog"
#include "QMessageBox"
#include "QInputDialog"
#include "Form_VisualFolder.h"
#include "../Plugin/Plugin_Global.h"


Form_ProjectManger::Form_ProjectManger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_ProjectManger)
{
    ui->setupUi(this);
    //this->setStyleSheet("");
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);//设定树框自定义上下文菜单模式(右键菜单)，响应customContextMenuRequested事件

    connect(ui->action_AddFolder, &QAction::triggered,this,&Form_ProjectManger::event_menu_createNewFolder);
    connect(ui->action_AddForm, &QAction::triggered,this,&Form_ProjectManger::event_menu_addForm);
    connect(ui->action_AddHasFile, &QAction::triggered,this,&Form_ProjectManger::event_menu_addHasFile);
    connect(ui->action_AddNewFile, &QAction::triggered,this,&Form_ProjectManger::event_menu_addOtherFile);

    //默认就用工具栏
    ui->action_AddFolder->setEnabled(false);
    ui->action_AddForm->setEnabled(false);
    ui->action_AddHasFile->setEnabled(false);
    ui->action_AddNewFile->setEnabled(false);

/*
    QString  t_fileName = QCoreApplication::applicationDirPath() + "/Config.ini";

    QSettings t_setPro(t_fileName, QSettings::IniFormat);//工程总配置信息
    t_setPro.beginGroup("FireMonkeyProJect");
    t_setPro.setValue("ProjectName","测试工程名"); //工程名
    t_setPro.setValue("IconPath",""); //图标文件
    t_setPro.setValue("Version","1.0"); //版本文本信息
    t_setPro.setValue("VersionNumber",0); //版本号
    t_setPro.setValue("Organization","无"); //组织信息（公司或者组织）
    t_setPro.setValue("Email","NULL"); //邮箱信息
    t_setPro.setValue("Call","000-0000-0000"); //联系电话
    t_setPro.setValue("Note","本程序基于火猴开发平台"); //联系电话
    t_setPro.setValue("Note","本程序基于火猴开发平台"); //联系电话
    t_setPro.setValue("SrcPath","./src"); //工程文件在当前配置文件的那个相对位置


    QSettings t_setVirFolders(t_fileName, QSettings::IniFormat); //虚拟文件夹
    t_setVirFolders.beginGroup("Fmp_VirtualFolders");
    t_setVirFolders.setValue("头文件",".h/right"); //虚拟分类文件夹，left:左边存在，right:右边存在，has:只要存在
    t_setVirFolders.setValue("源文件",".cpp/right");


    QSettings t_setNormalFolders(t_fileName, QSettings::IniFormat); //真实自定义文件夹
    t_setNormalFolders.beginGroup("Fmp_NormalFolders");
    t_setNormalFolders.setValue("自定义分类文件夹","/自定义分类文件夹");


    QSettings t_setFilelist(t_fileName, QSettings::IniFormat); //文件列表
    t_setFilelist.beginGroup("Fmp_Filelist");
    QString t_file1 = "<srcPath>/test.h";
    QString t_file2 = "<srcPath>/main.cpp";
    t_setFilelist.setValue(QFileInfo(t_file1).fileName(),t_file1);
    t_setFilelist.setValue(QFileInfo(t_file2).fileName(),t_file2);
    return;

*/


    InitMenu();


    //测试代码
    //this->addProjectForFile("C:/Users/31914/Desktop/FmpProject/src/test.h");
    //this->addProjectForDir("C:/Users/31914/Desktop/FmpProject/src"); //以目录添加工程
    //this->addProjectForFmp("C:/Users/31914/Desktop/FmpProject/FmProject.fmp"); //以启动文件添加工程
    //this->flashTreeWidget();
}

Form_ProjectManger::~Form_ProjectManger()
{
    delete ui;
}

//获取初始尺寸信息
QSize Form_ProjectManger::sizeHint() const
{
    return QSize(200,900);
}

//使用fmp添加工程
bool Form_ProjectManger::addProjectForFmp(QString projectFile)
{
    QFileInfo t_fileInfo(projectFile);
    if(!t_fileInfo.exists()) return false;

    ProjectMsg* t_proMsg = new ProjectMsg;

    //设定工程目录
    t_proMsg->proPath = t_fileInfo.absolutePath();

    //读取工程目录信息
    QSettings t_setPro(projectFile, QSettings::IniFormat);//工程总配置信息
    t_setPro.beginGroup("FireMonkeyProJect");
    t_proMsg->proName = t_setPro.value("ProjectName").toString(); //工程名
    t_proMsg->proIconPath = t_setPro.value("IconPath").toString(); //图标文件
    t_proMsg->proVerson = t_setPro.value("Version").toString(); //版本文本信息
    t_proMsg->proVersonNum = t_setPro.value("VersionNumber").toInt(); //版本号
    t_proMsg->proOrg = t_setPro.value("Organization").toString(); //组织信息（公司或者组织）
    t_proMsg->proEmail = t_setPro.value("Email").toString(); //邮箱信息
    t_proMsg->proCall = t_setPro.value("Call").toString(); //联系电话
    t_proMsg->proNote = t_setPro.value("Note","本程序由火猴开发平台构建").toString(); //联系电话
    t_proMsg->proSrcPath = t_setPro.value("SrcPath").toString(); //工程文件在当前配置文件的那个相对位置
    t_proMsg->proSystem =  t_setPro.value("System").toString(); //支持的操作系统平台<存在于模板条件筛选>
    t_proMsg->proLanguage =  t_setPro.value("Language").toString(); //使用的编程语言<存在于模板条件筛选>
    t_proMsg->proNoteClass =  t_setPro.value("NoteClass").toString(); //其他备注类<存在于模板条件筛选>

    if(this->projectExisted(t_proMsg->proPath)) return false; //工程已经存在了，防止多次打开

    //添加启动文件类型
    this->addItem(t_fileInfo.fileName(),  //文件名
                  projectFile, //标记文本
                  ico_fmp, //图标文件
                  t_proMsg, //父项目指针
                  listType::file_fmp //文件类型
                  );

    //虚拟分类文件夹，left:左边存在，right:右边存在，has:只要存在
    QSettings t_setVirFolders(projectFile, QSettings::IniFormat); //虚拟文件夹
    t_setVirFolders.beginGroup("Fmp_VirtualFolders");
    QStringList t_strList = t_setVirFolders.allKeys();
    for(QStringList::Iterator t_it = t_strList.begin();t_it < t_strList.end();t_it++){
        //遍历所有虚拟文件夹
        QString t_key = *t_it;
        if(!t_key.isEmpty()){
            listType t_type = listType::folder_rightSign;

            QString t_value = t_setVirFolders.value(t_key).toString(); //获取标记的数值
            int t_index = t_value.indexOf('/');
            QString t_l = t_value.left(t_index); //虚拟文件夹的后缀信息
            QString t_r = t_value.right(t_value.length() - t_index - 1); //虚拟文件夹类型

            if(t_r == "left"){
                t_type = listType::folder_leftSign;
            }
            else if(t_r == "has"){
                t_type = listType::folder_hasSign;
            }

            //虚拟后缀
            if(t_l == "") continue;
            this->addItem(t_key,
                          t_l, //后缀标记
                          ico_signFolder,
                          t_proMsg,
                          listType::folder_rightSign //虚拟文件夹类型
                          );
        }
    }

//    //加入窗体文件分类文件夹
//    this->addItem(tr("窗体"),  //文件名
//                  ".uix", //标记文本
//                  ico_uiFolder, //图标文件
//                  t_proMsg, //父项目指针
//                  listType::folder_rightSign //文件类型
//                  );

//    //加入资源文件分类文件夹
//    this->addItem(tr("资源文件"),  //文件名
//                  ".res", //标记文本
//                  ico_resFolder, //图标文件
//                  t_proMsg, //父项目指针
//                  listType::folder_rightSign //文件类型
//                  );



    //加入文件夹信息
    QSettings t_setNormalFolders(projectFile, QSettings::IniFormat); //真实自定义文件夹
    t_setNormalFolders.beginGroup("Fmp_NormalFolders");
    t_strList = t_setNormalFolders.allKeys();
    for(QStringList::Iterator t_it = t_strList.begin();t_it < t_strList.end();t_it++){
        QString t_str = t_setNormalFolders.value(*t_it).toString();
        t_str.replace("<srcPath>", t_proMsg->proPath + t_proMsg->proSrcPath);
        this->addItem(*t_it,  //文件夹名
                      t_str, //标记文本
                      ico_normalFolder, //图标文件
                      t_proMsg, //父项目指针
                      listType::folder_normalSign //文件类型
                      );
    }



    //加入文件信息
    QSettings t_setFilelist(projectFile, QSettings::IniFormat); //文件列表
    t_setFilelist.beginGroup("Fmp_Filelist");
    t_strList = t_setFilelist.allKeys();
    for(QStringList::Iterator t_it = t_strList.begin();t_it < t_strList.end();t_it++){
        QString t_str = t_setFilelist.value(*t_it).toString();
        t_str.replace("<srcPath>", t_proMsg->proPath + t_proMsg->proSrcPath);
        this->addItem(*t_it,  //文件名
                      t_str, //标记文本
                      ico_fileType_unKnow, //图标文件
                      t_proMsg, //父项目指针
                      listType::file_normal //文件类型
                      );
    }


    //将工程添加到工程列表
    t_proMsg->proParentItem = new QTreeWidgetItem(); //创建工程最初的树项
    this->ProjectList.append(t_proMsg);

    this->NowProjectMsg = t_proMsg;
    this->onProjectActiveChanged(this->NowProjectMsg->proPath,this->NowProjectMsg->proLanguage,this->NowProjectMsg->proNoteClass); //激发工程切换事件

    //允许工具栏按钮
    ui->action_AddFolder->setEnabled(true);
    ui->action_AddForm->setEnabled(true);
    ui->action_AddHasFile->setEnabled(true);
    ui->action_AddNewFile->setEnabled(true);
    return true;
}

//使用文件夹添加工程
bool Form_ProjectManger::addProjectForDir(QString dirPath)
{
    QDir t_dir(dirPath);
    if(!t_dir.exists()) return false;

    ProjectMsg* t_proMsg = new ProjectMsg; //新文件夹创建工程
    t_proMsg->proName = Form_ProjectManger::GetDirFileName(dirPath);
    t_proMsg->proPath = dirPath;
    t_proMsg->proSrcPath = "";

    if(this->projectExisted(t_proMsg->proPath)) return false;//工程已经存在，防止多次打开

    QVector<QString> t_dirList;
    QVector<QString> t_fileList;
    this->Find_DirFile(dirPath,t_dirList,t_fileList);

    for(int a = 0;a<t_dirList.length();a++){
        this->addItem(Form_ProjectManger::GetDirFileName(t_dirList[a]),  //文件夹类型
                      t_dirList[a], //文件夹路径
                      ico_normalFolder, //图标文件
                      t_proMsg, //父项目指针
                      listType::folder_normalSign //文件夹类型
                      );
    }

    for(int a = 0;a<t_fileList.length();a++){
        this->addItem(Form_ProjectManger::GetDirFileName(t_fileList[a]),  //文件名
                      t_fileList[a], //标记文本
                      ico_fileType_unKnow, //图标文件
                      t_proMsg, //父项目指针
                      listType::file_normal //文件类型
                      );
    }

    //整合虚拟工程
    //将工程添加到工程列表
    t_proMsg->proParentItem = new QTreeWidgetItem(); //创建工程最初的树项
    this->ProjectList.append(t_proMsg);

    this->NowProjectMsg = t_proMsg;
    this->onProjectActiveChanged(this->NowProjectMsg->proPath,this->NowProjectMsg->proLanguage,this->NowProjectMsg->proNoteClass); //激发工程切换事件

    //允许工具栏按钮
    ui->action_AddFolder->setEnabled(true);
    ui->action_AddForm->setEnabled(true);
    ui->action_AddHasFile->setEnabled(true);
    ui->action_AddNewFile->setEnabled(true);
    return true;
}

//使用普通文件添加工程
bool Form_ProjectManger::addProjectForFile(QString filePath)
{
    QFileInfo t_fileInfo(filePath);
    if(!t_fileInfo.exists()) return false;

    ProjectMsg* t_proMsg = new ProjectMsg; //新文件夹创建工程
    t_proMsg->proName = t_fileInfo.baseName();
    t_proMsg->proPath = t_fileInfo.path();
    t_proMsg->proSrcPath = "";

    if(this->projectExisted(t_proMsg->proPath)) return false;//工程已经存在，防止多次打开

    this->addItem(t_fileInfo.fileName(),  //文件名
                  filePath, //标记文本
                  ico_fileType_unKnow, //图标文件
                  t_proMsg, //父项目指针
                  listType::file_normal //文件类型
                  );

    //将工程添加到工程列表
    t_proMsg->proParentItem = new QTreeWidgetItem(); //创建工程最初的树项
    this->ProjectList.append(t_proMsg);

    this->NowProjectMsg = t_proMsg;
    this->onProjectActiveChanged(this->NowProjectMsg->proPath,this->NowProjectMsg->proLanguage,this->NowProjectMsg->proNoteClass); //激发工程切换事件

    //允许工具栏按钮
    ui->action_AddFolder->setEnabled(true);
    ui->action_AddForm->setEnabled(true);
    ui->action_AddHasFile->setEnabled(true);
    ui->action_AddNewFile->setEnabled(true);
    return true;
}


//添加项目并且标记
QTreeWidgetItem* Form_ProjectManger::addItem(QString name, QString signText,QIcon ico,ProjectMsg * itemParent,listType type)
{
    itemMsg t_itemMsg;
    t_itemMsg.name = name; //子项名称
    t_itemMsg.signText = signText; //子项标记
    t_itemMsg.projectPth = itemParent; //子项父类标记
    t_itemMsg.type = type; //子项类型
    t_itemMsg.item = new QTreeWidgetItem; //设定子项
    t_itemMsg.item->setIcon(0,ico);       //设定图标
    t_itemMsg.item->setText(0,name);      //设定标题
    //t_itemMsg.item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable);
    itemParent->proItemList.append(t_itemMsg); //添加Item信息到父组件;
    return t_itemMsg.item;
}


//刷新树框
void Form_ProjectManger::flashTreeWidget()
{

    QVector<ProjectMsg*>::Iterator t_itRoot;
    //项目合集操作
    for(t_itRoot = ProjectList.begin();t_itRoot < ProjectList.end();t_itRoot++){
        //(*t_itRoot)->proParentItem = new QTreeWidgetItem();
        (*t_itRoot)->proParentItem->setIcon(0,ico_project);
        (*t_itRoot)->proParentItem->setText(0,(*t_itRoot)->proName);
        ui->treeWidget->addTopLevelItem((*t_itRoot)->proParentItem);

        //子项合集操作
        QVector<itemMsg>::Iterator t_itItem;
        for(t_itItem = (*t_itRoot)->proItemList.begin();t_itItem < (*t_itRoot)->proItemList.end();t_itItem++){
            QIcon t_ico = this->ico_fileType_unKnow; //默认文件图标

            QTreeWidgetItem* t_parentItem = (*t_itRoot)->proParentItem;
            if(t_itItem->type == listType::file_normal || t_itItem->type == listType::file_fmp){ //如果是文件信息，则扫描是否包含于文件夹当中
                //检索是否存在于某个文件夹之下
                QVector<itemMsg>::Iterator t_itItem2;
                for(t_itItem2 = (*t_itRoot)->proItemList.begin();t_itItem2 < (*t_itRoot)->proItemList.end();t_itItem2++){
                    //检索是否存在于真实文件夹目录下
                    if(t_itItem2->type == listType::folder_normalSign && QFileInfo(t_itItem->signText).path() == t_itItem2->signText){
                        t_parentItem = t_itItem2->item;//普通文件夹，直接嵌入子项
                        break;
                    }

                    //文件目录在根目录
                    if(QFileInfo(t_itItem->signText).path() == (*t_itRoot)->proPath + (*t_itRoot)->proSrcPath){
                        if(t_itItem2->type == listType::folder_hasSign){ //文件在虚拟文件夹-存在
                            if(QFileInfo(t_itItem2->signText).fileName().indexOf(t_itItem->signText) != -1){
                                t_parentItem = t_itItem2->item;//存在文件夹
                                break;
                            }
                        }
                        else if(t_itItem2->type == listType::folder_leftSign){ //文件在虚拟文件夹-左存在
                            if(QFileInfo(t_itItem->signText).fileName().left(t_itItem2->signText.length()) == t_itItem2->signText){
                                t_parentItem = t_itItem2->item;//左边存在
                                break;
                            }
                        }
                        else if(t_itItem2->type == listType::folder_rightSign){ //文件在虚拟文件夹-右存在
                            if(QFileInfo(t_itItem->signText).fileName().right(t_itItem2->signText.length()) == t_itItem2->signText){
                                t_parentItem = t_itItem2->item;//右边存在
                                break;
                            }
                        }
                    }
                }

                //根据文件后缀纠正关联的图标信息
                for(int a = 0;a<icoList_file.length();a++){
                    if(t_itItem->name.right(icoList_file[a].str.length()) == icoList_file[a].str){
                        t_ico = icoList_file[a].ico;
                        break;
                    }
                }

            }
            else if(t_itItem->type == listType::folder_normalSign){ //若是默认文件夹信息
                QVector<itemMsg>::Iterator t_itItem2;
                for(t_itItem2 = (*t_itRoot)->proItemList.begin();t_itItem2 < (*t_itRoot)->proItemList.end();t_itItem2++){
                    if(t_itItem2->type == listType::folder_normalSign){
                        QString t_str = t_itItem->signText;
                        //当前文件夹比对比的长，并且当前的文件夹去除对比的文件夹后不存在‘/’
                        if(t_str.length() > t_itItem2->signText.length() && t_str.replace(t_itItem2->signText + '/',"").indexOf("/") == -1){
                            t_parentItem = t_itItem2->item;
                            break;
                        }
                    }
                }
                t_ico = ico_normalFolder;

            }
            else if(t_itItem->type == listType::folder_leftSign || t_itItem->type == listType::folder_rightSign || t_itItem->type == listType::folder_hasSign){
                t_ico = ico_signFolder; //默认标记

                //根据信息更改虚拟文件夹图标
                for(int a = 0;a<icoList_visualFolder.length();a++){
                    if(t_itItem->signText == icoList_visualFolder[a].str){
                        t_ico = icoList_visualFolder[a].ico;
                        break;
                    }
                }

            }

            t_itItem->item->setIcon(0,t_ico); //设定预设好的ICO文件，否则保持默认
            t_parentItem->addChild(t_itItem->item); //添加到父项，若存在则不重叠
        }
    }
}


//刷新工程列表内信息表的排序，按照枚举类型排序
void Form_ProjectManger::sortItem(ProjectMsg *itemParent)
{
    //冒泡排序整理信息
    for(int a = 0;a<itemParent->proItemList.length();a++){
        for(int b = 0;b<itemParent->proItemList.length() - a - 1;b++){
            if(itemParent->proItemList[b].type > itemParent->proItemList[b + 1].type){
                itemMsg t_itemMsg = itemParent->proItemList[b];
                itemParent->proItemList[b] = itemParent->proItemList[b + 1];
                itemParent->proItemList[b + 1] = t_itemMsg;
            }
        }
    }
}


//移除工程列表所有的Item关联子项关联
void Form_ProjectManger::initItem(ProjectMsg *itemParent)
{
    for(int a = 0;a<itemParent->proItemList.length();a++){
        if(itemParent->proItemList[a].item->parent() != nullptr){
            itemParent->proItemList[a].item->parent()->removeChild(itemParent->proItemList[a].item); //移除所有子项关联
        }
    }
}


//初始化菜单
void Form_ProjectManger::InitMenu()
{
    //构建工程菜单
    Menu_pro = new QMenu(this);
    QAction* t_menuAction;
    t_menuAction = Menu_pro->addAction(ico_menu_build,tr("构建"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_proMenu_Biild);
    t_menuAction = Menu_pro->addAction(ico_menu_clear,tr("清理"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_proMneu_Clear);
    Menu_pro->addSeparator();//添加分割线
    t_menuAction = Menu_pro->addAction(ico_menu_Action,tr("设定为活动工程"));
    this->menuAction_setActive = t_menuAction; //保存当前的活动工程的右键菜单选项
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_proMneu_SetActive);
    Menu_pro->addSeparator();//添加分割线
    t_menuAction = Menu_pro->addAction(ico_menu_check,tr("刷新项目结构"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_proMneu_Flash);
    t_menuAction = Menu_pro->addAction(ico_menu_check,tr("验证项目文件"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_proMneu_Check);
    Menu_pro->addSeparator();//添加分割线
    t_menuAction = Menu_pro->addAction(ico_menu_addFolder,tr("添加根文件夹"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_menu_createNewFolder); //在根工程菜单添加一个文件夹添加接口菜单
    Menu_pro->addSeparator();//添加分割线
    t_menuAction = Menu_pro->addAction(ico_menu_close,tr("关闭项目"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_proMneu_Close);


    //构建文件菜单
    Menu_normal = new QMenu(this);
    QMenu* t_Menu_item = new QMenu(Menu_normal);//子项菜单
    Menu_addNewFile = t_Menu_item;
    t_Menu_item->setTitle("添加文件");
    t_Menu_item->setIcon(ico_menu_addNewFile);
    t_menuAction = t_Menu_item->addAction(ico_menu_addNewFile,tr("头文件(.h)"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_menu_addHead);
    t_menuAction = t_Menu_item->addAction(ico_menu_addNewFile,tr("源文件(.cpp)"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_menu_addCpp);
    t_menuAction = t_Menu_item->addAction(ico_menu_addFormFile,tr("窗体文件(.uix)"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_menu_addForm);
    t_menuAction = t_Menu_item->addAction(ico_fileType_unKnow,tr("其他文件"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_menu_addOtherFile);
    Menu_normal->addMenu(t_Menu_item);

    t_menuAction = Menu_normal->addAction(ico_menu_addHasFile,tr("添加已有文件"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_menu_addHasFile);
    Menu_normal->addSeparator();//添加分割线

    t_Menu_item = new QMenu(Menu_normal);//子项菜单
    t_Menu_item->setTitle("文件夹/分类器");
    t_Menu_item->setIcon(ico_menu_folder);
    t_menuAction = t_Menu_item->addAction(ico_menu_addFolder,tr("创建文件夹"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_menu_createNewFolder);
    t_menuAction = t_Menu_item->addAction(ico_menu_addVisualFolder,tr("创建虚拟文件夹"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_menu_createVisualFolder);
    Menu_normal->addMenu(t_Menu_item);
    Menu_normal->addSeparator();//添加分割线

    t_menuAction = Menu_normal->addAction(ico_menu_rename,tr("重命名"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_menu_rename);
    Menu_normal->addSeparator();//添加分割线

    t_menuAction = Menu_normal->addAction(ico_menu_delete,tr("永久删除"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_menu_delete);
    t_menuAction = Menu_normal->addAction(ico_menu_remove,tr("从项目列表移除"));
    connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_menu_remove);
    //Menu_normal->addSeparator();//添加分割线



}


//查找Poeject指针，不存在返回nullptr
Form_ProjectManger::ProjectMsg *Form_ProjectManger::Find_ProjectMsg(QTreeWidgetItem *item)
{
    QVector<ProjectMsg*>::Iterator t_it;
    for(t_it = ProjectList.begin();t_it<ProjectList.end();t_it++){
        if((*t_it)->proParentItem == item){ //直接查找工程指针信息
            return (*t_it);
        }
        else{
            QVector<itemMsg>::Iterator t_itItem;
            for(t_itItem = (*t_it)->proItemList.begin();t_itItem < (*t_it)->proItemList.end();t_itItem++){
                if(t_itItem->item == item){ //从子项查找工程指针信息
                    return t_itItem->projectPth;
                }
            }
        }
    }
    return nullptr;
}

//查找itemMsg指针，不存在返回nullptr
Form_ProjectManger::itemMsg *Form_ProjectManger::Find_ItemMsg(QTreeWidgetItem *item)
{
    QVector<ProjectMsg*>::Iterator t_it;
    for(t_it = ProjectList.begin();t_it<ProjectList.end();t_it++){
        QVector<itemMsg>::Iterator t_it2;
        for(t_it2 = (*t_it)->proItemList.begin();t_it2 < (*t_it)->proItemList.end();t_it2++){
            if(t_it2->item == item){
                return t_it2;
            }
        }
    }
    return nullptr;
}

//获取文件或者文件夹路径
QString Form_ProjectManger::GetPath()
{
    QString t_path = "";
    itemMsg* t_itemMsg = this->Find_ItemMsg(ui->treeWidget->currentItem());
    if(t_itemMsg == nullptr) { //如果不是子项目，则扫描工程，获取工程的路径
        ProjectMsg* t_proMsg = Find_ProjectMsg(ui->treeWidget->currentItem()); //扫描是否为本地工程
        if(t_proMsg != nullptr){
            t_path = t_proMsg->proPath + t_proMsg->proSrcPath; //默认为工程目录标准文件路径
        }

    }
    else{
        if(t_itemMsg->type == listType::folder_hasSign ||   //如果是虚拟文件夹
           t_itemMsg->type == listType::folder_leftSign ||
            t_itemMsg->type == listType::folder_rightSign){
            t_path = t_itemMsg->projectPth->proPath + t_itemMsg->projectPth->proSrcPath; //默认为工程目录标准文件路径
        }
        else if(t_itemMsg->type == listType::file_fmp || t_itemMsg->type == listType::file_normal){ //如果是文件
            t_path = QFileInfo(t_path).path();
        }
        else if(t_itemMsg->type == listType::folder_normalSign){ //如果是文件夹
            t_path = QFileInfo(t_path).absoluteFilePath();
        }
    }
    return t_path;
}

//添加一个文件
void Form_ProjectManger::AddFile(QString name)
{
    QString t_path = this->GetPath();
    if(t_path.isEmpty()) return;
    t_path = t_path + "/" + name; //添加头文件
        t_path = Form_ProjectManger::GetValidPath(t_path); //纠正文件类型

    itemMsg* t_itemMsg = this->Find_ItemMsg(ui->treeWidget->currentItem());
        if(t_itemMsg == nullptr || t_itemMsg->projectPth == nullptr) return;

    QFile t_file(t_path);
    if(!t_file.open(QIODevice::WriteOnly)) return;
    t_file.close(); //写出一个文件

    this->addItem(QFileInfo(t_path).fileName(),  //文件名
                  t_path, //标记文本
                  ico_fmp, //图标文件
                  t_itemMsg->projectPth, //父项目指针
                  listType::file_normal //文件类型
                  );
    this->flashTreeWidget();//刷新树信息
}

//检查当前工程是否存在这个文件
bool Form_ProjectManger::HasFile(QString filePath)
{
    if(NowProjectMsg == nullptr) return false;
    QVector<itemMsg>::Iterator t_it;
    for(t_it = NowProjectMsg->proItemList.begin();t_it < NowProjectMsg->proItemList.end();t_it++){
        if(t_it->type == listType::file_fmp || t_it->type == listType::file_normal){
            if(t_it->signText == filePath) return true;
        }
    }
    return false;
}

//获取有效的文件路径
QString Form_ProjectManger::GetValidPath(QString pathName)
{
    if(!QFileInfo(pathName).exists()) return pathName;

    QFileInfo t_fileinfo = QFileInfo(pathName);
    QString t_suffix = t_fileinfo.suffix();     //文件后缀
    QString t_baseName = t_fileinfo.baseName(); //基础名字
    QString t_path = t_fileinfo.path();         //文件路径

    QString t_pathName;
    int a = 0;
    while(true){
        a++;
        t_pathName = t_path + "/" + t_baseName + "(" + QString::number(a) + ")." + t_suffix;
        if(!QFileInfo(t_pathName).exists()) return t_pathName;
    }
}


//根据路径获取路径的最后一个文件夹
QString Form_ProjectManger::GetDirFileName(QString pathDir)
{
    int t_index = pathDir.lastIndexOf('/');
    if(t_index == -1) return "";
    return pathDir.right(pathDir.length() - t_index - 1); //工程文件名
}


//检查工程是否已经存在
bool Form_ProjectManger::projectExisted(QString proPath)
{
    for(int a = 0;a<this->ProjectList.length();a++){
        if(this->ProjectList[a]->proPath == proPath) {
            return true;
        }
    }
    return false;
}



//将ProjectMsg转换为PluginGlobalMsg::projectMsgBase
PluginGlobalMsg::projectMsgBase Form_ProjectManger::projectMsgConvertToBase(ProjectMsg msg)
{
    PluginGlobalMsg::projectMsgBase t_base;
    t_base.proPath = msg.proPath; //工程目录
    t_base.proName = msg.proName;//工程名
    t_base.proIconPath = msg.proIconPath;//图标路径
    t_base.proVerson = msg.proVerson;//版本信息
    t_base.proVersonNum = msg.proVersonNum;//版本号
    t_base.proOrg = msg.proOrg;//社区与公司名称
    t_base.proEmail = msg.proEmail;//邮箱
    t_base.proCall = msg.proCall;//电话
    t_base.proNote = msg.proNote;//备注
    t_base.proSrcPath = msg.proSrcPath;//源码相对路径
    t_base.proSystem = msg.proSystem; //操作系统平台标记
    t_base.proLanguage = msg.proLanguage; //语言标记
    t_base.proNoteClass = msg.proNoteClass; //其他备注标记
    return t_base;
}



//获取工程的基础信息
PluginGlobalMsg::projectMsgBase Form_ProjectManger::getProjectMsgBase(QString proPath)
{
    PluginGlobalMsg::projectMsgBase t_base;
    for(int a = 0;a<this->ProjectList.length();a++){
        if(this->ProjectList[a]->proPath == proPath) {
            t_base = this->projectMsgConvertToBase(*this->ProjectList[a]);
            break;
        }
    }
    return t_base;
}

//移除项目的所有子项Item
void Form_ProjectManger::RemoveAllItemChild(QTreeWidgetItem *parent)
{
    while(parent->childCount() > 0){
        parent->removeChild(parent->child(0));
    }
}

//重命名item
bool Form_ProjectManger::RenameItem()
{
    if(this->canEditorItem == nullptr) return false;
    itemMsg* t_itemMsgPtr = this->Find_ItemMsg(this->canEditorItem);
    QString t_newName = this->canEditorItem->text(0);
    this->canEditorItem = nullptr;//置空信息
    if(t_itemMsgPtr != nullptr){
        if(t_itemMsgPtr->name == t_itemMsgPtr->item->text(0)) return true;//未更名则不做任何分配
        QString t_olderName = t_itemMsgPtr->signText;
        if(t_itemMsgPtr->type == listType::file_fmp || t_itemMsgPtr->type == listType::file_normal){ //如果是文件
            QFile t_file(t_itemMsgPtr->signText);
            QString t_newFilePath = QFileInfo(t_itemMsgPtr->signText).path() + "/" + t_newName; //新的文件名（包含路径）
            if(t_file.rename(t_newFilePath) == false){ //文件更名
                //更名失败
                t_itemMsgPtr->item->setText(0,t_itemMsgPtr->name); //还原名称
                return false;
            }

            this->onFileRename(t_itemMsgPtr->signText,t_newFilePath); //激发文件更名事件
            t_itemMsgPtr->name = t_newName; //设定新名称
            t_itemMsgPtr->signText = t_newFilePath; //设定新路径

            if(QFileInfo(t_olderName).suffix() != QFileInfo(t_itemMsgPtr->item->text(0)).suffix()){ //后缀对比,新后缀将重新创建Item
                QMessageBox::warning(this,tr("文件后缀变动"),tr("注意：当前的文件类型存在变动，若当前文件在分类器中，可能会重新分配！"));
                delete t_itemMsgPtr->item;//回收内存信息
                t_itemMsgPtr->item = new QTreeWidgetItem;//创建新的子项
                t_itemMsgPtr->item->setText(0,t_newName);
            }
            return true;
        }
        if(t_itemMsgPtr->type == listType::folder_hasSign || t_itemMsgPtr->type == listType::folder_leftSign || t_itemMsgPtr->type == listType::folder_rightSign){//若是分类文件夹
            t_itemMsgPtr->name = t_newName; //直接更改信息
            return true;
        }
        if(t_itemMsgPtr->type == listType::folder_normalSign){ //文件夹更名
            int t_index = t_itemMsgPtr->signText.lastIndexOf('/');
            if(t_index == -1) return false;
            QString t_p = t_itemMsgPtr->signText.left(t_index) + "/" + t_newName;
            QDir t_dir;
            if(t_dir.rename(t_itemMsgPtr->signText,t_p) == false){
                t_itemMsgPtr->item->setText(0,t_itemMsgPtr->name); //还原名称
                return false;
            }
            t_itemMsgPtr->name = t_newName;
            t_itemMsgPtr->signText = t_p;
            return true;
        }
    }
    return false;
}


//遍历文件夹与子文件夹，还有文件
void Form_ProjectManger::Find_DirFile(QString dirPath, QVector<QString> &dirList, QVector<QString> &fileList)
{
    QDir t_dir(dirPath);
    if(!t_dir.exists()) return;
    QFileInfoList t_infoList = t_dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for(int a = 0;a<t_infoList.length();a++){
        QString t_filaPath = t_infoList[a].absoluteFilePath();
        if(t_infoList[a].isDir()){
            dirList.append(t_filaPath);
            this->Find_DirFile(t_filaPath,dirList,fileList);
        }
        else{
            fileList.append(t_filaPath);
        }
    }
}

//构建项目
void Form_ProjectManger::event_proMenu_Biild()
{
    ProjectMsg * t_pro = this->Find_ProjectMsg(ui->treeWidget->currentItem());
    if(t_pro != nullptr){
        this->onProjectBuild(t_pro->proPath + t_pro->proSrcPath);
    }
}
//清理项目
void Form_ProjectManger::event_proMneu_Clear()
{
    ProjectMsg * t_pro = this->Find_ProjectMsg(ui->treeWidget->currentItem());
    if(t_pro != nullptr){
        this->onFileClose(t_pro->proPath + t_pro->proSrcPath);
    }
}


//切换活动项目
void Form_ProjectManger::event_proMneu_SetActive()
{
    ProjectMsg * t_pro = this->Find_ProjectMsg(ui->treeWidget->currentItem());
    if(t_pro == nullptr) return;
    this->NowProjectMsg = t_pro;
    this->onProjectActiveChanged(t_pro->proPath,t_pro->proLanguage,t_pro->proNoteClass);
}

//刷新项目
void Form_ProjectManger::event_proMneu_Flash()
{
    ProjectMsg * t_pro = this->Find_ProjectMsg(ui->treeWidget->currentItem());
    if(t_pro != nullptr){
        this->sortItem(t_pro);
        this->initItem(t_pro);
        this->flashTreeWidget();
    }
}
//验证项目
void Form_ProjectManger::event_proMneu_Check()
{
    ProjectMsg * t_pro = this->Find_ProjectMsg(ui->treeWidget->currentItem());
    if(t_pro != nullptr){
        QVector<itemMsg>::Iterator t_it;
        for(t_it = t_pro->proItemList.begin();t_it < t_pro->proItemList.end();t_it++){
            if(t_it->type == listType::file_fmp || t_it->type == listType::file_normal){ //如果是工程文件或者是普通文件
                //开始验证文件是否存在
                if(QFile(t_it->signText).exists()){
                    t_it->item->setForeground(0,color_Normal); //文件存在，默认取色
                }
                else{
                    t_it->item->setForeground(0,color_HasNot); //不存在，则默认灰色显示
                }
                continue;
            }
            else if(t_it->type == listType::folder_normalSign){
                QDir t_folder(t_it->signText);
                if(t_folder.exists()){
                    t_it->item->setForeground(0,color_Normal); //文件存在，默认取色
                }
                else{
                    t_it->item->setForeground(0,color_HasNot); //不存在，则默认灰色显示
                }
                continue;
            }
        }
    }
}
//关闭项目
void Form_ProjectManger::event_proMneu_Close()
{
    ProjectMsg * t_pro = this->Find_ProjectMsg(ui->treeWidget->currentItem());
    if(t_pro != nullptr){
        this->onProjectClose(t_pro->proPath + t_pro->proSrcPath); //响应关闭事件
        //清理项目树框组件
        delete t_pro->proParentItem; //直接delete后会自动回收删除Item的所有子节点
        ProjectList.removeOne(t_pro); //移除当前的项目信息
        if(NowProjectMsg == t_pro){ //判断关闭的工程是否为当前工程
            //如果是，则默认为第一个工程为当前工程。
            if(ProjectList.length() > 0){
                this->NowProjectMsg = ProjectList[0]; //切换工程为第一个有效工程
                this->onProjectActiveChanged(t_pro->proPath,t_pro->proLanguage,t_pro->proNoteClass);
            }
            else{
                NowProjectMsg = nullptr; //工程已经全部清除，置空当前项目指针
                this->onProjectActiveChanged("","","");
            }
        }
    }

    if(ProjectList.length() == 0){
        //如果没有工程则禁用工具栏按钮
        ui->action_AddFolder->setEnabled(false);
        ui->action_AddForm->setEnabled(false);
        ui->action_AddHasFile->setEnabled(false);
        ui->action_AddNewFile->setEnabled(false);
    }
}


//添加头文件
void Form_ProjectManger::event_menu_addHead()
{
    this->AddFile("头文件.h");
}

//添加源文件
void Form_ProjectManger::event_menu_addCpp()
{
    this->AddFile("源文件.cpp");
}

//添加窗体文件
void Form_ProjectManger::event_menu_addForm()
{
    this->AddFile("newForm.uix");
}

//添加其他类型文件
void Form_ProjectManger::event_menu_addOtherFile()
{
    QString t_str = QInputDialog::getText(this, tr("添加文件"), tr("请输入文件名："), QLineEdit::Normal, QString());
    if(t_str.isEmpty()) return;
    this->AddFile(t_str);
}

//添加已有文件
void Form_ProjectManger::event_menu_addHasFile()
{
    QString t_path = this->GetPath();//获取当前目录
    QString t_filePath = QFileDialog::getOpenFileName(this, tr("打开已有文件"), "", "默认工程文件 (*.h *.c *.cpp *.uix);;所有文件(*.*)");
    if(t_filePath.isEmpty() || !QFileInfo(t_filePath).exists()) return;//如果文件不存在
    if(this->HasFile(t_filePath)) return;//工程已经存在这个文件，直接返回

    QString t_newFilePath = t_path + "/" + QFileInfo(t_filePath).fileName(); //新文件路径
    if(QFile(t_newFilePath).exists()){
        if(QMessageBox::question(this,tr("当前工程已经存在同名文件，是否覆盖？"),"",QMessageBox::Yes | QMessageBox::No,QMessageBox::No) == QMessageBox::No){
            //不覆盖同名文件，创建新的文件
            t_newFilePath = this->GetValidPath(t_newFilePath);
        }
    }
    QFile::copy(t_filePath,t_newFilePath);
    this->addItem(QFileInfo(t_newFilePath).fileName(),  //文件名
                  t_newFilePath, //标记文本
                  ico_fmp, //图标文件
                  this->NowProjectMsg, //父项目指针
                  listType::file_normal //文件类型
                  );
    this->flashTreeWidget();//刷新树信息
}

//创建文件夹
void Form_ProjectManger::event_menu_createNewFolder()
{
    ProjectMsg* t_proPth = nullptr;
    itemMsg* t_itemMsg = this->Find_ItemMsg(ui->treeWidget->currentItem());
    if(t_itemMsg != nullptr){
        t_proPth = t_itemMsg->projectPth;
    }
    else{
        t_proPth = this->Find_ProjectMsg(ui->treeWidget->currentItem());
    }
    if(t_proPth == nullptr) return; //指针信息正确

    QString t_folderName = QInputDialog::getText(nullptr,"输入","文件夹名");
    if(t_folderName.isEmpty()) return;

    QString t_path = this->GetPath();
    if(t_path.isEmpty()) return;

    QString t_folderSign = t_path + "/" + t_folderName;
    if(QDir(t_folderSign).exists()){
        for (int a = 1;true; a++) { //注意：目录后缀的添加是以"1"开始
            t_folderSign = t_path + "/" + t_folderName + QString::number(a);
            if(!QDir(t_folderSign).exists()){
                t_folderName = t_folderName + QString::number(a); //新文件夹名称
                break;
            }
        }
    }

    QDir t_dir;
    if(t_dir.mkpath(t_folderSign)){
        this->addItem(t_folderName,  //文件名
                      t_folderSign, //标记文本
                      ico_normalFolder, //图标文件
                      t_proPth, //父项目指针
                      listType::folder_normalSign //文件夹类型
                      );
    }
    this->flashTreeWidget();//刷新树信息
}

//创建虚拟文件夹
void Form_ProjectManger::event_menu_createVisualFolder()
{
    QTreeWidgetItem* t_currentItem = ui->treeWidget->currentItem();//临时保存Item指针
    Form_VisualFolder* t_vfolder = new Form_VisualFolder(nullptr);

    t_vfolder->setAttribute(Qt::WA_ShowModal, true); //设置模态,也就是对话窗口模式

    t_vfolder->setFun([this,t_currentItem](QString folderName,QString folderText,int type){
        if(folderName.isEmpty() || folderText.isEmpty()) return;
        listType t_type;
        switch(type){
        default:{
            t_type = listType::folder_rightSign;
            break;
        }
        case 0:{ //后缀分类
            t_type = listType::folder_rightSign;
            break;
        }
        case 1:{ //前缀分类
            t_type = listType::folder_leftSign;
            break;
        }
        case 2:{ //存在分类
            t_type = listType::folder_hasSign;
            break;
        }
        }
        itemMsg* t_itemMsg = this->Find_ItemMsg(t_currentItem);
        if(t_itemMsg == nullptr) return;
        this->addItem(folderName,  //文件名
                      folderText, //标记文本
                      ico_signFolder, //图标文件
                      t_itemMsg->projectPth, //父项目指针
                      t_type //文件类型
                      );
        this->flashTreeWidget();//刷新树信息
    });

    t_vfolder->setWindowModality(Qt::ApplicationModal); //设置为对话模式
    t_vfolder->show();
}

//重命名
void Form_ProjectManger::event_menu_rename()
{
    itemMsg* t_itemMsgPtr = this->Find_ItemMsg(ui->treeWidget->currentItem());
    if(t_itemMsgPtr == nullptr) return;
    ui->treeWidget->openPersistentEditor(t_itemMsgPtr->item,0);//设置为可编辑

    canEditorItem = t_itemMsgPtr->item; //设定当前可编辑的item指针



}

//永久删除
void Form_ProjectManger::event_menu_delete()
{
    itemMsg t_itemMsg = *this->Find_ItemMsg(ui->treeWidget->currentItem());
    if(t_itemMsg.type == listType::file_fmp) QMessageBox::warning(this,tr("警告"),tr("无法删除工程配置文件，强制移除可能会导致工程配置异常！"));
    if(t_itemMsg.type != listType::file_normal && t_itemMsg.type != listType::folder_normalSign) return;//不删除虚拟文件文件和启动文件

    if(t_itemMsg.type == listType::file_normal){
        QFile t_file(t_itemMsg.signText);
        if(!t_file.exists() || !t_file.remove()){
            QMessageBox::critical(this, tr("错误"), tr("出现问题，无法删除该项目文件！"));
            return;
        }
        this->onFileClose(t_itemMsg.signText); //激发文件被删除事件
    }
    else if(t_itemMsg.type == listType::folder_normalSign){
        QDir t_dir(t_itemMsg.signText);
        if(!t_dir.exists() || !t_dir.removeRecursively()){
            QMessageBox::critical(this, tr("错误"), tr("出现问题，无法删除该目录！"));
            return;
        }
    }

    //文件删除完成，删除项目结构目录
    this->event_menu_remove();
}

//从列表移除
void Form_ProjectManger::event_menu_remove()
{
    //获取当前选择的项目信息和工程信息
    itemMsg* t_itemMsgPtr = this->Find_ItemMsg(ui->treeWidget->currentItem());
    ProjectMsg* t_proMsgPtr = this->Find_ProjectMsg(ui->treeWidget->currentItem()); //查找的工程信息
    if(t_proMsgPtr == nullptr || t_itemMsgPtr == nullptr) return;

    itemMsg t_itemMsg = *t_itemMsgPtr; //取出信息，防止QVector列表删除造成的数据指针所指向的内存发生变动
    QTreeWidgetItem* t_nowitem = t_itemMsg.item; //当前选择的树框item

    if(t_itemMsg.type == listType::file_fmp){
        QMessageBox::warning(this,"警告","无法移除工程配置文件，强制移除可能会导致工程配置异常！");
        return;
    }


    QVector<itemMsg>::Iterator t_it;
    if(t_itemMsg.type == listType::folder_normalSign){ //如果这是普通文件夹，则自动清空子项的所有信息
        //遍历移除工程子项信息,并且删除
        CLEAR_LIST:
        QVector<itemMsg>::Iterator t_it;
        int a = 0;
        for(t_it = t_proMsgPtr->proItemList.begin();t_it != t_proMsgPtr->proItemList.end();t_it++){ //清空所有子项信息
            if(t_it->type == listType::file_fmp || t_it->type == listType::file_normal || t_it->type == listType::folder_normalSign){
                if(t_it->signText.left(t_itemMsg.signText.length()) == t_itemMsg.signText){
                    t_proMsgPtr->proItemList.removeAt(a);
                    goto CLEAR_LIST; //再次执行。直到清除完毕，减少代码的递归写法
                }
            }
            a++;
        }
        delete t_nowitem;
    }
    else{//如果这是虚拟文件夹,则直接删除自身信息,并且清除item信息
        //删除子项信息
        QVector<itemMsg>::Iterator t_it;
        int a = 0;
        for(t_it = t_proMsgPtr->proItemList.begin();t_it < t_proMsgPtr->proItemList.end();t_it++){ //清空所有子项信息
            if(t_it->item == t_itemMsg.item){//子项信息
                //移除当前项目所有的子项
                this->RemoveAllItemChild(t_it->item);
                delete t_nowitem;
                t_proMsgPtr->proItemList.removeAt(a); //删除当前子项信息
                break;
            }
            a++;
        }
    }
    //刷新树
    this->flashTreeWidget();

    //判断是否有工程存在，操作工具栏
    if(this->ProjectList.length() == 0){
        ui->action_AddFolder->setEnabled(false);
        ui->action_AddForm->setEnabled(false);
        ui->action_AddHasFile->setEnabled(false);
        ui->action_AddNewFile->setEnabled(false);
    }
}



//弹出菜单
void Form_ProjectManger::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    bool isProItem = false;
    QTreeWidgetItem* t_item = ui->treeWidget->currentItem();
    if(!t_item) return; //无工程，不打开右键菜单

    QVector<ProjectMsg*>::Iterator t_it;
    for(t_it = ProjectList.begin();t_it < ProjectList.end();t_it++){
        if((*t_it)->proParentItem == t_item){ //如果是工程的节点
            isProItem = true;
            break;
        }
    }
    //否则弹出基础文件右键菜单
    if(isProItem){
        ProjectMsg* t_proMsgPtr = this->Find_ProjectMsg(t_item); //查找的工程信息
        if(t_proMsgPtr == nullptr) return;
        if(t_proMsgPtr != NowProjectMsg){ //判断当前的工程是不是活动工程，如果不是则允许切换
            this->menuAction_setActive->setEnabled(true);
            this->menuAction_setActive->setCheckable(true);
        }
        else{
            this->menuAction_setActive->setEnabled(false);
            this->menuAction_setActive->setCheckable(false);
        }

        Menu_pro->exec(QCursor::pos());
    }
    else{
        Menu_normal->exec(QCursor::pos());
    }


}


//项目名称被改变
void Form_ProjectManger::on_treeWidget_itemChanged(QTreeWidgetItem *item, int column)
{
    if(this->canEditorItem == nullptr) return;
    itemMsg* t_itemMsgPtr = this->Find_ItemMsg(this->canEditorItem);
    if(t_itemMsgPtr == nullptr) return;
    this->RenameItem();
    ui->treeWidget->closePersistentEditor(t_itemMsgPtr->item,0); //关闭可编辑状态
    this->flashTreeWidget(); //刷新树
}

//项目被双击，文件被打开
void Form_ProjectManger::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    itemMsg* t_itemMsgPtr = this->Find_ItemMsg(item);
    if(t_itemMsgPtr == nullptr) return;

    if(t_itemMsgPtr->type == listType::file_fmp || t_itemMsgPtr->type == listType::file_normal){ //文件被打开
        this->onFileOpen(t_itemMsgPtr->signText);
    }
}

