// ArrayFunctions.h
#ifndef ARRAYFUNCTIONS_H
#define ARRAYFUNCTIONS_H

#include <vector>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

class ArrayFunctions {
public:
    // Constructor to read data from a file into a 2D array
    ArrayFunctions(const std::string& filename);

    // Function to find the index of a specific target integer in the array
    int findIndex(int target);

    // Function to modify the value at a given index and return the old and new values
    std::pair<int, int> modifyValue(int index, int newValue);

    // Function to add an integer to the end of the array
    void addInteger(int value);

    // Function to replace or remove an integer at a given index
    void replaceOrRemove(int index, bool remove);

    // Function to retrieve the 2D array
    const std::vector<std::vector<int>>& getArray() const;

private:
    std::vector<std::vector<int>> array;

    // Function to check if an index is valid
    bool isValidIndex(int index) const;
};

#endif
