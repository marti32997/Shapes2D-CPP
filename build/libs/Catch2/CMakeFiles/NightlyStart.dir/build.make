# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yosua/Projects/Shapes2D/Shapes2D-CPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build

# Utility rule file for NightlyStart.

# Include the progress variables for this target.
include libs/Catch2/CMakeFiles/NightlyStart.dir/progress.make

libs/Catch2/CMakeFiles/NightlyStart:
	cd /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/libs/Catch2 && /usr/bin/ctest -D NightlyStart

NightlyStart: libs/Catch2/CMakeFiles/NightlyStart
NightlyStart: libs/Catch2/CMakeFiles/NightlyStart.dir/build.make

.PHONY : NightlyStart

# Rule to build all files generated by this target.
libs/Catch2/CMakeFiles/NightlyStart.dir/build: NightlyStart

.PHONY : libs/Catch2/CMakeFiles/NightlyStart.dir/build

libs/Catch2/CMakeFiles/NightlyStart.dir/clean:
	cd /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/libs/Catch2 && $(CMAKE_COMMAND) -P CMakeFiles/NightlyStart.dir/cmake_clean.cmake
.PHONY : libs/Catch2/CMakeFiles/NightlyStart.dir/clean

libs/Catch2/CMakeFiles/NightlyStart.dir/depend:
	cd /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yosua/Projects/Shapes2D/Shapes2D-CPP /home/yosua/Projects/Shapes2D/Shapes2D-CPP/libs/Catch2 /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/libs/Catch2 /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/libs/Catch2/CMakeFiles/NightlyStart.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/Catch2/CMakeFiles/NightlyStart.dir/depend

