#include <iostream>
#include <cstdlib>
#include "LinkedListCQ.h"

using namespace std;

void init(CQueue *pqueue) {
	pqueue->front = pqueue->rear = NULL;
}

bool isEmpty(CQueue *pqueue) {
	return pqueue->front == NULL;
}

//Insert the element to queue
void enQueue(CQueue *pqueue, int value) {
	// Make new node
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;

	if (isEmpty(pqueue))
		pqueue->front = newNode;
	else 
		pqueue->rear->next = newNode;

	pqueue->rear = newNode;
	pqueue->rear->next = pqueue->front;

	cout << "Enqueue : " << value << "\n";
}

// Delete the element in queue
void deQueue(CQueue *pqueue) {
	int tdata;
	Node *tnode;

	// If circular queue is empty, return
	if (isEmpty(pqueue)) {
		cout << "Circular Queue is Empty" << "\n";
		return;
	}

	// Store the node pointed to by front in tnode
	tnode = pqueue->front;
	// Store the data pointed to by current front in tdata
	tdata = tnode->data;
	
	if (pqueue->front == pqueue->rear)
		pqueue->front = pqueue->rear = NULL;
	else {
		pqueue->front = pqueue->front->next;
		pqueue->rear->next = pqueue->front;
	}
	// Delete node in tnode
	free(tnode);

	cout << "Dequeue : " << tdata << "\n";
}

int getSize(CQueue *pqueue) {
	int size = 0;
	Node *cur = pqueue->front;

	if (isEmpty(pqueue)) {
		return size;
	}

	while (cur->next != pqueue->front) {
		size++;
		cur = cur->next;
	}

	return size++;
}

// Return the element at the front
void peek(CQueue *pqueue) {
	// If circular queue is empty, return
	if (isEmpty(pqueue)) {
		cout << "Circular Queue is Empty" << "\n";
		return;
	}

	cout << "Peek : " << pqueue->front->data << "\n";
}

// Print queue
void print(CQueue *pqueue) {
	Node *cur = pqueue->front;

	// If circular queue is empty, return
	if (isEmpty(pqueue)) {
		cout << "Circular Queue is Empty" << "\n";
		return;
	}

	// Print queue from front to rear
	cout << "Front ";
	while (cur->next != pqueue->front) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << cur->data << " Rear \n";
}