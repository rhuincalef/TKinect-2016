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
include octree/CMakeFiles/pcl_octree.dir/depend.make

# Include the progress variables for this target.
include octree/CMakeFiles/pcl_octree.dir/progress.make

# Include the compile flags for this target's objects.
include octree/CMakeFiles/pcl_octree.dir/flags.make

octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o: octree/CMakeFiles/pcl_octree.dir/flags.make
octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o: octree/src/octree_inst.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o"
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/octree && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o -c /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/octree/src/octree_inst.cpp

octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.i"
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/octree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/octree/src/octree_inst.cpp > CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.i

octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.s"
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/octree && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/octree/src/octree_inst.cpp -o CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.s

octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o.requires:
.PHONY : octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o.requires

octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o.provides: octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o.requires
	$(MAKE) -f octree/CMakeFiles/pcl_octree.dir/build.make octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o.provides.build
.PHONY : octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o.provides

octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o.provides.build: octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o

# Object files for target pcl_octree
pcl_octree_OBJECTS = \
"CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o"

# External object files for target pcl_octree
pcl_octree_EXTERNAL_OBJECTS =

lib/libpcl_octree.so.1.7.2: octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o
lib/libpcl_octree.so.1.7.2: octree/CMakeFiles/pcl_octree.dir/build.make
lib/libpcl_octree.so.1.7.2: /usr/lib/i386-linux-gnu/libboost_system.so
lib/libpcl_octree.so.1.7.2: /usr/lib/i386-linux-gnu/libboost_filesystem.so
lib/libpcl_octree.so.1.7.2: /usr/lib/i386-linux-gnu/libboost_thread.so
lib/libpcl_octree.so.1.7.2: /usr/lib/i386-linux-gnu/libboost_date_time.so
lib/libpcl_octree.so.1.7.2: /usr/lib/i386-linux-gnu/libboost_iostreams.so
lib/libpcl_octree.so.1.7.2: /usr/lib/i386-linux-gnu/libboost_chrono.so
lib/libpcl_octree.so.1.7.2: /usr/lib/i386-linux-gnu/libpthread.so
lib/libpcl_octree.so.1.7.2: octree/CMakeFiles/pcl_octree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../lib/libpcl_octree.so"
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/octree && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pcl_octree.dir/link.txt --verbose=$(VERBOSE)
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/octree && $(CMAKE_COMMAND) -E cmake_symlink_library ../lib/libpcl_octree.so.1.7.2 ../lib/libpcl_octree.so.1.7 ../lib/libpcl_octree.so

lib/libpcl_octree.so.1.7: lib/libpcl_octree.so.1.7.2

lib/libpcl_octree.so: lib/libpcl_octree.so.1.7.2

# Rule to build all files generated by this target.
octree/CMakeFiles/pcl_octree.dir/build: lib/libpcl_octree.so
.PHONY : octree/CMakeFiles/pcl_octree.dir/build

octree/CMakeFiles/pcl_octree.dir/requires: octree/CMakeFiles/pcl_octree.dir/src/octree_inst.cpp.o.requires
.PHONY : octree/CMakeFiles/pcl_octree.dir/requires

octree/CMakeFiles/pcl_octree.dir/clean:
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/octree && $(CMAKE_COMMAND) -P CMakeFiles/pcl_octree.dir/cmake_clean.cmake
.PHONY : octree/CMakeFiles/pcl_octree.dir/clean

octree/CMakeFiles/pcl_octree.dir/depend:
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1 /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/octree /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1 /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/octree /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/octree/CMakeFiles/pcl_octree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : octree/CMakeFiles/pcl_octree.dir/depend

