#include <iostream>
#include "ArrayCQ.h"

using namespace std;

void init(CQueue *pcqueue) {
	pcqueue->front = pcqueue->rear = -1;
}
bool isFull(CQueue *pcqueue) {
	if ((pcqueue->front == 0 && pcqueue->rear == CQ_LEN - 1) || (pcqueue->rear == (pcqueue->front - 1) % (CQ_LEN - 1)))
		return true;
	else
		return false;
}
bool isEmpty(CQueue *pcqueue) {
	return pcqueue->front == -1;
}
void enQueue(CQueue *pcqueue, int data) {
	if (isFull(pcqueue)) {
		cout << "Circular Queue is Full" << "\n";
		return;
	}
	else if (pcqueue->front == -1)
		pcqueue->front = pcqueue->rear = 0;

	else if (pcqueue->rear == CQ_LEN - 1)
		pcqueue->rear = 0;
	else
		pcqueue->rear++;

	pcqueue->cqArr[pcqueue->rear] = data;

	cout << "Enqueue : " << data << "\n";
}
void deQueue(CQueue *pcqueue) {
	if (isEmpty(pcqueue)) {
		cout << "Circular Queue is Empty" << "\n";
		return;
	}

	int tdata = pcqueue->cqArr[pcqueue->front];
	if (pcqueue->front == pcqueue->rear)
		pcqueue->front = pcqueue->rear = -1;
	else if (pcqueue->front == CQ_LEN - 1)
		pcqueue->front = 0;
	else
		pcqueue->front++;

	cout << "Dequeue : " << tdata << "\n";
}
int getSize(CQueue *pcqueue) {
	int size = 0;

	if (isEmpty(pcqueue)) {
		cout << "Circular Queue is Empty" << "\n";
		return size;
	}
	if (pcqueue->rear >= pcqueue->rear)
		size = pcqueue->rear - pcqueue->front;
	else
		size = pcqueue->front - pcqueue->rear;
	return size++;
}
void peek(CQueue *pcqueue) {
	if (isEmpty(pcqueue)) {
		cout << "Circular Queue is Empty" << "\n";
		return;
	}

	cout << "Peek: " << pcqueue->cqArr[pcqueue->front] << "\n";
}
void print(CQueue *pcqueue) {
	if (isEmpty(pcqueue)) {
		cout << "Circular Queue is Empty" << "\n";
		return;
	}

	cout << "Front ";
	if (pcqueue->rear >= pcqueue->front) {
		for (int i = pcqueue->front; i <= pcqueue->rear; i++)
			cout << pcqueue->cqArr[i] << " ";
	}
	else {
		for (int i = pcqueue->front; i < CQ_LEN; i++)
			cout << pcqueue->cqArr[i] << " ";
		for (int i = 0; i <= pcqueue->rear; i++)
			cout << pcqueue->cqArr[i] << " ";
	}
	cout << "Rear \n";
}