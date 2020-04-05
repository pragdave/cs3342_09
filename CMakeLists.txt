cmake_minimum_required(VERSION 3.15)
project(20S-3353-PA02)
set (EXE_NAME runMe)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")
add_executable(${EXE_NAME} main.cpp)