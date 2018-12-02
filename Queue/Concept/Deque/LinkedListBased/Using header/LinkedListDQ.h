#ifndef __L_DQueue_H_
#define __L_DQueue_H_

// Dequeue Node
typedef struct node {
	int data;
	node *front, *rear;
}Node;

// Dequeue front and rear point
typedef struct listDQueue {
	Node *head, *tail;
}ListDQueue;

typedef ListDQueue DQueue;

void init(DQueue *pqueue); // Dequeue initialization
bool isEmpty(DQueue *pqueue); // Return true if the circular queue is empty or false otherwise
void pushFront(DQueue *pqueue, int value); // Push data to dequeue's front 
void pushRear(DQueue *pqueue, int value); // Push data to dequeue's rear
void popFront(DQueue *pqueue); // Pop front data
void popRear(DQueue *pqueue); // Pop rear data
int getSize(DQueue *pqueue); // Return size of dequeue
void print(DQueue *pqueue); // Print dequeue

#endif