#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored status messages
print_status() {
    echo -e "${BLUE}[BUILD]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

# Check if build directory exists
if [ -d "build" ]; then
    print_status "Removing existing build directory..."
    rm -rf build
fi

# Create and enter build directory
print_status "Creating build directory..."
mkdir build
cd build

# Configure with CMake
print_status "Configuring with CMake..."
if [ "$1" == "test" ]; then
    cmake -DBUILD_TESTS=ON ..
    
    if [ $? -eq 0 ]; then
        print_status "Building tests..."
        make vector_test
        
        if [ $? -eq 0 ]; then
            print_success "Build successful! Run tests with: ./vector_test"
        else
            echo "Error: Build failed"
            exit 1
        fi
    else
        echo "Error: CMake configuration failed"
        exit 1
    fi
else
    cmake ..
    
    if [ $? -eq 0 ]; then
        print_status "Building TUI..."
        make dsa_tui
        
        if [ $? -eq 0 ]; then
            print_success "Build successful! Run with: ./build/dsa_tui"
        else
            echo "Error: Build failed"
            exit 1
        fi
    else
        echo "Error: CMake configuration failed"
        exit 1
    fi
fi 