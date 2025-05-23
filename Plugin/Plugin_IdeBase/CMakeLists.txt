

#引用当前目录，头文件直接引入文件夹名+文件名
include_directories(./)

# 格局操作系统设定输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG 	${outBuildDir}/plg/Plugin_IdeBase)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	${outBuildDir}/plg/Plugin_IdeBase)


add_library(Plugin_ideBase SHARED
	Form/Form_Terminal.ui
	Dialog/Dialog_Index.ui

	Form/Form_Terminal.h
	Form/Form_Terminal.cpp
    	Widget/Widget_TextEdit.h
	Widget/Widget_TextEdit.cpp
    	util/InputList.h
	util/InputList.cpp
    	Dialog/Dialog_Index.h
	Dialog/Dialog_Index.cpp
    	plugin_IdeBase_global.h
	Dialog/Dialog_Index.cpp
    	Plugin_IdeBase.h
	Plugin_IdeBase.cpp

	res.qrc
)

target_compile_definitions(Plugin_ideBase PRIVATE PLUGIN_IDEBASE_LIBRARY)
target_link_libraries(Plugin_ideBase PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


