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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dmitry/study/httpserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitry/study/httpserver/build

# Include any dependencies generated for this target.
include CMakeFiles/httpserver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/httpserver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/httpserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/httpserver.dir/flags.make

CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o: CMakeFiles/httpserver.dir/flags.make
CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o: httpserver_autogen/mocs_compilation.cpp
CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o: CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dmitry/study/httpserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o -MF CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o -c /home/dmitry/study/httpserver/build/httpserver_autogen/mocs_compilation.cpp

CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/study/httpserver/build/httpserver_autogen/mocs_compilation.cpp > CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.i

CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/study/httpserver/build/httpserver_autogen/mocs_compilation.cpp -o CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.s

CMakeFiles/httpserver.dir/source/main.cpp.o: CMakeFiles/httpserver.dir/flags.make
CMakeFiles/httpserver.dir/source/main.cpp.o: /home/dmitry/study/httpserver/source/main.cpp
CMakeFiles/httpserver.dir/source/main.cpp.o: CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dmitry/study/httpserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/httpserver.dir/source/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/httpserver.dir/source/main.cpp.o -MF CMakeFiles/httpserver.dir/source/main.cpp.o.d -o CMakeFiles/httpserver.dir/source/main.cpp.o -c /home/dmitry/study/httpserver/source/main.cpp

CMakeFiles/httpserver.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/source/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/study/httpserver/source/main.cpp > CMakeFiles/httpserver.dir/source/main.cpp.i

CMakeFiles/httpserver.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/source/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/study/httpserver/source/main.cpp -o CMakeFiles/httpserver.dir/source/main.cpp.s

# Object files for target httpserver
httpserver_OBJECTS = \
"CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/httpserver.dir/source/main.cpp.o"

# External object files for target httpserver
httpserver_EXTERNAL_OBJECTS =

httpserver: CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o
httpserver: CMakeFiles/httpserver.dir/source/main.cpp.o
httpserver: CMakeFiles/httpserver.dir/build.make
httpserver: libhttpserverlib.a
httpserver: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.12.8
httpserver: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
httpserver: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
httpserver: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
httpserver: CMakeFiles/httpserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/dmitry/study/httpserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable httpserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/httpserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/httpserver.dir/build: httpserver
.PHONY : CMakeFiles/httpserver.dir/build

CMakeFiles/httpserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/httpserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/httpserver.dir/clean

CMakeFiles/httpserver.dir/depend:
	cd /home/dmitry/study/httpserver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/study/httpserver /home/dmitry/study/httpserver /home/dmitry/study/httpserver/build /home/dmitry/study/httpserver/build /home/dmitry/study/httpserver/build/CMakeFiles/httpserver.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/httpserver.dir/depend

