# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/zhenrong1999/Projects/A2_CPT113

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhenrong1999/Projects/A2_CPT113

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/cmake-gui -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/zhenrong1999/Projects/A2_CPT113/CMakeFiles /home/zhenrong1999/Projects/A2_CPT113/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/zhenrong1999/Projects/A2_CPT113/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named A2_CPT112_Lib

# Build rule for target.
A2_CPT112_Lib: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 A2_CPT112_Lib
.PHONY : A2_CPT112_Lib

# fast build rule for target.
A2_CPT112_Lib/fast:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/build
.PHONY : A2_CPT112_Lib/fast

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

binarysearch.o: binarysearch.cpp.o

.PHONY : binarysearch.o

# target to build an object file
binarysearch.cpp.o:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/binarysearch.cpp.o
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/binarysearch.cpp.o
.PHONY : binarysearch.cpp.o

binarysearch.i: binarysearch.cpp.i

.PHONY : binarysearch.i

# target to preprocess a source file
binarysearch.cpp.i:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/binarysearch.cpp.i
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/binarysearch.cpp.i
.PHONY : binarysearch.cpp.i

binarysearch.s: binarysearch.cpp.s

.PHONY : binarysearch.s

# target to generate assembly for a file
binarysearch.cpp.s:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/binarysearch.cpp.s
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/binarysearch.cpp.s
.PHONY : binarysearch.cpp.s

book_info.o: book_info.cpp.o

.PHONY : book_info.o

# target to build an object file
book_info.cpp.o:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/book_info.cpp.o
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/book_info.cpp.o
.PHONY : book_info.cpp.o

book_info.i: book_info.cpp.i

.PHONY : book_info.i

# target to preprocess a source file
book_info.cpp.i:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/book_info.cpp.i
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/book_info.cpp.i
.PHONY : book_info.cpp.i

book_info.s: book_info.cpp.s

.PHONY : book_info.s

# target to generate assembly for a file
book_info.cpp.s:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/book_info.cpp.s
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/book_info.cpp.s
.PHONY : book_info.cpp.s

booking_list.o: booking_list.cpp.o

.PHONY : booking_list.o

# target to build an object file
booking_list.cpp.o:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/booking_list.cpp.o
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/booking_list.cpp.o
.PHONY : booking_list.cpp.o

booking_list.i: booking_list.cpp.i

.PHONY : booking_list.i

# target to preprocess a source file
booking_list.cpp.i:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/booking_list.cpp.i
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/booking_list.cpp.i
.PHONY : booking_list.cpp.i

booking_list.s: booking_list.cpp.s

.PHONY : booking_list.s

# target to generate assembly for a file
booking_list.cpp.s:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/booking_list.cpp.s
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/booking_list.cpp.s
.PHONY : booking_list.cpp.s

car_info.o: car_info.cpp.o

.PHONY : car_info.o

# target to build an object file
car_info.cpp.o:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/car_info.cpp.o
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/car_info.cpp.o
.PHONY : car_info.cpp.o

car_info.i: car_info.cpp.i

.PHONY : car_info.i

# target to preprocess a source file
car_info.cpp.i:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/car_info.cpp.i
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/car_info.cpp.i
.PHONY : car_info.cpp.i

car_info.s: car_info.cpp.s

.PHONY : car_info.s

# target to generate assembly for a file
car_info.cpp.s:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/car_info.cpp.s
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/car_info.cpp.s
.PHONY : car_info.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/main.cpp.o
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/main.cpp.i
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/main.cpp.s
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.s
.PHONY : main.cpp.s

mystack.o: mystack.cpp.o

.PHONY : mystack.o

# target to build an object file
mystack.cpp.o:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/mystack.cpp.o
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/mystack.cpp.o
.PHONY : mystack.cpp.o

mystack.i: mystack.cpp.i

.PHONY : mystack.i

# target to preprocess a source file
mystack.cpp.i:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/mystack.cpp.i
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/mystack.cpp.i
.PHONY : mystack.cpp.i

mystack.s: mystack.cpp.s

.PHONY : mystack.s

# target to generate assembly for a file
mystack.cpp.s:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/mystack.cpp.s
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/mystack.cpp.s
.PHONY : mystack.cpp.s

ordered_linked_list.o: ordered_linked_list.cpp.o

.PHONY : ordered_linked_list.o

# target to build an object file
ordered_linked_list.cpp.o:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/ordered_linked_list.cpp.o
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/ordered_linked_list.cpp.o
.PHONY : ordered_linked_list.cpp.o

ordered_linked_list.i: ordered_linked_list.cpp.i

.PHONY : ordered_linked_list.i

# target to preprocess a source file
ordered_linked_list.cpp.i:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/ordered_linked_list.cpp.i
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/ordered_linked_list.cpp.i
.PHONY : ordered_linked_list.cpp.i

ordered_linked_list.s: ordered_linked_list.cpp.s

.PHONY : ordered_linked_list.s

# target to generate assembly for a file
ordered_linked_list.cpp.s:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/ordered_linked_list.cpp.s
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/ordered_linked_list.cpp.s
.PHONY : ordered_linked_list.cpp.s

queue.o: queue.cpp.o

.PHONY : queue.o

# target to build an object file
queue.cpp.o:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/queue.cpp.o
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/queue.cpp.o
.PHONY : queue.cpp.o

queue.i: queue.cpp.i

.PHONY : queue.i

# target to preprocess a source file
queue.cpp.i:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/queue.cpp.i
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/queue.cpp.i
.PHONY : queue.cpp.i

queue.s: queue.cpp.s

.PHONY : queue.s

# target to generate assembly for a file
queue.cpp.s:
	$(MAKE) -f CMakeFiles/A2_CPT112_Lib.dir/build.make CMakeFiles/A2_CPT112_Lib.dir/queue.cpp.s
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/queue.cpp.s
.PHONY : queue.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... A2_CPT112_Lib"
	@echo "... edit_cache"
	@echo "... main"
	@echo "... binarysearch.o"
	@echo "... binarysearch.i"
	@echo "... binarysearch.s"
	@echo "... book_info.o"
	@echo "... book_info.i"
	@echo "... book_info.s"
	@echo "... booking_list.o"
	@echo "... booking_list.i"
	@echo "... booking_list.s"
	@echo "... car_info.o"
	@echo "... car_info.i"
	@echo "... car_info.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... mystack.o"
	@echo "... mystack.i"
	@echo "... mystack.s"
	@echo "... ordered_linked_list.o"
	@echo "... ordered_linked_list.i"
	@echo "... ordered_linked_list.s"
	@echo "... queue.o"
	@echo "... queue.i"
	@echo "... queue.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

