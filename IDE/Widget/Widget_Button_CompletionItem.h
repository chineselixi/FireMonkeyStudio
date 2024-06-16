#ifndef WIDGET_BUTTON_COMPLETIONITEM_H
#define WIDGET_BUTTON_COMPLETIONITEM_H

#include <QWidget>

namespace Ui {
class Widget_Button_CompletionItem;
}

class Widget_Button_CompletionItem : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Button_CompletionItem(QString title = "",
                                          QPixmap pixmap = QPixmap(),
                                          QWidget *parent = nullptr);
    ~Widget_Button_CompletionItem();

private:
    Ui::Widget_Button_CompletionItem *ui;


public:
    void setTipTitle(QString title);           //设置提示标题
    void setTipPixmap(QPixmap pixmap);         //设置提示图片
};

#endif // WIDGET_BUTTON_COMPLETIONITEM_H
