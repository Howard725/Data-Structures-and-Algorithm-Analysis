cmake_minimum_required(VERSION 3.3)
project(list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES List.h List.c main.c)
add_executable(list ${SOURCE_FILES})