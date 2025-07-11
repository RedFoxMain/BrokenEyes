#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <cstdint>
#include <stack>
#include <vector>
#include <algorithm>
#include <fstream>

using vector_of_pairs = std::vector<std::pair<int, int>>;

vector_of_pairs getBraces(const std::string& text);
int findOpenBrace(const vector_of_pairs& vec, size_t index);
int findCloseBrace(const vector_of_pairs& vec, size_t index);
int getDigit(const std::string& code, size_t& pos);
std::string readFromFile(const char* file_name);
#endif // !UTILS_HPP