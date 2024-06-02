#!/bin/bash

# Set the project directory
PROJECT_DIR=$(dirname "$0")

"$PROJECT_DIR/vcpkg/vcpkg" install

# Create and enter the build directory
mkdir -p build
cd build || exit

# Configure the project with CMake
cmake -DCMAKE_TOOLCHAIN_FILE="$PROJECT_DIR/vcpkg/scripts/buildsystems/vcpkg.cmake" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

# Build the project
cmake --build .

# Confirm the location of compile_commands.json
if [ -f "compile_commands.json" ]; then
    echo "compile_commands.json has been successfully generated in the build directory."
else
    echo "Failed to generate compile_commands.json."
fi
