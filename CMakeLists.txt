cmake_minimum_required(VERSION 3.10)
project(raycons)

set(CMAKE_CXX_STANDARD 11)

add_executable(raycons main.cpp Icons.h)

if(EXISTS "/sys/firmware/devicetree/base/model")
    target_link_libraries(raycons raylib dl)
else()
    target_link_libraries(raycons raylib dl X11)
endif()
