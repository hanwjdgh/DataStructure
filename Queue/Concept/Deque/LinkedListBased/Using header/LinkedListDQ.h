#ifndef __L_DQueue_H_
#define __L_DQueue_H_

typedef struct node{
    int data;
    node *front, *rear;
}Node;

typedef struct listDQueue{
    Node *head, *tail;
}ListDQueue;

typedef ListDQueue DQueue;

void init(DQueue *pqueue);
bool isEmpty(DQueue *pqueue);
void pushFront(DQueue *pqueue, int value);
void PushRear(DQueue *pqueue, int value);
void popFront(DQueue *pqueue);
void popRear(DQueue *pqueue);
int getSize(DQueue *pqueue); 
void print(DQueue *pqueue); 

#endif