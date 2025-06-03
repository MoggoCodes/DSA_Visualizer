#include "Vector.hpp"
#include <cstring>

// Constructor
Vector::Vector(size_t initial_capacity) 
    : size_(0), capacity_(std::max(initial_capacity, MIN_CAPACITY)) {
    data_ = new int[capacity_];
}

// Copy constructor
Vector::Vector(const Vector& other) 
    : size_(other.size_), capacity_(other.capacity_) {
    data_ = new int[capacity_];
    std::memcpy(data_, other.data_, size_ * sizeof(int));
    currentOperation = other.currentOperation;
}

// Copy assignment operator
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new int[capacity_];
        std::memcpy(data_, other.data_, size_ * sizeof(int));
        currentOperation = other.currentOperation;
    }
    return *this;
}

// Destructor
Vector::~Vector() {
    delete[] data_;
}

// Core operations
void Vector::insert(int value) {
    push_back(value);
    currentOperation = "Inserted " + std::to_string(value);
}

bool Vector::remove(int value) {
    int index = search(value);
    if (index != -1) {
        // Shift elements left to fill the gap
        std::memmove(&data_[index], &data_[index + 1], (size_ - index - 1) * sizeof(int));
        --size_;
        currentOperation = "Removed " + std::to_string(value);
        return true;
    }
    currentOperation = "Value " + std::to_string(value) + " not found";
    return false;
}

bool Vector::contains(int value) const {
    return search(value) != -1;
}

int Vector::search(int value) const {
    for (size_t i = 0; i < size_; ++i) {
        if (data_[i] == value) {
            currentOperation = "Found value " + std::to_string(value) + " at index " + std::to_string(i);
            return i;
        }
    }
    currentOperation = "Value " + std::to_string(value) + " not found in vector";
    return -1;
}

void Vector::clear() {
    size_ = 0;
    currentOperation = "Cleared vector";
}

// Array-specific operations
void Vector::push_back(int value) {
    if (size_ == capacity_) {
        size_t new_capacity = capacity_ * GROWTH_FACTOR;
        currentOperation = "Resizing vector from " + std::to_string(capacity_) + 
                         " to " + std::to_string(new_capacity) + " to add " + std::to_string(value);
        resize(new_capacity);
    } else {
        currentOperation = "Inserted " + std::to_string(value);
    }
    data_[size_++] = value;
}

void Vector::pop_back() {
    if (size_ > 0) --size_;
}

int& Vector::at(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

const int& Vector::at(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

int& Vector::operator[](size_t index) {
    return data_[index];
}

const int& Vector::operator[](size_t index) const {
    return data_[index];
}

// Capacity operations
void Vector::reserve(size_t new_capacity) {
    if (new_capacity > capacity_) {
        resize(new_capacity);
    }
}

void Vector::shrink_to_fit() {
    if (capacity_ > size_) {
        resize(size_);
    }
}

// Helper methods
void Vector::resize(size_t new_capacity) {
    if (new_capacity < size_) return;  // Don't shrink below current size
    
    int* new_data = new int[new_capacity];
    std::memcpy(new_data, data_, size_ * sizeof(int));
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

// Display method
void Vector::display() const {
    std::cout << "\nVector contents:\n";
    if (empty()) {
        std::cout << "Empty (capacity: " << capacity_ << ")\n";
        return;
    }
    
    // Print elements
    std::cout << "Elements: [ ";
    for (size_t i = 0; i < capacity_; ++i) {
        if (i < size_) {
            std::cout << std::setw(3) << data_[i];
        } else {
            std::cout << std::setw(3) << "_";
        }
        if (i < capacity_ - 1) {
            std::cout << " | ";
        }
    }
    std::cout << " ]\n";
    
    // Print indices aligned with elements
    std::cout << "Indices:  ";  // 2 spaces after colon
    std::cout << "  ";         // 2 spaces to account for "[ "
    for (size_t i = 0; i < size_; ++i) {
        std::cout << std::setw(3) << i;
        if (i < size_ - 1) {
            std::cout << "   ";  // 3 spaces to match the " | " above
        }
    }
    std::cout << "\n\n";
    
    // Print last operation
    std::cout << "Last operation: " << currentOperation << "\n";
    std::cout << "Size: " << size_ << ", Capacity: " << capacity_ << "\n";
} 