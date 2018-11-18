#include <iostream>
#include <cstdlib>
#include "LinkedListQueue.h"

using namespace std;

// Queue initialization
void init(LQueue *pqueue) {
	// Define queue's front and rear point is NULL
	pqueue->front = pqueue->rear = NULL;
}

// Return true if the queue is empty or false otherwise
int isEmpty(LQueue *pqueue) {
	// If front pointer is NULL, queue is empty
	return pqueue->front == NULL;
}

//Insert the element to queue
void enQueue(LQueue *pqueue, int value) {
	// Make new node
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;

	// If queue is empty, new node is front and rear
	if (isEmpty(pqueue))
		pqueue->front = pqueue->rear = newNode;
	// Else rear's next is new node and rear is new node
	else {
		pqueue->rear->next = newNode;
		pqueue->rear = newNode;
	}
}

// Delete the element in queue
int deQueue(LQueue *pqueue) {
	int tdata;
	Node *tnode;

	// If queue is empty, exit program
	if (isEmpty(pqueue)) {
		cout << "Queue Memory Error!" << "\n";
		exit(-1);
	}

	// Store the node pointed to by front in tnode
	tnode = pqueue->front;
	// Store the data pointed to by current front in tdata
	tdata = tnode->data;
	// Front point to the node pointed to by front's next point
	pqueue->front = pqueue->front->next;

	// Delete node in tnode
	free(tnode);

	// Return data in tdata
	return tdata;
}

// Return the element at the front
int peek(LQueue *pqueue) {
	// If queue is empty, exit program
	if (isEmpty(pqueue)) {
		cout << "Queue Memory Error!" << "\n";
		exit(-1);
	}

	// Return data that front of queue
	return pqueue->front->data;
}

// Print queue
void print(LQueue *pqueue) {
	Node *cur = pqueue->front;

	// If queue is NULL, print queue is empty
	if (isEmpty(pqueue)) {
		cout << "Queue is Empty" << "\n";
		return;
	}

	// Print queue from front to rear
	cout << "Front ";
	while (cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << "Rear \n";
}