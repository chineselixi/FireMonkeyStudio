//#include "mainwindow.h"

#include <QApplication>
#include "Form_Terminal.h"
#include "Widget_TextEdit.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form_Terminal w;
    w.show();
    return a.exec();
}
