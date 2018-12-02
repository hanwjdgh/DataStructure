#include <iostream>
#include <cstdlib>
#include "LinkedListDQ.h"

using namespace std;

// Dequeue initialization
void init(DQueue *pqueue) {
	// Define dequeue's head and rear is NULL
	pqueue->head = pqueue->tail = NULL;
}

// Return true if the dequeue is empty or false otherwise
bool isEmpty(DQueue *pqueue) {
	// If front pointer is NULL, dequeue is empty
	return pqueue->head == NULL;
}

// Push data to dequeue's front 
void pushFront(DQueue *pqueue, int value) {
	// Make new node
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = value;
	newNode->front = NULL;
	newNode->rear = pqueue->head;

	if (isEmpty(pqueue))
		pqueue->tail = newNode;
	else 
		pqueue->head->front = newNode;

	pqueue->head = newNode;
}

// Push data to dequeue's rear
void pushRear(DQueue *pqueue, int value) {
	// Make new node
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = value;
	newNode->front = pqueue->tail;
	newNode->rear = NULL;

	if (isEmpty(pqueue)) 
		pqueue->head = newNode;
	else
		pqueue->tail->rear = newNode;

	pqueue->tail = newNode;
}

// Pop front data
void popFront(DQueue *pqueue) {
	int tdata;
	Node *tnode;

	// If circular queue is empty, return
	if (isEmpty(pqueue)) {
		cout << "Queue is Empty" << "\n";
		return;
	}

	tnode = pqueue->head;
	tdata = tnode->data;
	pqueue->head = pqueue->head->rear;
	free(tnode);

	if (pqueue->head == NULL)
		pqueue->tail = NULL;
	else
		pqueue->head->front = NULL;
}

// Pop rear data
void popRear(DQueue *pqueue) {
	int tdata;
	Node *tnode;

	// If circular queue is empty, return
	if (isEmpty(pqueue)) {
		cout << "Queue is Empty" << "\n";
		return;
	}

	tnode = pqueue->tail;
	tdata = tnode->data;
	pqueue->tail = pqueue->tail->front;
	free(tnode);

	if (pqueue->tail == NULL)
		pqueue->head = NULL;
	else
		pqueue->tail->rear = NULL;
}

// Return size of dequeue
int getSize(DQueue *pqueue) {
	int size = 0;
	Node *cur = pqueue->head;

	while (cur) {
		size++;
		cur = cur->rear;
	}

	return size;
}

// Print dequeue
void print(DQueue *pqueue) {
	Node *cur = pqueue->head;

	if (isEmpty(pqueue)) {
		cout << "Queue is Empty" << "\n";
		return;
	}

	cout << "Front ";
	while (cur) {
		cout << cur->data << " ";
		cur = cur->rear;
	}
	cout << "Rear \n";
}