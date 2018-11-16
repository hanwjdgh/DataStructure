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

		cout << "Push : " << data << "\n";
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
		cout << "Top ";
		while (cur) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << "Bottom \n";
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// Declaration LinkedList stack
	Stack stack;

	// Push data in stack
	stack.push(1);
	stack.push(2);
	stack.push(3);

	// Print stack
	stack.print();

	// Print data that top of stack
	cout << "Peek: " << stack.peek() << "\n";
	// Print size of stack
	cout << "Size: " << stack.getSize() << "\n";

	// Pop data in stack
	cout << "Pop : " << stack.pop() << "\n";
	cout << "Pop : " << stack.pop() << "\n";

	// Print whether stack is empty or not
	cout << "Empty: " << (stack.isEmpty() ? "TRUE" : "FALSE") << "\n";

	return 0;
}