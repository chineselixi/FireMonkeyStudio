#ifndef FORM_WORKSPACE_H
#define FORM_WORKSPACE_H

#include <QMainWindow>


class mod_WebPage; //模块声明
class Widget_Statusbar; //状态栏组件

namespace Ui {
class Form_WorkSpace;
}

class Form_WorkSpace : public QMainWindow
{
    Q_OBJECT
    friend class cppObject; //设定WebEngine的cppobj为友元
public:
    explicit Form_WorkSpace(QWidget *parent = nullptr);
    ~Form_WorkSpace();

protected:
    void resizeEvent(QResizeEvent *event) override; //窗口尺寸改变
    void showEvent(QShowEvent *event) override;     //窗体显示

public:
    void loadProject(); //加载工程
    void init(); //初始化
    void setPorMangerStyle(QString style); //设置工程管理器样式表
    void setCompilePrintStyle(QString style); //设置编译输出样式表
    void setPrintStyle(QString style); //设置打印样式表
    void setTipMangerStyle(QString style); //设置通知管理器主题
    void setTheme(QString themeName); //设定主题
    QMenu* getEditorMenu(); //获取UI对象


private slots:
    void on_action_file_newCreate_triggered(); //新建工程或文件
    void on_action_file_open_triggered(); //打开工程文件


    void on_action_dock_project_triggered(bool checked); //Dock栏显示，工程管理
//    void on_action_dock_tool_triggered(bool checked); //Dock栏显示，工具箱
    void on_action_dock_compilePrint_triggered(bool checked); //Dock栏显示，编译输出
    void on_action_dock_runTip_triggered(bool checked); //Dock栏显示，输出与提示
    void on_action_dock_debug_triggered(bool checked); //Dock栏显示，调试
    void on_action_dock_find_triggered(bool checked); //Dock栏显示，搜索结果

    void on_action_pluginManger_triggered();
    void on_action_menu_about_triggered(); //关于菜单被按下

    void on_menu_theme_aboutToShow();          //主题菜单触发

    void on_dockWidget_ProjectManger_visibilityChanged(bool visible);   //Dock栏控制菜单
//    void on_dockWidget_toolBox_visibilityChanged(bool visible);       //Dock栏控制菜单
    void on_dockWidget_compilePrint_visibilityChanged(bool visible);    //Dock栏控制菜单
    void on_dockWidget_print_visibilityChanged(bool visible);           //Dock栏控制菜单
    void on_dockWidget_debug_visibilityChanged(bool visible);           //Dock栏控制菜单
    void on_dockWidget_find_visibilityChanged(bool visible);            //Dock栏控制菜单

    void on_comboBox_compileMode_currentTextChanged(const QString &arg1); //编译模式被改变

    void on_action_menu_run_enabledChanged(bool enabled); //同步菜单与工具栏的enable
    void on_action_menu_Rerun_enabledChanged(bool enabled);
    void on_action_menu_stop_enabledChanged(bool enabled);
    void on_action_menu_compile_enabledChanged(bool enabled);
    void on_action_menu_staticCompile_enabledChanged(bool enabled);


//    void on_action_toolBar_run_triggered();//工具栏事件
//    void on_action_toolBar_Rerun_triggered();
//    void on_action_toolBar_stop_triggered();

    void on_action_systemSettings_triggered(); //打开系统设置
    void on_action_toolBar_blue_triggered(); //更改蓝色主题
    void on_action_toolBar_white_triggered(); //更改白色主题
    void on_action_toolBar_Dark_triggered(); //更改黑色主题
    void on_action_file_save_triggered(); //保存按钮被按下
    void on_action_file_saveAll_triggered(); //全部保存按钮被按下

private:
    Ui::Form_WorkSpace *ui;
    mod_WebPage* mod_webs; //Web页面模块


    //工程信息
    QString project_path;
    QString project_lang;
    QString project_noteClass;

    //通知栏控件
    Widget_Statusbar* widget_statusbar;

protected:
    //工程管理事件，在init方法内被初始化
    void event_ProjectManger_onProjectActiveChanged(QString projectPath,QString projectLang,QString projectNoteClass); //当活动工程被改变
    void event_ProjectManger_onFileOpen(QString filePath);//文件被打开事件
    void event_ProjectManger_onFileClose(QString filePath);//文件被删除或者关闭
    void event_ProjectManger_onProjectBuild(QString projectPath);//当项目被构建
    void event_ProjectManger_onProjectClose(QString projectPath);//当项目被关闭
    void event_ProjectManger_onFileRename(QString filePath,QString newFilePath);//文件被更名

    //代码编辑器事件


};

#endif // FORM_WORKSPACE_H
