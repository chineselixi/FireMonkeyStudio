#include "Form_WorkSpace.h"
#include "ui_Form_WorkSpace.h"


#include "QDialog"
#include "QFileDialog"
#include "QFileInfo"
#include <QScreen>

#include "SwSystem/System_GlobalVar.h"
#include "SwSystem/system_systemsetting.h"
#include "Plugin/Plugin_Manger.h"

#include "Window/Form_New.h"
#include "Window/Form_ProjectManger.h"
#include "Window/Form_About.h"
#include "Window/Form_PluginManger.h"
#include "Window/Form_SystemSettings.h"

#include "module/mod_WebPage.h"


Form_WorkSpace::Form_WorkSpace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Form_WorkSpace)
{
    ui->setupUi(this);
    Window::workSpace = this;

    this->init(); //初始化代码
    Manger::pluginManger->event_onCompileTypeChanged(PluginGlobalMsg::compileType::debug); //响应编译模式
    Manger::pluginManger->event_onWorkSpaceFinish(); //响应插件workSpace加载完成事件


//==============================临时代码==============================
    //添加工具
//    ui->widget_toolBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Cursor_16x.png"),"指针","Currsor");
//    ui->widget_toolBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/TextBox_16x.png"),"编辑框","Currsor");
//    ui->widget_toolBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Image_16x.png"),"图片框","Currsor");
//    ui->widget_toolBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Panel_16x.png"),"外形框","Currsor");
//    ui->widget_toolBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Label_16x.png"),"标签","Currsor");
//    ui->widget_toolBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Button_16x.png"),"按钮","Currsor");
//    ui->widget_toolBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Checkbox_16x.png"),"选择框","Currsor");
//    ui->widget_toolBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/RadioButton_16x.png"),"单选框","Currsor");
//    ui->widget_toolBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/ComboBox_16x.png"),"组合框","Currsor");
//    ui->widget_toolBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/ListBox_16x.png"),"列表框","Currsor");
//    ui->widget_toolBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/CheckboxList_16x.png"),"选择列表框","Currsor");
//    ui->widget_toolBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/VerticalScrollBarControl_16x.png"),"纵向滚动条","Currsor");
//    ui->widget_toolBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/HorizontalScrollBarControl_16x.png"),"横向滚动条","Currsor");


    //ui->textEdit_print->addLineText("测试红色",qRgb(255,0,0));
    ui->textEdit_print->addLineText("插件系统加载成功！",qRgb(0, 120, 215));
    ui->textEdit_print->addLineText("E:/QtProject/FireMonkeyStudio/release/plg/FireMonkeyStudioBasic/plugin_ideBasic.plg");
    //ui->textEdit_print->addText("左边文本",qRgb(255,0,0));
    //ui->textEdit_print->addText("右边文本");
    //ui->textEdit_print->clearTextEditor();


//    for(int a = 0;a<10;a++){
//        ui->textEdit_compilePrint->addMsg("","加载成功了","","",0);
//    }

//    Form_About* ab = new Form_About;
//    ui->widget_WindowTab->addTabWidget("关于我们",ab,"",QIcon(":/ProjectView/icon/Theme/Blue/Image/ProJectView/Dialog.png"));




}

Form_WorkSpace::~Form_WorkSpace()
{
    Manger::pluginManger->event_onWorkSpaceClose(); //响应插件workSpace加载完成事件
    //delete Manger::pluginManger;
    delete ui;
}


//初始化
void Form_WorkSpace::init()
{
    //窗口剧中
    const QRect t_screen = QGuiApplication::primaryScreen()->geometry();
    this->move( t_screen.center() - this->geometry().center());


    //=================将编译模式选择插入到工具栏=================
    ui->toolBar->insertAction(ui->action_toolBar_compile,ui->toolBar->addWidget(ui->comboBox_compileMode));

    //=================设置主页显示模式=================
    mod_webs = new mod_WebPage(this);
    ui->widget_WindowTab->addTabWidget("主页",mod_webs,"",QIcon(":/WidgetIcon/icon/WidgetIcon/logo/Logo_64.png"),true,PluginGlobalMsg::TabType::web);  //添加到TAB
    mod_webs->setUrl(QUrl("file:" + QApplication::applicationDirPath() + "/web/Start/index.html"));
    mod_webs->show();


    //=================融合部分Dockwidget=================
    this->tabifyDockWidget(ui->dockWidget_compilePrint,ui->dockWidget_find);
    this->tabifyDockWidget(ui->dockWidget_compilePrint,ui->dockWidget_debug);
    ui->dockWidget_compilePrint->raise();


    //=================初始化工程管理事件=================
    connect(ui->widget_ProjectManger,&Form_ProjectManger::onProjectActiveChanged,this,&Form_WorkSpace::event_ProjectManger_onProjectActiveChanged); //工程改变
    connect(ui->widget_ProjectManger,&Form_ProjectManger::onFileOpen,this,&Form_WorkSpace::event_ProjectManger_onFileOpen); //打开文件
    connect(ui->widget_ProjectManger,&Form_ProjectManger::onFileClose,this,&Form_WorkSpace::event_ProjectManger_onFileClose); //文件删除或者关闭
    connect(ui->widget_ProjectManger,&Form_ProjectManger::onProjectBuild,this,&Form_WorkSpace::event_ProjectManger_onProjectBuild); //工程创建完毕
    connect(ui->widget_ProjectManger,&Form_ProjectManger::onProjectClose,this,&Form_WorkSpace::event_ProjectManger_onProjectClose); //工程被关闭
    connect(ui->widget_ProjectManger,&Form_ProjectManger::onFileRename,this,&Form_WorkSpace::event_ProjectManger_onFileRename); //文件被更名


    //=================加载主题样式表=================
    Form_SystemSettings::changeThream(Setting::style_themeName); //加载主题


    //=================插件，函数绑定=================
    //绑定tabView
    PluginGlobalMsg::addTabViewPth t_tabPth
        = [this](QString title,QWidget *form,QString sign,QIcon titeIco,PluginGlobalMsg::TabType type)
    {
        this->ui->widget_WindowTab->addTabWidget(title,form,sign,titeIco,true,type);
    };
    Manger::pluginManger->workSpace_init_tabView(t_tabPth);


    //绑定菜单添加函数
    Manger::pluginManger->workSpace_init_Menu(
        [this](QAction* act){ui->menu_tool->addAction(act);},//toolBar_tool
        [this](QAction* act){ui->menu_set->addAction(act);},//toolBar_set
        [this](QAction* act){ui->menu_help->addAction(act);},//toolBar_help
        [this](QAction* act){ui->menu_view->addAction(act);},//toolBar_view
        [this](QAction* act){ui->menu_expand->addAction(act);},//toolBar_add
        [this](QAction* act){ui->menu_db->addAction(act);},//toolBar_dataBase
        [this](QAction* act){ui->menu_compile->addAction(act);},//toolBar_compile
        [this](QAction* act){ui->menu_insert->addAction(act);},//toolBar_insert
        [this](QAction* act){ui->menu_file->addAction(act);},//toolBar_file
        [this](QAction* act){ui->widget_ProjectManger->Menu_pro->addAction(act);},//ProManger_project
        [this](QAction* act){ui->widget_ProjectManger->Menu_addNewFile->addAction(act);},//ProManger_newFile
        [this](QAction* act){ui->widget_ProjectManger->Menu_normal->addAction(act);});//ProManger_proNormal


    //显示插件的提示信息
    QVector<Plugin_Manger::PluginMsg> t_plgMsgs = Manger::pluginManger->getPluginList();
    for(int a = 0;a<t_plgMsgs.length();a++){
        if(t_plgMsgs[a].plgPth != nullptr){  //只是筛选加载的插件
            ui->textEdit_compilePrint->addMsg("",t_plgMsgs[a].plgPth->getBaseMsg().loadTip,"","",0);
        }
    }

    //初始化代码编辑器接口
//    Manger::pluginManger->workSpace_init_codeEditor(
//        [this](std::function<void (QString leftText,QString rightText,QString lineText,QWidget* codeEditor)> tipEvent)->QWidget*{ //当代码编辑器创建(绑定智能提示)
//            CodeEditor* t_editor = new CodeEditor;

//            QTextCharFormat t_format;
//            t_format.setForeground(QColor(0, 0, 255));
//            t_editor->GetModel_HeighLight()->SetKeyWordFormat(mod_HeighLightEditor::KeyWord1,t_format);
//            t_format.setForeground(QColor(255, 0, 0));
//            t_editor->GetModel_HeighLight()->SetKeyWordFormat(mod_HeighLightEditor::KeyWord2,t_format);
//            t_format.setForeground(QColor(0, 161, 0));
//            t_editor->GetModel_HeighLight()->SetKeyWordFormat(mod_HeighLightEditor::String,t_format);
//            t_format.setForeground(QColor(26, 26, 255));
//            t_editor->GetModel_HeighLight()->SetKeyWordFormat(mod_HeighLightEditor::Sign,t_format);
//            t_format.setForeground(QColor(12, 134, 12));
//            t_editor->GetModel_HeighLight()->SetKeyWordFormat(mod_HeighLightEditor::Note,t_format);

//            t_editor->setFont(QFont("Consolas",16));
//            t_editor->SetLineFont(QFont("Consolas",16));

//            connect(t_editor,&CodeEditor::event_onTipWillShow,[tipEvent,t_editor](QString leftText,QString rightText,QString lineText){
//                tipEvent(leftText,rightText,lineText,(QWidget*)t_editor);
//            });

//            return (QWidget*)t_editor;
//        },
//        [this](QWidget* editor,QVector<QString> keys,int index){ //绑定添加关键字信息
//            CodeEditor* t_editor = (CodeEditor*)editor;
//            t_editor->GetModel_HeighLight()->addKeyWordMsg(keys,index); //添加高亮模块的关键字
//            t_editor->GetModel_Tips()->AddListMsg(mod_TipList::listType::KeyWordList,keys);
//        },
//        [this](QWidget* editor)->QString{ // 获取代码编辑器文本信息
//            CodeEditor* t_editor = (CodeEditor*)editor;
//            return t_editor->toPlainText();
//        },
//        [this](QWidget* editor,QString str){ // 添加代码文本信息
//            CodeEditor* t_editor = (CodeEditor*)editor;
//            t_editor->appendPlainText(str);
//        });




    //同步菜单与工具栏的enable
    Manger::pluginManger->workSpace_init_toolBarActionEnable(
        [this](PluginGlobalMsg::toolBarAction actionType,bool isEnable){ //设定工具栏的Action启用与关闭
            QAction* t_toolBarAction = nullptr;
            switch(actionType){
            case  PluginGlobalMsg::toolBarAction::cut:{t_toolBarAction = this->ui->action_toolBar_cut;break;}//剪切
            case  PluginGlobalMsg::toolBarAction::copy:{t_toolBarAction = this->ui->action_toolBar_copy;break;}//复制
            case  PluginGlobalMsg::toolBarAction::paste:{t_toolBarAction = this->ui->action_toolBar_paste;break;}//粘贴
            case  PluginGlobalMsg::toolBarAction::undo:{t_toolBarAction = this->ui->action_toolBar_undo;break;}//撤销
            case  PluginGlobalMsg::toolBarAction::redo:{t_toolBarAction = this->ui->action_toolBar_redo;break;}//重做
            case  PluginGlobalMsg::toolBarAction::compile:{t_toolBarAction = this->ui->action_toolBar_compile;break;}//编译
            case  PluginGlobalMsg::toolBarAction::staticCompile:{t_toolBarAction = this->ui->action_toolBar_staticCompile;break;}//静态编译
            case  PluginGlobalMsg::toolBarAction::onlineCompile:{t_toolBarAction = this->ui->action_toolBar_onlineCompile;break;}//在线编译
            case  PluginGlobalMsg::toolBarAction::find:{t_toolBarAction = this->ui->action_toolBar_find;break;}//查找
            case  PluginGlobalMsg::toolBarAction::run:{t_toolBarAction = this->ui->action_toolBar_run;break;}//运行
            case  PluginGlobalMsg::toolBarAction::stop:{t_toolBarAction = this->ui->action_toolBar_stop;break;}//停止运行
            case  PluginGlobalMsg::toolBarAction::Rerun:{t_toolBarAction = this->ui->action_toolBar_Rerun;break;}//重新运行
            case  PluginGlobalMsg::toolBarAction::toggleAllBreakpoints:{t_toolBarAction = this->ui->action_toolBar_toggleAllBreakpoints;break;}//切换所有断点
            case  PluginGlobalMsg::toolBarAction::clearBreakpointGroup:{t_toolBarAction = this->ui->action_toolBar_clearBreakpointGroup;break;}//清除断点
            case  PluginGlobalMsg::toolBarAction::debugFind:{t_toolBarAction = this->ui->action_toolBar_debugFind;break;}//调试查找
            case  PluginGlobalMsg::toolBarAction::stepForward:{t_toolBarAction = this->ui->action_toolBar_stepForward;break;}//调试前进
            case  PluginGlobalMsg::toolBarAction::stepOver:{t_toolBarAction = this->ui->action_toolBar_stepOver;break;}//调试跳过
            case  PluginGlobalMsg::toolBarAction::stepIn:{t_toolBarAction = this->ui->action_toolBar_stepIn;break;}//调试进入
            case  PluginGlobalMsg::toolBarAction::stepOut:{t_toolBarAction = this->ui->action_toolBar_stepOut;break;}//调试跳出
            case  PluginGlobalMsg::toolBarAction::toolTip:{t_toolBarAction = this->ui->action_toolBar_toolTip;break;}//工具提示
            case  PluginGlobalMsg::toolBarAction::bookmark:{t_toolBarAction = this->ui->action_toolBar_bookmark;break;}//书签
            case  PluginGlobalMsg::toolBarAction::previousBookmark:{t_toolBarAction = this->ui->action_toolBar_previousBookmark;break;}//上一个书签
            case  PluginGlobalMsg::toolBarAction::nextBookmark:{t_toolBarAction = this->ui->action_toolBar_nextBookmark;break;}//下一个书签
            case  PluginGlobalMsg::toolBarAction::bookmarkMainMenuTabitem:{t_toolBarAction = this->ui->action_toolBar_bookmarkMainMenuTabitem;break;}//书签主菜单
            case  PluginGlobalMsg::toolBarAction::property:{t_toolBarAction = this->ui->action_toolBar_property;break;}//资产
            default:{t_toolBarAction = nullptr;break;}
            }
            if(t_toolBarAction != nullptr) t_toolBarAction->setEnabled(isEnable);
        },
        [this](){ //关闭ToolBar的所有子Action
            QObjectList t_actionList = ui->toolBar->children();
            for(QObjectList::iterator i = t_actionList.begin(); i < t_actionList.end(); i++){
                ((QAction*)(*i))->setEnabled(false);
            }
        });


    //初始化内容输出接口
    Manger::pluginManger->workSpace_init_tipPrint(
        [this](QString code, QString text,QString project,QString file,int row,PluginGlobalMsg::printIcoType type,QColor textColor){ //从列表输出提示
            this->ui->textEdit_compilePrint->addMsg(code,text,project,file,row,type,textColor);
        },
        [this](QColor color,QString printText){ //输出单个文本信息
            this->ui->textEdit_print->addText(printText,color);
        },
        [this](QColor color,QString printText){ //输出一行文本信息
            this->ui->textEdit_print->addLineText(printText,color);
        },
        [this](){ //清理提示列表
            this->ui->textEdit_compilePrint->clearMsg();
        },
        [this](){ //清理文本空间
            this->ui->textEdit_print->clearTextEditor();
        });


    //初始化Dock添加信息
    Manger::pluginManger->workSpace_init_dockWidget(
        [this](Qt::DockWidgetArea area,QDockWidget* dockWidget){
            this->addDockWidget(area,dockWidget);
        },
        [this](QDockWidget* dockWidget){
            this->removeDockWidget(dockWidget);
        });



    //绑定工具栏与菜单栏按钮的触发事件和启用事件
    std::function<void(bool)> t_fun = nullptr;
    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::cut,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_cut,&QAction::triggered,t_fun);
    connect(this->ui->action_editor_cut,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_cut,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_editor_cut->setEnabled(isEnable);});

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::copy,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_copy,&QAction::triggered,t_fun);
    connect(this->ui->action_editor_copy,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_copy,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_editor_copy->setEnabled(isEnable);});//复制

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::paste,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_paste,&QAction::triggered,t_fun);
    connect(this->ui->action_editor_paste,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_paste,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_editor_paste->setEnabled(isEnable);});//粘贴


    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::undo,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_undo,&QAction::triggered,t_fun);
    connect(this->ui->action_editor_undo,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_undo,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_editor_undo->setEnabled(isEnable);});//撤销

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::redo,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_redo,&QAction::triggered,t_fun);
    connect(this->ui->action_editor_redo,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_redo,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_editor_redo->setEnabled(isEnable);});//重做

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::compile,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_compile,&QAction::triggered,t_fun);
    connect(this->ui->action_menu_compile,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_compile,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_menu_compile->setEnabled(isEnable);});//编译

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::staticCompile,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_staticCompile,&QAction::triggered,t_fun);
    connect(this->ui->action_menu_staticCompile,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_staticCompile,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_menu_staticCompile->setEnabled(isEnable);});//静态编译

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::onlineCompile,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_onlineCompile,&QAction::triggered,t_fun);

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::find,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_find,&QAction::triggered,t_fun);
    connect(this->ui->action_editor_quickFind,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_find,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_editor_quickFind->setEnabled(isEnable);});//查找

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::run,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_run,&QAction::triggered,t_fun);
    connect(this->ui->action_menu_run,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_run,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_menu_run->setEnabled(isEnable);});//运行

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::stop,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_stop,&QAction::triggered,t_fun);
    connect(this->ui->action_menu_stop,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_stop,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_menu_stop->setEnabled(isEnable);});//停止运行

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::Rerun,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_Rerun,&QAction::triggered,t_fun);
    connect(this->ui->action_menu_Rerun,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_Rerun,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_menu_Rerun->setEnabled(isEnable);});//重新运行

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::toggleAllBreakpoints,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_toggleAllBreakpoints,&QAction::triggered,t_fun);
    connect(this->ui->action_menu_toggleAllBreakpoints,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_toggleAllBreakpoints,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_menu_toggleAllBreakpoints->setEnabled(isEnable);});//切换所有断点

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::clearBreakpointGroup,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_clearBreakpointGroup,&QAction::triggered,t_fun);
    connect(this->ui->action_menu_clearBreakpointGroup,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_clearBreakpointGroup,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_menu_clearBreakpointGroup->setEnabled(isEnable);});//清除断点

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::debugFind,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_debugFind,&QAction::triggered,t_fun);
    connect(this->ui->action_menu_fileSystemWatcher,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_debugFind,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_menu_fileSystemWatcher->setEnabled(isEnable);});//调试查找

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::stepForward,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_stepForward,&QAction::triggered,t_fun);
    connect(this->ui->action_menu_stepForward,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_stepForward,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_menu_stepForward->setEnabled(isEnable);});//调试前进

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::stepOver,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_stepOver,&QAction::triggered,t_fun);
    connect(this->ui->action_menu_stepOver,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_stepOver,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_menu_stepOver->setEnabled(isEnable);});//调试跳过

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::stepIn,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_stepIn,&QAction::triggered,t_fun);
    connect(this->ui->action_menu_stepIn,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_stepIn,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_menu_stepIn->setEnabled(isEnable);});//调试进入

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::stepOut,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_stepOut,&QAction::triggered,t_fun);
    connect(this->ui->action_menu_stepOut,&QAction::triggered,t_fun);
    connect(this->ui->action_toolBar_stepOut,&QAction::enabledChanged,[this](bool isEnable){this->ui->action_menu_stepOut->setEnabled(isEnable);});//调试跳出

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::toolTip,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_toolTip,&QAction::triggered,t_fun);

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::bookmark,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_bookmark,&QAction::triggered,t_fun);

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::previousBookmark,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_previousBookmark,&QAction::triggered,t_fun);

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::nextBookmark,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_nextBookmark,&QAction::triggered,t_fun);

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::bookmarkMainMenuTabitem,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_bookmarkMainMenuTabitem,&QAction::triggered,t_fun);

    t_fun = [this](bool){Manger::pluginManger->event_onToolBarActionTriggered(PluginGlobalMsg::toolBarAction::property,this->project_path,this->project_lang,this->project_noteClass);};
    connect(this->ui->action_toolBar_property,&QAction::triggered,t_fun);

}



//通过文件或者路径加载工程
void Form_WorkSpace::loadProject()
{
    QFileInfo t_fileInfo(ProjectOpen::projectPath);
    if(!t_fileInfo.exists()) return;
    Form_ProjectManger* t_proManger = (Form_ProjectManger*)ui->widget_ProjectManger; //工程管理器对象
    if(t_fileInfo.isDir()){
        t_proManger->addProjectForDir(t_fileInfo.absoluteFilePath());
    }
    else if(t_fileInfo.isFile()){
        if(t_fileInfo.suffix() == "fmp"){
            t_proManger->addProjectForFmp(t_fileInfo.absoluteFilePath());
        }
        else{
            t_proManger->addProjectForFile(t_fileInfo.absoluteFilePath());
        }
    }
    t_proManger->flashTreeWidget(); //刷新树框
    ProjectOpen::projectPath = "";
}



//新建工程或文件
void Form_WorkSpace::on_action_file_newCreate_triggered()
{
    Form_New* t_newForm = new Form_New(nullptr);
    t_newForm->setWindowModality(Qt::ApplicationModal);
    t_newForm->show();
}

//打开工程文件
void Form_WorkSpace::on_action_file_open_triggered()
{
    QString t_path = QFileDialog::getOpenFileName(this,tr("打开工程文件"),"/Home","工程文件(*.fmp);;所有文件(*.*)");
    if(t_path.isEmpty()) return;
    ProjectOpen::projectPath = t_path; //工程路径
    this->loadProject();
}



//Dock栏目工程管理
void Form_WorkSpace::on_action_dock_project_triggered(bool checked)
{
    if(checked){
        ui->dockWidget_ProjectManger->show();
    }
    else{
        ui->dockWidget_ProjectManger->close();
    }
}

////Dock栏显示，工具箱
//void Form_WorkSpace::on_action_dock_tool_triggered(bool checked)
//{
//    if(checked){
//        ui->dockWidget_toolBox->show();
//    }
//    else{
//        ui->dockWidget_toolBox->close();
//    }
//}

//Dock栏显示，编译输出
void Form_WorkSpace::on_action_dock_compilePrint_triggered(bool checked)
{
    if(checked){
        ui->dockWidget_compilePrint->show();
    }
    else{
        ui->dockWidget_compilePrint->close();
    }
}

//Dock栏显示，输出与提示
void Form_WorkSpace::on_action_dock_runTip_triggered(bool checked)
{
    if(checked){
        ui->dockWidget_print->show();
    }
    else{
        ui->dockWidget_print->close();
    }
}

//Dock栏显示，调试
void Form_WorkSpace::on_action_dock_debug_triggered(bool checked)
{
    if(checked){
        ui->dockWidget_debug->show();
    }
    else{
        ui->dockWidget_debug->close();
    }
}

//Dock栏显示，寻找
void Form_WorkSpace::on_action_dock_find_triggered(bool checked)
{
    if(checked){
        ui->dockWidget_find->show();
    }
    else{
        ui->dockWidget_find->close();
    }
}



//Dock栏控制菜单
void Form_WorkSpace::on_dockWidget_ProjectManger_visibilityChanged(bool visible)
{
    if(ui->dockWidget_ProjectManger->isHidden()){
        ui->action_dock_project->setChecked(false);
    }
    else{
        ui->action_dock_project->setChecked(true);
    }
}

////Dock栏控制菜单
//void Form_WorkSpace::on_dockWidget_toolBox_visibilityChanged(bool visible)
//{
//    if(ui->dockWidget_toolBox->isHidden()){
//        ui->action_dock_tool->setChecked(false);
//    }
//    else{
//        ui->action_dock_tool->setChecked(true);
//    }
//}

//Dock栏控制菜单
void Form_WorkSpace::on_dockWidget_compilePrint_visibilityChanged(bool visible)
{
    if(ui->dockWidget_compilePrint->isHidden()){
        ui->action_dock_compilePrint->setChecked(false);
    }
    else{
        ui->action_dock_compilePrint->setChecked(true);
    }
}

//Dock栏控制菜单
void Form_WorkSpace::on_dockWidget_print_visibilityChanged(bool visible)
{
    if(ui->dockWidget_print->isHidden()){
        ui->action_dock_runTip->setChecked(false);
    }
    else{
        ui->action_dock_runTip->setChecked(true);
    }
}

//Dock栏控制菜单
void Form_WorkSpace::on_dockWidget_debug_visibilityChanged(bool visible)
{
    if(ui->dockWidget_debug->isHidden()){
        ui->action_dock_debug->setChecked(false);
    }
    else{
        ui->action_dock_debug->setChecked(true);
    }
}

//Dock栏控制菜单
void Form_WorkSpace::on_dockWidget_find_visibilityChanged(bool visible)
{
    if(ui->dockWidget_find->isHidden()){
        ui->action_dock_find->setChecked(false);
    }
    else{
        ui->action_dock_find->setChecked(true);
    }
}

//当活动工程被改变
void Form_WorkSpace::event_ProjectManger_onProjectActiveChanged(QString projectPath, QString projectLang,QString projectNoteClass)
{
    this->project_path = projectPath;
    this->project_lang = projectLang;
    this->project_noteClass = projectNoteClass;
    Manger::pluginManger->event_onPorjectLoad(projectPath,projectLang,projectNoteClass); //激发当前工程已经被改变
}

//文件被打开事件
void Form_WorkSpace::event_ProjectManger_onFileOpen(QString filePath)
{
    if(!ui->widget_WindowTab->hasTabMsg(filePath,true)){
        Manger::pluginManger->event_onFileOpen(filePath);
    }
}

//文件被删除或者关闭
void Form_WorkSpace::event_ProjectManger_onFileClose(QString filePath)
{
    Manger::pluginManger->event_onFileClose(filePath);
    qDebug() << "文件被关闭" << filePath;
}

//当项目被构建
void Form_WorkSpace::event_ProjectManger_onProjectBuild(QString projectPath)
{
    qDebug() << "项目被构建" << projectPath;
}

//当项目被关闭
void Form_WorkSpace::event_ProjectManger_onProjectClose(QString projectPath)
{
    qDebug() << "项目被关闭" << projectPath;
}

//文件被更名
void Form_WorkSpace::event_ProjectManger_onFileRename(QString filePath, QString newFilePath)
{
    qDebug() << "文件被更名" << filePath << newFilePath;
}

//插件管理器被打开
void Form_WorkSpace::on_action_pluginManger_triggered()
{
    //打开插件管理器
    Form_PluginManger* t_pluginManger = new Form_PluginManger;
    t_pluginManger->setAttribute(Qt::WA_ShowModal, true); //设置模态,也就是对话窗口模式
    t_pluginManger->show();
}


//关于菜单被按下
void Form_WorkSpace::on_action_menu_about_triggered()
{
    Form_About* t_about = new Form_About;
    t_about->setAttribute(Qt::WA_ShowModal, true);
    t_about->show();
}

//编译模式已经改变
void Form_WorkSpace::on_comboBox_compileMode_currentIndexChanged(int index)
{
    if(index == 0){  //如果是0则为debug模式，如果是
        Manger::pluginManger->event_onCompileTypeChanged(PluginGlobalMsg::compileType::debug);
    }
    else{
        Manger::pluginManger->event_onCompileTypeChanged(PluginGlobalMsg::compileType::release);
    }
}



//同步菜单与工具栏的enable
void Form_WorkSpace::on_action_menu_run_enabledChanged(bool enabled){ui->action_toolBar_run->setEnabled(enabled);}
void Form_WorkSpace::on_action_menu_Rerun_enabledChanged(bool enabled){ui->action_toolBar_Rerun->setEnabled(enabled);}
void Form_WorkSpace::on_action_menu_stop_enabledChanged(bool enabled){ui->action_toolBar_stop->setEnabled(enabled);}
void Form_WorkSpace::on_action_menu_compile_enabledChanged(bool enabled){ui->action_toolBar_compile->setEnabled(enabled);}
void Form_WorkSpace::on_action_menu_staticCompile_enabledChanged(bool enabled){ui->action_toolBar_staticCompile->setEnabled(enabled);}



//菜单栏任务绑定
void Form_WorkSpace::on_action_menu_run_triggered()
{
    Manger::pluginManger->event_onToolBarActionTriggered(
        PluginGlobalMsg::toolBarAction::run,
        this->project_path,
        this->project_lang,
        this->project_noteClass);
}

void Form_WorkSpace::on_action_menu_stop_triggered()
{
    Manger::pluginManger->event_onToolBarActionTriggered(
        PluginGlobalMsg::toolBarAction::stop,
        this->project_path,
        this->project_lang,
        this->project_noteClass);
}

void Form_WorkSpace::on_action_menu_Rerun_triggered()
{
    Manger::pluginManger->event_onToolBarActionTriggered(
        PluginGlobalMsg::toolBarAction::Rerun,
        this->project_path,
        this->project_lang,
        this->project_noteClass);
}


////工具栏任务绑定
//void Form_WorkSpace::on_action_toolBar_run_triggered() //当项目被运行
//{
//    if(!this->project_path.isEmpty()){
//        Manger::pluginManger->event_onRunDown(this->project_path,this->project_lang,this->project_noteClass);
//    }
//}


//void Form_WorkSpace::on_action_toolBar_stop_triggered() //当项目被停止
//{
//    if(!this->project_path.isEmpty()){
//        Manger::pluginManger->event_onRunDown(this->project_path,this->project_lang,this->project_noteClass);
//    }
//}

//void Form_WorkSpace::on_action_toolBar_Rerun_triggered() //当项目被重新运行
//{
//    this->on_action_toolBar_stop_triggered(); //关闭项目
//    this->on_action_toolBar_run_triggered(); //运行项目
//}



//打开系统设置
void Form_WorkSpace::on_action_systemSettings_triggered()
{
    Form_SystemSettings* t_settingForm = new Form_SystemSettings(nullptr);
    t_settingForm->setWindowModality(Qt::ApplicationModal);
    t_settingForm->show();
}





//设置工程管理器样式表
void Form_WorkSpace::setPorMangerStyle(QString style)
{
    ui->widget_ProjectManger->setStyleSheet(style);
}

//设置编译输出样式表
void Form_WorkSpace::setCompilePrintStyle(QString style)
{
    ui->textEdit_compilePrint->setStyleSheet(style);
}

//设置打印样式表
void Form_WorkSpace::setPrintStyle(QString style)
{
    ui->textEdit_print->setStyleSheet(style);
}


//设定主题
void Form_WorkSpace::setTheme(QString themeName)
{
    ui->action_toolBar_blue->setChecked(false);
    ui->action_toolBar_white->setChecked(false);
    ui->action_toolBar_Dark->setChecked(false);

    if(themeName == "White"){
        ui->action_toolBar_white->setChecked(true);
    }
    else if(themeName == "Dark"){
        ui->action_toolBar_Dark->setChecked(true);
    }
    else{
        ui->action_toolBar_blue->setChecked(true);
    }

    Setting::style_themeName = themeName;
    mod_webs->page()->runJavaScript("changeTheme('" + Setting::style_themeName + "')"); //更换web样式
    Setting::sys_setting->changeSetting("Style","theme",Setting::style_themeName); //保存主题样式
}


//切换保存蓝色主题
void Form_WorkSpace::on_action_toolBar_blue_triggered()
{
    Form_SystemSettings::changeThream("Blue"); //加载主题
}

//切换保存白色主题
void Form_WorkSpace::on_action_toolBar_white_triggered()
{
    Form_SystemSettings::changeThream("White"); //加载主题
}

//切换保存黑色主题
void Form_WorkSpace::on_action_toolBar_Dark_triggered()
{
    Form_SystemSettings::changeThream("Dark"); //加载主题
}


