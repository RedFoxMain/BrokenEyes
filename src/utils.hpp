#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <cstdint>
#include <stack>
#include <vector>
#include <algorithm>

using vector_of_pairs = std::vector<std::pair<int, int>>;

vector_of_pairs getBraces(const std::string& text);
int findOpenBrace(const vector_of_pairs& vec, size_t index);
int findCloseBrace(const vector_of_pairs& vec, size_t index);
uint8_t getDigit(const std::string& code, size_t& pos);
#endif // !UTILS_HPP