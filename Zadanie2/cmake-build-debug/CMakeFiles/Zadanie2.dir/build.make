# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /cygdrive/c/Users/jojob/AppData/Local/JetBrains/CLion2023.3/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/jojob/AppData/Local/JetBrains/CLion2023.3/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/jojob/Desktop/Programovacie Techniky/zadania/Zadanie2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/jojob/Desktop/Programovacie Techniky/zadania/Zadanie2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Zadanie2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Zadanie2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Zadanie2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Zadanie2.dir/flags.make

CMakeFiles/Zadanie2.dir/zadanie02.cpp.o: CMakeFiles/Zadanie2.dir/flags.make
CMakeFiles/Zadanie2.dir/zadanie02.cpp.o: /cygdrive/c/Users/jojob/Desktop/Programovacie\ Techniky/zadania/Zadanie2/zadanie02.cpp
CMakeFiles/Zadanie2.dir/zadanie02.cpp.o: CMakeFiles/Zadanie2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/cygdrive/c/Users/jojob/Desktop/Programovacie Techniky/zadania/Zadanie2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Zadanie2.dir/zadanie02.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Zadanie2.dir/zadanie02.cpp.o -MF CMakeFiles/Zadanie2.dir/zadanie02.cpp.o.d -o CMakeFiles/Zadanie2.dir/zadanie02.cpp.o -c "/cygdrive/c/Users/jojob/Desktop/Programovacie Techniky/zadania/Zadanie2/zadanie02.cpp"

CMakeFiles/Zadanie2.dir/zadanie02.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Zadanie2.dir/zadanie02.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/jojob/Desktop/Programovacie Techniky/zadania/Zadanie2/zadanie02.cpp" > CMakeFiles/Zadanie2.dir/zadanie02.cpp.i

CMakeFiles/Zadanie2.dir/zadanie02.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Zadanie2.dir/zadanie02.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/jojob/Desktop/Programovacie Techniky/zadania/Zadanie2/zadanie02.cpp" -o CMakeFiles/Zadanie2.dir/zadanie02.cpp.s

# Object files for target Zadanie2
Zadanie2_OBJECTS = \
"CMakeFiles/Zadanie2.dir/zadanie02.cpp.o"

# External object files for target Zadanie2
Zadanie2_EXTERNAL_OBJECTS =

Zadanie2.exe: CMakeFiles/Zadanie2.dir/zadanie02.cpp.o
Zadanie2.exe: CMakeFiles/Zadanie2.dir/build.make
Zadanie2.exe: CMakeFiles/Zadanie2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/cygdrive/c/Users/jojob/Desktop/Programovacie Techniky/zadania/Zadanie2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Zadanie2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Zadanie2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Zadanie2.dir/build: Zadanie2.exe
.PHONY : CMakeFiles/Zadanie2.dir/build

CMakeFiles/Zadanie2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Zadanie2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Zadanie2.dir/clean

CMakeFiles/Zadanie2.dir/depend:
	cd "/cygdrive/c/Users/jojob/Desktop/Programovacie Techniky/zadania/Zadanie2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/jojob/Desktop/Programovacie Techniky/zadania/Zadanie2" "/cygdrive/c/Users/jojob/Desktop/Programovacie Techniky/zadania/Zadanie2" "/cygdrive/c/Users/jojob/Desktop/Programovacie Techniky/zadania/Zadanie2/cmake-build-debug" "/cygdrive/c/Users/jojob/Desktop/Programovacie Techniky/zadania/Zadanie2/cmake-build-debug" "/cygdrive/c/Users/jojob/Desktop/Programovacie Techniky/zadania/Zadanie2/cmake-build-debug/CMakeFiles/Zadanie2.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Zadanie2.dir/depend

