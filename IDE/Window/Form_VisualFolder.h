#ifndef FORM_VISUALFOLDER_H
#define FORM_VISUALFOLDER_H

#include <QWidget>
#include "functional"

namespace Ui {
class Form_VisualFolder;
}

class Form_VisualFolder : public QWidget
{
    Q_OBJECT
private:
    //void (*Fun)(QString folderName,QString signText,int typeSign) = nullptr;

    std::function<void (QString,QString,int)> Fun = nullptr;//函数指针,type的0为后缀标记  1为前缀标记  2为存在标记

public:
    explicit Form_VisualFolder(QWidget *parent = nullptr);
    ~Form_VisualFolder();
    void setFun(std::function<void (QString,QString,int)> fun); //弹出窗口

private slots:
    void on_pushButton_close_clicked();
    void on_pushButton_OK_clicked();

    void on_lineEdit_folderSign_textChanged(const QString &arg1);

    void on_comboBox_modSelect_currentIndexChanged(int index);

private:
    Ui::Form_VisualFolder *ui;
};

#endif // FORM_VISUALFOLDER_H
