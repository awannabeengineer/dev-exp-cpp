cmake_minimum_required(VERSION 3.10)

# Set the project name
project(dev-exp-cpp VERSION 0.1.0)

# Include vcpkg
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

# include vcpkg path
if(DEFINED CMAKE_TOOLCHAIN_FILE)
    include(${CMAKE_TOOLCHAIN_FILE})
endif()

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Use ccache for faster builds
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
    set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
endif()

# Add the executable
add_executable(dev-exp-cpp src/main.cpp)


# Export compile commands for LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# include(${CMAKE_TOOLCHAIN_FILE})

# Find and link the fmt library
find_package(fmt CONFIG REQUIRED)
target_link_libraries(dev-exp-cpp PRIVATE fmt::fmt)

# Find and link the OpenCV library
find_package(OpenCV REQUIRED)
target_link_libraries(dev-exp-cpp PRIVATE ${OpenCV_LIBS})
