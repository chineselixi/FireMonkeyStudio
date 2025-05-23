find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

#-------------------------------------- 包含头文件 --------------------------------------
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../library/QScintilla/src)

#-------------------------------------- 引入库文件 --------------------------------------
link_directories(${outBuildDir})



add_subdirectory(Plugin_IdeBase)
#add_subdirectory(Plugin_CppBase)
