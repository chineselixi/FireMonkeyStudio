

#引用当前目录，头文件直接引入文件夹名+文件名
include_directories(./)
include_directories(../../library/QScintilla/src/Qsci)

#add_subdirectory(../../library/QScintilla/src/Qsci)

#add_subdirectory(E:\QtProject\FMS_CMake\library\QScintilla)

# 指定可执行程序输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG 	${outBuildDir}/plg/Plugin_CppBase)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	${outBuildDir}/plg/Plugin_CppBase)


add_library(Plugin_CppBase SHARED
	Form/Form_Attribute.ui
	Form/Form_CodeEditor.ui
	Form/settingForm/Form_settings_Clangd.ui
	Form/settingForm/Form_settings_Compile.ui
	Form/settingForm/Widget/Widget_List.ui
	Form/Form_Attributee.h
	Form/Form_CodeEditor.h
	Form/settingForm/Form_settings_Clangd.h
	Form/settingForm/Form_settings_Compile.h
	Form/settingForm/Widget/Widget_List.h
	Plugin_CppBase_global.h
	Plugin_CppBase.h
	Widget/Widget_SciCodeEditor.h
	util/GccUtil.h 
	util/LspClient.h
	Form/Form_Attribute.cpp
	Form/Form_CodeEditor.cpp
	Form/settingForm/Form_settings_Clangd.cpp
	Form/settingForm/Form_settings_Compile.cpp
	Form/settingForm/Widget/Widget_List.cpp
	Plugin_CppBase.cpp
	Widget/Widget_SciCodeEditor.cpp
	util/GccUtil.cpp
	util/LspClient.cpp
	res.qrc
)


target_link_libraries(Plugin_CppBase PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Plugin_CppBase PUBLIC qscintilla2_qt6d.dll)
#target_link_libraries(Plugin_CppBase PRIVATE qscintilla2_qt${Qt_VERSION_MAJOR})


target_compile_definitions(Plugin_CppBase PRIVATE PLUGIN_CPPBASE_LIBRARY)
