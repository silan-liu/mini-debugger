# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/project/mini-debugger

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/project/mini-debugger

# Include any dependencies generated for this target.
include CMakeFiles/minidbg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minidbg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minidbg.dir/flags.make

CMakeFiles/minidbg.dir/src/debugger.cpp.o: CMakeFiles/minidbg.dir/flags.make
CMakeFiles/minidbg.dir/src/debugger.cpp.o: src/debugger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/project/mini-debugger/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/minidbg.dir/src/debugger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minidbg.dir/src/debugger.cpp.o -c /home/project/mini-debugger/src/debugger.cpp

CMakeFiles/minidbg.dir/src/debugger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minidbg.dir/src/debugger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/project/mini-debugger/src/debugger.cpp > CMakeFiles/minidbg.dir/src/debugger.cpp.i

CMakeFiles/minidbg.dir/src/debugger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minidbg.dir/src/debugger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/project/mini-debugger/src/debugger.cpp -o CMakeFiles/minidbg.dir/src/debugger.cpp.s

CMakeFiles/minidbg.dir/ext/linenoise/linenoise.c.o: CMakeFiles/minidbg.dir/flags.make
CMakeFiles/minidbg.dir/ext/linenoise/linenoise.c.o: ext/linenoise/linenoise.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/project/mini-debugger/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/minidbg.dir/ext/linenoise/linenoise.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minidbg.dir/ext/linenoise/linenoise.c.o   -c /home/project/mini-debugger/ext/linenoise/linenoise.c

CMakeFiles/minidbg.dir/ext/linenoise/linenoise.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minidbg.dir/ext/linenoise/linenoise.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/project/mini-debugger/ext/linenoise/linenoise.c > CMakeFiles/minidbg.dir/ext/linenoise/linenoise.c.i

CMakeFiles/minidbg.dir/ext/linenoise/linenoise.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minidbg.dir/ext/linenoise/linenoise.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/project/mini-debugger/ext/linenoise/linenoise.c -o CMakeFiles/minidbg.dir/ext/linenoise/linenoise.c.s

# Object files for target minidbg
minidbg_OBJECTS = \
"CMakeFiles/minidbg.dir/src/debugger.cpp.o" \
"CMakeFiles/minidbg.dir/ext/linenoise/linenoise.c.o"

# External object files for target minidbg
minidbg_EXTERNAL_OBJECTS =

minidbg: CMakeFiles/minidbg.dir/src/debugger.cpp.o
minidbg: CMakeFiles/minidbg.dir/ext/linenoise/linenoise.c.o
minidbg: CMakeFiles/minidbg.dir/build.make
minidbg: ext/libelfin/dwarf/libdwarf++.so
minidbg: ext/libelfin/elf/libelf++.so
minidbg: CMakeFiles/minidbg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/project/mini-debugger/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable minidbg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minidbg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minidbg.dir/build: minidbg

.PHONY : CMakeFiles/minidbg.dir/build

CMakeFiles/minidbg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minidbg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minidbg.dir/clean

CMakeFiles/minidbg.dir/depend:
	cd /home/project/mini-debugger && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/project/mini-debugger /home/project/mini-debugger /home/project/mini-debugger /home/project/mini-debugger /home/project/mini-debugger/CMakeFiles/minidbg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minidbg.dir/depend
