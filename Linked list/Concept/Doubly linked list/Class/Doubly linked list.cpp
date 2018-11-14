#include <iostream>
#include <ios>

using namespace std;

// Node class
class Node {
public:
	int data;
	Node* prev;
	Node* next;

	Node(int data);
	void distroy();
};

// Constructor
Node::Node(int data) {
	this->data = data;
	this->prev = NULL;
	this->next = NULL;
}
// Destructor 
void Node::distroy() {
	cout << "Distroy node :  " << this->data << endl;
	delete this;
}

// DoublyLinkedList class
class doublyLinkedList {
public:
	Node* head;
	Node* tail;

	doublyLinkedList();
	~doublyLinkedList();

	void insertLast(Node* node);
	void insertFirst(Node* node);
	void insertAfter(Node* target, Node* node);
	void insertBefore(Node* target, Node* node);
	Node* getNodeAt(int loc);
	void removeNode(Node* node);
	int getLength();
	void print(bool isReverse);
};

// Constructor
doublyLinkedList::doublyLinkedList() {
	this->head = NULL;
	this->tail = NULL;
}
// Destructor 
doublyLinkedList::~doublyLinkedList() {
	if (!this->head) return;

	Node* current = this->head;
	while (current->next) {
		if (current->prev) current->prev->distroy();
		current = current->next;
	}
	current->distroy();
}

// Insert node at end of list
void doublyLinkedList::insertLast(Node* node) {
	if (!this->head) {
		this->head = node;
		this->tail = node;
	}
	else {
		Node* current = this->tail;
		current->next = node;
		node->prev = current;
		this->tail = node;
	}
}
// Insert node at front of list
void doublyLinkedList::insertFirst(Node* node) {
	if (!this->head && !this->tail) {
		this->head = node;
		this->tail = node;
	}
	else {
		Node* current = this->head;
		node->next = current;
		current->prev = node;
		this->head = node;
	}
}

void doublyLinkedList::insertAfter(Node* target, Node* node) {
	if (target == this->tail) {
		target->next = node;
		node->prev = target;
		this->tail = node;
	}
	else {
		target->next->prev = node;
		node->next = target->next;
		node->prev = target;
		target->next = node;
	}
}

void doublyLinkedList::insertBefore(Node* target, Node* node) {
	if (target == this->head) {
		target->prev = node;
		node->next = target;
		this->head = node;
	}
	else {
		target->prev->next = node;
		node->prev = target->prev;
		node->next = target;
		target->prev = node;
	}
}

Node* doublyLinkedList::getNodeAt(int loc) {
	Node* node = this->head;
	while (loc--) {
		node = node->next;
	}
	return node;
}

void doublyLinkedList::removeNode(Node* node) {
	if (node == this->head) {
		node->next->prev = NULL;
		this->head = node->next;
	}
	else if (node == this->tail) {
		node->prev->next = NULL;
		this->tail = node->prev;
	}
	else {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	node->distroy();
}

int doublyLinkedList::getLength() {
	int length = 0;
	if (!this->head) return length;

	Node* current = this->head;
	while (current) {
		current = current->next;
		length++;
	}

	return length;
}

void doublyLinkedList::print(bool isReverse = false) {
	cout << "LinkedList" << (isReverse ? "(reversed): " : ": ");
	Node* current = isReverse ? this->tail : this->head;

	if (isReverse) {
		while (current) {
			cout << current->data;
			current = current->prev;
			if (current) {
				cout << " <- ";
			}
		}

	}
	else {
		while (current != NULL) {
			cout << current->data;
			current = current->next;
			if (current) {
				cout << " -> ";
			}
		}
	}

	cout << endl;

}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cout << "[TEST] Node creation & disposal" << endl;
	Node* node = new Node(5);
	cout << node->data << endl;
	node->distroy();

	doublyLinkedList dll;

	cout << "insertLast & insertFirst & print" << endl;
	for (int i = 0; i < 10; i++) {
		dll.insertLast(new Node(i));
	}
	dll.print();

	for (int i = 10; i <20; i++) {
		dll.insertFirst(new Node(i));
	}
	dll.print();
	dll.print(true);

	cout << "node search" << endl;

	node = dll.getNodeAt(3);
	cout << node->data << endl;

	cout << "length: " << dll.getLength() << endl;

	cout << "insert before & after" << endl;
	dll.insertBefore(dll.getNodeAt(0), new Node(100));
	dll.print();
	dll.insertBefore(dll.getNodeAt(3), new Node(101));
	dll.print();

	return 0;
}