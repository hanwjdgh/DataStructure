#include<iostream>


struct Node {
	int data;
	Node* next, *prev;
	Node() {
		next = prev = NULL;
		data = 0;
	}
	Node(int i, Node* ptr)//ptr 뒤에 추가한다.
	{
		data = i;
		prev = ptr;
		next = ptr->next;
		next->prev = prev->next = this;
	}
	void selvDelete() {
		prev->next = next;
		next->prev = prev;
		delete this;
	}
};

struct DLinkedList {
	Node *head;
	Node *tail;
	int count;
	DLinkedList() { 
		count = 0;
		head = new Node(); 
		tail = new Node(); 
		head->next = tail; 
		tail->prev = head;
	}
	~DLinkedList() {
		while (head->next != tail)
			head->next->selvDelete();
		delete head;
		delete tail;
	}
	void firstInsert(int i) { 
		new Node(i, head);
	}
	void endInsert(int i) { 
		new Node(i, tail->prev);
	}
	void firstDelete() { 
		if (head->next == tail)    return;
		head->next->selvDelete();
	}
	void endDelete() { 
		if (tail->prev == head) return;
		tail->prev->selvDelete();
	}
	void printAll() {
		Node* tmp = head;
		while (tmp->next != tail) {
			printf("%d\n", tmp->next->data);
			tmp = tmp->next;
		}
	}
};

int main() {
	DLinkedList *list = new DLinkedList();
	list->firstInsert(1); 
	list->firstInsert(3); 
	list->firstInsert(5); 
	list->firstDelete(); 
	list->endInsert(100); 
	list->endInsert(200); 
	list->endInsert(300); 
	list->endDelete();
	list->printAll();
	delete list;
}