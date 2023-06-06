QT += widgets

TEMPLATE = lib
DEFINES += PLUGIN_IDEBASIC_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#输出的文件路径
DESTDIR = ../../release/plg/plugin_ideBasic
#输出的文件名
TARGET = plg_ideBasic


SOURCES += \
    CodeEditor/CodeEditor.cpp \
    CodeEditor/GccMsgFormat.cpp \
    CodeEditor/globalValue.cpp \
    module/mod_HeighLightEditor.cpp \
    module/mod_TipList.cpp \
    Plugin_ideBasic.cpp


HEADERS += \
    CodeEditor/CodeEditor.h \
    CodeEditor/GccMsgFormat.h \
    CodeEditor/globalValue.h \
    module/mod_HeighLightEditor.h \
    module/mod_TipList.h \
    plugin_ideBasic_global.h \
    Plugin_ideBasic.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
