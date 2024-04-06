#include "Forms/Form_EditorSpace.h"
#include "Forms/Form_WidgetBox.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Form_EditorSpace fe;
    fe.show();

    (new Form_WidgetBox())->show();

    //fr.roi_addRec({{"测试",{10,10,100,50}},{"测试2",{130,45,100,50}},{"测试3",{10,110,100,50}}});


    return a.exec();
}
