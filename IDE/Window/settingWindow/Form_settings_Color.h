#ifndef FORM_SETTINGS_COLOR_H
#define FORM_SETTINGS_COLOR_H

#include <QWidget>
#include "module/mod_settingsFormBase.h"

namespace Ui {
class Form_settings_Color;
}

class Form_settings_Color : public QWidget,public mod_settingsFormBase
{
    Q_OBJECT

public:
    explicit Form_settings_Color(QWidget *parent = nullptr);
    ~Form_settings_Color();

private:
    Ui::Form_settings_Color *ui;
};

#endif // FORM_SETTINGS_COLOR_H
