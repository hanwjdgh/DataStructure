#include <iostream>
#include <cstdlib>
#include "LinkedListStack.h"

using namespace std;

// Stack initialization
void Init(LStack *pstack) {
    // Define stack's head point is NULL
	pstack->head = NULL;
}

// Return true if the stack is empty or false otherwise
int IsEmpty(LStack *pstack) {
    // If head pointer is NULL, stack is empty
	if (pstack->head == NULL)
		return TRUE;

    // Else not empty
	else
		return FALSE;
}

// Insert the element to top
void Push(LStack *pstack, int data) {
    // Make new node
	Node *newNode = (Node *)malloc(sizeof(Node));
	
    // Insert data to New node's data variable
	newNode->data = data;
    // New node's next point is the node pointed to by head
	newNode->next = pstack->head;

    // Head point to new node
	pstack->head = newNode;
}

// Delete the element in top
int Pop(LStack *pstack) {
	int tdata;
	Node *tnode;

    // If stack is empty, exit program
	if (IsEmpty(pstack)) {
		cout << "Stack Memory Error!" << "\n";
		exit(-1);
	}

    // Store the data pointed to by current head in tdata
	tdata = pstack->head->data;
    // Store the node pointed to by head in tnode
	tnode = pstack->head;

    // Head point to the node pointed to by head's next point
	pstack->head = pstack->head->next;
    // Delete node in tnode
	free(tnode);

    // Return data in tdata
	return tdata;
}

// Return the element at the top
int Peek(LStack *pstack) {
    // If stack is empty, exit program
	if (IsEmpty(pstack)) {
		cout << "Stack Memory Error!" << "\n";
		exit(-1);
	}

    // Return data that top of stack 
	return pstack->head->data;
}