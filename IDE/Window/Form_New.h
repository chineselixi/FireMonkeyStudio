#ifndef FORM_NEW_H
#define FORM_NEW_H

#include <QWidget>
#include "QListWidgetItem"


namespace Ui {
class Form_New;
}

class Form_New : public QWidget
{
    Q_OBJECT

public:
    struct modListMsg{
        QString fmpPath = ""; //配置文件
        QString modNmae = "NULL"; //模板名称
        QString modTip = "NULL"; //提示信息
        QString modSystem = ""; //支持的系统
        QString modLang = ""; //支持的语言
        QString modNoteClass = ""; //其他支持信息
    };


public:
    explicit Form_New(QWidget *parent = nullptr);
    ~Form_New();

private slots:
    void on_pushButton_back_toStart_clicked();

    void on_pushButton_back_toModList_clicked();

    void on_pushButton_back_toMain2_clicked();

    void on_pushButton_git_path_clicked();

    void on_comboBox_lang_activated(int index); //根据语言分类

    void on_comboBox_os_activated(int index);

    void on_comboBox_other_activated(int index);

    void on_comboBox_findMod_editTextChanged(const QString &arg1);

    void on_pushButton_next_toCreate_clicked(); //当前界面已经切换事件

    void on_pushButton_path_3_clicked(); //选择文件夹路径

    void on_pushButton_createProject_clicked(); //创建工程

    void on_stackedWidget_currentChanged(int arg1);

    void on_lineEdit_projectName_textEdited(const QString &arg1); //项目名被改变

private:
    Ui::Form_New *ui;
    QVector<modListMsg> modMsgList;//工程模板列表
    QString modFilePath = ""; //fmp配置文件路径
    QString modName = "NULL"; //模板名称
    QString modLang = "other"; //模板使用的编程语言

    QString classify_keyWord = ""; //分类配置_关键字
    QString classify_lang = "";    //分类配置_语言
    QString classify_os = "";      //分类配置_系统
    QString classify_other = "";   //分类配置_其他

private:
    bool eventFilter(QObject *obj, QEvent *event); //事件过滤器
    void findMod(QString path,QVector<QString>& retList); //查找模块信息
    void removeRepeat(QVector<QString>& strList); //去除列表的重复
    void showItemForClass(QString lang,QString os,QString other,QString keyWord); //筛选item信息
    static void copyFolder(QString sourceFolder, QString destinationFolder); //复制文件夹


protected slots:
    void OnBtnOpenDuwn();//打开文件被按下
    void OnBtnOpenDirDuwn();//打开文件夹被按下
    void OnBtnCreateDuwn();//创建项目被按下
    void OnBtnGitDown();//Git按下
};

#endif // FORM_NEW_H
