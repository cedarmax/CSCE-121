#include <iostream>
#include <string>
#include <sstream>
#include "functions.h"
using std::cin, std::cout, std::endl, std::string, std::istringstream;

int main() {
  // prompt user input
  cout << "Type RPN expression (end with '=')." << endl;
  cout << "> ";
  
  //TODO: create a command-line interface for calculator GUI
Stack numbersList;  
string input;
  cin >> input;
  while (input != "=") {
	int number;
	if(istringstream(input) >> number) {
		push(numbersList, std::stod(input));
	} else {
		int rho = 0;
		int lho = 0;
		if (input == "+") {
			rho = pop(numbersList);
			lho = pop(numbersList);
			int sum = rho + lho;
			push(numbersList, sum);
		}
		if (input == "-") {
			rho = pop(numbersList);
			lho = pop(numbersList);
			int diff = lho - rho;
			push(numbersList, diff);
		}
		if (input == "*") {
			rho = pop(numbersList);
			lho = pop(numbersList);
			int product = rho * lho;
			push (numbersList, product);
		}
		if (input == "^") {
			rho = pop(numbersList);
			lho = pop(numbersList);
			int num = 1;
			for (int i = 0; i < rho; i++) {
				num = num * lho;
			}
			push(numbersList, num);
		}
	}
	cin >> input;
	}
	cout << "Ans: " << numbersList.numbers[0] << endl;
	delete numbersList.numbers;

  return 0;
}
