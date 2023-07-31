#ifndef FORM_SETTINGS_QT_H
#define FORM_SETTINGS_QT_H

#include <QWidget>
#include "module/mod_settingsFormBase.h"

namespace Ui {
class Form_settings_Qt;
}

class Form_settings_Qt : public QWidget,public mod_settingsFormBase
{
    Q_OBJECT

public:
    explicit Form_settings_Qt(QWidget *parent = nullptr);
    ~Form_settings_Qt();

private:
    Ui::Form_settings_Qt *ui;
};

#endif // FORM_SETTINGS_QT_H
