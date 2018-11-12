#ifndef __L_STACK_H_
#define __L_STACK_H_

#define TRUE 1
#define FALSE 0

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

void Init(LStack *pstack); // Stack initialization
int IsEmpty(LStack *pstack); // Return true if the stack is empty or false otherwise
void Push(LStack *pstack, int data); // Insert the element to top
int Pop(LStack *pstack); // Delete the element in top
int Peek(LStack *pstack); // Return the element at the top

#endif