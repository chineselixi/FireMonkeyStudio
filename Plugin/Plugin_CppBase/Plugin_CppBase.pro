QT += widgets

TEMPLATE = lib
DEFINES += PLUGIN_CPPBASE_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


DESTDIR = $$OUT_PWD/../../release/plg/Plugin_CppBase
TARGET = Plugin_CppBase


SOURCES += \
    Plugin_CppBase.cpp

HEADERS += \
    Plugin_CppBase_global.h \
    Plugin_CppBase.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
