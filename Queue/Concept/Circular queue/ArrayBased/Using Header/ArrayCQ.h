#ifndef __A_STACK_H_
#define __A_STACK_H_

#define CQ_LEN 3 

typedef struct arrayCircularQueue {
	int cqArr[CQ_LEN];
	int front,rear;
}ArrayCircularStack;

typedef ArrayCircularStack CQueue;

void init(CQueue *pstack); 
bool isFull(CQueue *pstack); 
bool isEmpty(CQueue *pstack); 
void enQueue(CQueue *pstack, int data); 
void deQueue(CQueue *pstack);
int getSize(CQueue *pstack); 
void peek(CQueue *pstack); 
void print(CQueue *pstack); 

#endif