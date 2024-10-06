#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>
#include <map>

std::vector<std::string> readLines(const std::string& fileName);

void appendLine(const std::string& fileName, const std::string& content);

std::vector<int> stringToIntegerVector(const std::string& input);

std::vector<std::string> splitString(const std::string& mainStr, const std::string& delimiter = " ");

std::string calculateGrade(float point);

std::map<std::string, int> countLetters(const std::vector<std::string>& elements);

#endif // FILE_UTILS_H