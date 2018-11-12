#ifndef __A_STACK_H_
#define __A_STACK_H_

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100 // Stack length

// Stack node 
typedef struct arrayStack {
	int stackArr[STACK_LEN];
	int topIndex;
}ArrayStack;

typedef ArrayStack AStack; 

void Init(AStack *pstack); // Stack initialization
int IsEmpty(AStack *pstack); // Return true if the stack is empty or false otherwise
void Push(AStack *pstack, int data); // Insert the element to top
int Pop(AStack *pstack); // Delete the element in top
int Peek(AStack *pstack); // Return the element at the top

#endif