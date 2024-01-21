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
#include "QJsonDocument"
#include "QJsonObject"
#include "QElapsedTimer"
#include "QProgressDialog" //进度对话框
#include "QMessageBox" //信息框

#include "../SwSystem/System_UtilFun.h"
//#include "Form_VisualFolder.h"
//#include "../Plugin/Plugin_Global.h"


Form_ProjectManger::Form_ProjectManger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_ProjectManger)
{
    ui->setupUi(this);
    //this->setStyleSheet("");


    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);//设定树框自定义上下文菜单模式(右键菜单)，响应customContextMenuRequested事件
/*
    connect(ui->action_AddFolder, &QAction::triggered,this,&Form_ProjectManger::event_menu_createNewFolder);
    connect(ui->action_AddForm, &QAction::triggered,this,&Form_ProjectManger::event_menu_addForm);
    connect(ui->action_AddHasFile, &QAction::triggered,this,&Form_ProjectManger::event_menu_addHasFile);
    connect(ui->action_AddNewFile, &QAction::triggered,this,&Form_ProjectManger::event_menu_addOtherFile);

    //默认就用工具栏
    ui->action_AddFolder->setEnabled(false);
    ui->action_AddForm->setEnabled(false);
    ui->action_AddHasFile->setEnabled(false);
    ui->action_AddNewFile->setEnabled(false);


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

    //初始化构建菜单
    InitMenu();


    //初始化图标
    this->addFileIco("cpp",ico_fileType_cpp);
    this->addFileIco("h",ico_fileType_h);
    this->addFileIco("c",ico_fileType_c);
    this->addFileIco("java",ico_fileType_java);
    this->addFileIco("js",ico_fileType_js);
    this->addFileIco("json",ico_fileType_json);
    this->addFileIco("py",ico_fileType_py);
    this->addFileIco("php",ico_fileType_php);
    this->addFileIco("jar",ico_fileType_jar);
    this->addFileIco("link",ico_fileType_link);
    this->addFileIco("html",ico_fileType_html);
    this->addFileIco("css",ico_fileType_css);
    this->addFileIco("ini",ico_fileType_ini);
    this->addFileIco("sql",ico_fileType_sql);
    this->addFileIco("txt",ico_fileType_txt);
    this->addFileIco("xml",ico_fileType_xml);
    this->addFileIco("zip",ico_fileType_zip);
    this->addFileIco("uix",ico_window);
    this->addFileIco("ui",ico_window);
    this->addFileIco("fmp",ico_fmp);


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


//初始化菜单
void Form_ProjectManger::InitMenu()
{
    //新建菜单
    Menu_addNewFile = new QMenu(this);
    Menu_addNewFile->setTitle("新建");
    Menu_addNewFile->setIcon(ico_menu_folder);
    act_new_file = Menu_addNewFile->addAction(ico_fileType_unKnow,tr("文件"));
    connect(act_new_file,&QAction::triggered,this,&Form_ProjectManger::event_newMenu_file);
    act_new_folder = Menu_addNewFile->addAction(ico_menu_addFolder,tr("文件夹"));
    connect(act_new_folder,&QAction::triggered,this,&Form_ProjectManger::event_newMenu_folder);
    Menu_addNewFile->addSeparator();//添加分割线


    //工程菜单
    Menu_pro = new QMenu(this);
    Menu_pro->addMenu(Menu_addNewFile);
    act_pro_openProject = Menu_pro->addAction(ico_project,tr("打开新工程"));
    connect(act_pro_openProject,&QAction::triggered,this,&Form_ProjectManger::event_proMneu_openNewProject);
    Menu_pro->addSeparator();//添加分割线
    act_pro_paste = Menu_pro->addAction(QIcon(),tr("粘贴到工程目录 "));
    Menu_pro->addSeparator();//添加分割线
    connect(act_pro_paste,&QAction::triggered,this,&Form_ProjectManger::event_proMenu_paste);
    act_pro_flash = Menu_pro->addAction(ico_menu_check,tr("刷新"));
    connect(act_pro_flash,&QAction::triggered,this,&Form_ProjectManger::event_proMenu_flash);
    act_pro_explorer = Menu_pro->addAction(ico_menu_addVisualFolder,tr("在资源管理器打开"));
    connect(act_pro_explorer,&QAction::triggered,this,&Form_ProjectManger::event_proMenu_explorer);
    Menu_pro->addSeparator();//添加分割线
    act_pro_activity = Menu_pro->addAction(ico_menu_Action,tr("设置为活动工程"));
    connect(act_pro_activity,&QAction::triggered,this,&Form_ProjectManger::event_proMenu_setActive);
    act_pro_build = Menu_pro->addAction(ico_menu_build,tr("构建"));
    connect(act_pro_build,&QAction::triggered,this,&Form_ProjectManger::event_proMenu_build);
    act_pro_clear = Menu_pro->addAction(ico_menu_clear,tr("清理"));
    connect(act_pro_clear,&QAction::triggered,this,&Form_ProjectManger::event_proMenu_clear);
    Menu_pro->addSeparator();//添加分割线
    act_pro_attribute = Menu_pro->addAction(QIcon(),tr("工程属性"));
    connect(act_pro_attribute,&QAction::triggered,this,&Form_ProjectManger::event_proMenu_attribute);
    act_pro_close = Menu_pro->addAction(ico_menu_close,tr("关闭项目"));
    connect(act_pro_close,&QAction::triggered,this,&Form_ProjectManger::event_proMenu_close);
    Menu_pro->addSeparator();//添加分割线
    //connect(t_menuAction,&QAction::triggered,this,&Form_ProjectManger::event_proMenu_Biild);
    //Menu_pro->addSeparator();//添加分割线


    //默认菜单
    Menu_normal = new QMenu(this);
    Menu_normal->addMenu(Menu_addNewFile);
    Menu_normal->addSeparator();//添加分割线
    act_nor_cut = Menu_normal->addAction(QIcon(),tr("剪切"));
    connect(act_nor_cut,&QAction::triggered,this,&Form_ProjectManger::event_norMenu_cut);
    act_nor_copy = Menu_normal->addAction(QIcon(),tr("复制"));
    connect(act_nor_copy,&QAction::triggered,this,&Form_ProjectManger::event_norMenu_copy);
    act_nor_paste = Menu_normal->addAction(QIcon(),tr("粘贴"));
    connect(act_nor_paste,&QAction::triggered,this,&Form_ProjectManger::event_norMenu_paste);
    Menu_normal->addSeparator();//添加分割线
    act_nor_flash = Menu_normal->addAction(ico_menu_check,tr("刷新"));
    connect(act_nor_flash,&QAction::triggered,this,&Form_ProjectManger::event_norMenu_flash);
    act_nor_rename = Menu_normal->addAction(QIcon(),tr("重命名"));
    connect(act_nor_rename,&QAction::triggered,this,&Form_ProjectManger::event_norMenu_rename);
    Menu_normal->addSeparator();//添加分割线
    act_nor_explorer = Menu_normal->addAction(ico_menu_addVisualFolder,tr("在资源管理器打开"));
    connect(act_nor_explorer,&QAction::triggered,this,&Form_ProjectManger::event_norMenu_explorer);
    Menu_normal->addSeparator();//添加分割线
    act_nor_remove = Menu_normal->addAction(QIcon(),tr("删除"));
    connect(act_nor_remove,&QAction::triggered,this,&Form_ProjectManger::event_norMenu_remove);
    Menu_normal->addSeparator();//添加分割线
}


//是否存在此路径
bool Form_ProjectManger::existPath(QString path)
{
    for(int a = 0; a < this->projectArray.length(); a++){
        for(int i = 0; i < this->projectArray[a]->itemNodes.length(); i++){
            if(this->projectArray[a]->itemNodes[i].path.indexOf(path) != -1){
                return true;
            }
        }
    }
    return false;
}


//删除也有此路径的节点
//void Form_ProjectManger::delPath(QString path)
//{

//    //删除父树的QTreeWidgetItem，子树也会一并删除
//    for(int a = 0; a < this->projectArray.length(); a++){
//        for(int i = 0; i < this->projectArray[a]->itemNodes.length(); i++){
//            if(this->projectArray[a]->itemNodes[i].path == path){
//                if(this->projectArray[a]->itemNodes[i].treeItem != nullptr) delete this->projectArray[a]->itemNodes[i].treeItem;
//                this->projectArray[a]->watcher->delLikeLeftPath(path); //watcher停止监视此信息
//                break;
//            }
//        }
//    }

//    //倒找删除子项目信息
//    for(int a = 0; a < this->projectArray.length(); a++){
//        for(int i = this->projectArray[a]->itemNodes.length() - 1; i >= 0 ; i--){
//            if(this->projectArray[a]->itemNodes[i].path.indexOf(path) != -1){
//                this->projectArray[a]->itemNodes.remove(i);
//            }
//        }
//    }
//}


//读取FMS信息
PluginGlobalMsg::ProjectMsg Form_ProjectManger::readProjectMsg(QString fmsFilePath)
{
    QJsonDocument t_jsonDoc = QJsonDocument::fromJson(System_File::readFile(fmsFilePath));
    if(!t_jsonDoc.isObject()) return PluginGlobalMsg::ProjectMsg();
    PluginGlobalMsg::ProjectMsg t_retMsg;
    QJsonObject t_jsonObj = t_jsonDoc.object();
    t_retMsg.proName = t_jsonObj.value("proName").toString("");
    t_retMsg.proIconPath = t_jsonObj.value("proIconPath").toString("");
    t_retMsg.proVerson = t_jsonObj.value("proVerson").toString("1.0.0");
    t_retMsg.proVersonNum = t_jsonObj.value("proVersonNum").toInt(1);
    t_retMsg.proOrg = t_jsonObj.value("proOrg").toString("");
    t_retMsg.proEmail = t_jsonObj.value("proEmail").toString("null");
    t_retMsg.proCall = t_jsonObj.value("proCall").toString("");
    t_retMsg.proNote = t_jsonObj.value("proNote").toString("");
    t_retMsg.proSystem = t_jsonObj.value("proSystem").toString("");
    t_retMsg.proLanguage = t_jsonObj.value("proLanguage").toString("");
    t_retMsg.proNoteClass = t_jsonObj.value("proNoteClass").toString("");
    return t_retMsg;
}


//根据一个路径，在工程列表中查找是否存在这个工程，存在则返回
Form_ProjectManger::ProjectNode* Form_ProjectManger::getProjectNode(QString path)
{
    for(int i = 0; i < this->projectArray.length(); i++){
        ProjectNode* pro  = this->projectArray[i];
        for(auto nodeItem : pro->itemNodes){
            if(nodeItem.path == path){
                return pro;
            }
        }
    }
    return nullptr;
}


//根据一个QTreeWidgetItem指针，在工程列表中查找是否存在这个工程，存在则返回
Form_ProjectManger::ProjectNode *Form_ProjectManger::getProjectNode(QTreeWidgetItem *item)
{
    for(int i = 0; i < this->projectArray.length(); i++){
        ProjectNode* pro  = this->projectArray[i];
        for(auto nodeItem : pro->itemNodes){
            if(nodeItem.treeItem == item){
                return pro;
            }
        }
    }
    return nullptr;
}


//扫描自定路径下的文件信息，构建成节点树，但是不创建QTreeWidgetItem
QVector<Form_ProjectManger::ItemTreeNode> Form_ProjectManger::scanSubNode(QString path)
{
    QVector<ItemTreeNode> fileList;
    QDir directory(path);
    directory.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
    QFileInfoList fileInfoList = directory.entryInfoList();
    foreach (const QFileInfo& fileInfo, fileInfoList) {
        ItemTreeNode t_item; //临时节点存储
        t_item.node.path = fileInfo.filePath();
        if(fileInfo.isDir()){
            t_item.node.type = ItemType::Folder;
            t_item.subItem = this->scanSubNode(t_item.node.path);
        }
        else if(fileInfo.isFile()){
            t_item.node.type = ItemType::File;
            if(fileInfo.fileName() == FMP){
                t_item.node.type = ItemType::project;
            }
            //t_item.node.treeItem = new QTreeWidgetItem;
        }
        fileList.append(t_item); //加入到返回列表
    }
    return fileList;
}


//根据树创建Item
void Form_ProjectManger::createItemFromTree(QVector<ItemTreeNode> &tree)
{
    for(int i = 0; i < tree.length(); i++){
        if(tree[i].node.treeItem == nullptr){
            tree[i].node.treeItem = new QTreeWidgetItem();
            tree[i].node.treeItem->setText(0,QFileInfo(tree[i].node.path).fileName());
            this->createItemFromTree(tree[i].subItem); //给子项创建Item
        }
        //parentItem->addChild(tree[i].node.treeItem);
    }
}


//根据列表创建item
void Form_ProjectManger::cerateItemFromVector(QVector<ItemNode>& list)
{
    for(ItemNode& node : list){
        if(node.treeItem == nullptr){
            node.treeItem = new QTreeWidgetItem();
            node.treeItem->setText(0,QFileInfo(node.path).fileName());
        }
        //parentItem->addChild(tree[i].node.treeItem);
    }
}


//把树节点，添加到记录表
QVector<Form_ProjectManger::ItemNode> Form_ProjectManger::TreeToArray(QVector<ItemTreeNode> &tree)
{
    QVector<ItemNode> t_retArray;
    t_retArray.reserve(50);

    for(int i = 0; i < tree.length(); i++){
        t_retArray.append(tree[i].node);
        if(tree[i].subItem.length() > 0){
            t_retArray.append(this->TreeToArray(tree[i].subItem));
        }
    }
    return t_retArray;
}


//根据列表创建树
QVector<Form_ProjectManger::ItemTreeNode> Form_ProjectManger::ArrayToTree(QVector<ItemNode>& array)
{

    QVector<ItemTreeNode> t_retTree;

    //冒泡排序，从大到小
    for(int a = 0; a < array.length(); a++){
        for(int b = 0; b < array.length() - a - 1; b++){
            if(array[b].path.length() < array[b + 1].path.length()){ //从大到小排序
                ItemNode t_node;
                t_node = array[b];
                array[b] = array[b + 1];
                array[b + 1] = t_node;
            }
        }
    }

    //创建标记组
    int* nums = new int[array.length()];
    for(int a = 0; a < array.length(); a++) nums[a] = 0;


    for(int a = array.length() - 1; a >= 0 ; a--){
        if(nums[a] == 1){continue;} //有标记则跳过
        nums[a] = 1; //标记此处被使用了
        ItemTreeNode t_treeNode;
        t_treeNode.node = array[a];
        QVector<ItemNode> t_subs;
        QString t_scanIndexStr = array[a].path + "/";
        for(int b = a - 1; b >= 0; b--){
            if(nums[b] == 1){continue;} //有标记则跳过
            if(array[b].path.indexOf(t_scanIndexStr) != -1){
                t_subs.append(array[b]);
                nums[b] = 1;//打上标记，后面的跳过此位置
            }
        }

        //递归查找子Node
        if(t_subs.length() > 0){
            t_treeNode.subItem = this->ArrayToTree(t_subs);
        }
        t_retTree.append(t_treeNode);
    }

    //排序节点(从小到大排序)
    for(int x = 0; x < t_retTree.length(); x++){
        for(int y = 0; y < t_retTree.length() - x - 1; y++){
            if(t_retTree[y].node.path.compare(t_retTree[y + 1].node.path) > 0){
                ItemTreeNode t_treeNode = t_retTree[y];
                t_retTree[y] = t_retTree[y + 1];
                t_retTree[y + 1] = t_treeNode;
            }
        }
    }

    //把节点分类
    QVector<ItemTreeNode> t_tNodes;
    t_tNodes.reserve(t_retTree.length());
    for(int i = 0; i < t_retTree.length(); i++){ //工程节点
        if(t_retTree[i].node.type == ItemType::project){
            t_tNodes.append(t_retTree[i]);
        }
    }
    for(int i = 0; i < t_retTree.length(); i++){ //文件夹
        if(t_retTree[i].node.type == ItemType::Folder){t_tNodes.append(t_retTree[i]);}
    }
    for(int i = 0; i < t_retTree.length(); i++){ //文件
        if(t_retTree[i].node.type == ItemType::File){t_tNodes.append(t_retTree[i]);}
    }
    for(int i = 0; i < t_retTree.length(); i++){ //其他
        if(t_retTree[i].node.type != ItemType::project &&
            t_retTree[i].node.type != ItemType::Folder &&
            t_retTree[i].node.type != ItemType::File)
        {t_tNodes.append(t_retTree[i]);}
    }

    delete [] nums;
    return t_tNodes;
}


//调整树信息
void Form_ProjectManger::adjustTree(QVector<ItemTreeNode> tree)
{
    for(int a = 0; a < tree.length(); a++){
        bool t_ex = tree[a].node.treeItem->isExpanded();
        for(int b = 0; b < tree[a].subItem.length(); b++){
            if(tree[a].node.treeItem->child(b) != tree[a].subItem[b].node.treeItem){ //位置不正确，则刷新
                tree[a].node.treeItem->removeChild(tree[a].subItem[b].node.treeItem); //先移除
                tree[a].node.treeItem->insertChild(b,tree[a].subItem[b].node.treeItem); //调整位置
            }
        }
        this->adjustTree(tree[a].subItem);
        tree[a].node.treeItem->setExpanded(t_ex);
    }
}


//清理无效的树（scanPath为包含的路径,checkExists为检查是否存在，如果不检查，则直接移除）
QVector<Form_ProjectManger::ItemTreeNode> Form_ProjectManger::clearSpentTree(QVector<ItemTreeNode> tree, QString scanPath, bool checkExists)
{
    for(int a = tree.length() - 1; a >= 0; a--){
        if(tree[a].node.path.indexOf(scanPath) != -1){


            //递归删除子项目，主要是用于回收子项目itemWidget内存
            if(tree[a].subItem.length() > 0){
                tree[a].subItem = this->clearSpentTree(tree[a].subItem,scanPath,checkExists);
            }


            if(checkExists){ //需要检查是否存在
                if(!QFileInfo(tree[a].node.path).exists()){ //不存在的项目则删除，存在的项目不删除
                    goto ITEMDEL;
                }
            }
            else{
                ITEMDEL:

                //移除所有的TreeWidgetItem(注意，此时不会销毁item)
                for(int b = tree[a].node.treeItem->childCount() - 1; b >= 0; b--){
                    tree[a].node.treeItem->removeChild(tree[a].node.treeItem->child(b));
                }

                //删除TreeWidgetItem
                if(tree[a].node.treeItem != nullptr){
                    delete tree[a].node.treeItem;
                }

                tree.remove(a); //删除当前树对象
            }
        }
    }
    return tree;
}


//清理无效列表
QVector<Form_ProjectManger::ItemNode> Form_ProjectManger::clearSpentList(QVector<ItemNode> list, QString scanPath, bool checkExists)
{
//    QVector<ItemNode> t_retList;
//    t_retList.reserve(t_retList.length());
    for(int a = list.length() - 1; a >= 0; a--){
        if(list[a].path.indexOf(scanPath) != -1){

            if(checkExists){ //需要检查是否存在
                if(!QFileInfo(list[a].path).exists()){ //不存在的项目则删除，存在的项目不删除
                    goto ITEMDEL;
                }
            }
            else{
                ITEMDEL:
                //移除所有的TreeWidgetItem(注意，此时不会销毁item)
                for(int b = list[a].treeItem->childCount() - 1; b >= 0; b--){
                    list[a].treeItem->removeChild(list[a].treeItem->child(b));
                }
                //删除TreeWidgetItem
                if(list[a].treeItem != nullptr){
                    delete list[a].treeItem;
                }
                list.remove(a); //删除当前树对象
            }
        }
    }
    return list;
}


//根据QTreeWidgetItem指针获取节点信息
void Form_ProjectManger::getNodeByTreeWidgetItem(QTreeWidgetItem *item, ItemNode &retNode, ProjectNode *&proPtr)
{
    if(item == nullptr) return;
    for(ProjectNode* proNode : this->projectArray){
        for(ItemNode node : proNode->itemNodes){
            if(node.treeItem == item){
                retNode = node;
                proPtr = proNode;
                return;
            }
        }
    }
}


//融合list2到List1中，返回新的Lsit
QVector<Form_ProjectManger::ItemNode> Form_ProjectManger::fusionNodeLsit(QVector<ItemNode> list1, QVector<ItemNode> list2)
{
    QVector<ItemNode> t_retList;
    t_retList.reserve(list1.length() + list2.length());

    t_retList.append(list1);
    for(ItemNode node2 : list2){
        for(ItemNode node1 : list1){
            if(node2.path == node1.path){ //已经存在此节点，则不在追加
                goto GOOUT;
            }
        }
        //追加新的节点
        t_retList.append(node2);
        GOOUT:
        continue;
    }
        return t_retList;
}


//更新观察对象,重新监测文件对象
void Form_ProjectManger::updateWatcher(ProjectNode* proNodePtr, QVector<ItemNode> list)
{
    if(proNodePtr->watcher != nullptr){delete proNodePtr->watcher;}
    QFileSystemWatcher* watcher = new QFileSystemWatcher;
    connect(watcher,&QFileSystemWatcher::directoryChanged,[=](const QString& path){
    this->directoryChanged(proNodePtr,path);
    }); //连接信号
    QStringList t_strList;
    t_strList.reserve(list.length() + 10);
    for(ItemNode item : list){
        if(item.type == ItemType::Folder || item.type == ItemType::project){
            if(QFileInfo(item.path).isDir()){
                t_strList.append(item.path);
            }
        }
    }
    watcher->addPaths(t_strList);
    proNodePtr->watcher = watcher;
}



//添加Node
void Form_ProjectManger::addItemNode(ProjectNode *proNodePtr, QString path)
{
    QFileInfo info(path);
    if(!info.exists()) return;

    for(auto& item : proNodePtr->itemNodes){
        if(item.path == path){
            return;
        }
    }

    ItemNode t_itemNode;
    t_itemNode.path = path;
    t_itemNode.treeItem = new QTreeWidgetItem;
    t_itemNode.treeItem->setText(0,info.fileName());

    t_itemNode.type = ItemType::Non;
    if(info.isFile()){
        t_itemNode.type = ItemType::File;
    }
    else if(info.isDir()){
        t_itemNode.type = ItemType::Folder;
        proNodePtr->itemNodes.append(t_itemNode);

        //扫描子目录信息
        if(proNodePtr->watcher != nullptr){
            proNodePtr->watcher->addPath(path);
        }
    }


}

//根据路径选择Item，让Item获取焦点
void Form_ProjectManger::selectItemByPath(QString path)
{
    for(int i = 0; i < this->projectArray.length(); i++){
        ProjectNode* pro  = this->projectArray[i];
        for(auto nodeItem : pro->itemNodes){
            if(nodeItem.path == path && nodeItem.treeItem != nullptr){
                nodeItem.treeItem->setSelected(true); //选中Item
            }
        }
    }
}


//文件夹改变
void Form_ProjectManger::directoryChanged(ProjectNode* proNodePtr, const QString &path)
{
    QString newPath = path;
    QFileInfo fileInfo(path);
    if(!fileInfo.exists()){
        newPath = fileInfo.dir().path();
    }
    this->flashProjectPath(proNodePtr,newPath);
}



//从文件或者文件夹添加一个工程
bool Form_ProjectManger::addProject(QString path)
{
    //排除工程节点是否已经存在
    if(this->getProjectNode(path) != nullptr) return false; //根据一个路径，判断是否已经在工程列表中出现

    QFileInfo t_fileInfo(path);
    if(!t_fileInfo.exists()) return false; //文件或者文件夹不存在则添加失败
    //if(this->existPath(path)) return false; //已经存在列表则不添加

    ItemNode t_rootNode; //根节点信息
    t_rootNode.path = path;
    t_rootNode.type = ItemType::project;
    //t_rootNode.treeItem = new QTreeWidgetItem;

    ProjectNode* t_newProject; //新工程节点

    //文件文件夹分开处理
    if(t_fileInfo.isFile()){ //如果是文件
        if(t_fileInfo.fileName() == FMP){ //如果是启动文件，则按照文件夹类型打开
            path = t_fileInfo.path();
            goto ISDIR;
        }
        else{ //如果只是单文件，则按照单文件内容打开
            t_rootNode.treeItem = new QTreeWidgetItem;
            t_rootNode.treeItem->setText(0,t_fileInfo.fileName());

            //工程树
            t_newProject = new ProjectNode;
            t_newProject->itemNodes.append(t_rootNode); //加入根节点信息
            t_newProject->proMsg.proName = t_rootNode.treeItem->text(0); //工程名
            t_newProject->proMsg.proPath = path;

            //加入到UI
            ui->treeWidget->addTopLevelItem(t_rootNode.treeItem);
            //添加到工程信息
            projectArray.append(t_newProject);

            //更改当前活动工程
            //判断工程是否为空，为空则切换工程
            if(nowProject == nullptr){
                nowProject = t_newProject;
                this->onProjectActiveChanged(nowProject->proMsg.proPath,nowProject->proMsg.proLanguage,nowProject->proMsg.proNoteClass);//当活动工程被改变
            }
        }
    }
    else if(t_fileInfo.isDir()){ //如果是文件夹
        ISDIR:
        t_rootNode.path = path; //这里重新赋值的原因是因为可能是pro文件启动的工程

        //创建项目根节点
        t_newProject = new ProjectNode;
        t_newProject->proMsg = this->readProjectMsg(path + "/" + FMP);
        t_newProject->proMsg.proPath = path;

        //创建根节点的TreeItem
        t_rootNode.treeItem = new QTreeWidgetItem;
        QString t_proName = t_newProject->proMsg.proName;
        if(t_proName.isEmpty()){
            t_proName = t_fileInfo.fileName();
            t_newProject->proMsg.proName = t_proName;
        }
        t_rootNode.treeItem->setText(0,t_proName);

        //扫描本地文件，获取工程树
        QVector<ItemTreeNode> t_treeNode =  this->scanSubNode(t_newProject->proMsg.proPath);

        //把数组变为工程树（此时已经排序）
        //t_treeNode =  this->ArrayToTree(t_newProject->itemNodes);

        //把根节点加入到工程节点列表
        t_newProject->itemNodes.append(t_rootNode); //把根节点加入到项目节点组里面

        //给工程树创建QTreeWidgetItem;
        this->createItemFromTree(t_treeNode);

        //把树节点加入到项目的记录表,注意：最开始的根节点并没有添加，防止出现有一个根
        t_newProject->itemNodes.append(this->TreeToArray(t_treeNode));

        //把树节点加入根树节点
        for(int i = 0; i < t_treeNode.length(); i++){
            t_rootNode.treeItem->addChild(t_treeNode[i].node.treeItem);
        }

        //加入到UI
        ui->treeWidget->addTopLevelItem(t_rootNode.treeItem);

        //添加观察者
        this->updateWatcher(t_newProject,t_newProject->itemNodes);

        //将工程根节点与树根节点保存
        projectArray.append(t_newProject);

        //更改当前活动工程
        this->onProjectActiveChanged(t_newProject->proMsg.proPath,t_newProject->proMsg.proLanguage,t_newProject->proMsg.proNoteClass);//当活动工程被改变

        //刷新工程树，调整QTreeWidget结构
        flashProjectTree(t_newProject->proMsg.proPath);

        //判断工程是否为空，为空则切换工程
        if(nowProject == nullptr){
            nowProject = t_newProject;
            this->onProjectActiveChanged(nowProject->proMsg.proPath,nowProject->proMsg.proLanguage,nowProject->proMsg.proNoteClass);//当活动工程被改变
        }
    }

    this->flashProjectIcon(); //刷新工程树的图标
    return true;
}


//关闭工程
bool Form_ProjectManger::closeProject(QString path)
{
    //获取目标根
    for(int i = 0; i < this->projectArray.length(); i++){
        ProjectNode* pro  = this->projectArray[i];
        if(pro->proMsg.proPath == path){
            //回收监视对象
            if(pro->watcher != nullptr){
                delete pro->watcher;
            }

            //删除根QTreeWidgetItem节点
            for(auto nodeItem : pro->itemNodes){
                if(nodeItem.path == path && nodeItem.type == ItemType::project){
                    delete nodeItem.treeItem; //回收最开始的根节点，所有子节点都删除
                }
            }

            //激发工程改变
            if(this->projectArray.length() <= 0){ //已经没有工程
                nowProject = nullptr;
                this->onProjectActiveChanged("","","");
            }
            else{   //还存在其他工程，则尝试打开其他工程
                if(i > 0){
                    nowProject = this->projectArray[i - 1]; //删除的不是第一个，那么自动选择上一个
                }
                else{
                    if(this->projectArray.length() == 1){ //删除的是第一个，且只存在这一个，则工程失效
                        nowProject = nullptr;
                    }
                    else{
                        nowProject = this->projectArray[1]; //删除的是第一个，总长度大于一，那么选择第二个
                    }
                }

                //激发工程改变信息
                if(nowProject){
                    this->onProjectActiveChanged(nowProject->proMsg.proPath,nowProject->proMsg.proLanguage,nowProject->proMsg.proNoteClass);//当活动工程被改变
                }
                else{
                    this->onProjectActiveChanged("","","");//当活动工程被改变
                }
            }

            //工程被关闭信号
            this->onProjectClose(path);

            //回收工程内存
            delete pro;

            //自身信息从工程列表移除
            this->projectArray.remove(i);

            return true;
        }
    }
    return false;
}


//刷新工程的某个路径信息（自动判断是否有效，自动更改观察者）
bool Form_ProjectManger::flashProjectPath(ProjectNode *proNodePtr, QString scanPath)
{
    if(proNodePtr == nullptr) return false; //工程指针为空则返回，并且不处理
    if(!QFileInfo(proNodePtr->proMsg.proPath).exists()){ //工程目标路径已经不存在，则立即关闭工程
        this->closeProject(proNodePtr->proMsg.proPath); //工程不存在，关闭工程
        return false;
    }

    //如果工程根不是文件夹，则不扫描
    if(!QDir(proNodePtr->proMsg.proPath).exists()){
        return false;
    }

    //根据节点组，创建节点树，去除无用的树节点
    QVector<ItemTreeNode> t_tree;
    QVector<ItemNode> t_list;

//    QElapsedTimer timer;
//    timer.start();

    t_tree = this->scanSubNode(scanPath);    //扫描此路径，获取子树结构
    t_list = this->fusionNodeLsit(proNodePtr->itemNodes,this->TreeToArray(t_tree));//将扫描到的新树融合
    t_list = clearSpentList(t_list,scanPath,true); //把已经失效的信息移除
    this->cerateItemFromVector(t_list); //给没有创建TreeWidgetItem的对象创建TreeWidgetItem
    this->adjustTree(ArrayToTree(t_list)); //刷新树结构
    proNodePtr->itemNodes = t_list; //更新节点列表
    this->flashProjectIcon(); //更新图标信息


    //test(ArrayToTree(t_list));

    //重新构建观察着信息
    this->updateWatcher(proNodePtr,proNodePtr->itemNodes); //更新观察者信息
    return true;
}


//刷新工程
bool Form_ProjectManger::flashProjectTree(QString projectPath)
{
    ProjectNode* project = nullptr;
    for(int i = 0; i < this->projectArray.length(); i++){
        if(this->projectArray[i]->proMsg.proPath == projectPath){
            project = this->projectArray[i];
            break;
        }
    }
    if(project == nullptr) return false;
    adjustTree(this->ArrayToTree(project->itemNodes)); //调整树结构对象
}


//刷新工程图标
void Form_ProjectManger::flashProjectIcon(QString projectPath)
{
    this->setFolderIco(ico_normalFolder);
    this->setProjectIco(ico_project);
    for(FileIconNode node : fileIconArray){
        this->setFileIcoBySuffix(node.ico,projectPath,node.suffix);  //根据后缀设置图标
    }
}


//设置目标图标，如果目标为空，则设置类型为non的图标
void Form_ProjectManger::setObjIco(QIcon ico, QString objPath)
{
    for(ProjectNode* proNode : this->projectArray){
        for(ItemNode& item : proNode->itemNodes){
            if(item.path == objPath || (objPath.isEmpty() && item.type == ItemType::Non)){
                item.treeItem->setIcon(0,ico);
                return;
            }
        }
    }
}


//设置文件夹图标,(工程路径，目标路径)
void Form_ProjectManger::setFolderIco(QIcon ico, QString proPath, QString objPath)
{
    for(ProjectNode* proNode : this->projectArray){
        if(proPath.isEmpty() || proNode->proMsg.proPath == proPath){
            for(ItemNode& item : proNode->itemNodes){
                if(item.type == ItemType::Folder){
                    if(objPath.isEmpty() || item.path == objPath){
                        item.treeItem->setIcon(0,ico);
                        if(!objPath.isEmpty()){
                            break;
                        }
                    }
                }
            }
            if(!proPath.isEmpty()){
                return;
            }
        }
    }
}


//设置工程图标，工程路径为空则设置全部工程图标
void Form_ProjectManger::setpRrojectIco(QIcon ico, QString proPath)
{
    for(ProjectNode* proNode : this->projectArray){
        if(proPath.isEmpty() || proNode->proMsg.proPath == proPath){
            for(ItemNode& item : proNode->itemNodes){
                if(item.type == ItemType::project){
                    item.treeItem->setIcon(0,ico);
                }
            }
        }
    }
}


//设置文件图标,(工程路径，目标路径)
void Form_ProjectManger::setFileIco(QIcon ico, QString proPath, QString objPath)
{
    for(ProjectNode* proNode : this->projectArray){
        if(proPath.isEmpty() || proNode->proMsg.proPath == proPath){
            for(ItemNode& item : proNode->itemNodes){
                if(item.type == ItemType::File){
                    if(objPath.isEmpty() || item.path == objPath){
                        item.treeItem->setIcon(0,ico);
                        if(!objPath.isEmpty()){
                            break;
                        }
                    }
                }
            }
            if(!proPath.isEmpty()){
                return;
            }
        }
    }
}


//根据后缀设置文件图标,(工程路径，目标路径)
void Form_ProjectManger::setFileIcoBySuffix(QIcon ico, QString path, QString suffix)
{
    for(ProjectNode* proNode : this->projectArray){
        if(path.isEmpty() || path.indexOf(proNode->proMsg.proPath) == 0){
            for(ItemNode& item : proNode->itemNodes){
                if(item.type == ItemType::File){
                    if(path.isEmpty() || item.path.indexOf(path) == 0){
                        if(QFileInfo(item.path).suffix() == suffix){
                            item.treeItem->setIcon(0,ico);
                        }
                    }
                }
            }
        }
    }
}


//给指定文件后缀的文件添加图标，已存在则覆盖。如果ICO为空，则是删除此ICO信息
void Form_ProjectManger::addFileIco(QString suffix, QIcon ico)
{
    for(int i = 0; i < fileIconArray.length(); i++){
        if(fileIconArray[i].suffix == suffix){
            if(ico.isNull()){
                fileIconArray.remove(i); goto BREAK;
            }
            fileIconArray[i].ico = ico; goto BREAK;
        }
    }
    fileIconArray.append({suffix,ico});
BREAK:
    return;
    //this->setFileIcoBySuffix(ico,"",suffix);    //设置文件图标
}



//设置工程图标
void Form_ProjectManger::setProjectIco(QIcon ico, QString proPath)
{
    for(ProjectNode* proNode : this->projectArray){
        if(proPath.isEmpty() || proNode->proMsg.proPath == proPath){
            for(ItemNode& item : proNode->itemNodes){
                if(item.type == ItemType::project){
                    item.treeItem->setIcon(0,ico);
                }
            }
        }
    }
}



//新增一个文件,返回新增的文件名，如果为空则创建失败
QString Form_ProjectManger::addNewFile(QString path, QString fileName, QString content)
{
    QDir t_dir(path);
    if(!t_dir.exists()) return "";

    QFileInfo t_info(fileName);;
    QString t_newFilePath = path + "/" +fileName;
    unsigned int t_num = 0;

    while(QFile(t_newFilePath).exists()){
        t_num++;
        t_newFilePath = path + "/" + t_info.baseName() + "(" + QString::number(t_num) + ")." + t_info.suffix();
    }

    QFile t_outFile(t_newFilePath);
    if(!t_outFile.open(QIODevice::ReadWrite)) return "";
    t_outFile.write(content.toUtf8());
    t_outFile.close();
    return t_newFilePath;
}


//添加文件夹，若添加成功返回文件夹名
QString Form_ProjectManger::addNewFolder(QString path, QString folderName)
{
    if(!QDir(path).exists()) return "";
    QString t_newPath = path + "/" + folderName;
    unsigned int t_num = 0;

    while(QDir(t_newPath).exists()){
        t_num++;
        t_newPath = path + "/" + folderName + "(" + QString::number(t_num) + ")";
    }

    if(QDir().mkdir(t_newPath)){ //创建单级目录
        return t_newPath;
    }
    else{
        return "";
    }
}


//获取当前工程
PluginGlobalMsg::ProjectMsg Form_ProjectManger::getNowProjectMsg()
{
    if(this->nowProject){
        return this->getProjectMsg(this->nowProject->proMsg.proPath);
    }
    return PluginGlobalMsg::ProjectMsg();
}


//根据一个文件或者文件夹路径，获取已经可用的文件夹路径
QString Form_ProjectManger::getCreatePath(QString srcPath)
{
    QString t_savePath = "";
    QFileInfo t_info(srcPath);
    if(t_info.isDir()){
        t_savePath = srcPath;
    }
    else if(t_info.isFile()){
        t_savePath = t_info.path();
    }
    if(t_savePath.isEmpty()) return "";
    return t_savePath;
}



//获取当前工程信息
PluginGlobalMsg::ProjectMsg Form_ProjectManger::getProjectMsg(QString proPath)
{
    QString t_savePath = "";
    t_savePath = this->getCreatePath(proPath); //获取一个有效的创建路径
    t_savePath = t_savePath.append("/").append(FMP);

    QJsonDocument t_jsonDoc;
    t_jsonDoc = QJsonDocument::fromJson(System_File::readFile(t_savePath));
    QJsonObject t_jsonObj = t_jsonDoc.object();

    PluginGlobalMsg::ProjectMsg t_retMsg;
    t_retMsg.proPath = proPath;
    t_retMsg.proName = t_jsonObj.value("proName").toString("");           //工程名
    t_retMsg.proIconPath = t_jsonObj.value("proIconPath").toString("");           //图标路径
    t_retMsg.proVerson = t_jsonObj.value("proVerson").toString("1.0.0");        //版本信息
    t_retMsg.proVersonNum = t_jsonObj.value("proVersonNum").toInt(1);              //版本号
    t_retMsg.proOrg = t_jsonObj.value("proOrg").toString("");                //社区与公司名称
    t_retMsg.proEmail = t_jsonObj.value("proEmail").toString("null");          //邮箱
    t_retMsg.proCall = t_jsonObj.value("proCall").toString("000-0000-0000");  //电话
    t_retMsg.proNote = t_jsonObj.value("proNote").toString("");               //备注
    t_retMsg.proSystem = t_jsonObj.value("proSystem").toString("");             //操作系统平台标记
    t_retMsg.proLanguage = t_jsonObj.value("proLanguage").toString("");           //语言标记
    t_retMsg.proNoteClass = t_jsonObj.value("proNoteClass").toString("");          //其他备注标记
    return t_retMsg;
}



//保存当前工程信息
bool Form_ProjectManger::saveProjectMsg(QString proPath, PluginGlobalMsg::ProjectMsg proMsg)
{
    QString t_savePath = "";
    t_savePath = this->getCreatePath(proPath); //获取一个有效的创建路径
    if(t_savePath.isEmpty()) return false;

    QJsonDocument t_jsonDoc;
    QJsonObject t_jsonObj;
    t_jsonObj.insert("proName",proMsg.proName);           //工程名
    t_jsonObj.insert("proIconPath",proMsg.proIconPath);           //图标路径
    t_jsonObj.insert("proVerson",proMsg.proVerson);        //版本信息
    t_jsonObj.insert("proVersonNum",proMsg.proVersonNum);              //版本号
    t_jsonObj.insert("proOrg",proMsg.proOrg);                //社区与公司名称
    t_jsonObj.insert("proEmail",proMsg.proEmail);          //邮箱
    t_jsonObj.insert("proCall",proMsg.proCall);  //电话
    t_jsonObj.insert("proNote",proMsg.proNote);               //备注
    t_jsonObj.insert("proSystem",proMsg.proSystem);             //操作系统平台标记
    t_jsonObj.insert("proLanguage",proMsg.proLanguage);           //语言标记
    t_jsonObj.insert("proNoteClass",proMsg.proNoteClass);          //其他备注标记
    t_jsonDoc.setObject(t_jsonObj);
    return System_File::writeFile(t_savePath + "/" + FMP,t_jsonDoc.toJson());
}


//添加创建文件标记（后缀，图标，默认名称，默认内容）
void Form_ProjectManger::addBuildFileSign(QString suffix, QString sign, QIcon ico_16, QString normalName, QString content)
{
    if(!ico_16.isNull()){this->addFileIco(suffix,ico_16);} //新增文件的图标如果不是空，则添加

    for(BuildFileNode& bItem : buildFileArray){
        if(bItem.icoNode.suffix == suffix){
            bItem.icoNode.ico = ico_16;
            bItem.action->setIcon(ico_16);
            bItem.action->setText(sign);
            bItem.normalName = normalName;
            bItem.normalContent = content;
            return;
        }
    }

    BuildFileNode t_bfNode;
    t_bfNode.icoNode.suffix = suffix;
    t_bfNode.icoNode.ico = ico_16;
    t_bfNode.action = new QAction;
    t_bfNode.action->setIcon(ico_16);
    t_bfNode.action->setText(sign);
    t_bfNode.normalName = normalName;
    t_bfNode.normalContent = content;
    Menu_addNewFile->addAction(t_bfNode.action);

    //创建新的文件
    connect(t_bfNode.action,&QAction::triggered,[=]{
        ItemNode t_node;
        ProjectNode* t_proNode = nullptr;
        this->getNodeByTreeWidgetItem(ui->treeWidget->currentItem(),t_node,t_proNode);
        QString t_oPath = getCreatePath(t_node.path);
        if(t_oPath.isEmpty()) return;

        QString t_newName = QInputDialog::getText(this,tr("输入"),tr("新文件名"),QLineEdit::Normal,t_bfNode.normalName);
        if(t_newName.isEmpty()) return;

        int t_lastIndex = t_newName.lastIndexOf("."); //如果已经存在后缀
        QString t_newSuffix = "." + t_bfNode.icoNode.suffix;
        if(t_lastIndex != -1){
            if(t_bfNode.icoNode.suffix == t_newName.right(t_newName.length() - t_lastIndex - 1)){
                t_newSuffix = "";
            }
            else{
                t_newSuffix = "." + t_bfNode.icoNode.suffix;
            }
        }
        this->addNewFile(t_oPath,t_newName + t_newSuffix,t_bfNode.normalContent); //创建新文件
        this->flashProjectPath(t_proNode,t_oPath); //刷新工程树
    });
}


//删除创建文件标记
void Form_ProjectManger::delBuildFileSign(QString suffix)
{
    this->addFileIco(suffix,QIcon()); //清空此后缀的文件信息
    for(int i = buildFileArray.length() - 1; i >= 0; i--){
        if(buildFileArray[i].icoNode.suffix == suffix){
            delete buildFileArray[i].action;
            buildFileArray.remove(i);
            return;
        }
    }

}


//打印树结构
//void Form_ProjectManger::test(QVector<ItemTreeNode> trees, QString str)
//{
//    for(auto item : trees){
//        qDebug() << str + item.node.path << item.node.treeItem;
//        test(item.subItem,str + "----");
//    }
//}






//弹出菜单
void Form_ProjectManger::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    bool isProItem = false;
    QTreeWidgetItem* t_item = ui->treeWidget->currentItem();
    if(!t_item) return; //无工程，不打开右键菜单

    ItemNode t_nodeMsg;
    ProjectNode* t_nowSelectProject;
    for(int a = 0; a<projectArray.length(); a++){
        for(int b = 0; b<projectArray[a]->itemNodes.length(); b++){
            if(projectArray[a]->itemNodes[b].treeItem == t_item){
                t_nowSelectProject = projectArray[a];
                t_nodeMsg = t_nowSelectProject->itemNodes[b];
                goto ITEMMSG;
            }
        }
    }
    ITEMMSG:
    if(t_nodeMsg.treeItem == nullptr){ //判断当前获取的节点数是否正常
        return;
    }

    //如果是工程，且工程还是文件
    if(t_nodeMsg.type == ItemType::project && QFileInfo(t_nodeMsg.path).isFile()){
        this->Menu_addNewFile->setEnabled(false);
    }
    else{
        this->Menu_addNewFile->setEnabled(true);
    }


    //判断是否可粘贴
    QFileInfo t_pasteInfo(this->copyMsg.path);
    if(t_pasteInfo.exists() && QFileInfo(t_nodeMsg.path).isDir()){
        this->act_nor_paste->setEnabled(true);
        this->act_pro_paste->setEnabled(true);
    }
    else{
        this->act_nor_paste->setEnabled(false);
        this->act_pro_paste->setEnabled(false);
    }


    //对文件夹开放刷新菜单，文件项目不显示刷新菜单
    if(QFileInfo(t_nodeMsg.path).isDir()){
        this->act_pro_flash->setEnabled(true);
        this->act_nor_flash->setEnabled(true);
    }
    else{
        this->act_pro_flash->setEnabled(false);
        this->act_nor_flash->setEnabled(false);
    }

    //根据节点类型判断,弹出工程菜单或者普通菜单
    if(t_nodeMsg.type == ItemType::project){
        if(t_nowSelectProject == nowProject){   //判断选择的工程是否为活动工程，如果是活动工程则屏蔽设置当前为活动工程的菜单
            this->act_pro_activity->setEnabled(false);
        }
        else{
            this->act_pro_activity->setEnabled(true);
        }

        Menu_pro->popup(QCursor::pos());
    }
    else if(t_nodeMsg.type == ItemType::File || t_nodeMsg.type == ItemType::Folder){
        Menu_normal->popup(QCursor::pos());
    }
}



//项目被双击，文件被打开
void Form_ProjectManger::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    ItemNode t_node;
    ProjectNode* t_proNode = nullptr;
    this->getNodeByTreeWidgetItem(ui->treeWidget->currentItem(),t_node,t_proNode);
    if(t_node.type == ItemType::File) {
        this->onFileOpen(t_node.path);
    }
}


//工程右键菜单_打开新的工程
void Form_ProjectManger::event_proMneu_openNewProject()
{
    this->onOpenProject();
}

//工程右键菜单_刷新
void Form_ProjectManger::event_proMenu_flash()
{
    ItemNode t_node;
    ProjectNode* t_proNode = nullptr;
    this->getNodeByTreeWidgetItem(ui->treeWidget->currentItem(),t_node,t_proNode);
    if(t_node.type == ItemType::Non || t_proNode == nullptr) return;
    this->flashProjectPath(t_proNode,t_node.path); //刷新工程树
}

//工程右键菜单_粘贴
void Form_ProjectManger::event_proMenu_paste()
{
    this->event_norMenu_paste();
}

//工程右键菜单_在资源管理器打开
void Form_ProjectManger::event_proMenu_explorer()
{
    ItemNode t_node;
    ProjectNode* t_proNode = nullptr;
    this->getNodeByTreeWidgetItem(ui->treeWidget->currentItem(),t_node,t_proNode);
    if(t_node.type == ItemType::Non) return;

    QString t_flashPath = t_node.path;
    QFileInfo t_info(t_node.path);
    if(t_info.isFile()){t_flashPath = t_info.absolutePath();}

    QDesktopServices::openUrl(QUrl::fromLocalFile(t_flashPath));
}

//工程右键菜单_设定为活动工程
void Form_ProjectManger::event_proMenu_setActive()
{
    ProjectNode* t_proNode = this->getProjectNode(ui->treeWidget->currentItem());
    if(t_proNode != nullptr){
        this->nowProject = t_proNode;
        this->onProjectActiveChanged(nowProject->proMsg.proPath,nowProject->proMsg.proLanguage,nowProject->proMsg.proNoteClass);//当活动工程被改变
    }
}

//工程右键菜单_构建项目
void Form_ProjectManger::event_proMenu_build()
{
    ProjectNode* t_proNode = this->getProjectNode(ui->treeWidget->currentItem());
    if(t_proNode != nullptr){
        this->onProjectBuild(t_proNode->proMsg.proPath);
    }
}

//工程右键菜单_清理项目
void Form_ProjectManger::event_proMenu_clear()
{
    ProjectNode* t_proNode = this->getProjectNode(ui->treeWidget->currentItem());
    if(t_proNode != nullptr){
        this->onProjectClear(t_proNode->proMsg.proPath);
    }
}

//工程右键菜单_工程属性
void Form_ProjectManger::event_proMenu_attribute()
{
    ItemNode t_node;
    ProjectNode* t_proNode = nullptr;
    this->getNodeByTreeWidgetItem(ui->treeWidget->currentItem(),t_node,t_proNode);
    if(t_proNode != nullptr){
        this->onProjectAttribute(t_proNode->proMsg.proPath); //投递项目关闭消息
    }
}

//工程右键菜单_关闭项目
void Form_ProjectManger::event_proMenu_close()
{
    ItemNode t_node;
    ProjectNode* t_proNode = nullptr;
    this->getNodeByTreeWidgetItem(ui->treeWidget->currentItem(),t_node,t_proNode);
    if(t_proNode != nullptr){
        this->closeProject(t_proNode->proMsg.proPath);
        //this->onProjectClose(t_proNode->proMsg.proPath); //投递项目关闭消息，这里不用投递，在closeProject，方法里面已经消息投递了
    }
}


//默认菜单_剪切
void Form_ProjectManger::event_norMenu_cut()
{
    this->copyMsg.type = CopyType::Cut;
    ItemNode t_node;
    ProjectNode* t_proNode = nullptr;
    this->getNodeByTreeWidgetItem(ui->treeWidget->currentItem(),t_node,t_proNode);
    this->copyMsg.path = t_node.path;
}

//默认菜单_复制
void Form_ProjectManger::event_norMenu_copy()
{
    copyMsg.type = CopyType::Copy;
    ItemNode t_node;
    ProjectNode* t_proNode = nullptr;
    this->getNodeByTreeWidgetItem(ui->treeWidget->currentItem(),t_node,t_proNode);
    this->copyMsg.path = t_node.path;
}

//默认菜单_粘贴
void Form_ProjectManger::event_norMenu_paste()
{
    ItemNode t_node;
    ProjectNode* t_proNode = nullptr;
    this->getNodeByTreeWidgetItem(ui->treeWidget->currentItem(),t_node,t_proNode);
    QFileInfo t_info(t_node.path);  //t_node.path为复制的文件夹路径
    if(!(t_info.exists() && t_info.isDir())) return;

    QFileInfo t_srcInfo(this->copyMsg.path);
    if(t_srcInfo.isFile()){ //复制文件
        QString t_newFileName = QFileInfo(this->copyMsg.path).fileName();
        if(QFile(t_node.path + "/" + t_newFileName).exists()){
            if(QMessageBox::question(this, tr("提示"), tr("文件已存在，是否覆盖"), QMessageBox::Yes|QMessageBox::No) == QMessageBox::No){return;}
        }
        if(!QFile().copy(this->copyMsg.path,t_node.path + "/" + t_newFileName)) return; //复制文件
    }
    else if(t_srcInfo.isDir()){ //复制目录
        QString t_newFolderName = QDir(this->copyMsg.path).dirName();
        if(QDir(t_node.path + "/" + t_newFolderName).exists()){
            if(QMessageBox::question(this, tr("提示"), tr("目录已存在，是否覆盖"), QMessageBox::Yes|QMessageBox::No) == QMessageBox::No){return;}
        }
        QProgressDialog t_progressDialog;
        t_progressDialog.setWindowTitle(tr("正在拷贝"));//对话框标题
        t_progressDialog.setLabelText("");//对话框文本
        t_progressDialog.setCancelButtonText(tr("取消"));//设置取消按钮
        t_progressDialog.setRange(1,100);//设置进度条范围
        t_progressDialog.setModal(true);//以模态方式弹出对话框
        t_progressDialog.show();

        if(!System_File::copyPath(this->copyMsg.path,t_node.path + "/" + t_newFolderName,[&](int index)->bool{
            t_progressDialog.setValue(index);
            return !t_progressDialog.wasCanceled();
            })){ //复制文件夹
            return;
        }
    }
    this->flashProjectPath(t_proNode,t_node.path);

    //如果是剪切，则删除源目标
    if(this->copyMsg.type == CopyType::Cut){
        if(t_srcInfo.isFile()){
            QFile(this->copyMsg.path).remove();
        }
        else if(t_srcInfo.isDir()){
            //防止剪切的路径是目标的父路径
            if(t_node.path.indexOf(this->copyMsg.path) == 0){ //如果是父路径
                QMessageBox::warning(this,tr("警告"),tr("剪切对象不合法，已使用复制代替！"));
            }
            else{
                QDir(this->copyMsg.path).removeRecursively();
            }
        }
        this->flashProjectPath(t_proNode,t_srcInfo.dir().path()); //扫描父目录
    }

}

//默认菜单_刷新
void Form_ProjectManger::event_norMenu_flash()
{
    this->event_proMenu_flash();
}

//默认菜单_重命名
void Form_ProjectManger::event_norMenu_rename()
{
    ItemNode t_node;
    ProjectNode* t_proNode = nullptr;
    this->getNodeByTreeWidgetItem(ui->treeWidget->currentItem(),t_node,t_proNode);

    QFileInfo t_info(t_node.path);
    if(t_info.isFile()){
        QFile t_file(t_node.path);
        QString t_newName = QInputDialog::getText(this,tr("输入"),tr("新文件名"),QLineEdit::Normal,t_info.fileName());
        if(t_newName.isEmpty()){return;}
        if(t_file.rename(t_info.dir().path() + "/" + t_newName)){
            this->flashProjectPath(t_proNode,t_info.dir().path()); //文件更名成功后刷新
            this->onRename(t_node.path, t_info.dir().path() + "/" + t_newName); //激发文件更名信号
        }
    }
    else if(t_info.isDir()){
        QDir t_dir(t_node.path);
        QString t_newName = QInputDialog::getText(this,tr("输入"),tr("新文件名"),QLineEdit::Normal,t_info.fileName());
        if(t_newName.isEmpty()){return;}

        //移除存在的监视
        QStringList t_pathList = t_proNode->watcher->directories();
        QStringList t_rmList;
        for(QString path : t_pathList){if(path.indexOf(t_node.path) != -1){t_rmList.append(path);}}
        t_proNode->watcher->removePaths(t_rmList);

        //开始重命名
        if(t_dir.rename(t_node.path,t_info.dir().path() + "/" + t_newName)){
            t_proNode->watcher->addPath(t_info.dir().path() + "/" + t_newName); //移除成功，添加新监视
            this->flashProjectPath(t_proNode,t_info.dir().path()); //文件更名成功后刷新
            this->onRename(t_node.path,t_info.dir().path() + "/" + t_newName); //激发文件夹更名信号
        }
        else{
            t_proNode->watcher->addPath(t_node.path); //移除失败，重新添加监视
        }
    }

}

//默认菜单_在资源管理器打开
void Form_ProjectManger::event_norMenu_explorer()
{
    this->event_proMenu_explorer();
}

//默认菜单_删除
void Form_ProjectManger::event_norMenu_remove()
{
    ItemNode t_node;
    ProjectNode* t_proNode = nullptr;
    this->getNodeByTreeWidgetItem(ui->treeWidget->currentItem(),t_node,t_proNode);
    if(QFileInfo(t_node.path).isDir()){
        QDir(t_node.path).removeRecursively();
    }
    else{
        QFile(t_node.path).remove();
    }
    this->flashProjectPath(t_proNode,QFileInfo(t_node.path).dir().path()); //扫描父目录
    this->onFileOrDirDel(t_node.path); //投递删除信号
}

//新建菜单_文件
void Form_ProjectManger::event_newMenu_file()
{


    this->selectItemByPath(""); //根据路径选择Item
}

//新建菜单_文件夹
void Form_ProjectManger::event_newMenu_folder()
{
    ItemNode t_node;
    ProjectNode* t_proNode = nullptr;
    this->getNodeByTreeWidgetItem(ui->treeWidget->currentItem(),t_node,t_proNode);
    QString t_oPath = getCreatePath(t_node.path);
    if(t_oPath.isEmpty()) return;
    QString t_newName = QInputDialog::getText(this,tr("输入"),tr("文件夹名称"),QLineEdit::Normal,"");
    if(t_newName.isEmpty()) return;

    if(QDir(t_oPath + "/" + t_newName).exists()){
        QMessageBox t_msgBox(QMessageBox::Question,tr("提示"), tr("当前文件夹已存在，需要如何操作？"));
        QPushButton* t_cover = t_msgBox.addButton(tr("覆盖"),QMessageBox::DestructiveRole);
        QPushButton* t_rename = t_msgBox.addButton(tr("创建不重名"),QMessageBox::YesRole);
        QPushButton* t_no = t_msgBox.addButton(tr("取消"),QMessageBox::NoRole);
        t_msgBox.exec();

        if(t_msgBox.clickedButton() == (QAbstractButton*)t_cover){ //覆盖
            QDir t_dir(t_oPath + "/" + t_newName);
            t_dir.removeRecursively();
        }
        else if(t_msgBox.clickedButton() == (QAbstractButton*)t_no){
            return;
        }
    }
    this->addNewFolder(t_oPath,t_newName);
    this->flashProjectPath(t_proNode,t_oPath); //刷新工程树
}



