#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	LinkedList();

	~LinkedList();
	LinkedList(const LinkedList&);
	LinkedList& operator=(const LinkedList&);

	int size();
	bool insert(int val, int index);

	void append(int val);
	void print();

	void clear();
	void deepcopy(const LinkedList& l);

};

#endif