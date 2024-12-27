#!/bin/bash

# Define the build directory
BUILD_DIR="build"

# Check if the build directory exists
if [ ! -d "$BUILD_DIR" ]; then
  echo "Build directory does not exist. Creating $BUILD_DIR..."
  mkdir "$BUILD_DIR"
fi

# Navigate to the build directory
cd "$BUILD_DIR" || exit

# Run cmake
echo "Running cmake .."
cmake .. || { echo "CMake failed"; exit 1; }

# Run make
echo "Running make"
make || { echo "Make failed"; exit 1; }

echo "Build completed successfully!"

