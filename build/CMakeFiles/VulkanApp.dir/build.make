# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alderson/Projects/Mine/vulkan-engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alderson/Projects/Mine/vulkan-engine/build

# Include any dependencies generated for this target.
include CMakeFiles/VulkanApp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/VulkanApp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/VulkanApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VulkanApp.dir/flags.make

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.o: CMakeFiles/VulkanApp.dir/flags.make
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.o: /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanBufferManager.cpp
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.o: CMakeFiles/VulkanApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alderson/Projects/Mine/vulkan-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.o -MF CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.o.d -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.o -c /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanBufferManager.cpp

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanBufferManager.cpp > CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.i

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanBufferManager.cpp -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.s

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.o: CMakeFiles/VulkanApp.dir/flags.make
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.o: /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanContext.cpp
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.o: CMakeFiles/VulkanApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alderson/Projects/Mine/vulkan-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.o -MF CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.o.d -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.o -c /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanContext.cpp

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanContext.cpp > CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.i

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanContext.cpp -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.s

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.o: CMakeFiles/VulkanApp.dir/flags.make
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.o: /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanDescriptors.cpp
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.o: CMakeFiles/VulkanApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alderson/Projects/Mine/vulkan-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.o -MF CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.o.d -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.o -c /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanDescriptors.cpp

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanDescriptors.cpp > CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.i

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanDescriptors.cpp -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.s

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.o: CMakeFiles/VulkanApp.dir/flags.make
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.o: /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanGraphicsPipeline.cpp
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.o: CMakeFiles/VulkanApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alderson/Projects/Mine/vulkan-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.o -MF CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.o.d -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.o -c /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanGraphicsPipeline.cpp

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanGraphicsPipeline.cpp > CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.i

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanGraphicsPipeline.cpp -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.s

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.o: CMakeFiles/VulkanApp.dir/flags.make
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.o: /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanImageHandler.cpp
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.o: CMakeFiles/VulkanApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alderson/Projects/Mine/vulkan-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.o -MF CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.o.d -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.o -c /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanImageHandler.cpp

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanImageHandler.cpp > CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.i

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanImageHandler.cpp -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.s

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.o: CMakeFiles/VulkanApp.dir/flags.make
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.o: /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanManager.cpp
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.o: CMakeFiles/VulkanApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alderson/Projects/Mine/vulkan-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.o -MF CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.o.d -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.o -c /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanManager.cpp

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanManager.cpp > CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.i

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanManager.cpp -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.s

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.o: CMakeFiles/VulkanApp.dir/flags.make
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.o: /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanSingleTimeCommand.cpp
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.o: CMakeFiles/VulkanApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alderson/Projects/Mine/vulkan-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.o -MF CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.o.d -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.o -c /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanSingleTimeCommand.cpp

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanSingleTimeCommand.cpp > CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.i

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanSingleTimeCommand.cpp -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.s

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.o: CMakeFiles/VulkanApp.dir/flags.make
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.o: /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanSwapChain.cpp
CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.o: CMakeFiles/VulkanApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alderson/Projects/Mine/vulkan-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.o -MF CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.o.d -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.o -c /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanSwapChain.cpp

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanSwapChain.cpp > CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.i

CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/VulkanSwapChain.cpp -o CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.s

CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.o: CMakeFiles/VulkanApp.dir/flags.make
CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.o: /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/Window.cpp
CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.o: CMakeFiles/VulkanApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alderson/Projects/Mine/vulkan-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.o -MF CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.o.d -o CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.o -c /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/Window.cpp

CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/Window.cpp > CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.i

CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alderson/Projects/Mine/vulkan-engine/src/engine/backend/Window.cpp -o CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.s

CMakeFiles/VulkanApp.dir/src/main.cpp.o: CMakeFiles/VulkanApp.dir/flags.make
CMakeFiles/VulkanApp.dir/src/main.cpp.o: /home/alderson/Projects/Mine/vulkan-engine/src/main.cpp
CMakeFiles/VulkanApp.dir/src/main.cpp.o: CMakeFiles/VulkanApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alderson/Projects/Mine/vulkan-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/VulkanApp.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VulkanApp.dir/src/main.cpp.o -MF CMakeFiles/VulkanApp.dir/src/main.cpp.o.d -o CMakeFiles/VulkanApp.dir/src/main.cpp.o -c /home/alderson/Projects/Mine/vulkan-engine/src/main.cpp

CMakeFiles/VulkanApp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VulkanApp.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alderson/Projects/Mine/vulkan-engine/src/main.cpp > CMakeFiles/VulkanApp.dir/src/main.cpp.i

CMakeFiles/VulkanApp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VulkanApp.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alderson/Projects/Mine/vulkan-engine/src/main.cpp -o CMakeFiles/VulkanApp.dir/src/main.cpp.s

# Object files for target VulkanApp
VulkanApp_OBJECTS = \
"CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.o" \
"CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.o" \
"CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.o" \
"CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.o" \
"CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.o" \
"CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.o" \
"CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.o" \
"CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.o" \
"CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.o" \
"CMakeFiles/VulkanApp.dir/src/main.cpp.o"

# External object files for target VulkanApp
VulkanApp_EXTERNAL_OBJECTS =

VulkanApp: CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanBufferManager.cpp.o
VulkanApp: CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanContext.cpp.o
VulkanApp: CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanDescriptors.cpp.o
VulkanApp: CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanGraphicsPipeline.cpp.o
VulkanApp: CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanImageHandler.cpp.o
VulkanApp: CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanManager.cpp.o
VulkanApp: CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSingleTimeCommand.cpp.o
VulkanApp: CMakeFiles/VulkanApp.dir/src/engine/backend/VulkanSwapChain.cpp.o
VulkanApp: CMakeFiles/VulkanApp.dir/src/engine/backend/Window.cpp.o
VulkanApp: CMakeFiles/VulkanApp.dir/src/main.cpp.o
VulkanApp: CMakeFiles/VulkanApp.dir/build.make
VulkanApp: /usr/lib/x86_64-linux-gnu/libvulkan.so
VulkanApp: CMakeFiles/VulkanApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/alderson/Projects/Mine/vulkan-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable VulkanApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VulkanApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VulkanApp.dir/build: VulkanApp
.PHONY : CMakeFiles/VulkanApp.dir/build

CMakeFiles/VulkanApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VulkanApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VulkanApp.dir/clean

CMakeFiles/VulkanApp.dir/depend:
	cd /home/alderson/Projects/Mine/vulkan-engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alderson/Projects/Mine/vulkan-engine /home/alderson/Projects/Mine/vulkan-engine /home/alderson/Projects/Mine/vulkan-engine/build /home/alderson/Projects/Mine/vulkan-engine/build /home/alderson/Projects/Mine/vulkan-engine/build/CMakeFiles/VulkanApp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/VulkanApp.dir/depend

