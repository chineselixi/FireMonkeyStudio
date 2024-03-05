#ifndef FORM_SEARCH_H
#define FORM_SEARCH_H

#include <QDialog>
#include "QList"
#include "../SwSystem/System_History.h"

namespace Ui {
class Form_Search;
}

class Form_Search : public QDialog
{
    Q_OBJECT

public:

    //搜索参数
    struct searchAttr{
        QString proName;    //工程名
        QString filePath;   //文件路径
    };

    //分析返回参数
    struct searchMsg{
        QString LineCode;                   //当前行代码
        QString filePath;                   //所属文件
        QString proName;                    //工程名
        qsizetype line = 0;                  //行号
        qsizetype lineIndex = 0;             //起始索引
        qsizetype len = 0;                   //长度
    };

private:
    static Form_Search* searchFormPtr;

    System_History his_search;
    System_History his_replace;

public:
    static Form_Search* create(QWidget *parent = nullptr); //创建搜索框

private slots:
    void on_rbInProject_toggled(bool checked); //禁用工程选择
    void on_btnQuery_clicked(); //搜索按钮被点击
    void on_btnClose_clicked(); //退出被点击
    void on_btnReplace_clicked(); //查找并替换

private:
    Form_Search(QWidget *parent = nullptr);
    ~Form_Search();

private:
    void init(); //初始化工程管理器
    QString getFileProName(QString filePath); //获取文件的工程名
    bool hasSuffix(QStringList suffixList, QString filePath); //检查是否拥有此后缀

    QList<searchMsg> query(QString queryStr, QList<searchAttr> files, bool isCaseSensetive, bool isWholeWord, bool isRegular); //根据文件查找
    QList<searchMsg> queryReg(QString filePath, QString proName, QString regStr); //根据正则表达式查找
    QList<searchMsg> queryIndex(QString filePath, QString proName, QString searchStr, bool isCaseSensetive, bool isWholeWord); //根据默认文本查找

private:
    Ui::Form_Search *ui;
};

#endif // FORM_SEARCH_H
