// Bernardo Dias
// CS 303
// Assignment 1
// September 14, 2023
// main.cpp
// This program reads an input file containing a 2D array of integers and performs operations on the array.

#include "ArrayFunctions.h"
#include <iostream>

using namespace std;

int main() {
    try {
        // Create the instance of ArrayFunctions to read the data from "data.txt"
        ArrayFunctions arrayFunctions("data.txt");

        int target;
        cout << "Enter the number you want to search for: ";
        cin >> target;

        // check if a certain integer exists in the array
        int index = arrayFunctions.findIndex(target);
        if (index != -1) {
            cout << "Integer " << target << " found at index " << index << endl;
        } else {
            cout << "Integer " << target << " not found in the array." << endl;
        }

        int modifyIndex, newValue;
        cout << "Enter the new index: ";
        cin >> modifyIndex;
        cout << "Enter a new value: ";
        cin >> newValue;

        // A function that can modify the value of an integer when called with the index of the integer in the array
        pair<int, int> modifyResult = arrayFunctions.modifyValue(modifyIndex, newValue);
        cout << "Modified: Old value = " << modifyResult.first << ", New value = " << modifyResult.second << endl;

        int addValue;
        cout << "Enter an integer you want to add to the end of the array: ";
        cin >> addValue;

        // adds a new integer to the end of the array
        arrayFunctions.addInteger(addValue);
        cout << "Added integer " << addValue << " to the end of the array." << endl;

        int removeIndex;
        cout << "Enter the index you want to remove from the array: ";
        cin >> removeIndex;

        // Remove the integer at the index
        arrayFunctions.replaceOrRemove(removeIndex, true);
        cout << "Removed integer at index " << removeIndex << endl;

        // Print the modified array
        cout << "Modified Array:" << endl;
        const vector<vector<int>>& modifiedArray = arrayFunctions.getArray();
        for (const auto& row : modifiedArray) {
            for (int value : row) {
                if (value != 0) {
                    cout << value << ", "; // Print non-zero values in the row
                }
            }
            cout << endl; // Move to the next row
        }

        return 0; // Return 0 to the execution
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl; // Print exceptions
        return 1; // Return 1 to indicate an error occurred
    }
}
