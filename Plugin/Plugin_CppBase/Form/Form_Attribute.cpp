#include "Form_Attributee.h"
#include "ui_Form_Attribute.h"
#include "QFileDialog"
#include "QJsonDocument"
#include "QJsonObject"
#include "../../../IDE/SwSystem/System_UtilFun.h"

Form_Attribute::Form_Attribute(QWidget *parent, QString attrPath, QString proName) :
    QWidget(parent),
    attributeFilePath(attrPath),
    normalName(proName),
    ui(new Ui::Form_Attribute)
{
    ui->setupUi(this);
    QString t_file = System_File::readFile(attrPath);
    this->updateUi(loadAttribute(t_file)); //加载属性信息

    //加载设置信息到UI


}

Form_Attribute::~Form_Attribute()
{
    //保存设置
    QString t_json = this->buildJson(this->getAttrFromUi()); //获取保存的Json数据
    System_File::writeFile(attributeFilePath,t_json.toUtf8()); //写出保存配置信息

    delete ui;
}


//刷新UI
void Form_Attribute::updateUi(Attribute attr)
{
    if(attr.programName.isEmpty()){attr.programName = normalName;}//如果工程为空，添加信息
    ui->txt_applicationName->setText(attr.programName);
    ui->txt_copyright->setText(attr.copyright);

    //读取版本信息
    QStringList t_strLsit = attr.versionCode.split(".");

    qDebug() << "版本" << attr.versionCode;


    if(t_strLsit.length()>0) ui->txt_version4->setText(t_strLsit[t_strLsit.length() - 1]);
    if(t_strLsit.length()>1) ui->txt_version3->setText(t_strLsit[t_strLsit.length() - 2]);
    if(t_strLsit.length()>2) ui->txt_version2->setText(t_strLsit[t_strLsit.length() - 3]);
    if(t_strLsit.length()>3) ui->txt_version1->setText(t_strLsit[t_strLsit.length() - 4]);

    //输出文件路径
    attr.outPath = attr.outPath.replace("${projectPath}",QFileInfo(attributeFilePath).path());
    ui->txt_outPath->setText(attr.outPath); //输出路径
    attr.tempPath = attr.tempPath.replace("${projectPath}",QFileInfo(attributeFilePath).path());
    ui->txt_tempPath->setText(attr.tempPath); //临时文件路径

    attr.icoPath = attr.icoPath.replace("${projectPath}",QFileInfo(attributeFilePath).path());//替换为正确的路径
    QPixmap t_pixmap(attr.icoPath);
    if(!t_pixmap.isNull()){
        if(t_pixmap.width() > 64 || t_pixmap.height() >64){
            t_pixmap = t_pixmap.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        }
        ui->label_ico->setPixmap(t_pixmap);
    }
    this->icoPath = attr.icoPath;//保存图标路径

    ui->txt_explain->setText(attr.programNote); //程序备注说明
    ui->txt_srcName->setText(attr.srcName); //原始名称
    ui->txt_orgName->setText(attr.orgName); //公司社区名称
}



//从UI获取属性
Form_Attribute::Attribute Form_Attribute::getAttrFromUi()
{
    Attribute t_retAttr;
    t_retAttr.programName = ui->txt_applicationName->text();
    t_retAttr.copyright =  ui->txt_copyright->text();
    //读取版本信息
    t_retAttr.versionCode = ui->txt_version1->text() + "." + ui->txt_version2->text() + "." + ui->txt_version3->text() + "." + ui->txt_version4->text();
    //输出文件路径 ;//替换为正确的路径
    t_retAttr.outPath = ui->txt_outPath->text().replace(QFileInfo(attributeFilePath).path(), "${projectPath}"); //输出路径
    t_retAttr.tempPath = ui->txt_tempPath->text().replace(QFileInfo(attributeFilePath).path(), "${projectPath}"); //临时文件路径
    t_retAttr.icoPath = this->icoPath.replace(QFileInfo(attributeFilePath).path(),"${projectPath}"); //获取图标路径
    t_retAttr.programNote = ui->txt_explain->toPlainText(); //程序备注说明
    t_retAttr.srcName = ui->txt_srcName->text(); //原始名称
    t_retAttr.orgName = ui->txt_orgName->text(); //公司社区名称
    return t_retAttr;
}


//选择输出路径
void Form_Attribute::on_btn_outPath_clicked()
{
    QString t_dirPath = QFileDialog::getExistingDirectory(this, tr("选择输出目录"), "", QFileDialog::ShowDirsOnly);
    if(t_dirPath.isEmpty()) return;
    ui->txt_outPath->setText(t_dirPath);
}

//选择临时路径路径
void Form_Attribute::on_btn_tempPath_clicked()
{
    QString t_dirPath = QFileDialog::getExistingDirectory(this, tr("选择临时目录"), "", QFileDialog::ShowDirsOnly);
    if(t_dirPath.isEmpty()) return;
    ui->txt_tempPath->setText(t_dirPath);
}


//导入Ico
void Form_Attribute::on_btn_importIco_clicked()
{
    QString t_fileName = QFileDialog::getOpenFileName(nullptr, tr("选择程序"), "", tr("图标文件 (*ico)"));
    if(t_fileName.isEmpty()) return;

    Attribute t_attr = this->getAttrFromUi(); //获取当前UI的属性
    t_attr.icoPath = t_fileName;
    this->updateUi(t_attr); //更新UI

}



//还原清空Ico
void Form_Attribute::on_btn_recIco_clicked()
{
    ui->label_ico->setPixmap(QPixmap());
    Attribute t_attr = this->getAttrFromUi(); //获取当前UI的属性
    t_attr.icoPath = "";
    this->updateUi(t_attr); //更新UI
}



//获取把属性信息保存为Json数据
QString Form_Attribute::buildJson(Attribute attr)
{
    QJsonDocument t_jsonDocument;
    QJsonObject t_jsonObj;
    t_jsonObj.insert("programName",attr.programName);
    t_jsonObj.insert("copyright",attr.copyright);
    t_jsonObj.insert("versionCode",attr.versionCode);
    t_jsonObj.insert("outPath",attr.outPath);
    t_jsonObj.insert("tempPath",attr.tempPath);
    t_jsonObj.insert("icoPath",attr.icoPath);
    t_jsonObj.insert("programNote",attr.programNote);
    t_jsonObj.insert("srcName",attr.srcName);
    t_jsonObj.insert("orgName",attr.orgName);
    t_jsonDocument.setObject(t_jsonObj);
    return t_jsonDocument.toJson();
}

//把json文本载入为设置信息
Form_Attribute::Attribute Form_Attribute::loadAttribute(QString jsonStr)
{
    Attribute t_attr;
    QJsonDocument t_jsonDocument = QJsonDocument::fromJson(jsonStr.toUtf8()); //读入json文件
//    if(t_jsonDocument.isObject()){}
    QJsonObject t_jsonObj = t_jsonDocument.object();//读取Json
    t_attr.programName = t_jsonObj.value("programName").toString("");                           //程序名称
    t_attr.copyright = t_jsonObj.value("copyright").toString(QObject::tr("FMS 开发"));            //版权信息
    t_attr.versionCode = t_jsonObj.value("versionCode").toString("0.0.0.1");                    //版本信息
    t_attr.outPath = t_jsonObj.value("outPath").toString("${projectPath}/out");                 //输出文件目录
    t_attr.tempPath = t_jsonObj.value("tempPath").toString("${projectPath}/out/temp");           //临时文件目录
    t_attr.icoPath = t_jsonObj.value("icoPath").toString("${projectPath}/ico.ico");              //图标路径
    t_attr.programNote = t_jsonObj.value("programNote").toString(QObject::tr("本程序由FMS开发！"));   //程序备注说明
    t_attr.srcName = t_jsonObj.value("srcName").toString("");                                   //原始名称
    t_attr.orgName = t_jsonObj.value("orgName").toString(QObject::tr("火猴开发社区"));            //公司社区名称

    return t_attr;
}
