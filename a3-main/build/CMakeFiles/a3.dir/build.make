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
CMAKE_SOURCE_DIR = /home/kanav/COL781/COL781_Assignments/a3-main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kanav/COL781/COL781_Assignments/a3-main/build

# Include any dependencies generated for this target.
include CMakeFiles/a3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/a3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/a3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a3.dir/flags.make

CMakeFiles/a3.dir/src/Scene.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/src/Scene.cpp.o: ../src/Scene.cpp
CMakeFiles/a3.dir/src/Scene.cpp.o: CMakeFiles/a3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanav/COL781/COL781_Assignments/a3-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a3.dir/src/Scene.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a3.dir/src/Scene.cpp.o -MF CMakeFiles/a3.dir/src/Scene.cpp.o.d -o CMakeFiles/a3.dir/src/Scene.cpp.o -c /home/kanav/COL781/COL781_Assignments/a3-main/src/Scene.cpp

CMakeFiles/a3.dir/src/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/src/Scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanav/COL781/COL781_Assignments/a3-main/src/Scene.cpp > CMakeFiles/a3.dir/src/Scene.cpp.i

CMakeFiles/a3.dir/src/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/src/Scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanav/COL781/COL781_Assignments/a3-main/src/Scene.cpp -o CMakeFiles/a3.dir/src/Scene.cpp.s

CMakeFiles/a3.dir/src/Shape.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/src/Shape.cpp.o: ../src/Shape.cpp
CMakeFiles/a3.dir/src/Shape.cpp.o: CMakeFiles/a3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanav/COL781/COL781_Assignments/a3-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/a3.dir/src/Shape.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a3.dir/src/Shape.cpp.o -MF CMakeFiles/a3.dir/src/Shape.cpp.o.d -o CMakeFiles/a3.dir/src/Shape.cpp.o -c /home/kanav/COL781/COL781_Assignments/a3-main/src/Shape.cpp

CMakeFiles/a3.dir/src/Shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/src/Shape.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanav/COL781/COL781_Assignments/a3-main/src/Shape.cpp > CMakeFiles/a3.dir/src/Shape.cpp.i

CMakeFiles/a3.dir/src/Shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/src/Shape.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanav/COL781/COL781_Assignments/a3-main/src/Shape.cpp -o CMakeFiles/a3.dir/src/Shape.cpp.s

CMakeFiles/a3.dir/src/Camera.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/src/Camera.cpp.o: ../src/Camera.cpp
CMakeFiles/a3.dir/src/Camera.cpp.o: CMakeFiles/a3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanav/COL781/COL781_Assignments/a3-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/a3.dir/src/Camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a3.dir/src/Camera.cpp.o -MF CMakeFiles/a3.dir/src/Camera.cpp.o.d -o CMakeFiles/a3.dir/src/Camera.cpp.o -c /home/kanav/COL781/COL781_Assignments/a3-main/src/Camera.cpp

CMakeFiles/a3.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/src/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanav/COL781/COL781_Assignments/a3-main/src/Camera.cpp > CMakeFiles/a3.dir/src/Camera.cpp.i

CMakeFiles/a3.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/src/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanav/COL781/COL781_Assignments/a3-main/src/Camera.cpp -o CMakeFiles/a3.dir/src/Camera.cpp.s

CMakeFiles/a3.dir/src/Lighting.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/src/Lighting.cpp.o: ../src/Lighting.cpp
CMakeFiles/a3.dir/src/Lighting.cpp.o: CMakeFiles/a3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanav/COL781/COL781_Assignments/a3-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/a3.dir/src/Lighting.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a3.dir/src/Lighting.cpp.o -MF CMakeFiles/a3.dir/src/Lighting.cpp.o.d -o CMakeFiles/a3.dir/src/Lighting.cpp.o -c /home/kanav/COL781/COL781_Assignments/a3-main/src/Lighting.cpp

CMakeFiles/a3.dir/src/Lighting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/src/Lighting.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanav/COL781/COL781_Assignments/a3-main/src/Lighting.cpp > CMakeFiles/a3.dir/src/Lighting.cpp.i

CMakeFiles/a3.dir/src/Lighting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/src/Lighting.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanav/COL781/COL781_Assignments/a3-main/src/Lighting.cpp -o CMakeFiles/a3.dir/src/Lighting.cpp.s

CMakeFiles/a3.dir/src/Material.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/src/Material.cpp.o: ../src/Material.cpp
CMakeFiles/a3.dir/src/Material.cpp.o: CMakeFiles/a3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanav/COL781/COL781_Assignments/a3-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/a3.dir/src/Material.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a3.dir/src/Material.cpp.o -MF CMakeFiles/a3.dir/src/Material.cpp.o.d -o CMakeFiles/a3.dir/src/Material.cpp.o -c /home/kanav/COL781/COL781_Assignments/a3-main/src/Material.cpp

CMakeFiles/a3.dir/src/Material.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/src/Material.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanav/COL781/COL781_Assignments/a3-main/src/Material.cpp > CMakeFiles/a3.dir/src/Material.cpp.i

CMakeFiles/a3.dir/src/Material.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/src/Material.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanav/COL781/COL781_Assignments/a3-main/src/Material.cpp -o CMakeFiles/a3.dir/src/Material.cpp.s

CMakeFiles/a3.dir/deps/src/gl.c.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/deps/src/gl.c.o: ../deps/src/gl.c
CMakeFiles/a3.dir/deps/src/gl.c.o: CMakeFiles/a3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanav/COL781/COL781_Assignments/a3-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/a3.dir/deps/src/gl.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/a3.dir/deps/src/gl.c.o -MF CMakeFiles/a3.dir/deps/src/gl.c.o.d -o CMakeFiles/a3.dir/deps/src/gl.c.o -c /home/kanav/COL781/COL781_Assignments/a3-main/deps/src/gl.c

CMakeFiles/a3.dir/deps/src/gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/a3.dir/deps/src/gl.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kanav/COL781/COL781_Assignments/a3-main/deps/src/gl.c > CMakeFiles/a3.dir/deps/src/gl.c.i

CMakeFiles/a3.dir/deps/src/gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/a3.dir/deps/src/gl.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kanav/COL781/COL781_Assignments/a3-main/deps/src/gl.c -o CMakeFiles/a3.dir/deps/src/gl.c.s

# Object files for target a3
a3_OBJECTS = \
"CMakeFiles/a3.dir/src/Scene.cpp.o" \
"CMakeFiles/a3.dir/src/Shape.cpp.o" \
"CMakeFiles/a3.dir/src/Camera.cpp.o" \
"CMakeFiles/a3.dir/src/Lighting.cpp.o" \
"CMakeFiles/a3.dir/src/Material.cpp.o" \
"CMakeFiles/a3.dir/deps/src/gl.c.o"

# External object files for target a3
a3_EXTERNAL_OBJECTS =

liba3.a: CMakeFiles/a3.dir/src/Scene.cpp.o
liba3.a: CMakeFiles/a3.dir/src/Shape.cpp.o
liba3.a: CMakeFiles/a3.dir/src/Camera.cpp.o
liba3.a: CMakeFiles/a3.dir/src/Lighting.cpp.o
liba3.a: CMakeFiles/a3.dir/src/Material.cpp.o
liba3.a: CMakeFiles/a3.dir/deps/src/gl.c.o
liba3.a: CMakeFiles/a3.dir/build.make
liba3.a: CMakeFiles/a3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanav/COL781/COL781_Assignments/a3-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library liba3.a"
	$(CMAKE_COMMAND) -P CMakeFiles/a3.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a3.dir/build: liba3.a
.PHONY : CMakeFiles/a3.dir/build

CMakeFiles/a3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a3.dir/clean

CMakeFiles/a3.dir/depend:
	cd /home/kanav/COL781/COL781_Assignments/a3-main/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanav/COL781/COL781_Assignments/a3-main /home/kanav/COL781/COL781_Assignments/a3-main /home/kanav/COL781/COL781_Assignments/a3-main/build /home/kanav/COL781/COL781_Assignments/a3-main/build /home/kanav/COL781/COL781_Assignments/a3-main/build/CMakeFiles/a3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a3.dir/depend

