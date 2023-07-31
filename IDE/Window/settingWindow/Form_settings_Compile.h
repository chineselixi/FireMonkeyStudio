#ifndef FORM_SETTINGS_COMPILE_H
#define FORM_SETTINGS_COMPILE_H

#include <QWidget>
#include "module/mod_settingsFormBase.h"

namespace Ui {
class Form_settings_Compile;
}

class Form_settings_Compile : public QWidget,public mod_settingsFormBase
{
    Q_OBJECT

public:
    explicit Form_settings_Compile(QWidget *parent = nullptr);
    ~Form_settings_Compile();

private:
    Ui::Form_settings_Compile *ui;
};

#endif // FORM_SETTINGS_COMPILE_H
