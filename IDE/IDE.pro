QT       += core gui webview

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webenginecore webenginewidgets

CONFIG += c++17 file_copies

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#输出的文件路径
DESTDIR = $$OUT_PWD/../release
#输出的文件名
TARGET = FMS

#子项目


#复制文件到构建的目标目录.
config.files = $$PWD/RunConfig/config           # 要复制的文件或目录
config.path = $$OUT_PWD/../release # 配置需要复制的目标目录, $$OUT_PWD为QMake内置变量，含义为程序输出目录
proModel.files = $$PWD/RunConfig/proModel           # 要复制的文件或目录
proModel.path = $$OUT_PWD/../release # 配置需要复制的目标目录, $$OUT_PWD为QMake内置变量，含义为程序输出目录
web.files = $$PWD/RunConfig/web           # 要复制的文件或目录
web.path = $$OUT_PWD/../release # 配置需要复制的目标目录, $$OUT_PWD为QMake内置变量，含义为程序输出目录
widgets.files = $$PWD/RunConfig/widgets           # 要复制的文件或目录
widgets.path = $$OUT_PWD/../release # 配置需要复制的目标目录, $$OUT_PWD为QMake内置变量，含义为程序输出目录
formStyle.files = $$PWD/RunConfig/formStyle           # 要复制的文件或目录
formStyle.path = $$OUT_PWD/../release # 配置需要复制的目标目录, $$OUT_PWD为QMake内置变量，含义为程序输出目录

COPIES += config proModel web widgets formStyle # 配置COPIES



SOURCES += \
    Plugin/Plugin_Base.cpp \
    Plugin/Plugin_CodeEditorInterface.cpp \
    Plugin/Plugin_Global.cpp \
    Plugin/Plugin_Manger.cpp \
    SwSystem/System_GlobalVar.cpp \
    SwSystem/System_History.cpp \
    SwSystem/System_UtilFun.cpp \
    SwSystem/system_systemsetting.cpp \
    Widget/Widget_Button_ListItem.cpp \
    Widget/Widget_Button_ModHistoryItem.cpp \
    Widget/Widget_Button_ModItem.cpp \
    Widget/Widget_Button_PluginItem.cpp \
    Widget/Widget_Button_Start.cpp \
    Widget/Widget_Button_WidgetItem.cpp \
    Widget/Widget_Statusbar.cpp \
    Widget/Widget_TipItem.cpp \
    Window/Form_About.cpp \
    Window/Form_Begin.cpp \
    Window/Form_Content.cpp \
    Window/Form_Editor.cpp \
    Window/Form_Index.cpp \
    Window/Form_ListPrint.cpp \
    Window/Form_New.cpp \
    Window/Form_PluginManger.cpp \
    Window/Form_ProjectManger.cpp \
    Window/Form_SystemSettings.cpp \
    Window/Form_TextPrint.cpp \
    Window/Form_VisualFolder.cpp \
    Window/Form_WidgetBox.cpp \
    Window/Form_WindowTab.cpp \
    Window/Form_WorkSpace.cpp \
    Window/Form_TipManger.cpp \
    Window/settingWindow/Form_settings_Basic.cpp \
    Window/settingWindow/Form_settings_Color.cpp \
    Window/settingWindow/Form_settings_DataBase.cpp \
    Window/settingWindow/Form_settings_Device.cpp \
    Window/settingWindow/Form_settings_Git.cpp \
    Window/settingWindow/Form_settings_Qt.cpp \
    main.cpp \
    mainwindow.cpp \
    module/mod_WebPage.cpp \
    module/mod_settingsFormBase.cpp

HEADERS += \
    Plugin/Plugin_Base.h \
    Plugin/Plugin_CodeEditorInterface.h \
    Plugin/Plugin_Global.h \
    Plugin/Plugin_Manger.h \
    SwSystem/System_GlobalVar.h \
    SwSystem/System_History.h \
    SwSystem/System_UtilFun.h \
    SwSystem/system_systemsetting.h \
    Widget/Widget_Button_ListItem.h \
    Widget/Widget_Button_ModHistoryItem.h \
    Widget/Widget_Button_ModItem.h \
    Widget/Widget_Button_PluginItem.h \
    Widget/Widget_Button_Start.h \
    Widget/Widget_Button_WidgetItem.h \
    Widget/Widget_Statusbar.h \
    Widget/Widget_TipItem.h \
    Window/Form_About.h \
    Window/Form_Begin.h \
    Window/Form_Content.h \
    Window/Form_Editor.h \
    Window/Form_Index.h \
    Window/Form_ListPrint.h \
    Window/Form_New.h \
    Window/Form_PluginManger.h \
    Window/Form_ProjectManger.h \
    Window/Form_SystemSettings.h \
    Window/Form_TextPrint.h \
    Window/Form_VisualFolder.h \
    Window/Form_WidgetBox.h \
    Window/Form_WindowTab.h \
    Window/Form_WorkSpace.h \
    Window/Form_TipManger.h \
    Window/settingWindow/Form_settings_Basic.h \
    Window/settingWindow/Form_settings_Color.h \
    Window/settingWindow/Form_settings_DataBase.h \
    Window/settingWindow/Form_settings_Device.h \
    Window/settingWindow/Form_settings_Git.h \
    Window/settingWindow/Form_settings_Qt.h \
    mainwindow.h \
    module/mod_WebPage.h \
    module/mod_settingsFormBase.h

FORMS += \
    Widget/Widget_Button_ListItem.ui \
    Widget/Widget_Button_ModHistoryItem.ui \
    Widget/Widget_Button_ModItem.ui \
    Widget/Widget_Button_PluginItem.ui \
    Widget/Widget_Button_Start.ui \
    Widget/Widget_Button_WidgetItem.ui \
    Widget/Widget_Statusbar.ui \
    Widget/Widget_TipItem.ui \
    Window/Form_About.ui \
    Window/Form_Beginui.ui \
    Window/Form_Content.ui \
    Window/Form_Editor.ui \
    Window/Form_Index.ui \
    Window/Form_ListPrint.ui \
    Window/Form_New.ui \
    Window/Form_PluginManger.ui \
    Window/Form_ProjectManger.ui \
    Window/Form_SystemSettings.ui \
    Window/Form_TextPrint.ui \
    Window/Form_VisualFolder.ui \
    Window/Form_WidgetBox.ui \
    Window/Form_WindowTab.ui \
    Window/Form_WorkSpace.ui \
    Window/Form_TipManger.ui \
    Window/settingWindow/Form_settings_Basic.ui \
    Window/settingWindow/Form_settings_Color.ui \
    Window/settingWindow/Form_settings_DataBase.ui \
    Window/settingWindow/Form_settings_Device.ui \
    Window/settingWindow/Form_settings_Git.ui \
    Window/settingWindow/Form_settings_Qt.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
icons.qrc \
    res.qrc


#load qsciscintilla
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../release/lib/ -lqscintilla
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../release/lib/ -lqscintillad
else:unix: LIBS += -L$$OUT_PWD/../release/lib/ -lqscintilla

INCLUDEPATH += $$OUT_PWD/../release
DEPENDPATH += $$OUT_PWD/../release
