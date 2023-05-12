#ifndef MOD_HEIGHLIGHTEDITOR_H
#define MOD_HEIGHLIGHTEDITOR_H

#include "QVector"
#include "QTextFormat" //文本样式
#include <QSyntaxHighlighter> //语法高亮类引入



class mod_HeighLightEditor:protected QSyntaxHighlighter
{
public:
    struct TextNode{
        enum Type{
            TypeCode, //基础代码类型
            TypeString, //字符/字符串代码类型
            TypeSign,   //符号类型
            TypeNote  //备注代码类型
        };
        QString Text;
        Type type = TypeCode;
    };

    //关键字符类型
    enum KeyWordType{
        KeyWord1,
        KeyWord2,
        Sign,
        String,
        Note
    };



private:
    QVector<QString> ListKeyWord1; //关键字列表1
    QTextCharFormat TextCharFormat_KeyWord1; //关键字1样式

    QVector<QString> ListKeyWord2; //关键字列表2
    QTextCharFormat TextCharFormat_KeyWord2; //关键字2样式


    QVector<QString> List_Sign = {"!" , "\"", "#" , "$" , "%" , "&" , "'" , "(" , ")" ,
                                  "*" , "+" , "," , "-" , "." , "/" , ":" , ";" , "<" ,
                                  "=" , ">" , "?" , "@" , "[" , "\\", "]" , "^" , "_" ,
                                  " " , "`" , "{" , "|" , "}" , "~" };
    //QString List_Sign = QString("— !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~");    //符号列表组
    //— !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~
    //·！￥…（）—|：；“”‘’《，》。？

    QTextCharFormat TextCharFormat_Sign; //符号样式

    QString NoteSign = "//";     //备注符号
    QTextCharFormat TextCharFormat_Note; //备注样式

    QTextCharFormat TextCharFormat_String; //字符串样式

public:
    explicit mod_HeighLightEditor(QTextDocument * parent);
    ~mod_HeighLightEditor();

public:
    //关键字添加操作
    void addKeyWordMsg(QString keyMsg,int keyIndex = 0);  //添加单个关键字
    void addKeyWordMsg(QVector<QString> keyMsgLsit,int keyIndex = 0); //添加多个关键字
    QVector<QString> getKeyWordMsgs(int keyIndex = 0); //获取关键字列表
    void dropAllKeyWordMsg(int keyIndex = 0); //删除已经存在的关键字信息

    //设置文本样式
    void SetKeyWordFormat(KeyWordType type,QTextCharFormat format);//根据关键字类型设置文本样式

    //语句分析
    QVector<TextNode> getHeighLightCodeList(QString codeStr); //根据字符串分解出高亮文本列表
    QVector<TextNode> getCharStringList(QString codeStr,QString charSign = "\"",TextNode::Type signType = TextNode::Type::TypeString); //获取一个字符串和字符的列表，字符串与字符将被独特标记，其他的类型将保持默认


protected:
    virtual void highlightBlock(const QString &text); //重写代码高亮



};

#endif // MOD_HEIGHLIGHTEDITOR_H
