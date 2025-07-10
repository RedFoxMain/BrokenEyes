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
// +[(72){.}(101){.}(108){..}(111){.}+]+[(44){,!}+]+[(32){.}(87){.}(111){.}(114){.}------.+++++++]+[(33){.!}+]

/* MAIN */
int main(int argc, char* argv) {
	uint8_t value = 0;
	std::string code = "+[(72){.}(101){.}(108){..}(111){.}+]+[(44){,!}+]+[(32){.}(87){.}(111){.}(114){.}+]+[(108){.}+]+[(100){.}+]+[(33){.!}+]";
	vector_of_pairs braces = getBraces(code);
	std::stack<int> opened_loop_pos;
	for (size_t i = 0; i < code.size(); ++i) {
		if (code[i] == '!') {
			i = opened_loop_pos.top() + 1;
			opened_loop_pos.pop();
		}
		if (code[i] == '+') ++value;
		if (code[i] == '-') --value;
		if (code[i] == '.') std::cout << static_cast<char>(value);
		if (code[i] == ',') std::cout << static_cast<char>(value) << " ";
		if (code[i] == ';') std::cout << static_cast<char>(value) << std::endl;
		if (code[i] == '[') {
			if (value == 0) i = findCloseBrace(braces, i);
			else opened_loop_pos.push(findCloseBrace(braces, i));
		} else if (code[i] == ']')
			if (value != 0) i = findOpenBrace(braces, i);
		if (code[i] == '(') {
			if (value != getDigit(code, ++i)) {
				i = findCloseBrace(braces, ++i);
			}
		}
	}
	return 0;
}