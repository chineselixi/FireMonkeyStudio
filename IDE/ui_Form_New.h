/********************************************************************************
** Form generated from reading UI file 'Form_New.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_NEW_H
#define UI_FORM_NEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Widget/Widget_Button_Start.h"

QT_BEGIN_NAMESPACE

class Ui_Form_New
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_main;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_tip1;
    QListWidget *listWidget_ProjectList;
    QFrame *frame;
    QLabel *label_tip2;
    QLabel *label_Jump;
    Widget_Button_Start *Btn_CreateProject;
    Widget_Button_Start *Btn_OpenDir;
    Widget_Button_Start *Btn_OpenProject;
    Widget_Button_Start *Btn_FromGit;
    QWidget *page_git;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_2;
    QLabel *label_tip1_2;
    QLabel *label_3;
    QLineEdit *lineEdit_Path;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *lineEdit_URL;
    QPushButton *pushButton_git_path;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_3;
    QPushButton *pushButton_back_toStart;
    QPushButton *pushButton_clone;
    QWidget *page_projectMod;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label_tip1_3;
    QListWidget *listWidget_ModHistory;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox_findMod;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *comboBox_lang;
    QComboBox *comboBox_os;
    QComboBox *comboBox_other;
    QSpacerItem *horizontalSpacer_4;
    QListWidget *listWidget_ModList;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_back_toMain2;
    QPushButton *pushButton_next_toCreate;
    QWidget *page_create;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame_6;
    QLabel *label_tip1_5;
    QLabel *label_9;
    QLineEdit *lineEdit_Path_3;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_projectName;
    QPushButton *pushButton_path_3;
    QLabel *label_12;
    QLineEdit *lineEdit_pathName;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_createTip;
    QPushButton *pushButton_back_toModList;
    QPushButton *pushButton_createProject;

    void setupUi(QWidget *Form_New)
    {
        if (Form_New->objectName().isEmpty())
            Form_New->setObjectName("Form_New");
        Form_New->resize(890, 600);
        Form_New->setMinimumSize(QSize(890, 600));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("applications-office");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        Form_New->setWindowIcon(icon);
        Form_New->setStyleSheet(QString::fromUtf8("/*\344\270\273\350\203\214\346\231\257\345\222\214\345\210\227\350\241\250\350\203\214\346\231\257*/\n"
"#Form_New,QListWidget{\n"
"	background-color: rgb(251, 251, 251);\n"
"}\n"
"\n"
"\n"
"/*\345\210\227\350\241\250\346\240\267\345\274\217*/\n"
"QListWidget{\n"
"	border:0px;\n"
"}\n"
"QListWidget::item:selected {\n"
"    background-color: #B5E7FF;\n"
"    color: black;\n"
"}\n"
"\n"
" /*\345\255\220\351\241\271\346\240\267\345\274\217\n"
".QListWidget::item:hover{\n"
"	background-color:rgb(196, 213, 255);\n"
"}\n"
".QListWidget::item:focus {\n"
"	border: 1px solid rgb(93, 107, 153);\n"
"	background-color: rgb(196, 213, 255);\n"
"}\n"
"*/\n"
"\n"
"\n"
"\n"
"/*\345\210\227\350\241\250\346\214\211\351\222\256\346\240\267\345\274\217*/\n"
".Widget_Button_Start{\n"
"	background-color: rgb(238, 235, 235);\n"
"}\n"
".Widget_Button_Start:hover{\n"
"	background-color: rgb(208, 231, 248);\n"
"}\n"
"\n"
"\n"
"\n"
"/*\350\267\263\350\275\254\346\240\207\347\255\276\346\240\267\345\274\217*/\n"
"#label_Jump{\n"
"	color: "
                        "rgb(0, 108, 209);\n"
"}\n"
"#label_Jump:hover{\n"
"	text-decoration: underline;\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"\n"
"/*\346\214\211\351\222\256\346\240\267\345\274\217*/\n"
"QPushButton{\n"
"	border-radius:0px;\n"
"	border:1px solid rgb(133, 145, 162);\n"
"	background-color: rgb(242, 245, 252);\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(196, 213, 255);\n"
"}\n"
"QPushButton:!enabled{\n"
"	color:rgb(162, 164, 165);\n"
"	background-color: rgb(223, 231, 243);\n"
"	border:1px solid rgb(162, 164, 165);\n"
"}\n"
"\n"
"/*\345\210\233\345\273\272\351\241\271\347\233\256\347\232\204\344\277\241\346\201\257\346\217\220\347\244\272*/\n"
"#label_createTip{\n"
"	color: rgb(255, 0, 0);\n"
"	margin-right:20px;\n"
"}"));
        gridLayout = new QGridLayout(Form_New);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(Form_New);
        stackedWidget->setObjectName("stackedWidget");
        page_main = new QWidget();
        page_main->setObjectName("page_main");
        gridLayout_2 = new QGridLayout(page_main);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(30, -1, 0, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(page_main);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 41));
        label->setMaximumSize(QSize(16777215, 41));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, -1, 50, -1);
        label_tip1 = new QLabel(page_main);
        label_tip1->setObjectName("label_tip1");
        label_tip1->setMinimumSize(QSize(0, 70));
        label_tip1->setMaximumSize(QSize(16777215, 70));
        QFont font1;
        font1.setPointSize(14);
        label_tip1->setFont(font1);

        verticalLayout->addWidget(label_tip1);

        listWidget_ProjectList = new QListWidget(page_main);
        listWidget_ProjectList->setObjectName("listWidget_ProjectList");
        listWidget_ProjectList->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);

        verticalLayout->addWidget(listWidget_ProjectList);


        horizontalLayout->addLayout(verticalLayout);

        frame = new QFrame(page_main);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(410, 0));
        frame->setMaximumSize(QSize(410, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_tip2 = new QLabel(frame);
        label_tip2->setObjectName("label_tip2");
        label_tip2->setGeometry(QRect(20, 1, 359, 70));
        label_tip2->setMinimumSize(QSize(0, 70));
        label_tip2->setMaximumSize(QSize(16777215, 70));
        label_tip2->setFont(font1);
        label_Jump = new QLabel(frame);
        label_Jump->setObjectName("label_Jump");
        label_Jump->setGeometry(QRect(20, 410, 345, 31));
        label_Jump->setCursor(QCursor(Qt::PointingHandCursor));
        label_Jump->setStyleSheet(QString::fromUtf8("#label_Jump{\n"
"	color: rgb(0, 108, 209);\n"
"	border-bottom: 2px solid transparent;\n"
"}\n"
"#label_Jump:hover{\n"
"	color: rgb(0, 0, 0);\n"
"	text-decoration: underline;\n"
"}"));
        label_Jump->setAlignment(Qt::AlignCenter);
        Btn_CreateProject = new Widget_Button_Start(frame);
        Btn_CreateProject->setObjectName("Btn_CreateProject");
        Btn_CreateProject->setGeometry(QRect(20, 240, 345, 80));
        Btn_OpenDir = new Widget_Button_Start(frame);
        Btn_OpenDir->setObjectName("Btn_OpenDir");
        Btn_OpenDir->setGeometry(QRect(20, 155, 345, 80));
        Btn_OpenProject = new Widget_Button_Start(frame);
        Btn_OpenProject->setObjectName("Btn_OpenProject");
        Btn_OpenProject->setGeometry(QRect(20, 80, 345, 70));
        Btn_FromGit = new Widget_Button_Start(frame);
        Btn_FromGit->setObjectName("Btn_FromGit");
        Btn_FromGit->setGeometry(QRect(20, 325, 345, 80));

        horizontalLayout->addWidget(frame);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        stackedWidget->addWidget(page_main);
        page_git = new QWidget();
        page_git->setObjectName("page_git");
        verticalLayout_3 = new QVBoxLayout(page_git);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(30, -1, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        frame_2 = new QFrame(page_git);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(610, 270));
        frame_2->setMaximumSize(QSize(610, 270));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_tip1_2 = new QLabel(frame_2);
        label_tip1_2->setObjectName("label_tip1_2");
        label_tip1_2->setGeometry(QRect(0, 65, 388, 30));
        label_tip1_2->setMinimumSize(QSize(0, 0));
        label_tip1_2->setMaximumSize(QSize(16777215, 70));
        label_tip1_2->setFont(font1);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 115, 111, 20));
        lineEdit_Path = new QLineEdit(frame_2);
        lineEdit_Path->setObjectName("lineEdit_Path");
        lineEdit_Path->setGeometry(QRect(0, 210, 530, 25));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 190, 111, 20));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 10, 491, 41));
        label_2->setMinimumSize(QSize(0, 41));
        label_2->setMaximumSize(QSize(16777215, 41));
        label_2->setFont(font);
        lineEdit_URL = new QLineEdit(frame_2);
        lineEdit_URL->setObjectName("lineEdit_URL");
        lineEdit_URL->setGeometry(QRect(0, 140, 530, 25));
        pushButton_git_path = new QPushButton(frame_2);
        pushButton_git_path->setObjectName("pushButton_git_path");
        pushButton_git_path->setGeometry(QRect(545, 210, 30, 25));
        pushButton_git_path->setMinimumSize(QSize(30, 25));
        pushButton_git_path->setMaximumSize(QSize(35, 25));
        QFont font2;
        font2.setPointSize(10);
        pushButton_git_path->setFont(font2);

        horizontalLayout_2->addWidget(frame_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 243, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        frame_3 = new QFrame(page_git);
        frame_3->setObjectName("frame_3");
        frame_3->setMinimumSize(QSize(200, 50));
        frame_3->setMaximumSize(QSize(200, 50));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        pushButton_back_toStart = new QPushButton(frame_3);
        pushButton_back_toStart->setObjectName("pushButton_back_toStart");
        pushButton_back_toStart->setGeometry(QRect(5, 10, 90, 30));
        pushButton_back_toStart->setMinimumSize(QSize(90, 30));
        pushButton_back_toStart->setMaximumSize(QSize(90, 30));
        pushButton_clone = new QPushButton(frame_3);
        pushButton_clone->setObjectName("pushButton_clone");
        pushButton_clone->setEnabled(false);
        pushButton_clone->setGeometry(QRect(100, 10, 90, 30));
        pushButton_clone->setMinimumSize(QSize(90, 30));
        pushButton_clone->setMaximumSize(QSize(90, 30));
        pushButton_clone->setAutoDefault(false);
        pushButton_clone->setFlat(false);

        horizontalLayout_3->addWidget(frame_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(page_git);
        page_projectMod = new QWidget();
        page_projectMod->setObjectName("page_projectMod");
        horizontalLayout_4 = new QHBoxLayout(page_projectMod);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(30, -1, 9, -1);
        frame_4 = new QFrame(page_projectMod);
        frame_4->setObjectName("frame_4");
        frame_4->setMinimumSize(QSize(280, 0));
        frame_4->setMaximumSize(QSize(500, 16777215));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_4);
        verticalLayout_4->setSpacing(12);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_5 = new QLabel(frame_4);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(0, 30));
        label_5->setMaximumSize(QSize(65535, 30));
        label_5->setFont(font);

        verticalLayout_4->addWidget(label_5);

        label_tip1_3 = new QLabel(frame_4);
        label_tip1_3->setObjectName("label_tip1_3");
        label_tip1_3->setMinimumSize(QSize(0, 0));
        label_tip1_3->setMaximumSize(QSize(16777215, 70));
        label_tip1_3->setFont(font1);

        verticalLayout_4->addWidget(label_tip1_3);

        listWidget_ModHistory = new QListWidget(frame_4);
        listWidget_ModHistory->setObjectName("listWidget_ModHistory");

        verticalLayout_4->addWidget(listWidget_ModHistory);


        horizontalLayout_4->addWidget(frame_4);

        frame_5 = new QFrame(page_projectMod);
        frame_5->setObjectName("frame_5");
        frame_5->setMinimumSize(QSize(500, 0));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_5);
        verticalLayout_5->setSpacing(15);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(25, 25, 20, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        comboBox_findMod = new QComboBox(frame_5);
        comboBox_findMod->setObjectName("comboBox_findMod");
        comboBox_findMod->setMinimumSize(QSize(360, 30));
        comboBox_findMod->setMaximumSize(QSize(30, 16777215));
        comboBox_findMod->setEditable(true);
        comboBox_findMod->setDuplicatesEnabled(false);

        horizontalLayout_5->addWidget(comboBox_findMod);

        horizontalSpacer_3 = new QSpacerItem(40, 27, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        comboBox_lang = new QComboBox(frame_5);
        comboBox_lang->addItem(QString());
        comboBox_lang->setObjectName("comboBox_lang");
        comboBox_lang->setMinimumSize(QSize(160, 22));
        comboBox_lang->setMaximumSize(QSize(160, 22));

        horizontalLayout_6->addWidget(comboBox_lang);

        comboBox_os = new QComboBox(frame_5);
        comboBox_os->addItem(QString());
        comboBox_os->setObjectName("comboBox_os");
        comboBox_os->setMinimumSize(QSize(160, 22));
        comboBox_os->setMaximumSize(QSize(160, 22));

        horizontalLayout_6->addWidget(comboBox_os);

        comboBox_other = new QComboBox(frame_5);
        comboBox_other->addItem(QString());
        comboBox_other->setObjectName("comboBox_other");
        comboBox_other->setMinimumSize(QSize(160, 22));
        comboBox_other->setMaximumSize(QSize(160, 22));

        horizontalLayout_6->addWidget(comboBox_other);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_6);

        listWidget_ModList = new QListWidget(frame_5);
        listWidget_ModList->setObjectName("listWidget_ModList");
        listWidget_ModList->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        listWidget_ModList->setSelectionMode(QAbstractItemView::SingleSelection);
        listWidget_ModList->setProperty("isWrapping", QVariant(false));
        listWidget_ModList->setSelectionRectVisible(false);

        verticalLayout_5->addWidget(listWidget_ModList);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        pushButton_back_toMain2 = new QPushButton(frame_5);
        pushButton_back_toMain2->setObjectName("pushButton_back_toMain2");
        pushButton_back_toMain2->setMinimumSize(QSize(90, 30));
        pushButton_back_toMain2->setMaximumSize(QSize(90, 30));

        horizontalLayout_7->addWidget(pushButton_back_toMain2);

        pushButton_next_toCreate = new QPushButton(frame_5);
        pushButton_next_toCreate->setObjectName("pushButton_next_toCreate");
        pushButton_next_toCreate->setEnabled(false);
        pushButton_next_toCreate->setMinimumSize(QSize(90, 30));
        pushButton_next_toCreate->setMaximumSize(QSize(90, 30));
        pushButton_next_toCreate->setAutoDefault(false);
        pushButton_next_toCreate->setFlat(false);

        horizontalLayout_7->addWidget(pushButton_next_toCreate);


        verticalLayout_5->addLayout(horizontalLayout_7);


        horizontalLayout_4->addWidget(frame_5);

        stackedWidget->addWidget(page_projectMod);
        page_create = new QWidget();
        page_create->setObjectName("page_create");
        verticalLayout_6 = new QVBoxLayout(page_create);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, -1, -1);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        frame_6 = new QFrame(page_create);
        frame_6->setObjectName("frame_6");
        frame_6->setMinimumSize(QSize(610, 320));
        frame_6->setMaximumSize(QSize(65535, 320));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_tip1_5 = new QLabel(frame_6);
        label_tip1_5->setObjectName("label_tip1_5");
        label_tip1_5->setGeometry(QRect(20, 65, 388, 30));
        label_tip1_5->setMinimumSize(QSize(0, 0));
        label_tip1_5->setMaximumSize(QSize(16777215, 70));
        label_tip1_5->setFont(font1);
        label_9 = new QLabel(frame_6);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 115, 111, 20));
        lineEdit_Path_3 = new QLineEdit(frame_6);
        lineEdit_Path_3->setObjectName("lineEdit_Path_3");
        lineEdit_Path_3->setGeometry(QRect(20, 200, 530, 25));
        label_10 = new QLabel(frame_6);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 180, 111, 20));
        label_11 = new QLabel(frame_6);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 10, 491, 41));
        label_11->setMinimumSize(QSize(0, 41));
        label_11->setMaximumSize(QSize(16777215, 41));
        label_11->setFont(font);
        lineEdit_projectName = new QLineEdit(frame_6);
        lineEdit_projectName->setObjectName("lineEdit_projectName");
        lineEdit_projectName->setGeometry(QRect(20, 140, 530, 25));
        pushButton_path_3 = new QPushButton(frame_6);
        pushButton_path_3->setObjectName("pushButton_path_3");
        pushButton_path_3->setGeometry(QRect(565, 200, 30, 25));
        pushButton_path_3->setMinimumSize(QSize(30, 25));
        pushButton_path_3->setMaximumSize(QSize(35, 25));
        pushButton_path_3->setFont(font2);
        label_12 = new QLabel(frame_6);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 240, 111, 20));
        lineEdit_pathName = new QLineEdit(frame_6);
        lineEdit_pathName->setObjectName("lineEdit_pathName");
        lineEdit_pathName->setGeometry(QRect(20, 260, 530, 25));

        horizontalLayout_8->addWidget(frame_6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        verticalLayout_6->addLayout(horizontalLayout_8);

        verticalSpacer_2 = new QSpacerItem(20, 222, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalSpacer_7 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);

        label_createTip = new QLabel(page_create);
        label_createTip->setObjectName("label_createTip");
        label_createTip->setMinimumSize(QSize(200, 0));
        label_createTip->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_createTip);

        pushButton_back_toModList = new QPushButton(page_create);
        pushButton_back_toModList->setObjectName("pushButton_back_toModList");
        pushButton_back_toModList->setMinimumSize(QSize(90, 30));
        pushButton_back_toModList->setMaximumSize(QSize(90, 30));

        horizontalLayout_9->addWidget(pushButton_back_toModList);

        pushButton_createProject = new QPushButton(page_create);
        pushButton_createProject->setObjectName("pushButton_createProject");
        pushButton_createProject->setEnabled(false);
        pushButton_createProject->setMinimumSize(QSize(90, 30));
        pushButton_createProject->setMaximumSize(QSize(90, 30));
        pushButton_createProject->setAutoDefault(false);
        pushButton_createProject->setFlat(false);

        horizontalLayout_9->addWidget(pushButton_createProject);


        verticalLayout_6->addLayout(horizontalLayout_9);

        stackedWidget->addWidget(page_create);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(Form_New);

        stackedWidget->setCurrentIndex(0);
        pushButton_clone->setDefault(false);
        pushButton_next_toCreate->setDefault(false);
        pushButton_createProject->setDefault(false);


        QMetaObject::connectSlotsByName(Form_New);
    } // setupUi

    void retranslateUi(QWidget *Form_New)
    {
        Form_New->setWindowTitle(QCoreApplication::translate("Form_New", "\345\210\233\345\273\272\346\210\226\346\211\223\345\274\200\345\267\245\347\250\213", nullptr));
        label->setText(QCoreApplication::translate("Form_New", "FireMonkey Studio 2023", nullptr));
        label_tip1->setText(QCoreApplication::translate("Form_New", "\346\211\223\345\274\200\346\234\200\350\277\221\344\275\277\347\224\250\347\232\204\345\206\205\345\256\271", nullptr));
        label_tip2->setText(QCoreApplication::translate("Form_New", "\345\274\200\345\247\213\344\275\277\347\224\250", nullptr));
        label_Jump->setText(QCoreApplication::translate("Form_New", "\347\273\247\347\273\255\344\275\206\346\227\240\351\234\200\344\273\243\347\240\201 \342\206\222", nullptr));
        label_tip1_2->setText(QCoreApplication::translate("Form_New", "\350\276\223\345\205\245 Git \345\255\230\345\202\250\345\272\223 URL", nullptr));
        label_3->setText(QCoreApplication::translate("Form_New", "\345\255\230\345\202\250\345\272\223\344\275\215\347\275\256", nullptr));
        lineEdit_Path->setPlaceholderText(QCoreApplication::translate("Form_New", "uesr/document/src", nullptr));
        label_4->setText(QCoreApplication::translate("Form_New", "\350\267\257\345\276\204", nullptr));
        label_2->setText(QCoreApplication::translate("Form_New", "\345\205\213\351\232\206\345\255\230\345\202\250\345\272\223", nullptr));
        lineEdit_URL->setPlaceholderText(QCoreApplication::translate("Form_New", "https://example.com/example.git <\345\277\205\345\241\253>", nullptr));
        pushButton_git_path->setText(QCoreApplication::translate("Form_New", "...", nullptr));
        pushButton_back_toStart->setText(QCoreApplication::translate("Form_New", "\344\270\212\344\270\200\346\255\245", nullptr));
        pushButton_clone->setText(QCoreApplication::translate("Form_New", "\345\205\213\351\232\206", nullptr));
        label_5->setText(QCoreApplication::translate("Form_New", "\345\210\233\345\273\272\346\226\260\351\241\271\347\233\256", nullptr));
        label_tip1_3->setText(QCoreApplication::translate("Form_New", "\346\234\200\350\277\221\344\275\277\347\224\250\347\232\204\351\241\271\347\233\256\346\250\241\346\235\277", nullptr));
        comboBox_findMod->setCurrentText(QString());
        comboBox_findMod->setPlaceholderText(QString());
        comboBox_lang->setItemText(0, QCoreApplication::translate("Form_New", "\346\211\200\346\234\211\350\257\255\350\250\200", nullptr));

        comboBox_os->setItemText(0, QCoreApplication::translate("Form_New", "\346\211\200\346\234\211\345\271\263\345\217\260", nullptr));

        comboBox_other->setItemText(0, QCoreApplication::translate("Form_New", "\346\211\200\346\234\211\351\231\204\345\212\240\346\235\241\344\273\266", nullptr));

        pushButton_back_toMain2->setText(QCoreApplication::translate("Form_New", "\344\270\212\344\270\200\346\255\245", nullptr));
        pushButton_next_toCreate->setText(QCoreApplication::translate("Form_New", "\344\270\213\344\270\200\346\255\245", nullptr));
        label_tip1_5->setText(QCoreApplication::translate("Form_New", "\346\216\247\345\210\266\345\217\260\345\272\224\347\224\250", nullptr));
        label_9->setText(QCoreApplication::translate("Form_New", "\351\241\271\347\233\256\345\220\215\347\247\260", nullptr));
        lineEdit_Path_3->setPlaceholderText(QCoreApplication::translate("Form_New", "uesr/document/src", nullptr));
        label_10->setText(QCoreApplication::translate("Form_New", "\350\267\257\345\276\204", nullptr));
        label_11->setText(QCoreApplication::translate("Form_New", "\351\205\215\347\275\256\346\226\260\351\241\271\347\233\256", nullptr));
        lineEdit_projectName->setPlaceholderText(QCoreApplication::translate("Form_New", "\351\241\271\347\233\256\346\226\207\344\273\266\345\220\215 <\345\277\205\345\241\253>", nullptr));
        pushButton_path_3->setText(QCoreApplication::translate("Form_New", "...", nullptr));
        label_12->setText(QCoreApplication::translate("Form_New", "\350\247\243\345\206\263\346\226\271\346\241\210\345\220\215\347\247\260", nullptr));
        lineEdit_pathName->setPlaceholderText(QCoreApplication::translate("Form_New", "\350\247\243\345\206\263\346\226\271\346\241\210\346\226\207\344\273\266\347\232\204\345\220\215\347\247\260\357\274\214\344\271\237\345\260\206\347\224\250\344\272\216\345\221\275\345\220\215\345\267\245\347\250\213\347\233\256\345\275\225\345\222\214\345\220\257\345\212\250\346\226\207\344\273\266", nullptr));
        label_createTip->setText(QString());
        pushButton_back_toModList->setText(QCoreApplication::translate("Form_New", "\344\270\212\344\270\200\346\255\245", nullptr));
        pushButton_createProject->setText(QCoreApplication::translate("Form_New", "\345\210\233\345\273\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_New: public Ui_Form_New {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_NEW_H
