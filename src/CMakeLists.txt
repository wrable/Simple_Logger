cmake_minimum_required(VERSION 2.8.11)

project(Logger_example_Logger)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp logger.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Logger_example_Logger ${SOURCE_FILES})


