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
include tools/CMakeFiles/pcl_demean_cloud.dir/depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/pcl_demean_cloud.dir/progress.make

# Include the compile flags for this target's objects.
include tools/CMakeFiles/pcl_demean_cloud.dir/flags.make

tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o: tools/CMakeFiles/pcl_demean_cloud.dir/flags.make
tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o: tools/demean_cloud.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o"
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/tools && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o -c /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/tools/demean_cloud.cpp

tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.i"
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/tools/demean_cloud.cpp > CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.i

tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.s"
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/tools/demean_cloud.cpp -o CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.s

tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o.requires:
.PHONY : tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o.requires

tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o.provides: tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o.requires
	$(MAKE) -f tools/CMakeFiles/pcl_demean_cloud.dir/build.make tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o.provides.build
.PHONY : tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o.provides

tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o.provides.build: tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o

# Object files for target pcl_demean_cloud
pcl_demean_cloud_OBJECTS = \
"CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o"

# External object files for target pcl_demean_cloud
pcl_demean_cloud_EXTERNAL_OBJECTS =

bin/pcl_demean_cloud: tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o
bin/pcl_demean_cloud: tools/CMakeFiles/pcl_demean_cloud.dir/build.make
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libboost_system.so
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libboost_filesystem.so
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libboost_thread.so
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libboost_date_time.so
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libboost_iostreams.so
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libboost_chrono.so
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libpthread.so
bin/pcl_demean_cloud: lib/libpcl_common.so.1.7.2
bin/pcl_demean_cloud: lib/libpcl_io.so.1.7.2
bin/pcl_demean_cloud: lib/libpcl_common.so.1.7.2
bin/pcl_demean_cloud: lib/libpcl_io_ply.so.1.7.2
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libboost_system.so
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libboost_filesystem.so
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libboost_thread.so
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libboost_date_time.so
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libboost_iostreams.so
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libboost_chrono.so
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libpthread.so
bin/pcl_demean_cloud: /usr/lib/libvtkGenericFiltering.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkGeovis.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkCharts.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkViews.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkInfovis.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkWidgets.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkVolumeRendering.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkHybrid.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkParallel.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkRendering.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkImaging.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkGraphics.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkIO.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkFiltering.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtkCommon.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/libvtksys.so.5.8.0
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libpng.so
bin/pcl_demean_cloud: /usr/lib/i386-linux-gnu/libusb-1.0.so
bin/pcl_demean_cloud: /usr/lib/libOpenNI.so
bin/pcl_demean_cloud: tools/CMakeFiles/pcl_demean_cloud.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/pcl_demean_cloud"
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pcl_demean_cloud.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/CMakeFiles/pcl_demean_cloud.dir/build: bin/pcl_demean_cloud
.PHONY : tools/CMakeFiles/pcl_demean_cloud.dir/build

tools/CMakeFiles/pcl_demean_cloud.dir/requires: tools/CMakeFiles/pcl_demean_cloud.dir/demean_cloud.cpp.o.requires
.PHONY : tools/CMakeFiles/pcl_demean_cloud.dir/requires

tools/CMakeFiles/pcl_demean_cloud.dir/clean:
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/tools && $(CMAKE_COMMAND) -P CMakeFiles/pcl_demean_cloud.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/pcl_demean_cloud.dir/clean

tools/CMakeFiles/pcl_demean_cloud.dir/depend:
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1 /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/tools /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1 /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/tools /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/tools/CMakeFiles/pcl_demean_cloud.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/CMakeFiles/pcl_demean_cloud.dir/depend

