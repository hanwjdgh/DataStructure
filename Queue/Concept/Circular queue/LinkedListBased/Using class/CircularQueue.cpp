#include <iostream>
#include <ios>

using namespace std;

// Node struct
typedef struct node {
	int data;
	node *next;

	node(int value) {
		data = value;
		next = NULL;
	}
}Node;

// CircularQueue class
class CircularQueue {
private:
	node *front, *rear;
	int size;
public:
	// Constructor
	CircularQueue() {
		front = rear = NULL;
		size = 0;
	}
	// Destructor 
	~CircularQueue() {
		Node *cur = front;
		cout << "Delete : ";
		while (cur->next != front) {
			Node *tmp = cur;
			cur = cur->next;
			cout << tmp->data << " ";
			delete tmp;
		}
		cout << cur->data << " ";
		delete cur;
		cout << "\n";
	}

	// Push data
	void enQueue(int data) {
		// Make new node
		Node *tmp = new node(data);

		// If circular queue is empty, new node is front
		if (isEmpty())
			front = tmp;
		// Else rear'next is new node
		else
			rear->next = tmp;

		// new node is rear and rear's next is front
		rear = tmp;
		rear->next = front;

		// Increase size by 1
		size++;

		cout << "Enqueue : " << data << "\n";
	}
	// Pop data
	void deQueue() {
		int tdata;
		Node *tnode;

		// If circular queue is empty, print commet
		if (isEmpty()) {
			cout << "Circular Queue is Empty" << "\n";
			return;
		}
		// Store front node in tnode
		tnode = front;
		// store front data in tdata
		tdata = tnode->data;

		// If front and rear is equal, both are NULL
		if (front == rear)
			front = rear = NULL;
		// Else front is front's next and rear's next is front 
		else {
			front = front->next;
			rear->next = front;
		}

		// Decrease size by 1
		size--;
		// Delete front node
		delete tnode;

		cout << "Dequeue : " << tdata << "\n";
	}
	// Return true if the circular queue is empty or false otherwise
	bool isEmpty() {
		return front == NULL;
	}
	// Return size of circular queue
	int getSize() {
		return size;
	}
	// Return the data at the front
	int peek() {
		return front->data;
	}
	// Print circular queue from front to rear
	void print() {
		Node *cur = front;

		// If circular queue is empty, print commet
		if (isEmpty()) {
			cout << "Circular Queue is Empty" << "\n";
			return;
		}

		// Print circular queue from front to rear
		cout << "Front ";
		while (cur->next != front) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << cur->data << " Rear \n";
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// Declaration LinkedList circular Queue
	CircularQueue Cqueue;

	// Push data
	Cqueue.enQueue(1);
	Cqueue.enQueue(2);
	Cqueue.enQueue(3);

	// Print circular Queue
	Cqueue.print();

	// Print data that front of circular queue
	cout << "Peek: " << Cqueue.peek() << "\n";
	// Print size of circular queue
	cout << "Size: " << Cqueue.getSize() << "\n";

	// Pop data
	Cqueue.deQueue();
	Cqueue.deQueue();

	// Print whether circular queue is empty or not
	cout << "Empty: " << (Cqueue.isEmpty() ? "TRUE" : "FALSE") << "\n";

	return 0;
}