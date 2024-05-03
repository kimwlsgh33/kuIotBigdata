cmake_minimum_required(VERSION 3.20)
project(HelloWorld)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(OpenCV_DIR "/opt/homebrew/Cellar/opencv/4.9.0_8")
set(OpenCV_INCLUDE_DIRS "/opt/homebrew/Cellar/opencv/4.9.0_8/include")

# find_library: find OpenCV's object files
# find_package: find OpenCV's CMakeLists.txt
find_package(PkgConfig REQUIRED)
find_package(OpenCV REQUIRED opencv4)

add_executable(helloworld helloworld.cpp)
target_link_libraries(helloworld ${OpenCV_LIBS})

# header
target_include_directories(helloworld PUBLIC ${OpenCV_LIB_DIR})
