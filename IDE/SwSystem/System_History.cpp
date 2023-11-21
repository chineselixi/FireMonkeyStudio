
#include "System_History.h"
#include "QJsonDocument"
#include "QJsonArray"
#include "QJsonObject"
#include "System_UtilFun.h""

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
    QJsonDocument t_jsonDoc = QJsonDocument::fromJson(System_File::readFile(this->proHisPath));
    if(!t_jsonDoc.isArray()){
        return false;
    }

    QJsonArray t_jsonArray = t_jsonDoc.array();
    if(t_jsonArray.size() == 0){
        return false;
    }

    QString t_name,t_ico,t_path,t_other;
    for(QJsonValueRef item : t_jsonArray){
        QJsonObject t_obj = item.toObject();
        t_name = t_obj.value("name").toString("");
        t_ico = t_obj.value("ico").toString("");
        t_path = t_obj.value("path").toString("");
        t_other = t_obj.value("other").toString("");
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
    for(int a=0;a<this->His_proList.length();a++){
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


//清空所有历史信息
void System_History::clear()
{
    His_proList.clear(); //清空历史信息
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
    QJsonDocument t_jsonDoc;
    QJsonArray t_jsonArray;
    for(int a=0;a<this->His_proList.length();a++){
        QJsonObject t_jsonObj;
        t_jsonObj.insert("name",this->His_proList[a].showName);
        t_jsonObj.insert("ico",this->His_proList[a].showIco);
        t_jsonObj.insert("path",this->His_proList[a].filePath);
        t_jsonObj.insert("other",this->His_proList[a].other);
        t_jsonArray.append(t_jsonObj);
    }
    t_jsonDoc.setArray(t_jsonArray);
    System_File::writeFile(this->proHisPath,t_jsonDoc.toJson());
}

