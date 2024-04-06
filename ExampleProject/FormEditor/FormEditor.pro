QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GlobalMsg.cpp \
    Plugins/Plugin_Base.cpp \
    Plugins/Plugin_Button.cpp \
    Plugins/Plugin_MainWindow.cpp \
    Plugins/Plugin_TabWidget.cpp \
    Plugins/Plugin_Label.cpp \
    Widgets/Widget_Button_WidgetItem.cpp \
    Widgets/Widget_MdiArea.cpp \
    Widgets/Widget_widgetList.cpp \
    Forms/Form_EditorSpace.cpp \
    Forms/Form_Roi.cpp \
    Forms/Form_PropertyEditor.cpp \
    Forms/Form_WidgetBox.cpp \
    main.cpp \
    qtpropertybrowser/qtbuttonpropertybrowser.cpp \
    qtpropertybrowser/qteditorfactory.cpp \
    qtpropertybrowser/qtgroupboxpropertybrowser.cpp \
    qtpropertybrowser/qtpropertybrowser.cpp \
    qtpropertybrowser/qtpropertybrowserutils.cpp \
    qtpropertybrowser/qtpropertymanager.cpp \
    qtpropertybrowser/qttreepropertybrowser.cpp \
    qtpropertybrowser/qtvariantproperty.cpp \
    util/FunUtil.cpp

HEADERS += \
    GlobalMsg.h \
    Plugins/Plugin_Base.h \
    Plugins/Plugin_Button.h \
    Plugins/Plugin_MainWindow.h \
    Plugins/Plugin_TabWidget.h \
    Plugins/Plugin_Label.h \
    Widgets/Widget_Button_WidgetItem.h \
    Widgets/Widget_MdiArea.h \
    Widgets/Widget_widgetList.h \
    Forms/Form_EditorSpace.h \
    Forms/Form_Roi.h \
    Forms/Form_PropertyEditor.h \
    Forms/Form_WidgetBox.h \
    qtpropertybrowser/qtbuttonpropertybrowser.h \
    qtpropertybrowser/qteditorfactory.h \
    qtpropertybrowser/qtgroupboxpropertybrowser.h \
    qtpropertybrowser/qtpropertybrowser.h \
    qtpropertybrowser/qtpropertybrowserutils_p.h \
    qtpropertybrowser/qtpropertymanager.h \
    qtpropertybrowser/qttreepropertybrowser.h \
    qtpropertybrowser/qtvariantproperty.h \
    util/FunUtil.h

FORMS += \
    Widgets/Widget_Button_WidgetItem.ui \
    Widgets/Widget_widgetList.ui \
    Forms/Form_EditorSpace.ui \
    Forms/Form_Roi.ui \
    Forms/Form_PropertyEditor.ui \
    Forms/Form_WidgetBox.ui \

RESOURCES += \
    res.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
