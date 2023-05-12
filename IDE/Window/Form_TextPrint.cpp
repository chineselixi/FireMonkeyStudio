#include "Form_TextPrint.h"
#include "ui_Form_TextPrint.h"

Form_TextPrint::Form_TextPrint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_TextPrint)
{

    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

Form_TextPrint::~Form_TextPrint()
{
    delete ui;
}

QSize Form_TextPrint::sizeHint() const
{
    return QSize(180, 180); /* 在这里定义dock的初始大小 */
}

//清理文本编辑器
void Form_TextPrint::clearTextEditor()
{
    ui->textEdit->clear();
}

//添加行文本
void Form_TextPrint::addLineText(QString text, QColor color)
{
    ui->textEdit->setTextColor(color);
    ui->textEdit->append(text);
}

//添加文本
void Form_TextPrint::addText(QString text, QColor color)
{
    ui->textEdit->textCursor().movePosition(QTextCursor::End);
    ui->textEdit->setTextColor(color);
    ui->textEdit->insertPlainText(text);
}
