#include <iostream>
#include <ios>

using namespace std;

// Node class
class Node {
public:
	int data;
    
	Node(int data);
	~Node();
};

// Constructor
Node::Node(int data) {
	this->data = data;
}
// Destructor 
Node::~Node() {
	cout << "Deleting node (" << this->data << ")" << "\n";
}


// Stack classs
class Stack {
public:
	int size;
	int top;
	Node** nodes;

	Stack(int size);
	~Stack();

	void Push(int data);
	int Pop();
	bool IsEmpty();
	int GetSize();
	int Peek();
};

// Constructor
Stack::Stack(int size) {
	this->nodes = new Node*[size];
	this->size = size;
	this->top = 0;
}
// Destructor 
Stack::~Stack() {
	for (int i = 0; i < this->size; i++) {
		if (this->nodes[i]) {
			delete this->nodes[i];
		}
	}
	delete[] this->nodes;
}

// Insert the element to top
void Stack::Push(int data) {
	this->nodes[this->top++] = new Node(data);
	cout << "Push: " << data << "\n";
}
// Delete the element in top
int Stack::Pop() {
	int data = this->nodes[--(this->top)]->data;
	cout << "Pop: " << data << "\n";
	return data;
}
// Return true if the stack is empty or false otherwise
bool Stack::IsEmpty() {
	return (this->top == 0);
}
// Return size of stack
int Stack::GetSize() {
	return this->top;
}
// Return the element at the top
int Stack::Peek() {
	return this->nodes[this->top - 1]->data;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    // Declaration array stack with size thirty
	Stack stack(3);

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