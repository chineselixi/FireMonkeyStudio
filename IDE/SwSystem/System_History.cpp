
#include "System_History.h"
#include "QSettings"


System_History::System_History()
{

}

System_History::~System_History()
{

}

//初始化
bool System_History::Init(QString proHisConfigPath)
{
    this->proHisPath = proHisConfigPath;

    QSettings t_setPro_Name(proHisConfigPath, QSettings::IniFormat);//工程吗名称信息
    t_setPro_Name.beginGroup("HisList_Name");
    QSettings t_setPro_Ico(proHisConfigPath, QSettings::IniFormat);//工程总配置信息
    t_setPro_Ico.beginGroup("HisList_Ico");
    QSettings t_setPro_Path(proHisConfigPath, QSettings::IniFormat);//工程总配置信息
    t_setPro_Path.beginGroup("HisList_Path");
    QSettings t_setPro_Other(proHisConfigPath, QSettings::IniFormat);//工程总配置信息
    t_setPro_Other.beginGroup("HisList_Other");

    QString t_name,t_ico,t_path,t_other;

    for(int a = 0;a<t_setPro_Name.allKeys().length();a++){
        t_name = t_setPro_Name.value(QString::number(a)).toString();
        t_ico = t_setPro_Ico.value(QString::number(a)).toString();
        t_path = t_setPro_Path.value(QString::number(a)).toString();
        t_other = t_setPro_Other.value(QString::number(a)).toString();
        this->His_proList.append({t_name,t_ico,t_path,t_other});
    }
    return true;
}

//获取工程历史列表
QVector<System_History::HistoryMsg> System_History::getHisList()
{
    return His_proList;
}

//移除工程列表历史记录
bool System_History::removeProHisList(QString sign)
{
    qDebug() << "sss";

    for(int a=0;a<this->His_proList.length();a++){
        qDebug() << a << this->His_proList.length();
        qDebug() << this->His_proList[a].filePath << sign;

        if(this->His_proList[a].filePath == sign){
            this->His_proList.removeAt(a);
            return true;
        }
    }
    return false;
}

//清理重复数据，后加入的数据将不会
void System_History::clearRepeat()
{
    for(int a=0;a<this->His_proList.length();a++){
        for(int b = a+1;b<this->His_proList.length();b++){
            if(this->His_proList[a].filePath == this->His_proList[b].filePath){
                this->His_proList.removeAt(a);
                this->clearRepeat(); //递归检查
                break;
            }
        }
    }
}

//添加子项目
void System_History::addMsg(QString showName, QString showIco, QString filePath, QString other)
{
    His_proList.append({showName,showIco,filePath,other});
}


//根据路径，检索当前是否存在此历史记录
bool System_History::has(QString filePath)
{
    for(int a=0;a<this->His_proList.length();a++){
        if(His_proList[a].filePath == filePath){
            return true;
        }
    }
    return false;
}


//保存列表
void System_History::saveHisList()
{
    QSettings t_setPro_Name(this->proHisPath, QSettings::IniFormat);//工程吗名称信息
    t_setPro_Name.beginGroup("HisList_Name");
    QSettings t_setPro_Ico(this->proHisPath, QSettings::IniFormat);//工程总配置信息
    t_setPro_Ico.beginGroup("HisList_Ico");
    QSettings t_setPro_Path(this->proHisPath, QSettings::IniFormat);//工程总配置信息
    t_setPro_Path.beginGroup("HisList_Path");
    QSettings t_setPro_Other(this->proHisPath, QSettings::IniFormat);//工程总配置信息
    t_setPro_Other.beginGroup("HisList_Other");

    t_setPro_Name.clear(); //删除全部的信息
    for(int a=0;a<this->His_proList.length();a++){
        t_setPro_Name.setValue(QString::number(a),this->His_proList[a].showName); //工程名
        t_setPro_Ico.setValue(QString::number(a),this->His_proList[a].showIco); //图标
        t_setPro_Path.setValue(QString::number(a),this->His_proList[a].filePath); //文件路径
        t_setPro_Other.setValue(QString::number(a),this->His_proList[a].other); //其他信息
    }
}

