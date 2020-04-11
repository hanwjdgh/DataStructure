#include <iostream>

using namespace std;

template <class T>
class _queue {
private:
	struct Node {
		T val;
		Node* next;
		Node() {};
		Node(T val) : val(val), next(NULL) {}
	};

	Node* head, * tail;
	int _size = 0;

public:
	_queue() {
		head = tail = NULL;
		_size = 0;
	}

	void push(T val) {
		Node* temp = new Node(val);

		if (empty()) {
			head = tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
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

	T front() {
		return head->val;
	}

	T back() {
		return tail->val;
	}

	int size() {
		return _size;
	}

};

int main() {
	_queue <int > q;

	for (int i = 0; i < 5; i++)
		q.push(i);

	while (!q.empty()) {
		cout << "Queue Front : " << q.front() << " / Queue Back : " << q.back() << " / Queue Size : " << q.size() << "\n";
		q.pop();
	}

	return 0;
}