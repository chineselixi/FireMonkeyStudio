#include "Form_TipManger.h"
#include "ui_Form_TipManger.h"
#include "QDateTime"

Form_TipManger::Form_TipManger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_TipManger)
{
    ui->setupUi(this);
}

Form_TipManger::~Form_TipManger()
{
    delete ui;
}

//添加一个提示消息
uint16_t Form_TipManger::addTip(QString title, QString tip, qint64 showTime, TipType type, QPixmap pixmap, bool canClose)
{
    std::function<void(uint16_t id)> t_fun = [=](uint16_t id){
        this->closeTip(id);
    };

    TipNode* t_node = new TipNode;
    t_node->id = (++index);
    t_node->item = new QListWidgetItem(ui->listWidget);
    t_node->widget = new Widget_TipItem(t_node->id,title, tip,type,pixmap,canClose,t_fun);
    t_node->item->setSizeHint(QSize(184,49));        //设置每一个项目的高度
    t_node->closeTime = QDateTime::currentMSecsSinceEpoch() + showTime;
    connect(&t_node->timer,&QTimer::timeout,[t_node,this](){
        qint64 t_d = t_node->closeTime - QDateTime::currentMSecsSinceEpoch();
        if(t_d > 0){    //还剩时间，则再次等待
            t_node->timer.start(t_d + 10);
        }
        else{   //等待完毕，结束这个通知
            t_node->timer.stop();
            this->closeTip(t_node->id);
        }
    });

    ui->listWidget->addItem(t_node->item);
    ui->listWidget->setItemWidget(t_node->item,t_node->widget);   //将item与widget绑定

    TipNodeList.push_back(t_node);
    t_node->timer.start(showTime + 10); //开始循环
    return t_node->id;
}

void Form_TipManger::closeTip(uint16_t id)
{
    std::list<TipNode*>::iterator i;
    for(i = TipNodeList.begin(); i != TipNodeList.end(); i++){
        if((*i)->id == id){
            (*i)->timer.stop();
            delete (*i)->widget;
            delete (*i)->item;
            TipNodeList.erase(i);
            adjustWindowRec();  //调整窗口大小
            return;
        }
    }
}

//关闭所有提示
void Form_TipManger::closeAll()
{
    std::list<TipNode*>::iterator i;
    for(i = TipNodeList.begin(); i != TipNodeList.end(); i++){
        (*i)->timer.stop();
        delete (*i)->widget;
        delete (*i)->item;
    }
    TipNodeList.clear(); //清楚所有信息
    this->adjustWindowRec();    //调整窗口大小
}

//是否还存在此提示
bool Form_TipManger::hasTip(uint16_t id)
{
    std::list<TipNode*>::iterator i;
    for(i = TipNodeList.begin(); i != TipNodeList.end(); i++){
        if((*i)->id == id){
            return true;
        }
    }
    return false;
}

//调整窗口尺寸
void Form_TipManger::adjustWindowRec()
{
    QRect t_rect = this->geometry();
    uint16_t t_heigh = 0;
    if(TipNodeList.size() >= 10){
        t_heigh = 500;
    }
    else{
        t_heigh = 50 * TipNodeList.size();
    }
    t_rect.setTop(t_rect.top() + (t_rect.height() - t_heigh));
    t_rect.setHeight(t_heigh);
    this->setGeometry(t_rect);
    //ui->listWidget->scrollToBottom();
    //qDebug() << t_rect << t_heigh;
}

//提供右下角坐标，将窗口右下角移动到给定点
void Form_TipManger::moveToRT(int x, int y)
{
    this->adjustWindowRec(); //调整窗口
    QRect t_rect = this->geometry();
    QPoint t_p;
    t_p.setX(x - t_rect.width());
    t_p.setY(y - t_rect.height());
    this->move(t_p);
}

void Form_TipManger::setTipTitle(uint16_t id, QString title)
{
    std::list<TipNode*>::iterator i;
    for(i = TipNodeList.begin(); i != TipNodeList.end(); i++){
        if((*i)->id == id){
            (*i)->widget->setTipTitle(title);
            return;
        }
    }
}

void Form_TipManger::setTipText(uint16_t id, QString text)
{
    std::list<TipNode*>::iterator i;
    for(i = TipNodeList.begin(); i != TipNodeList.end(); i++){
        if((*i)->id == id){
            (*i)->widget->setTipText(text);
            return;
        }
    }
}

void Form_TipManger::setTipType(uint16_t id, TipType type)
{
    std::list<TipNode*>::iterator i;
    for(i = TipNodeList.begin(); i != TipNodeList.end(); i++){
        if((*i)->id == id){
            (*i)->widget->setTipType(type);
            return;
        }
    }
}

void Form_TipManger::setTipPixmap(uint16_t id, QPixmap pixmap)
{
    std::list<TipNode*>::iterator i;
    for(i = TipNodeList.begin(); i != TipNodeList.end(); i++){
        if((*i)->id == id){
            (*i)->widget->setTipPixmap(pixmap);
            return;
        }
    }
}

void Form_TipManger::setTipCanClose(uint16_t id, bool canClose)
{
    std::list<TipNode*>::iterator i;
    for(i = TipNodeList.begin(); i != TipNodeList.end(); i++){
        if((*i)->id == id){
            (*i)->widget->setTipCanClose(canClose);
            return;
        }
    }
}

void Form_TipManger::setTipShowTime(uint16_t id, qint64 showTime)
{
    std::list<TipNode*>::iterator i;
    for(i = TipNodeList.begin(); i != TipNodeList.end(); i++){
        if((*i)->id == id){
            (*i)->closeTime = QDateTime::currentMSecsSinceEpoch() + showTime;
            (*i)->timer.start(showTime + 10);
            return;
        }
    }
}

////事件接口
//bool Form_TipManger::event(QEvent *e)
//{
//    if (QEvent::Show == e->type())
//        if(QEvent::Show == e->type())
//        {
//            activateWindow();
//        }
//    else if (QEvent::WindowDeactivate == e->type())
//    {
//        this->close();
//    }
//    return QWidget::event(e);
//}
