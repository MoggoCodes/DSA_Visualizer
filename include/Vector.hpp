#pragma once
#include <string>
#include <stdexcept>

class Vector {
public:
    // Constructors and destructor
    Vector(size_t initial_capacity = 2);
    Vector(const Vector& other);             // Copy constructor
    Vector& operator=(const Vector& other);  // Copy assignment
    ~Vector();                              // Destructor
    
    // Core operations
    void insert(int value);
    bool remove(int value);
    bool contains(int value) const;
    void clear();
    
    // Search operation
    int search(int value) const;  // Returns index of first occurrence or -1 if not found
    
    // Array-specific operations
    void push_back(int value);
    void pop_back();
    int& at(size_t index);
    const int& at(size_t index) const;
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    
    // Capacity operations
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }
    void reserve(size_t new_capacity);
    void shrink_to_fit();
    
    // Display methods
    void display() const;
    std::string getOperationDescription() const { return currentOperation; }
    
private:
    int* data_;            // Dynamic array
    size_t size_;         // Current number of elements
    size_t capacity_;     // Current capacity
    std::string currentOperation;
    
    // Helper methods
    void resize(size_t new_capacity);
    static constexpr size_t GROWTH_FACTOR = 2;
    static constexpr size_t MIN_CAPACITY = 2;
}; 