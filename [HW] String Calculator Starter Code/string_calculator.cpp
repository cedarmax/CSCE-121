#include <iostream>
#include <string>
#include "./string_calculator.h"

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    int number = digit - '0';
    if ((number < 0) or (number > 9)) {
    	throw std::invalid_argument("Input must be an integer between and including 0 and 9");
    }
    return number;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    if (decimal > 9) {
    	throw std::invalid_argument("Input must be an integer between and including 0 and 9"); 
    }
    char number = (char)decimal + 48;
    return number;
}

std::string trim_leading_zeros(std::string num) {
    // TODO(student): implement
    bool nonzero = false;
    bool negative = false;
    if (num[0] == '-') {
    	num.erase(0, 1);
    	negative = true;
    }
    for (long unsigned int i = 0; i < num.length(); ++i) {
    	if (num[i] != '0') {
    		nonzero = true;
    	}
    }
    num.erase(0, num.find_first_not_of('0'));
    if (negative) {
    	num.insert(0, "-");
    }
    if (not nonzero) {
    	num = "0";
    }
    return num;
}

bool greater_than(std::string lhs, std::string rhs) {
	lhs = trim_leading_zeros(lhs);
	rhs = trim_leading_zeros(rhs);
	if (lhs.length() != rhs.length()) {
		if (lhs.length() > rhs.length()) {
			return true;
		} else if (lhs.length() < rhs.length()) {
			return false;
		}
	}
		for (long unsigned int i = 0; i < lhs.length(); ++i) {
			if (lhs[i] != rhs[i]) {
				if (std::stoi(std::to_string(lhs[i])) > std::stoi(std::to_string(rhs[i]))) {
					return true;
				} else {
					return false;
				}
			}
		}
	return 0;	 
}

std::string subtract(std::string lhs, std::string rhs) {
	bool lhs_negative = false;
	bool rhs_negative = false;
	bool sign_swap = false;
	std::string difference = "";
	if (lhs[0] == '-') {
		lhs.erase(0, 1);
		lhs_negative = true;
	}
	if (rhs[0] == '-') {
		rhs.erase(0, 1);
		rhs_negative = true;
	}
	if (lhs_negative and not rhs_negative) {
		return "-" + add(lhs, rhs);
	}
	if (rhs_negative and not lhs_negative) {
		return add(lhs, rhs);
	}
	if (lhs.length() > rhs.length()) {
		rhs = std::string(lhs.length() - rhs.length(), '0').append(rhs);
	} else if (lhs.length() < rhs.length()) {
		lhs = std::string(rhs.length() - lhs.length(), '0').append(lhs);
	}
	if (not greater_than(lhs, rhs)) {
		//Subtracting a smaller number from a larger number, this function fixes this
		sign_swap = true;
		std::string temp = rhs;
		rhs = lhs;
		lhs = temp;
	}
	if (rhs_negative and lhs_negative and not greater_than(lhs,rhs)) {
		//necessary to amend the problems with greater_than()
		sign_swap = false;
	} else if (rhs_negative and lhs_negative and greater_than(lhs,rhs)) {
		sign_swap = true;
	}
	for (long unsigned int i = 0; i < lhs.length(); ++i) {
		int int_lhs = (lhs[lhs.length() - i - 1]) - '0'; //was - i - 1
		//cout << "int_lhs " << int_lhs << endl;
		int int_rhs = (rhs[rhs.length() - i - 1]) - '0'; //was - i -1
		//cout << "int_rhs " << int_rhs << endl;
		int int_lhs_borrowfrom = (lhs[lhs.length() - i - 2]) - '0';
		//cout << "int_lhs_borrowfrom " << int_lhs_borrowfrom << endl;
		//int int_rhs_borrowfrom = (rhs[rhs.length() - i - 2]) - '0';
		if (int_rhs > int_lhs) {
			//subtracting one from the digit next to the left, changing this value in the original string, then adding ten to the top digit
			int_lhs_borrowfrom--;
			lhs[lhs.length() - i - 2] = std::to_string(int_lhs_borrowfrom)[0];
			//cout << "lhs " << lhs << endl;
			int_lhs += 10;
			difference = std::to_string(int_lhs - int_rhs).append(difference);
			//cout << difference << endl;
		} else {
			difference = std::to_string(int_lhs - int_rhs).append(difference);
			//cout << difference << endl;
		}
	}
	if (sign_swap) {
		difference = ("-") + difference;
	}
	difference = trim_leading_zeros(difference);
	return difference;
}

std::string add(std::string lhs, std::string rhs) { 
	bool lhs_negative = false;
	bool rhs_negative = false;
	bool sum_negative = false;
	if (lhs[0] == '-') {
                lhs.erase(0, 1);
                lhs_negative = true;
        }
        if (rhs[0] == '-') {
                rhs.erase(0, 1);
                rhs_negative = true;
        }
	if (lhs_negative and rhs_negative) {
		sum_negative = true;
	}
	lhs = trim_leading_zeros(lhs);
	rhs = trim_leading_zeros(rhs);	
	std::string sum = "";
	int carry = 0;
	if (lhs.length() > rhs.length()) {
		rhs = std::string(lhs.length() - rhs.length(), '0').append(rhs);
	} else if (lhs.length() < rhs.length()) {
		lhs = std::string(rhs.length() - lhs.length(), '0').append(lhs);
	}
	
	if ((lhs[0] - '0') + (rhs[0] - '0')) {
		lhs = std::string("0").append(lhs);
		rhs = std::string("0").append(rhs);
	}
	for (long unsigned int i = 0; i < lhs.length(); ++i) {
		//adds each individual digit sum to the whole string
		int int_lhs = (lhs[lhs.length() - i - 1]) - '0';
		int int_rhs = (rhs[rhs.length() - i - 1]) - '0';
		if ((int_lhs + int_rhs + carry) > 9) {
			sum = (std::to_string((int_lhs + int_rhs) - 10 + carry)).append(sum);
			carry = 1;
		} else {
			sum = (std::to_string((int_lhs + int_rhs) + carry)).append(sum);
			carry = 0;		
		}
	}
	sum = trim_leading_zeros(sum);
	if (sum_negative) {     
		sum.insert(0, "-");
	}
	return sum;
}

std::string multiply(std::string lhs, std::string rhs) {
	// TODO(student): implement
        bool lhs_negative = false;
        bool rhs_negative = false;
	bool product_negative = false;
	if (lhs[0] == '-') {
                lhs.erase(0, 1);
                lhs_negative = true;
        }
        if (rhs[0] == '-') {
                rhs.erase(0, 1);
                rhs_negative = true;
        }
	if ((lhs_negative and not rhs_negative) or (rhs_negative and not lhs_negative)) {
                product_negative = true;
        }
 	lhs = trim_leading_zeros(lhs);
	rhs = trim_leading_zeros(rhs);
	std::string product = "0";
	std::string partial_product = "0";
	int int_partial_product;
/*
	while (temp != rhs) {
	    	product = add(product, lhs);
	    	temp = add("1", temp);
	    	temp = trim_leading_zeros(temp);
		std::cout << "Product: " << product << std::endl;
		std::cout << "temp: " << temp << std::endl;
		std::cout << "lhs: " << lhs << std::endl;
		std::cout << "rhs: " << rhs << std::endl;
 	}
*/
	int carry = 0;
	for (long unsigned int i = 0; i < lhs.length(); ++i) {
		partial_product = "0";
		for (long unsigned int j = 0; j < rhs.length(); ++j) {
			int int_lhs = (lhs[lhs.length() - i - 1]) - '0';
			int int_rhs = (rhs[rhs.length() - j - 1]) - '0';
			int_partial_product = int_lhs * int_rhs + carry;
			if (int_partial_product > 9) {	
				while (int_partial_product > 9) {
					int_partial_product -= 10;
					carry++;
				}
			} else {
				carry = 0;
			}
			partial_product.insert(0, std::to_string(int_partial_product));
		}
		add(product, partial_product);
	}

	product = trim_leading_zeros(product);
	if (product_negative) {
		product.insert(0, "-");
        }
	return product;
}
