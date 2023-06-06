/********************************************************************************
** Form generated from reading UI file 'Widget_Button_PluginItem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BUTTON_PLUGINITEM_H
#define UI_WIDGET_BUTTON_PLUGINITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Button_PluginItem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_img;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_pluginName;
    QLabel *label_sign;
    QLabel *label_version;
    QSpacerItem *horizontalSpacer;
    QLabel *label_filePath;
    QFrame *frame;
    QPushButton *But_enable;
    QPushButton *But_unload;

    void setupUi(QWidget *Widget_Button_PluginItem)
    {
        if (Widget_Button_PluginItem->objectName().isEmpty())
            Widget_Button_PluginItem->setObjectName("Widget_Button_PluginItem");
        Widget_Button_PluginItem->resize(501, 64);
        Widget_Button_PluginItem->setStyleSheet(QString::fromUtf8("#Widget_Button_PluginItem{\n"
"	background-color: rgb(245, 245, 245);\n"
"}\n"
"\n"
"#label_pluginName{\n"
"	color: rgb(0,0,0);\n"
"}\n"
"\n"
"#label_filePath{\n"
"	color: rgb(79, 79, 79);\n"
"}\n"
"\n"
"/*\351\231\204\345\212\240\346\217\222\344\273\266\346\240\207\350\256\260\346\240\207\347\255\276*/\n"
"#label_sign,#label_version{\n"
"	color: rgb(28, 28, 28);\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius:8px;\n"
"	padding:4px;\n"
"	margin-left:8px;\n"
"	margin-top:5px;\n"
"	margin-bottom:5px;\n"
"}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(Widget_Button_PluginItem);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(4, 0, 0, 0);
        label_img = new QLabel(Widget_Button_PluginItem);
        label_img->setObjectName("label_img");
        label_img->setMinimumSize(QSize(48, 48));
        label_img->setMaximumSize(QSize(48, 48));
        label_img->setPixmap(QPixmap(QString::fromUtf8(":/WidgetIcon/icon/WidgetIcon/plugin/pluginNormal.png")));

        horizontalLayout_2->addWidget(label_img);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_pluginName = new QLabel(Widget_Button_PluginItem);
        label_pluginName->setObjectName("label_pluginName");
        label_pluginName->setMinimumSize(QSize(0, 28));
        label_pluginName->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(12);
        label_pluginName->setFont(font);

        horizontalLayout->addWidget(label_pluginName);

        label_sign = new QLabel(Widget_Button_PluginItem);
        label_sign->setObjectName("label_sign");
        label_sign->setMinimumSize(QSize(0, 40));
        label_sign->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setPointSize(8);
        label_sign->setFont(font1);
        label_sign->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_sign);

        label_version = new QLabel(Widget_Button_PluginItem);
        label_version->setObjectName("label_version");
        label_version->setMinimumSize(QSize(0, 40));
        label_version->setMaximumSize(QSize(16777215, 40));

        horizontalLayout->addWidget(label_version);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        label_filePath = new QLabel(Widget_Button_PluginItem);
        label_filePath->setObjectName("label_filePath");
        label_filePath->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_filePath->setWordWrap(true);

        verticalLayout->addWidget(label_filePath);


        horizontalLayout_2->addLayout(verticalLayout);

        frame = new QFrame(Widget_Button_PluginItem);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(90, 50));
        frame->setMaximumSize(QSize(90, 60));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        But_enable = new QPushButton(frame);
        But_enable->setObjectName("But_enable");
        But_enable->setGeometry(QRect(5, 2, 80, 25));
        But_enable->setMinimumSize(QSize(80, 25));
        But_enable->setMaximumSize(QSize(80, 25));
        But_unload = new QPushButton(frame);
        But_unload->setObjectName("But_unload");
        But_unload->setGeometry(QRect(5, 30, 80, 25));
        But_unload->setMinimumSize(QSize(80, 25));
        But_unload->setMaximumSize(QSize(80, 25));

        horizontalLayout_2->addWidget(frame);


        retranslateUi(Widget_Button_PluginItem);

        QMetaObject::connectSlotsByName(Widget_Button_PluginItem);
    } // setupUi

    void retranslateUi(QWidget *Widget_Button_PluginItem)
    {
        Widget_Button_PluginItem->setWindowTitle(QCoreApplication::translate("Widget_Button_PluginItem", "Form", nullptr));
        label_img->setText(QString());
        label_pluginName->setText(QCoreApplication::translate("Widget_Button_PluginItem", "\351\273\230\350\256\244\346\214\211\351\222\256\346\240\207\351\242\230", nullptr));
        label_sign->setText(QCoreApplication::translate("Widget_Button_PluginItem", "Normal Sign", nullptr));
        label_version->setText(QCoreApplication::translate("Widget_Button_PluginItem", "0.0.0.1", nullptr));
        label_filePath->setText(QCoreApplication::translate("Widget_Button_PluginItem", "<html><head/><body><p>home/dirname/plugin.plg</p></body></html>", nullptr));
        But_enable->setText(QCoreApplication::translate("Widget_Button_PluginItem", "\347\246\201\347\224\250", nullptr));
        But_unload->setText(QCoreApplication::translate("Widget_Button_PluginItem", "\345\215\270\350\275\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Button_PluginItem: public Ui_Widget_Button_PluginItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BUTTON_PLUGINITEM_H
