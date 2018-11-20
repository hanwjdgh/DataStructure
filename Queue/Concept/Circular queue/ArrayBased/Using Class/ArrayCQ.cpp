#include <iostream>
#include <ios>

using namespace std;

class CircularQueue {
private:
	int CQ_LEN;
	int front, rear;
	int *cqArr;
public:
	CircularQueue(int size) {
		front = rear = -1;
		CQ_LEN = size;
		cqArr = new int[size];
	}
	~CircularQueue() {
		cout << "delete : ";
		if (rear >= front) {
			for (int i = front; i <= rear; i++)
				cout << cqArr[i] << " ";
		}
		else {
			for (int i = front; i < CQ_LEN; i++)
				cout << cqArr[i] << " ";
			for (int i = 0; i <= rear; i++)
				cout << cqArr[i] << " ";
		}
		cout << "\n";
		delete[] cqArr;
	}
	void enQueue(int data) {
		if (isFull()) {
			cout << "Circular Queue is Full" << "\n";
			return;
		}

		else if (front == -1)
			front = rear = 0;

		else if (rear == CQ_LEN - 1)
			rear = 0;
		else
			rear++;

		cqArr[rear] = data;

		cout << "Enqueue : " << data << "\n";
	}
	void deQueue() {
		if (isEmpty()) {
			cout << "Circular Queue is Empty" << "\n";
			return;
		}

		int tdata = cqArr[front];
		if (front == rear)
			front = rear = -1;
		else if (front == CQ_LEN - 1)
			front = 0;
		else
			front++;

		cout << "Dequeue : " << tdata << "\n";
	}
	bool isFull() {
		if ((front == 0 && rear == CQ_LEN - 1) || (rear == (front - 1) % (CQ_LEN - 1)))
			return true;
		else
			return false;
	}
	bool isEmpty() {
		return front == -1;
	}
	int getSize() {//
		return CQ_LEN;
	}
	void peek() {
		if (isEmpty()) {
			cout << "Circular Queue is Empty" << "\n";
			return;
		}

		cout << "Peek: " << cqArr[front] << "\n";
	}
	void print() {
		if (isEmpty()) {
			cout << "Circular Queue is Empty" << "\n";
			return;
		}

		cout << "Front ";
		if (rear >= front) {
			for (int i = front; i <= rear; i++)
				cout << cqArr[i] << " ";
		}
		else {
			for (int i = front; i < CQ_LEN; i++)
				cout << cqArr[i] << " ";
			for (int i = 0; i <= rear; i++)
				cout << cqArr[i] << " ";
		}
		cout << "Rear \n";
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	CircularQueue Cqueue(3);

	Cqueue.enQueue(1);
	Cqueue.enQueue(2);
	Cqueue.enQueue(3);

	Cqueue.print();

	Cqueue.peek();
	cout << "Size: " << Cqueue.getSize() << "\n";

	Cqueue.deQueue();
	Cqueue.deQueue();

	cout << "Empty: " << (Cqueue.isEmpty() ? "TRUE" : "FALSE") << "\n";

	Cqueue.enQueue(4);
	Cqueue.enQueue(5);
	Cqueue.enQueue(6);

	Cqueue.print();

	return 0;
}