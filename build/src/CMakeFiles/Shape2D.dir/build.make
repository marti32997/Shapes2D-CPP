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

# Include any dependencies generated for this target.
include src/CMakeFiles/Shape2D.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Shape2D.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Shape2D.dir/flags.make

src/CMakeFiles/Shape2D.dir/Shape2D.cpp.o: src/CMakeFiles/Shape2D.dir/flags.make
src/CMakeFiles/Shape2D.dir/Shape2D.cpp.o: ../src/Shape2D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Shape2D.dir/Shape2D.cpp.o"
	cd /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/src && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Shape2D.dir/Shape2D.cpp.o -c /home/yosua/Projects/Shapes2D/Shapes2D-CPP/src/Shape2D.cpp

src/CMakeFiles/Shape2D.dir/Shape2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Shape2D.dir/Shape2D.cpp.i"
	cd /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yosua/Projects/Shapes2D/Shapes2D-CPP/src/Shape2D.cpp > CMakeFiles/Shape2D.dir/Shape2D.cpp.i

src/CMakeFiles/Shape2D.dir/Shape2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Shape2D.dir/Shape2D.cpp.s"
	cd /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yosua/Projects/Shapes2D/Shapes2D-CPP/src/Shape2D.cpp -o CMakeFiles/Shape2D.dir/Shape2D.cpp.s

src/CMakeFiles/Shape2D.dir/Shape2D.cpp.o.requires:

.PHONY : src/CMakeFiles/Shape2D.dir/Shape2D.cpp.o.requires

src/CMakeFiles/Shape2D.dir/Shape2D.cpp.o.provides: src/CMakeFiles/Shape2D.dir/Shape2D.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/Shape2D.dir/build.make src/CMakeFiles/Shape2D.dir/Shape2D.cpp.o.provides.build
.PHONY : src/CMakeFiles/Shape2D.dir/Shape2D.cpp.o.provides

src/CMakeFiles/Shape2D.dir/Shape2D.cpp.o.provides.build: src/CMakeFiles/Shape2D.dir/Shape2D.cpp.o


# Object files for target Shape2D
Shape2D_OBJECTS = \
"CMakeFiles/Shape2D.dir/Shape2D.cpp.o"

# External object files for target Shape2D
Shape2D_EXTERNAL_OBJECTS =

src/libShape2D.a: src/CMakeFiles/Shape2D.dir/Shape2D.cpp.o
src/libShape2D.a: src/CMakeFiles/Shape2D.dir/build.make
src/libShape2D.a: src/CMakeFiles/Shape2D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libShape2D.a"
	cd /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Shape2D.dir/cmake_clean_target.cmake
	cd /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Shape2D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Shape2D.dir/build: src/libShape2D.a

.PHONY : src/CMakeFiles/Shape2D.dir/build

src/CMakeFiles/Shape2D.dir/requires: src/CMakeFiles/Shape2D.dir/Shape2D.cpp.o.requires

.PHONY : src/CMakeFiles/Shape2D.dir/requires

src/CMakeFiles/Shape2D.dir/clean:
	cd /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Shape2D.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Shape2D.dir/clean

src/CMakeFiles/Shape2D.dir/depend:
	cd /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yosua/Projects/Shapes2D/Shapes2D-CPP /home/yosua/Projects/Shapes2D/Shapes2D-CPP/src /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/src /home/yosua/Projects/Shapes2D/Shapes2D-CPP/build/src/CMakeFiles/Shape2D.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Shape2D.dir/depend
