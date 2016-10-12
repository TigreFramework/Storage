cmake_minimum_required(VERSION 3.4)
project(Storage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(LIBRARY_FILES File.cpp File.h)
set(SOURCE_FILES main.cpp ${LIBRARY_FILES})
add_executable(Storage_teste ${SOURCE_FILES})
add_library(Storage STATIC ${LIBRARY_FILES})