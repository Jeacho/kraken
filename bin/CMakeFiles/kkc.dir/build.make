# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jake\Desktop\kraken

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jake\Desktop\kraken\bin

# Include any dependencies generated for this target.
include CMakeFiles/kkc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kkc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kkc.dir/flags.make

CMakeFiles/kkc.dir/src/driver.cpp.obj: CMakeFiles/kkc.dir/flags.make
CMakeFiles/kkc.dir/src/driver.cpp.obj: CMakeFiles/kkc.dir/includes_CXX.rsp
CMakeFiles/kkc.dir/src/driver.cpp.obj: ../src/driver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jake\Desktop\kraken\bin\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kkc.dir/src/driver.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\kkc.dir\src\driver.cpp.obj -c C:\Users\jake\Desktop\kraken\src\driver.cpp

CMakeFiles/kkc.dir/src/driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kkc.dir/src/driver.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jake\Desktop\kraken\src\driver.cpp > CMakeFiles\kkc.dir\src\driver.cpp.i

CMakeFiles/kkc.dir/src/driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kkc.dir/src/driver.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jake\Desktop\kraken\src\driver.cpp -o CMakeFiles\kkc.dir\src\driver.cpp.s

# Object files for target kkc
kkc_OBJECTS = \
"CMakeFiles/kkc.dir/src/driver.cpp.obj"

# External object files for target kkc
kkc_EXTERNAL_OBJECTS =

kkc.exe: CMakeFiles/kkc.dir/src/driver.cpp.obj
kkc.exe: CMakeFiles/kkc.dir/build.make
kkc.exe: src/libkraken.a
kkc.exe: CMakeFiles/kkc.dir/linklibs.rsp
kkc.exe: CMakeFiles/kkc.dir/objects1.rsp
kkc.exe: CMakeFiles/kkc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jake\Desktop\kraken\bin\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable kkc.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\kkc.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kkc.dir/build: kkc.exe

.PHONY : CMakeFiles/kkc.dir/build

CMakeFiles/kkc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\kkc.dir\cmake_clean.cmake
.PHONY : CMakeFiles/kkc.dir/clean

CMakeFiles/kkc.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jake\Desktop\kraken C:\Users\jake\Desktop\kraken C:\Users\jake\Desktop\kraken\bin C:\Users\jake\Desktop\kraken\bin C:\Users\jake\Desktop\kraken\bin\CMakeFiles\kkc.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kkc.dir/depend

