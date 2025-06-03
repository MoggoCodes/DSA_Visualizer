# Data Structures Visualizer

A C++ project that implements and visualizes common data structures. Currently features a custom Vector implementation with real-time visualization of internal operations via TUI.

## Features

### Custom Vector Implementation
- Dynamic array-based implementation with automatic resizing
- Initial capacity of 2 elements with 2x growth factor
- Visual representation of both used and reserved spaces
- Real-time operation feedback and capacity management

#### Supported Operations
- **Insert/Push Back**: Add elements to the vector
- **Remove**: Remove first occurrence of a value
- **Search**: Find index of first matching element
- **Contains**: Check if a value exists
- **Clear**: Remove all elements
- **Capacity Management**: Auto-resize, reserve, shrink_to_fit

### Visual Features
- Display of elements with reserved space visualization
- Index alignment under elements
- Operation feedback messages
- Capacity and size tracking
- Visual indication of empty slots using '_'

## Building the Project

The project now uses Make for building. Here are the available commands:

```bash
# Build the TUI (Terminal User Interface) version
make

# Build and run tests
make test

# Install the executable (requires sudo)
make install

# Clean build files
make clean
```

### Requirements
- C++17 compatible compiler
- GNU Make

### Project Structure
```
DSA_Visualizer/
├── include/
│   └── Vector.hpp       # Vector class declaration
├── src/
│   ├── Vector.cpp      # Vector implementation
│   └── tui.cpp         # Terminal UI implementation
├── tests/
│   └── vector_test.cpp # Comprehensive test suite
├── Makefile           # Build configuration
└── ReadMe.md          # This file
```

## Example Usage

```cpp
Vector v;               // Creates vector with capacity 2
v.push_back(1);        // [ 1 | _ ]
v.push_back(2);        // [ 1 | 2 ]
v.push_back(3);        // Resizes: [ 1 | 2 | 3 | _ ]
v.search(2);           // Returns 1, displays "Found value 2 at index 1"
```

### Sample Output
```
Vector contents:
Elements: [  1 |  2 |  3 |  _ ]
Indices:     0    1    2

Last operation: Found value 2 at index 1
Size: 3, Capacity: 4
```

## Testing

The project includes a comprehensive test suite covering:
- Basic operations (insert, remove, search)
- Memory management (resizing, copying)
- Edge cases and error handling
- Capacity management

Run tests using:
```bash
make test
```
