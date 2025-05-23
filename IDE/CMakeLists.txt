#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#project(FMSIDE)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(ENV{PATH} "${CMAKE_CURRENT_SOURCE_DIR}")


#引用当前目录，头文件直接引入文件夹名+文件名
include_directories(./)

# 指定可执行程序输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG 	${outBuildDir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	${outBuildDir})


#复制资源文件到编译
file(COPY ${CMAKE_CURRENT_LIST_DIR}/RunConfig/ DESTINATION ${outBuildDir})

if(ANDROID)
    # 创建 assets 目录
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/android-build/assets)

    # 复制文件到 assets 目录，末尾有斜杠，那么复制的是文件夹内的内容，没有则复制这个文件夹
    file(COPY ${outBuildDir}/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/android-build/assets)

    # 配置 Android 部署
    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/android-build")
endif()


# 使用 Qt 资源系统
#qt_add_resources(your_target
#    PREFIX "/xml"
#    FILES
#        sources/android_sources/AndroidManifest.xml
#)


#message("BUILD PATH1:${CMAKE_CURRENT_LIST_DIR}/RunConfig/")
#message("BUILD PATH2:${outBuildDir}")
#message("BUILD PATH3:${CMAKE_CURRENT_BINARY_DIR}/android-build/assets")
#message("BUILD PATH4:${CMAKE_CURRENT_BINARY_DIR}/android-build")

set(PROJECT_SOURCES
    Plugin/Plugin_Base.cpp
    Plugin/Plugin_CodeEditorInterface.cpp
    Plugin/Plugin_Global.cpp
    Plugin/Plugin_Manger.cpp
    SwSystem/System_CodeEditorManger.cpp
    SwSystem/System_GlobalVar.cpp
    SwSystem/System_History.cpp
    SwSystem/System_UtilFun.cpp
    SwSystem/System_SystemSetting.cpp
    Widget/Widget_Button_ListItem.cpp
    Widget/Widget_Button_ModHistoryItem.cpp
    Widget/Widget_Button_ModItem.cpp
    Widget/Widget_Button_PluginItem.cpp
    Widget/Widget_Button_Start.cpp
    Widget/Widget_Button_WidgetItem.cpp
    Widget/Widget_Statusbar.cpp
    Widget/Widget_TipItem.cpp
    Widget/Widget_Button_HistoryItem.cpp
    Widget/Widget_HistoryList.cpp
    Widget/Widget_Button_CompletionItem.cpp
    Window/Form_About.cpp
    Window/Form_Begin.cpp
    Window/Form_CompletionTip.cpp
    Window/Form_Content.cpp
    Window/Form_Editor.cpp
    Window/Form_Index.cpp
    Window/Form_ListPrint.cpp
    Window/Form_SearchList.cpp
    Window/Form_New.cpp
    Window/Form_PluginManger.cpp
    Window/Form_ProjectManger.cpp
    Window/Form_Search.cpp
    Window/Form_SystemSettings.cpp
    Window/Form_TextPrint.cpp
    Window/Form_VisualFolder.cpp
    Window/Form_WidgetBox.cpp
    Window/Form_WindowTab.cpp
    Window/Form_WorkSpace.cpp
    Window/Form_TipManger.cpp
    Window/Form_Start.cpp
    Window/settingWindow/Form_settings_Basic.cpp
    Window/settingWindow/Form_settings_Color.cpp
    Window/settingWindow/Form_settings_DataBase.cpp
    Window/settingWindow/Form_settings_Device.cpp
    Window/settingWindow/Form_settings_Git.cpp
    Window/settingWindow/Form_settings_ProjectManger.cpp
    Window/settingWindow/Form_settings_Qt.cpp
    module/mod_settingsFormBase.cpp
    mainwindow.cpp
    main.cpp

    InterFace/InterFace_CompletionTip.h
    Plugin/Plugin_Base.h
    Plugin/Plugin_CodeEditorInterface.h
    Plugin/Plugin_Global.h
    Plugin/Plugin_Manger.h
    SwSystem/System_CodeEditorManger.h
    SwSystem/System_GlobalVar.h
    SwSystem/System_History.h
    SwSystem/System_UtilFun.h
    SwSystem/System_SystemSetting.h
    Widget/Widget_Button_ListItem.h
    Widget/Widget_Button_ModHistoryItem.h
    Widget/Widget_Button_ModItem.h
    Widget/Widget_Button_PluginItem.h
    Widget/Widget_Button_Start.h
    Widget/Widget_Button_WidgetItem.h
    Widget/Widget_Statusbar.h
    Widget/Widget_TipItem.h
    Widget/Widget_Button_HistoryItem.h
    Widget/Widget_HistoryList.h
    Widget/Widget_Button_CompletionItem.h
    Window/Form_About.h
    Window/Form_Begin.h
    Window/Form_CompletionTip.h
    Window/Form_Content.h
    Window/Form_Editor.h
    Window/Form_Index.h
    Window/Form_ListPrint.h
    Window/Form_SearchList.h
    Window/Form_New.h
    Window/Form_PluginManger.h
    Window/Form_ProjectManger.h
    Window/Form_Search.h
    Window/Form_SystemSettings.h
    Window/Form_TextPrint.h
    Window/Form_VisualFolder.h
    Window/Form_WidgetBox.h
    Window/Form_WindowTab.h
    Window/Form_WorkSpace.h
    Window/Form_TipManger.h
    Window/Form_Start.h
    Window/settingWindow/Form_settings_Basic.h
    Window/settingWindow/Form_settings_Color.h
    Window/settingWindow/Form_settings_DataBase.h
    Window/settingWindow/Form_settings_Device.h
    Window/settingWindow/Form_settings_Git.h
    Window/settingWindow/Form_settings_ProjectManger.h
    Window/settingWindow/Form_settings_Qt.h
    mainwindow.h
    module/mod_settingsFormBase.h

    Widget/Widget_Button_ListItem.ui
    Widget/Widget_Button_ModHistoryItem.ui
    Widget/Widget_Button_ModItem.ui
    Widget/Widget_Button_PluginItem.ui
    Widget/Widget_Button_Start.ui
    Widget/Widget_Button_WidgetItem.ui
    Widget/Widget_Statusbar.ui
    Widget/Widget_TipItem.ui
    Widget/Widget_Button_HistoryItem.ui
    Widget/Widget_HistoryList.ui
    Widget/Widget_Button_CompletionItem.ui
    Window/Form_About.ui
    Window/Form_Beginui.ui
    Window/Form_CompletionTip.ui
    Window/Form_Content.ui
    Window/Form_Editor.ui
    Window/Form_Index.ui
    Window/Form_ListPrint.ui
    Window/Form_SearchList.ui
    Window/Form_New.ui
    Window/Form_PluginManger.ui
    Window/Form_ProjectManger.ui
    Window/Form_Search.ui
    Window/Form_SystemSettings.ui
    Window/Form_TextPrint.ui
    Window/Form_VisualFolder.ui
    Window/Form_WidgetBox.ui
    Window/Form_WindowTab.ui
    Window/Form_WorkSpace.ui
    Window/Form_TipManger.ui
    Window/Form_Start.ui
    Window/settingWindow/Form_settings_Basic.ui
    Window/settingWindow/Form_settings_Color.ui
    Window/settingWindow/Form_settings_DataBase.ui
    Window/settingWindow/Form_settings_Device.ui
    Window/settingWindow/Form_settings_Git.ui
    Window/settingWindow/Form_settings_ProjectManger.ui
    Window/settingWindow/Form_settings_Qt.ui
#    mainwindow.ui

    icons.qrc
    res.qrc
)



qt_add_resources(ide "images"
    PREFIX "/images"
    FILES sources/android_sources/AndroidManifest.xml)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ide
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ide APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ide SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ide
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ide PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ide)
endif()
set_target_properties(ide PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ide
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ide)
endif()
