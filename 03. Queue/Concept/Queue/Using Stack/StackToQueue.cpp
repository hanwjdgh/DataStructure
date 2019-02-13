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

// Stack class
class Stack {
private:
	node *top;
	int size;
public:
	// Constructor
	Stack() {
		top = NULL;
		size = 0;
	}
	// Destructor 
	~Stack() {
		Node *cur = top;
		cout << "Delete : ";
		while (top) {
			Node *tmp = top;
			top = top->next;
			cout << tmp->data << " ";
			delete tmp;
		}
		cout << "\n";
	}

	// Push data to top
	void push(int data) {
		// Make new node
		Node *tmp = new node(data);

		// If top is NULL, new node is top
		if (!top)
			top = tmp;
		// Else new node is top and new node's next is previous top
		else {
			Node *cur = top;
			top = tmp;
			top->next = cur;
		}
		// Increase size by 1
		size++;

	}
	// Pop data
	int pop() {
		// Store top data in rdata
		int rdata = top->data;
		// Store top node in cur
		Node *cur = top;
		// Change top to top's next
		top = top->next;

		// Derease size by 1
		size--;
		// Delete top node
		delete cur;
		// Return data
		return rdata;
	}
	// Return true if the stack is empty or false otherwise
	bool isEmpty() {
		return top == NULL;
	}
	// Return size of stack
	int getSize() {
		return size;
	}
	// Return the data at the top
	int peek() {
		return top->data;
	}
	// Print stack from top to bottom
	void print() {
		Node *cur = top;
		cout << "Front ";
		while (cur) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << "Rear \n";
	}
};

class Queue {
private:
	Stack stack1, stack2;
	int size;
public:
	Queue() {
		size = 0;
	}

	~Queue() {
		cout << "Q delete" << "\n";
	}

	void enQueue(int data) {
		stack1.push(data);
		size++;
	}

	int deQueue() {
		if (stack2.isEmpty()) {
			while (!stack1.isEmpty())
				stack2.push(stack1.pop());
		}
		size--;
		return stack2.pop();
	}

	void getSize() {
		cout << "Size: " << size << "\n";
	}

	void print() {
		stack1.print();
		stack2.print();
		cout << "\n";
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	Queue queue;

	queue.enQueue(1);
	queue.enQueue(2);
	queue.enQueue(3);
	queue.enQueue(4);
	queue.getSize();
	queue.print();

	cout << queue.deQueue() << "\n";
	cout << queue.deQueue() << "\n";

	queue.getSize();
	queue.print();

	queue.enQueue(5);
	queue.enQueue(6);

	queue.getSize();
	queue.print();

	return 0;
}