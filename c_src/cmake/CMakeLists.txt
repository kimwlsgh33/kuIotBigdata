cmake_minimum_required(VERSION 3.10)
project(cmake_example C)
# message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(${CMAKE_PROJECT_NAME})
# Release, Debug, RelWithDebInfo, MinSizeRel
set(CMAKE_BUILD_TYPE "Debug")
# You can see the all command in the build (you must write this after project() command)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(SOURCE_FILES main.c foo.c bar.c)
add_executable(app.out ${SOURCE_FILES})
# lib-foo.so, (SHARED, STATIC, MODULE), source
# add_library(foo SHARED foo.c)
# add_library(bar SHARED bar.c)
