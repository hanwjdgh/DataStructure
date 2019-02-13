#include <iostream>
#include <ios>
#include "ArrayCQ.h"

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// Declararation Array circular queue
	CQueue cqueue;

	// Initialize circular queue
	init(&cqueue);

	// Push data
	enQueue(&cqueue, 1);
	enQueue(&cqueue, 2);
	enQueue(&cqueue, 3);

	// Print circular queue from front to rear
	print(&cqueue);

	// Print data that front of circuluar queue
	peek(&cqueue);
	// Print size of circuluar queue
	cout << "Size: " << getSize(&cqueue) << "\n";

	// Pop data
	deQueue(&cqueue);
	deQueue(&cqueue);

	// Print whether circular queue is empty or not
	cout << "Empty: " << (isEmpty(&cqueue) ? "TRUE" : "FALSE") << "\n";

	// Push data
	enQueue(&cqueue,4);
	enQueue(&cqueue,5);
	enQueue(&cqueue,6);

	// Print data
	print(&cqueue);

	return 0;
}