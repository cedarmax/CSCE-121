#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}


LinkedList::~LinkedList() {
	clear();
}


void LinkedList::clear() {
	Node* marker = head;
	while (head != nullptr) {
		head = head->next;
		marker->next = nullptr;
		delete marker;
		marker = head;
	}
	tail = nullptr;
}

LinkedList::LinkedList(const LinkedList& l) {
	deepcopy(l);
}

void LinkedList::deepcopy(const LinkedList& l) {
	if (l.head != nullptr) {
		this->head = new Node(l.head->value);
		Node* thislist = head;
		Node* thatlist = l.head->next;
		while(thatlist != nullptr) {
			thislist->next = new Node(thatlist->value);
			thatlist = thatlist->next;
			thislist = thislist->next;
		}
		tail = thislist;
	} else {
		head = nullptr;
		tail = nullptr;
	}
}


LinkedList& LinkedList::operator=(const LinkedList& l) {
	if (this != &l) {
		clear();
		deepcopy(l);
	}
	return *this;
}


void LinkedList::append(int val) {
	Node* newnode = new Node(val);
	if (head == nullptr) {
		head = newnode;
		tail = newnode;
	} else {
		tail->next = newnode;
		tail = newnode;
	}
}

bool LinkedList::insert(int val, int index) {
	Node* newnode = new Node(val);
	if (index == 0) {
		newnode->next = head;
		head = newnode;
		return true;
	}
	Node* curr = head;
	int pos = 0;
	while( curr != nullptr && pos < index - 1) {
		curr = curr->next;
		pos++;
	}
	if (curr == nullptr) {
		return false;
	}
	// core logic
	newnode->next = curr->next;
	curr->next = newnode;
	if (newnode->next == nullptr) {
		tail = newnode;
	}
	return true;
}

int LinkedList::size() {
	Node* current = head;
	int count = 0;
	while (current != nullptr) {
		current = current->next;
		count++;
	}
	return count;
}

void LinkedList::print() {
	Node* current = head;
	while (current != nullptr) {
		cout << current->value << endl;
		current = current->next;
	}
	// for (Node* current = head; current != nullptr; current = current->next) {}
}

