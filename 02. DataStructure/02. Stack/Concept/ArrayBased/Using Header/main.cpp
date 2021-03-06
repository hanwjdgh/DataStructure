#include <iostream>
#include <ios>
#include "ArrayStack.h"

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// Declaration array stack
	AStack stack;

	// Initialize stack
	init(&stack);

	// Push data
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);

	// Print stack from top to bottom
	print(&stack);

	// Print data that top of stack
	peek(&stack);
	// Print size of stack
	cout << "Size: " << getSize(&stack) << "\n";

	// Pop data
    pop(&stack);
	pop(&stack);

	// Print whether stack is empty or not
	cout << "Empty: " << (isEmpty(&stack) ? "TRUE" : "FALSE") << "\n";

	while (!isEmpty(&stack))
		pop(&stack);

	return 0;
}