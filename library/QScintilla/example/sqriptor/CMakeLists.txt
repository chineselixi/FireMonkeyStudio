cmake_minimum_required(VERSION 3.5)

project(Sqriptor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QScintilla_DIR ${CMAKE_BINARY_DIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)
find_package(QScintilla REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(HEADERS
    sqriptor.h
    scrollbar.h
    lexer/awk.h
    lexer/journal.h
    lexer/markdown2.h
    lexer/xorg.h
    lexer/pkgbuild.h
    lexer/xorglog.h
    lexer/nim.h
    lexer/lisp.h
    lexer/fontconfig.h
)

set(SOURCES
    sqriptor.cpp
    createui.cpp
    syntax.cpp
    filetype.cpp
    settings.cpp
    scrollbar.cpp
    lexer/awk.cpp
    lexer/journal.cpp
    lexer/markdown2.cpp
    lexer/xorg.cpp
    lexer/pkgbuild.cpp
    lexer/xorglog.cpp
    lexer/nim.cpp
    lexer/lisp.cpp
    lexer/fontconfig.cpp
)

set(PROJECT_SOURCES
    main.cpp

    ${SOURCES}
    ${HEADERS}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Sqriptor
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

       # application.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Sqriptor APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Sqriptor SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Sqriptor
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Sqriptor PRIVATE QScintilla::qscintilla2_qt${QT_VERSION_MAJOR})
target_link_libraries(Sqriptor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Sqriptor)
endif()
set_target_properties(Sqriptor PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Sqriptor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Sqriptor)
endif()
