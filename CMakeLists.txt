cmake_minimum_required(VERSION 3.5)

project(FMS VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#使用C++17标准
set(CMAKE_CXX_STANDARD 17)
#强制要求此C++标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#开启额外语法支持
set(CMAKE_CXX_EXTENSIONS ON)


#设定当前构建输出目录
set(outBuildDir ${CMAKE_BINARY_DIR}/build)


#设置输出目录
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUT_BUILD_DIR}/lib)


add_subdirectory(library)
add_subdirectory(plugin)
add_subdirectory(ide)


message("OUT_BUILD_DIR:${OUT_BUILD_DIR}")



