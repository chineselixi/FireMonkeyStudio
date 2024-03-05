#ifndef INPUTLIST_H
#define INPUTLIST_H

#include "QQueue"


#define LISTNUM 30

class InputList
{
private:
    int readIndex = -1;          //历史读取索引

    QQueue<QString> queue;

public:
    InputList();
    int add(QString str); //添加历史
    QString getNext(); //获取下一个
    QString getLast(); //获取上一个
};

#endif // INPUTLIST_H
