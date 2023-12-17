#ifndef FORM_PROJECTMANGER_H
#define FORM_PROJECTMANGER_H

#include <QWidget>
#include "QVector"
#include "QTreeWidgetItem"


//外部插件声明
namespace PluginGlobalMsg{
struct projectMsgBase; //工程信息基础结构体，仅仅声明，在Plugin_Global.h中有定义
}



namespace Ui {
class Form_ProjectManger;
}

class Form_ProjectManger : public QWidget
{
    Q_OBJECT

    //列表项目类型，先后更改将影响排序信息
    enum listType{
        file_fmp, //启动文件标记
        folder_leftSign,//前缀分类文件夹
        folder_rightSign, //后缀分类文件夹
        folder_hasSign, //存在标记文件夹
        folder_normalSign, //普通文件夹，真实存在与工程目录下
        file_normal, //文件，路径存在于工程目录下
    };

    struct ProjectMsg; //工程完整结构体
    //子项信息信息
    struct itemMsg{
        QString name;
        QString signText;
        listType type;
        QTreeWidgetItem* item = nullptr;
        ProjectMsg* projectPth = nullptr; //父项指针
    };

    //工程信息
    struct ProjectMsg{
        QVector<itemMsg> proItemList;//项目子项列表
        QTreeWidgetItem* proParentItem = nullptr; //父项顶层的ITEM
        QString proPath = ""; //工程目录
        QString proName = "null";//工程名
        QString proIconPath = "";//图标路径
        QString proVerson = "1.0.0";//版本信息
        int proVersonNum = 1;//版本号
        QString proOrg = "";//社区与公司名称
        QString proEmail = "null";//邮箱
        QString proCall = "000-0000-0000";//电话
        QString proNote = "";//备注
        QString proSrcPath = "./src";//源码相对路径
        QString proSystem = ""; //操作系统平台标记
        QString proLanguage = ""; //语言标记
        QString proNoteClass = ""; //其他备注标记
    };

    //专属图标信息
    struct icoMsg{
        QString str;
        QIcon ico;
    };




public:
    explicit Form_ProjectManger(QWidget *parent = nullptr);
    ~Form_ProjectManger();
    QSize sizeHint() const;//获取初始尺寸


    //菜单指针
    QMenu* Menu_pro = nullptr; //工程头右键菜单
    QMenu* Menu_normal = nullptr; //默认菜单
    QMenu* Menu_addNewFile = nullptr; //添加新文件菜单

private:
    Ui::Form_ProjectManger *ui;

    ProjectMsg* NowProjectMsg = nullptr; //当前的项目信息指针
    QVector<ProjectMsg*> ProjectList; //多个项目列表
    QTreeWidgetItem* canEditorItem = nullptr; //当前可编辑的item指针



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

    //文件图标列表
    QVector<icoMsg> icoList_file = {
        {".cpp",ico_fileType_cpp},
        {".h",ico_fileType_h},
        {".c",ico_fileType_c},
        {".java",ico_fileType_java},
        {".js",ico_fileType_js},
        {".json",ico_fileType_json},
        {".py",ico_fileType_py},
        {".php",ico_fileType_php},
        {".jar",ico_fileType_jar},
        {".link",ico_fileType_link},
        {".html",ico_fileType_html},
        {".css",ico_fileType_css},
        {".ini",ico_fileType_ini},
        {".sql",ico_fileType_sql},
        {".txt",ico_fileType_txt},
        {".xml",ico_fileType_xml},
        {".zip",ico_fileType_zip},
        {".uix",ico_window},
        {".ui",ico_window},
        {".fmp",ico_fmp}
    };

    //虚拟文件夹图标列表
    QVector<icoMsg> icoList_visualFolder = {
        {".h",ico_signFolder},
        {".cpp",ico_signFolder},
        {".uix",ico_uiFolder},
        {".res",ico_resFolder},
    };


    QAction* menuAction_setActive = nullptr; //工程切换的右键菜单选项，如果是当前工程则禁用此项目

public:
    bool addProjectForFmp(QString projectFile); //使用Fmp文件添加工程
    bool addProjectForDir(QString dirPath); //使用文件夹添加工程
    bool addProjectForFile(QString filePath); //使用普通文件添加工程

    QTreeWidgetItem* addItem(QString name,QString signText,QIcon ico,ProjectMsg * itemParent,listType type = listType::folder_rightSign); //添加项目并且标记
    void flashTreeWidget(); //刷新树框
    void sortItem(ProjectMsg * itemParent); //刷新工程列表内信息表的排序，按照枚举类型排序
    void initItem(ProjectMsg * itemParent); //移除工程列表所有的Item关联子项关联，方便重新刷新数据
    static QString GetValidPath(QString pathName); //获取有效的文件路径
    static QString GetDirFileName(QString pathDir); //根据路径获取路径的最后一个文件夹
    bool projectExisted(QString proPath); //检查工程是否已经存在
    PluginGlobalMsg::projectMsgBase projectMsgConvertToBase(ProjectMsg msg); //将ProjectMsg转换为PluginGlobalMsg::projectMsgBase
    PluginGlobalMsg::projectMsgBase getProjectMsgBase(QString proPath); //获取工程的基础信息

private:
    void InitMenu();//初始化菜单
    ProjectMsg* Find_ProjectMsg(QTreeWidgetItem* item); //查找Poeject指针，不存在返回nullptr
    itemMsg* Find_ItemMsg(QTreeWidgetItem* item); //查找itemMsg指针，不存在返回nullptr
    QString GetPath(); //获取文件或者文件夹路径
    void AddFile(QString name); //添加一个文件
    bool HasFile(QString filePath); //检查当前工程是否存在这个文件
    void RemoveAllItemChild(QTreeWidgetItem* parent); //移除项目的所有子项Item
    bool RenameItem(); //重命名item,也重命名文件信息
    void Find_DirFile(QString dirPath,QVector<QString>& dirList,QVector<QString>& fileList); //遍历文件夹与子文件夹，还有文件


    //工程右键菜单
    void event_proMenu_Biild(); //构建项目
    void event_proMneu_Clear(); //清理项目
    void event_proMneu_SetActive(); //设定为活动工程
    void event_proMneu_Flash(); //刷新项目
    void event_proMneu_Check(); //验证项目
    void event_proMneu_Close(); //关闭项目

    //普通文件菜单
    void event_menu_addHead(); //添加头文件
    void event_menu_addCpp(); //添加源文件
    void event_menu_addForm(); //添加窗体文件
    void event_menu_addOtherFile(); //添加其他类型文件
    void event_menu_addHasFile(); //添加已有文件
    void event_menu_createNewFolder();//创建文件夹
    void event_menu_createVisualFolder(); //创建虚拟文件夹
    void event_menu_rename(); //重命名
    void event_menu_delete(); //永久删除
    void event_menu_remove(); //从列表移除

    //树框事件
    void event_treeWidget_onItemChanged(); //当前选择的Item被改变

signals:
    void onProjectActiveChanged(QString projectPath,QString projectLang,QString projectNoteClass); //当活动工程被改变
    void onFileOpen(QString filePath);//文件被打开事件
    void onFileClose(QString filePath);//文件被删除或者关闭
    void onProjectBuild(QString projectPath);//当项目被构建
    void onProjectClose(QString projectPath);//当项目被关闭
    void onFileRename(QString filePath,QString newFilePath);//文件被更名

private slots:
    void on_treeWidget_customContextMenuRequested(const QPoint &pos); //弹出右键菜单
    void on_treeWidget_itemChanged(QTreeWidgetItem *item, int column); //项目名称被改变
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
};

#endif // FORM_PROJECTMANGER_H
