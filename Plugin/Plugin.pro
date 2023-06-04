TEMPLATE = subdirs


SUBDIRS += \
    plugin_GccBuild \
    plugin_ideBasic \
    plugin_UixEditor

# 加上ordered配置就可以按顺序编译SUBDIRS
CONFIG += ordered



