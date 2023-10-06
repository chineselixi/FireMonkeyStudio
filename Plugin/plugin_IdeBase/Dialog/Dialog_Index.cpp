#include "Dialog_Index.h"
#include "ui_Dialog_Index.h"

Dialog_Index::Dialog_Index(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dialog_Index)
{
    ui->setupUi(this);
}

Dialog_Index::~Dialog_Index()
{
    delete ui;
}
