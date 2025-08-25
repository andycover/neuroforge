cmake_minimum_required(VERSION 3.10)
project(NeuroForge LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Executable
add_executable(neuroforge ${SOURCES})

# Testing (enable later)
enable_testing()
# Add Google Test submodule or find_package later

# For now, a simple build