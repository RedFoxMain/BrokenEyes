#include <iostream>
#include "utils.hpp"

/*
* +|-		-> inc or dec value			- done
* .			-> print value				- done
* ,			-> print with space			- done
* ;			-> print value with \n		- done
* []		-> [loop]					- done
* (){}		-> (cond) {if_true}			- done
* !			-> exit from loop			- done
* ^			-> clear value				- done
*/

// 72 101 108 108 111 44 32 87 111 114 108 100 33 -> Hello, World!
// +[(72){.}(101){.}(108){..}(111){.}+]+[(44){,!}+]+[(32){.}(87){.}(111){.}(114){.}+]+[(108){.}+]+[(100){.}+]+[(33){.!}+]

/* MAIN */
int main(int argc, char* argv[]) {
	if (argv[1] == NULL) {
		std::cerr << "BrokenEyes file_name.be";
		exit(1);
	}
	uint8_t value = 0;
	std::string code = readFromFile(argv[1]);
	std::remove_if(code.begin(), code.end(), isspace); // Remove all space
	vector_of_pairs braces = getBraces(code);
	std::stack<int> opened_loop_pos;
	for (size_t i = 0; i < code.size(); ++i) {
		char current_char = code[i];
		if (current_char == '!') {
			i = opened_loop_pos.top();
			opened_loop_pos.pop();
		}
		if(current_char == '+') ++value;
		if(current_char == '-') --value;
		if(current_char == '.') std::cout << static_cast<char>(value);
		if(current_char == ',') std::cout << static_cast<char>(value) << " ";
		if(current_char == ';') std::cout << static_cast<char>(value) << std::endl;
		if(current_char == '^') value = 0;
		if (current_char == '[') {
			if (value == 0) i = findCloseBrace(braces, i);
			else opened_loop_pos.push(findCloseBrace(braces, i));
		}
		if (current_char == ']') {
			if (value != 0) i = findOpenBrace(braces, i);
			else  opened_loop_pos.pop();
		}
		if (current_char == '(') {
			if (value != getDigit(code, ++i)) {
				i = findCloseBrace(braces, ++i);
			}
		}
	}
	return 0;
}