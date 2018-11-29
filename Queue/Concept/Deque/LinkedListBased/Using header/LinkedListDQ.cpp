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
    Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = value;
	newNode->front = newNode->rear = NULL;

    if (isEmpty(pqueue)) 
		pqueue->head = newNode;
	else
        pqueue->tail->rear = newNode;

    pqueue->tail = newNode;
}
void popFront(DQueue *pqueue){
	int tdata;
	Node *tnode;

	if (isEmpty(pqueue)) {
		cout << "Queue is Empty" << "\n";
		return;
	}

	tnode = pqueue->head;
	tdata = tnode->data;
	pqueue->head = pqueue->head->rear;
	free(tnode);

	if(pqueue->head==NULL)
		pqueue->tail = NULL;
	else
		pqueue->head->front = NULL;
}
void popRear(DQueue *pqueue){

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