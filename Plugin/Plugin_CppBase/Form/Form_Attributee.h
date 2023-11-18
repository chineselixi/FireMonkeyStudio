#ifndef FORM_ATTRIBUTEE_H
#define FORM_ATTRIBUTEE_H

#include <QWidget>
#include "../Plugin_CppBase_global.h"


namespace Ui {
class Form_Attribute;
}

class Form_Attribute : public QWidget
{
    Q_OBJECT

    typedef cppAttributeNamespace::projectAttribute Attribute;


public:
    explicit Form_Attribute(QWidget *parent = nullptr, QString attrPath = "", QString proName = "app");
    ~Form_Attribute();


private:
    void updateUi(Attribute attr);//更新UI
    Attribute getAttrFromUi(); //从UI获取属性


private slots:
    void on_btn_outPath_clicked(); //选择输出路径
    void on_btn_tempPath_clicked(); //选择临时路径路径
    void on_btn_importIco_clicked(); //导入Ico
    void on_btn_recIco_clicked(); //还原清空Ico

public:
    static QString buildJson(Attribute attr); //获取把属性信息保存为Json数据
    static Attribute loadAttribute(QString jsonStr); //把json文本载入为设置信息

private:
    Ui::Form_Attribute *ui;
    QString attributeFilePath = "";
    QString normalName = "app";
    QString icoPath = ""; //图片路径
};

#endif // FORM_ATTRIBUTEE_H
