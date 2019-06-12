cmake_minimum_required(VERSION 3.10)
project(raycons)

set(CMAKE_CXX_STANDARD 11)

add_executable(raycons lib.cpp)
target_link_libraries(raycons raylib)