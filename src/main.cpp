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
		switch (code[i]) {
			case '!':
				i = opened_loop_pos.top() + 1;
				opened_loop_pos.pop();
				break;
			case '+': ++value; break;
			case '-': --value; break;
			case '.': std::cout << static_cast<char>(value); break;
			case ',': std::cout << static_cast<char>(value) << " "; break;
			case ';': std::cout << static_cast<char>(value) << std::endl; break;
			case '[':
				if (value == 0) i = findCloseBrace(braces, i);
				else opened_loop_pos.push(findCloseBrace(braces, i));
				break;
			case ']':
				if (value != 0) i = findOpenBrace(braces, i);
				break;
			case '(':
				if (value != getDigit(code, ++i)) {
					i = findCloseBrace(braces, ++i);
				}
				break;
		}
	}
	return 0;
}