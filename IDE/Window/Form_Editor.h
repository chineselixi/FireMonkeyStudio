#ifndef FORM_EDITOR_H
#define FORM_EDITOR_H

#include <QWidget>

namespace Ui {
class Form_Editor;
}

class Form_Editor : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Editor(QWidget *parent = nullptr);
    ~Form_Editor();

private:
    Ui::Form_Editor *ui;
};

#endif // FORM_EDITOR_H
