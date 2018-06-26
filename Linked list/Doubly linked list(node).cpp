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
	DLinkedList() { //생성자
		count = 0;
		head = new Node(); //더미를 선언해서 가지고 있게한다.
		tail = new Node(); //더미를 선언해서 가지고 있게한다.
		head->next = tail; //서로연결한다.
		tail->prev = head;
	}
	~DLinkedList() {
		while (head->next != tail)
			head->next->selvDelete();
		delete head;
		delete tail;
	}
	void firstInsert(int i) { //head 다음에 추가한다.
		new Node(i, head);
	}
	void endInsert(int i) { //tail 앞에 추가한다.
		new Node(i, tail->prev);
	}
	void firstDelete() { //head 다음 노드 삭제한다.
		if (head->next == tail)    return;
		head->next->selvDelete();
	}
	void endDelete() { //tail 앞에 제거한다.
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
	list->firstInsert(1); //1을 삽입한다.(가장앞)
	list->firstInsert(3); //3을 삽입한다.(1앞에)
	list->firstInsert(5); //5을 삽입한다.(3앞에)
	list->firstDelete(); //5를 삭제한다
	list->endInsert(100); //100을 삽입한다.(가장뒤에)
	list->endInsert(200); //200을 삽입한다.(100뒤에)
	list->endInsert(300); //300을 삽입한다.(200뒤에)
	list->endDelete(); //300을 삭제한다.
	list->printAll();
	delete list;
}