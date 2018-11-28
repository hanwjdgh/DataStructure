#include <iostream>
#include <cstdlib>
#include "LinkedListDQ.h"

using namespace std;

void init(DQueue *pqueue){
    pqueue->head = pqueue->rear = NULL;
}
bool isEmpty(DQueue *pqueue){
    return pqueue -> head == NULL;
}
void pushFront(DQueue *pqueue, int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = value;
	newNode->front = newNode->rear = NULL;

    if (isEmpty(pqueue)) 
		pqueue->tail = newNode;
	else
        pqueue->head->front = newNode;
        
    pqueue->head = newNode;
}
void PushRear(DQueue *pqueue, int value){

}
void popFront(DQueue *pqueue){

}
void PopRear(DQueue *pqueue){

}
int getSize(DQueue *pqueue){
    int size = 0;
	Node *cur = pqueue->front;

	while (cur) {
		size++;
		cur = cur->next;
	}

	return size;
}
void print(DQueue *pqueue){
    Node *cur = pqueue->front;

	if (isEmpty(pqueue)) {
		cout << "Queue is Empty" << "\n";
		return;
	}

	cout << "Front ";
	while (cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << "Rear \n";
}