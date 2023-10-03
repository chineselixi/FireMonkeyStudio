TEMPLATE = subdirs


# 加上ordered配置就可以按顺序编译SUBDIRS,必须加在SUBDIRS的前面

CONFIG += ordered


SUBDIRS += \
    QScintilla/src/QScintilla.pro \
    IDE \
    Plugin






