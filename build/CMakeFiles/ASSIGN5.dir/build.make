# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/dirtyv/Codes/Assignment_5_FAZU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dirtyv/Codes/Assignment_5_FAZU/build

# Include any dependencies generated for this target.
include CMakeFiles/ASSIGN5.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ASSIGN5.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ASSIGN5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ASSIGN5.dir/flags.make

CMakeFiles/ASSIGN5.dir/src/main.c.o: CMakeFiles/ASSIGN5.dir/flags.make
CMakeFiles/ASSIGN5.dir/src/main.c.o: /home/dirtyv/Codes/Assignment_5_FAZU/src/main.c
CMakeFiles/ASSIGN5.dir/src/main.c.o: CMakeFiles/ASSIGN5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dirtyv/Codes/Assignment_5_FAZU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ASSIGN5.dir/src/main.c.o"
	/usr/bin/x86_64-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ASSIGN5.dir/src/main.c.o -MF CMakeFiles/ASSIGN5.dir/src/main.c.o.d -o CMakeFiles/ASSIGN5.dir/src/main.c.o -c /home/dirtyv/Codes/Assignment_5_FAZU/src/main.c

CMakeFiles/ASSIGN5.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ASSIGN5.dir/src/main.c.i"
	/usr/bin/x86_64-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dirtyv/Codes/Assignment_5_FAZU/src/main.c > CMakeFiles/ASSIGN5.dir/src/main.c.i

CMakeFiles/ASSIGN5.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ASSIGN5.dir/src/main.c.s"
	/usr/bin/x86_64-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dirtyv/Codes/Assignment_5_FAZU/src/main.c -o CMakeFiles/ASSIGN5.dir/src/main.c.s

CMakeFiles/ASSIGN5.dir/src/wordle.c.o: CMakeFiles/ASSIGN5.dir/flags.make
CMakeFiles/ASSIGN5.dir/src/wordle.c.o: /home/dirtyv/Codes/Assignment_5_FAZU/src/wordle.c
CMakeFiles/ASSIGN5.dir/src/wordle.c.o: CMakeFiles/ASSIGN5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dirtyv/Codes/Assignment_5_FAZU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ASSIGN5.dir/src/wordle.c.o"
	/usr/bin/x86_64-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ASSIGN5.dir/src/wordle.c.o -MF CMakeFiles/ASSIGN5.dir/src/wordle.c.o.d -o CMakeFiles/ASSIGN5.dir/src/wordle.c.o -c /home/dirtyv/Codes/Assignment_5_FAZU/src/wordle.c

CMakeFiles/ASSIGN5.dir/src/wordle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ASSIGN5.dir/src/wordle.c.i"
	/usr/bin/x86_64-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dirtyv/Codes/Assignment_5_FAZU/src/wordle.c > CMakeFiles/ASSIGN5.dir/src/wordle.c.i

CMakeFiles/ASSIGN5.dir/src/wordle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ASSIGN5.dir/src/wordle.c.s"
	/usr/bin/x86_64-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dirtyv/Codes/Assignment_5_FAZU/src/wordle.c -o CMakeFiles/ASSIGN5.dir/src/wordle.c.s

# Object files for target ASSIGN5
ASSIGN5_OBJECTS = \
"CMakeFiles/ASSIGN5.dir/src/main.c.o" \
"CMakeFiles/ASSIGN5.dir/src/wordle.c.o"

# External object files for target ASSIGN5
ASSIGN5_EXTERNAL_OBJECTS =

/home/dirtyv/Codes/Assignment_5_FAZU/ASSIGN5: CMakeFiles/ASSIGN5.dir/src/main.c.o
/home/dirtyv/Codes/Assignment_5_FAZU/ASSIGN5: CMakeFiles/ASSIGN5.dir/src/wordle.c.o
/home/dirtyv/Codes/Assignment_5_FAZU/ASSIGN5: CMakeFiles/ASSIGN5.dir/build.make
/home/dirtyv/Codes/Assignment_5_FAZU/ASSIGN5: CMakeFiles/ASSIGN5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dirtyv/Codes/Assignment_5_FAZU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable /home/dirtyv/Codes/Assignment_5_FAZU/ASSIGN5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ASSIGN5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ASSIGN5.dir/build: /home/dirtyv/Codes/Assignment_5_FAZU/ASSIGN5
.PHONY : CMakeFiles/ASSIGN5.dir/build

CMakeFiles/ASSIGN5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ASSIGN5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ASSIGN5.dir/clean

CMakeFiles/ASSIGN5.dir/depend:
	cd /home/dirtyv/Codes/Assignment_5_FAZU/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dirtyv/Codes/Assignment_5_FAZU /home/dirtyv/Codes/Assignment_5_FAZU /home/dirtyv/Codes/Assignment_5_FAZU/build /home/dirtyv/Codes/Assignment_5_FAZU/build /home/dirtyv/Codes/Assignment_5_FAZU/build/CMakeFiles/ASSIGN5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ASSIGN5.dir/depend
