#ifndef __A_STACK_H_
#define __A_STACK_H_

#define CQ_LEN 3 // Circular queue length

// Circular Queue node
typedef struct arrayCircularQueue {
	int cqArr[CQ_LEN];
	int front,rear;
}ArrayCircularStack;

typedef ArrayCircularStack CQueue;

void init(CQueue *pstack); // Circular queue initialization
bool isFull(CQueue *pstack); // Return true if the circular queue is full or false otherwise
bool isEmpty(CQueue *pstack); // Return true if the circular queue is empty or false otherwise
void enQueue(CQueue *pstack, int data); // Push data
void deQueue(CQueue *pstack); // Pop data
int getSize(CQueue *pstack);  // Return size of circular queue
void peek(CQueue *pstack);  // Print the element at the of circular queue
void print(CQueue *pstack); // Print circular queue

#endif