TEMPLATE = subdirs

SUBDIRS += \
    subObject/QScintilla/src/qscintilla.pro \
    subObject/mainPlugin/plugin_cppBasic.pro

# 加上ordered配置就可以按顺序编译SUBDIRS
CONFIG += ordered
