#ifndef FORM_SYSTEMSETTINGS_H
#define FORM_SYSTEMSETTINGS_H

#include <QWidget>

namespace Ui {
class Form_SystemSettings;
}

class Form_SystemSettings : public QWidget
{
    Q_OBJECT

public:
    explicit Form_SystemSettings(QWidget *parent = nullptr);
    ~Form_SystemSettings();

private:
    Ui::Form_SystemSettings *ui;
};

#endif // FORM_SYSTEMSETTINGS_H
