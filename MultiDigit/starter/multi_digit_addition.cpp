/*
----- Linked List Addition Problem -----
Implement the add function.
*/

#include "multi_digit_addition.h"
using std::ostream, std::cout, std::endl;

// copy constructor
Number::Number(const Number& other) : head(nullptr), tail(nullptr) {
    Digit* marker = other.head;
    while (nullptr != marker) {
        insertFront(marker->value);
        marker = marker->next;
    }
}

// destructor
Number::~Number() {
    // initialize auxiliary pointer
    Digit* marker = nullptr;

    // iterate through list
    while (nullptr != head) {
        // set pointer to head node
        marker = head;

        // move head node to next node
        head = head->next;

        // disconect current node from rest of linked list
        marker->next = nullptr;
        if (nullptr != head) {
            head->prev   = nullptr;
        }

        // deallocate pointer
        delete marker;
        marker = nullptr;
    }
}

// copy assignment operator
Number& Number::operator=(const Number& other) {
    throw std::runtime_error("do not use operator= function");
    if (this == &other) { return *this; }
    return *this;
}

// insert front
void Number::insertFront(int value) {
    // create new node
    Digit* digit = new Digit(value);

    // case: list is empty => set tail node
    if (nullptr == tail) {
        tail = digit;
    }

    // case: list is non-empty => link head to new node
    else {
        head->prev = digit;
    }

    // link node to head and update head
    digit->next = head;
    head = digit;
}

// insert back
void Number::insertBack(int value) {
    // create new node
    Digit* digit = new Digit(value);

    // case: list is empty => set head node
    if (nullptr == head) {
        head = digit;
    }

    // case: list is non-empty => link tail to new node
    else {
        tail->next = digit;
    }

    // link node to tail and update tail
    digit->prev = tail;
    tail = digit;
}

// insertion operator
ostream& operator<<(ostream& out, const Number& number) {
    Digit* marker = number.getHead();
    while (nullptr != marker) {
        out << marker->value;
        marker = marker->next;
    }
    return out;
}

/*
TODO: Implement add function
*/

// add function
Number Number::add(const Number& rhs) {
        tail = nullptr;
        Digit* rhsDigit = rhs.tail;
	Digit* thisDigit = this->tail;
        Digit* curr = nullptr;
	Digit* prev = nullptr;
	Digit* next = nullptr;
        while (thisDigit != nullptr) {
                if (prev == nullptr) {
                        curr->value = (rhsDigit->value + thisDigit->value);
                        tail = curr;
                } else {
			curr->next = curr;
                        curr->prev->value = (rhsDigit->value + thisDigit->value);
                        curr = curr->prev;
                }
		thisDigit = thisDigit->prev;
                rhsDigit = rhsDigit->prev;
        }
        head = curr;
	return *this; 
}
