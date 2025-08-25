cmake_minimum_required(VERSION 3.10)
project(NeuroForge LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)
include_directories(extern/googletest/googletest/include)
include_directories(extern/googletest/googlemock/include)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Executable
add_executable(neuroforge ${SOURCES})

# Add Google Test submodule
add_subdirectory(extern/googletest)

# Enable testing
enable_testing()

# Test sources (gather all test files)
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

# Test executable
add_executable(unit_tests ${TEST_SOURCES} ${SOURCES})  # Link your sources if tests need them
target_link_libraries(unit_tests PRIVATE gtest gtest_main gmock gmock_main)  # pthread for threading support

# Add tests to CTest
add_test(NAME UnitTests COMMAND unit_tests)