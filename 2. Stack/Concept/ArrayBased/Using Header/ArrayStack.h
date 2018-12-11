#ifndef __A_STACK_H_
#define __A_STACK_H_

#define STACK_LEN 3 // Stack length

// Stack node 
typedef struct arrayStack {
	int stackArr[STACK_LEN];
	int topIndex;
}ArrayStack;

typedef ArrayStack AStack;

void init(AStack *pstack); // Stack initialization
bool isFull(AStack *pstack); // Return true if the stack is full or false otherwise
bool isEmpty(AStack *pstack); // Return true if the stack is empty or false otherwise
void push(AStack *pstack, int data); // Push data
void pop(AStack *pstack); // Pop data
int getSize(AStack *pstack); // Return size of stack
void peek(AStack *pstack); // Print the element at the top
void print(AStack *pstack); // Print stack

#endif