#include <iostream>
#include <ios>

using namespace std;

// Stack classs
class Stack {
private:
	int STACK_LEN;
	int topIndex;
	int *stackArr;
public:
	// Constructor
	Stack(int size) {
		topIndex = -1;
		STACK_LEN = size;
		stackArr = new int[size];
	}
	// Destructor 
	~Stack() {
		cout << "delete : ";
		for (int i = topIndex; i > -1; i--) {
			cout << stackArr[i] << " ";
		}
		cout << "\n";
		delete[] stackArr;
	}

	// Push data
	void push(int data) {
		// If stack is full, return
		if (isFull()) {
			cout << "Stack is Full \n";
			return;
		}
		cout << "Push : " << data << "\n";

		// Push data to stack
		stackArr[++topIndex] = data;
	}
	// Pop data
	void pop() {
		// If stack is empty, return
		if (isEmpty()) {
			cout << "Stack is Empty \n";
			return;
		}

		// Pop data
		cout << "Pop : " << stackArr[topIndex--] << "\n";
	}
	// Return true if the stack is full or false otherwise
	bool isFull() {
		return topIndex + 1 == STACK_LEN;
	}
	// Return true if the stack is empty or false otherwise
	bool isEmpty() {
		return topIndex == -1;
	}
	// Return size of stack
	int getSize() {
		return topIndex + 1;
	}
	// Return the data at the top
	void peek() {
		if (isEmpty()) {
			cout << "Stack is Empty \n";
			return;
		}
		cout << "Peek: " << stackArr[topIndex - 1] << "\n";
	}
	// Print stack from top to bottom
	void print() {
		// If stack is empty, return
		if (isEmpty()) {
			cout << "Stack is Empty \n";
			return;
		}

		// Print stack from top to bottom
		cout << "Top ";
		for (int i = topIndex; i > -1; i--)
			cout << stackArr[i] << " ";
		cout << "Bottom \n";
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// Declaration array stack with size
	Stack stack(3);

	// Push data in stack
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	// Print stack
	stack.print();

	// Print data that top of stack
	stack.peek();
	// Print size of stack
	cout << "Size: " << stack.getSize() << "\n";

	// Pop data in stack
	stack.pop();
	stack.pop();

	// Print whether stack is empty or not
	cout << "Empty: " << (stack.isEmpty() ? "TRUE" : "FALSE") << "\n";

	return 0;
}