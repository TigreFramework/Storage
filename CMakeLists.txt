cmake_minimum_required(VERSION 3.4)
project(Storage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp File.cpp File.h)
add_executable(Storage ${SOURCE_FILES})