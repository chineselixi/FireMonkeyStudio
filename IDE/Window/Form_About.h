#ifndef FORM_ABOUT_H
#define FORM_ABOUT_H

#include <QWidget>

namespace Ui {
class Form_About;
}

class Form_About : public QWidget
{
    Q_OBJECT

public:
    explicit Form_About(QWidget *parent = nullptr);
    ~Form_About();

private:
    Ui::Form_About *ui;
};

#endif // FORM_ABOUT_H
