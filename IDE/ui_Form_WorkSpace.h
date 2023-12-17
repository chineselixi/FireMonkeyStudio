/********************************************************************************
** Form generated from reading UI file 'Form_WorkSpace.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_WORKSPACE_H
#define UI_FORM_WORKSPACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "Window/Form_ListPrint.h"
#include "Window/Form_ProjectManger.h"
#include "Window/Form_TextPrint.h"
#include "Window/Form_WindowTab.h"

QT_BEGIN_NAMESPACE

class Ui_Form_WorkSpace
{
public:
    QAction *action_toolBar_backward;
    QAction *action_toolBar_forward;
    QAction *action_toolBar_newFileCollection;
    QAction *action_toolBar_open;
    QAction *action_toolBar_save;
    QAction *action_toolBar_cut;
    QAction *action_toolBar_copy;
    QAction *action_toolBar_paste;
    QAction *action_toolBar_undo;
    QAction *action_toolBar_redo;
    QAction *action_toolBar_compile;
    QAction *action_toolBar_staticCompile;
    QAction *action_toolBar_onlineCompile;
    QAction *action_toolBar_find;
    QAction *action_toolBar_run;
    QAction *action_toolBar_stop;
    QAction *action_toolBar_Rerun;
    QAction *action_toolBar_toggleAllBreakpoints;
    QAction *action_toolBar_clearBreakpointGroup;
    QAction *action_toolBar_debugFind;
    QAction *action_toolBar_stepForward;
    QAction *action_toolBar_stepOver;
    QAction *action_toolBar_stepIn;
    QAction *action_toolBar_stepOut;
    QAction *action_toolBar_toolTip;
    QAction *action_toolBar_bookmark;
    QAction *action_toolBar_previousBookmark;
    QAction *action_toolBar_nextBookmark;
    QAction *action_toolBar_bookmarkMainMenuTabitem;
    QAction *action_toolBar_config;
    QAction *action_toolBar_settings;
    QAction *action_toolBar_winLook;
    QAction *action_toolBar_lefr;
    QAction *action_toolBar_right;
    QAction *action_toolBar_top;
    QAction *action_toolBar_bottom;
    QAction *action_toolBar_horizontally_window;
    QAction *action_toolBar_verticalCenter_window;
    QAction *action_toolBar_verticalCenter_widget;
    QAction *action_toolBar_horizontally_widget;
    QAction *action_toolBar_horizontally_avg;
    QAction *action_toolBar_horizontally_avg_2;
    QAction *action_file_newCreate;
    QAction *action_file_open;
    QAction *action_file_close;
    QAction *action_file_save;
    QAction *action_file_saveAll;
    QAction *action_file_print;
    QAction *action_file_config;
    QAction *action_file_connect;
    QAction *action_file_exit;
    QAction *action_editor_undo;
    QAction *action_editor_redo;
    QAction *action_editor_copy;
    QAction *action_editor_cut;
    QAction *action_editor_paste;
    QAction *action_editor_deleteRow;
    QAction *action_editor_quickFind;
    QAction *action_editor_highlightText;
    QAction *action_editor_findNext;
    QAction *action_editor_findPrevious;
    QAction *action_editor_quickReplace;
    QAction *action_editor_findResults;
    QAction *action_editor_jumpLine;
    QAction *action_menu_run;
    QAction *action_menu_Rerun;
    QAction *action_menu_stop;
    QAction *action_menu_fileSystemWatcher;
    QAction *action_menu_stepOver;
    QAction *action_menu_stepIn;
    QAction *action_menu_stepOut;
    QAction *action_menu_stepForward;
    QAction *action_menu_toggleAllBreakpoints;
    QAction *action_menu_termBreakpoint;
    QAction *action_menu_clearBreakpointGroup;
    QAction *action_menu_lineArrow;
    QAction *action_menu_rigidRelationshipError;
    QAction *action_menu_compile;
    QAction *action_menu_staticCompile;
    QAction *action_menu_compleInstall;
    QAction *action_menu_compleSpecifyType;
    QAction *action_menu_staticCompleSpecifyType;
    QAction *action_menu_compleOther;
    QAction *action_menu_feedback;
    QAction *action_menu_TOU;
    QAction *action_menu_devHelper;
    QAction *action_menu_knowledgeBase;
    QAction *action_menu_course;
    QAction *action_menu_certificate;
    QAction *action_menu_devGuide;
    QAction *action_menu_about;
    QAction *action_menu_feedBack;
    QAction *action_menu_cooperation;
    QAction *action_menu_MSDS;
    QAction *action_addNewPlugin;
    QAction *action_pluginManger;
    QAction *action_systemSettings;
    QAction *action_toolBar_attestation;
    QAction *action_toolBar_findInMod;
    QAction *action_toolBar_blue;
    QAction *action_toolBar_white;
    QAction *action_toolBar_Dark;
    QAction *action_toolBar_widthSame;
    QAction *action_toolBar_highSame;
    QAction *action_toolBar_widthHighSame;
    QAction *action_dock_project;
    QAction *action_dock_compilePrint;
    QAction *action_dock_runTip;
    QAction *action_dock_debug;
    QAction *action_dock_find;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QComboBox *comboBox_compileMode;
    Form_WindowTab *widget_WindowTab;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_check;
    QMenu *menu_insert;
    QMenu *menu_db;
    QMenu *menu_debug;
    QMenu *menu_compile;
    QMenu *menu_tool;
    QMenu *menu_expand;
    QMenu *menu_view;
    QMenu *menu_help;
    QMenu *menu_set;
    QMenu *menu_theme;
    QMenu *menu_editor;
    QStatusBar *statusbar;
    QDockWidget *dockWidget_ProjectManger;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_6;
    Form_ProjectManger *widget_ProjectManger;
    QDockWidget *dockWidget_compilePrint;
    QWidget *dockWidgetContents_8;
    QGridLayout *gridLayout_3;
    Form_ListPrint *textEdit_compilePrint;
    QDockWidget *dockWidget_print;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_4;
    Form_TextPrint *textEdit_print;
    QDockWidget *dockWidget_debug;
    QWidget *dockWidgetContents_15;
    QDockWidget *dockWidget_find;
    QWidget *dockWidgetContents_13;
    QGridLayout *gridLayout_7;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *Form_WorkSpace)
    {
        if (Form_WorkSpace->objectName().isEmpty())
            Form_WorkSpace->setObjectName("Form_WorkSpace");
        Form_WorkSpace->resize(1200, 750);
        Form_WorkSpace->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/WidgetIcon/icon/WidgetIcon/logo/Logo_128.png"), QSize(), QIcon::Normal, QIcon::Off);
        Form_WorkSpace->setWindowIcon(icon);
        Form_WorkSpace->setStyleSheet(QString::fromUtf8("/*=============================Form_WorkSpace\347\252\227\345\217\243\344\270\213\351\235\242\347\232\204\346\240\267\345\274\217\350\241\250=============================*/\n"
"/*\344\270\273\347\252\227\345\217\243\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"#Form_WorkSpace{\n"
"	background-color: rgb(93, 107, 153);\n"
"}\n"
"\n"
"/*\345\272\225\351\203\250\347\212\266\346\200\201\346\240\217*/\n"
"QStatusBar{\n"
"	background-color:#40568d;\n"
"	color:rgb(255,255,255);\n"
"}\n"
"\n"
"QStatusBar QToolButton{\n"
"	background-color:#40568d;\n"
"	color:rgb(255,255,255);\n"
"	border:0px;\n"
"	margin-right:4px;\n"
"}\n"
"\n"
"QStatusBar QToolButton:hover{\n"
"	background-color:#6673a4;\n"
"}\n"
"\n"
"QStatusBar QProgressBar{\n"
"	font:9pt;\n"
"	border-radius:5px;\n"
"	text-align:center;\n"
"	border:1px solid #E8EDF2;\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-color: rgb(180, 180, 180);\n"
"}\n"
"\n"
"QStatusBar QProgressBar:chunk{\n"
"	border-radius:5px;\n"
"	background-color:#1ABC9C;\n"
"}\n"
""
                        "\n"
"\n"
"/*\350\217\234\345\215\225\346\240\217*/\n"
"QMenuBar{\n"
"	background-color:rgb(204, 213, 240);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"\n"
"/*\345\267\245\345\205\267\346\240\217*/\n"
"QToolBar{\n"
"	background-color:rgb(204, 213, 240);\n"
"	border:0px;\n"
"}\n"
"\n"
"/*\345\267\245\345\205\267\346\240\217\345\210\206\351\232\224\347\254\246*/\n"
"QToolBar::separator { \n"
"	width: 1px;\n"
"	border:0px;\n"
"	margin:5px 0px;\n"
"	background-image: url(:/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Separator.png);\n"
" }\n"
"\n"
"/*\345\267\245\345\205\267\346\240\217\346\213\226\345\212\250\345\233\276\347\211\207\346\240\217*/\n"
"QToolBar::handle {\n"
"	margin:4px 6px;\n"
"	width:5px;\n"
"	background-image: url(:/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Row1.png);\n"
"}\n"
"\n"
"/*\345\267\245\345\205\267\346\240\217\345\255\220\351\241\271\346\214\211\351\222\256*/\n"
"QToolButton {\n"
"	padding:0px;\n"
"	padding:0px;\n"
"}\n"
"\n"
"/*\346\250\241\345\274\217\351\200\211\346\213\251\346\241\206*/\n"
"#combo"
                        "Box_compileMode{\n"
"	margin:0px 5px;\n"
"}\n"
"\n"
"\n"
"\n"
"/*\351\200\211\346\213\251\346\240\217*/\n"
"QTabBar{\n"
"	border:0px;\n"
"	padding:0px;\n"
"}\n"
"\n"
"/*\351\200\211\346\213\251\345\244\271\347\232\204\345\255\220\345\244\271*/\n"
"QTabBar::tab{\n"
"    background-color: #0B0E11;\n"
"	 /*font-family:Consolas;   \350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\345\255\227\344\275\223*/\n"
"	font-size:8pt;\n"
"	color:rgb(255, 255, 255);    /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\351\242\234\350\211\262*/\n"
"	/*border-top-left-radius: 5px;    \350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\267\246\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	/*border-top-right-radius: 5px;    \350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\217\263\344\270\212\345\234\206\350\247\222"
                        "\357\274\211*/\n"
"	min-width: 100px;\n"
"	margin-right:2px;\n"
"	padding: 5px;\n"
"	background-color: rgb(59, 79, 129);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204tab\350\242\253\351\200\211\344\270\255\346\227\266\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:selected{\n"
"    background-color: rgb(245, 204, 132);\n"
"	color:rgb(58, 52, 42);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255\351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QTabBar\347\232\204tab\344\270\212\357\274\214\344\275\206\346\234\252\351\200\211\344\270\255\350\257\245Tab\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:hover:!selected {\n"
"    background-color: rgb(187, 198, 241);\n"
"	color:rgb(92, 45, 145);\n"
"}\n"
"\n"
"/*Dock\347\232\204\346\226\207\346\234\254\346\241\206*/\n"
"#textEdit_help_tip,#textEdit_print{\n"
"	background-color:rgb(230, 231, 232);\n"
"	color:rgb(42, 42, 42);\n"
"}\n"
"\n"
"\n"
"/*\350\256\276\347\275\256TabWidget\347\232\204\350"
                        "\276\271\346\241\206\347\232\204\346\240\267\345\274\217\n"
"/*\346\265\256\345\212\250\347\252\227\346\240\274*/\n"
"QDockWidget{\n"
"	color:rgb(255,255,255);\n"
"	background-color:rgb(93, 107, 153);\n"
"}\n"
"\n"
"/*\346\265\256\345\212\250\347\252\227\346\240\274\346\240\207\351\242\230\346\240\217*/\n"
"QDockWidget::title {\n"
"    border-style: inset;\n"
"    text-align: left;\n"
"	margin-top: 8px;\n"
"    padding: 3px;\n"
"	color:rgb(255,255,255);\n"
"	background-color:#40568d;\n"
"}\n"
"\n"
"\n"
"/*\345\217\263\351\224\256\350\217\234\345\215\225*/\n"
"QMenu{\n"
"	background-color: rgb(233, 238, 255);\n"
"	border:1px solid rgb(148, 166, 202);\n"
"	padding:2px;\n"
"}\n"
"QMenu::item{\n"
"	color: rgb(30, 30, 31);\n"
"}\n"
"QMenu::item:selected{\n"
"	color: rgb(30, 30, 31);\n"
"	background-color: rgb(177, 197, 255);\n"
"}\n"
"QMenu::separator{\n"
"	background:#bbbbbb;\n"
"    height:1px;\n"
"	margin:5px 10px;\n"
"}\n"
"QMenu:icon{\n"
"	width:16px;\n"
"	height:16px\n"
"}\n"
"QMenu::item:disabled {/*\350\217"
                        "\234\345\215\225\350\242\253\347\246\201\347\224\250*/\n"
"	color: rgb(181, 194, 202);\n"
"}"));
        Form_WorkSpace->setToolButtonStyle(Qt::ToolButtonIconOnly);
        action_toolBar_backward = new QAction(Form_WorkSpace);
        action_toolBar_backward->setObjectName("action_toolBar_backward");
        action_toolBar_backward->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/Backward_16x.png"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Backward_16x.png"), QSize(), QIcon::Disabled, QIcon::On);
        action_toolBar_backward->setIcon(icon1);
        action_toolBar_forward = new QAction(Form_WorkSpace);
        action_toolBar_forward->setObjectName("action_toolBar_forward");
        action_toolBar_forward->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/Forward_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Forward_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_forward->setIcon(icon2);
        action_toolBar_newFileCollection = new QAction(Form_WorkSpace);
        action_toolBar_newFileCollection->setObjectName("action_toolBar_newFileCollection");
        action_toolBar_newFileCollection->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/NewFileCollection_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_toolBar_newFileCollection->setIcon(icon3);
        action_toolBar_open = new QAction(Form_WorkSpace);
        action_toolBar_open->setObjectName("action_toolBar_open");
        action_toolBar_open->setEnabled(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/OpenFolder_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_toolBar_open->setIcon(icon4);
        action_toolBar_save = new QAction(Form_WorkSpace);
        action_toolBar_save->setObjectName("action_toolBar_save");
        action_toolBar_save->setEnabled(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/SaveStatusBar1_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/SaveStatusBar1_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_save->setIcon(icon5);
        action_toolBar_cut = new QAction(Form_WorkSpace);
        action_toolBar_cut->setObjectName("action_toolBar_cut");
        action_toolBar_cut->setEnabled(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/Cut_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Cut_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_cut->setIcon(icon6);
        action_toolBar_copy = new QAction(Form_WorkSpace);
        action_toolBar_copy->setObjectName("action_toolBar_copy");
        action_toolBar_copy->setEnabled(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/Copy_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Copy_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_copy->setIcon(icon7);
        action_toolBar_paste = new QAction(Form_WorkSpace);
        action_toolBar_paste->setObjectName("action_toolBar_paste");
        action_toolBar_paste->setEnabled(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/Paste_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Paste_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_paste->setIcon(icon8);
        action_toolBar_undo = new QAction(Form_WorkSpace);
        action_toolBar_undo->setObjectName("action_toolBar_undo");
        action_toolBar_undo->setEnabled(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/Undo_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Undo_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_undo->setIcon(icon9);
        action_toolBar_redo = new QAction(Form_WorkSpace);
        action_toolBar_redo->setObjectName("action_toolBar_redo");
        action_toolBar_redo->setEnabled(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/Redo_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon10.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Redo_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_redo->setIcon(icon10);
        action_toolBar_compile = new QAction(Form_WorkSpace);
        action_toolBar_compile->setObjectName("action_toolBar_compile");
        action_toolBar_compile->setEnabled(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/BuildSelection_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/BuildSelection_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_compile->setIcon(icon11);
        action_toolBar_staticCompile = new QAction(Form_WorkSpace);
        action_toolBar_staticCompile->setObjectName("action_toolBar_staticCompile");
        action_toolBar_staticCompile->setEnabled(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/BuildSolution_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon12.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/BuildSolution_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_staticCompile->setIcon(icon12);
        action_toolBar_onlineCompile = new QAction(Form_WorkSpace);
        action_toolBar_onlineCompile->setObjectName("action_toolBar_onlineCompile");
        action_toolBar_onlineCompile->setEnabled(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/BuildBlackMoon_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon13.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/BuildBlackMoon_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_onlineCompile->setIcon(icon13);
        action_toolBar_find = new QAction(Form_WorkSpace);
        action_toolBar_find->setObjectName("action_toolBar_find");
        action_toolBar_find->setEnabled(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/SearchInFile_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon14.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/FindResults_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_find->setIcon(icon14);
        action_toolBar_run = new QAction(Form_WorkSpace);
        action_toolBar_run->setObjectName("action_toolBar_run");
        action_toolBar_run->setEnabled(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/Run_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon15.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Run_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_run->setIcon(icon15);
        action_toolBar_stop = new QAction(Form_WorkSpace);
        action_toolBar_stop->setObjectName("action_toolBar_stop");
        action_toolBar_stop->setEnabled(true);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/Stop_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon16.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Stop_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_stop->setIcon(icon16);
        action_toolBar_Rerun = new QAction(Form_WorkSpace);
        action_toolBar_Rerun->setObjectName("action_toolBar_Rerun");
        action_toolBar_Rerun->setEnabled(true);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/Restart_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon17.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Restart_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_Rerun->setIcon(icon17);
        action_toolBar_toggleAllBreakpoints = new QAction(Form_WorkSpace);
        action_toolBar_toggleAllBreakpoints->setObjectName("action_toolBar_toggleAllBreakpoints");
        action_toolBar_toggleAllBreakpoints->setEnabled(true);
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/ToggleAllBreakpoints_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon18.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/ToggleAllBreakpoints_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_toggleAllBreakpoints->setIcon(icon18);
        action_toolBar_clearBreakpointGroup = new QAction(Form_WorkSpace);
        action_toolBar_clearBreakpointGroup->setObjectName("action_toolBar_clearBreakpointGroup");
        action_toolBar_clearBreakpointGroup->setEnabled(true);
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/ClearBreakpointGroup_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon19.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/ClearBreakpointGroup_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_clearBreakpointGroup->setIcon(icon19);
        action_toolBar_debugFind = new QAction(Form_WorkSpace);
        action_toolBar_debugFind->setObjectName("action_toolBar_debugFind");
        action_toolBar_debugFind->setEnabled(true);
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/FileSystemWatcher_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon20.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/FileSystemWatcher_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_debugFind->setIcon(icon20);
        action_toolBar_stepForward = new QAction(Form_WorkSpace);
        action_toolBar_stepForward->setObjectName("action_toolBar_stepForward");
        action_toolBar_stepForward->setEnabled(true);
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/StepForward_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon21.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/StepForward_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_stepForward->setIcon(icon21);
        action_toolBar_stepOver = new QAction(Form_WorkSpace);
        action_toolBar_stepOver->setObjectName("action_toolBar_stepOver");
        action_toolBar_stepOver->setEnabled(true);
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/StepOver_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon22.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/StepOver_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_stepOver->setIcon(icon22);
        action_toolBar_stepIn = new QAction(Form_WorkSpace);
        action_toolBar_stepIn->setObjectName("action_toolBar_stepIn");
        action_toolBar_stepIn->setEnabled(true);
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/StepIn_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon23.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/StepIn_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_stepIn->setIcon(icon23);
        action_toolBar_stepOut = new QAction(Form_WorkSpace);
        action_toolBar_stepOut->setObjectName("action_toolBar_stepOut");
        action_toolBar_stepOut->setEnabled(true);
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/StepOut_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon24.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/StepOut_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_stepOut->setIcon(icon24);
        action_toolBar_toolTip = new QAction(Form_WorkSpace);
        action_toolBar_toolTip->setObjectName("action_toolBar_toolTip");
        action_toolBar_toolTip->setEnabled(true);
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/ToolTip_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon25.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/ToolTip_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_toolTip->setIcon(icon25);
        action_toolBar_bookmark = new QAction(Form_WorkSpace);
        action_toolBar_bookmark->setObjectName("action_toolBar_bookmark");
        action_toolBar_bookmark->setEnabled(true);
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/Bookmark_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon26.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Bookmark_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_bookmark->setIcon(icon26);
        action_toolBar_previousBookmark = new QAction(Form_WorkSpace);
        action_toolBar_previousBookmark->setObjectName("action_toolBar_previousBookmark");
        action_toolBar_previousBookmark->setEnabled(true);
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/PreviousBookmark_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon27.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/PreviousBookmark_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_previousBookmark->setIcon(icon27);
        action_toolBar_nextBookmark = new QAction(Form_WorkSpace);
        action_toolBar_nextBookmark->setObjectName("action_toolBar_nextBookmark");
        action_toolBar_nextBookmark->setEnabled(true);
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/NextBookmark_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon28.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/NextBookmark_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_nextBookmark->setIcon(icon28);
        action_toolBar_bookmarkMainMenuTabitem = new QAction(Form_WorkSpace);
        action_toolBar_bookmarkMainMenuTabitem->setObjectName("action_toolBar_bookmarkMainMenuTabitem");
        action_toolBar_bookmarkMainMenuTabitem->setEnabled(true);
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/BookmarkMainMenuTabItem_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon29.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/BookmarkMainMenuTabItem_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_bookmarkMainMenuTabitem->setIcon(icon29);
        action_toolBar_config = new QAction(Form_WorkSpace);
        action_toolBar_config->setObjectName("action_toolBar_config");
        action_toolBar_config->setEnabled(true);
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/Property_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon30.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Property_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_config->setIcon(icon30);
        action_toolBar_settings = new QAction(Form_WorkSpace);
        action_toolBar_settings->setObjectName("action_toolBar_settings");
        action_toolBar_settings->setEnabled(true);
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/Settings_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon31.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Settings_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_settings->setIcon(icon31);
        action_toolBar_winLook = new QAction(Form_WorkSpace);
        action_toolBar_winLook->setObjectName("action_toolBar_winLook");
        action_toolBar_winLook->setEnabled(false);
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/RunTestDialog_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon32.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/RunTestDialog_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_winLook->setIcon(icon32);
        action_toolBar_lefr = new QAction(Form_WorkSpace);
        action_toolBar_lefr->setObjectName("action_toolBar_lefr");
        action_toolBar_lefr->setEnabled(false);
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/AlignLeft_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon33.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/AlignLeft_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_lefr->setIcon(icon33);
        action_toolBar_right = new QAction(Form_WorkSpace);
        action_toolBar_right->setObjectName("action_toolBar_right");
        action_toolBar_right->setEnabled(false);
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/AlignRight_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon34.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/AlignRight_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_right->setIcon(icon34);
        action_toolBar_top = new QAction(Form_WorkSpace);
        action_toolBar_top->setObjectName("action_toolBar_top");
        action_toolBar_top->setEnabled(false);
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/AlignTop_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon35.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/AlignTop_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_top->setIcon(icon35);
        action_toolBar_bottom = new QAction(Form_WorkSpace);
        action_toolBar_bottom->setObjectName("action_toolBar_bottom");
        action_toolBar_bottom->setEnabled(false);
        QIcon icon36;
        icon36.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/AlignBottom_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon36.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/AlignBottom_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_bottom->setIcon(icon36);
        action_toolBar_horizontally_window = new QAction(Form_WorkSpace);
        action_toolBar_horizontally_window->setObjectName("action_toolBar_horizontally_window");
        action_toolBar_horizontally_window->setEnabled(false);
        QIcon icon37;
        icon37.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/TextCenterInFormHorizontal_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon37.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/TextCenterInFormHorizontal_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_horizontally_window->setIcon(icon37);
        action_toolBar_verticalCenter_window = new QAction(Form_WorkSpace);
        action_toolBar_verticalCenter_window->setObjectName("action_toolBar_verticalCenter_window");
        action_toolBar_verticalCenter_window->setEnabled(false);
        QIcon icon38;
        icon38.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/CenterInFormVertical_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon38.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/CenterInFormVertical_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_verticalCenter_window->setIcon(icon38);
        action_toolBar_verticalCenter_widget = new QAction(Form_WorkSpace);
        action_toolBar_verticalCenter_widget->setObjectName("action_toolBar_verticalCenter_widget");
        action_toolBar_verticalCenter_widget->setEnabled(false);
        QIcon icon39;
        icon39.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/DistributeHorizontalCenter_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon39.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/DistributeHorizontalCenter_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_verticalCenter_widget->setIcon(icon39);
        action_toolBar_horizontally_widget = new QAction(Form_WorkSpace);
        action_toolBar_horizontally_widget->setObjectName("action_toolBar_horizontally_widget");
        action_toolBar_horizontally_widget->setEnabled(false);
        QIcon icon40;
        icon40.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/DistributeVerticalCenter_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon40.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/DistributeVerticalCenter_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_horizontally_widget->setIcon(icon40);
        action_toolBar_horizontally_avg = new QAction(Form_WorkSpace);
        action_toolBar_horizontally_avg->setObjectName("action_toolBar_horizontally_avg");
        action_toolBar_horizontally_avg->setEnabled(false);
        QIcon icon41;
        icon41.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/SpaceAcross_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon41.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/SpaceAcross_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_horizontally_avg->setIcon(icon41);
        action_toolBar_horizontally_avg_2 = new QAction(Form_WorkSpace);
        action_toolBar_horizontally_avg_2->setObjectName("action_toolBar_horizontally_avg_2");
        action_toolBar_horizontally_avg_2->setEnabled(false);
        QIcon icon42;
        icon42.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/SpaceDown_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon42.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/SpaceDown_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_horizontally_avg_2->setIcon(icon42);
        action_file_newCreate = new QAction(Form_WorkSpace);
        action_file_newCreate->setObjectName("action_file_newCreate");
        action_file_newCreate->setCheckable(false);
        action_file_newCreate->setChecked(false);
        QIcon icon43;
        icon43.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/NewFileCollection_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_newCreate->setIcon(icon43);
        action_file_open = new QAction(Form_WorkSpace);
        action_file_open->setObjectName("action_file_open");
        QIcon icon44;
        icon44.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/OpenFileFromProject_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_open->setIcon(icon44);
        action_file_close = new QAction(Form_WorkSpace);
        action_file_close->setObjectName("action_file_close");
        QIcon icon45;
        icon45.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/CloseProject_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_close->setIcon(icon45);
        action_file_save = new QAction(Form_WorkSpace);
        action_file_save->setObjectName("action_file_save");
        QIcon icon46;
        icon46.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/SaveStatusBar1_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_save->setIcon(icon46);
        action_file_saveAll = new QAction(Form_WorkSpace);
        action_file_saveAll->setObjectName("action_file_saveAll");
        action_file_print = new QAction(Form_WorkSpace);
        action_file_print->setObjectName("action_file_print");
        action_file_print->setEnabled(false);
        QIcon icon47;
        icon47.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/Print_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_print->setIcon(icon47);
        action_file_config = new QAction(Form_WorkSpace);
        action_file_config->setObjectName("action_file_config");
        QIcon icon48;
        icon48.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/Property_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_config->setIcon(icon48);
        action_file_connect = new QAction(Form_WorkSpace);
        action_file_connect->setObjectName("action_file_connect");
        action_file_connect->setEnabled(false);
        action_file_exit = new QAction(Form_WorkSpace);
        action_file_exit->setObjectName("action_file_exit");
        action_editor_undo = new QAction(Form_WorkSpace);
        action_editor_undo->setObjectName("action_editor_undo");
        QIcon icon49;
        icon49.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/Undo_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_undo->setIcon(icon49);
        action_editor_redo = new QAction(Form_WorkSpace);
        action_editor_redo->setObjectName("action_editor_redo");
        QIcon icon50;
        icon50.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/Redo_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_redo->setIcon(icon50);
        action_editor_copy = new QAction(Form_WorkSpace);
        action_editor_copy->setObjectName("action_editor_copy");
        QIcon icon51;
        icon51.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/Copy_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_copy->setIcon(icon51);
        action_editor_cut = new QAction(Form_WorkSpace);
        action_editor_cut->setObjectName("action_editor_cut");
        QIcon icon52;
        icon52.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/Cut_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_cut->setIcon(icon52);
        action_editor_paste = new QAction(Form_WorkSpace);
        action_editor_paste->setObjectName("action_editor_paste");
        QIcon icon53;
        icon53.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/Paste_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_paste->setIcon(icon53);
        action_editor_deleteRow = new QAction(Form_WorkSpace);
        action_editor_deleteRow->setObjectName("action_editor_deleteRow");
        action_editor_quickFind = new QAction(Form_WorkSpace);
        action_editor_quickFind->setObjectName("action_editor_quickFind");
        QIcon icon54;
        icon54.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/QuickFind_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_quickFind->setIcon(icon54);
        action_editor_highlightText = new QAction(Form_WorkSpace);
        action_editor_highlightText->setObjectName("action_editor_highlightText");
        QIcon icon55;
        icon55.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/HighlightText_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_highlightText->setIcon(icon55);
        action_editor_findNext = new QAction(Form_WorkSpace);
        action_editor_findNext->setObjectName("action_editor_findNext");
        QIcon icon56;
        icon56.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/FindNext_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_findNext->setIcon(icon56);
        action_editor_findPrevious = new QAction(Form_WorkSpace);
        action_editor_findPrevious->setObjectName("action_editor_findPrevious");
        QIcon icon57;
        icon57.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/FindPrevious_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_findPrevious->setIcon(icon57);
        action_editor_quickReplace = new QAction(Form_WorkSpace);
        action_editor_quickReplace->setObjectName("action_editor_quickReplace");
        QIcon icon58;
        icon58.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/QuickReplace_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_quickReplace->setIcon(icon58);
        action_editor_findResults = new QAction(Form_WorkSpace);
        action_editor_findResults->setObjectName("action_editor_findResults");
        QIcon icon59;
        icon59.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/FindResults_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_findResults->setIcon(icon59);
        action_editor_jumpLine = new QAction(Form_WorkSpace);
        action_editor_jumpLine->setObjectName("action_editor_jumpLine");
        action_menu_run = new QAction(Form_WorkSpace);
        action_menu_run->setObjectName("action_menu_run");
        action_menu_run->setEnabled(false);
        QIcon icon60;
        icon60.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/Run_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_run->setIcon(icon60);
        action_menu_Rerun = new QAction(Form_WorkSpace);
        action_menu_Rerun->setObjectName("action_menu_Rerun");
        action_menu_Rerun->setEnabled(false);
        action_menu_stop = new QAction(Form_WorkSpace);
        action_menu_stop->setObjectName("action_menu_stop");
        action_menu_stop->setEnabled(false);
        QIcon icon61;
        icon61.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/Stop_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_stop->setIcon(icon61);
        action_menu_fileSystemWatcher = new QAction(Form_WorkSpace);
        action_menu_fileSystemWatcher->setObjectName("action_menu_fileSystemWatcher");
        action_menu_fileSystemWatcher->setEnabled(false);
        QIcon icon62;
        icon62.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/FileSystemWatcher_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_fileSystemWatcher->setIcon(icon62);
        action_menu_stepOver = new QAction(Form_WorkSpace);
        action_menu_stepOver->setObjectName("action_menu_stepOver");
        action_menu_stepOver->setEnabled(false);
        QIcon icon63;
        icon63.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/StepOver_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_stepOver->setIcon(icon63);
        action_menu_stepIn = new QAction(Form_WorkSpace);
        action_menu_stepIn->setObjectName("action_menu_stepIn");
        action_menu_stepIn->setEnabled(false);
        QIcon icon64;
        icon64.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/StepIn_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_stepIn->setIcon(icon64);
        action_menu_stepOut = new QAction(Form_WorkSpace);
        action_menu_stepOut->setObjectName("action_menu_stepOut");
        action_menu_stepOut->setEnabled(false);
        QIcon icon65;
        icon65.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/StepOut_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_stepOut->setIcon(icon65);
        action_menu_stepForward = new QAction(Form_WorkSpace);
        action_menu_stepForward->setObjectName("action_menu_stepForward");
        action_menu_stepForward->setEnabled(false);
        QIcon icon66;
        icon66.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/StepForward_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_stepForward->setIcon(icon66);
        action_menu_toggleAllBreakpoints = new QAction(Form_WorkSpace);
        action_menu_toggleAllBreakpoints->setObjectName("action_menu_toggleAllBreakpoints");
        action_menu_toggleAllBreakpoints->setEnabled(false);
        QIcon icon67;
        icon67.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/ToggleAllBreakpoints_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_toggleAllBreakpoints->setIcon(icon67);
        action_menu_termBreakpoint = new QAction(Form_WorkSpace);
        action_menu_termBreakpoint->setObjectName("action_menu_termBreakpoint");
        action_menu_termBreakpoint->setEnabled(false);
        action_menu_clearBreakpointGroup = new QAction(Form_WorkSpace);
        action_menu_clearBreakpointGroup->setObjectName("action_menu_clearBreakpointGroup");
        action_menu_clearBreakpointGroup->setEnabled(false);
        QIcon icon68;
        icon68.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/ClearBreakpointGroup_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_clearBreakpointGroup->setIcon(icon68);
        action_menu_lineArrow = new QAction(Form_WorkSpace);
        action_menu_lineArrow->setObjectName("action_menu_lineArrow");
        action_menu_lineArrow->setEnabled(false);
        QIcon icon69;
        icon69.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/LineArrow_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_lineArrow->setIcon(icon69);
        action_menu_rigidRelationshipError = new QAction(Form_WorkSpace);
        action_menu_rigidRelationshipError->setObjectName("action_menu_rigidRelationshipError");
        action_menu_rigidRelationshipError->setEnabled(false);
        QIcon icon70;
        icon70.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/RigidRelationshipError_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_rigidRelationshipError->setIcon(icon70);
        action_menu_compile = new QAction(Form_WorkSpace);
        action_menu_compile->setObjectName("action_menu_compile");
        action_menu_compile->setEnabled(false);
        QIcon icon71;
        icon71.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/BuildSelection_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_compile->setIcon(icon71);
        action_menu_staticCompile = new QAction(Form_WorkSpace);
        action_menu_staticCompile->setObjectName("action_menu_staticCompile");
        action_menu_staticCompile->setEnabled(false);
        QIcon icon72;
        icon72.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/BuildSolution_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_staticCompile->setIcon(icon72);
        action_menu_compleInstall = new QAction(Form_WorkSpace);
        action_menu_compleInstall->setObjectName("action_menu_compleInstall");
        action_menu_compleInstall->setEnabled(false);
        action_menu_compleSpecifyType = new QAction(Form_WorkSpace);
        action_menu_compleSpecifyType->setObjectName("action_menu_compleSpecifyType");
        action_menu_compleSpecifyType->setEnabled(false);
        action_menu_staticCompleSpecifyType = new QAction(Form_WorkSpace);
        action_menu_staticCompleSpecifyType->setObjectName("action_menu_staticCompleSpecifyType");
        action_menu_staticCompleSpecifyType->setEnabled(false);
        action_menu_compleOther = new QAction(Form_WorkSpace);
        action_menu_compleOther->setObjectName("action_menu_compleOther");
        action_menu_compleOther->setCheckable(false);
        action_menu_compleOther->setEnabled(false);
        action_menu_compleOther->setVisible(true);
        action_menu_compleOther->setShortcutVisibleInContextMenu(true);
        action_menu_feedback = new QAction(Form_WorkSpace);
        action_menu_feedback->setObjectName("action_menu_feedback");
        QIcon icon73;
        icon73.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/FeedbackSmile_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_feedback->setIcon(icon73);
        action_menu_TOU = new QAction(Form_WorkSpace);
        action_menu_TOU->setObjectName("action_menu_TOU");
        action_menu_devHelper = new QAction(Form_WorkSpace);
        action_menu_devHelper->setObjectName("action_menu_devHelper");
        action_menu_knowledgeBase = new QAction(Form_WorkSpace);
        action_menu_knowledgeBase->setObjectName("action_menu_knowledgeBase");
        action_menu_course = new QAction(Form_WorkSpace);
        action_menu_course->setObjectName("action_menu_course");
        action_menu_course->setEnabled(false);
        action_menu_certificate = new QAction(Form_WorkSpace);
        action_menu_certificate->setObjectName("action_menu_certificate");
        action_menu_certificate->setEnabled(false);
        QIcon icon74;
        icon74.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/Certificate_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_certificate->setIcon(icon74);
        action_menu_devGuide = new QAction(Form_WorkSpace);
        action_menu_devGuide->setObjectName("action_menu_devGuide");
        action_menu_about = new QAction(Form_WorkSpace);
        action_menu_about->setObjectName("action_menu_about");
        QIcon icon75;
        icon75.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/StatusHelp_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_about->setIcon(icon75);
        action_menu_feedBack = new QAction(Form_WorkSpace);
        action_menu_feedBack->setObjectName("action_menu_feedBack");
        action_menu_cooperation = new QAction(Form_WorkSpace);
        action_menu_cooperation->setObjectName("action_menu_cooperation");
        action_menu_MSDS = new QAction(Form_WorkSpace);
        action_menu_MSDS->setObjectName("action_menu_MSDS");
        action_addNewPlugin = new QAction(Form_WorkSpace);
        action_addNewPlugin->setObjectName("action_addNewPlugin");
        QIcon icon76;
        icon76.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/CreateLibraryEnvironment_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_addNewPlugin->setIcon(icon76);
        action_pluginManger = new QAction(Form_WorkSpace);
        action_pluginManger->setObjectName("action_pluginManger");
        QIcon icon77;
        icon77.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/LibrarySetting_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_pluginManger->setIcon(icon77);
        action_systemSettings = new QAction(Form_WorkSpace);
        action_systemSettings->setObjectName("action_systemSettings");
        QIcon icon78;
        icon78.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/Settings_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_systemSettings->setIcon(icon78);
        action_toolBar_attestation = new QAction(Form_WorkSpace);
        action_toolBar_attestation->setObjectName("action_toolBar_attestation");
        action_toolBar_attestation->setIcon(icon74);
        action_toolBar_findInMod = new QAction(Form_WorkSpace);
        action_toolBar_findInMod->setObjectName("action_toolBar_findInMod");
        action_toolBar_blue = new QAction(Form_WorkSpace);
        action_toolBar_blue->setObjectName("action_toolBar_blue");
        action_toolBar_blue->setCheckable(true);
        action_toolBar_blue->setChecked(true);
        action_toolBar_blue->setEnabled(true);
        QIcon icon79;
        icon79.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/CheckboxN_16x.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon79.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/MenuBar/Checkbox_16x.png"), QSize(), QIcon::Selected, QIcon::On);
        action_toolBar_blue->setIcon(icon79);
        action_toolBar_white = new QAction(Form_WorkSpace);
        action_toolBar_white->setObjectName("action_toolBar_white");
        action_toolBar_white->setCheckable(true);
        action_toolBar_white->setEnabled(true);
        action_toolBar_white->setIcon(icon79);
        action_toolBar_Dark = new QAction(Form_WorkSpace);
        action_toolBar_Dark->setObjectName("action_toolBar_Dark");
        action_toolBar_Dark->setCheckable(true);
        action_toolBar_Dark->setEnabled(true);
        action_toolBar_Dark->setIcon(icon79);
        action_toolBar_widthSame = new QAction(Form_WorkSpace);
        action_toolBar_widthSame->setObjectName("action_toolBar_widthSame");
        action_toolBar_widthSame->setEnabled(false);
        QIcon icon80;
        icon80.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/AutosizeFixedWidth_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon80.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/AutosizeFixedWidth_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_widthSame->setIcon(icon80);
        action_toolBar_highSame = new QAction(Form_WorkSpace);
        action_toolBar_highSame->setObjectName("action_toolBar_highSame");
        action_toolBar_highSame->setEnabled(false);
        QIcon icon81;
        icon81.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/TextLineHeight_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon81.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/TextLineHeight_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_highSame->setIcon(icon81);
        action_toolBar_widthHighSame = new QAction(Form_WorkSpace);
        action_toolBar_widthHighSame->setObjectName("action_toolBar_widthHighSame");
        action_toolBar_widthHighSame->setEnabled(false);
        QIcon icon82;
        icon82.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/AutosizeOptimize_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon82.addFile(QString::fromUtf8(":/Theme/Blue/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/AutosizeOptimize_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_widthHighSame->setIcon(icon82);
        action_dock_project = new QAction(Form_WorkSpace);
        action_dock_project->setObjectName("action_dock_project");
        action_dock_project->setCheckable(true);
        action_dock_project->setChecked(true);
        action_dock_project->setEnabled(true);
        action_dock_project->setIcon(icon79);
        action_dock_project->setAutoRepeat(true);
        action_dock_project->setVisible(true);
        action_dock_project->setIconVisibleInMenu(true);
        action_dock_project->setShortcutVisibleInContextMenu(true);
        action_dock_project->setPriority(QAction::NormalPriority);
        action_dock_compilePrint = new QAction(Form_WorkSpace);
        action_dock_compilePrint->setObjectName("action_dock_compilePrint");
        action_dock_compilePrint->setCheckable(true);
        action_dock_compilePrint->setChecked(true);
        action_dock_compilePrint->setIcon(icon79);
        action_dock_runTip = new QAction(Form_WorkSpace);
        action_dock_runTip->setObjectName("action_dock_runTip");
        action_dock_runTip->setCheckable(true);
        action_dock_runTip->setChecked(true);
        action_dock_runTip->setIcon(icon79);
        action_dock_debug = new QAction(Form_WorkSpace);
        action_dock_debug->setObjectName("action_dock_debug");
        action_dock_debug->setCheckable(true);
        action_dock_debug->setChecked(true);
        action_dock_debug->setIcon(icon79);
        action_dock_find = new QAction(Form_WorkSpace);
        action_dock_find->setObjectName("action_dock_find");
        action_dock_find->setCheckable(true);
        action_dock_find->setChecked(true);
        action_dock_find->setIcon(icon79);
        centralwidget = new QWidget(Form_WorkSpace);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 8, 0, 0);
        comboBox_compileMode = new QComboBox(centralwidget);
        comboBox_compileMode->addItem(QString());
        comboBox_compileMode->addItem(QString());
        comboBox_compileMode->setObjectName("comboBox_compileMode");
        comboBox_compileMode->setEnabled(false);
        comboBox_compileMode->setMinimumSize(QSize(150, 0));
        comboBox_compileMode->setEditable(false);

        gridLayout->addWidget(comboBox_compileMode, 0, 0, 1, 1);

        widget_WindowTab = new Form_WindowTab(centralwidget);
        widget_WindowTab->setObjectName("widget_WindowTab");

        gridLayout->addWidget(widget_WindowTab, 1, 0, 1, 1);

        Form_WorkSpace->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Form_WorkSpace);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName("menu_file");
        menu_check = new QMenu(menubar);
        menu_check->setObjectName("menu_check");
        menu_insert = new QMenu(menubar);
        menu_insert->setObjectName("menu_insert");
        menu_db = new QMenu(menubar);
        menu_db->setObjectName("menu_db");
        menu_debug = new QMenu(menubar);
        menu_debug->setObjectName("menu_debug");
        menu_compile = new QMenu(menubar);
        menu_compile->setObjectName("menu_compile");
        menu_tool = new QMenu(menubar);
        menu_tool->setObjectName("menu_tool");
        menu_expand = new QMenu(menubar);
        menu_expand->setObjectName("menu_expand");
        menu_view = new QMenu(menubar);
        menu_view->setObjectName("menu_view");
        menu_help = new QMenu(menubar);
        menu_help->setObjectName("menu_help");
        menu_set = new QMenu(menubar);
        menu_set->setObjectName("menu_set");
        menu_theme = new QMenu(menu_set);
        menu_theme->setObjectName("menu_theme");
        menu_editor = new QMenu(menubar);
        menu_editor->setObjectName("menu_editor");
        menu_editor->setEnabled(true);
        menu_editor->setTabletTracking(false);
        menu_editor->setTearOffEnabled(false);
        Form_WorkSpace->setMenuBar(menubar);
        statusbar = new QStatusBar(Form_WorkSpace);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(true);
        Form_WorkSpace->setStatusBar(statusbar);
        dockWidget_ProjectManger = new QDockWidget(Form_WorkSpace);
        dockWidget_ProjectManger->setObjectName("dockWidget_ProjectManger");
        dockWidget_ProjectManger->setMinimumSize(QSize(180, 150));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName("dockWidgetContents_2");
        gridLayout_6 = new QGridLayout(dockWidgetContents_2);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_ProjectManger = new Form_ProjectManger(dockWidgetContents_2);
        widget_ProjectManger->setObjectName("widget_ProjectManger");

        gridLayout_6->addWidget(widget_ProjectManger, 0, 0, 1, 1);

        dockWidget_ProjectManger->setWidget(dockWidgetContents_2);
        Form_WorkSpace->addDockWidget(Qt::LeftDockWidgetArea, dockWidget_ProjectManger);
        dockWidget_compilePrint = new QDockWidget(Form_WorkSpace);
        dockWidget_compilePrint->setObjectName("dockWidget_compilePrint");
        dockWidget_compilePrint->setMinimumSize(QSize(229, 141));
        dockWidgetContents_8 = new QWidget();
        dockWidgetContents_8->setObjectName("dockWidgetContents_8");
        gridLayout_3 = new QGridLayout(dockWidgetContents_8);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        textEdit_compilePrint = new Form_ListPrint(dockWidgetContents_8);
        textEdit_compilePrint->setObjectName("textEdit_compilePrint");

        gridLayout_3->addWidget(textEdit_compilePrint, 0, 0, 1, 1);

        dockWidget_compilePrint->setWidget(dockWidgetContents_8);
        Form_WorkSpace->addDockWidget(Qt::BottomDockWidgetArea, dockWidget_compilePrint);
        dockWidget_print = new QDockWidget(Form_WorkSpace);
        dockWidget_print->setObjectName("dockWidget_print");
        dockWidget_print->setMinimumSize(QSize(229, 141));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        gridLayout_4 = new QGridLayout(dockWidgetContents);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        textEdit_print = new Form_TextPrint(dockWidgetContents);
        textEdit_print->setObjectName("textEdit_print");

        gridLayout_4->addWidget(textEdit_print, 0, 0, 1, 1);

        dockWidget_print->setWidget(dockWidgetContents);
        Form_WorkSpace->addDockWidget(Qt::BottomDockWidgetArea, dockWidget_print);
        dockWidget_debug = new QDockWidget(Form_WorkSpace);
        dockWidget_debug->setObjectName("dockWidget_debug");
        dockWidget_debug->setMinimumSize(QSize(229, 82));
        dockWidgetContents_15 = new QWidget();
        dockWidgetContents_15->setObjectName("dockWidgetContents_15");
        dockWidget_debug->setWidget(dockWidgetContents_15);
        Form_WorkSpace->addDockWidget(Qt::BottomDockWidgetArea, dockWidget_debug);
        dockWidget_find = new QDockWidget(Form_WorkSpace);
        dockWidget_find->setObjectName("dockWidget_find");
        dockWidget_find->setMinimumSize(QSize(229, 82));
        dockWidgetContents_13 = new QWidget();
        dockWidgetContents_13->setObjectName("dockWidgetContents_13");
        gridLayout_7 = new QGridLayout(dockWidgetContents_13);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        dockWidget_find->setWidget(dockWidgetContents_13);
        Form_WorkSpace->addDockWidget(Qt::BottomDockWidgetArea, dockWidget_find);
        toolBar = new QToolBar(Form_WorkSpace);
        toolBar->setObjectName("toolBar");
        toolBar->setAllowedAreas(Qt::BottomToolBarArea|Qt::TopToolBarArea);
        toolBar->setIconSize(QSize(20, 20));
        Form_WorkSpace->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(Form_WorkSpace);
        toolBar_2->setObjectName("toolBar_2");
        toolBar_2->setAllowedAreas(Qt::BottomToolBarArea|Qt::TopToolBarArea);
        toolBar_2->setIconSize(QSize(20, 20));
        Form_WorkSpace->addToolBar(Qt::TopToolBarArea, toolBar_2);
        Form_WorkSpace->insertToolBarBreak(toolBar_2);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_editor->menuAction());
        menubar->addAction(menu_check->menuAction());
        menubar->addAction(menu_insert->menuAction());
        menubar->addAction(menu_db->menuAction());
        menubar->addAction(menu_debug->menuAction());
        menubar->addAction(menu_compile->menuAction());
        menubar->addAction(menu_tool->menuAction());
        menubar->addAction(menu_expand->menuAction());
        menubar->addAction(menu_view->menuAction());
        menubar->addAction(menu_help->menuAction());
        menubar->addAction(menu_set->menuAction());
        menu_file->addAction(action_file_newCreate);
        menu_file->addAction(action_file_open);
        menu_file->addAction(action_file_close);
        menu_file->addAction(action_file_save);
        menu_file->addAction(action_file_saveAll);
        menu_file->addAction(action_file_print);
        menu_file->addSeparator();
        menu_file->addAction(action_file_config);
        menu_file->addAction(action_file_connect);
        menu_file->addSeparator();
        menu_file->addSeparator();
        menu_file->addAction(action_file_exit);
        menu_debug->addAction(action_menu_run);
        menu_debug->addAction(action_menu_Rerun);
        menu_debug->addAction(action_menu_stop);
        menu_debug->addSeparator();
        menu_debug->addAction(action_menu_fileSystemWatcher);
        menu_debug->addAction(action_menu_stepOver);
        menu_debug->addAction(action_menu_stepIn);
        menu_debug->addAction(action_menu_stepOut);
        menu_debug->addAction(action_menu_stepForward);
        menu_debug->addSeparator();
        menu_debug->addAction(action_menu_toggleAllBreakpoints);
        menu_debug->addAction(action_menu_termBreakpoint);
        menu_debug->addAction(action_menu_clearBreakpointGroup);
        menu_debug->addSeparator();
        menu_debug->addAction(action_menu_lineArrow);
        menu_debug->addAction(action_menu_rigidRelationshipError);
        menu_compile->addAction(action_menu_compile);
        menu_compile->addAction(action_menu_staticCompile);
        menu_compile->addSeparator();
        menu_compile->addAction(action_menu_compleInstall);
        menu_compile->addAction(action_menu_compleSpecifyType);
        menu_compile->addAction(action_menu_staticCompleSpecifyType);
        menu_compile->addSeparator();
        menu_compile->addAction(action_menu_compleOther);
        menu_view->addAction(action_dock_project);
        menu_view->addAction(action_dock_compilePrint);
        menu_view->addAction(action_dock_runTip);
        menu_view->addAction(action_dock_debug);
        menu_view->addAction(action_dock_find);
        menu_help->addAction(action_menu_feedback);
        menu_help->addAction(action_menu_TOU);
        menu_help->addSeparator();
        menu_help->addAction(action_menu_devHelper);
        menu_help->addAction(action_menu_knowledgeBase);
        menu_help->addAction(action_menu_course);
        menu_help->addAction(action_menu_certificate);
        menu_help->addAction(action_menu_devGuide);
        menu_help->addSeparator();
        menu_help->addAction(action_menu_about);
        menu_help->addAction(action_menu_feedBack);
        menu_help->addAction(action_menu_cooperation);
        menu_help->addAction(action_menu_MSDS);
        menu_set->addAction(action_addNewPlugin);
        menu_set->addAction(action_pluginManger);
        menu_set->addSeparator();
        menu_set->addAction(action_systemSettings);
        menu_set->addAction(menu_theme->menuAction());
        menu_set->addSeparator();
        menu_set->addAction(action_toolBar_attestation);
        menu_set->addAction(action_toolBar_findInMod);
        menu_theme->addAction(action_toolBar_blue);
        menu_theme->addAction(action_toolBar_white);
        menu_theme->addAction(action_toolBar_Dark);
        menu_editor->addAction(action_editor_undo);
        menu_editor->addAction(action_editor_redo);
        menu_editor->addAction(action_editor_copy);
        menu_editor->addAction(action_editor_cut);
        menu_editor->addAction(action_editor_paste);
        menu_editor->addAction(action_editor_deleteRow);
        menu_editor->addSeparator();
        menu_editor->addAction(action_editor_quickFind);
        menu_editor->addAction(action_editor_highlightText);
        menu_editor->addAction(action_editor_findNext);
        menu_editor->addAction(action_editor_findPrevious);
        menu_editor->addAction(action_editor_quickReplace);
        menu_editor->addAction(action_editor_findResults);
        menu_editor->addAction(action_editor_jumpLine);
        toolBar->addAction(action_toolBar_backward);
        toolBar->addAction(action_toolBar_forward);
        toolBar->addSeparator();
        toolBar->addAction(action_toolBar_newFileCollection);
        toolBar->addAction(action_toolBar_open);
        toolBar->addAction(action_toolBar_save);
        toolBar->addSeparator();
        toolBar->addAction(action_toolBar_cut);
        toolBar->addAction(action_toolBar_copy);
        toolBar->addAction(action_toolBar_paste);
        toolBar->addAction(action_toolBar_undo);
        toolBar->addAction(action_toolBar_redo);
        toolBar->addSeparator();
        toolBar->addAction(action_toolBar_compile);
        toolBar->addAction(action_toolBar_staticCompile);
        toolBar->addAction(action_toolBar_onlineCompile);
        toolBar->addSeparator();
        toolBar->addAction(action_toolBar_find);
        toolBar->addSeparator();
        toolBar->addAction(action_toolBar_run);
        toolBar->addAction(action_toolBar_stop);
        toolBar->addAction(action_toolBar_Rerun);
        toolBar->addSeparator();
        toolBar->addAction(action_toolBar_toggleAllBreakpoints);
        toolBar->addAction(action_toolBar_clearBreakpointGroup);
        toolBar->addSeparator();
        toolBar->addAction(action_toolBar_debugFind);
        toolBar->addAction(action_toolBar_stepForward);
        toolBar->addAction(action_toolBar_stepOver);
        toolBar->addAction(action_toolBar_stepIn);
        toolBar->addAction(action_toolBar_stepOut);
        toolBar->addSeparator();
        toolBar->addAction(action_toolBar_toolTip);
        toolBar->addSeparator();
        toolBar->addAction(action_toolBar_bookmark);
        toolBar->addAction(action_toolBar_previousBookmark);
        toolBar->addAction(action_toolBar_nextBookmark);
        toolBar->addAction(action_toolBar_bookmarkMainMenuTabitem);
        toolBar->addSeparator();
        toolBar->addAction(action_toolBar_config);
        toolBar->addAction(action_toolBar_settings);
        toolBar_2->addAction(action_toolBar_winLook);
        toolBar_2->addSeparator();
        toolBar_2->addAction(action_toolBar_lefr);
        toolBar_2->addAction(action_toolBar_right);
        toolBar_2->addAction(action_toolBar_top);
        toolBar_2->addAction(action_toolBar_bottom);
        toolBar_2->addSeparator();
        toolBar_2->addAction(action_toolBar_horizontally_window);
        toolBar_2->addAction(action_toolBar_verticalCenter_window);
        toolBar_2->addSeparator();
        toolBar_2->addAction(action_toolBar_horizontally_widget);
        toolBar_2->addAction(action_toolBar_verticalCenter_widget);
        toolBar_2->addAction(action_toolBar_horizontally_avg);
        toolBar_2->addAction(action_toolBar_horizontally_avg_2);
        toolBar_2->addSeparator();
        toolBar_2->addAction(action_toolBar_widthSame);
        toolBar_2->addAction(action_toolBar_highSame);
        toolBar_2->addAction(action_toolBar_widthHighSame);

        retranslateUi(Form_WorkSpace);

        QMetaObject::connectSlotsByName(Form_WorkSpace);
    } // setupUi

    void retranslateUi(QMainWindow *Form_WorkSpace)
    {
        Form_WorkSpace->setWindowTitle(QCoreApplication::translate("Form_WorkSpace", "FireMoneky Studio 2023", nullptr));
        action_toolBar_backward->setText(QCoreApplication::translate("Form_WorkSpace", "\350\267\263\345\210\260\345\211\215\350\267\263\350\275\254\345\244\204", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_backward->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\350\267\263\345\210\260\345\211\215\350\267\263\350\275\254\345\244\204", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_forward->setText(QCoreApplication::translate("Form_WorkSpace", "\350\267\263\345\210\260\345\221\275\344\273\244\350\260\203\347\224\250\345\244\204", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_forward->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\350\267\263\345\210\260\345\221\275\344\273\244\350\260\203\347\224\250\345\244\204", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_newFileCollection->setText(QCoreApplication::translate("Form_WorkSpace", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_newFileCollection->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\346\226\260\345\273\272", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_open->setText(QCoreApplication::translate("Form_WorkSpace", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_open->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\346\211\223\345\274\200", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_save->setText(QCoreApplication::translate("Form_WorkSpace", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_save->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_cut->setText(QCoreApplication::translate("Form_WorkSpace", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_cut->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\345\211\252\345\210\207", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_copy->setText(QCoreApplication::translate("Form_WorkSpace", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_copy->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\345\244\215\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_paste->setText(QCoreApplication::translate("Form_WorkSpace", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_paste->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\347\262\230\350\264\264", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_undo->setText(QCoreApplication::translate("Form_WorkSpace", "\346\222\244\351\224\200", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_undo->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\346\222\244\351\224\200", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_redo->setText(QCoreApplication::translate("Form_WorkSpace", "\351\207\215\345\201\232", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_redo->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\351\207\215\345\201\232", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_compile->setText(QCoreApplication::translate("Form_WorkSpace", "\347\274\226\350\257\221", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_compile->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\347\274\226\350\257\221", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_staticCompile->setText(QCoreApplication::translate("Form_WorkSpace", "\351\235\231\346\200\201\347\274\226\350\257\221", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_staticCompile->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\351\235\231\346\200\201\347\274\226\350\257\221", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_onlineCompile->setText(QCoreApplication::translate("Form_WorkSpace", "\345\234\250\347\272\277\347\274\226\350\257\221", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_onlineCompile->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\345\234\250\347\272\277\347\274\226\350\257\221", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_find->setText(QCoreApplication::translate("Form_WorkSpace", "\346\237\245\346\211\276", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_find->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\346\237\245\346\211\276", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_run->setText(QCoreApplication::translate("Form_WorkSpace", "\350\277\220\350\241\214\347\250\213\345\272\217", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_run->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\350\277\220\350\241\214\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_stop->setText(QCoreApplication::translate("Form_WorkSpace", "\347\273\210\346\255\242\350\277\220\350\241\214", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_stop->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\347\273\210\346\255\242\350\277\220\350\241\214", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_Rerun->setText(QCoreApplication::translate("Form_WorkSpace", "\351\207\215\346\226\260\346\236\204\345\273\272", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_Rerun->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\351\207\215\346\226\260\346\236\204\345\273\272", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_toggleAllBreakpoints->setText(QCoreApplication::translate("Form_WorkSpace", "\345\210\207\346\215\242\346\211\200\346\234\211\346\226\255\347\202\271", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_toggleAllBreakpoints->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\345\210\207\346\215\242\346\211\200\346\234\211\346\226\255\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_clearBreakpointGroup->setText(QCoreApplication::translate("Form_WorkSpace", "\346\270\205\351\231\244\346\226\255\347\202\271", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_clearBreakpointGroup->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\346\270\205\351\231\244\346\226\255\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_debugFind->setText(QCoreApplication::translate("Form_WorkSpace", "\346\237\245\346\211\276", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_debugFind->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\350\260\203\350\257\225\346\237\245\346\211\276", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_stepForward->setText(QCoreApplication::translate("Form_WorkSpace", "\350\260\203\350\257\225\345\211\215\350\277\233", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_stepForward->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\350\260\203\350\257\225\345\211\215\350\277\233", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_stepOver->setText(QCoreApplication::translate("Form_WorkSpace", "\350\260\203\350\257\225\350\267\263\350\277\207", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_stepOver->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\350\260\203\350\257\225\350\267\263\350\277\207", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_stepIn->setText(QCoreApplication::translate("Form_WorkSpace", "\350\260\203\350\257\225\350\277\233\345\205\245", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_stepIn->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\350\260\203\350\257\225\350\277\233\345\205\245", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_stepOut->setText(QCoreApplication::translate("Form_WorkSpace", "\350\260\203\350\257\225\350\267\263\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_stepOut->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\350\260\203\350\257\225\350\267\263\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_toolTip->setText(QCoreApplication::translate("Form_WorkSpace", "\345\267\245\345\205\267\346\217\220\347\244\272", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_toolTip->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\345\267\245\345\205\267\346\217\220\347\244\272", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_bookmark->setText(QCoreApplication::translate("Form_WorkSpace", "\344\271\246\347\255\276", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_bookmark->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\344\271\246\347\255\276", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_previousBookmark->setText(QCoreApplication::translate("Form_WorkSpace", "\344\270\212\344\270\200\344\270\252\344\271\246\347\255\276", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_previousBookmark->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\344\270\212\344\270\200\344\270\252\344\271\246\347\255\276", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_nextBookmark->setText(QCoreApplication::translate("Form_WorkSpace", "\344\270\213\344\270\200\344\270\252\344\271\246\347\255\276", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_nextBookmark->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\344\270\213\344\270\200\344\270\252\344\271\246\347\255\276", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_bookmarkMainMenuTabitem->setText(QCoreApplication::translate("Form_WorkSpace", "\344\271\246\347\255\276\344\270\273\350\217\234\345\215\225", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_bookmarkMainMenuTabitem->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\344\271\246\347\255\276\344\270\273\350\217\234\345\215\225", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_config->setText(QCoreApplication::translate("Form_WorkSpace", "\351\205\215\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_config->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\351\205\215\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_settings->setText(QCoreApplication::translate("Form_WorkSpace", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_settings->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_winLook->setText(QCoreApplication::translate("Form_WorkSpace", "\351\242\204\350\247\210\347\252\227\345\217\243\350\256\276\350\256\241", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_winLook->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\351\242\204\350\247\210\347\252\227\345\217\243\350\256\276\350\256\241", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_lefr->setText(QCoreApplication::translate("Form_WorkSpace", "\345\267\246\345\257\271\351\275\220", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_lefr->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\345\267\246\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_right->setText(QCoreApplication::translate("Form_WorkSpace", "\345\217\263\345\257\271\345\205\266", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_right->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\345\217\263\345\257\271\345\205\266", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_top->setText(QCoreApplication::translate("Form_WorkSpace", "\344\270\212\345\257\271\345\205\266", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_top->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\344\270\212\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_bottom->setText(QCoreApplication::translate("Form_WorkSpace", "\344\270\213\345\257\271\345\205\266", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_bottom->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\344\270\213\345\257\271\345\205\266", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_horizontally_window->setText(QCoreApplication::translate("Form_WorkSpace", "\347\252\227\345\217\243\346\260\264\345\271\263\345\211\247\344\270\255", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_horizontally_window->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\347\252\227\345\217\243\346\260\264\345\271\263\345\211\247\344\270\255", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_verticalCenter_window->setText(QCoreApplication::translate("Form_WorkSpace", "\347\252\227\345\217\243\345\236\202\347\233\264\345\261\205\344\270\255", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_verticalCenter_window->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\347\252\227\345\217\243\345\236\202\347\233\264\345\261\205\344\270\255", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_verticalCenter_widget->setText(QCoreApplication::translate("Form_WorkSpace", "\347\273\204\344\273\266\345\236\202\347\233\264\345\261\205\344\270\255", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_verticalCenter_widget->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\347\273\204\344\273\266\345\236\202\347\233\264\345\261\205\344\270\255", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_horizontally_widget->setText(QCoreApplication::translate("Form_WorkSpace", "\347\273\204\344\273\266\346\260\264\345\271\263\345\261\205\344\270\255", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_horizontally_widget->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\347\273\204\344\273\266\346\260\264\345\271\263\345\261\205\344\270\255", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_horizontally_avg->setText(QCoreApplication::translate("Form_WorkSpace", "\346\260\264\345\271\263\345\271\263\345\235\207\345\210\206\345\270\203", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_horizontally_avg->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\346\260\264\345\271\263\345\271\263\345\235\207\345\210\206\345\270\203", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_horizontally_avg_2->setText(QCoreApplication::translate("Form_WorkSpace", "\345\236\202\347\233\264\345\271\263\345\235\207\345\210\206\345\270\203", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_horizontally_avg_2->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\345\236\202\347\233\264\345\271\263\345\235\207\345\210\206\345\270\203", nullptr));
#endif // QT_CONFIG(tooltip)
        action_file_newCreate->setText(QCoreApplication::translate("Form_WorkSpace", "\346\226\260\345\273\272(&N)", nullptr));
#if QT_CONFIG(shortcut)
        action_file_newCreate->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_file_open->setText(QCoreApplication::translate("Form_WorkSpace", "\346\211\223\345\274\200(&O)", nullptr));
#if QT_CONFIG(shortcut)
        action_file_open->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_file_close->setText(QCoreApplication::translate("Form_WorkSpace", "\345\205\263\351\227\255(&C)", nullptr));
        action_file_save->setText(QCoreApplication::translate("Form_WorkSpace", "\344\277\235\345\255\230(&S)", nullptr));
#if QT_CONFIG(shortcut)
        action_file_save->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_file_saveAll->setText(QCoreApplication::translate("Form_WorkSpace", "\344\277\235\345\255\230\345\205\250\351\203\250(&A)", nullptr));
#if QT_CONFIG(tooltip)
        action_file_saveAll->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\344\277\235\345\255\230\345\205\250\351\203\250(A)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        action_file_saveAll->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_file_print->setText(QCoreApplication::translate("Form_WorkSpace", "\346\211\223\345\215\260(&P)", nullptr));
#if QT_CONFIG(shortcut)
        action_file_print->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        action_file_config->setText(QCoreApplication::translate("Form_WorkSpace", "\351\205\215\347\275\256(&U)", nullptr));
        action_file_connect->setText(QCoreApplication::translate("Form_WorkSpace", "\351\207\215\346\226\260\345\205\263\350\201\224\346\226\207\344\273\266\345\220\215(&L)", nullptr));
        action_file_exit->setText(QCoreApplication::translate("Form_WorkSpace", "\351\200\200\345\207\272(&X)", nullptr));
        action_editor_undo->setText(QCoreApplication::translate("Form_WorkSpace", "\346\222\244\351\224\200(&U)", nullptr));
#if QT_CONFIG(shortcut)
        action_editor_undo->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        action_editor_redo->setText(QCoreApplication::translate("Form_WorkSpace", "\351\207\215\345\201\232(&R)", nullptr));
#if QT_CONFIG(tooltip)
        action_editor_redo->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\351\207\215\345\201\232(R)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        action_editor_redo->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        action_editor_copy->setText(QCoreApplication::translate("Form_WorkSpace", "\345\244\215\345\210\266(&C)", nullptr));
#if QT_CONFIG(shortcut)
        action_editor_copy->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        action_editor_cut->setText(QCoreApplication::translate("Form_WorkSpace", "\345\211\252\345\210\207(&T)", nullptr));
#if QT_CONFIG(shortcut)
        action_editor_cut->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        action_editor_paste->setText(QCoreApplication::translate("Form_WorkSpace", "\347\262\230\350\264\264(&P)", nullptr));
#if QT_CONFIG(shortcut)
        action_editor_paste->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        action_editor_deleteRow->setText(QCoreApplication::translate("Form_WorkSpace", "\345\210\240\351\231\244\350\241\214(&D)", nullptr));
#if QT_CONFIG(shortcut)
        action_editor_deleteRow->setShortcut(QCoreApplication::translate("Form_WorkSpace", "F10", nullptr));
#endif // QT_CONFIG(shortcut)
        action_editor_quickFind->setText(QCoreApplication::translate("Form_WorkSpace", "\345\274\200\345\247\213\346\237\245\346\211\276(&F)", nullptr));
#if QT_CONFIG(shortcut)
        action_editor_quickFind->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        action_editor_highlightText->setText(QCoreApplication::translate("Form_WorkSpace", "\351\253\230\344\272\256\346\240\207\350\256\260\345\276\205\345\257\273\346\211\276\345\215\225\350\257\215(&G)", nullptr));
#if QT_CONFIG(shortcut)
        action_editor_highlightText->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        action_editor_findNext->setText(QCoreApplication::translate("Form_WorkSpace", "\345\257\273\346\211\276\344\270\213\344\270\200\344\270\252(&N)", nullptr));
#if QT_CONFIG(shortcut)
        action_editor_findNext->setShortcut(QCoreApplication::translate("Form_WorkSpace", "F3", nullptr));
#endif // QT_CONFIG(shortcut)
        action_editor_findPrevious->setText(QCoreApplication::translate("Form_WorkSpace", "\345\257\273\346\211\276\344\270\212\344\270\200\344\270\252(&V)", nullptr));
#if QT_CONFIG(shortcut)
        action_editor_findPrevious->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Shift+F3", nullptr));
#endif // QT_CONFIG(shortcut)
        action_editor_quickReplace->setText(QCoreApplication::translate("Form_WorkSpace", "\345\257\273\346\211\276\346\233\277\346\215\242(&H)", nullptr));
#if QT_CONFIG(shortcut)
        action_editor_quickReplace->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        action_editor_findResults->setText(QCoreApplication::translate("Form_WorkSpace", "\346\225\264\344\275\223\346\220\234\345\257\273(&E)", nullptr));
#if QT_CONFIG(shortcut)
        action_editor_findResults->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Alt+F", nullptr));
#endif // QT_CONFIG(shortcut)
        action_editor_jumpLine->setText(QCoreApplication::translate("Form_WorkSpace", "\350\267\263\350\275\254\345\210\260\346\214\207\345\256\232\350\241\214(&W)", nullptr));
#if QT_CONFIG(shortcut)
        action_editor_jumpLine->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_run->setText(QCoreApplication::translate("Form_WorkSpace", "\350\277\220\350\241\214(&S)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_run->setShortcut(QCoreApplication::translate("Form_WorkSpace", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_Rerun->setText(QCoreApplication::translate("Form_WorkSpace", "\351\207\215\346\226\260\350\277\220\350\241\214(&M)", nullptr));
#if QT_CONFIG(tooltip)
        action_menu_Rerun->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\351\207\215\346\226\260\350\277\220\350\241\214(M)", nullptr));
#endif // QT_CONFIG(tooltip)
        action_menu_stop->setText(QCoreApplication::translate("Form_WorkSpace", "\347\273\210\346\255\242(&E)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_stop->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+F5", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_fileSystemWatcher->setText(QCoreApplication::translate("Form_WorkSpace", "\346\237\245\347\234\213\350\241\250\350\276\276\345\274\217/\345\217\230\351\207\217(&V)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_fileSystemWatcher->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Shift+F9", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_stepOver->setText(QCoreApplication::translate("Form_WorkSpace", "\345\215\225\346\255\245\350\267\237\350\270\252(&O)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_stepOver->setShortcut(QCoreApplication::translate("Form_WorkSpace", "F8", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_stepIn->setText(QCoreApplication::translate("Form_WorkSpace", "\345\215\225\346\255\245\350\267\237\350\270\252\350\277\233\345\205\245(&I)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_stepIn->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Shift+F8", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_stepOut->setText(QCoreApplication::translate("Form_WorkSpace", "\350\267\237\350\270\252\350\277\224\345\233\236(&U)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_stepOut->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Shift+F8", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_stepForward->setText(QCoreApplication::translate("Form_WorkSpace", "\346\211\247\350\241\214\345\210\260\345\205\211\346\240\207\345\244\204(&R)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_stepForward->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+F8", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_toggleAllBreakpoints->setText(QCoreApplication::translate("Form_WorkSpace", "\350\256\276\347\275\256\346\210\226\346\270\205\351\231\244\346\226\255\347\202\271(&T)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_toggleAllBreakpoints->setShortcut(QCoreApplication::translate("Form_WorkSpace", "F9", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_termBreakpoint->setText(QCoreApplication::translate("Form_WorkSpace", "\346\235\241\344\273\266\346\226\255\347\202\271(&A)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_termBreakpoint->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+F9", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_clearBreakpointGroup->setText(QCoreApplication::translate("Form_WorkSpace", "\346\270\205\346\245\232\346\211\200\346\234\211\346\226\255\347\202\271(&C)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_clearBreakpointGroup->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Shift+F9", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_lineArrow->setText(QCoreApplication::translate("Form_WorkSpace", "\345\210\260\347\216\260\350\241\214\346\211\247\350\241\214\344\275\215\347\275\256(&G)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_lineArrow->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+.", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_rigidRelationshipError->setText(QCoreApplication::translate("Form_WorkSpace", "\345\210\260\350\277\220\350\241\214\346\227\266\351\224\231\350\257\257\347\233\270\345\205\263\344\275\215\347\275\256(&N)", nullptr));
        action_menu_compile->setText(QCoreApplication::translate("Form_WorkSpace", "\347\274\226\350\257\221(&C)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_compile->setShortcut(QCoreApplication::translate("Form_WorkSpace", "F7", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_staticCompile->setText(QCoreApplication::translate("Form_WorkSpace", "\351\235\231\346\200\201\347\274\226\350\257\221(&S)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_staticCompile->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Shift+F7", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_compleInstall->setText(QCoreApplication::translate("Form_WorkSpace", "\347\274\226\350\257\221\347\224\237\346\210\220\345\256\211\350\243\205\350\275\257\344\273\266(&I)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_compleInstall->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Shift+F7", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_compleSpecifyType->setText(QCoreApplication::translate("Form_WorkSpace", "\347\274\226\350\257\221\344\270\272\346\214\207\345\256\232\347\261\273\345\236\213(&M)", nullptr));
        action_menu_staticCompleSpecifyType->setText(QCoreApplication::translate("Form_WorkSpace", "\351\235\231\346\200\201\347\274\226\350\257\221\344\270\272\346\214\207\345\256\232\347\261\273\345\236\213(&T)", nullptr));
        action_menu_compleOther->setText(QCoreApplication::translate("Form_WorkSpace", "\345\205\266\344\273\226\347\274\226\350\257\221(&O)", nullptr));
        action_menu_feedback->setText(QCoreApplication::translate("Form_WorkSpace", "\345\273\272\350\256\256\345\217\215\351\246\210(&Q)", nullptr));
        action_menu_TOU->setText(QCoreApplication::translate("Form_WorkSpace", "\344\275\277\347\224\250\346\235\241\346\254\276(&W)", nullptr));
        action_menu_devHelper->setText(QCoreApplication::translate("Form_WorkSpace", "\346\231\272\350\203\275\345\274\200\345\217\221\345\212\251\346\211\213(&H)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_devHelper->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Alt+H", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_knowledgeBase->setText(QCoreApplication::translate("Form_WorkSpace", "\347\237\245\350\257\206\345\272\223(&E)", nullptr));
        action_menu_course->setText(QCoreApplication::translate("Form_WorkSpace", "\345\244\232\345\252\222\344\275\223\346\225\231\347\250\213(&T)", nullptr));
        action_menu_certificate->setText(QCoreApplication::translate("Form_WorkSpace", "\346\257\217\346\227\245\344\270\200\350\264\264(&D)", nullptr));
        action_menu_devGuide->setText(QCoreApplication::translate("Form_WorkSpace", "\346\224\257\346\214\201\345\272\223\346\211\213\345\206\214\345\217\212\344\276\213\347\250\213(&C)", nullptr));
        action_menu_about->setText(QCoreApplication::translate("Form_WorkSpace", "\345\205\263\344\272\216(&A)", nullptr));
        action_menu_feedBack->setText(QCoreApplication::translate("Form_WorkSpace", "\347\224\250\346\210\267\345\217\215\351\246\210\350\241\250(&U)", nullptr));
        action_menu_cooperation->setText(QCoreApplication::translate("Form_WorkSpace", "\350\264\255\344\271\260\344\270\216\345\225\206\344\270\232\345\220\210\344\275\234(&R)", nullptr));
        action_menu_MSDS->setText(QCoreApplication::translate("Form_WorkSpace", "\345\271\263\345\217\260\345\256\211\345\205\250\346\243\200\346\265\213\346\212\245\345\221\212(&V)", nullptr));
        action_addNewPlugin->setText(QCoreApplication::translate("Form_WorkSpace", "\345\256\211\350\243\205\346\226\260\347\232\204\346\217\222\344\273\266\346\224\257\346\214\201(&I)", nullptr));
#if QT_CONFIG(tooltip)
        action_addNewPlugin->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\345\256\211\350\243\205\346\226\260\347\232\204\346\217\222\344\273\266\346\224\257\346\214\201(I)", nullptr));
#endif // QT_CONFIG(tooltip)
        action_pluginManger->setText(QCoreApplication::translate("Form_WorkSpace", "\346\217\222\344\273\266\347\256\241\347\220\206\345\231\250(&L)", nullptr));
#if QT_CONFIG(tooltip)
        action_pluginManger->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\346\217\222\344\273\266\347\256\241\347\220\206\345\231\250(L)", nullptr));
#endif // QT_CONFIG(tooltip)
        action_systemSettings->setText(QCoreApplication::translate("Form_WorkSpace", "\347\263\273\347\273\237\350\256\276\347\275\256(&O)", nullptr));
        action_toolBar_attestation->setText(QCoreApplication::translate("Form_WorkSpace", "\347\255\276\345\220\215\350\256\244\350\257\201(&C)", nullptr));
        action_toolBar_findInMod->setText(QCoreApplication::translate("Form_WorkSpace", "\345\234\250\346\250\241\345\235\227\345\217\212\346\224\257\346\214\201\345\272\223\344\270\255\346\237\245\346\211\276(&F)", nullptr));
        action_toolBar_blue->setText(QCoreApplication::translate("Form_WorkSpace", "Blue(\351\273\230\350\256\244)(&N)", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_blue->setToolTip(QCoreApplication::translate("Form_WorkSpace", "Blue(N)", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_white->setText(QCoreApplication::translate("Form_WorkSpace", "White(&W)", nullptr));
        action_toolBar_Dark->setText(QCoreApplication::translate("Form_WorkSpace", "Dark(&D)", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_Dark->setToolTip(QCoreApplication::translate("Form_WorkSpace", "Dark(D)", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_widthSame->setText(QCoreApplication::translate("Form_WorkSpace", "\344\275\277\345\256\275\345\272\246\347\233\270\345\220\214", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_widthSame->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\344\275\277\345\256\275\345\272\246\347\233\270\345\220\214", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_highSame->setText(QCoreApplication::translate("Form_WorkSpace", "\344\275\277\351\253\230\345\272\246\347\233\270\345\220\214", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_highSame->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\344\275\277\351\253\230\345\272\246\347\233\270\345\220\214", nullptr));
#endif // QT_CONFIG(tooltip)
        action_toolBar_widthHighSame->setText(QCoreApplication::translate("Form_WorkSpace", "\344\275\277\345\256\275\351\253\230\347\233\270\345\220\214", nullptr));
#if QT_CONFIG(tooltip)
        action_toolBar_widthHighSame->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\344\275\277\345\256\275\351\253\230\347\233\270\345\220\214", nullptr));
#endif // QT_CONFIG(tooltip)
        action_dock_project->setText(QCoreApplication::translate("Form_WorkSpace", "\345\267\245\347\250\213\347\256\241\347\220\206", nullptr));
        action_dock_compilePrint->setText(QCoreApplication::translate("Form_WorkSpace", "\347\274\226\350\257\221\350\276\223\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        action_dock_compilePrint->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\347\274\226\350\257\221\350\276\223\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        action_dock_runTip->setText(QCoreApplication::translate("Form_WorkSpace", "\350\277\220\350\241\214\346\217\220\347\244\272", nullptr));
#if QT_CONFIG(tooltip)
        action_dock_runTip->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\350\277\220\350\241\214\344\270\216\346\217\220\347\244\272", nullptr));
#endif // QT_CONFIG(tooltip)
        action_dock_debug->setText(QCoreApplication::translate("Form_WorkSpace", "\346\226\255\347\202\271\345\240\206\346\240\210", nullptr));
        action_dock_find->setText(QCoreApplication::translate("Form_WorkSpace", "\346\220\234\345\257\273\347\273\223\346\236\234", nullptr));
#if QT_CONFIG(tooltip)
        action_dock_find->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\346\220\234\345\257\273\347\273\223\346\236\234", nullptr));
#endif // QT_CONFIG(tooltip)
        comboBox_compileMode->setItemText(0, QCoreApplication::translate("Form_WorkSpace", "Debug\357\274\210\350\260\203\350\257\225\357\274\211", nullptr));
        comboBox_compileMode->setItemText(1, QCoreApplication::translate("Form_WorkSpace", "Release\357\274\210\345\217\221\345\270\203\357\274\211", nullptr));

        menu_file->setTitle(QCoreApplication::translate("Form_WorkSpace", "\346\226\207\344\273\266(&F)", nullptr));
        menu_check->setTitle(QCoreApplication::translate("Form_WorkSpace", "\346\237\245\347\234\213(&V)", nullptr));
        menu_insert->setTitle(QCoreApplication::translate("Form_WorkSpace", "\346\217\222\345\205\245(&I)", nullptr));
        menu_db->setTitle(QCoreApplication::translate("Form_WorkSpace", "\346\225\260\346\215\256\345\272\223(&B)", nullptr));
        menu_debug->setTitle(QCoreApplication::translate("Form_WorkSpace", "\350\260\203\350\257\225(&R)", nullptr));
        menu_compile->setTitle(QCoreApplication::translate("Form_WorkSpace", "\347\224\237\346\210\220(&C)", nullptr));
        menu_tool->setTitle(QCoreApplication::translate("Form_WorkSpace", "\345\267\245\345\205\267(&T)", nullptr));
        menu_expand->setTitle(QCoreApplication::translate("Form_WorkSpace", "\346\211\251\345\261\225(&X)", nullptr));
        menu_view->setTitle(QCoreApplication::translate("Form_WorkSpace", "\350\247\206\345\233\276(&W)", nullptr));
        menu_help->setTitle(QCoreApplication::translate("Form_WorkSpace", "\345\270\256\345\212\251(&H)", nullptr));
        menu_set->setTitle(QCoreApplication::translate("Form_WorkSpace", "\350\256\276\347\275\256(&S)", nullptr));
        menu_theme->setTitle(QCoreApplication::translate("Form_WorkSpace", "\344\270\273\351\242\230(&T)", nullptr));
        menu_editor->setTitle(QCoreApplication::translate("Form_WorkSpace", "\347\274\226\350\276\221(&E)", nullptr));
        dockWidget_ProjectManger->setWindowTitle(QCoreApplication::translate("Form_WorkSpace", "\345\267\245\347\250\213\347\256\241\347\220\206", nullptr));
        dockWidget_compilePrint->setWindowTitle(QCoreApplication::translate("Form_WorkSpace", "\347\274\226\350\257\221\350\276\223\345\207\272", nullptr));
        dockWidget_print->setWindowTitle(QCoreApplication::translate("Form_WorkSpace", "\350\277\220\350\241\214\344\270\216\346\217\220\347\244\272", nullptr));
        dockWidget_debug->setWindowTitle(QCoreApplication::translate("Form_WorkSpace", "\346\226\255\347\202\271\345\240\206\346\240\210", nullptr));
        dockWidget_find->setWindowTitle(QCoreApplication::translate("Form_WorkSpace", "\346\220\234\345\257\273\347\273\223\346\236\234", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Form_WorkSpace", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("Form_WorkSpace", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_WorkSpace: public Ui_Form_WorkSpace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_WORKSPACE_H
