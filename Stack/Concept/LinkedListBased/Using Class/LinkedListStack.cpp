#include <iostream>
#include <ios>

using namespace std;

// Node class
class Node {
public:
	int data;
	Node* next;

	Node(int data);
	~Node();
};

// Constructor
Node::Node(int data) {
	this->data = data;
	this->next = NULL;
}
// Destructor 
Node::~Node() {
	cout << "Deleting node (" << this->data << ")" << "\n";
}

// Stack class
class Stack {
public:
	Node* topNode;
	int length;

	Stack();
	~Stack();

	void Push(int data);
	int Pop();
	bool IsEmpty();
	int GetSize();
	int Peek();
};

// Constructor
Stack::Stack() {
	this->topNode = NULL;
	this->length = 0;
}
// Destructor 
Stack::~Stack() {
	Node* top = this->topNode;
	while (top) {
		Node* old = top;
		top = top->next;
		delete old;
	}
}

// Insert the element to top
void Stack::Push(int data) {
	if (this->topNode == NULL) 
		this->topNode = new Node(data);
	else {
		Node* old = this->topNode;
		this->topNode = new Node(data);
		this->topNode->next = old;
	}
	length++;

	cout << "Push: " << data << "\n";
}
// Delete the element in top
int Stack::Pop() {
	int data = this->topNode->data;
	Node* old = this->topNode;
	this->topNode = this->topNode->next;

	length--;
	delete old;
	cout << "Pop: " << data << "\n";
	return data;
}
// Return true if the stack is empty or false otherwise
bool Stack::IsEmpty() {
	return (this->topNode == NULL);
}
// Return size of stack
int Stack::GetSize() {
	return length;
}
// Return the element at the top
int Stack::Peek() {
	return this->topNode->data;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    // Declaration LinkedList stack
	Stack stack;

    // Push data in stack
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);

	// Print data that top of stack
	cout << "Peek: " << stack.Peek() << "\n";
	// Print size of stack
	cout << "Size: " << stack.GetSize() << "\n";

	// Pop data in stack
	stack.Pop();
	stack.Pop();

	// Print whether stack is empty or not
	cout << "Empty: " << (stack.IsEmpty() ? "TRUE" : "FALSE") << "\n";

	stack.Pop();

	cout << "Empty: " << (stack.IsEmpty() ? "TRUE" : "FALSE") << "\n";

	return 0;
}