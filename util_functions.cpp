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

    std::vector<std::string> str_vector = splitString(input, " ");
    for(std::string str_number:str_vector){
        int num = stoi(str_number);
        result.push_back(num);

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
    if(point < 50){
        return letters.at(12);
    }
    float map_acces_index = 20 - (point / 5);
    int units_digit = static_cast<int>(map_acces_index);
    return letters.at(units_digit);

}

int countOccurrences(const std::vector<std::string>& vec, const std::string& target) {
    int count = 0;
    for (const std::string& str : vec) {
        if (str == target) {
            count++;
        }
    }
    return count;
}

/**
 * Returns the frequencies of letters grades in a vector<string> as a map.
 * Takes parameter as a vector such as {"A1", "A2", "F1", "B3"}
 *
 * @param elements: The array containing elements (std::vector<std::string>)
 * @return: A map containing the counts of elements (std::map<std::string, int>)
 */
std::map<std::string, int> countLetters(const std::vector<std::string>& elements) {
    std::map<std::string, int> letter_map;

    for (size_t i = 0; i < letters.size(); ++i) {
        letter_map[letters[i]] = 0;  // Anahtarlara karşılık gelen değerlere örnek olarak sıra numarası atayalım
    }

    for(std::string element:elements){
        letter_map[element] = countOccurrences(elements, element);
    }

    // Print all key-value pairs in the map
    for (const auto& pair : letter_map) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return letter_map;

}

std::vector<std::string> splitString(const std::string& mainStr, const std::string& delimiter) {
    std::vector<std::string> result;
    std::string word = "";

    for (char ch : mainStr) {
        // delimiter[0] kullanarak string'in ilk karakteri ile karşılaştırma yapıyoruz
        if (ch == delimiter[0]) {
            if (!word.empty()) {
                result.push_back(word);  // word'u vektöre ekle
                word = "";  // word'u sıfırla
            }
        } else {
            word += ch;  // word'e karakter ekle
        }
    }

    // Son kelimeyi ekle
    if (!word.empty()) {
        result.push_back(word);
    }

    return result;
}