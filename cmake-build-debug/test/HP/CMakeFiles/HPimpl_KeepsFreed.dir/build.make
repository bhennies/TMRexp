# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/162/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/162/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/cmake-build-debug

# Include any dependencies generated for this target.
include test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/depend.make
# Include the progress variables for this target.
include test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/progress.make

# Include the compile flags for this target's objects.
include test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/flags.make

test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/KeepsFreed.cpp.o: test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/flags.make
test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/KeepsFreed.cpp.o: ../test/HP/KeepsFreed.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/KeepsFreed.cpp.o"
	cd /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/cmake-build-debug/test/HP && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HPimpl_KeepsFreed.dir/KeepsFreed.cpp.o -c /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/test/HP/KeepsFreed.cpp

test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/KeepsFreed.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HPimpl_KeepsFreed.dir/KeepsFreed.cpp.i"
	cd /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/cmake-build-debug/test/HP && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/test/HP/KeepsFreed.cpp > CMakeFiles/HPimpl_KeepsFreed.dir/KeepsFreed.cpp.i

test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/KeepsFreed.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HPimpl_KeepsFreed.dir/KeepsFreed.cpp.s"
	cd /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/cmake-build-debug/test/HP && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/test/HP/KeepsFreed.cpp -o CMakeFiles/HPimpl_KeepsFreed.dir/KeepsFreed.cpp.s

# Object files for target HPimpl_KeepsFreed
HPimpl_KeepsFreed_OBJECTS = \
"CMakeFiles/HPimpl_KeepsFreed.dir/KeepsFreed.cpp.o"

# External object files for target HPimpl_KeepsFreed
HPimpl_KeepsFreed_EXTERNAL_OBJECTS =

bin/HPimpl_KeepsFreed: test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/KeepsFreed.cpp.o
bin/HPimpl_KeepsFreed: test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/build.make
bin/HPimpl_KeepsFreed: src/libTMRexpLib.a
bin/HPimpl_KeepsFreed: test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/HPimpl_KeepsFreed"
	cd /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/cmake-build-debug/test/HP && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HPimpl_KeepsFreed.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/build: bin/HPimpl_KeepsFreed
.PHONY : test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/build

test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/clean:
	cd /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/cmake-build-debug/test/HP && $(CMAKE_COMMAND) -P CMakeFiles/HPimpl_KeepsFreed.dir/cmake_clean.cmake
.PHONY : test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/clean

test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/depend:
	cd /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/test/HP /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/cmake-build-debug /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/cmake-build-debug/test/HP /home/benjamin/Dokumente/Uni/Hiwi_TCS/TMRexp-POPL19-chksmr/cmake-build-debug/test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/HP/CMakeFiles/HPimpl_KeepsFreed.dir/depend

