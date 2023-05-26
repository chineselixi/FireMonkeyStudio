#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include "CodeEditor/CodeEditor.h"
//#include "module/mod_TipList.h"


//CodeEditor* Editor;
//mod_TipList* tips;


void tipEvent(QString str){
    qDebug() << "string:" << str;
}




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    Editor = new CodeEditor(this);
//    Editor->setGeometry(0,0,this->geometry().width() - 200,this->geometry().height());

//    mod_HeighLightEditor * HeighKightMod = Editor->GetModel_HeighLight();
//    HeighKightMod->addKeyWordMsg({"int","char","double","flat","string","void","if","else","break","for","while","do","continue","return","namespace","using","include","function"},0);
//    HeighKightMod->addKeyWordMsg({"main","NULL"},1);

//    QTextCharFormat t_format;
//    t_format.setForeground(QColor(0, 0, 255));
//    HeighKightMod->SetKeyWordFormat(mod_HeighLightEditor::KeyWord1,t_format);
//    t_format.setForeground(QColor(255, 0, 0));
//    HeighKightMod->SetKeyWordFormat(mod_HeighLightEditor::KeyWord2,t_format);
//    t_format.setForeground(QColor(0, 161, 0));
//    HeighKightMod->SetKeyWordFormat(mod_HeighLightEditor::String,t_format);
//    t_format.setForeground(QColor(26, 26, 255));
//    HeighKightMod->SetKeyWordFormat(mod_HeighLightEditor::Sign,t_format);
//    t_format.setForeground(QColor(12, 134, 12));
//    HeighKightMod->SetKeyWordFormat(mod_HeighLightEditor::Note,t_format);

//    Editor->setFont(QFont("Monaco",16));
//    Editor->SetLineFont(QFont("Monaco",16));



//    //tips = new mod_TipList(this,QSize(16,16));


//    //tips->AddListMsg(tips->KeyWordList,{"char","int","string","char","inteee","in","bbbi","aina"});
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{
//    QString left,right,line;

//    Editor->GetCursorString(left,right,line);


//    qDebug() << left << right << line;

//    tips->ShowTips("int",Editor->GetCursorPersion());
}

