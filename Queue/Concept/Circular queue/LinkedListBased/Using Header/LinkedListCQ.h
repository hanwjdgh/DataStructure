#ifndef __L_CQUEUE_H_
#define __L_CQUEUE_H_

// Circular Queue Node
typedef struct node {
	int data;
	node *next;
}Node;

// Circular Queue front and rear point
typedef struct listCircularQueue {
	Node *front, *rear;
}ListCircularQueue;

typedef ListCircularQueue CQueue;

void init(CQueue *pqueue); // Circular queue initialization
bool isEmpty(CQueue *pqueue); // Return true if the circular queue is empty or false otherwise
void enQueue(CQueue *pqueue, int value); // Insert the element to circular queue
void deQueue(CQueue *pqueue); // Delete the element in circular queue
int getSize(CQueue *pqueue); // Return size of circular queue
void peek(CQueue *pqueue); // Return the element at the front
void print(CQueue *pqueue); // Print circular queue

#endif 
