#include <iostream>
#include <ios>
#include "LinkedListStack.h"

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// Declaration LinkedList stack
	LStack stack;

	// Initialize stack
	init(&stack);

	// Push data in stack
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);

	// Print stack from top to bottom
	print(&stack);

	// Print data that top of stack
	cout << "Peek : " << peek(&stack) << "\n";

	// Pop data in stack until stack is empty
	cout << "Pop : ";
	while (!isEmpty(&stack))
		cout << pop(&stack) << " ";

	return 0;
}