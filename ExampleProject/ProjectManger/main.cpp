#include "Window/Form_ProjectManger.h"
#include "QFileInfo"
#include "QString"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    QFileInfo t_fi("C:/Users/31914/Desktop/test/test2.exe");

//    qDebug() << t_fi.path();
//    qDebug() << t_fi.absolutePath();
//    qDebug() << t_fi.filePath();
//    qDebug() << t_fi.absoluteFilePath();




    //return 0;

//    QFileInfo info("C:/Users/31914/Desktop/test");
//    qDebug() << info.fileName();
//    qDebug() << info.filePath();
//    qDebug() << info.path();
//    qDebug() << info.absolutePath();
//    qDebug() << info.absoluteFilePath();

//    qDebug() << "=================";

//    QFileInfo info2("C:/Users/31914/Desktop/test/test1.exe");
//    qDebug() << info2.fileName();
//    qDebug() << info2.filePath();
//    qDebug() << info2.path();
//    qDebug() << info2.absolutePath();
//    qDebug() << info2.absoluteFilePath();




    Form_ProjectManger w;
    w.show();
    //C:/Users/31914/Desktop/CVLine-main  C:/Users/31914/Desktop/test C:/Users/31914/Desktop/testProject
    //w.addProject("C:/Users/31914/Desktop/testProject");
    //w.saveProjectMsg("C:/Users/31914/Desktop/testProject",w.getNowProjectMsg());

    w.addBuildFileSign("cpp","C++源文件",QIcon(":/FileType/icon/Theme/Blue/Image/ResManagerView/FileType/CPP_16x.png"),"源文件","这是新创建的CPP内容");

    //w.addProject("C:/Users/31914/Desktop/testProject");
    qDebug() << w.addProject("C:/Users/31914/Desktop/testProject/pro.fmp");
    qDebug() << w.addProject("C:/Users/31914/Desktop/testProject");
//    w.addProject("C:/Users/31914/Desktop/3PC__Turn.fbx");
    return a.exec();
}
