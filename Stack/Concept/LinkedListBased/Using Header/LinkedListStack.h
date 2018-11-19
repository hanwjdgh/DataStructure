#ifndef __L_STACK_H_
#define __L_STACK_H_

// Stack Node
typedef struct node {
	int data;
	struct node *next;
}Node;

// Stack head point
typedef struct listStack {
	Node *head;
}ListStack;

typedef ListStack LStack;

void init(LStack *pstack); // Stack initialization
bool isEmpty(LStack *pstack); // Return true if the stack is empty or false otherwise
void push(LStack *pstack, int value); // Insert the element to top
void pop(LStack *pstack); // Delete the element in top
int getSize(LStack *pstack); // Return size of stack
void peek(LStack *pstack); // Print the element at the top
void print(LStack *pstack); // Print stack

#endif