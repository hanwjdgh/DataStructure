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

// Queue class
class Queue {
private:
	node *front, *rear;
	int size;
public:
	// Constructor
	Queue() {
		front = rear = NULL;
		size = 0;
	}
	// Destructor 
	~Queue() {
		Node *cur = front;
		cout << "Delete : ";
		while (cur) {
			Node *tmp = cur;
			cur = cur->next;
			cout << tmp->data << " ";
			delete tmp;
		}
		cout << "\n";
	}

	// Push data
	void enQueue(int data) {
		// Make new node
		Node *tmp = new node(data);

		// If queue is empty, new node is front and rear
		if (isEmpty())
			front = rear = tmp;
		// Else rear and rear'next is new node
		else {
			rear->next = tmp;
			rear = tmp;
		}
		// Increase size by 1
		size++;

		cout << "Enqueue : " << data << "\n";
	}
	// Pop data
	void deQueue() {
		// If queue is empty, retrun
		if (isEmpty()) {
			cout << "Queue is Empty" << "\n";
			return;
		}

		// Store front node in cur
		Node *tnode = front;
		// Store front data in rdata
		int tdata = tnode->data;
		// Change front to front's next
		front = front->next;

		// Decrease size by 1
		size--;
		// Delete front node
		delete tnode;
		cout << "Dequeue : " << tdata << "\n";
	}
	// Return true if the stack is empty or false otherwise
	bool isEmpty() {
		return front == NULL;
	}
	// Return size of queue
	int getSize() {
		return size;
	}
	// Return the data at the front
	int peek() {
		return front->data;
	}
	// Print stack from front to rear
	void print() {
		Node *cur = front;

		// If queue is empty, retrun
		if (isEmpty()) {
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
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// Declaration LinkedList Queue
	Queue queue;

	// Push data in Queue
	queue.enQueue(1);
	queue.enQueue(2);
	queue.enQueue(3);

	// Print Queue
	queue.print();

	// Print data that front of Queue
	cout << "Peek: " << queue.peek() << "\n";
	// Print size of Queue
	cout << "Size: " << queue.getSize() << "\n";

	// Pop data in Queue
	queue.deQueue();
	queue.deQueue();

	// Print whether Queue is empty or not
	cout << "Empty: " << (queue.isEmpty() ? "TRUE" : "FALSE") << "\n";

	return 0;
}