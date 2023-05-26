QT       += core gui webview

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webenginecore webenginewidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Plugin/Plugin_Base.cpp \
    Plugin/Plugin_Global.cpp \
    Plugin/Plugin_Manger.cpp \
    SwSystem/System_GlobalVar.cpp \
    SwSystem/System_History.cpp \
    Widget/Widget_Button_ListItem.cpp \
    Widget/Widget_Button_ModHistoryItem.cpp \
    Widget/Widget_Button_ModItem.cpp \
    Widget/Widget_Button_PluginItem.cpp \
    Widget/Widget_Button_Start.cpp \
    Widget/Widget_Button_WidgetItem.cpp \
    Window/Form_About.cpp \
    Window/Form_Begin.cpp \
    Window/Form_Content.cpp \
    Window/Form_Editor.cpp \
    Window/Form_ListPrint.cpp \
    Window/Form_New.cpp \
    Window/Form_PluginManger.cpp \
    Window/Form_ProjectManger.cpp \
    Window/Form_TextPrint.cpp \
    Window/Form_VisualFolder.cpp \
    Window/Form_WidgetBox.cpp \
    Window/Form_WindowTab.cpp \
    Window/Form_WorkSpace.cpp \
    main.cpp \
    mainwindow.cpp \
    module/mod_WebPage.cpp

HEADERS += \
    Plugin/Plugin_Base.h \
    Plugin/Plugin_Global.h \
    Plugin/Plugin_Manger.h \
    SwSystem/System_GlobalVar.h \
    SwSystem/System_History.h \
    Widget/Widget_Button_ListItem.h \
    Widget/Widget_Button_ModHistoryItem.h \
    Widget/Widget_Button_ModItem.h \
    Widget/Widget_Button_PluginItem.h \
    Widget/Widget_Button_Start.h \
    Widget/Widget_Button_WidgetItem.h \
    Window/Form_About.h \
    Window/Form_Begin.h \
    Window/Form_Content.h \
    Window/Form_Editor.h \
    Window/Form_ListPrint.h \
    Window/Form_New.h \
    Window/Form_PluginManger.h \
    Window/Form_ProjectManger.h \
    Window/Form_TextPrint.h \
    Window/Form_VisualFolder.h \
    Window/Form_WidgetBox.h \
    Window/Form_WindowTab.h \
    Window/Form_WorkSpace.h \
    mainwindow.h \
    module/mod_WebPage.h

FORMS += \
    Widget/Widget_Button_ListItem.ui \
    Widget/Widget_Button_ModHistoryItem.ui \
    Widget/Widget_Button_ModItem.ui \
    Widget/Widget_Button_PluginItem.ui \
    Widget/Widget_Button_Start.ui \
    Widget/Widget_Button_WidgetItem.ui \
    Window/Form_About.ui \
    Window/Form_Beginui.ui \
    Window/Form_Content.ui \
    Window/Form_Editor.ui \
    Window/Form_ListPrint.ui \
    Window/Form_New.ui \
    Window/Form_PluginManger.ui \
    Window/Form_ProjectManger.ui \
    Window/Form_TextPrint.ui \
    Window/Form_VisualFolder.ui \
    Window/Form_WidgetBox.ui \
    Window/Form_WindowTab.ui \
    Window/Form_WorkSpace.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
images.qrc \
icons.qrc
