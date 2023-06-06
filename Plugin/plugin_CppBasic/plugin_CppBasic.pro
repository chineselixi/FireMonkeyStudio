TEMPLATE = subdirs

SUBDIRS += \
    subObject/QScintilla/src/qscintilla.pro \
    subObject/mainPlugin/plugin_ideBasic.pro

# 加上ordered配置就可以按顺序编译SUBDIRS
CONFIG += ordered
