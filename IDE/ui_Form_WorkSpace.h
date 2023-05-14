/********************************************************************************
** Form generated from reading UI file 'Form_WorkSpace.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_WORKSPACE_H
#define UI_FORM_WORKSPACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
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
    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;
    QAction *action5;
    QAction *action6;
    QAction *action7;
    QAction *action8;
    QAction *action9;
    QAction *action10;
    QAction *action_toolBar_compile;
    QAction *action_toolBar_staticCompile;
    QAction *action_toolBar_onlineCompile;
    QAction *action_toolBar_find;
    QAction *action_toolBar_run;
    QAction *action_toolBar_stop;
    QAction *action_toolBar_Rerun;
    QAction *action18;
    QAction *action19;
    QAction *action20;
    QAction *action21;
    QAction *action22;
    QAction *action23;
    QAction *action24;
    QAction *action25;
    QAction *action26;
    QAction *action27;
    QAction *action28;
    QAction *action29;
    QAction *action30;
    QAction *action31;
    QAction *action32;
    QAction *action33;
    QAction *action34;
    QAction *action35;
    QAction *action36;
    QAction *action37;
    QAction *action38;
    QAction *action39;
    QAction *action40;
    QAction *action41;
    QAction *action42;
    QAction *action_file_newCreate;
    QAction *action_file_open;
    QAction *action_file_close;
    QAction *action_file_save;
    QAction *action_file_saveAs;
    QAction *action_file_saveAll;
    QAction *action_file_print;
    QAction *action_file_config;
    QAction *action_file_connect;
    QAction *action_file_exit;
    QAction *action_U;
    QAction *action_R;
    QAction *action_C;
    QAction *action_T;
    QAction *action_P;
    QAction *action_D;
    QAction *action_F;
    QAction *action_G;
    QAction *action_N;
    QAction *action_V;
    QAction *action_H;
    QAction *action_E;
    QAction *action_W;
    QAction *action_menu_run;
    QAction *action_menu_Rerun;
    QAction *action_menu_stop;
    QAction *action_V_2;
    QAction *action_O_2;
    QAction *action_I;
    QAction *action_U_2;
    QAction *action_R_2;
    QAction *action_T_2;
    QAction *action_A;
    QAction *action_C_2;
    QAction *action_G_2;
    QAction *action_N_2;
    QAction *action_menu_compile;
    QAction *action_menu_staticCompile;
    QAction *action_I_2;
    QAction *action_M_2;
    QAction *action_T_3;
    QAction *action_O_3;
    QAction *action_Q;
    QAction *action_W_2;
    QAction *action_H_2;
    QAction *action_E_3;
    QAction *action_T_4;
    QAction *action_D_2;
    QAction *action_C_4;
    QAction *action_about;
    QAction *action_U_3;
    QAction *action_R_3;
    QAction *action_V_3;
    QAction *action_addNewPlugin;
    QAction *action_pluginManger;
    QAction *action_O_4;
    QAction *action_C_5;
    QAction *action_F_2;
    QAction *actionBlue_N;
    QAction *actionBlue_W;
    QAction *actionBlue_D;
    QAction *actionaction43;
    QAction *actionaction44;
    QAction *actionaction45;
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
    QMenu *menu_T;
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
        Form_WorkSpace->setStyleSheet(QString::fromUtf8("\n"
"/*\344\270\273\347\252\227\345\217\243\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QMainWindow{\n"
"	background-color: rgb(93, 107, 153);\n"
"}\n"
"\n"
"/*\345\272\225\351\203\250\347\212\266\346\200\201\346\240\217*/\n"
"QStatusBar{\n"
"	background-color:#40568d;\n"
"}\n"
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
"    background-image: url(:/Theme/icon/Theme/Blue/Image/ToolBar/Separator.png);\n"
" }\n"
"\n"
"/*\345\267\245\345\205\267\346\240\217\346\213\226\345\212\250\345\233\276\347\211\207\346\240\217*/\n"
"QToolBar::handle {\n"
"	margin:4px 6px;\n"
"	width:5px;\n"
"	background-image: url(:/Theme/icon/Theme/"
                        "Blue/Image/ToolBar/Row1.png);\n"
"}\n"
"\n"
"/*\345\267\245\345\205\267\346\240\217\345\255\220\351\241\271\346\214\211\351\222\256*/\n"
"QToolButton {\n"
"	padding:0px;\n"
"	padding:0px;\n"
"}\n"
"\n"
"/*\346\250\241\345\274\217\351\200\211\346\213\251\346\241\206*/\n"
"#comboBox_compileMode{\n"
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
"	/*border-top-left-radius: 5px;    \350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247"
                        "\222\357\274\210\345\267\246\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	/*border-top-right-radius: 5px;    \350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\217\263\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
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
""
                        "	color:rgb(92, 45, 145);\n"
"}\n"
"\n"
"\n"
"\n"
"/*Dock\347\232\204\346\226\207\346\234\254\346\241\206*/\n"
"#textEdit_help_tip,#textEdit_print{\n"
"	background-color:rgb(230, 231, 232);\n"
"	color:rgb(42, 42, 42);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"/*\350\256\276\347\275\256TabWidget\347\232\204\350\276\271\346\241\206\347\232\204\346\240\267\345\274\217\n"
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
"	color: rgb(30"
                        ", 30, 31);\n"
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
"QMenu::item:disabled {/*\350\217\234\345\215\225\350\242\253\347\246\201\347\224\250*/\n"
"	color: rgb(181, 194, 202);\n"
"}"));
        Form_WorkSpace->setToolButtonStyle(Qt::ToolButtonIconOnly);
        action1 = new QAction(Form_WorkSpace);
        action1->setObjectName("action1");
        action1->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/Backward_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Backward_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action1->setIcon(icon);
        action2 = new QAction(Form_WorkSpace);
        action2->setObjectName("action2");
        action2->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/Forward_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Forward_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action2->setIcon(icon1);
        action3 = new QAction(Form_WorkSpace);
        action3->setObjectName("action3");
        action3->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/NewFileCollection_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action3->setIcon(icon2);
        action4 = new QAction(Form_WorkSpace);
        action4->setObjectName("action4");
        action4->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/OpenFolder_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action4->setIcon(icon3);
        action5 = new QAction(Form_WorkSpace);
        action5->setObjectName("action5");
        action5->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/SaveStatusBar1_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/SaveStatusBar1_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action5->setIcon(icon4);
        action6 = new QAction(Form_WorkSpace);
        action6->setObjectName("action6");
        action6->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/Cut_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Cut_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action6->setIcon(icon5);
        action7 = new QAction(Form_WorkSpace);
        action7->setObjectName("action7");
        action7->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/Copy_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Copy_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action7->setIcon(icon6);
        action8 = new QAction(Form_WorkSpace);
        action8->setObjectName("action8");
        action8->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/Paste_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Paste_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action8->setIcon(icon7);
        action9 = new QAction(Form_WorkSpace);
        action9->setObjectName("action9");
        action9->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/Undo_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Undo_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action9->setIcon(icon8);
        action10 = new QAction(Form_WorkSpace);
        action10->setObjectName("action10");
        action10->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/Redo_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Redo_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action10->setIcon(icon9);
        action_toolBar_compile = new QAction(Form_WorkSpace);
        action_toolBar_compile->setObjectName("action_toolBar_compile");
        action_toolBar_compile->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/BuildSelection_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon10.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/BuildSelection_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_compile->setIcon(icon10);
        action_toolBar_staticCompile = new QAction(Form_WorkSpace);
        action_toolBar_staticCompile->setObjectName("action_toolBar_staticCompile");
        action_toolBar_staticCompile->setEnabled(false);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/BuildSolution_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/BuildSolution_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_staticCompile->setIcon(icon11);
        action_toolBar_onlineCompile = new QAction(Form_WorkSpace);
        action_toolBar_onlineCompile->setObjectName("action_toolBar_onlineCompile");
        action_toolBar_onlineCompile->setEnabled(false);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/BuildBlackMoon_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon12.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/BuildBlackMoon_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_onlineCompile->setIcon(icon12);
        action_toolBar_find = new QAction(Form_WorkSpace);
        action_toolBar_find->setObjectName("action_toolBar_find");
        action_toolBar_find->setEnabled(false);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/SearchInFile_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon13.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/FindResults_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_find->setIcon(icon13);
        action_toolBar_run = new QAction(Form_WorkSpace);
        action_toolBar_run->setObjectName("action_toolBar_run");
        action_toolBar_run->setEnabled(false);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/Run_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon14.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Run_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_run->setIcon(icon14);
        action_toolBar_stop = new QAction(Form_WorkSpace);
        action_toolBar_stop->setObjectName("action_toolBar_stop");
        action_toolBar_stop->setEnabled(false);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/Stop_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon15.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Stop_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_stop->setIcon(icon15);
        action_toolBar_Rerun = new QAction(Form_WorkSpace);
        action_toolBar_Rerun->setObjectName("action_toolBar_Rerun");
        action_toolBar_Rerun->setEnabled(false);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/Restart_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon16.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Restart_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action_toolBar_Rerun->setIcon(icon16);
        action18 = new QAction(Form_WorkSpace);
        action18->setObjectName("action18");
        action18->setEnabled(false);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/ToggleAllBreakpoints_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon17.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/ToggleAllBreakpoints_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action18->setIcon(icon17);
        action19 = new QAction(Form_WorkSpace);
        action19->setObjectName("action19");
        action19->setEnabled(false);
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/ClearBreakpointGroup_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon18.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/ClearBreakpointGroup_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action19->setIcon(icon18);
        action20 = new QAction(Form_WorkSpace);
        action20->setObjectName("action20");
        action20->setEnabled(false);
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/FileSystemWatcher_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon19.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/FileSystemWatcher_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action20->setIcon(icon19);
        action21 = new QAction(Form_WorkSpace);
        action21->setObjectName("action21");
        action21->setEnabled(false);
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/StepForward_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon20.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/StepForward_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action21->setIcon(icon20);
        action22 = new QAction(Form_WorkSpace);
        action22->setObjectName("action22");
        action22->setEnabled(false);
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/StepOver_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon21.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/StepOver_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action22->setIcon(icon21);
        action23 = new QAction(Form_WorkSpace);
        action23->setObjectName("action23");
        action23->setEnabled(false);
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/StepIn_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon22.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/StepIn_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action23->setIcon(icon22);
        action24 = new QAction(Form_WorkSpace);
        action24->setObjectName("action24");
        action24->setEnabled(false);
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/StepOut_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon23.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/StepOut_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action24->setIcon(icon23);
        action25 = new QAction(Form_WorkSpace);
        action25->setObjectName("action25");
        action25->setEnabled(false);
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/ToolTip_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon24.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/ToolTip_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action25->setIcon(icon24);
        action26 = new QAction(Form_WorkSpace);
        action26->setObjectName("action26");
        action26->setEnabled(false);
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/Bookmark_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon25.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Bookmark_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action26->setIcon(icon25);
        action27 = new QAction(Form_WorkSpace);
        action27->setObjectName("action27");
        action27->setEnabled(false);
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/PreviousBookmark_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon26.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/PreviousBookmark_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action27->setIcon(icon26);
        action28 = new QAction(Form_WorkSpace);
        action28->setObjectName("action28");
        action28->setEnabled(false);
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/NextBookmark_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon27.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/NextBookmark_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action28->setIcon(icon27);
        action29 = new QAction(Form_WorkSpace);
        action29->setObjectName("action29");
        action29->setEnabled(false);
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/BookmarkMainMenuTabItem_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon28.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/BookmarkMainMenuTabItem_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action29->setIcon(icon28);
        action30 = new QAction(Form_WorkSpace);
        action30->setObjectName("action30");
        action30->setEnabled(false);
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/Property_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon29.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Property_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action30->setIcon(icon29);
        action31 = new QAction(Form_WorkSpace);
        action31->setObjectName("action31");
        action31->setEnabled(false);
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/Settings_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon30.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/Settings_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action31->setIcon(icon30);
        action32 = new QAction(Form_WorkSpace);
        action32->setObjectName("action32");
        action32->setEnabled(false);
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/RunTestDialog_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon31.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/RunTestDialog_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action32->setIcon(icon31);
        action33 = new QAction(Form_WorkSpace);
        action33->setObjectName("action33");
        action33->setEnabled(false);
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/AlignLeft_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon32.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/AlignLeft_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action33->setIcon(icon32);
        action34 = new QAction(Form_WorkSpace);
        action34->setObjectName("action34");
        action34->setEnabled(false);
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/AlignRight_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon33.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/AlignRight_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action34->setIcon(icon33);
        action35 = new QAction(Form_WorkSpace);
        action35->setObjectName("action35");
        action35->setEnabled(false);
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/AlignTop_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon34.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/AlignTop_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action35->setIcon(icon34);
        action36 = new QAction(Form_WorkSpace);
        action36->setObjectName("action36");
        action36->setEnabled(false);
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/AlignBottom_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon35.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/AlignBottom_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action36->setIcon(icon35);
        action37 = new QAction(Form_WorkSpace);
        action37->setObjectName("action37");
        action37->setEnabled(false);
        QIcon icon36;
        icon36.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/TextCenterInFormHorizontal_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon36.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/TextCenterInFormHorizontal_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action37->setIcon(icon36);
        action38 = new QAction(Form_WorkSpace);
        action38->setObjectName("action38");
        action38->setEnabled(false);
        QIcon icon37;
        icon37.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/CenterInFormVertical_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon37.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/CenterInFormVertical_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action38->setIcon(icon37);
        action39 = new QAction(Form_WorkSpace);
        action39->setObjectName("action39");
        action39->setEnabled(false);
        QIcon icon38;
        icon38.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/DistributeHorizontalCenter_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon38.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/DistributeHorizontalCenter_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action39->setIcon(icon38);
        action40 = new QAction(Form_WorkSpace);
        action40->setObjectName("action40");
        action40->setEnabled(false);
        QIcon icon39;
        icon39.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/DistributeVerticalCenter_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon39.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/DistributeVerticalCenter_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action40->setIcon(icon39);
        action41 = new QAction(Form_WorkSpace);
        action41->setObjectName("action41");
        action41->setEnabled(false);
        QIcon icon40;
        icon40.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/SpaceAcross_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon40.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/SpaceAcross_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action41->setIcon(icon40);
        action42 = new QAction(Form_WorkSpace);
        action42->setObjectName("action42");
        action42->setEnabled(false);
        QIcon icon41;
        icon41.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/SpaceDown_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon41.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/SpaceDown_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        action42->setIcon(icon41);
        action_file_newCreate = new QAction(Form_WorkSpace);
        action_file_newCreate->setObjectName("action_file_newCreate");
        action_file_newCreate->setCheckable(false);
        action_file_newCreate->setChecked(false);
        QIcon icon42;
        icon42.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/NewFileCollection_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_newCreate->setIcon(icon42);
        action_file_open = new QAction(Form_WorkSpace);
        action_file_open->setObjectName("action_file_open");
        QIcon icon43;
        icon43.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/OpenFileFromProject_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_open->setIcon(icon43);
        action_file_close = new QAction(Form_WorkSpace);
        action_file_close->setObjectName("action_file_close");
        QIcon icon44;
        icon44.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/CloseProject_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_close->setIcon(icon44);
        action_file_save = new QAction(Form_WorkSpace);
        action_file_save->setObjectName("action_file_save");
        QIcon icon45;
        icon45.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/SaveStatusBar1_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_save->setIcon(icon45);
        action_file_saveAs = new QAction(Form_WorkSpace);
        action_file_saveAs->setObjectName("action_file_saveAs");
        action_file_saveAll = new QAction(Form_WorkSpace);
        action_file_saveAll->setObjectName("action_file_saveAll");
        action_file_saveAll->setEnabled(false);
        action_file_print = new QAction(Form_WorkSpace);
        action_file_print->setObjectName("action_file_print");
        action_file_print->setEnabled(false);
        QIcon icon46;
        icon46.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/Print_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_print->setIcon(icon46);
        action_file_config = new QAction(Form_WorkSpace);
        action_file_config->setObjectName("action_file_config");
        QIcon icon47;
        icon47.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/Property_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_config->setIcon(icon47);
        action_file_connect = new QAction(Form_WorkSpace);
        action_file_connect->setObjectName("action_file_connect");
        action_file_connect->setEnabled(false);
        action_file_exit = new QAction(Form_WorkSpace);
        action_file_exit->setObjectName("action_file_exit");
        action_U = new QAction(Form_WorkSpace);
        action_U->setObjectName("action_U");
        QIcon icon48;
        icon48.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/Undo_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_U->setIcon(icon48);
        action_R = new QAction(Form_WorkSpace);
        action_R->setObjectName("action_R");
        QIcon icon49;
        icon49.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/Redo_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_R->setIcon(icon49);
        action_C = new QAction(Form_WorkSpace);
        action_C->setObjectName("action_C");
        QIcon icon50;
        icon50.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/Copy_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_C->setIcon(icon50);
        action_T = new QAction(Form_WorkSpace);
        action_T->setObjectName("action_T");
        QIcon icon51;
        icon51.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/Cut_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_T->setIcon(icon51);
        action_P = new QAction(Form_WorkSpace);
        action_P->setObjectName("action_P");
        QIcon icon52;
        icon52.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/Paste_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_P->setIcon(icon52);
        action_D = new QAction(Form_WorkSpace);
        action_D->setObjectName("action_D");
        action_F = new QAction(Form_WorkSpace);
        action_F->setObjectName("action_F");
        QIcon icon53;
        icon53.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/QuickFind_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_F->setIcon(icon53);
        action_G = new QAction(Form_WorkSpace);
        action_G->setObjectName("action_G");
        QIcon icon54;
        icon54.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/HighlightText_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_G->setIcon(icon54);
        action_N = new QAction(Form_WorkSpace);
        action_N->setObjectName("action_N");
        QIcon icon55;
        icon55.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/FindNext_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_N->setIcon(icon55);
        action_V = new QAction(Form_WorkSpace);
        action_V->setObjectName("action_V");
        QIcon icon56;
        icon56.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/FindPrevious_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_V->setIcon(icon56);
        action_H = new QAction(Form_WorkSpace);
        action_H->setObjectName("action_H");
        QIcon icon57;
        icon57.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/QuickReplace_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_H->setIcon(icon57);
        action_E = new QAction(Form_WorkSpace);
        action_E->setObjectName("action_E");
        QIcon icon58;
        icon58.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/FindResults_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_E->setIcon(icon58);
        action_W = new QAction(Form_WorkSpace);
        action_W->setObjectName("action_W");
        action_menu_run = new QAction(Form_WorkSpace);
        action_menu_run->setObjectName("action_menu_run");
        action_menu_run->setEnabled(false);
        QIcon icon59;
        icon59.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/Run_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_run->setIcon(icon59);
        action_menu_Rerun = new QAction(Form_WorkSpace);
        action_menu_Rerun->setObjectName("action_menu_Rerun");
        action_menu_Rerun->setEnabled(false);
        action_menu_stop = new QAction(Form_WorkSpace);
        action_menu_stop->setObjectName("action_menu_stop");
        action_menu_stop->setEnabled(false);
        QIcon icon60;
        icon60.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/Stop_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_stop->setIcon(icon60);
        action_V_2 = new QAction(Form_WorkSpace);
        action_V_2->setObjectName("action_V_2");
        action_V_2->setEnabled(false);
        QIcon icon61;
        icon61.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/FileSystemWatcher_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_V_2->setIcon(icon61);
        action_O_2 = new QAction(Form_WorkSpace);
        action_O_2->setObjectName("action_O_2");
        action_O_2->setEnabled(false);
        QIcon icon62;
        icon62.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/StepOver_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_O_2->setIcon(icon62);
        action_I = new QAction(Form_WorkSpace);
        action_I->setObjectName("action_I");
        action_I->setEnabled(false);
        QIcon icon63;
        icon63.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/StepIn_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_I->setIcon(icon63);
        action_U_2 = new QAction(Form_WorkSpace);
        action_U_2->setObjectName("action_U_2");
        action_U_2->setEnabled(false);
        QIcon icon64;
        icon64.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/StepOut_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_U_2->setIcon(icon64);
        action_R_2 = new QAction(Form_WorkSpace);
        action_R_2->setObjectName("action_R_2");
        action_R_2->setEnabled(false);
        QIcon icon65;
        icon65.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/StepForward_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_R_2->setIcon(icon65);
        action_T_2 = new QAction(Form_WorkSpace);
        action_T_2->setObjectName("action_T_2");
        action_T_2->setEnabled(false);
        QIcon icon66;
        icon66.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/ToggleAllBreakpoints_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_T_2->setIcon(icon66);
        action_A = new QAction(Form_WorkSpace);
        action_A->setObjectName("action_A");
        action_A->setEnabled(false);
        action_C_2 = new QAction(Form_WorkSpace);
        action_C_2->setObjectName("action_C_2");
        action_C_2->setEnabled(false);
        QIcon icon67;
        icon67.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/ClearBreakpointGroup_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_C_2->setIcon(icon67);
        action_G_2 = new QAction(Form_WorkSpace);
        action_G_2->setObjectName("action_G_2");
        action_G_2->setEnabled(false);
        QIcon icon68;
        icon68.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/LineArrow_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_G_2->setIcon(icon68);
        action_N_2 = new QAction(Form_WorkSpace);
        action_N_2->setObjectName("action_N_2");
        action_N_2->setEnabled(false);
        QIcon icon69;
        icon69.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/RigidRelationshipError_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_N_2->setIcon(icon69);
        action_menu_compile = new QAction(Form_WorkSpace);
        action_menu_compile->setObjectName("action_menu_compile");
        action_menu_compile->setEnabled(false);
        QIcon icon70;
        icon70.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/BuildSelection_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_compile->setIcon(icon70);
        action_menu_staticCompile = new QAction(Form_WorkSpace);
        action_menu_staticCompile->setObjectName("action_menu_staticCompile");
        action_menu_staticCompile->setEnabled(false);
        QIcon icon71;
        icon71.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/BuildSolution_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu_staticCompile->setIcon(icon71);
        action_I_2 = new QAction(Form_WorkSpace);
        action_I_2->setObjectName("action_I_2");
        action_I_2->setEnabled(false);
        action_M_2 = new QAction(Form_WorkSpace);
        action_M_2->setObjectName("action_M_2");
        action_M_2->setEnabled(false);
        action_T_3 = new QAction(Form_WorkSpace);
        action_T_3->setObjectName("action_T_3");
        action_T_3->setEnabled(false);
        action_O_3 = new QAction(Form_WorkSpace);
        action_O_3->setObjectName("action_O_3");
        action_O_3->setCheckable(false);
        action_O_3->setEnabled(false);
        action_O_3->setVisible(true);
        action_O_3->setShortcutVisibleInContextMenu(true);
        action_Q = new QAction(Form_WorkSpace);
        action_Q->setObjectName("action_Q");
        QIcon icon72;
        icon72.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/FeedbackSmile_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Q->setIcon(icon72);
        action_W_2 = new QAction(Form_WorkSpace);
        action_W_2->setObjectName("action_W_2");
        action_H_2 = new QAction(Form_WorkSpace);
        action_H_2->setObjectName("action_H_2");
        action_E_3 = new QAction(Form_WorkSpace);
        action_E_3->setObjectName("action_E_3");
        action_T_4 = new QAction(Form_WorkSpace);
        action_T_4->setObjectName("action_T_4");
        action_T_4->setEnabled(false);
        action_D_2 = new QAction(Form_WorkSpace);
        action_D_2->setObjectName("action_D_2");
        action_D_2->setEnabled(false);
        QIcon icon73;
        icon73.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/Certificate_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_D_2->setIcon(icon73);
        action_C_4 = new QAction(Form_WorkSpace);
        action_C_4->setObjectName("action_C_4");
        action_about = new QAction(Form_WorkSpace);
        action_about->setObjectName("action_about");
        QIcon icon74;
        icon74.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/StatusHelp_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_about->setIcon(icon74);
        action_U_3 = new QAction(Form_WorkSpace);
        action_U_3->setObjectName("action_U_3");
        action_R_3 = new QAction(Form_WorkSpace);
        action_R_3->setObjectName("action_R_3");
        action_V_3 = new QAction(Form_WorkSpace);
        action_V_3->setObjectName("action_V_3");
        action_addNewPlugin = new QAction(Form_WorkSpace);
        action_addNewPlugin->setObjectName("action_addNewPlugin");
        QIcon icon75;
        icon75.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/CreateLibraryEnvironment_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_addNewPlugin->setIcon(icon75);
        action_pluginManger = new QAction(Form_WorkSpace);
        action_pluginManger->setObjectName("action_pluginManger");
        QIcon icon76;
        icon76.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/LibrarySetting_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_pluginManger->setIcon(icon76);
        action_O_4 = new QAction(Form_WorkSpace);
        action_O_4->setObjectName("action_O_4");
        QIcon icon77;
        icon77.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/Settings_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_O_4->setIcon(icon77);
        action_C_5 = new QAction(Form_WorkSpace);
        action_C_5->setObjectName("action_C_5");
        action_C_5->setIcon(icon73);
        action_F_2 = new QAction(Form_WorkSpace);
        action_F_2->setObjectName("action_F_2");
        actionBlue_N = new QAction(Form_WorkSpace);
        actionBlue_N->setObjectName("actionBlue_N");
        actionBlue_N->setCheckable(true);
        actionBlue_N->setChecked(true);
        actionBlue_N->setEnabled(true);
        QIcon icon78;
        icon78.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/CheckboxN_16x.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon78.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/MenuBar/Checkbox_16x.png"), QSize(), QIcon::Selected, QIcon::On);
        actionBlue_N->setIcon(icon78);
        actionBlue_W = new QAction(Form_WorkSpace);
        actionBlue_W->setObjectName("actionBlue_W");
        actionBlue_W->setCheckable(true);
        actionBlue_W->setEnabled(true);
        actionBlue_W->setIcon(icon78);
        actionBlue_D = new QAction(Form_WorkSpace);
        actionBlue_D->setObjectName("actionBlue_D");
        actionBlue_D->setCheckable(true);
        actionBlue_D->setEnabled(true);
        actionBlue_D->setIcon(icon78);
        actionaction43 = new QAction(Form_WorkSpace);
        actionaction43->setObjectName("actionaction43");
        actionaction43->setEnabled(false);
        QIcon icon79;
        icon79.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/AutosizeFixedWidth_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon79.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/AutosizeFixedWidth_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        actionaction43->setIcon(icon79);
        actionaction44 = new QAction(Form_WorkSpace);
        actionaction44->setObjectName("actionaction44");
        actionaction44->setEnabled(false);
        QIcon icon80;
        icon80.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/TextLineHeight_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon80.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/TextLineHeight_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        actionaction44->setIcon(icon80);
        actionaction45 = new QAction(Form_WorkSpace);
        actionaction45->setObjectName("actionaction45");
        actionaction45->setEnabled(false);
        QIcon icon81;
        icon81.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/AutosizeOptimize_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon81.addFile(QString::fromUtf8(":/Theme/icon/Theme/Blue/Image/ToolBar/Btn/displayIcon/AutosizeOptimize_16x.png"), QSize(), QIcon::Disabled, QIcon::Off);
        actionaction45->setIcon(icon81);
        action_dock_project = new QAction(Form_WorkSpace);
        action_dock_project->setObjectName("action_dock_project");
        action_dock_project->setCheckable(true);
        action_dock_project->setChecked(true);
        action_dock_project->setEnabled(true);
        action_dock_project->setIcon(icon78);
        action_dock_project->setAutoRepeat(true);
        action_dock_project->setVisible(true);
        action_dock_project->setIconVisibleInMenu(true);
        action_dock_project->setShortcutVisibleInContextMenu(true);
        action_dock_project->setPriority(QAction::NormalPriority);
        action_dock_compilePrint = new QAction(Form_WorkSpace);
        action_dock_compilePrint->setObjectName("action_dock_compilePrint");
        action_dock_compilePrint->setCheckable(true);
        action_dock_compilePrint->setChecked(true);
        action_dock_compilePrint->setIcon(icon78);
        action_dock_runTip = new QAction(Form_WorkSpace);
        action_dock_runTip->setObjectName("action_dock_runTip");
        action_dock_runTip->setCheckable(true);
        action_dock_runTip->setChecked(true);
        action_dock_runTip->setIcon(icon78);
        action_dock_debug = new QAction(Form_WorkSpace);
        action_dock_debug->setObjectName("action_dock_debug");
        action_dock_debug->setCheckable(true);
        action_dock_debug->setChecked(true);
        action_dock_debug->setIcon(icon78);
        action_dock_find = new QAction(Form_WorkSpace);
        action_dock_find->setObjectName("action_dock_find");
        action_dock_find->setCheckable(true);
        action_dock_find->setChecked(true);
        action_dock_find->setIcon(icon78);
        centralwidget = new QWidget(Form_WorkSpace);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 8, 0, 0);
        comboBox_compileMode = new QComboBox(centralwidget);
        comboBox_compileMode->addItem(QString());
        comboBox_compileMode->addItem(QString());
        comboBox_compileMode->setObjectName("comboBox_compileMode");
        comboBox_compileMode->setMinimumSize(QSize(150, 0));
        comboBox_compileMode->setEditable(false);

        gridLayout->addWidget(comboBox_compileMode, 0, 0, 1, 1);

        widget_WindowTab = new Form_WindowTab(centralwidget);
        widget_WindowTab->setObjectName("widget_WindowTab");

        gridLayout->addWidget(widget_WindowTab, 1, 0, 1, 1);

        Form_WorkSpace->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Form_WorkSpace);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 26));
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
        menu_T = new QMenu(menu_set);
        menu_T->setObjectName("menu_T");
        menu_editor = new QMenu(menubar);
        menu_editor->setObjectName("menu_editor");
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
        menu_file->addAction(action_file_saveAs);
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
        menu_debug->addAction(action_V_2);
        menu_debug->addAction(action_O_2);
        menu_debug->addAction(action_I);
        menu_debug->addAction(action_U_2);
        menu_debug->addAction(action_R_2);
        menu_debug->addSeparator();
        menu_debug->addAction(action_T_2);
        menu_debug->addAction(action_A);
        menu_debug->addAction(action_C_2);
        menu_debug->addSeparator();
        menu_debug->addAction(action_G_2);
        menu_debug->addAction(action_N_2);
        menu_compile->addAction(action_menu_compile);
        menu_compile->addAction(action_menu_staticCompile);
        menu_compile->addSeparator();
        menu_compile->addAction(action_I_2);
        menu_compile->addAction(action_M_2);
        menu_compile->addAction(action_T_3);
        menu_compile->addSeparator();
        menu_compile->addAction(action_O_3);
        menu_view->addAction(action_dock_project);
        menu_view->addAction(action_dock_compilePrint);
        menu_view->addAction(action_dock_runTip);
        menu_view->addAction(action_dock_debug);
        menu_view->addAction(action_dock_find);
        menu_help->addAction(action_Q);
        menu_help->addAction(action_W_2);
        menu_help->addSeparator();
        menu_help->addAction(action_H_2);
        menu_help->addAction(action_E_3);
        menu_help->addAction(action_T_4);
        menu_help->addAction(action_D_2);
        menu_help->addAction(action_C_4);
        menu_help->addSeparator();
        menu_help->addAction(action_about);
        menu_help->addAction(action_U_3);
        menu_help->addAction(action_R_3);
        menu_help->addAction(action_V_3);
        menu_set->addAction(action_addNewPlugin);
        menu_set->addAction(action_pluginManger);
        menu_set->addSeparator();
        menu_set->addAction(action_O_4);
        menu_set->addAction(menu_T->menuAction());
        menu_set->addSeparator();
        menu_set->addAction(action_C_5);
        menu_set->addAction(action_F_2);
        menu_T->addAction(actionBlue_N);
        menu_T->addAction(actionBlue_W);
        menu_T->addAction(actionBlue_D);
        menu_editor->addAction(action_U);
        menu_editor->addAction(action_R);
        menu_editor->addAction(action_C);
        menu_editor->addAction(action_T);
        menu_editor->addAction(action_P);
        menu_editor->addAction(action_D);
        menu_editor->addSeparator();
        menu_editor->addAction(action_F);
        menu_editor->addAction(action_G);
        menu_editor->addAction(action_N);
        menu_editor->addAction(action_V);
        menu_editor->addAction(action_H);
        menu_editor->addAction(action_E);
        menu_editor->addAction(action_W);
        toolBar->addAction(action1);
        toolBar->addAction(action2);
        toolBar->addSeparator();
        toolBar->addAction(action3);
        toolBar->addAction(action4);
        toolBar->addAction(action5);
        toolBar->addSeparator();
        toolBar->addAction(action6);
        toolBar->addAction(action7);
        toolBar->addAction(action8);
        toolBar->addAction(action9);
        toolBar->addAction(action10);
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
        toolBar->addAction(action18);
        toolBar->addAction(action19);
        toolBar->addSeparator();
        toolBar->addAction(action20);
        toolBar->addAction(action21);
        toolBar->addAction(action22);
        toolBar->addAction(action23);
        toolBar->addAction(action24);
        toolBar->addSeparator();
        toolBar->addAction(action25);
        toolBar->addSeparator();
        toolBar->addAction(action26);
        toolBar->addAction(action27);
        toolBar->addAction(action28);
        toolBar->addAction(action29);
        toolBar->addSeparator();
        toolBar->addAction(action30);
        toolBar->addAction(action31);
        toolBar_2->addAction(action32);
        toolBar_2->addSeparator();
        toolBar_2->addAction(action33);
        toolBar_2->addAction(action34);
        toolBar_2->addAction(action35);
        toolBar_2->addAction(action36);
        toolBar_2->addSeparator();
        toolBar_2->addAction(action37);
        toolBar_2->addAction(action38);
        toolBar_2->addSeparator();
        toolBar_2->addAction(action39);
        toolBar_2->addAction(action40);
        toolBar_2->addAction(action41);
        toolBar_2->addAction(action42);
        toolBar_2->addSeparator();
        toolBar_2->addAction(actionaction43);
        toolBar_2->addAction(actionaction44);
        toolBar_2->addAction(actionaction45);

        retranslateUi(Form_WorkSpace);

        QMetaObject::connectSlotsByName(Form_WorkSpace);
    } // setupUi

    void retranslateUi(QMainWindow *Form_WorkSpace)
    {
        Form_WorkSpace->setWindowTitle(QCoreApplication::translate("Form_WorkSpace", "FireMoneky Studio 2023", nullptr));
        action1->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action2->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action3->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action4->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action5->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action6->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action7->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action8->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action9->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action10->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action_toolBar_compile->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action_toolBar_staticCompile->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action_toolBar_onlineCompile->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
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
        action18->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action19->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action20->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action21->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action22->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action23->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action24->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action25->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action26->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action27->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action28->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action29->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action30->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action31->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action32->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action33->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action34->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action35->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action36->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action37->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action38->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action39->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action40->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action41->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action42->setText(QCoreApplication::translate("Form_WorkSpace", "5", nullptr));
        action_file_newCreate->setText(QCoreApplication::translate("Form_WorkSpace", "\346\226\260\345\273\272(&N)", nullptr));
        action_file_open->setText(QCoreApplication::translate("Form_WorkSpace", "\346\211\223\345\274\200(&O)", nullptr));
#if QT_CONFIG(shortcut)
        action_file_open->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_file_close->setText(QCoreApplication::translate("Form_WorkSpace", "\345\205\263\351\227\255(&C)", nullptr));
        action_file_save->setText(QCoreApplication::translate("Form_WorkSpace", "\344\277\235\345\255\230(&S)", nullptr));
#if QT_CONFIG(shortcut)
        action_file_save->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_file_saveAs->setText(QCoreApplication::translate("Form_WorkSpace", "\345\217\246\345\255\230\344\270\272(&A)", nullptr));
#if QT_CONFIG(shortcut)
        action_file_saveAs->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_file_saveAll->setText(QCoreApplication::translate("Form_WorkSpace", "\344\277\235\345\255\230\345\205\250\351\203\250(&M)", nullptr));
#if QT_CONFIG(tooltip)
        action_file_saveAll->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\344\277\235\345\255\230\345\205\250\351\203\250(M)", nullptr));
#endif // QT_CONFIG(tooltip)
        action_file_print->setText(QCoreApplication::translate("Form_WorkSpace", "\346\211\223\345\215\260(&P)", nullptr));
#if QT_CONFIG(shortcut)
        action_file_print->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        action_file_config->setText(QCoreApplication::translate("Form_WorkSpace", "\351\205\215\347\275\256(&U)", nullptr));
        action_file_connect->setText(QCoreApplication::translate("Form_WorkSpace", "\351\207\215\346\226\260\345\205\263\350\201\224\346\226\207\344\273\266\345\220\215(&L)", nullptr));
        action_file_exit->setText(QCoreApplication::translate("Form_WorkSpace", "\351\200\200\345\207\272(&X)", nullptr));
        action_U->setText(QCoreApplication::translate("Form_WorkSpace", "\346\222\244\351\224\200(&U)", nullptr));
#if QT_CONFIG(shortcut)
        action_U->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        action_R->setText(QCoreApplication::translate("Form_WorkSpace", "\351\207\215\345\244\215(&R)", nullptr));
#if QT_CONFIG(shortcut)
        action_R->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        action_C->setText(QCoreApplication::translate("Form_WorkSpace", "\345\244\215\345\210\266(&C)", nullptr));
#if QT_CONFIG(shortcut)
        action_C->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        action_T->setText(QCoreApplication::translate("Form_WorkSpace", "\345\211\252\345\210\207(&T)", nullptr));
#if QT_CONFIG(shortcut)
        action_T->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        action_P->setText(QCoreApplication::translate("Form_WorkSpace", "\347\262\230\350\264\264(&P)", nullptr));
#if QT_CONFIG(shortcut)
        action_P->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        action_D->setText(QCoreApplication::translate("Form_WorkSpace", "\345\210\240\351\231\244\350\241\214(&D)", nullptr));
#if QT_CONFIG(shortcut)
        action_D->setShortcut(QCoreApplication::translate("Form_WorkSpace", "F10", nullptr));
#endif // QT_CONFIG(shortcut)
        action_F->setText(QCoreApplication::translate("Form_WorkSpace", "\345\274\200\345\247\213\346\237\245\346\211\276(&F)", nullptr));
#if QT_CONFIG(shortcut)
        action_F->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        action_G->setText(QCoreApplication::translate("Form_WorkSpace", "\351\253\230\344\272\256\346\240\207\350\256\260\345\276\205\345\257\273\346\211\276\345\215\225\350\257\215(&G)", nullptr));
#if QT_CONFIG(shortcut)
        action_G->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        action_N->setText(QCoreApplication::translate("Form_WorkSpace", "\345\257\273\346\211\276\344\270\213\344\270\200\344\270\252(&N)", nullptr));
#if QT_CONFIG(shortcut)
        action_N->setShortcut(QCoreApplication::translate("Form_WorkSpace", "F3", nullptr));
#endif // QT_CONFIG(shortcut)
        action_V->setText(QCoreApplication::translate("Form_WorkSpace", "\345\257\273\346\211\276\344\270\212\344\270\200\344\270\252(&V)", nullptr));
#if QT_CONFIG(shortcut)
        action_V->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Shift+F3", nullptr));
#endif // QT_CONFIG(shortcut)
        action_H->setText(QCoreApplication::translate("Form_WorkSpace", "\345\257\273\346\211\276\346\233\277\346\215\242(&H)", nullptr));
#if QT_CONFIG(shortcut)
        action_H->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        action_E->setText(QCoreApplication::translate("Form_WorkSpace", "\346\225\264\344\275\223\346\220\234\345\257\273(&E)", nullptr));
#if QT_CONFIG(shortcut)
        action_E->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Alt+F", nullptr));
#endif // QT_CONFIG(shortcut)
        action_W->setText(QCoreApplication::translate("Form_WorkSpace", "\350\267\263\350\275\254\345\210\260\346\214\207\345\256\232\350\241\214(&W)", nullptr));
#if QT_CONFIG(shortcut)
        action_W->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+W", nullptr));
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
        action_V_2->setText(QCoreApplication::translate("Form_WorkSpace", "\346\237\245\347\234\213\350\241\250\350\276\276\345\274\217/\345\217\230\351\207\217(&V)", nullptr));
#if QT_CONFIG(shortcut)
        action_V_2->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Shift+F9", nullptr));
#endif // QT_CONFIG(shortcut)
        action_O_2->setText(QCoreApplication::translate("Form_WorkSpace", "\345\215\225\346\255\245\350\267\237\350\270\252(&O)", nullptr));
#if QT_CONFIG(shortcut)
        action_O_2->setShortcut(QCoreApplication::translate("Form_WorkSpace", "F8", nullptr));
#endif // QT_CONFIG(shortcut)
        action_I->setText(QCoreApplication::translate("Form_WorkSpace", "\345\215\225\346\255\245\350\267\237\350\270\252\350\277\233\345\205\245(&I)", nullptr));
#if QT_CONFIG(shortcut)
        action_I->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Shift+F8", nullptr));
#endif // QT_CONFIG(shortcut)
        action_U_2->setText(QCoreApplication::translate("Form_WorkSpace", "\350\267\237\350\270\252\350\277\224\345\233\236(&U)", nullptr));
#if QT_CONFIG(shortcut)
        action_U_2->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Shift+F8", nullptr));
#endif // QT_CONFIG(shortcut)
        action_R_2->setText(QCoreApplication::translate("Form_WorkSpace", "\346\211\247\350\241\214\345\210\260\345\205\211\346\240\207\345\244\204(&R)", nullptr));
#if QT_CONFIG(shortcut)
        action_R_2->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+F8", nullptr));
#endif // QT_CONFIG(shortcut)
        action_T_2->setText(QCoreApplication::translate("Form_WorkSpace", "\350\256\276\347\275\256\346\210\226\346\270\205\351\231\244\346\226\255\347\202\271(&T)", nullptr));
#if QT_CONFIG(shortcut)
        action_T_2->setShortcut(QCoreApplication::translate("Form_WorkSpace", "F9", nullptr));
#endif // QT_CONFIG(shortcut)
        action_A->setText(QCoreApplication::translate("Form_WorkSpace", "\346\235\241\344\273\266\346\226\255\347\202\271(&A)", nullptr));
#if QT_CONFIG(shortcut)
        action_A->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+F9", nullptr));
#endif // QT_CONFIG(shortcut)
        action_C_2->setText(QCoreApplication::translate("Form_WorkSpace", "\346\270\205\346\245\232\346\211\200\346\234\211\346\226\255\347\202\271(&C)", nullptr));
#if QT_CONFIG(shortcut)
        action_C_2->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Shift+F9", nullptr));
#endif // QT_CONFIG(shortcut)
        action_G_2->setText(QCoreApplication::translate("Form_WorkSpace", "\345\210\260\347\216\260\350\241\214\346\211\247\350\241\214\344\275\215\347\275\256(&G)", nullptr));
#if QT_CONFIG(shortcut)
        action_G_2->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+.", nullptr));
#endif // QT_CONFIG(shortcut)
        action_N_2->setText(QCoreApplication::translate("Form_WorkSpace", "\345\210\260\350\277\220\350\241\214\346\227\266\351\224\231\350\257\257\347\233\270\345\205\263\344\275\215\347\275\256(&N)", nullptr));
        action_menu_compile->setText(QCoreApplication::translate("Form_WorkSpace", "\347\274\226\350\257\221(&C)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_compile->setShortcut(QCoreApplication::translate("Form_WorkSpace", "F7", nullptr));
#endif // QT_CONFIG(shortcut)
        action_menu_staticCompile->setText(QCoreApplication::translate("Form_WorkSpace", "\351\235\231\346\200\201\347\274\226\350\257\221(&S)", nullptr));
#if QT_CONFIG(shortcut)
        action_menu_staticCompile->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Shift+F7", nullptr));
#endif // QT_CONFIG(shortcut)
        action_I_2->setText(QCoreApplication::translate("Form_WorkSpace", "\347\274\226\350\257\221\347\224\237\346\210\220\345\256\211\350\243\205\350\275\257\344\273\266(&I)", nullptr));
#if QT_CONFIG(shortcut)
        action_I_2->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Shift+F7", nullptr));
#endif // QT_CONFIG(shortcut)
        action_M_2->setText(QCoreApplication::translate("Form_WorkSpace", "\347\274\226\350\257\221\344\270\272\346\214\207\345\256\232\347\261\273\345\236\213(&M)", nullptr));
        action_T_3->setText(QCoreApplication::translate("Form_WorkSpace", "\351\235\231\346\200\201\347\274\226\350\257\221\344\270\272\346\214\207\345\256\232\347\261\273\345\236\213(&T)", nullptr));
        action_O_3->setText(QCoreApplication::translate("Form_WorkSpace", "\345\205\266\344\273\226\347\274\226\350\257\221(&O)", nullptr));
        action_Q->setText(QCoreApplication::translate("Form_WorkSpace", "\345\273\272\350\256\256\345\217\215\351\246\210(&Q)", nullptr));
        action_W_2->setText(QCoreApplication::translate("Form_WorkSpace", "\344\275\277\347\224\250\346\235\241\346\254\276(&W)", nullptr));
        action_H_2->setText(QCoreApplication::translate("Form_WorkSpace", "\346\231\272\350\203\275\345\274\200\345\217\221\345\212\251\346\211\213(&H)", nullptr));
#if QT_CONFIG(shortcut)
        action_H_2->setShortcut(QCoreApplication::translate("Form_WorkSpace", "Ctrl+Alt+H", nullptr));
#endif // QT_CONFIG(shortcut)
        action_E_3->setText(QCoreApplication::translate("Form_WorkSpace", "\347\237\245\350\257\206\345\272\223(&E)", nullptr));
        action_T_4->setText(QCoreApplication::translate("Form_WorkSpace", "\345\244\232\345\252\222\344\275\223\346\225\231\347\250\213(&T)", nullptr));
        action_D_2->setText(QCoreApplication::translate("Form_WorkSpace", "\346\257\217\346\227\245\344\270\200\350\264\264(&D)", nullptr));
        action_C_4->setText(QCoreApplication::translate("Form_WorkSpace", "\346\224\257\346\214\201\345\272\223\346\211\213\345\206\214\345\217\212\344\276\213\347\250\213(&C)", nullptr));
        action_about->setText(QCoreApplication::translate("Form_WorkSpace", "\345\205\263\344\272\216(&A)", nullptr));
        action_U_3->setText(QCoreApplication::translate("Form_WorkSpace", "\347\224\250\346\210\267\345\217\215\351\246\210\350\241\250(&U)", nullptr));
        action_R_3->setText(QCoreApplication::translate("Form_WorkSpace", "\350\264\255\344\271\260\344\270\216\345\225\206\344\270\232\345\220\210\344\275\234(&R)", nullptr));
        action_V_3->setText(QCoreApplication::translate("Form_WorkSpace", "\345\271\263\345\217\260\345\256\211\345\205\250\346\243\200\346\265\213\346\212\245\345\221\212(&V)", nullptr));
        action_addNewPlugin->setText(QCoreApplication::translate("Form_WorkSpace", "\345\256\211\350\243\205\346\226\260\347\232\204\346\217\222\344\273\266\346\224\257\346\214\201(&I)", nullptr));
#if QT_CONFIG(tooltip)
        action_addNewPlugin->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\345\256\211\350\243\205\346\226\260\347\232\204\346\217\222\344\273\266\346\224\257\346\214\201(I)", nullptr));
#endif // QT_CONFIG(tooltip)
        action_pluginManger->setText(QCoreApplication::translate("Form_WorkSpace", "\346\217\222\344\273\266\347\256\241\347\220\206\345\231\250(&L)", nullptr));
#if QT_CONFIG(tooltip)
        action_pluginManger->setToolTip(QCoreApplication::translate("Form_WorkSpace", "\346\217\222\344\273\266\347\256\241\347\220\206\345\231\250(L)", nullptr));
#endif // QT_CONFIG(tooltip)
        action_O_4->setText(QCoreApplication::translate("Form_WorkSpace", "\347\263\273\347\273\237\350\256\276\347\275\256(&O)", nullptr));
        action_C_5->setText(QCoreApplication::translate("Form_WorkSpace", "\347\255\276\345\220\215\350\256\244\350\257\201(&C)", nullptr));
        action_F_2->setText(QCoreApplication::translate("Form_WorkSpace", "\345\234\250\346\250\241\345\235\227\345\217\212\346\224\257\346\214\201\345\272\223\344\270\255\346\237\245\346\211\276(&F)", nullptr));
        actionBlue_N->setText(QCoreApplication::translate("Form_WorkSpace", "Blue(\351\273\230\350\256\244)(&N)", nullptr));
#if QT_CONFIG(tooltip)
        actionBlue_N->setToolTip(QCoreApplication::translate("Form_WorkSpace", "Blue(N)", nullptr));
#endif // QT_CONFIG(tooltip)
        actionBlue_W->setText(QCoreApplication::translate("Form_WorkSpace", "White(&W)", nullptr));
        actionBlue_D->setText(QCoreApplication::translate("Form_WorkSpace", "Black(&D)", nullptr));
        actionaction43->setText(QCoreApplication::translate("Form_WorkSpace", "action43", nullptr));
        actionaction44->setText(QCoreApplication::translate("Form_WorkSpace", "action44", nullptr));
        actionaction45->setText(QCoreApplication::translate("Form_WorkSpace", "action45", nullptr));
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
        menu_T->setTitle(QCoreApplication::translate("Form_WorkSpace", "\344\270\273\351\242\230(&T)", nullptr));
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
