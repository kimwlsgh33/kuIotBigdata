cmake_minimum_required(VERSION 3.0)

# ${PROJECT_NAME} = target file
project(booklist)

find_library(MYSQL mysqlclient)

# specify target file and source file
add_executable(${PROJECT_NAME}.out booklist.c)

# include header files of library to target
target_include_directories(${PROJECT_NAME}.out PUBLIC /usr/include/mysql)

# link libraries to target
target_link_libraries(${PROJECT_NAME}.out ${MYSQL})

# package 형식의 라이브러리 => the most simple way