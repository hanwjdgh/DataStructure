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
bool isEmpty(LQueue *pqueue) {
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

	cout << "Enqueue : " << value << "\n";
}

// Delete the element in queue
void deQueue(LQueue *pqueue) {
	int tdata;
	Node *tnode;

	// If queue is NULL, return
	if (isEmpty(pqueue)) {
		cout << "Queue is Empty" << "\n";
		return;
	}

	// Store the node pointed to by front in tnode
	tnode = pqueue->front;
	// Store the data pointed to by current front in tdata
	tdata = tnode->data;
	// Front point to the node pointed to by front's next point
	pqueue->front = pqueue->front->next;

	// Delete node in tnode
	free(tnode);

	cout << "Dequeue : " << tdata << "\n";
}

// Return size of queue
int getSize(LQueue *pqueue) {
	int size = 0;
	Node *cur = pqueue->front;

	while (cur) {
		size++;
		cur = cur->next;
	}

	return size;
}

// Return the element at the front
void peek(LQueue *pqueue) {
	// If queue is NULL, return
	if (isEmpty(pqueue)) {
		cout << "Queue is Empty" << "\n";
		return;
	}

	cout << "Peek : " << pqueue->front->data << "\n";
}

// Print queue
void print(LQueue *pqueue) {
	Node *cur = pqueue->front;

	// If queue is NULL, return
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