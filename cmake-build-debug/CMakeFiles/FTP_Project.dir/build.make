# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\coding\computer_network\FTP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\coding\computer_network\FTP\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FTP_Project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FTP_Project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FTP_Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FTP_Project.dir/flags.make

CMakeFiles/FTP_Project.dir/source/FTPClient/client.c.obj: CMakeFiles/FTP_Project.dir/flags.make
CMakeFiles/FTP_Project.dir/source/FTPClient/client.c.obj: CMakeFiles/FTP_Project.dir/includes_C.rsp
CMakeFiles/FTP_Project.dir/source/FTPClient/client.c.obj: ../source/FTPClient/client.c
CMakeFiles/FTP_Project.dir/source/FTPClient/client.c.obj: CMakeFiles/FTP_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\coding\computer_network\FTP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FTP_Project.dir/source/FTPClient/client.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FTP_Project.dir/source/FTPClient/client.c.obj -MF CMakeFiles\FTP_Project.dir\source\FTPClient\client.c.obj.d -o CMakeFiles\FTP_Project.dir\source\FTPClient\client.c.obj -c D:\coding\computer_network\FTP\source\FTPClient\client.c

CMakeFiles/FTP_Project.dir/source/FTPClient/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FTP_Project.dir/source/FTPClient/client.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\coding\computer_network\FTP\source\FTPClient\client.c > CMakeFiles\FTP_Project.dir\source\FTPClient\client.c.i

CMakeFiles/FTP_Project.dir/source/FTPClient/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FTP_Project.dir/source/FTPClient/client.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\coding\computer_network\FTP\source\FTPClient\client.c -o CMakeFiles\FTP_Project.dir\source\FTPClient\client.c.s

CMakeFiles/FTP_Project.dir/source/FTPServer/server.c.obj: CMakeFiles/FTP_Project.dir/flags.make
CMakeFiles/FTP_Project.dir/source/FTPServer/server.c.obj: CMakeFiles/FTP_Project.dir/includes_C.rsp
CMakeFiles/FTP_Project.dir/source/FTPServer/server.c.obj: ../source/FTPServer/server.c
CMakeFiles/FTP_Project.dir/source/FTPServer/server.c.obj: CMakeFiles/FTP_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\coding\computer_network\FTP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/FTP_Project.dir/source/FTPServer/server.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FTP_Project.dir/source/FTPServer/server.c.obj -MF CMakeFiles\FTP_Project.dir\source\FTPServer\server.c.obj.d -o CMakeFiles\FTP_Project.dir\source\FTPServer\server.c.obj -c D:\coding\computer_network\FTP\source\FTPServer\server.c

CMakeFiles/FTP_Project.dir/source/FTPServer/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FTP_Project.dir/source/FTPServer/server.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\coding\computer_network\FTP\source\FTPServer\server.c > CMakeFiles\FTP_Project.dir\source\FTPServer\server.c.i

CMakeFiles/FTP_Project.dir/source/FTPServer/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FTP_Project.dir/source/FTPServer/server.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\coding\computer_network\FTP\source\FTPServer\server.c -o CMakeFiles\FTP_Project.dir\source\FTPServer\server.c.s

CMakeFiles/FTP_Project.dir/source/FTPServer/server_main.c.obj: CMakeFiles/FTP_Project.dir/flags.make
CMakeFiles/FTP_Project.dir/source/FTPServer/server_main.c.obj: CMakeFiles/FTP_Project.dir/includes_C.rsp
CMakeFiles/FTP_Project.dir/source/FTPServer/server_main.c.obj: ../source/FTPServer/server_main.c
CMakeFiles/FTP_Project.dir/source/FTPServer/server_main.c.obj: CMakeFiles/FTP_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\coding\computer_network\FTP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/FTP_Project.dir/source/FTPServer/server_main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FTP_Project.dir/source/FTPServer/server_main.c.obj -MF CMakeFiles\FTP_Project.dir\source\FTPServer\server_main.c.obj.d -o CMakeFiles\FTP_Project.dir\source\FTPServer\server_main.c.obj -c D:\coding\computer_network\FTP\source\FTPServer\server_main.c

CMakeFiles/FTP_Project.dir/source/FTPServer/server_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FTP_Project.dir/source/FTPServer/server_main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\coding\computer_network\FTP\source\FTPServer\server_main.c > CMakeFiles\FTP_Project.dir\source\FTPServer\server_main.c.i

CMakeFiles/FTP_Project.dir/source/FTPServer/server_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FTP_Project.dir/source/FTPServer/server_main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\coding\computer_network\FTP\source\FTPServer\server_main.c -o CMakeFiles\FTP_Project.dir\source\FTPServer\server_main.c.s

# Object files for target FTP_Project
FTP_Project_OBJECTS = \
"CMakeFiles/FTP_Project.dir/source/FTPClient/client.c.obj" \
"CMakeFiles/FTP_Project.dir/source/FTPServer/server.c.obj" \
"CMakeFiles/FTP_Project.dir/source/FTPServer/server_main.c.obj"

# External object files for target FTP_Project
FTP_Project_EXTERNAL_OBJECTS =

FTP_Project.exe: CMakeFiles/FTP_Project.dir/source/FTPClient/client.c.obj
FTP_Project.exe: CMakeFiles/FTP_Project.dir/source/FTPServer/server.c.obj
FTP_Project.exe: CMakeFiles/FTP_Project.dir/source/FTPServer/server_main.c.obj
FTP_Project.exe: CMakeFiles/FTP_Project.dir/build.make
FTP_Project.exe: CMakeFiles/FTP_Project.dir/linklibs.rsp
FTP_Project.exe: CMakeFiles/FTP_Project.dir/objects1.rsp
FTP_Project.exe: CMakeFiles/FTP_Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\coding\computer_network\FTP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable FTP_Project.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\FTP_Project.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FTP_Project.dir/build: FTP_Project.exe
.PHONY : CMakeFiles/FTP_Project.dir/build

CMakeFiles/FTP_Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FTP_Project.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FTP_Project.dir/clean

CMakeFiles/FTP_Project.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\coding\computer_network\FTP D:\coding\computer_network\FTP D:\coding\computer_network\FTP\cmake-build-debug D:\coding\computer_network\FTP\cmake-build-debug D:\coding\computer_network\FTP\cmake-build-debug\CMakeFiles\FTP_Project.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FTP_Project.dir/depend

