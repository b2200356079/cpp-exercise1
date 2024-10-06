#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <iostream>
#include "util_functions.h"


std::vector<std::string> letters = {"A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3", "D", "F1", "F2", "F3"};


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
        while (std::getline(file, line)) {  // Dosyayı satır satır okur
            student_grades.push_back(line);
            std::cout << line << std::endl;  // Her satırı ekrana yazdırır
        }
        file.close();  // Dosyayı kapatır
    } else {
        std::cout << "Dosya acilamadi!" << std::endl;
        exit(-1);
    }
    return student_grades;
    //Fill this method.

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
