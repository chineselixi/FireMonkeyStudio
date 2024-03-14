
#ifndef MOD_SETTINGSFORMBASE_H
#define MOD_SETTINGSFORMBASE_H

//the base parent class which need to be inherited by setting window 
//设置窗口需要继承的基础父类

class mod_settingsFormBase
{
public:
    mod_settingsFormBase();


    //confirm button be pressed
    virtual void Event_Ok(); //确认键被按下
    //cancel button be pressed
    virtual void Event_cancel(); //取消键被按下
    //apply button be pressed
    virtual void Event_use(); //应用键被按下

};

#endif // MOD_SETTINGSFORMBASE_H
