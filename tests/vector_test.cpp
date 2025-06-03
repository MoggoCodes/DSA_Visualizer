#include "../include/Vector.hpp"
#include <cassert>
#include <iostream>

#define TEST(name) void name()
#define ASSERT(condition) do { \
    if (!(condition)) { \
        std::cerr << "Assertion failed: " << #condition << "\nFile: " << __FILE__ << "\nLine: " << __LINE__ << std::endl; \
        exit(1); \
    } \
} while(0)

// Test constructors and basic operations
TEST(test_constructor) {
    Vector v;
    ASSERT(v.size() == 0);
    ASSERT(v.capacity() >= 10);
    ASSERT(v.empty());
}

TEST(test_push_back) {
    Vector v;
    v.push_back(1);
    ASSERT(v.size() == 1);
    ASSERT(v[0] == 1);
    
    v.push_back(2);
    ASSERT(v.size() == 2);
    ASSERT(v[0] == 1);
    ASSERT(v[1] == 2);
}

TEST(test_copy_constructor) {
    Vector v1;
    v1.push_back(1);
    v1.push_back(2);
    
    Vector v2(v1);
    ASSERT(v2.size() == 2);
    ASSERT(v2[0] == 1);
    ASSERT(v2[1] == 2);
    
    // Modify v1 and check v2 is unaffected
    v1[0] = 3;
    ASSERT(v2[0] == 1);
}

TEST(test_assignment_operator) {
    Vector v1;
    v1.push_back(1);
    v1.push_back(2);
    
    Vector v2;
    v2 = v1;
    ASSERT(v2.size() == 2);
    ASSERT(v2[0] == 1);
    ASSERT(v2[1] == 2);
    
    // Modify v1 and check v2 is unaffected
    v1[0] = 3;
    ASSERT(v2[0] == 1);
}

TEST(test_at) {
    Vector v;
    v.push_back(1);
    v.push_back(2);
    
    ASSERT(v.at(0) == 1);
    ASSERT(v.at(1) == 2);
    
    bool exception_thrown = false;
    try {
        v.at(2);
    } catch (const std::out_of_range&) {
        exception_thrown = true;
    }
    ASSERT(exception_thrown);
}

TEST(test_search) {
    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);  // Duplicate value
    v.push_back(3);
    
    // Test finding first occurrence
    ASSERT(v.search(1) == 0);
    ASSERT(v.search(2) == 1);  // Returns first occurrence
    ASSERT(v.search(3) == 3);
    
    // Test non-existent value
    ASSERT(v.search(4) == -1);
    
    // Test on empty vector
    Vector empty;
    ASSERT(empty.search(1) == -1);
}

TEST(test_remove) {
    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    ASSERT(v.remove(2));
    ASSERT(v.size() == 2);
    ASSERT(v[0] == 1);
    ASSERT(v[1] == 3);
    
    ASSERT(!v.remove(4));  // Try to remove non-existent element
    ASSERT(v.size() == 2);
}

TEST(test_contains) {
    Vector v;
    v.push_back(1);
    v.push_back(2);
    
    ASSERT(v.contains(1));
    ASSERT(v.contains(2));
    ASSERT(!v.contains(3));
}

TEST(test_clear) {
    Vector v;
    v.push_back(1);
    v.push_back(2);
    
    v.clear();
    ASSERT(v.empty());
    ASSERT(v.size() == 0);
}

TEST(test_capacity_operations) {
    Vector v;
    size_t initial_capacity = v.capacity();
    
    // Fill to capacity
    for (size_t i = 0; i < initial_capacity; ++i) {
        v.push_back(i);
    }
    ASSERT(v.size() == initial_capacity);
    
    // Add one more element to trigger growth
    v.push_back(100);
    ASSERT(v.capacity() > initial_capacity);
    ASSERT(v.size() == initial_capacity + 1);
    
    // Test reserve
    size_t new_capacity = v.capacity() * 2;
    v.reserve(new_capacity);
    ASSERT(v.capacity() >= new_capacity);
    
    // Test shrink_to_fit
    v.shrink_to_fit();
    ASSERT(v.capacity() == v.size());
}

int main() {
    std::cout << "Running Vector tests...\n";
    
    test_constructor();
    test_push_back();
    test_copy_constructor();
    test_assignment_operator();
    test_at();
    test_search();
    test_remove();
    test_contains();
    test_clear();
    test_capacity_operations();
    
    std::cout << "All tests passed!\n";
    return 0;
} 