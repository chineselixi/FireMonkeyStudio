#include "mod_TipList.h"
#include "QKeyEvent"


mod_TipList::mod_TipList(QWidget *parent,QSize iconSize):QListWidget(parent)
{
    //connect(this, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));

    connect(this, &QListWidget::itemClicked, this, &mod_TipList::onItemClicked,Qt::QueuedConnection);

    this->setIconSize(iconSize);//设置ICON的图标
    //tipEvent = strEvent; //保存函数指针
}

//展示列表
void mod_TipList::ShowTips(QString src, QRect positionRec, bool thinkNow, QString otherSrc)
{
    this->clear();//清空item
    QVector<strLikeMsg> t_keyList;
    t_keyList.append(getStringLikeList(src,List_ClassList,listType::ClassList));

    t_keyList.append(getStringLikeList(src,List_ConstList,listType::ConstList));
    t_keyList.append(getStringLikeList(src,List_DefList,listType::DefList));
    t_keyList.append(getStringLikeList(src,List_FunList,listType::FunList));
    t_keyList.append(getStringLikeList(src,List_HeadList,listType::HeadList));
    t_keyList.append(getStringLikeList(src,List_KeyWordList,listType::KeyWordList));
    t_keyList.append(getStringLikeList(src,List_OtherList,listType::OtherList));
    t_keyList.append(getStringLikeList(src,List_StructList,listType::StructList));
    t_keyList.append(getStringLikeList(src,List_VarList,listType::VarList));
    t_keyList.append(getStringLikeList(src,List_SystemSaveList,listType::SystemSave));

    //相似度排序
    strLikeMsg t_strOne;

    for(int a = t_keyList.length() - 1;a > 0;a--){
        for(int b = 0;b<a;b++){
            if(t_keyList[b].likeNum < t_keyList[b + 1].likeNum){
                t_strOne = t_keyList[b];
                t_keyList[b] = t_keyList[b + 1];
                t_keyList[b + 1] = t_strOne;
            }
        }
    }
    for(int a = 0;a<t_keyList.length();a++){
        QIcon t_icon;
        switch (t_keyList[a].type){
        case listType::ClassList:{
            t_icon = QIcon(":/tipsIcon/icon/tipIcon/class.png");break;
        }
        case listType::ConstList:{
            t_icon = QIcon(":/tipsIcon/icon/tipIcon/const.png");break;
        }
        case listType::DefList:{
            t_icon = QIcon(":/tipsIcon/icon/tipIcon/def.png");break;
        }
        case listType::FunList:{
            t_icon = QIcon(":/tipsIcon/icon/tipIcon/fun.png");break;
        }
        case listType::HeadList:{
            t_icon = QIcon(":/tipsIcon/icon/tipIcon/head.png");break;
        }
        case listType::KeyWordList:{
            t_icon = QIcon(":/tipsIcon/icon/tipIcon/key.png");break;
        }
        case listType::OtherList:{
            t_icon = QIcon(":/tipsIcon/icon/tipIcon/other.png");break;
        }
        case listType::StructList:{
            t_icon = QIcon(":/tipsIcon/icon/tipIcon/struct.png");break;
        }
        case listType::VarList:{
            t_icon = QIcon(":/tipsIcon/icon/tipIcon/var.png");break;
        }
        case listType::SystemSave:{
            t_icon = QIcon(":/tipsIcon/icon/tipIcon/none.png");break;
        }
        default:t_icon = QIcon(":/tipsIcon/icon/tipIcon/none.png");break;
        }
        //qDebug()<<t_keyList[a].str<<"  "<<t_keyList[a].likeNum;
        this->addItem(new QListWidgetItem(t_icon,t_keyList[a].str));
    }

    if(t_keyList.length() > 0){
        this->setGeometry(positionRec);
        this->show();
    }
}



//这将直接激活字符串事件
void mod_TipList::Select()
{
    QString t_selectStr = this->currentItem()->text();
    if(!t_selectStr.isEmpty()){
        this->onTipOut(t_selectStr); //激活提示事件
    }
}


//添加列表信息
void mod_TipList::AddListMsg(listType type, QVector<QString> strList)
{
    this->getList(type)->append(strList);
}

//删除多个信息组
void mod_TipList::DropAllListMsg(listType type)
{
    this->getList(type)->clear();
}

//获取列表
QVector<QString>* mod_TipList::getList(listType type)
{
    switch (type) {
    case listType::KeyWordList:
        return &List_KeyWordList;
    case listType::HeadList:
        return &List_HeadList;
    case listType::ConstList:
        return &List_ConstList;
    case listType::VarList:
        return &List_VarList;
    case listType::FunList:
        return &List_FunList;
    case listType::ClassList:
        return &List_ClassList;
    case listType::StructList:
        return &List_StructList;
    case listType::DefList:
        return &List_DefList;
    case listType::OtherList:
        return &List_OtherList;
    default:
        return &List_SystemSaveList;
    }
}

void mod_TipList::onItemClicked(QListWidgetItem *item)
{
    this->Select();
    this->setHidden(true);
}


//按钮按下
void mod_TipList::keyPressEvent(QKeyEvent *event)
{
    //这里的return和enter分别是主键盘和小键盘上面的回车键
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        this->Select();
        this->setHidden(true);//激活事件完毕后隐藏
    } else {
        QListWidget::keyPressEvent(event);
    }
}




//整理文本列表的指定字符串相似程度
QVector<mod_TipList::strLikeMsg> mod_TipList::getStringLikeList(QString src,QVector<QString> parentList,listType type)
{
    strLikeMsg t_strOne;
    QVector<strLikeMsg> t_strLikelist;
    //开始检索是否相像
    for(int a = 0;a < parentList.length();a++){
        t_strOne.str = parentList[a];
        t_strOne.likeNum = this->findStringLike(src,parentList[a]);
        t_strOne.type = type;
        if(t_strOne.likeNum > 0){
            t_strLikelist.append(t_strOne);
        }
    }
    return t_strLikelist;
}


//查找相似程度
int mod_TipList::findStringLike(QString src, QString parentStr)
{
    if(src.length() > parentStr.length()){ //子项长度大于父项，则直接跳出
        return 0;
    }

    QString t_findStr = ""; //查找的字符
    int t_index = -1;
    int t_fastIndex = -1;
    for(int a = 0;a<src.length();a++){
        t_findStr = src.mid(0,a+1);
        t_index = parentStr.indexOf(t_findStr);
        if(t_index == -1){
            break;
        }
        t_fastIndex = t_index;
    }
    //qDebug()<<parentStr<<"  "<<(t_findStr.length() - 1) <<"  "<<parentStr.length();

    int retNum = (t_findStr.length() - 1.0) / parentStr.length() * 100;//基本相似判断加成
    if(t_fastIndex >= 0){
        retNum += 100 - (float)t_fastIndex / parentStr.length() * 100;//符号越靠前加成
    }

    return retNum; //返回相似的概率（0-200）
}


//删除一个信息
void mod_TipList::DeleteListMsg(listType type, QString strList)
{
    QVector<QString>* t_list = this->getList(type);
    for(int a = 0;a<t_list->length();a++){
        if((*t_list)[a] == strList){
            (*t_list).removeAt(a);
        }
    }
}


