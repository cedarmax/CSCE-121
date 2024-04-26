#include <iostream>

using std::cout, std::cin, std::endl;

int func (int param) {

	int sum = 0;
	std::string s = std::to_string(param);
	int digit = 0;
	if((s[0] - '0') == 7) return 0;
	for (int i = 0; i < s.size(); i++) {
		digit = s[i] - '0';
		if (digit % 2 == 0) {
			sum += digit;
		} 
	}
	return sum;
}

int main () {
	
	cout << func(2092082169) << endl;
	cout << func(744698345) << endl;
	cout << func(27413) << endl;
	cout << func(5369485) << endl;
	cout << func(950905) << endl;

}
