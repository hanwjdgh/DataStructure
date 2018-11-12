#include <iostream>
#include <ios>
#include "LinkedListStack.h"

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    // Declaration array stack
	LStack stack;

    // Initialize stack
	Init(&stack);

    // Push data in stack
	Push(&stack, 1);
	Push(&stack, 2);
	Push(&stack, 3);
	Push(&stack, 4);
	Push(&stack, 5);

    // Print data that top of stack
	cout << "Peek : " << Peek(&stack) << "\n";
	
    // Pop data in stack until stack is empty
    cout << "Pop : ";
	while (!IsEmpty(&stack))
		cout << Pop(&stack) << " ";

	return 0;
}