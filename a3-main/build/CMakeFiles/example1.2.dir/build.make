# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wm0395/COL781_Assignments/a3-main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wm0395/COL781_Assignments/a3-main/build

# Include any dependencies generated for this target.
include CMakeFiles/example1.2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/example1.2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/example1.2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example1.2.dir/flags.make

CMakeFiles/example1.2.dir/examples/example1.2.cpp.o: CMakeFiles/example1.2.dir/flags.make
CMakeFiles/example1.2.dir/examples/example1.2.cpp.o: ../examples/example1.2.cpp
CMakeFiles/example1.2.dir/examples/example1.2.cpp.o: CMakeFiles/example1.2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wm0395/COL781_Assignments/a3-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/example1.2.dir/examples/example1.2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/example1.2.dir/examples/example1.2.cpp.o -MF CMakeFiles/example1.2.dir/examples/example1.2.cpp.o.d -o CMakeFiles/example1.2.dir/examples/example1.2.cpp.o -c /home/wm0395/COL781_Assignments/a3-main/examples/example1.2.cpp

CMakeFiles/example1.2.dir/examples/example1.2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example1.2.dir/examples/example1.2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wm0395/COL781_Assignments/a3-main/examples/example1.2.cpp > CMakeFiles/example1.2.dir/examples/example1.2.cpp.i

CMakeFiles/example1.2.dir/examples/example1.2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example1.2.dir/examples/example1.2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wm0395/COL781_Assignments/a3-main/examples/example1.2.cpp -o CMakeFiles/example1.2.dir/examples/example1.2.cpp.s

# Object files for target example1.2
example1_2_OBJECTS = \
"CMakeFiles/example1.2.dir/examples/example1.2.cpp.o"

# External object files for target example1.2
example1_2_EXTERNAL_OBJECTS =

example1.2: CMakeFiles/example1.2.dir/examples/example1.2.cpp.o
example1.2: CMakeFiles/example1.2.dir/build.make
example1.2: liba3.a
example1.2: /usr/lib/x86_64-linux-gnu/libSDL2.so
example1.2: CMakeFiles/example1.2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wm0395/COL781_Assignments/a3-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example1.2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example1.2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example1.2.dir/build: example1.2
.PHONY : CMakeFiles/example1.2.dir/build

CMakeFiles/example1.2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example1.2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example1.2.dir/clean

CMakeFiles/example1.2.dir/depend:
	cd /home/wm0395/COL781_Assignments/a3-main/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wm0395/COL781_Assignments/a3-main /home/wm0395/COL781_Assignments/a3-main /home/wm0395/COL781_Assignments/a3-main/build /home/wm0395/COL781_Assignments/a3-main/build /home/wm0395/COL781_Assignments/a3-main/build/CMakeFiles/example1.2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example1.2.dir/depend

