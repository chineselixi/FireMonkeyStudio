#ifndef FORM_PROJECTMANGER_H
#define FORM_PROJECTMANGER_H

#include <QWidget>
#include "QVector"
#include "QDesktopServices"
#include "QUrl"
#include "QFileSystemWatcher"

//#include "SwSystem/System_DirWatcher.h"
#include "QTreeWidgetItem"
#include "../Plugin/Plugin_Global.h"

#define FMP "pro.fmp"



namespace Ui {
class Form_ProjectManger;
}

class Form_ProjectManger : public QWidget
{
    Q_OBJECT


    //节点类型
    enum class ItemType{
        File,               //文件
        Folder,             //文件夹
        project,            //工程节点文件夹(吻技安)
        Non,                //未知类型
    };


    //复制类型
    enum class CopyType{
        Copy,
        Cut,
    };


    //节点信息
    struct ItemNode{
        QString path = "";                      //目标路径
        ItemType type = ItemType::Non;          //节点类型
        QTreeWidgetItem* treeItem = nullptr;    //树节点指针
    };


    //节点树信息
    struct ItemTreeNode{
        ItemNode node;
        QVector<ItemTreeNode> subItem;              //子节点信息组
    };


    //工程节点信息
    struct ProjectNode{
        PluginGlobalMsg::ProjectMsg proMsg;                          //工程节点信息
        QVector<ItemNode> itemNodes;                //根节点信息
        QFileSystemWatcher* watcher = nullptr;       //工程监视器
    };


    //文件图标信息
    struct FileIconNode{
        QString suffix;
        QIcon   ico;
    };

    //复制的信息
    struct CopyMsg{
        CopyType type = CopyType::Copy;
        QString path = "";
    };

    //新增文件信息
    struct BuildFileNode{
        FileIconNode icoNode; //图标节点信息，包含后缀
        QString normalName; //默认名称
        QString normalContent = ""; //文本内容信息
        QAction* action = nullptr; //菜单指针
    };

public:
    //菜单指针
    QMenu* Menu_pro = nullptr; //工程菜单
    QMenu* Menu_normal = nullptr; //默认菜单
    QMenu* Menu_addNewFile = nullptr; //添加新文件菜单


private:
    ProjectNode* nowProject = nullptr;           //当前工程指针
    QVector<ProjectNode*> projectArray;          //工程信息
    QVector<FileIconNode> fileIconArray;         //文件图标组
    QVector<BuildFileNode> buildFileArray;       //构建文件数组

    CopyMsg copyMsg;    //复制剪切的信息

    //工程菜单项目指针
    QAction* act_pro_openProject;   //剪切
    QAction* act_pro_cut;           //剪切
    QAction* act_pro_flash;         //刷新
    QAction* act_pro_paste;         //粘贴
    QAction* act_pro_explorer;      //资源管理器
    QAction* act_pro_activity;      //设为活动工程
    QAction* act_pro_build;         //构建
    QAction* act_pro_clear;         //清理
    QAction* act_pro_attribute;     //属性
    QAction* act_pro_close;         //关闭

    //新建菜单项目指针
    QAction* act_new_file;
    QAction* act_new_folder;

    //默认菜单项目指针
    QAction* act_nor_cut;       //剪切
    QAction* act_nor_copy;      //复制
    QAction* act_nor_paste;     //粘贴
    QAction* act_nor_flash;     //刷新
    QAction* act_nor_rename;    //重命名
    QAction* act_nor_explorer;  //资源管理器
    QAction* act_nor_remove;    //删除


public:
    explicit Form_ProjectManger(QWidget *parent = nullptr);
    ~Form_ProjectManger();
    QSize sizeHint() const;//获取初始尺寸




private:
    Ui::Form_ProjectManger *ui;



    QIcon ico_project = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/ProjectSystemSqlCommandVariables_16x.png"); //工程图标
    QIcon ico_fmp = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Class2_16x.png");
    QIcon ico_signFolder = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/LinkedFolder_16x.png");
    QIcon ico_normalFolder = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Folder_16x.png");
    QIcon ico_resFolder = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/ImageScale_16x.png");
    QIcon ico_uiFolder = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Dialog.png");
    QIcon ico_window = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/WindowsForm_16x.png");
    QIcon ico_src = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Namespace_16x.png");
    QIcon ico_null = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/ec.png");

    QIcon ico_menu_build = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Menu/AddClass_16x.png"); //构建菜单
    QIcon ico_menu_clear = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Menu/GoToSourceCode_16x.png"); //清理菜单
    QIcon ico_menu_Action = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Menu/InterfaceSealed_16x.png"); //活动工程
    QIcon ico_menu_check = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Menu/Synchronize_16x.png"); //检查菜单
    QIcon ico_menu_close = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Menu/DeleteClass_16x.png"); //关闭菜单

    QIcon ico_menu_addNewFile = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Menu/AddNamespace_16x.png"); //添加新文件
    QIcon ico_menu_addHasFile = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Menu/AddImage_16x.png"); //添加已有文件
    QIcon ico_menu_addFormFile = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Menu/AddForm_16x.png"); //添加新窗体
    QIcon ico_menu_folder = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Menu/FolderTopPanel_16x.png"); //添加文件夹图标
    QIcon ico_menu_addFolder = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Menu/NewSolutionFolder_16x.png"); //添加文件夹
    QIcon ico_menu_addVisualFolder = QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Menu/ListFolder_16x.png"); //添加虚拟文件夹
    QIcon ico_menu_rename; //重命名
    QIcon ico_menu_delete; //永久删除
    QIcon ico_menu_remove; //移除

    QIcon ico_fileType_unKnow = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/unKnowFile.png");
    QIcon ico_fileType_cpp = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CPP_16x.png");
    QIcon ico_fileType_h = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CPPHeaderFile_16x.png");
    QIcon ico_fileType_c = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/CFile_16x_color.png");
    QIcon ico_fileType_java = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/JavaFile_16x.png");
    QIcon ico_fileType_js = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/JS_16x.png");
    QIcon ico_fileType_json = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/JSONFile_16x.png");
    QIcon ico_fileType_py = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/PY_16x.png");
    QIcon ico_fileType_php = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/PHPFile_16x.png");
    QIcon ico_fileType_jar = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/JARFile_16x.png");
    QIcon ico_fileType_link = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/LinkFile_16x.png");
    QIcon ico_fileType_html = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/HTMLFile_16x.png");
    QIcon ico_fileType_css = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CSSLink_16x.png");
    QIcon ico_fileType_ini = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/SettingsFile_16x.png");
    QIcon ico_fileType_sql = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/SQLFile_16x.png");
    QIcon ico_fileType_txt = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/TextFile_16x.png");
    QIcon ico_fileType_xml = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/XMLFile_16x.png");
    QIcon ico_fileType_zip = QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/ZipFile_16x.png");

    QColor color_Normal = QColor(0,0,0); //默认文本颜色
    QColor color_HasNot = QColor(220,220,220); //不存在文本颜色

private:
    void InitMenu();//初始化菜单
    bool existPath(QString path);   //是否存在此路径
    PluginGlobalMsg::ProjectMsg readProjectMsg(QString fmsFilePath); //读取FMS信息
    ProjectNode* getProjectNode(QString path); //根据一个路径，在工程列表中查找是否存在这个工程，存在则返回
    ProjectNode* getProjectNode(QTreeWidgetItem* item); //根据一个QTreeWidgetItem指针，在工程列表中查找是否存在这个工程，存在则返回
    QVector<ItemTreeNode> scanSubNode(QString paths); //扫描自定路径下的文件信息，构建成节点树，但是不创建QTreeWidgetItem
    void createItemFromTree(QVector<ItemTreeNode>& tree); //根据树创建Item
    void cerateItemFromVector(QVector<ItemNode>& list); //根据列表创建item
    QVector<ItemNode> TreeToArray(QVector<ItemTreeNode>& tree); //把树节点转换为节点
    QVector<ItemTreeNode> ArrayToTree(QVector<ItemNode>& array); //根据列表创建树
    void adjustTree(QVector<ItemTreeNode> tree); //调整树的层次信息
    QVector<ItemTreeNode> clearSpentTree(QVector<ItemTreeNode> tree,QString scanPath, bool checkExists = false); //清理无效的树（scanPath为包含的路径）
    QVector<ItemNode> clearSpentList(QVector<ItemNode> list, QString scanPath, bool checkExists = false); //清理无效列表
    void getNodeByTreeWidgetItem(QTreeWidgetItem* item,ItemNode& retNode,ProjectNode*& proPtr); //根据QTreeWidgetItem指针获取节点信息
    QVector<ItemNode> fusionNodeLsit(QVector<ItemNode> list1,QVector<ItemNode> list2); //融合list2到List1中，返回新的Lsit
    void updateWatcher(ProjectNode* proNodePtr, QVector<ItemNode> list); //更新观察对象
    void addItemNode(ProjectNode* proNodePtr, QString path); //添加Node
    void selectItemByPath(QString path); //根据路径选择Item，让Item获取焦点

    //观察对象事件
    void directoryChanged(ProjectNode* proNodePtr, const QString &path); //文件夹改变
    //void createNewFile(QString name, QString suffix, QString content);

public:
    bool addProject(QString path); //从文件或者文件夹添加一个工程
    bool closeProject(QString path); //关闭工程

    bool flashProjectPath(ProjectNode* proNodePtr,QString scanPath);//刷新工程的某个路径信息（自动判断是否有效，自动更改观察者）
    bool flashProjectTree(QString projectPath); //刷新工程
    void flashProjectIcon(QString projectPath = ""); //刷新工程图标

    void setObjIco(QIcon ico,QString objPath = ""); //设置目标图标，如果目标为空，则设置类型为non的图标
    void setFolderIco(QIcon ico,QString proPath = "", QString objPath = ""); //设置文件夹图标,(工程路径，目标路径)
    void setpRrojectIco(QIcon ico,QString proPath = ""); //设置工程图标，工程路径为空则设置全部工程图标
    void setFileIco(QIcon ico,QString proPath = "", QString objPath = "");   //设置文件图标,(工程路径，目标路径)
    void setFileIcoBySuffix(QIcon ico,QString path = "", QString suffix = "");   //根据后缀设置文件图标,(工程路径，目标路径)
    void setProjectIco(QIcon ico,QString proPath = ""); //设置工程图标

    void addFileIco(QString suffix, QIcon ico); //给指定文件后缀的文件添加图标，已存在则覆盖。如果ICO为空，则是删除此ICO信息
    QString addNewFile(QString path, QString fileName,QString content); //新增一个文件,返回新增的文件名，如果为空则创建失败
    QString addNewFolder(QString path, QString folderName); //添加文件夹，若添加成功返回文件夹名

    PluginGlobalMsg::ProjectMsg getNowProjectMsg(); //获取当前工程
    PluginGlobalMsg::ProjectMsg getProjectMsg(QString proPath); //获取当前工程信息
    QString getCreatePath(QString srcPath); //根据一个文件或者文件夹路径，获取已经可用的文件夹路径
    bool saveProjectMsg(QString proPath, PluginGlobalMsg::ProjectMsg proMsg); //保存指定工程信息

    //菜单操作类
    void addBuildFileSign(QString suffix, QString sign, QIcon ico_16 = QIcon(), QString normalName = "", QString content = "");  //添加创建文件标记（后缀，图标，默认名称，默认内容）
    void delBuildFileSign(QString suffix); //删除创建文件标记

    //void test(QVector<ItemTreeNode> trees,QString str = ""); //打印树结构

signals:
    void onOpenProject(); //当打开工程
    void onProjectActiveChanged(QString projectPath,QString projectLang,QString projectNoteClass); //当活动工程被改变
    void onFileOpen(QString filePath);//文件被打开事件
    void onFileOrDirDel(QString path);//文件或文件夹被删除
    void onProjectBuild(QString projectPath);//当项目被构建
    void onProjectClear(QString projectPath);//当项目被清理
    void onProjectAttribute(QString projectPath);//当查看项目属性
    void onProjectClose(QString projectPath);//当项目被关闭
    void onRename(QString oldPath,QString newPath);//文件或文件夹被更名

private slots:
    void on_treeWidget_customContextMenuRequested(const QPoint &pos); //弹出右键菜单
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column); //Item被双击，通常意味着打开文件

private:
    //工程右键菜单
    void event_proMneu_openNewProject(); //工程右键菜单_打开新的工程
    void event_proMenu_flash(); //工程右键菜单_刷新
    void event_proMenu_paste(); //工程右键菜单_粘贴
    void event_proMenu_explorer(); //工程右键菜单_在资源管理器打开
    void event_proMenu_setActive(); //工程右键菜单_设定为活动工程
    void event_proMenu_build(); //工程右键菜单_构建项目
    void event_proMenu_clear(); //工程右键菜单_清理项目
    void event_proMenu_attribute(); //工程右键菜单_工程属性
    void event_proMenu_close(); //工程右键菜单_关闭项目

    //默认菜单
    void event_norMenu_cut(); //默认菜单_剪切
    void event_norMenu_copy(); //默认菜单_复制
    void event_norMenu_paste();//默认菜单_粘贴
    void event_norMenu_flash(); //默认菜单_刷新
    void event_norMenu_rename(); //默认菜单_重命名
    void event_norMenu_explorer(); //默认菜单_在资源管理器打开
    void event_norMenu_remove(); //默认菜单_删除

    //新建菜单
    void event_newMenu_file(); //新建菜单_文件
    void event_newMenu_folder(); //新建菜单_文件夹

};

#endif // FORM_PROJECTMANGER_H
