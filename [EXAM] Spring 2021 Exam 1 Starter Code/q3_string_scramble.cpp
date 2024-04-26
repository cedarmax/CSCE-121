#include <iostream>

using std::cout, std::cin, std::endl, std::string;

string scrambleWord(string word);

int main() {
	cout << scrambleWord("optimistic") << endl;
	return 0;
}

string scrambleWord(string word) {
	char temp;
	int index = rand()%word.size()-1;
	for(int i=0;i<word.size() - 1;i++) {
		if(i == 0 or i == word.size()-2) continue;
		if(i%2 == 1) {
			if(word[i] == 'e') continue;
			temp = word[i+1];
			word[i+1] = word[i];
			word[i] = temp;
		}
	}
	return word;
}
