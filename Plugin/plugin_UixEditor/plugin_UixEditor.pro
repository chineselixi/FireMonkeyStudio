QT += widgets

TEMPLATE = lib
DEFINES += PLUGIN_UIXEDITOR_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Widget/Widget_Button_WidgetItem.cpp \
    Window/Form_EditorSpace.cpp \
    Window/Form_WidgetBox.cpp \
    plugin_uixeditor.cpp

HEADERS += \
    Widget/Widget_Button_WidgetItem.h \
    Window/Form_EditorSpace.h \
    Window/Form_WidgetBox.h \
    plugin_UixEditor_global.h \
    plugin_uixeditor.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    Widget/Widget_Button_WidgetItem.ui \
    Window/Form_EditorSpace.ui \
    Window/Form_WidgetBox.ui

RESOURCES += \
    res.qrc
