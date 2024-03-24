QT += widgets

TEMPLATE = lib
DEFINES += PLUGIN_CPPBASE_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


DESTDIR = $$OUT_PWD/../../release/plg/Plugin_CppBase/
TARGET = Plugin_CppBase


SOURCES += \
    Form/Form_Attribute.cpp \
    Form/Form_CodeEditor.cpp \
    Form/settingForm/Form_settings_Compile.cpp \
    Form/settingForm/Widget/Widget_List.cpp \
    Plugin_CppBase.cpp \
    util/GccUtil.cpp

HEADERS += \
    Form/Form_Attributee.h \
    Form/Form_CodeEditor.h \
    Form/settingForm/Form_settings_Compile.h \
    Form/settingForm/Widget/Widget_List.h \
    Plugin_CppBase_global.h \
    Plugin_CppBase.h \
    util/GccUtil.h

FORMS += \
    Form/Form_Attribute.ui \
    Form/Form_CodeEditor.ui \
    Form/settingForm/Form_settings_Compile.ui \
    Form/settingForm/Widget/Widget_List.ui

RESOURCES += \
    res.qrc



# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target



#load qsciscintilla
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../release/ -lqscintilla
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../release/ -lqscintillad
else:unix: LIBS += -L$$OUT_PWD/../../release/ -lqscintilla

INCLUDEPATH += $$OUT_PWD/../../release
DEPENDPATH += $$OUT_PWD/../../release


