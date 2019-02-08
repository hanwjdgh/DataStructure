#include <iostream>
#include <ios>

using namespace std;

// Node struct
typedef struct node {
	int data;
	node *prev, *next;

	// Constructor
	node(int value) {
		data = value;
		prev = next = NULL;
	}
}Node;

// DoublyLinkedList class
class DoublyLinkedList {
private:
	Node *head, *tail;
public:
	// Constructor
	DoublyLinkedList() {
		head = tail = NULL;
	}
	// Destructor 
	~DoublyLinkedList() {
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

	// Insert node front or last of DLL
	void appendNode(int data, char mode) {
		// Make new node
		Node *tmp = new node(data);

		// If head and tail is NULL, head and tail is new node
		if (!head && !tail) {
			head = tmp;
			tail = tmp;
		}
		// Else check mode
		else {
			// If mode is F that mean front, insert node front of DLL
			if (mode == 'F') {
				Node* cur = head;
				tmp->next = cur;
				cur->prev = tmp;
				head = tmp;
			}
			// Else insert node last of DLL
			else {
				Node* cur = tail;
				cur->next = tmp;
				tmp->prev = cur;
				tail = tmp;
			}
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
		// If head is a specific node, change head to node's next and node->next->prev is NULL
		if (head == node) {
			node->next->prev = NULL;
			head = node->next;
		}
		// If tail is a specific node, change tail to node's prev and node->prev->next is nULL
		else if (tail == node) {
			node->prev->next = NULL;
			tail = node->prev;
		}
		// If a specific node exist middle of DLL, connect node's prev node with next node
		else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		// Remove a specific node
		delete node;
	}

	// Insert node before or after a specific location
	void insertLocation(Node *cur, int data, char mode) {
		// Make new node
		Node *tmp = new node(data);

		// Check mode
		switch (mode) {
			// If mode is B, insert node before a specific location
		case 'B':
			if (head == cur) {
				cur->prev = tmp;
				tmp->next = cur;
				head = tmp;
			}
			else {
				cur->prev->next = tmp;
				tmp->prev = cur->prev;
				tmp->next = cur;
				cur->prev = tmp;
			}
			break;
			// If mode is A, insert node after a specific location
		case 'A':
			if (tail == cur) {
				tail->next = tmp;
				tmp->prev = tail;
				tail = tmp;
			}
			else {
				cur->next->prev = tmp;
				tmp->next = cur->next;
				tmp->prev = cur;
				cur->next = tmp;
			}
			break;
		default:
			break;
		}
	}

	// Print DoublyLinkedList
	void print(bool reverse = false) {
		// If head is NULL, print empty
		if (!head) {
			cout << "Empty" << "\n";
			return;
		}
		// If reverse is false, print from head to tail
		if (!reverse) {
			Node *cur = head;
			while (cur != NULL) {
				cout << cur->data << " ";
				cur = cur->next;
			}
			cout << "\n";
		}
		// Else print from tail to head
		else {
			Node *cur = tail;
			while (cur != NULL) {
				cout << cur->data << " ";
				cur = cur->prev;
			}
			cout << "\n";
		}
	}

	// Return DoublyLinkedList's length
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

	// Declaration DoublyLinkedList
	DoublyLinkedList DLL;

	// Print and get length of empty DLL
	DLL.print();
	cout << "Length: " << DLL.getLength() << "\n";

	// Append node to DLL's head
	for (int i = 0; i < 5; i++)
		DLL.appendNode(i, 'F');

	// Append node to DLL's tail
	for (int i = 6; i < 10; i++)
		DLL.appendNode(i, 'L');

	DLL.print(); // 4 3 2 1 0 6 7 8 9
	DLL.print(true); // 9 8 7 6 0 1 2 3 4

	// Get a specific node
	Node* re = DLL.getNodeAt(1);
	cout << "Location 1's data : " << re->data << "\n";

	// Remove a specific node
	DLL.removeNode(re);
	DLL.print(); // 4 2 1 0 6 7 8 9

	// Remove a specific node
	DLL.removeNode(DLL.getNodeAt(0));
	DLL.print(); // 2 1 0 6 7 8 9

	// Insert node before a specific location
	DLL.insertLocation(DLL.getNodeAt(1), 10, 'B');
	DLL.print(); // 2 10 1 0 6 7 8 9

	// Insert node after a specific location
	DLL.insertLocation(DLL.getNodeAt(6), 10, 'A');
	DLL.print(); // 2 10 1 0 6 7 8 10 9

	// Print length of DLL
	cout << "Length: " << DLL.getLength() << endl;
	return 0;
}