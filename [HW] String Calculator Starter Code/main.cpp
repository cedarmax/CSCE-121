#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

int main() {
    std::cout << "String Calculator" << std::endl;
    std::cout << "\"q\" or \"quit\" or ctrl+d to exit" << std::endl;
    
    // TODO(student): implement the UI
       
    std::string lhs = "";
    std::string operation = "";
    std::string rhs = "";
    
    while (true) {
    std::cout << ">>" << std::flush;
    std::cin >> lhs;
    	if (lhs == "q" or lhs == "quit") {
    		std::cout << std::endl << "farvel!" << std::endl;
    		break;
    	}
	std::cin >> operation;
	std::cin >> rhs;

	bool lhs_negative = false;
	bool rhs_negative = false;
	bool sum_subtract_instead = false;

	if (lhs[0] == '-') {
		lhs_negative = true;
	}
	if (rhs[0] == '-') {
		rhs_negative = true;
	}
	if ((lhs_negative and not rhs_negative) or (rhs_negative and not lhs_negative)) {
		sum_subtract_instead = true;
	}

	std::string result = "";

	if (operation == "+") {
		if (sum_subtract_instead) {
			result = subtract(lhs, rhs);
			std::cout << std::endl << "ans =\n\n    " << result << std::endl << std::endl;
		} else {
			result = add(lhs, rhs);
			std::cout << std::endl << "ans =\n\n    " << result << std::endl << std::endl;
		}
	} else if (operation == "*") {
		result = multiply(lhs, rhs);	
		std::cout << std::endl << "ans =\n\n    " << result << std::endl << std::endl;
	} else if (operation == "-") {
		result = subtract(lhs, rhs);
		std::cout << std::endl << "ans =\n\n    " << result << std::endl << std::endl;
	} else {
		std::cout << "Invalid operator" << std::endl;
	}
	}
}

