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
CMAKE_SOURCE_DIR = /var/www/html/tkinect2016/webGLViewer/cgi-bin/main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /var/www/html/tkinect2016/webGLViewer/cgi-bin/main

# Include any dependencies generated for this target.
include CMakeFiles/conversorCgi.cgi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/conversorCgi.cgi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/conversorCgi.cgi.dir/flags.make

CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o: CMakeFiles/conversorCgi.cgi.dir/flags.make
CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o: conversorCgi.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /var/www/html/tkinect2016/webGLViewer/cgi-bin/main/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o -c /var/www/html/tkinect2016/webGLViewer/cgi-bin/main/conversorCgi.cpp

CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /var/www/html/tkinect2016/webGLViewer/cgi-bin/main/conversorCgi.cpp > CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.i

CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /var/www/html/tkinect2016/webGLViewer/cgi-bin/main/conversorCgi.cpp -o CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.s

CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o.requires:
.PHONY : CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o.requires

CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o.provides: CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o.requires
	$(MAKE) -f CMakeFiles/conversorCgi.cgi.dir/build.make CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o.provides.build
.PHONY : CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o.provides

CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o.provides.build: CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o

# Object files for target conversorCgi.cgi
conversorCgi_cgi_OBJECTS = \
"CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o"

# External object files for target conversorCgi.cgi
conversorCgi_cgi_EXTERNAL_OBJECTS =

build/conversorCgi.cgi: CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o
build/conversorCgi.cgi: CMakeFiles/conversorCgi.cgi.dir/build.make
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_system.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_filesystem.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_thread.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_date_time.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_iostreams.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_serialization.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_chrono.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libpthread.so
build/conversorCgi.cgi: /usr/lib/libpcl_common.so
build/conversorCgi.cgi: /usr/lib/libOpenNI.so
build/conversorCgi.cgi: /usr/lib/libOpenNI2.so
build/conversorCgi.cgi: /usr/lib/libvtkCommon.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkFiltering.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkImaging.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkGraphics.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkGenericFiltering.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkIO.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkRendering.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkVolumeRendering.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkHybrid.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkWidgets.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkParallel.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkInfovis.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkGeovis.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkViews.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkCharts.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libpcl_io.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_system.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_filesystem.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_thread.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_date_time.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_iostreams.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_serialization.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_chrono.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libpthread.so
build/conversorCgi.cgi: /usr/lib/libpcl_common.so
build/conversorCgi.cgi: /usr/lib/libpcl_octree.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_system.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_filesystem.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_thread.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_date_time.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_iostreams.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_serialization.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_chrono.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libpthread.so
build/conversorCgi.cgi: /usr/lib/libpcl_common.so
build/conversorCgi.cgi: libpcd_to_csv.a
build/conversorCgi.cgi: libpcd_to_json.a
build/conversorCgi.cgi: libexcepciones.a
build/conversorCgi.cgi: /usr/lib/libvtkGenericFiltering.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkGeovis.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkCharts.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkViews.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkInfovis.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkWidgets.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkVolumeRendering.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkHybrid.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkParallel.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkRendering.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkImaging.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkGraphics.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkIO.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkFiltering.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtkCommon.so.5.8.0
build/conversorCgi.cgi: /usr/lib/libvtksys.so.5.8.0
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_system.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_filesystem.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_thread.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_date_time.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_iostreams.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_serialization.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_chrono.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libpthread.so
build/conversorCgi.cgi: /usr/lib/libpcl_common.so
build/conversorCgi.cgi: /usr/lib/libOpenNI.so
build/conversorCgi.cgi: /usr/lib/libOpenNI2.so
build/conversorCgi.cgi: /usr/lib/libpcl_io.so
build/conversorCgi.cgi: /usr/lib/libpcl_octree.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_system.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_filesystem.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_thread.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_date_time.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_iostreams.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_serialization.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libboost_chrono.so
build/conversorCgi.cgi: /usr/lib/i386-linux-gnu/libpthread.so
build/conversorCgi.cgi: /usr/lib/libpcl_common.so
build/conversorCgi.cgi: /usr/lib/libOpenNI.so
build/conversorCgi.cgi: /usr/lib/libOpenNI2.so
build/conversorCgi.cgi: /usr/lib/libpcl_io.so
build/conversorCgi.cgi: /usr/lib/libpcl_octree.so
build/conversorCgi.cgi: CMakeFiles/conversorCgi.cgi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable build/conversorCgi.cgi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/conversorCgi.cgi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/conversorCgi.cgi.dir/build: build/conversorCgi.cgi
.PHONY : CMakeFiles/conversorCgi.cgi.dir/build

CMakeFiles/conversorCgi.cgi.dir/requires: CMakeFiles/conversorCgi.cgi.dir/conversorCgi.cpp.o.requires
.PHONY : CMakeFiles/conversorCgi.cgi.dir/requires

CMakeFiles/conversorCgi.cgi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/conversorCgi.cgi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/conversorCgi.cgi.dir/clean

CMakeFiles/conversorCgi.cgi.dir/depend:
	cd /var/www/html/tkinect2016/webGLViewer/cgi-bin/main && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/www/html/tkinect2016/webGLViewer/cgi-bin/main /var/www/html/tkinect2016/webGLViewer/cgi-bin/main /var/www/html/tkinect2016/webGLViewer/cgi-bin/main /var/www/html/tkinect2016/webGLViewer/cgi-bin/main /var/www/html/tkinect2016/webGLViewer/cgi-bin/main/CMakeFiles/conversorCgi.cgi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/conversorCgi.cgi.dir/depend

