# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /cygdrive/c/Users/emonc/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/emonc/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/i/C++/C++ Repository/Assignment 3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/i/C++/C++ Repository/Assignment 3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Assignment_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment_3.dir/flags.make

CMakeFiles/Assignment_3.dir/main.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/i/C++/C++ Repository/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment_3.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/main.cpp.o -c "/cygdrive/i/C++/C++ Repository/Assignment 3/main.cpp"

CMakeFiles/Assignment_3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/i/C++/C++ Repository/Assignment 3/main.cpp" > CMakeFiles/Assignment_3.dir/main.cpp.i

CMakeFiles/Assignment_3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/i/C++/C++ Repository/Assignment 3/main.cpp" -o CMakeFiles/Assignment_3.dir/main.cpp.s

CMakeFiles/Assignment_3.dir/Student.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/Student.cpp.o: ../Student.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/i/C++/C++ Repository/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Assignment_3.dir/Student.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/Student.cpp.o -c "/cygdrive/i/C++/C++ Repository/Assignment 3/Student.cpp"

CMakeFiles/Assignment_3.dir/Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/Student.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/i/C++/C++ Repository/Assignment 3/Student.cpp" > CMakeFiles/Assignment_3.dir/Student.cpp.i

CMakeFiles/Assignment_3.dir/Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/Student.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/i/C++/C++ Repository/Assignment 3/Student.cpp" -o CMakeFiles/Assignment_3.dir/Student.cpp.s

# Object files for target Assignment_3
Assignment_3_OBJECTS = \
"CMakeFiles/Assignment_3.dir/main.cpp.o" \
"CMakeFiles/Assignment_3.dir/Student.cpp.o"

# External object files for target Assignment_3
Assignment_3_EXTERNAL_OBJECTS =

Assignment_3.exe: CMakeFiles/Assignment_3.dir/main.cpp.o
Assignment_3.exe: CMakeFiles/Assignment_3.dir/Student.cpp.o
Assignment_3.exe: CMakeFiles/Assignment_3.dir/build.make
Assignment_3.exe: CMakeFiles/Assignment_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/i/C++/C++ Repository/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Assignment_3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment_3.dir/build: Assignment_3.exe

.PHONY : CMakeFiles/Assignment_3.dir/build

CMakeFiles/Assignment_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment_3.dir/clean

CMakeFiles/Assignment_3.dir/depend:
	cd "/cygdrive/i/C++/C++ Repository/Assignment 3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/i/C++/C++ Repository/Assignment 3" "/cygdrive/i/C++/C++ Repository/Assignment 3" "/cygdrive/i/C++/C++ Repository/Assignment 3/cmake-build-debug" "/cygdrive/i/C++/C++ Repository/Assignment 3/cmake-build-debug" "/cygdrive/i/C++/C++ Repository/Assignment 3/cmake-build-debug/CMakeFiles/Assignment_3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Assignment_3.dir/depend

