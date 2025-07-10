#include "utils.hpp"

vector_of_pairs getBraces(const std::string& text) {
	std::stack<int> st;
	vector_of_pairs temp;
	for (size_t i = 0; i < text.size(); ++i) {
		if (text[i] == '[' || text[i] == '(' || text[i] == '{') st.push(i);
		if (text[i] == ']' || text[i] == ')' || text[i] == '}') {
			if (!st.empty()) {
				int pos = st.top(); st.pop();
				temp.push_back({ pos, i });
			}
		}
	}
	return temp;
}

int findOpenBrace(const vector_of_pairs& vec, size_t index) {
	auto iter = std::find_if(vec.begin(), vec.end(), [index](const auto& pair) {
		return pair.second == index;
	});
	return (iter != vec.end()) ? iter->first : -1;
}

int findCloseBrace(const vector_of_pairs& vec, size_t index) {
	auto iter = std::find_if(vec.begin(), vec.end(), [index](const auto& pair) {
		return pair.first == index;
	});
	return (iter != vec.end()) ? iter->second : -1;
}

std::string readFromFile(const char* file_name) {
	std::string code;
	std::ifstream file(file_name);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) code += line;
	}
	file.close();
	return code;
}

uint8_t getDigit(const std::string& code, size_t& pos) {
	std::string temp;
	while (std::isdigit(code[pos]) && code[pos] != ')') temp += code[pos++];
	return static_cast<uint8_t>(std::stoi(temp));
}