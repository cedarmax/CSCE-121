#include <iostream>
#include <vector>
#include "AggiePatrons.h"

using namespace std;

// Function to print the contents of class members that return a vector
void printVector(vector<unsigned int> vec, string label = "") {
  cout << label << ": " << endl;
  for (unsigned int i=0; i<vec.size(); ++i) {
    cout << vec.at(i) << endl;
  }
}

int main() {
  AggiePatrons ap;
  ap.loadPatronData("data.txt");
  ap.print();
  cout << ap.getAverageAttendanceForPatron(2) << endl;
  cout << ap.getTotalAttendanceForDay(4) << endl;
  for (long unsigned int i = 0; i < ap.getActiveDays().size(); i++) {
  	cout << ap.getActiveDays().at(i) << ", ";
}
cout << endl;
for (long unsigned int i = 0; i < ap.getMostActivePatrons().size(); i++) {
	cout << ap.getMostActivePatrons().at(i) << ", ";
	}
cout << endl;

/* I am assuming that whatever is in this file doesn't matter, as it is just for testing purposes, so I will leave this as is. */

  // add calls to test your functions
  // Note there is a print vector function that will print the contents
  //   of class members that return a vector.

  
}
