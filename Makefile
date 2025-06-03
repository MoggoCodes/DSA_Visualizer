CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./include
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Main executable
TARGET = $(BUILD_DIR)/dsa_tui

# Test files
TEST_SOURCES = tests/vector_test.cpp src/Vector.cpp
TEST_TARGET = $(BUILD_DIR)/vector_test

.PHONY: all clean test dirs

all: dirs $(TARGET)

# Create build directory
dirs:
	@mkdir -p $(BUILD_DIR)

# Main target
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Test target
test: dirs $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_SOURCES)
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET)

# Install target (copies executable to /usr/local/bin)
install: all
	@echo "Installing to /usr/local/bin..."
	@sudo cp $(TARGET) /usr/local/bin/dsa_tui

# Clean build files
clean:
	rm -rf $(BUILD_DIR)
	rm -f $(TARGET) $(TEST_TARGET) 