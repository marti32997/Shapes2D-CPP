cmake_minimum_required(VERSION 3.10)
project(CSCI251_A2)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libs/Catch2/contrib" ${CMAKE_MODULE_PATH})

include_directories(include)
add_subdirectory(src)
add_subdirectory(libs/Catch2)

enable_testing()
add_subdirectory(tests)

# add_subdirectory(docs)