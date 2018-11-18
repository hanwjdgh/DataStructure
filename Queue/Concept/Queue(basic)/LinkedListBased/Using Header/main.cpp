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
	enQueue(&queue, 5);

	// Print queue from front to rear
	print(&queue);

	// Print data that top of queue
	cout << "Peek : " << peek(&queue) << "\n";

	// Pop data in queue until queue is empty
	cout << "Pop : ";
	while (!isEmpty(&queue))
		cout << deQueue(&queue) << " ";

	return 0;
}