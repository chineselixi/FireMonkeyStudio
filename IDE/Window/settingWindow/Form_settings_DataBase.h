#ifndef FORM_SETTINGS_DATABASE_H
#define FORM_SETTINGS_DATABASE_H

#include <QWidget>
#include "module/mod_settingsFormBase.h"

namespace Ui {
class Form_settings_DataBase;
}

class Form_settings_DataBase : public QWidget,public mod_settingsFormBase
{
    Q_OBJECT

public:
    explicit Form_settings_DataBase(QWidget *parent = nullptr);
    ~Form_settings_DataBase();

private:
    Ui::Form_settings_DataBase *ui;
};

#endif // FORM_SETTINGS_DATABASE_H
