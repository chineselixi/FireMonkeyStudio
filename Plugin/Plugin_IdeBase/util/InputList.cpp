#include "InputList.h"
#include "QDebug"


InputList::InputList()
{
    queue.reserve(LISTNUM); //设定初始容量大小
}


//添加历史
int InputList::add(QString str)
{
    str = str.trimmed();
    if(!str.isEmpty()) {
        if(queue.length() >= LISTNUM){
            queue.dequeue();
        }
        queue.enqueue(str);
        readIndex = queue.length();
    }
    readIndex = queue.length();
    return queue.length() - 1;
}



//获取上一个
QString InputList::getLast()
{
    if(readIndex < 0){return "";}
    readIndex--;
    if(readIndex < 0 || readIndex > queue.length() - 1){return "";}
    return queue.at(readIndex);
}


//获取下一个
QString InputList::getNext()
{
    if(readIndex > queue.length()-1){return "";}
    readIndex++;
    if(readIndex > queue.length()-1){return "";}
    return queue.at(readIndex);
}



