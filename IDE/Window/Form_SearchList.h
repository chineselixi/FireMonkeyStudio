#ifndef Form_SearchList_H
#define Form_SearchList_H

//#include <QWidget>
#include "QTreeWidgetItem"
#include "QList"
#include "Plugin/Plugin_Global.h"


namespace Ui {
class Form_SearchList;
}

class Form_SearchList : public QWidget
{
    Q_OBJECT


public:
    struct itemNode{
        QTreeWidgetItem* item = nullptr;    //树节点
        QString tipText;                    //提示文本
        QString filePath;                   //文件路径
        QString project;                    //工程路径
        uint16_t line = 0;                  //行号
        uint16_t lineIndex = 0;             //起始索引
        uint16_t len = 0;                   //长度
    };

    QList<itemNode> nodeList;


public:
    explicit Form_SearchList(QWidget *parent = nullptr);
    ~Form_SearchList();

private:
    Ui::Form_SearchList *ui;

public:
    //添加提示内容
    void addMsg(QString codeText, QString file, QString project,uint16_t line,uint16_t lineIndex,uint16_t len);

    //删除所有内容
    void clearMsg();

signals:
    void onFileOpen(QString file,uint16_t line = 0,uint16_t lineIndex = 0,uint16_t len = 0); //文件被打开消息


protected:
    void resizeEvent(QResizeEvent *event) override; //重写尺寸改变
private slots:
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
};

#endif // Form_SearchList_H
