cmake_minimum_required(VERSION 3.12)
project(file)

set(CMAKE_CXX_STANDARD 17)

add_executable(file main.cpp file.cpp file.h mydiff.cpp myls.cpp mycat.cpp mystat.cpp)