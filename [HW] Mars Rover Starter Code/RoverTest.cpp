#include <iostream>
#include <fstream>
#include "Rover.h"
#include "MyString.h"

// helper function "stoi" to converts MyString to int, works a lot like number slicing in reverse
int stoi(const MyString& str, size_t* pos = nullptr, int base = 10) { // just doing base 10 here
	int result = 0;
	for (unsigned int i = 0; i < str.size(); i++) { // MyString: size()
		if (str.at(i) >= '0' && str.at(i) <= '9') { // MyString: at()
			result *= 10; // increase digit (reverse of number slicing)
			result += str.at(i) - 48; // using ascii for conversion
		}
	}
	return result;
}

// helper function for insertion allows reading from input stream to MyString
std::istream& operator>>(std::istream& is, MyString& str) {
	str.clear();
	while (!is.eof()) {
		char c;
		is >> std::noskipws >> c; // use the noskipws manipulator
		if (isspace(c) || is.fail()) break; // if whitespace, can stop adding to string
		const char* newstr = new char[2] {c, '\0'};
		MyString newc = MyString(newstr); // MyString: copy constructor
		delete[] newstr;
		str += newc; // MyString: operator+=()
	}
	return is;
}


int main () {

	// open command file
	MyString filename; // MyString: default constructor

	std::cin >> filename; // operator>> is provided above

	std::ifstream commands(filename.data()); // MyString: data() return const char* type (otherwise, have to implement ifstream constructor for MyString type)

	if (!commands.is_open()) {
		std::cout << "Unable to open file" << std::endl;
		return 1;
	}

	// setup test rover
	Rover testRover;

	// read commands
	MyString comm;
	MyString data;
	while (!commands.eof()) {
		commands >> comm;

		if (comm.front() == 'P') { // MyString: front()
			testRover.print();
			continue;
		}

		if (comm.front() == 'C') {
			testRover.clear();
			continue;
		}

		commands >> data;

		switch (comm.front()) {
			case 'S':
				testRover.setSMILE(data);
				break;
			case 'R':
				testRover.read(stoi(data)); // stoi is provided above
				break;
			case 'J':
				testRover.join(data);
				break;
			case 'T':
				std::cout << testRover.test(data) << std::endl;
				break;
			case 'F':
				std::cout << data << " "; // MyString: operator<<()
				if (testRover.find(data)) {
					std::cout << "was found" << std::endl;
				} else {
					std::cout << "was not found" << std::endl;
				}
				break;
			default:
				continue;
		}
	}

	return 0;
}
