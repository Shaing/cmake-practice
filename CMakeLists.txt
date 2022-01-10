CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(HelloWorld_Lib)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/inc)
ADD_LIBRARY(helloworld_lib SHARED src/hw.cpp)

add_executable(sc main.cpp)
target_link_libraries(sc PRIVATE helloworld_lib)

