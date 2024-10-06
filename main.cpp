#include <iostream>
#include "util_functions.h"
#include <typeinfo>  // Required for typeid

int main() {
    std::vector<std::string> lines = readLines("part1_input.txt");  // Reading lines from file
    std::vector<int> lines_int_vector;

    // Loop over each string line
    for (const std::string& line : lines) {
        std::cout << "Original line: " << line << std::endl;  // Print the string line
        lines_int_vector = stringToIntegerVector(line);  // Convert string to integer vector

        // Now print the integer vector
        std::cout << "Converted integers: ";
        for (int num : lines_int_vector) {
            std::cout << num << " ";  // Print each integer in the vector
        }
        std::cout << std::endl;  // Move to the next line after printing all integers
    }

    return 0;
}