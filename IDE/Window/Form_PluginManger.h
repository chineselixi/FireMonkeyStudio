#ifndef FORM_PLUGINMANGER_H
#define FORM_PLUGINMANGER_H

#include <QWidget>

namespace Ui {
class Form_PluginManger;
}

class Form_PluginManger : public QWidget
{
    Q_OBJECT

public:
    explicit Form_PluginManger(QWidget *parent = nullptr);
    ~Form_PluginManger();




private:
    Ui::Form_PluginManger *ui;
};

#endif // FORM_PLUGINMANGER_H
