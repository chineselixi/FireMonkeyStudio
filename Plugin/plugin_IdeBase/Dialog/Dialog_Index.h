#ifndef DIALOG_INDEX_H
#define DIALOG_INDEX_H

#include <QWidget>

namespace Ui {
class Dialog_Index;
}

class Dialog_Index : public QWidget
{
    Q_OBJECT

public:
    explicit Dialog_Index(QWidget *parent = nullptr);
    ~Dialog_Index();

private:
    Ui::Dialog_Index *ui;
};

#endif // DIALOG_INDEX_H
