cmake_minimum_required(VERSION 3.5)

project (functional_streambuf)

set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(SOURCES src/func_example.cpp)

add_executable(func_example ${SOURCES})

target_include_directories(func_example
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
