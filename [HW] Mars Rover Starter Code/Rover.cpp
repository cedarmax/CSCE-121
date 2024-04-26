#include <iostream>
#include "Rover.h"
#include "MyString.h"

void Rover::print() {
	std::cout << savedSMILE << std::endl; // MyString: operator<<()
}

void Rover::read(int n) {
	std::cout << savedSMILE.at(n) << std::endl; // MyString: at()
}

void Rover::clear() {
	if (!savedSMILE.empty()) { // MyString: empty()
		savedSMILE.clear(); // MyString: clear()
	}
}

void Rover::join(MyString input) {
	savedSMILE += input; // MyString: operator+=()
}

MyString Rover::test(MyString input) {
	MyString tester(savedSMILE); // MyString: copy constructor
	tester += input; // MyString: operator+=()
	return tester; // MyString: destructor
}

bool Rover::find(MyString search) {
	int index = savedSMILE.find(search);
	return index >= 0; // MyString: find()
}
