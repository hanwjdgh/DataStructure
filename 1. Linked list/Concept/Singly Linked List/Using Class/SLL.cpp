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

// SinglyLinkedList class
class SinglyLinkedList {
private:
	Node *head;
public:
	// Constructor
	SinglyLinkedList() {
		head = NULL;
	}
	// Destructor 
	~SinglyLinkedList() {
		Node *cur = head;
		cout << "Delete : ";
		while (cur != NULL) {
			Node *tmp = cur->next;
			cout << cur->data << " ";
			delete cur;
			cur = tmp;
		}
		cout << "\n";
	}

	// Append node to end of SinglyLinkedlist
	void appendNode(int data) {
		// Make new node
		Node *tmp = new node(data);

		// If head is NULL, new node is head
		if (head == NULL)
			head = tmp;
		// Else find last node
		else {
			Node *cur = head;
			while (cur->next != NULL)
				cur = cur->next;
			// Append node to next to last node
			cur->next = tmp;
		}
	}
	// Retrun node at a specific location
	Node* getNodeAt(int loc) {
		Node *cur = head;

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
	void removeNode(Node *node) {
		// If head is a specific node, change head to node's next
		if (head == node)
			head = node->next;
		else {
			Node *cur = head;
			while (cur&&cur->next != node)
				cur = cur->next;
			// If find node, change prior node's next to node's next
			if (cur)
				cur->next = node->next;
		}
		// Remove a specific node
		delete node;
	}
	// Insert node after a specific location
	void insertAfter(Node *cur, int data) {
		// Make new node
		Node *tmp = new node(data);

		tmp->next = cur->next;
		cur->next = tmp;
	}
	// Print SinglyLinkedList
	void print() {
		// If head is NULL, print empty
		if (head == NULL) {
			cout << "Empty" << "\n";
			return;
		}
		// Print nodes in Linkedlist using loop
		Node *cur = head;
		while (cur != NULL) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << "\n";

	}
	// Return SinglyLinkedList's length
	int getLength() {
		int length = 0;

		// Measure length using loop
		Node *cur = head;
		while (cur) {
			length++;
			cur = cur->next;
		}
		// Return length
		return length;
	}
};


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// Declaration SinglyLinkedList
	SinglyLinkedList SLL;

	// Print and get length of empty SLL
	SLL.print();
	cout << "Length: " << SLL.getLength() << "\n";

	// Append node to linkedlist
	for (int i = 0; i < 10; i++)
		SLL.appendNode(i);
	SLL.print(); // 0 1 2 3 4 5 6 7 8 9

				 // Get a specific node
	Node* re = SLL.getNodeAt(1);
	cout << "Location 1's data : " << re->data << "\n";

	// Remove a specific node
	SLL.removeNode(re);
	SLL.print(); // 0 2 3 4 5 6 7 8 9

	// Remove a specific node
	SLL.removeNode(SLL.getNodeAt(0));
	SLL.print(); // 2 3 4 5 6 7 8 9

	// Insert node after a specific location
	SLL.insertAfter(SLL.getNodeAt(1), 10);
	SLL.print(); // 2 3 10 4 5 6 7 8 9

	// Print length of SLL
	cout << "Length: " << SLL.getLength() << endl;
	return 0;
}