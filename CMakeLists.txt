cmake_minimum_required(VERSION 3.10)

# Project name and version
project(VulkanApp VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Vulkan
find_package(Vulkan REQUIRED)

# Include directories
include_directories(${Vulkan_INCLUDE_DIRS})

# Add source files
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)

# Create the executable
add_executable(VulkanApp ${SOURCES} ${HEADERS})

# Link Vulkan library
target_link_libraries(VulkanApp Vulkan::Vulkan)

# Add GLFW (if you use it)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(VulkanApp ${GLFW_LIBRARIES})
