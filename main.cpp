#include <iostream>
#include "util_functions.h"
#include <typeinfo>  // Required for typeid

int main() {
    std::vector<std::string> lines = readLines("part1_input.txt");  // Reading lines from file
    std::vector<int> lines_int_vector;
    std::vector<std::string> letter_grade_vector;

    // Loop over each string line
    for (const std::string& line : lines) {
        std::cout << "Original line: " << line << std::endl;  // Print the string line
        lines_int_vector = stringToIntegerVector(line);  // Convert string to integer vector
      
        float final_num = (lines_int_vector.at(0) * 4.0 / 10) + (lines_int_vector.at(1) * 6.0 / 10);
        std::string letter_grade = calculateGrade(final_num);
        letter_grade_vector.push_back(letter_grade);
        std::cout << std::endl;  // Move to the next line after printing all integers
    }
    countLetters(letter_grade_vector);

    return 0;
}