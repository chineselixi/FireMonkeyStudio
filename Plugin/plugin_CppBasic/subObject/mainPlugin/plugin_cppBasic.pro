QT += widgets

TEMPLATE = lib
DEFINES += PLUGIN_IDEBASIC_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#输出的文件路径.
DESTDIR = ../../../../release/plg/plugin_cppBasic
#输出的文件名.
TARGET = plg_cppBasic


SOURCES += \
    Plugin_cppBasic.cpp


HEADERS += \
    Plugin_cppBasic.h \
    plugin_cppBasic_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc



#添加外部代码编辑器支持库.
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../release/lib/ -lqscintilla
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../release/lib/ -lqscintillad
else:unix: LIBS += -L$$PWD/../../../../release/lib/ -lqscintilla

INCLUDEPATH += $$PWD/../../../../release
DEPENDPATH += $$PWD/../../../../release
