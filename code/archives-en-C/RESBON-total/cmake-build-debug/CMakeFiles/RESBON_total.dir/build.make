# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\PC_Samuel_01\Documents\GitHub\REBSON\code\RESBON-total

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\PC_Samuel_01\Documents\GitHub\REBSON\code\RESBON-total\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RESBON_total.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RESBON_total.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RESBON_total.dir/flags.make

CMakeFiles/RESBON_total.dir/main.c.obj: CMakeFiles/RESBON_total.dir/flags.make
CMakeFiles/RESBON_total.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\PC_Samuel_01\Documents\GitHub\REBSON\code\RESBON-total\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RESBON_total.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\RESBON_total.dir\main.c.obj   -c C:\Users\PC_Samuel_01\Documents\GitHub\REBSON\code\RESBON-total\main.c

CMakeFiles/RESBON_total.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RESBON_total.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\PC_Samuel_01\Documents\GitHub\REBSON\code\RESBON-total\main.c > CMakeFiles\RESBON_total.dir\main.c.i

CMakeFiles/RESBON_total.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RESBON_total.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\PC_Samuel_01\Documents\GitHub\REBSON\code\RESBON-total\main.c -o CMakeFiles\RESBON_total.dir\main.c.s

# Object files for target RESBON_total
RESBON_total_OBJECTS = \
"CMakeFiles/RESBON_total.dir/main.c.obj"

# External object files for target RESBON_total
RESBON_total_EXTERNAL_OBJECTS =

RESBON_total.exe: CMakeFiles/RESBON_total.dir/main.c.obj
RESBON_total.exe: CMakeFiles/RESBON_total.dir/build.make
RESBON_total.exe: CMakeFiles/RESBON_total.dir/linklibs.rsp
RESBON_total.exe: CMakeFiles/RESBON_total.dir/objects1.rsp
RESBON_total.exe: CMakeFiles/RESBON_total.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\PC_Samuel_01\Documents\GitHub\REBSON\code\RESBON-total\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable RESBON_total.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RESBON_total.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RESBON_total.dir/build: RESBON_total.exe

.PHONY : CMakeFiles/RESBON_total.dir/build

CMakeFiles/RESBON_total.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RESBON_total.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RESBON_total.dir/clean

CMakeFiles/RESBON_total.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\PC_Samuel_01\Documents\GitHub\REBSON\code\RESBON-total C:\Users\PC_Samuel_01\Documents\GitHub\REBSON\code\RESBON-total C:\Users\PC_Samuel_01\Documents\GitHub\REBSON\code\RESBON-total\cmake-build-debug C:\Users\PC_Samuel_01\Documents\GitHub\REBSON\code\RESBON-total\cmake-build-debug C:\Users\PC_Samuel_01\Documents\GitHub\REBSON\code\RESBON-total\cmake-build-debug\CMakeFiles\RESBON_total.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RESBON_total.dir/depend

