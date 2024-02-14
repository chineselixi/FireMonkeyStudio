#include "Form_settings_Color.h"
#include "ui_Form_settings_Color.h"
#include "QFontDatabase"

#include "SwSystem/System_GlobalVar.h"
#include "SwSystem/System_SystemSetting.h"

#include "Window/Form_SystemSettings.h"



Form_settings_Color::Form_settings_Color(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_settings_Color)
{
    ui->setupUi(this);
    Init();
}

Form_settings_Color::~Form_settings_Color()
{
    delete ui;
}




//初始化
void Form_settings_Color::Init()
{
    loadSettings(); //静态加载设置

    ui->comboBox_theme->setCurrentIndex(0); //加载第一个主题
    for(int a = 0;a < ui->comboBox_theme->count();a++){
        if(ui->comboBox_theme->itemText(a) == Setting::style_themeName){
            ui->comboBox_theme->setCurrentIndex(a);
            break;
        }
    }

    //自动主题切换
    ui->checkBox_autoTheme->setChecked(Setting::style_themeIsAuto);


    //Setting::style_font = ui->fontComboBox->currentFont();
    ui->fontComboBox->setCurrentText(Setting::style_font.family()); //如果本地有存在，则直接加载本地的信息

    //字体尺寸
    ui->lineEdit_fontSize->setText(QString::number(Setting::style_font.pointSize()));

    //字体加粗
    ui->checkBox_bold->setChecked(Setting::style_font.bold());

    //字体倾斜
    ui->checkBox_italic->setChecked(Setting::style_font.italic());

    //每日一贴
    ui->checkBox_dailyTips->setChecked(Setting::style_dailyTips);
}


//静态加载设置
void Form_settings_Color::loadSettings()
{
    Setting::style_themeName = Setting::sys_setting->getSettingValue("Style","theme","Blue").toString(); //读取主题样式
    Setting::style_themeIsAuto = Setting::sys_setting->getSettingValue("Style","autoTheme",false).toBool(); //读取自动切换
    Setting::style_font = QFont(Setting::sys_setting->getSettingValue("Style","fontName").toString()); //读取字体
    Setting::style_font.setPointSize(Setting::sys_setting->getSettingValue("Style","fontSize",14).toUInt()); //读取字体大小
    Setting::style_font.setBold(Setting::sys_setting->getSettingValue("Style","fontBold",false).toBool()); //读取字体加粗
    Setting::style_font.setItalic(Setting::sys_setting->getSettingValue("Style","fontItalic",false).toBool()); //读取字体倾斜
    Setting::style_dailyTips = Setting::sys_setting->getSettingValue("Style","dailyTips",true).toBool(); //读取每日一贴


}


//应用键被按下
void Form_settings_Color::Event_use()
{
    Setting::style_themeName = ui->comboBox_theme->currentText();
    Setting::sys_setting->changeSetting("Style","theme",Setting::style_themeName); //保存主题样式

    Setting::style_themeIsAuto = ui->checkBox_autoTheme->isChecked();
    Setting::sys_setting->changeSetting("Style","autoTheme",Setting::style_themeIsAuto); //保存主题样式

    Setting::style_font = ui->fontComboBox->currentFont(); //字体名称
    Setting::sys_setting->changeSetting("Style","fontName",Setting::style_font.family()); //保存字体

    Setting::style_font.setPointSize(ui->lineEdit_fontSize->text().toInt());
    Setting::sys_setting->changeSetting("Style","fontSize",Setting::style_font.pointSize()); //保存字体大小

    Setting::style_font.setBold(ui->checkBox_bold->isChecked()); //字体加粗
    Setting::sys_setting->changeSetting("Style","fontBold",Setting::style_font.bold()); //保存字体加粗

    Setting::style_font.setItalic(ui->checkBox_italic->isChecked()); //字体倾斜
    Setting::sys_setting->changeSetting("Style","fontItalic",Setting::style_font.italic()); //保存字体倾斜

    Setting::style_dailyTips = ui->checkBox_dailyTips; //每日一贴
    Setting::sys_setting->changeSetting("Style","dailyTips",Setting::style_dailyTips); //保存每日一贴



    Form_SystemSettings::changeThream(Setting::style_themeName); //实时更改主题
    return;
}

//确认键被按下
void Form_settings_Color::Event_Ok()
{
    return;
}

//取消键被按下
void Form_settings_Color::Event_cancel()
{
    return;
}


