
#include "plugin_uixeditor.h"
#include "QFileInfo"



Plugin_UixEditor::Plugin_UixEditor()
{
    /*
* 注意，此时内部所有指针都是nullptr，不允许调用ide能力，当event_onModLoadFinish加载完毕后相关指针与模块才加载完毕
* 注意：调用指针的时候也需要判断调用的指针是否为空指针，在某些场景下，ide内部会置空某些模块内的指针
*/
    this->self_BaseMsg.name = "uix界面设计器";
    this->self_BaseMsg.version = "0.0.0.1 Dev";
    this->self_BaseMsg.versionNumber = 1;
    this->self_BaseMsg.sign = "UixEditor";
    this->self_BaseMsg.note = "FireMenkeyStudio界面编辑器插件，用于处理uix界面文件。\n ";
    this->self_BaseMsg.loadTip = "uix界面编辑器插件加载成功，IDE支持uix可视化界面设计";
}


//工作空间加载完毕
void Plugin_UixEditor::event_onWorkSpaceFinish()
{
    itemBox = new Form_WidgetBox;
    QDockWidget* t_dockWidget = new QDockWidget;
    t_dockWidget->setWidget(itemBox);
    t_dockWidget->setWindowTitle("控件箱");
    WorkSpace_DockWidget_Add(Qt::DockWidgetArea::RightDockWidgetArea,t_dockWidget);





    //测试代码
    itemBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Cursor_16x.png"),"指针","Currsor");
    itemBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/TextBox_16x.png"),"编辑框","Currsor");
    itemBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Image_16x.png"),"图片框","Currsor");
    itemBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Panel_16x.png"),"外形框","Currsor");
    itemBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Label_16x.png"),"标签","Currsor");
    itemBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Button_16x.png"),"按钮","Currsor");
    itemBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/Checkbox_16x.png"),"选择框","Currsor");
    itemBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/RadioButton_16x.png"),"单选框","Currsor");
    itemBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/ComboBox_16x.png"),"组合框","Currsor");
    itemBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/ListBox_16x.png"),"列表框","Currsor");
    itemBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/CheckboxList_16x.png"),"选择列表框","Currsor");
    itemBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/VerticalScrollBarControl_16x.png"),"纵向滚动条","Currsor");
    itemBox->addItem(QPixmap(":/WidgetBox/icon/WidgetBox/BlueIcons/HorizontalScrollBarControl_16x.png"),"横向滚动条","Currsor");

}


//当文件被打开
bool Plugin_UixEditor::event_onFileOpen(QString filePath)
{
    QString t_fileSuffix = QFileInfo(filePath).suffix();
    if(t_fileSuffix == "uix"){
        qDebug() << "添加1";
        //QString title, QWidget *form, QString sign, QIcon titeIco,PluginGlobalMsg::TabType type
        Form_EditorSpace* t_editorSpace = new Form_EditorSpace;
        //t_editorSpace->setAttribute(Qt::WA_StyledBackground); //脱离父窗口样式的覆盖



        qDebug() << "添加2";

        this->WorkSpace_addTabWindow(QFileInfo(filePath).fileName(),t_editorSpace,filePath,QIcon(":/WindowIco/icon/WindowIco/WindowsForm_16x.png"),PluginGlobalMsg::TabType::form); //将编辑器容器添加到Tab
        qDebug() << "添加3";
        return false;//阻止继续的事件激发
    }
    return true;
}


////获取基础的系统指针
//Plugin_Base::libMsg Plugin_UixEditor::getBaseMsg()
//{
//    return self_BaseMsg;
//}

