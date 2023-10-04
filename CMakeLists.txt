project(HelloWorld)
cmake_minimum_required(VERSION 3.0)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(hello_world main.cpp)
target_link_libraries(hello_world ${OpenCV_LIBS})