QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    SwSystem/System_DirWatcher.cpp \
    SwSystem/System_UtilFun.cpp \
    Window/Form_ProjectManger.cpp

HEADERS += \
    SwSystem/System_DirWatcher.h \
    SwSystem/System_UtilFun.cpp \
    Window/Form_ProjectManger.h

FORMS += \
    Window/Form_ProjectManger.ui

RESOURCES += \
    icons.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
