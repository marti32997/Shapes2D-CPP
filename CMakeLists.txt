cmake_minimum_required(VERSION 3.11)
project(CSCI251_A2)

# add_compile_options(--coverage)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")

option(CODE_COVERAGE "Enable Code Coverage" OFF)
if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|CLANG")
	include(CodeCoverage)
endif()

include_directories(include)
add_subdirectory(src)
add_subdirectory(libs)
enable_testing()
add_subdirectory(tests)

option(BUILD_WITH_DOCS "Enable docs generation" OFF)
if(BUILD_WITH_DOCS)
	add_subdirectory(docs)
endif()
