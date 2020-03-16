cmake_minimum_required(VERSION 3.15)
project(CSCI251_A2)

include_directories(include)
add_subdirectory(src)

add_subdirectory(libs)
enable_testing()
add_subdirectory(tests)

# add_subdirectory(docs)