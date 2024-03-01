#include "GccUtil.h"


GccUtil::GccUtil()
{

}

QList<GccUtil::GccCheckNode> GccUtil::parsingGccError(QString gccErrorText)
{
    QList<GccCheckNode> t_retList;
    GccCheckNode t_node; //临时节点

    QStringList t_lines = gccErrorText.split("\n"); //按照冒号分割
    for(QString lineText : t_lines){

        qsizetype t_indexS = lineText.indexOf(" | ");
        qsizetype t_indexM = lineText.indexOf(":");

        if(t_indexM == 1){t_indexM = lineText.indexOf(":",2);} //防止因为Windows的盘符导致分割异常
        if(t_indexM != -1 && (t_indexS == -1 || t_indexS > t_indexM)){ //一般的提示信息
            qsizetype t_startindex = 0;
            bool isCastInt = false; //是否转换为整数

            QString t_filePath = lineText.left(t_indexM); //取出文件路径

            //qDebug() << "t_filePath" << t_filePath << t_indexM << lineText;

            t_startindex = t_indexM + 1; //新的开始位置
            t_indexM = lineText.indexOf(":",t_startindex);
            int t_line = lineText.mid(t_startindex,t_indexM - t_startindex).toInt(&isCastInt);  //获取并保存当前是否为报错行
            if(!isCastInt) continue; //转换失败则跳过此次循环数据

            t_startindex = t_indexM + 1; //新的开始位置
            t_indexM = lineText.indexOf(":",t_startindex);
            int t_cindex = lineText.mid(t_startindex,t_indexM - t_startindex).toInt(&isCastInt);  //获取并保存当前是否为报错行的索引
            if(!isCastInt) continue; //转换失败则跳过此次循环数据

            t_startindex = t_indexM + 1; //新的开始位置
            t_indexM = lineText.indexOf(":",t_startindex);
            QString t_tipTypeStr = lineText.mid(t_startindex,t_indexM - t_startindex).trimmed(); //获取警告类型
            if(t_tipTypeStr.isEmpty()) continue;
            GccType t_gccType;
            if(t_tipTypeStr == "warning"){
                t_gccType = GccType::WARN;
            }
            else if(t_tipTypeStr == "error"){
                t_gccType = GccType::ERR;
            }
            else{
                t_gccType = GccType::TIP;
            }

            t_startindex = t_indexM + 1; //新的开始位置
            QString t_tipStr = lineText.right(lineText.length() - t_startindex);
            if(t_tipStr.isEmpty()) continue;

            //记录当前行信息
            t_node.file = t_filePath;
            t_node.line = t_line;
            t_node.index = t_cindex;
            t_node.type = t_gccType;
            t_node.tipStr = t_tipStr.trimmed();
        }
        else{
            if(t_indexS != -1 && t_indexM == -1){
                if(lineText.left(t_indexS + 1).trimmed().isEmpty()){
                    QString t_rightStr = lineText.right(lineText.length() - t_indexS - 3);

                    int t_tipIndex = t_rightStr.lastIndexOf(" "); //查找开始的位置
                    if(t_tipIndex != -1){
                        t_tipIndex++;
                        t_node.startIndex = t_tipIndex;
                    }

                    t_rightStr = t_rightStr.trimmed();
                    if(t_rightStr.indexOf("^") != -1){
                        t_node.len = t_rightStr.length();
                        t_retList.append(t_node); //保存节点信息
                    }
                }
            }
        }

    }

    return t_retList;
}
