QT += widgets

TEMPLATE = lib
DEFINES += PLUGIN_GCCBUILD_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#输出的文件路径
DESTDIR = $$OUT_PWD/../../release/plg/plugin_GccBuild
#输出的文件名
TARGET = plg_gccBuild


SOURCES += \
    Form_CheckGCC.cpp \
    plugin_gccbuild.cpp

HEADERS += \
    Form_CheckGCC.h \
    plugin_GccBuild_global.h \
    plugin_gccbuild.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    Form_CheckGCC.ui

RESOURCES += \
    res.qrc
