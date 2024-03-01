#ifndef GCCUTIL_H
#define GCCUTIL_H


#include "QStringList"

class GccUtil
{
public:
    //提示类型
    enum class GccType{
        WARN,
        ERR,
        TIP
    };

    //提示信息节点
    struct GccCheckNode{
        GccType  type = GccType::TIP;
        QString  tipStr = "";
        QString  file = "";
        uint16_t line = 0;
        uint16_t index = 0;
        uint16_t startIndex = 0;
        uint16_t len = 1;
    };

public:
    GccUtil();


public:
    static QList<GccCheckNode> parsingGccError(QString gccErrorText);

};

#endif // GCCUTIL_H
