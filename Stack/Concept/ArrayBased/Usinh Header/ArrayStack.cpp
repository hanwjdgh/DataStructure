#include <iostream>
#include "ArrayStack.h"

using namespace std;

// Stack initialization
void Init(AStack *pstack) {
    // In stack array, array index starts from 0, so -1 is defined as initialization
	pstack->topIndex = -1;
}

// Return true if the stack is empty or false otherwise
int IsEmpty(AStack *pstack) {
    // If array index is -1, stack is empty
	if (pstack->topIndex == -1)
		return TRUE;

    // Else not empty
	else
		return FALSE;
}

// Insert the element to top
void Push(AStack *pstack, int data) {
    // Increase array index by 1
	pstack->topIndex += 1;
    // Insert data in stack array
	pstack->stackArr[pstack->topIndex] = data;
}


// Delete the element in top
int Pop(AStack *pstack) {
	int tidx;

    // If stack is empty, exit program
	if (IsEmpty(pstack)) {
		cout << "Stack Memory Error!" << "\n";
		exit(-1);
	}

    // Store current array number in tidx 
	tidx = pstack->topIndex;
    // Decrease array index by 1
	pstack->topIndex -= 1;
	
    // Return data with the array number stored in tidx
	return pstack->stackArr[tidx];
}

// Return the element at the top
int Peek(AStack *pstack) {
    // If stack is empty, exit program
	if (IsEmpty(pstack)) {
		cout << "Stack Memory Error!" << "\n";
		exit(-1);
	}

    // Return data that top of stack 
	return pstack->stackArr[pstack->topIndex];
}