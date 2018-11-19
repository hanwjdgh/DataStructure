#ifndef __L_CQUEUE_H_
#define __L_CQUEUE_H_


typedef struct node {
	int data;
	node *next;
}Node;


typedef struct listCircularQueue {
	Node *front, *rear;
}ListCircularQueue;

typedef ListCircularQueue CQueue;

void init(CQueue *pqueue); 
bool isEmpty(CQueue *pqueue); 
void enQueue(CQueue *pqueue, int value); 
void deQueue(CQueue *pqueue); 
int getSize(CQueue *pqueue); 
void peek(CQueue *pqueue); 
void print(CQueue *pqueue); 

#endif 
