#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
	// Implement this function
}

LinkedList::~LinkedList() {
	// Implement this function
	while (head != nullptr) {
                Node* temp = head->next;
                delete head;
                head = temp;
        }
}

LinkedList::LinkedList(const LinkedList& source) {
	copy(source);
}

void LinkedList::copy(const LinkedList& source) {
	// Implement this function
	head = nullptr;
	Node* temp = source.head;
	Node* curr = nullptr;
	while (temp != nullptr) {
		if (curr == nullptr) {
			curr = new Node(temp->data.id, temp->data.year, temp->data.month, temp->data.temperature);
			head = curr;
		} else {
			curr->next = new Node(temp->data.id, temp->data.year, temp->data.month, temp->data.temperature);
			curr = curr->next;
		}
		temp = temp->next;
	}
	tail = curr;
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	if (this != &source) {
		clear();
		copy(source);
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
	// traverse
	// less than operator
	Node* newnode = new Node(location, year, month, temperature);
        if (head == nullptr) {
                newnode->next = head;
                head = newnode;
        }
        Node* curr = head;
//        int pos = 0;
        while(curr != nullptr && curr->next != nullptr) {
                curr = curr->next;
//                pos++;
        }
        if (curr == nullptr) return;
        // core logic
        newnode->next = curr->next;
        curr->next = newnode;
        if (newnode->next == nullptr) {
                tail = newnode;
        }
}

void LinkedList::clear() {
	// Implement this function
	// logic of destructor
	// identical
	while (head != nullptr) {
                Node* temp = head->next;
                delete head;
                head = temp;
        }
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return this->head;
}

string LinkedList::print() const {
	string outputString;
	// Implement this function
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
