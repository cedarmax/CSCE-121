#ifndef NODE_H
#define NODE_H

class Node {
public:
	int value;
	Node* next;

	Node() : value(0), next(nullptr) { 
		return;
	}
	Node(int v) : value(v), next(nullptr) { }
	Node(int v, Node* n) : value(v), next(n) { }
};

#endif