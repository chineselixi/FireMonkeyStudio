#ifndef FORM_INDEX_H
#define FORM_INDEX_H

#include <QWidget>


namespace Ui {
class Form_Index;
}

class Form_Index : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Index(QWidget *parent = nullptr);
    ~Form_Index();


private:
    Ui::Form_Index *ui;
    QTimer* timer;
};

#endif // FORM_INDEX_H
