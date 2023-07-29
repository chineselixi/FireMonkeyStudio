
#ifndef MOD_SETTINGSFORMBASE_H
#define MOD_SETTINGSFORMBASE_H


//设置窗口需要继承的基础父类

class mod_settingsFormBase
{
public:
    mod_settingsFormBase();


    virtual void Event_Ok(); //确认键被按下
    virtual void Event_cancel(); //取消键被按下
    virtual void Event_use(); //应用键被按下

};

#endif // MOD_SETTINGSFORMBASE_H
