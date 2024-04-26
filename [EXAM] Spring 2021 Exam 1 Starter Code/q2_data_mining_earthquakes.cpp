#include <iostream>

using std::cout, std::cin, std::endl;

int main()
{
	int test[10] = { -12, 2, -2, 3, 5, -4, 78, -3, 19, 33};
	// the largest difference between values should be 82
	unsigned int answer = 0;
	
	// loop and compare 
	for (int i = 0; i < 9; i++) {
    	
	if (abs(test[i] - test[i+1]) > answer) {
		answer = abs(test[i] - test[i+1]);

}




	}
	cout << answer << endl;
	return 0;	
}
