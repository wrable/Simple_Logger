cmake_minimum_required(VERSION 2.8.11)

include_directories(${CPPUTEST_SRC_DIR})
include_directories(${CPPUTESTEXT_SRC_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)

set(SOURCE_FILES
    main.cpp
    ${PROJECT_SOURCE_DIR}/src/logger.cpp
    logger_ut.cpp
)

add_executable(logger_ut ${SOURCE_FILES})
target_link_libraries(logger_ut CppUTest CppUTestExt)

add_test(logger_test logger_ut)

