# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1

# Include any dependencies generated for this target.
include io/tools/ply/CMakeFiles/pcl_ply2obj.dir/depend.make

# Include the progress variables for this target.
include io/tools/ply/CMakeFiles/pcl_ply2obj.dir/progress.make

# Include the compile flags for this target's objects.
include io/tools/ply/CMakeFiles/pcl_ply2obj.dir/flags.make

io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o: io/tools/ply/CMakeFiles/pcl_ply2obj.dir/flags.make
io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o: io/tools/ply/ply2obj.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o"
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/io/tools/ply && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o -c /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/io/tools/ply/ply2obj.cpp

io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.i"
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/io/tools/ply && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/io/tools/ply/ply2obj.cpp > CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.i

io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.s"
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/io/tools/ply && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/io/tools/ply/ply2obj.cpp -o CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.s

io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o.requires:
.PHONY : io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o.requires

io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o.provides: io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o.requires
	$(MAKE) -f io/tools/ply/CMakeFiles/pcl_ply2obj.dir/build.make io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o.provides.build
.PHONY : io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o.provides

io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o.provides.build: io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o

# Object files for target pcl_ply2obj
pcl_ply2obj_OBJECTS = \
"CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o"

# External object files for target pcl_ply2obj
pcl_ply2obj_EXTERNAL_OBJECTS =

bin/pcl_ply2obj: io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o
bin/pcl_ply2obj: io/tools/ply/CMakeFiles/pcl_ply2obj.dir/build.make
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libboost_system.so
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libboost_filesystem.so
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libboost_thread.so
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libboost_date_time.so
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libboost_iostreams.so
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libboost_chrono.so
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libpthread.so
bin/pcl_ply2obj: lib/libpcl_io_ply.so.1.7.2
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libboost_system.so
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libboost_filesystem.so
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libboost_thread.so
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libboost_date_time.so
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libboost_iostreams.so
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libboost_chrono.so
bin/pcl_ply2obj: /usr/lib/i386-linux-gnu/libpthread.so
bin/pcl_ply2obj: io/tools/ply/CMakeFiles/pcl_ply2obj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/pcl_ply2obj"
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/io/tools/ply && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pcl_ply2obj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
io/tools/ply/CMakeFiles/pcl_ply2obj.dir/build: bin/pcl_ply2obj
.PHONY : io/tools/ply/CMakeFiles/pcl_ply2obj.dir/build

io/tools/ply/CMakeFiles/pcl_ply2obj.dir/requires: io/tools/ply/CMakeFiles/pcl_ply2obj.dir/ply2obj.cpp.o.requires
.PHONY : io/tools/ply/CMakeFiles/pcl_ply2obj.dir/requires

io/tools/ply/CMakeFiles/pcl_ply2obj.dir/clean:
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/io/tools/ply && $(CMAKE_COMMAND) -P CMakeFiles/pcl_ply2obj.dir/cmake_clean.cmake
.PHONY : io/tools/ply/CMakeFiles/pcl_ply2obj.dir/clean

io/tools/ply/CMakeFiles/pcl_ply2obj.dir/depend:
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1 /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/io/tools/ply /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1 /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/io/tools/ply /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/io/tools/ply/CMakeFiles/pcl_ply2obj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : io/tools/ply/CMakeFiles/pcl_ply2obj.dir/depend

