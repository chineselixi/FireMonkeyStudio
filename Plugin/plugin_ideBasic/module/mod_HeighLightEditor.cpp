#include "mod_HeighLightEditor.h"
#include "QDebug"

#include "QTextEdit"


mod_HeighLightEditor::mod_HeighLightEditor(QTextDocument *parent):QSyntaxHighlighter(parent)
{


    //暂无构造实现
}

mod_HeighLightEditor::~mod_HeighLightEditor()
{
    //暂无析构实现
}

//添加单个关键字
void mod_HeighLightEditor::addKeyWordMsg(QString keyMsg,int keyIndex){
    if(keyIndex == 0){
        ListKeyWord1.append(keyMsg);
    }
    else if(keyIndex == 1){
        ListKeyWord2.append(keyMsg);
    }
}

//添加多个关键字
void mod_HeighLightEditor::addKeyWordMsg(QVector<QString> keyMsgLsit,int keyIndex){
    if(keyIndex == 0){
        ListKeyWord1.append(keyMsgLsit);
    }
    else if(keyIndex == 1){
        ListKeyWord2.append(keyMsgLsit);
    }
}

//获取关键字列表
QVector<QString> mod_HeighLightEditor::getKeyWordMsgs(int keyIndex){
    if(keyIndex == 0){
        return ListKeyWord1;
    }
    else{
        return ListKeyWord2;
    }
}

//删除已经存在的关键字信息
void mod_HeighLightEditor::dropAllKeyWordMsg(int keyIndex){
    if(keyIndex == 0){
        ListKeyWord1.clear();
    }
    else if(keyIndex == 1){
        ListKeyWord2.clear();
    }
}

//根据关键字类型设置文本样式
void mod_HeighLightEditor::SetKeyWordFormat(KeyWordType type, QTextCharFormat format)
{
    switch (type){
    case KeyWordType::KeyWord1:{
        TextCharFormat_KeyWord1 = format;
        break;
    }
    case KeyWordType::KeyWord2:{
        TextCharFormat_KeyWord2 = format;
        break;
    }
    case KeyWordType::String:{
        TextCharFormat_String = format;
        break;
    }
    case KeyWordType::Sign:{
        TextCharFormat_Sign = format;
        break;
    }
    case KeyWordType::Note:{
        TextCharFormat_Note = format;
        break;
    }
    }
}

//根据字符串分解出高亮文本列表
QVector<mod_HeighLightEditor::TextNode> mod_HeighLightEditor::getHeighLightCodeList(QString codeStr){

    //全局变量信息
    int t_index = -1;
    QVector<TextNode> t_retList;
    TextNode t_code;


    //字符串分离
    QVector<mod_HeighLightEditor::TextNode> t_strNods = this->getCharStringList(codeStr,"\"",TextNode::TypeString);
    for(int a = 0;a<t_strNods.length();a++){
        if(t_strNods[a].type == TextNode::TypeCode){ //如果是未定义的，将重新进行归档扫描
            t_retList.append(this->getCharStringList(t_strNods[a].Text,"\'",TextNode::TypeString));
        }
        else{
            t_retList.append(t_strNods[a]);
        }
    }


    //备注处理
    QList<TextNode>::iterator i;
    for (i = t_retList.begin(); i < t_retList.end(); i++) {
        if (i->type == TextNode::TypeCode) {
            t_index = i->Text.indexOf(this->NoteSign); //获取到备注的位置
            if (t_index != -1) {
                t_code.type = t_code.TypeNote; //标记为备注
                t_code.Text = i->Text.mid(t_index, i->Text.length() - t_index); //获取当前的备注部分
                i->Text = i->Text.mid(0,t_index); //更改当前

                QList<TextNode>::iterator i2;
                i2 = i;
                for (i++; i < t_retList.end(); i++) { //自动检索下一个
                    t_code.Text += i->Text; //获取后面备注的所有字符串
                }
                t_retList.insert(++i2, t_code); //插入备注代码
                break;
            }
        }
    }

    //整理注释代码
    for (i = t_retList.begin(); i < t_retList.end(); i++) {
        if (i->type == TextNode::TypeNote) {
            t_retList.erase(++i, t_retList.end()); //清除备注的多余代码
            break;
        }
    }


    //符号判定
    QVector<TextNode> t_tCode; //临时存放的新列表
    for (i = t_retList.begin(); i < t_retList.end(); i++) {
        if (i->type == TextNode::TypeCode) {
            QString t_str = i->Text;
            int t_index = 0;
            for (int a = 0; a < t_str.length(); a++) {
                for (int b = 0; b < this->List_Sign.length(); b++) {
                    if(this->List_Sign[b] == t_str.mid(a,List_Sign[b].length())){
                        //获取符号前面的字符串，并且加入
                        t_code.Text = t_str.mid(t_index, a - t_index);
                        t_code.type = TextNode::TypeCode;
                        t_tCode.append(t_code);

                        //获取符号并且加入
                        t_code.Text = this->List_Sign[b];
                        t_code.type = TextNode::TypeSign; //符号类型
                        t_tCode.append(t_code);

                        t_index = a + List_Sign[b].length(); //更新索引
                        break;
                    }
                }
            }
            if (t_index < t_str.length()) { //判断尾部是否残留字符串，存在则加入进去
                t_code.Text = t_str.mid(t_index, t_str.length() - t_index);
                t_code.type = TextNode::TypeCode;
                t_tCode.append(t_code);
            }
        }
        else {
            t_tCode.append(*i); //已经判断类型的直接分配进入
        }
    }


    QVector<TextNode> t_retCode;
    //删除多余的空白条目
    for (i = t_tCode.begin(); i < t_tCode.end(); i++) {
        if (!i->Text.isEmpty()) {
            t_retCode.append(*i);
        }
    }

    return t_retCode;
}

//获取一个字符串和字符的列表，字符串与字符将被独特标记，其他的类型将保持默认
QVector<mod_HeighLightEditor::TextNode> mod_HeighLightEditor::getCharStringList(QString codeStr,QString charSign,TextNode::Type signType)
{
    QVector<int> t_indexList;
    int t_index = -charSign.length();
    int t_lastIndex = 0;
    while (true) { //把字符串符号标记出来
        t_index = codeStr.indexOf(charSign, t_index + charSign.length());   //检索转义字符
        if (t_index == -1) { //如果不存在或者是转义字符的话则不符合
            break;
        }
        else {
            if(t_index == 0){
                t_indexList.append(t_index);
                t_lastIndex = t_index;//保存当前的索引，供下一次使用
            }
            else{
                for(int a = t_index - 1;a >= t_lastIndex;a--){ //检索多个和转义字符
                    if(codeStr.mid(a,1) != "\\"){
                        //qDebug() <<t_index - 1 - a << "   "<<codeStr.mid(a,1);
                        if((t_index - 1 - a) % 2 == 0){
                            t_indexList.append(t_index);
                            t_lastIndex = t_index;//保存当前的索引，供下一次使用
                        }
                        break;
                    }

                }
            }

        }
    }

    //字符串分离
    QVector<TextNode> t_retList;
    TextNode t_code;
    t_lastIndex = 0;
    if (t_indexList.length() <= 1) { //判断是否能查到最基本的字符串文本体
        t_code.Text = codeStr;
        t_code.type = t_code.TypeCode;
        t_retList.append(t_code);
        //这里不构成字符串的条件，直接返回
    }
    else {
        for (int a = 1; a < t_indexList.length(); a += 2) {
            //检索前面未标记字符信息
            t_code.Text = codeStr.mid(t_lastIndex, t_indexList[a - 1] - t_lastIndex);
            t_code.type = t_code.TypeCode;
            if (t_code.Text.isEmpty() == false) {
                t_retList.append(t_code);
            }

            //分离字符串,并且加入字符串信息
            t_code.Text = codeStr.mid(t_indexList[a - 1], t_indexList[a] - t_indexList[a - 1] + 1);
            t_code.type = signType;                                     //指定特殊类型标记
            if (t_code.Text.isEmpty() == false) {
                t_retList.append(t_code);
            }

            t_lastIndex = t_indexList[a]; //改变上一个的位置
        }
        if (t_lastIndex < codeStr.length() - 1) { //加入剩余的文本
            t_code.Text = codeStr.mid(t_lastIndex + 1, codeStr.length() - t_lastIndex -  1);
            t_code.type = t_code.TypeCode;
            t_retList.append(t_code);
        }
    }

    return t_retList; //不构成字符串信息，直接返回
}

//高亮代码
void mod_HeighLightEditor::highlightBlock(const QString &text){
    QVector<mod_HeighLightEditor::TextNode> textNodes = this->getHeighLightCodeList(text);
    int t_StartIndex = 0;//定位长度

    for(int a = 0;a < textNodes.length();a++){

        if(textNodes[a].type == TextNode::Type::TypeSign){
            this->setFormat(t_StartIndex,textNodes[a].Text.length(),TextCharFormat_Sign);
            //qDebug() << "符号";
            goto BREAK;
        }

        if(textNodes[a].type == TextNode::Type::TypeString){
            this->setFormat(t_StartIndex,textNodes[a].Text.length(),TextCharFormat_String);
            //qDebug() << "字符串";
            goto BREAK;
        }

        if(textNodes[a].type == TextNode::Type::TypeNote){
            this->setFormat(t_StartIndex,textNodes[a].Text.length(),TextCharFormat_Note);
            //qDebug() << "备注";
            goto BREAK;
        }

        //检索关键字1
        for(int b=0;b<ListKeyWord1.length();b++){
            if(textNodes[a].Text == ListKeyWord1[b]){
                this->setFormat(t_StartIndex,textNodes[a].Text.length(),TextCharFormat_KeyWord1);
                //qDebug() << "关键字1";
                goto BREAK;
            }
        }

        //检索关键字2
        for(int b=0;b<ListKeyWord2.length();b++){
            if(textNodes[a].Text == ListKeyWord2[b]){
                this->setFormat(t_StartIndex,textNodes[a].Text.length(),TextCharFormat_KeyWord2);
                //qDebug() << "关键字2";
                goto BREAK;
            }
        }

        BREAK:
        t_StartIndex += textNodes[a].Text.length();
    }
}
