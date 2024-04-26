#ifndef AGGIEPATRONS_H
#define AGGIEPATRONS_H

#include <string>
#include <vector>

class AggiePatrons {
private:
  unsigned int** table; // 2d array of patrons (row) and days (column)
  unsigned int numDays; // the logical number of days
  unsigned int numPatrons; // the logical number of columns
  unsigned int dayCapacity; // the number of columns in the table array
  unsigned int patronCapacity; // the number of rows in the table array
  
  void deleteTable(); // delete table and set all values to 0
  
  void increasePatrons(); // sets patron capacity to 2*patronCapacity or 1 if it is 0
  void increaseDays(); // sets day capacity to 2*dayCapacity or 1 if it is 0
  void resizeTable(unsigned int newPatronCapacity, unsigned int newDayCapacity);
    
public:
  AggiePatrons(); // default constructor
  AggiePatrons(const AggiePatrons& src); // copy constructor
  
  ~AggiePatrons(); // destructor
  
  AggiePatrons& operator=(const AggiePatrons& src); // copy assignment
  
  void loadPatronData(std::string filename);
  void addPatron();
  void addDayEvent(unsigned int patronID, unsigned int dayID,
                    unsigned int events);
  void print();
  
  // Write your functions here
  double getAverageAttendanceForPatron(unsigned int patronID);
  unsigned int getTotalAttendanceForDay(unsigned int dayID);
  std::vector<unsigned int> getActiveDays();
  std::vector<unsigned int> getMostActivePatrons();
};

#endif
