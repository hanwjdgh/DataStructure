#include <iostream>
#include <cstdlib>
#include "LinkedListCQ.h"

using namespace std;

// Circular queue initialization
void init(CQueue *pqueue) {
	// Define circular queue's front and rear is NULL
	pqueue->front = pqueue->rear = NULL;
}

// Return true if the circular queue is empty or false otherwise
bool isEmpty(CQueue *pqueue) {
	// If front pointer is NULL, circular queue is empty
	return pqueue->front == NULL;
}

//Insert the element to circular queue
void enQueue(CQueue *pqueue, int value) {
	// Make new node
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;

	// If circular queue is empty, new node is front
	if (isEmpty(pqueue))
		pqueue->front = newNode;
	// Else rear's next is new node
	else 
		pqueue->rear->next = newNode;

	// Connect rear and front
	pqueue->rear = newNode;
	pqueue->rear->next = pqueue->front;

	cout << "Enqueue : " << value << "\n";
}

// Delete the element in circular queue
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
	
	// If front same rear, front and rear is NULL
	if (pqueue->front == pqueue->rear)
		pqueue->front = pqueue->rear = NULL;
	// Else connect circular queue
	else {
		pqueue->front = pqueue->front->next;
		pqueue->rear->next = pqueue->front;
	}
	// Delete node in tnode
	free(tnode);

	cout << "Dequeue : " << tdata << "\n";
}

// Return size of circular queue
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