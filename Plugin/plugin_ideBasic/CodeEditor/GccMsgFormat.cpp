#include "GccMsgFormat.h"
#include "QStringList"
#include "QVector"
#include "qDebug"

GccMsgFormat::GccMsgFormat()
{

}



//获取GCC返回值信息
QVector<GccMsgFormat::compileMsg> GccMsgFormat::getMsgFormat(QString compileStrMsg)
{
    QVector<GccMsgFormat::compileMsg> t_compleMsgList; //编译信息列表
    QStringList t_lineStrList = compileStrMsg.split("\n"); //将编译信息行信息进行拆分
    for(int a=0;a<t_lineStrList.length();a++){
        //检索一行的信息
        GccMsgFormat::compileMsg t_compileMsg; //零食保存的编译信息
        QString t_line = t_lineStrList[a]; //一行信息
        if(t_line.isEmpty()) continue; //空白信息直接跳出
        QStringList t_lineItem = t_line.split(": "); //将某一行按照“： ”拆分
        if(t_lineItem.length() == 1){ //单个信息组
            t_compileMsg.tips = t_lineItem[0];
        }
        else if(t_lineItem.length() == 2){ //一般提示信息
            t_compileMsg.fileName = t_lineItem[0];
            t_compileMsg.tips = t_lineItem[1];
        }
        else if(t_lineItem.length() >= 3){ //拥有警告的信息
            t_compileMsg.fileName = t_lineItem[0];
            t_compileMsg.tips = t_lineItem[2];

            QString t_type = "error"; //检索并且更改数据类型
            if(t_lineItem[1].right(t_type.length()) == t_type){t_compileMsg.type = tipType::error;}
            t_type = "warning";
            if(t_lineItem[1].right(t_type.length()) == t_type){t_compileMsg.type = tipType::warning;}
            t_compileMsg.tips = t_type + ":" + t_compileMsg.tips;

            //如果数据长度大于3个，则后面的信息全部加入到tip
            for(int i = 3;i < t_lineItem.length();i++){t_compileMsg.tips += t_lineItem[i];} //将后面的信息作为提示信息加入
        }


        //检索行列信息
        QStringList t_fileNameItem = t_compileMsg.fileName.split(":"); //拆分行列信息
        if(t_fileNameItem.length() >= 2){
            t_compileMsg.row = t_fileNameItem[t_fileNameItem.length() - 2].toInt(); //检索行信息
            t_compileMsg.column = t_fileNameItem[t_fileNameItem.length() - 1].toInt(); //检索列信息

            t_compileMsg.fileName = "";
            for(int i=t_fileNameItem.length() - 3;i >= 0;i--){
                t_compileMsg.fileName = t_fileNameItem[i] + t_compileMsg.fileName; //检索文件信息
            }
        }
        t_compleMsgList.append(t_compileMsg); //将信息加入到列表

        //检索下一行是否为标记信息
        if(a + 1 < t_lineStrList.length()){ //下一行存在
            QString t_nextStr = t_lineStrList[a + 1]; //取出下一行文本
            int t_index = t_nextStr.indexOf(" | ");
            if(t_index != -1){
                int t_linNum = t_nextStr.left(t_index).toInt(); //获取当前行号信息
                if(t_compileMsg.row == t_linNum){ //行号相同
                    t_compileMsg.tips = t_nextStr.right(t_nextStr.length() - t_index - 3); //获取Tips信息
                    if(a + 2 < t_lineStrList.length()){ //获取下一行的下一行，波浪线信息
                        t_nextStr = t_lineStrList[a + 2]; //下下一行的文本信息
                        t_index = t_nextStr.indexOf(" | ");
                        if(t_index != -1){
                            int t_indexStart = t_nextStr.indexOf("^");
                            int t_indexEnd = t_nextStr.indexOf("~");
                            //获取开始长度
                            if(t_indexStart != -1){
                                t_compileMsg.type = tipType::sign;
                                t_compileMsg.length = 1;
                                if(t_indexEnd - t_indexStart > 0){  //更正数据长度
                                    t_compileMsg.length = t_indexEnd - t_indexStart + 1;
                                }
                                t_compleMsgList.append(t_compileMsg); //添加标记信息到列表
                                a += 2; //添加两行信息
                            }
                        }
                    }
                }
            }
        }
    }
    return t_compleMsgList;
}

/*
//获取GCC返回值信息
QVector<GccMsgFormat::retMsg> GccMsgFormat::getMsgFormat(QString str)
{
    QVector<GccMsgFormat::retMsg> t_msgList;



//    QStringList t_strLines = str.split("\n");
//    for(int a = 0;a<t_strLines.length();a++){
//        retMsg t_msg;
//        QString t_lineStr = t_strLines[a]; //当前行的文本数据

//        int t_signIndex = -1;
//        t_signIndex = t_lineStr.indexOf(" | ");

//        if(t_signIndex != -1 && t_lineStr.left(t_signIndex).toInt() != 0){
//            QString t_signStr = t_lineStr.right(t_lineStr.length() - t_signIndex - QString(" | ").length()); //获取标记的一整段文字
//            if(a + 1 >= t_strLines.length() || t_msgList.length() < 1){goto MSG_THINK;}//判断是否有下一行，且已经拥有了加入的数据

//            QString t_nextStr = t_strLines[a + 1]; //获取下一行文本
//            int t_nextIndex = t_nextStr.indexOf(" | ");
//            if(t_nextIndex != t_signIndex){goto MSG_THINK;}; //检查下一行的波浪线区域的划分是否为当前行相同


//            int t_signStart = t_nextStr.indexOf("^",t_nextIndex + 1);
//            int t_signEnd = t_nextStr.lastIndexOf("~");
//            if(t_signStart == -1){goto MSG_THINK;}; //检查波浪线是否标记正确，不正确则直接跳过

//            t_msg = t_msgList[t_msgList.length() - 1]; //获取最后一个标记的信息
//            if(t_signEnd == -1){t_msg.length = 1;} //如果没有末尾信息，则默认为长度为1
//            if(t_signStr < t_signEnd){t_msg.length = t_signEnd - t_signStart;} //检索标记的长度信息
//            t_msg.tips = t_signStr.mid(t_signStart,t_signStr.length());
//            t_msg.column = t_signStart - t_nextIndex - QString(" | ").length() - 1;
//            a++; //直接跳过下一行的检索，因为下一行为标记行
//            t_msgList.append(t_msg);
//            continue;
//        }


//        MSG_THINK:
//        QStringList t_list = t_lineStr.split(": "); //更具冒号分隔

//        //分析警告内容
//        if(t_list.length() <= 1){ //默认类型数据返回
//            t_msg.tips = t_strLines[a];
//            t_msg.type = tipType::normal;
//            t_msgList.append(t_msgList);
//            continue;
//        }
//        else if(t_list.length() <= 3){
//            t_msg.fileName = t_list[0];
//            t_msg.tips = t_list[1];
//            if(t_list.length() == 3) t_msg.tips += t_list[2];
//        }
//        else if(t_list.length() >= 4){
//            t_msg.fileName = t_list[0];
//            int t_row = t_list[1].toInt();
//            int t_column = t_list[2].toInt();
//            if(t_row != 0 && t_column != 0){
//                t_msg.row = t_row;
//                t_msg.column = t_column;
//                t_msg.tips = t_list[3];
//            }
//            else{
//                t_msg.tips = t_list[1] + t_list[2] + t_list[3];
//            }

//            for(int a = 4;a<t_list.length();a++){
//                t_msg.tips += t_list[a];
//            }
//        }


//        //分析警告类型
//        if(t_msg.tips.right(QString("warning:").length()) == "warning:"){
//            t_msg.type = tipType::warning;
//        }
//        else if(t_msg.tips.right(QString("error:").length()) == "error:"){
//            t_msg.type = tipType::error;
//        }
//        else{
//            t_msg.type = tipType::normal;
//        }

//        //添加信息到返回
//        t_msgList.append(t_msg);
//    }

    return t_msgList;
}

*/
