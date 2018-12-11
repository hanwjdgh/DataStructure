#include <iostream>
#include <ios>
#include "LinkedListCQ.h"

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// Declaration LinkedList circular queue
	CQueue cqueue;

	// Initialize circular queue
	init(&cqueue);

	// Push data in circular queue
	enQueue(&cqueue, 1);
	enQueue(&cqueue, 2);
	enQueue(&cqueue, 3);
	enQueue(&cqueue, 4);

	// Print circular queue from front to rear
	print(&cqueue);

	// Print data that top of circular queue
	peek(&cqueue);
	// Print size of circular queue
	cout << "Size: " << getSize(&cqueue) << "\n";

	// Pop data in circular queue
	deQueue(&cqueue);
	deQueue(&cqueue);

	// Print whether circular queue is empty or not
	cout << "Empty: " << (isEmpty(&cqueue) ? "TRUE" : "FALSE") << "\n";

	// Pop data in circular queue until circular queue is empty
	while (!isEmpty(&cqueue))
		deQueue(&cqueue);

	return 0;
}