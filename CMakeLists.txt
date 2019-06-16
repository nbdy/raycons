cmake_minimum_required(VERSION 3.10)
project(raycons)

set(CMAKE_CXX_STANDARD 11)

add_executable(raycons main.cpp Icons.h)
target_link_libraries(raycons raylib dl)