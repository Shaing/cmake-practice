CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(HelloWorld_Lib)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/inc)
ADD_LIBRARY(hw_lib SHARED src/hw.cpp)

add_executable(sc main.cpp)
target_link_libraries(sc PRIVATE hw_lib)

