#include <iostream>

using namespace std;

template <class T>
class _stack {
private:
	struct Node {
		T val;
		Node* next;
		Node() {}
		Node(T val) : val(val), next(NULL) {}
	};

	Node* head;
	int _size = 0;

public:
	_stack() {
		head = NULL;
		_size = 0;
	}

	~_stack() {
		while (head) {
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	void push(T val) {
		Node* temp = new Node(val);

		if (empty())
			head = temp;
		else {
			temp->next = head;
			head = temp;
		}
		_size++;
	}

	void pop() {
		Node* temp = head;
		head = head->next;
		delete temp;
		_size--;
	}

	bool empty() {
		return head == NULL;
	}

	T top() {
		return head->val;
	}

	int size() {
		return _size;
	}
};

int main() {
	_stack <int > s;

	for (int i = 0; i < 5; i++)
		s.push(i);

	while (!s.empty()) {
		cout << "Stack Top : " << s.top() << " / Stack Size : " << s.size() << "\n";
		s.pop();
	}

	return 0;
}