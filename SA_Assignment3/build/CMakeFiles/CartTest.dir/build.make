# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3/build

# Include any dependencies generated for this target.
include CMakeFiles/CartTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CartTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CartTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CartTest.dir/flags.make

CMakeFiles/CartTest.dir/CartTest.cc.o: CMakeFiles/CartTest.dir/flags.make
CMakeFiles/CartTest.dir/CartTest.cc.o: /Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3/CartTest.cc
CMakeFiles/CartTest.dir/CartTest.cc.o: CMakeFiles/CartTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CartTest.dir/CartTest.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CartTest.dir/CartTest.cc.o -MF CMakeFiles/CartTest.dir/CartTest.cc.o.d -o CMakeFiles/CartTest.dir/CartTest.cc.o -c /Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3/CartTest.cc

CMakeFiles/CartTest.dir/CartTest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CartTest.dir/CartTest.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3/CartTest.cc > CMakeFiles/CartTest.dir/CartTest.cc.i

CMakeFiles/CartTest.dir/CartTest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CartTest.dir/CartTest.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3/CartTest.cc -o CMakeFiles/CartTest.dir/CartTest.cc.s

# Object files for target CartTest
CartTest_OBJECTS = \
"CMakeFiles/CartTest.dir/CartTest.cc.o"

# External object files for target CartTest
CartTest_EXTERNAL_OBJECTS =

CartTest: CMakeFiles/CartTest.dir/CartTest.cc.o
CartTest: CMakeFiles/CartTest.dir/build.make
CartTest: /opt/homebrew/lib/libgtest.a
CartTest: /opt/homebrew/lib/libgmock.a
CartTest: /opt/homebrew/lib/libgtest_main.a
CartTest: /opt/homebrew/lib/libgtest.a
CartTest: CMakeFiles/CartTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CartTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CartTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CartTest.dir/build: CartTest
.PHONY : CMakeFiles/CartTest.dir/build

CMakeFiles/CartTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CartTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CartTest.dir/clean

CMakeFiles/CartTest.dir/depend:
	cd /Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3 /Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3 /Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3/build /Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3/build /Users/anshbhanushali/Desktop/SA_ARCH/SA_Assignment3/build/CMakeFiles/CartTest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/CartTest.dir/depend

