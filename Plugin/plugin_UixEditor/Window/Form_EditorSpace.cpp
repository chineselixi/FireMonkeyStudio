#include "Form_EditorSpace.h"
#include "ui_Form_EditorSpace.h"
#include "QMdiSubWindow"


Form_EditorSpace::Form_EditorSpace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_EditorSpace)
{
    ui->setupUi(this);

//    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
//    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    this->setAttribute(Qt::WA_StyledBackground); //脱离父窗口样式的覆盖
    //ui->editorScrollSpace->layout() ->setWidget(mainWindow); //将主窗体添加到滚动容器当中
    mainWindow = new QMainWindow;
    mainWindow->setAttribute(Qt::WA_StyledBackground); //脱离父窗口样式的覆盖
    mainWindow->setStyleSheet("background-color:rgb(240,240,240));");
    mainWindow->setGeometry(10,10,380,250);
    mainWindow->setWindowTitle(tr("主窗口"));


    QMdiSubWindow* t_subWindow = ui->mdiArea->addSubWindow(mainWindow);


    t_subWindow->setAttribute(Qt::WA_StyledBackground); //脱离父窗口样式的覆盖
    t_subWindow->setGeometry(10,10,600,500);


}

Form_EditorSpace::~Form_EditorSpace()
{
    delete ui;
}
