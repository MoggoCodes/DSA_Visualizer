cmake_minimum_required(VERSION 3.10)
project(DSA_Visualizer VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Option to build tests (OFF by default)
option(BUILD_TESTS "Build the test suite" OFF)

if(NOT BUILD_TESTS)
    # Add source files for TUI
    file(GLOB_RECURSE TUI_SOURCES 
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
    )
    list(FILTER TUI_SOURCES EXCLUDE REGEX ".*test.*")
    
    # Create executable for TUI version
    add_executable(dsa_tui ${TUI_SOURCES})
else()
    # Create test executable
    add_executable(vector_test tests/vector_test.cpp src/Vector.cpp)
endif()

# Add test target
add_custom_target(run_tests
    COMMAND vector_test
    DEPENDS vector_test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
) 