#include <iostream>
#include <ios>
#include "LinkedListQueue.h"

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// Declaration LinkedList queue
	LQueue queue;

	// Initialize queue
	init(&queue);

	// Push data in queue
	enQueue(&queue, 1);
	enQueue(&queue, 2);
	enQueue(&queue, 3);
	enQueue(&queue, 4);

	// Print queue from front to rear
	print(&queue);

	// Print data that top of queue
	peek(&queue);
	// Print size of Queue
	cout << "Size: " << getSize(&queue) << "\n";

	// Pop data in Queue
	deQueue(&queue);
	deQueue(&queue);

	// Print whether Queue is empty or not
	cout << "Empty: " << (isEmpty(&queue) ? "TRUE" : "FALSE") << "\n";

	// Pop data in queue until queue is empty
	while (!isEmpty(&queue))
		deQueue(&queue);

	return 0;
}