#include "linked_list.h"
#include <iostream>
#include <string>
using std::cout, std::endl, std::string, std::ostream;

void MyList::add(string name, int score) {
    // TODO
	MyNode* newNode = new MyNode(name, score);
	if (_size == 0) {
		newNode->setNext(nullptr);
		_headPtr = newNode;
		_tailPtr = newNode;
		_size++;
	} else if (_size == 1) {
		_headPtr->setNext(newNode);
		_tailPtr = newNode;
		_tailPtr->setNext(nullptr);
		_size++;
	} else {
		_tailPtr->setNext(newNode);
		newNode->setNext(nullptr);
		_tailPtr = newNode;
		_size++;
	}
}

void MyList::clear() {
    // TODO
	while (_headPtr != nullptr) {
		MyNode* temp =  _headPtr->next();
		delete _headPtr;
		_headPtr = temp;
		_size--;
	}
}

bool MyList::remove(string name) {
    // TODO
	
    return false;
}

bool MyList::insert(string name, int score, size_t index) {
    // TODO
    return false;
}

MyList::MyList()
  : _size(0), _headPtr(nullptr), _tailPtr(nullptr) { }

MyList::~MyList() {
    clear();
}

size_t MyList::size() {
    return _size;
}

bool MyList::empty() {
    return _headPtr == nullptr;
}

MyNode* MyList::head() const {
    return _headPtr;
}

ostream& operator<<(ostream& os, const MyList& myList) {
    MyNode* _current = myList.head();
    if (_current == nullptr) {
        os << "Linked list is empty" << endl;
        return os;
    }

    while (_current != nullptr) {
        os << "[ " << _current->name() << ", " << _current->score() << " ]" << endl;
        _current = _current->next();
    }
    return os;
}

MyNode::MyNode(std::string name, int score)
    : _name(name), _score(score), _nextPtr(nullptr) {}

std::string MyNode::name()  {
    return _name;
}

int MyNode::score() {
    return _score;
}

void MyNode::setNext(MyNode* other) {
    _nextPtr = other;
}

MyNode* MyNode::next() {
    return _nextPtr;
}
