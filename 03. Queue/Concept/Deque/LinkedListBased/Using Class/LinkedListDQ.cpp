#include <iostream>
#include <ios>

using namespace std;

// Node struct
typedef struct node {
	int data;
	node *front, *rear;

	node(int value) {
		data = value;
		front = rear = NULL;
	}
}Node;

// Dequeue class
class Dequeue {
private:
	node *head, *tail;
	int size;
public:
	// Constructor
	Dequeue() {
		head = tail = NULL;
		size = 0;
	}
	// Destructor 
	~Dequeue() {
		Node *cur = head;
		cout << "Delete : ";
		while (cur) {
			Node *tmp = cur;
			cur = cur->rear;
			cout << tmp->data << " ";
			delete tmp;
		}
		cout << "\n";
	}
	
	// Push data to dequeue's front 
	void pushFront(int data) {
		// Make new node
		Node *tmp = new node(data);
		tmp->rear = head;

		if (isEmpty())
			tail = tmp;
		else
			head->front = tmp;
		head = tmp;

		size++;
	}

	// Push data to dequeue's rear
	void pushRear(int data) {
		// Make new node
		Node *tmp = new node(data);
		tmp->front = tail;

		if (isEmpty())
			head = tmp;
		else
			tail->rear = tmp;
		tail = tmp;

		size++;
	}

	// Pop front data
	void popFront() {
		int tdata;
		Node *tnode;

		// If dequeue is empty, return
		if (isEmpty()) {
			cout << "Dequeue is Empty" << "\n";
			return;
		}

		tnode = head;
		tdata = tnode->data;
		head = head->rear;
		delete tnode;

		if (head == NULL)
			tail = NULL;
		else
			head->front = NULL;

		size--;
	}

	// Pop rear data
	void popRear() {
		int tdata;
		Node *tnode;

		// If dequeue is empty, return
		if (isEmpty()) {
			cout << "Dequeue is Empty" << "\n";
			return;
		}

		tnode = tail;
		tdata = tnode->data;
		tail = tail->front;
		delete tnode;

		if (tail == NULL)
			head = NULL;
		else
			tail->rear = NULL;

		size--;
	}
	
	// Return true if the dequeue is empty or false otherwise
	bool isEmpty() {
		return head == NULL;
	}
	
	// Return size of dequeue
	int getSize() {
		return size;
	}

	// Print the element at the front
	void peek() {
		// If dequeue is empty, return
		if (isEmpty()) {
			cout << "Dequeue is Empty" << "\n";
			return;
		}

		cout << "Peek: " << head->data << "\n";
	}

	// Print dequeue
	void print() {
		Node *cur = head;

		// If dequeue is empty, return
		if (isEmpty()) {
			cout << "Dequeue is Empty" << "\n";
			return;
		}

		cout << "Front ";
		while (cur) {
			cout << cur->data << " ";
			cur = cur->rear;
		}
		cout << "Rear \n";
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// Declaration LinkedList Dequeue
	Dequeue dqueue;

	// Push data
	dqueue.pushFront(2);
	dqueue.pushFront(1);
	dqueue.pushRear(3);
	dqueue.pushRear(4);

	// Print dequeue
	dqueue.print();

	// Print data that front of dequeue
	dqueue.peek();
	// Print size of dequeue
	cout << "Size: " << dqueue.getSize() << "\n";

	// Pop data
	dqueue.popFront();
	dqueue.popRear();

	// Print dequeue
	dqueue.print();

	// Print whether dequeue is empty or not
	cout << "Empty: " << (dqueue.isEmpty() ? "TRUE" : "FALSE") << "\n";

	return 0;
}