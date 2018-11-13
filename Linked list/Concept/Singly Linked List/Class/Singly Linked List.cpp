#include <iostream>
#include <ios>

using namespace std;

// Node class
class Node {
public:
	int data;
	Node* next;

	static Node* create(int data);
	static void destroy(Node * node);
};

// Constructor
Node* Node::create(int data) {
	Node* node = new Node;
	node->data = data;
	node->next = NULL;
	return node;
}
// Destructor 
void Node::destroy(Node* node) {
	delete node;
}

// SinglyLinkedList class
class SinglyLinkedList {
public:
	Node* head;

	void appendNode(Node* node);
	Node* getNodeAt(int loc);
	void removeNode(Node* node);
	void insertAfter(Node* cur, Node* node);
	void print();
	int getLength();

	SinglyLinkedList();
};
// Constructor
SinglyLinkedList::SinglyLinkedList() {
	this->head = NULL;
}

// Append node to end of SinglyLinkedlist
void SinglyLinkedList::appendNode(Node* node) {
    // If head is NULL, new node is head
	if (this->head == NULL)
		this->head = node;
    // Else find last node
	else {
		Node* cur = this->head;
		while (cur->next != NULL)
			cur = cur->next;
        // Append node to next to last node
		cur->next = node;
	}
}
// Retrun node at a specific location
Node* SinglyLinkedList::getNodeAt(int loc) {
	Node* cur = this->head;

    // Find node
	while (loc--) {
        // If node dosen't exist, return NULL
		if (!cur)
			return NULL;
		cur = cur->next;
	}

    // Retrun node at a specific location
	return cur;
}
// Remove a specific node
void SinglyLinkedList::removeNode(Node* node) {
    // If head is a specific node, change head to node's next
	if (this->head == node)
		this->head = node->next;
    // Else find node
	else {
		Node* cur = this->head;
		while (cur && cur->next != node)
			cur = cur->next;
        // If find node, change prior node's next to node's next
		if (cur)
			cur->next = node->next;
	}
    // Remove a specific node
	Node::destroy(node);
}
// Insert node after a specific location
void SinglyLinkedList::insertAfter(Node* cur, Node* node) {
	node->next = cur->next;
	cur->next = node;
}
// Return SinglyLinkedList's length
int SinglyLinkedList::getLength() {
	int length = 0;

    // If head is NULL, return length
	if (!this->head)
		return length;

    // Measure length using loop
	Node* cur = this->head;
	while (cur) {
		length++;
		cur = cur->next;
	}
    // Return length
	return length;
}
// Print SinglyLinkedList
void SinglyLinkedList::print() {
    // If head is NULL, print empty
	if (this->head == NULL) {
		cout << "Empty" << "\n";
		return;
	}
    // Print nodes in Linkedlist using loop
	Node* cur = this->head;
	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << "\n";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    // Creat node
	Node* node = Node::create(10);

	cout << node->data << "\n";
    // Destroy node
	Node::destroy(node);
	
    // Declaration SinglyLinkedList
	SinglyLinkedList SLL;

    // Append node to linkedlist
	for (int i = 0; i < 10; i++)
		SLL.appendNode(Node::create(i));
	SLL.print(); // 0 1 2 3 4 5 6 7 8 9

    // Get a specific node
	Node* result = SLL.getNodeAt(1);
	cout << result->data << "\n";

    // Remove a specific node
	SLL.removeNode(result);
	SLL.print(); // 0 2 3 4 5 6 7 8 9

    // Remove a specific node
	SLL.removeNode(SLL.getNodeAt(0));
	SLL.print(); // 2 3 4 5 6 7 8 9

    // Insert node after a specific location
	SLL.insertAfter(SLL.getNodeAt(1), Node::create(10));
	SLL.print(); // 2 3 10 4 5 6 7 8 9

	cout << "Length: " << SLL.getLength() << endl;
	return 0;
}