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
	}
	// Pop data
	int deQueue() {
		// If queue is empty, retrun
		if (isEmpty()) {
			cout << "Queue is Empty" << "\n";
			return 0;
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

		return tdata;
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

		cout << "Top ";
		while (cur) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << "Bottom \n";
	}
};

class Stack {
private:
	Queue queue1, queue2;
	int size;
public:
	Stack() {
		size = 0;
	}
	
	~Stack() {
		cout << "S delete" << "\n";
	}

	void push(int data) {
		if (queue1.isEmpty())
			queue1.enQueue(data);
		else {
			while (!queue1.isEmpty())
				queue2.enQueue(queue1.deQueue());
			queue1.enQueue(data);
			while (!queue2.isEmpty())
				queue1.enQueue(queue2.deQueue());
		}
		size++;
	}

	int pop() {
		size--;
		return queue1.deQueue();
	}

	void getSize() {
		cout << "Size: " << size << "\n";
	}

	void print() {
		queue1.print();
		queue2.print();
		cout << "\n";
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	Stack stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.getSize();
	stack.print();

	cout << stack.pop() << "\n";
	cout << stack.pop() << "\n";

	stack.getSize();
	stack.print();

	stack.push(5);
	stack.push(6);

	stack.getSize();
	stack.print();

	return 0;
}