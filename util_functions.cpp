#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <iostream>
#include "util_functions.h"


std::vector<std::string> letters = {"A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3", "D", "F1", "F2", "F3"};

// Helper function to replace tabs with single space and remove extra spaces
static inline std::string cleanSpaces(const std::string& str) {
    std::string result;
    bool lastWasSpace = false;
    for (char c : str) {
        if (c == ' ' || c == '\t') {
            if (!lastWasSpace) {
                result += ' ';
                lastWasSpace = true;
            }
        } else {
            result += c;
            lastWasSpace = false;
        }
    }
    return result;
}

/**
 * Reads the contents of a file and stores each line as a string in a vector.
 *
 * @param fileName The name of the file to read.
 * @return A vector of strings containing the lines from the file.
 * @note If the file cannot be opened, the program exits with a status code of -1.
 */
std::vector<std::string> readLines(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;
    std::vector<std::string> student_grades;
    
    if (file.is_open()) {
        while (std::getline(file, line)) {
            // Clean the line: replace tabs with spaces and remove extra spaces
            line = cleanSpaces(line);
            
            
            if (!line.empty()) {
                student_grades.push_back(line);
                std::cout << line << std::endl;  // Print cleaned line
            }
        }
        file.close();
    } else {
        std::cout << "Dosya acilamadi!" << std::endl;
        std::exit(-1);  // Use std::exit instead of exit
    }
    
    return student_grades;
}

/**
 * Appends a string to a file as a new line.
 *
 * @param fileName The name of the file to append to.
 * @param content The string to be appended as a new line.
 */
void appendLine(const std::string& fileName, const std::string& content) {
    std::ofstream file;

    file.open(fileName, std::ios::app);

    if (file.is_open()) {
        file << content << std::endl; 
        file.close(); 
        std::cout << "Line appended successfully!" << std::endl;
    }
    else{
        std::cout << "Dosya acilamadi!" << std::endl;
        exit(-1);
    }
}

/**
 * Converts a space-separated string of integers into a vector of integers.
 *
 * @param input The input string containing space-separated integers.
 * @return A vector of integers.
 */
std::vector<int> stringToIntegerVector(const std::string& input) {
    std::vector<int> result;
    std::string word = "";

    for(char ch:input){
        if(ch == ' '){
            if(!word.empty()){
                try{                
                    result.push_back(stoi(word));
                    word = "";
                }
                catch(const std::invalid_argument& e){
                    std::cerr << "Invalid argument: " << e.what() << std::endl;
                }
            }
        }

        else{
            word += ch;  
        }
    }
     if (!word.empty()) {
        result.push_back(stoi(word));
    }
return result;
}

/**
 * This function calculates the letter grade based on the given grade point.
 *
 * @param point: Grade point (float)
 * @return: Letter grade (std::string)
 */
std::string calculateGrade(float point) {
    float map_acces_index = 20 - (point / 5);
    int units_digit = static_cast<int>(map_acces_index) % 10;
    return letters.at(units_digit);

}
