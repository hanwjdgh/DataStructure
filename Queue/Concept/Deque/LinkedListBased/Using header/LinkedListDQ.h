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



#endif