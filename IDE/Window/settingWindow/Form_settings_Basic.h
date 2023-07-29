#ifndef FORM_SETTINGS_BASIC_H
#define FORM_SETTINGS_BASIC_H

#include <QWidget>
#include "module/mod_settingsFormBase.h"

namespace Ui {
class Form_settings_Basic;
}

class Form_settings_Basic : public QWidget,public mod_settingsFormBase
{
    Q_OBJECT

public:
    explicit Form_settings_Basic(QWidget *parent = nullptr);
    ~Form_settings_Basic();

private:
    Ui::Form_settings_Basic *ui;
};

#endif // FORM_SETTINGS_BASIC_H
