#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if ((10 <= a) and (a < 10000) and (10 <= b) and (b < 10000) and (a <= b)) {
		return true;
	} else {
		return false;
	}
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	
	int d3 = 0;
	int d2 = 0;
	int d1 = 0;
	int d0 = 0;
	
	if (number > 999) {
		d3 = number % 10;
		d2 = number / 10 % 10;
		d1 = number / 100 % 10;
		d0 = number / 1000 % 10;
		
		if ((d0 > d1) and (d1 < d2) and (d2 > d3)) {
			return 'V';
		} else if ((d0 < d1) and (d1 > d2) and (d2 < d3)) {
			return 'M';
		} else {
			return 'N';
		}
	} else if (number > 99) {
		d2 = number % 10;
		d1 = number / 10 % 10;
		d0 = number / 100 % 10;
		
		if ((d0 < d1) and (d1 > d2)) {
			return 'M';
		} else if ((d0 > d1) and (d1 < d2)) {
			return 'V';
		} else {
			return 'N';
		}
	} else if (number > 9) {
		d1 = number % 10;
		d0 = number / 10 % 10;
		
		if ((d0 < d1)) {
			return 'M';
		} else if (d0 > d1) {
			return 'V';
		} else {
			return 'N';
		}
	} else {
		cout << "Invalid Input" << endl;
	}
	
	
	return 'N';
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	
	int mountain_count = 0;
	int valley_count = 0;
	
	for (int i = a; i <= b; i++) {
		if (classify_mv_range_type(i) == 'M') {
			mountain_count++;
		} else if (classify_mv_range_type(i) == 'V') {
			valley_count++;
		} else {}
	}
	
	cout << "There are " << mountain_count << " mountain ranges and " << valley_count << " valley ranges between " << a << " and " << b << "." << endl;
		
}


