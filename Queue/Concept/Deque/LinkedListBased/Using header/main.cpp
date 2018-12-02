#include <iostream>
#include <ios>
#include "LinkedListDQ.h"

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    // Declaration LinkedList dequeue
	DQueue dqueue;

    // Initialize dequeue
	init(&dqueue);

    // Push front
	pushFront(&dqueue, 2);
	pushFront(&dqueue, 1);
    // Push rear
	pushRear(&dqueue, 3);
	pushRear(&dqueue, 4);

    // Print dequeue from front to rear
	print(&dqueue);

    // Print size of dequeue
	cout << "Size: " << getSize(&dqueue) << "\n";

    // Print whether dequeue is empty or not
	cout << "Empty: " << (isEmpty(&dqueue) ? "TRUE" : "FALSE") << "\n";
	
    // Pop front
	popFront(&dqueue);
    // Pop rear
	popRear(&dqueue);

    // Print dequeue from front to rear
	print(&dqueue);

	return 0;
}