#include <iostream>
#include <ios>

using namespace std;

// CircularQueue class
class CircularQueue {
private:
	int CQ_LEN;
	int front, rear;
	int *cqArr;
public:
	// Constructor
	CircularQueue(int size) {
		front = rear = -1;
		CQ_LEN = size;
		cqArr = new int[size];
	}
	// Destructor
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

	// Push data
	void enQueue(int data) {
		// If circular queue is full, return
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
	// Pop data
	void deQueue() {
		// If circular queue is empty, return
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
	// Return true if the circular queue is full or false otherwise
	bool isFull() {
		if ((front == 0 && rear == CQ_LEN - 1) || (rear == (front - 1) % (CQ_LEN - 1)))
			return true;
		else
			return false;
	}
	// Return true if the circular queue is empty or false otherwise
	bool isEmpty() {
		return front == -1;
	}
	int getSize() {//
		return CQ_LEN;
	}
	// Return the data at the front
	void peek() {
		// If circular queue is empty, return
		if (isEmpty()) {
			cout << "Circular Queue is Empty" << "\n";
			return;
		}

		cout << "Peek: " << cqArr[front] << "\n";
	}
	// Print circular queue from front to rear
	void print() {
		// If circular queue is empty, return
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

	// Declaration LinkedList circular Queue
	CircularQueue Cqueue(3);

	// Push data
	Cqueue.enQueue(1);
	Cqueue.enQueue(2);
	Cqueue.enQueue(3);

	// Print circular Queue
	Cqueue.print();

	// Print data that front of circular queue
	Cqueue.peek();
	// Print size of circular queue
	cout << "Size: " << Cqueue.getSize() << "\n";

	// Pop data
	Cqueue.deQueue();
	Cqueue.deQueue();

	// Print whether circular queue is empty or not
	cout << "Empty: " << (Cqueue.isEmpty() ? "TRUE" : "FALSE") << "\n";

	// Push data
	Cqueue.enQueue(4);
	Cqueue.enQueue(5);
	Cqueue.enQueue(6);

	// Print circular Queue
	Cqueue.print();

	return 0;
}