#include <iostream>
#include <cstdlib>
#include "LinkedListStack.h"

using namespace std;

// Stack initialization
void init(LStack *pstack) {
	// Define stack's head point is NULL
	pstack->head = NULL;
}

// Return true if the stack is empty or false otherwise
int isEmpty(LStack *pstack) {
	// If head pointer is NULL, stack is empty
	return pstack->head == NULL;
}

// Insert the element to top
void push(LStack *pstack, int value) {
	// Make new node
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;

	// If stack is empty, new node is head
	if (isEmpty(pstack))
		pstack->head = newNode;
	// Else new node's next is head and new node is head
	else {
		newNode->next = pstack->head;
		pstack->head = newNode;
	}
}

// Delete the element in top
int pop(LStack *pstack) {
	int tdata;
	Node *tnode;

	// If stack is empty, exit program
	if (isEmpty(pstack)) {
		cout << "Stack Memory Error!" << "\n";
		exit(-1);
	}

	// Store the node pointed to by head in tnode
	tnode = pstack->head;
	// Store the data pointed to by current head in tdata
	tdata = tnode->data;
	// Head point to the node pointed to by head's next point
	pstack->head = pstack->head->next;
	
	// Delete node in tnode
	free(tnode);

	// Return data in tdata
	return tdata;
}

// Return the element at the top
int peek(LStack *pstack) {
	// If stack is empty, exit program
	if (isEmpty(pstack)) {
		cout << "Stack Memory Error!" << "\n";
		exit(-1);
	}

	// Return data that top of stack 
	return pstack->head->data;
}

// Print stack
void print(LStack *pstack) {
	Node *cur = pstack->head;

	// If stack is NULL, print stack is empty
	if (isEmpty(pstack)) {
		cout << "Stack is Empty" << "\n";
		return;
	}

	// Print stack from top to bottom
	cout << "Top ";
	while (cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << "Bottom \n";
}