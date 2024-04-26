#ifndef ARRAYFUNCTIONS_H
#define ARRAYFUNCTIONS_H

const unsigned int CAPACITY = 100; // make largest size we will ever need

void loadRandom(int ary[], int size);
void insert(int val, unsigned int index, 
          int ary[], unsigned int size);
void removeAtIndex(unsigned int index, 
          int ary[], unsigned int size);
void removeFirstOf(int val, 
          int ary[], unsigned int size);
int getMax(int ary[], unsigned int size);
int getMin(int ary[], unsigned int size);
unsigned int countVal(int val, int ary[], unsigned int size);
void print(int ary[], unsigned int size);

#endif