#include <iostream>
#include "util_functions.h"
#include <typeinfo>  // Required for typeid

int main() {
    std::vector<std::string> lines = readLines("part1_input.txt");  // Reading lines from file
    std::vector<int> lines_int_vector;

    // Loop over each string line
    for (const std::string& line : lines) {
        lines_int_vector = stringToIntegerVector(line);  // Convert string to integer vector
    }
    std::cout << calculateGrade(57) << std::endl;

    return 0;
}