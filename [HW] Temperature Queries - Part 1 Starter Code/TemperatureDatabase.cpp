#include "TemperatureDatabase.h"

#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	ifstream inFS;
	istringstream inSS;
	string lineString;
	string strYear;
	string strMonth;
	string strTemperature;
	inFS.open(filename);
	if (!inFS.is_open()) {
		cout << "Error: Unable to open input.dat" << endl;
		exit(1);
	}
	while (!inFS.eof()) {
		getline(inFS, lineString);
		inSS.clear();
		inSS.str(lineString);
//		inSS >> this->id;
		inSS >> strYear;
		inSS >> strMonth;
		inSS >> strTemperature;
//		this->year = stoi(strYear);
	}
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

//void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
//}
