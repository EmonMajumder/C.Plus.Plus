# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\C++\Assignment 2\RationalCalculator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\C++\Assignment 2\RationalCalculator\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/RationalCalculator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RationalCalculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RationalCalculator.dir/flags.make

CMakeFiles/RationalCalculator.dir/main.cpp.obj: CMakeFiles/RationalCalculator.dir/flags.make
CMakeFiles/RationalCalculator.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\C++\Assignment 2\RationalCalculator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RationalCalculator.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RationalCalculator.dir\main.cpp.obj -c "E:\C++\Assignment 2\RationalCalculator\main.cpp"

CMakeFiles/RationalCalculator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RationalCalculator.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\C++\Assignment 2\RationalCalculator\main.cpp" > CMakeFiles\RationalCalculator.dir\main.cpp.i

CMakeFiles/RationalCalculator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RationalCalculator.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\C++\Assignment 2\RationalCalculator\main.cpp" -o CMakeFiles\RationalCalculator.dir\main.cpp.s

# Object files for target RationalCalculator
RationalCalculator_OBJECTS = \
"CMakeFiles/RationalCalculator.dir/main.cpp.obj"

# External object files for target RationalCalculator
RationalCalculator_EXTERNAL_OBJECTS =

RationalCalculator.exe: CMakeFiles/RationalCalculator.dir/main.cpp.obj
RationalCalculator.exe: CMakeFiles/RationalCalculator.dir/build.make
RationalCalculator.exe: CMakeFiles/RationalCalculator.dir/linklibs.rsp
RationalCalculator.exe: CMakeFiles/RationalCalculator.dir/objects1.rsp
RationalCalculator.exe: CMakeFiles/RationalCalculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\C++\Assignment 2\RationalCalculator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RationalCalculator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RationalCalculator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RationalCalculator.dir/build: RationalCalculator.exe

.PHONY : CMakeFiles/RationalCalculator.dir/build

CMakeFiles/RationalCalculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RationalCalculator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RationalCalculator.dir/clean

CMakeFiles/RationalCalculator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\C++\Assignment 2\RationalCalculator" "E:\C++\Assignment 2\RationalCalculator" "E:\C++\Assignment 2\RationalCalculator\cmake-build-debug" "E:\C++\Assignment 2\RationalCalculator\cmake-build-debug" "E:\C++\Assignment 2\RationalCalculator\cmake-build-debug\CMakeFiles\RationalCalculator.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/RationalCalculator.dir/depend

