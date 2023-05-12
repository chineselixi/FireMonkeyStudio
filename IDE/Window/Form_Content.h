#ifndef FORM_CONTENT_H
#define FORM_CONTENT_H

#include <QMainWindow>

namespace Ui {
class Form_Content;
}

class Form_Content : public QMainWindow
{
    Q_OBJECT

public:
    explicit Form_Content(QWidget *parent = nullptr);
    ~Form_Content();

private:
    Ui::Form_Content *ui;
};

#endif // FORM_CONTENT_H
