#ifndef MOD_TIPLIST_H
#define MOD_TIPLIST_H
#include "QListWidget"
#include "functional"

class mod_TipList : public QListWidget
{
    Q_OBJECT

public:
    enum listType{
        KeyWordList, //关键字列表
        HeadList, //头文件列表
        ConstList, //常量列表
        VarList, //变量列表
        FunList, //函数列表
        ClassList, //类列表
        StructList, //结构体到列表
        DefList, //宏列表
        OtherList, //其他到列表
        SystemSave //系统动态保留
    };


    struct strLikeMsg{
        QString str;
        int likeNum = 0;
        listType type;
    };

private:
    QVector<QString> List_KeyWordList; //关键字列表
    QVector<QString> List_HeadList; //头文件列表
    QVector<QString> List_ConstList; //常量列表
    QVector<QString> List_VarList; //变量列表
    QVector<QString> List_FunList; //函数列表
    QVector<QString> List_ClassList; //类列表
    QVector<QString> List_StructList; //结构体到列表
    QVector<QString> List_DefList; //宏列表
    QVector<QString> List_OtherList; //其他到列表
    QVector<QString> List_SystemSaveList; //其他到列表




private:
    //std::function<void(QString tipStr)> tipEvent; //保存这个函数指针


public:
    explicit mod_TipList(QWidget* parent,QSize iconSize);//构造函数

public:
    void ShowTips(QString src,QRect positionRec,bool thinkNow = false,QString otherSrc = "");//根据文字进行分析显示,可以更具提供的文字，继续分析
    void Select(); //选择当前的选项

    void AddListMsg(listType type,QVector<QString> strList); //添加信息到列表
    void DeleteListMsg(listType type,QString strList); //删除列表中的其中一个
    void DropAllListMsg(listType type); //清空列表
    void keyPressEvent(QKeyEvent *event);       //按钮按下信息


private slots:
    QVector<QString>* getList(listType type);   //根据类型获取对应的数据列表
    void onItemClicked(QListWidgetItem *item);
    int findStringLike(QString src,QString parentStr);  //查找子字符串与父字符串的相似程度
    QVector<strLikeMsg> getStringLikeList(QString src,QVector<QString> parentList,listType type);  //整理文本列表的指定字符串相似程度



signals:
    void onTipOut(QString tipText); //当文本输出


};

#endif // MOD_TIPLIST_H
