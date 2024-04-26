#include <iostream>
#include "arrayFunctions.h"

using std::cin, std::cout, std::endl;

using std::out_of_range;

// always throw an out_of_range exception for any invalid index

void loadRandom(int ary[], int size) {
  if (size > CAPACITY) {
    throw out_of_range("size is greater than capacity");
  }
  for (unsigned int i=0; i<size; ++i) {
    ary[i] = rand()%100 + 1; // values 1 through 100
  }
}

void insert(int val, unsigned int index, 
          int ary[], unsigned int size) {
  if (index > CAPACITY || index > size) {
    throw out_of_range("index too large");
  }
  for (unsigned int i=size; i > index; --i) {
    ary[i] = ary[i-1];
  }
  ary[index] = val;
}

void removeAtIndex(unsigned int index, 
          int ary[], unsigned int size) {
  if (index >= size) {
    throw out_of_range("index too large");
  }
  for (unsigned int i=index; i < size-1; ++i) {
    ary[i] = ary[i+1];
  }
}

void removeFirstOf(int val, 
          int ary[], unsigned int size) {
  for (int i=0; i<size; ++i) {
    if (val == ary[i]) { // found it!
      removeAtIndex(i, ary, size);
      return;
    }
  }
  throw out_of_range("value not found to remove");
}

int getMax(int ary[], unsigned int size) {
  int max = ary[0];
  for (unsigned int i=1; i<size; ++i) {
    if (ary[i] > max) {
      max = ary[i];
    }
  }
  return max;
}

int getMin(int ary[], unsigned int size) {
  return 0;
}

unsigned int countVal(int val, int ary[], unsigned int size) {
  return 0;
}

void print(int ary[], unsigned int size) {
  if (size == 0) {
    cout << "Empty array" << endl;
  }
  for (unsigned int i=0; i<size; ++i) {
    cout << ary[i] << endl;
  }  
}