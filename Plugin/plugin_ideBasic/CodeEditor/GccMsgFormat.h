#ifndef GCCMSGFORMAT_H
#define GCCMSGFORMAT_H

#include "QString"


class GccMsgFormat
{
public:
    GccMsgFormat();

    enum tipType{
        normal, //默认无提示
        error, //错误提示
        warning, //警告提示
        sign,    //下划线标记指点
    };

    struct compileMsg{
        QString fileName = ""; //返回文件名
        int row = -1; //行
        int column = -1; //列
        int length = 0;  //下划线标记长度
        QString tips = ""; //提示信息
        tipType type = normal;
    };

public:
    static QVector<compileMsg> getMsgFormat(QString compileStrMsg); //获取GCC返回值信息



};

#endif // GCCMSGFORMAT_H
