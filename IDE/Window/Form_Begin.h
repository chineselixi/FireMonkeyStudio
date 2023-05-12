#ifndef FORM_BEGIN_H
#define FORM_BEGIN_H

#include <QWidget>

namespace Ui {
class Form_Begin;
}

class Form_Begin : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Begin(QWidget *parent = nullptr);
    ~Form_Begin();

private:
    Ui::Form_Begin *ui;
};

#endif // FORM_BEGIN_H
