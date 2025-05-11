TEMPLATE = subdirs


#编译成功后的输出目录
OUTPUTPATH = $${OUT_PWD}/build/output

export(OUTPUTPATH)

message(outDESTDIR1 $${OUTPUTPATH})



# 加上ordered配置就可以按顺序编译SUBDIRS,必须加在SUBDIRS的前面
CONFIG += ordered



SUBDIRS += \
#    QScintilla/src/QScintilla.pro \
    IDE \
    Plugin






