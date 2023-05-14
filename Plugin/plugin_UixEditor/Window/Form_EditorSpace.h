#ifndef FORM_EDITORSPACE_H
#define FORM_EDITORSPACE_H

#include <QWidget>
#include "QMainWindow"

namespace Ui {
class Form_EditorSpace;
}

class Form_EditorSpace : public QWidget
{
    Q_OBJECT

public:
    explicit Form_EditorSpace(QWidget *parent = nullptr);
    ~Form_EditorSpace();

public:
    QMainWindow* mainWindow; //编辑器的主窗口



private:
    Ui::Form_EditorSpace *ui;
};

#endif // FORM_EDITORSPACE_H
