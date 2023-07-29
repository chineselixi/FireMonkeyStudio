#ifndef FORM_SETTINGS_DEVICE_H
#define FORM_SETTINGS_DEVICE_H

#include <QWidget>
#include "module/mod_settingsFormBase.h"

namespace Ui {
class Form_settings_Device;
}

class Form_settings_Device : public QWidget,public mod_settingsFormBase
{
    Q_OBJECT

public:
    explicit Form_settings_Device(QWidget *parent = nullptr);
    ~Form_settings_Device();

private:
    Ui::Form_settings_Device *ui;
};

#endif // FORM_SETTINGS_DEVICE_H
