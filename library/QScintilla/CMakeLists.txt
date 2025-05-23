cmake_minimum_required(VERSION 3.10)

# Project name
project(QScintilla VERSION 15.1.1 LANGUAGES CXX)

# CMake settings
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_EXAMPLE OFF)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG 	${outBuildDir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	${outBuildDir})



# Find Qt packages
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Gui PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Gui PrintSupport)

# Add subdirectory
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Set target name
if(WIN32)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(TARGET_NAME qscintilla2_qt${QT_VERSION_MAJOR}d)
    else()
        set(TARGET_NAME qscintilla2_qt${QT_VERSION_MAJOR})
    endif()
else()
    set(TARGET_NAME qscintilla2_qt${QT_VERSION_MAJOR})
endif()

# Define the library
add_library(${TARGET_NAME} SHARED
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

# macOS settings
if(MACOS)
    if(NOT BUILD_STATIC_LIBS)
        set_target_properties(${TARGET_NAME} PROPERTIES
            MACOSX_RPATH ON
            INSTALL_NAME_DIR "@rpath"
        )
    endif()
endif() 

# Set library version
set_target_properties(${TARGET_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Link libraries
target_link_libraries(${TARGET_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(${TARGET_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::PrintSupport)

# Compile definitions
target_compile_definitions(${TARGET_NAME} PRIVATE QSCINTILLA_MAKE_DLL)

# Include directories
target_include_directories(${TARGET_NAME} PRIVATE
    ${Qt${QT_VERSION_MAJOR}Core_INCLUDE_DIRS}
    ${Qt${QT_VERSION_MAJOR}Widgets_INCLUDE_DIRS}
    ${Qt${QT_VERSION_MAJOR}PrintSupport_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/scintilla/include
    ${CMAKE_CURRENT_SOURCE_DIR}/scintilla/src
    ${CMAKE_CURRENT_SOURCE_DIR}/scintilla/lexlib
)

message(STATUS "Qt${QT_VERSION_MAJOR}Core_INCLUDE_DIRS: ${Qt${QT_VERSION_MAJOR}Core_INCLUDE_DIRS}")
message(STATUS "Qt${QT_VERSION_MAJOR}Widgets_INCLUDE_DIRS: ${Qt${QT_VERSION_MAJOR}Widgets_INCLUDE_DIRS}")
message(STATUS "Qt${QT_VERSION_MAJOR}PrintSupport_INCLUDE_DIRS: ${Qt${QT_VERSION_MAJOR}PrintSupport_INCLUDE_DIRS}")

# Install path
if(NOT CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Install path" FORCE)
endif()

# Set include directories
set(QScintilla_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src CACHE PATH "QScintilla include directory")

# Install targets
install(TARGETS ${TARGET_NAME}
    EXPORT QScintillaTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Install header files
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/Qsci
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

# Create and install CMake package configuration files
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/QScintillaConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/QScintillaConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/QScintillaConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/QScintilla"
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/QScintillaConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/QScintillaConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/QScintilla"
)

# Export targets for other projects to find
export(EXPORT QScintillaTargets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/QScintillaTargets.cmake"
    NAMESPACE QScintilla::
)

install(EXPORT QScintillaTargets
    FILE QScintillaTargets.cmake
    NAMESPACE QScintilla::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/QScintilla"
)

if(BUILD_EXAMPLE)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/example)
endif()
