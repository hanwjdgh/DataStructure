#ifndef __L_QUEUE_H_
#define __L_QUEUE_H_

// Queue Node
typedef struct node {
	int data;
	node *next;
}Node;

// Queue front and rear point
typedef struct listQueue {
	Node *front, *rear;
}ListQueue;

typedef ListQueue LQueue;

void init(LQueue *pqueue); // Queue initialization
int isEmpty(LQueue *pqueue); // Return true if the queue is empty or false otherwise
void enQueue(LQueue *pqueue, int value); //Insert the element to queue
int deQueue(LQueue *pqueue); // Delete the element in queue
int peek(LQueue *pqueue); // Return the element at the front
void print(LQueue *pqueue); // Print queue

#endif 