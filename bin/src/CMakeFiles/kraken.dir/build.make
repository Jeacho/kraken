# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/jacob/Documents/kraken

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jacob/Documents/kraken/bin

# Include any dependencies generated for this target.
include src/CMakeFiles/kraken.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/kraken.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/kraken.dir/flags.make

src/CMakeFiles/kraken.dir/filesystem/io.cpp.o: src/CMakeFiles/kraken.dir/flags.make
src/CMakeFiles/kraken.dir/filesystem/io.cpp.o: ../src/filesystem/io.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jacob/Documents/kraken/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/kraken.dir/filesystem/io.cpp.o"
	cd /home/jacob/Documents/kraken/bin/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kraken.dir/filesystem/io.cpp.o -c /home/jacob/Documents/kraken/src/filesystem/io.cpp

src/CMakeFiles/kraken.dir/filesystem/io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kraken.dir/filesystem/io.cpp.i"
	cd /home/jacob/Documents/kraken/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jacob/Documents/kraken/src/filesystem/io.cpp > CMakeFiles/kraken.dir/filesystem/io.cpp.i

src/CMakeFiles/kraken.dir/filesystem/io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kraken.dir/filesystem/io.cpp.s"
	cd /home/jacob/Documents/kraken/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jacob/Documents/kraken/src/filesystem/io.cpp -o CMakeFiles/kraken.dir/filesystem/io.cpp.s

src/CMakeFiles/kraken.dir/filesystem/io.cpp.o.requires:

.PHONY : src/CMakeFiles/kraken.dir/filesystem/io.cpp.o.requires

src/CMakeFiles/kraken.dir/filesystem/io.cpp.o.provides: src/CMakeFiles/kraken.dir/filesystem/io.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/kraken.dir/build.make src/CMakeFiles/kraken.dir/filesystem/io.cpp.o.provides.build
.PHONY : src/CMakeFiles/kraken.dir/filesystem/io.cpp.o.provides

src/CMakeFiles/kraken.dir/filesystem/io.cpp.o.provides.build: src/CMakeFiles/kraken.dir/filesystem/io.cpp.o


src/CMakeFiles/kraken.dir/memory/buffer.cpp.o: src/CMakeFiles/kraken.dir/flags.make
src/CMakeFiles/kraken.dir/memory/buffer.cpp.o: ../src/memory/buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jacob/Documents/kraken/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/kraken.dir/memory/buffer.cpp.o"
	cd /home/jacob/Documents/kraken/bin/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kraken.dir/memory/buffer.cpp.o -c /home/jacob/Documents/kraken/src/memory/buffer.cpp

src/CMakeFiles/kraken.dir/memory/buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kraken.dir/memory/buffer.cpp.i"
	cd /home/jacob/Documents/kraken/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jacob/Documents/kraken/src/memory/buffer.cpp > CMakeFiles/kraken.dir/memory/buffer.cpp.i

src/CMakeFiles/kraken.dir/memory/buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kraken.dir/memory/buffer.cpp.s"
	cd /home/jacob/Documents/kraken/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jacob/Documents/kraken/src/memory/buffer.cpp -o CMakeFiles/kraken.dir/memory/buffer.cpp.s

src/CMakeFiles/kraken.dir/memory/buffer.cpp.o.requires:

.PHONY : src/CMakeFiles/kraken.dir/memory/buffer.cpp.o.requires

src/CMakeFiles/kraken.dir/memory/buffer.cpp.o.provides: src/CMakeFiles/kraken.dir/memory/buffer.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/kraken.dir/build.make src/CMakeFiles/kraken.dir/memory/buffer.cpp.o.provides.build
.PHONY : src/CMakeFiles/kraken.dir/memory/buffer.cpp.o.provides

src/CMakeFiles/kraken.dir/memory/buffer.cpp.o.provides.build: src/CMakeFiles/kraken.dir/memory/buffer.cpp.o


src/CMakeFiles/kraken.dir/support/console.cpp.o: src/CMakeFiles/kraken.dir/flags.make
src/CMakeFiles/kraken.dir/support/console.cpp.o: ../src/support/console.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jacob/Documents/kraken/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/kraken.dir/support/console.cpp.o"
	cd /home/jacob/Documents/kraken/bin/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kraken.dir/support/console.cpp.o -c /home/jacob/Documents/kraken/src/support/console.cpp

src/CMakeFiles/kraken.dir/support/console.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kraken.dir/support/console.cpp.i"
	cd /home/jacob/Documents/kraken/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jacob/Documents/kraken/src/support/console.cpp > CMakeFiles/kraken.dir/support/console.cpp.i

src/CMakeFiles/kraken.dir/support/console.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kraken.dir/support/console.cpp.s"
	cd /home/jacob/Documents/kraken/bin/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jacob/Documents/kraken/src/support/console.cpp -o CMakeFiles/kraken.dir/support/console.cpp.s

src/CMakeFiles/kraken.dir/support/console.cpp.o.requires:

.PHONY : src/CMakeFiles/kraken.dir/support/console.cpp.o.requires

src/CMakeFiles/kraken.dir/support/console.cpp.o.provides: src/CMakeFiles/kraken.dir/support/console.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/kraken.dir/build.make src/CMakeFiles/kraken.dir/support/console.cpp.o.provides.build
.PHONY : src/CMakeFiles/kraken.dir/support/console.cpp.o.provides

src/CMakeFiles/kraken.dir/support/console.cpp.o.provides.build: src/CMakeFiles/kraken.dir/support/console.cpp.o


# Object files for target kraken
kraken_OBJECTS = \
"CMakeFiles/kraken.dir/filesystem/io.cpp.o" \
"CMakeFiles/kraken.dir/memory/buffer.cpp.o" \
"CMakeFiles/kraken.dir/support/console.cpp.o"

# External object files for target kraken
kraken_EXTERNAL_OBJECTS =

src/libkraken.a: src/CMakeFiles/kraken.dir/filesystem/io.cpp.o
src/libkraken.a: src/CMakeFiles/kraken.dir/memory/buffer.cpp.o
src/libkraken.a: src/CMakeFiles/kraken.dir/support/console.cpp.o
src/libkraken.a: src/CMakeFiles/kraken.dir/build.make
src/libkraken.a: src/CMakeFiles/kraken.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jacob/Documents/kraken/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libkraken.a"
	cd /home/jacob/Documents/kraken/bin/src && $(CMAKE_COMMAND) -P CMakeFiles/kraken.dir/cmake_clean_target.cmake
	cd /home/jacob/Documents/kraken/bin/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kraken.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/kraken.dir/build: src/libkraken.a

.PHONY : src/CMakeFiles/kraken.dir/build

src/CMakeFiles/kraken.dir/requires: src/CMakeFiles/kraken.dir/filesystem/io.cpp.o.requires
src/CMakeFiles/kraken.dir/requires: src/CMakeFiles/kraken.dir/memory/buffer.cpp.o.requires
src/CMakeFiles/kraken.dir/requires: src/CMakeFiles/kraken.dir/support/console.cpp.o.requires

.PHONY : src/CMakeFiles/kraken.dir/requires

src/CMakeFiles/kraken.dir/clean:
	cd /home/jacob/Documents/kraken/bin/src && $(CMAKE_COMMAND) -P CMakeFiles/kraken.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/kraken.dir/clean

src/CMakeFiles/kraken.dir/depend:
	cd /home/jacob/Documents/kraken/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jacob/Documents/kraken /home/jacob/Documents/kraken/src /home/jacob/Documents/kraken/bin /home/jacob/Documents/kraken/bin/src /home/jacob/Documents/kraken/bin/src/CMakeFiles/kraken.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/kraken.dir/depend

