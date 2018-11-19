#include <iostream>
#include "ArrayStack.h"

using namespace std;

// Stack initialization
void init(AStack *pstack) {
	// In stack array, array index starts from 0, so -1 is defined as initialization
	pstack->topIndex = -1;
}

// Return true if the stack is empty or false otherwise
bool isFull(AStack *pstack) {
	// If array index is STACK_LEN , stack is full
	return pstack->topIndex + 1 == STACK_LEN;
}

// Return true if the stack is empty or false otherwise
bool isEmpty(AStack *pstack) {
	// If array index is -1, stack is empty
	return pstack->topIndex == -1;
}

// Insert the element to top
void push(AStack *pstack, int data) {
	// If stack is full, return
	if (isFull(pstack)) {
		cout << "Stack is Full \n";
		return;
	}
	cout << "Push : " << data << "\n";

	// Push data
	pstack->stackArr[++pstack->topIndex] = data;
}

// Delete the element in top
void pop(AStack *pstack) {
	int tidx;

	// If stack is empty, return
	if (isEmpty(pstack)) {
		cout << "Stack is Empty \n";
		return;
	}

	// Store current array number in tidx 
	tidx = pstack->topIndex;
	// Decrease array index by 1
	pstack->topIndex -= 1;

	// Pop data
	cout << "Pop : " << pstack->stackArr[tidx] << "\n";
}

// Return size of stack
int getSize(AStack *pstack) {
	return pstack->topIndex + 1;
}

// Return the element at the top
void peek(AStack *pstack) {
	// If stack is empty, return
	if (isEmpty(pstack)) {
		cout << "Stack is Empty \n";
		return;
	}

	// Print top of stack 
	cout << "Peek : " << pstack->stackArr[pstack->topIndex] << "\n";
}

// Print stack
void print(AStack *pstack) {
	// If stack is empty, return
	if (isEmpty(pstack)) {
		cout << "Stack is Empty \n";
		return;
	}

	// Print stack from top to bottom
	cout << "Top ";
	for (int i = pstack->topIndex; i > -1; i--)
		cout << pstack->stackArr[i] << " ";
	cout << "Bottom \n";
}