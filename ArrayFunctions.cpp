// ArrayFunctions.cpp
#include "ArrayFunctions.h"
#include <iostream>
#include <fstream>

// Constructor to read data from a file into a 2D array
ArrayFunctions::ArrayFunctions(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        // Throw a runtime error if the file cannot be opened
        throw std::runtime_error("Error opening file.");
    }

    // Reserves space for the 2D array (10x10)
    array.reserve(10);
    for (int i = 0; i < 10; ++i) {
        array.emplace_back(); 
        for (int j = 0; j < 10; ++j) {
            int value;
            inputFile >> value; // It reads an integer from the file
            array[i].push_back(value); // Adds the integer to the current row
        }
    }

    inputFile.close(); // Closes the file after reading
}

// Find the index of a specific target integer in the array
int ArrayFunctions::findIndex(int target) {
    for (int i = 0; i < array.size(); ++i) {
        for (int j = 0; j < array[i].size(); ++j) {
            if (array[i][j] == target) {
                return i * 10 + j; // Return the linear index
            }
        }
    }
    return -1; // Return -1 if the target is not found
}

// Function to modify the value at a given index and return the old and new values
std::pair<int, int> ArrayFunctions::modifyValue(int index, int newValue) {
    try {
        if (!isValidIndex(index)) {
            // Throw an out-of-range exception for an invalid index
            throw std::out_of_range("Invalid index");
        }

        int i = index / 10;
        int j = index % 10;
        int oldValue = array[i][j];
        array[i][j] = newValue; // Modify the value at the specified index

        return std::make_pair(oldValue, newValue);
    } catch (const std::out_of_range& e) {
        // Catch and handle an out-of-range exception, printing an error message
        std::cerr << "Error: " << e.what() << std::endl;
        return std::make_pair(-1, -1); // Return a pair with invalid values
    }
}

// Function to add an integer to the end of the array
void ArrayFunctions::addInteger(int value) {
    try {
        int i = array.size() - 1;
        if (i < 0 || array[i].size() == 10) {
            if (array.size() == 10) {
                // Throw an overflow error if the array is already full
                throw std::overflow_error("Array is full");
            } else {
                array.emplace_back(); // Create a new row if needed
                i++;
            }
        }
        array[i].push_back(value); // Add the integer to the current row
    } catch (const std::overflow_error& e) {
        // Catch and handle an overflow error, printing an error message
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Function to replace or remove an integer at a given index
void ArrayFunctions::replaceOrRemove(int index, bool remove) {
    try {
        if (!isValidIndex(index)) {
            // Throw an out-of-range exception for an invalid index
            throw std::out_of_range("Invalid index");
        }

        int i = index / 10;
        int j = index % 10;

        if (remove) {
            if (!array[i].empty() && j >= 0 && j < array[i].size()) {
                array[i].erase(array[i].begin() + j); // Remove the integer at the specified index
            }
        } else {
            array[i][j] = 0; // Replace the integer with 0 at the specified index
        }
    } catch (const std::out_of_range& e) {
        // Catch and handle an out-of-range exception, printing an error message
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Function to check if an index is valid
bool ArrayFunctions::isValidIndex(int index) const {
    return index >= 0 && index < 100;
}

// Function to retrieve the 2D array
const std::vector<std::vector<int>>& ArrayFunctions::getArray() const {
    return array;
}
