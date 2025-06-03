#include "Vector.hpp"
#include <iostream>
#include <limits>

void printMenu() {
    std::cout << "\nVector Operations:\n"
              << "1. Insert value\n"
              << "2. Remove value\n"
              << "3. Search value\n"
              << "4. Clear vector\n"
              << "5. Display vector\n"
              << "0. Exit\n"
              << "Enter choice: ";
}

int main() {
    Vector vec;
    int choice, value;
    
    std::cout << "Data Structure Visualizer - Vector\n";
    
    while (true) {
        printMenu();
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        
        switch (choice) {
            case 0:
                std::cout << "Exiting...\n";
                return 0;
                
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number.\n";
                    continue;
                }
                vec.insert(value);
                vec.display();
                break;
                
            case 2:
                std::cout << "Enter value to remove: ";
                std::cin >> value;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number.\n";
                    continue;
                }
                if (vec.remove(value)) {
                    std::cout << "Value removed successfully.\n";
                } else {
                    std::cout << "Value not found.\n";
                }
                vec.display();
                break;
                
            case 3:
                std::cout << "Enter value to search: ";
                std::cin >> value;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number.\n";
                    continue;
                }
                if (vec.contains(value)) {
                    std::cout << "Value found in the vector.\n";
                } else {
                    std::cout << "Value not found in the vector.\n";
                }
                vec.display();
                break;
                
            case 4:
                vec.clear();
                std::cout << "Vector cleared.\n";
                vec.display();
                break;
                
            case 5:
                vec.display();
                break;
                
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    
    return 0;
} 