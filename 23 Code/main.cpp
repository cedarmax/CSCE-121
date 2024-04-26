#include "LinkedList.h"

int main() {

	LinkedList ll;
	ll.append(10);
	ll.append(20);
	ll.append(5);

	ll.insert(15,1);
	ll.insert(2,4);

	ll.print();
}