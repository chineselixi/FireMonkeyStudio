#include "Form_EditorSpace.h"
#include "ui_Form_EditorSpace.h"



Form_EditorSpace::Form_EditorSpace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_EditorSpace)
{
    ui->setupUi(this);
    mainWindow = new QMainWindow(this);
    //ui->editorScrollSpace->layout() ->setWidget(mainWindow); //将主窗体添加到滚动容器当中
    mainWindow->setAttribute(Qt::WA_StyledBackground); //脱离父窗口样式的覆盖
    mainWindow->setStyleSheet("background-color:rgb(240,240,240));");
    mainWindow->setGeometry(10,10,600,500);
    mainWindow->setWindowTitle(tr("主窗口"));
    mainWindow->show();

}

Form_EditorSpace::~Form_EditorSpace()
{
    delete ui;
}
