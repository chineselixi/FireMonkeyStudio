#ifndef FORM_ATTRIBUTEE_H
#define FORM_ATTRIBUTEE_H

#include <QWidget>

namespace Ui {
class Form_Attribute;
}

class Form_Attribute : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Attribute(QWidget *parent = nullptr);
    ~Form_Attribute();

private:
    Ui::Form_Attribute *ui;
};

#endif // FORM_ATTRIBUTEE_H
