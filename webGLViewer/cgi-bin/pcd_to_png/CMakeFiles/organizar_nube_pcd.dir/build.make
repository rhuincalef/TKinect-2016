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
CMAKE_SOURCE_DIR = /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png

# Include any dependencies generated for this target.
include CMakeFiles/organizar_nube_pcd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/organizar_nube_pcd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/organizar_nube_pcd.dir/flags.make

CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o: CMakeFiles/organizar_nube_pcd.dir/flags.make
CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o: organizar_nube_pcd.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o -c /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/organizar_nube_pcd.cpp

CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/organizar_nube_pcd.cpp > CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.i

CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/organizar_nube_pcd.cpp -o CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.s

CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o.requires:
.PHONY : CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o.requires

CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o.provides: CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o.requires
	$(MAKE) -f CMakeFiles/organizar_nube_pcd.dir/build.make CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o.provides.build
.PHONY : CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o.provides

CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o.provides.build: CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o

# Object files for target organizar_nube_pcd
organizar_nube_pcd_OBJECTS = \
"CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o"

# External object files for target organizar_nube_pcd
organizar_nube_pcd_EXTERNAL_OBJECTS =

build/organizar_nube_pcd: CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o
build/organizar_nube_pcd: CMakeFiles/organizar_nube_pcd.dir/build.make
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_system.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_filesystem.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_thread.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_date_time.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_iostreams.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_serialization.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_chrono.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libpthread.so
build/organizar_nube_pcd: /usr/lib/libpcl_common.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libflann_cpp_s.a
build/organizar_nube_pcd: /usr/lib/libpcl_kdtree.so
build/organizar_nube_pcd: /usr/lib/libpcl_octree.so
build/organizar_nube_pcd: /usr/lib/libpcl_search.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libqhull.so
build/organizar_nube_pcd: /usr/lib/libpcl_surface.so
build/organizar_nube_pcd: /usr/lib/libpcl_sample_consensus.so
build/organizar_nube_pcd: /usr/lib/libOpenNI.so
build/organizar_nube_pcd: /usr/lib/libOpenNI2.so
build/organizar_nube_pcd: /usr/lib/libvtkCommon.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkFiltering.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkImaging.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkGraphics.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkGenericFiltering.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkIO.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkRendering.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkVolumeRendering.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkHybrid.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkWidgets.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkParallel.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkInfovis.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkGeovis.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkViews.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkCharts.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libpcl_io.so
build/organizar_nube_pcd: /usr/lib/libpcl_filters.so
build/organizar_nube_pcd: /usr/lib/libpcl_features.so
build/organizar_nube_pcd: /usr/lib/libpcl_keypoints.so
build/organizar_nube_pcd: /usr/lib/libpcl_registration.so
build/organizar_nube_pcd: /usr/lib/libpcl_segmentation.so
build/organizar_nube_pcd: /usr/lib/libpcl_recognition.so
build/organizar_nube_pcd: /usr/lib/libpcl_visualization.so
build/organizar_nube_pcd: /usr/lib/libpcl_people.so
build/organizar_nube_pcd: /usr/lib/libpcl_outofcore.so
build/organizar_nube_pcd: /usr/lib/libpcl_tracking.so
build/organizar_nube_pcd: /usr/lib/libpcl_apps.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_system.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_filesystem.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_thread.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_date_time.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_iostreams.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_serialization.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libboost_chrono.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libpthread.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libqhull.so
build/organizar_nube_pcd: /usr/lib/libOpenNI.so
build/organizar_nube_pcd: /usr/lib/libOpenNI2.so
build/organizar_nube_pcd: /usr/lib/i386-linux-gnu/libflann_cpp_s.a
build/organizar_nube_pcd: /usr/lib/libvtkCommon.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkFiltering.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkImaging.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkGraphics.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkGenericFiltering.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkIO.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkRendering.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkVolumeRendering.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkHybrid.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkWidgets.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkParallel.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkInfovis.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkGeovis.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkViews.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkCharts.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libpcl_common.so
build/organizar_nube_pcd: /usr/lib/libpcl_kdtree.so
build/organizar_nube_pcd: /usr/lib/libpcl_octree.so
build/organizar_nube_pcd: /usr/lib/libpcl_search.so
build/organizar_nube_pcd: /usr/lib/libpcl_surface.so
build/organizar_nube_pcd: /usr/lib/libpcl_sample_consensus.so
build/organizar_nube_pcd: /usr/lib/libpcl_io.so
build/organizar_nube_pcd: /usr/lib/libpcl_filters.so
build/organizar_nube_pcd: /usr/lib/libpcl_features.so
build/organizar_nube_pcd: /usr/lib/libpcl_keypoints.so
build/organizar_nube_pcd: /usr/lib/libpcl_registration.so
build/organizar_nube_pcd: /usr/lib/libpcl_segmentation.so
build/organizar_nube_pcd: /usr/lib/libpcl_recognition.so
build/organizar_nube_pcd: /usr/lib/libpcl_visualization.so
build/organizar_nube_pcd: /usr/lib/libpcl_people.so
build/organizar_nube_pcd: /usr/lib/libpcl_outofcore.so
build/organizar_nube_pcd: /usr/lib/libpcl_tracking.so
build/organizar_nube_pcd: /usr/lib/libpcl_apps.so
build/organizar_nube_pcd: /usr/lib/libvtkViews.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkInfovis.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkWidgets.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkVolumeRendering.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkHybrid.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkParallel.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkRendering.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkImaging.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkGraphics.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkIO.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkFiltering.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtkCommon.so.5.8.0
build/organizar_nube_pcd: /usr/lib/libvtksys.so.5.8.0
build/organizar_nube_pcd: CMakeFiles/organizar_nube_pcd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable build/organizar_nube_pcd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/organizar_nube_pcd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/organizar_nube_pcd.dir/build: build/organizar_nube_pcd
.PHONY : CMakeFiles/organizar_nube_pcd.dir/build

CMakeFiles/organizar_nube_pcd.dir/requires: CMakeFiles/organizar_nube_pcd.dir/organizar_nube_pcd.cpp.o.requires
.PHONY : CMakeFiles/organizar_nube_pcd.dir/requires

CMakeFiles/organizar_nube_pcd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/organizar_nube_pcd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/organizar_nube_pcd.dir/clean

CMakeFiles/organizar_nube_pcd.dir/depend:
	cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/CMakeFiles/organizar_nube_pcd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/organizar_nube_pcd.dir/depend
