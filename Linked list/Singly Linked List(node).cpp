#include <iostream>

using namespace std;

struct node {
	int data;
	node *next;
};

class linked_list {
private:
	node *head, *tail;
public:
	linked_list() {
		head = NULL;
		tail = NULL;
	}
	void add_node_head(int n) {
		node *tmp = new node;
		tmp->data = n;
		tmp->next = head;
		head = tmp;
		print();
	}
	void add_node_pos(int pos, int n) {
		node *pre = new node;
		node *cur = new node;
		node *tmp = new node;
		cur = head;
		for (int i = 1; i<=pos; i++){
			pre = cur;
			cur = cur->next;
		}
		tmp->data = n;
		pre->next = tmp;
		tmp->next = cur;
		print();
	}
	void add_node_tail(int n) {
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if (head == NULL) {
			head = tmp;
			tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tail->next;
		}
	}
	void delete_node_head() {
		node *tmp = new node;
		tmp = head;
		head = head->next;
		delete tmp;
		print();
	}
	void delete_node_pos(int pos) {
		node *cur = new node;
		node *pre = new node;
		cur = head;
		for (int i = 1; i<=pos; i++){
			pre = cur;
			cur = cur->next;
		}
		pre->next = cur->next;
		print();
	}
	void delete_node_tail() {
		node *cur = new node;
		node *pre = new node;
		cur = head;
		while (cur->next != NULL){
			pre = cur;
			cur = cur->next;
		}
		tail = pre;
		pre->next = NULL;
		delete cur;
		print();
	}
	void print() {
		node *cur = head;
		while (cur != NULL) {
			printf("%d ", cur->data);
			cur = cur->next;
		}
		printf("\n");
	}
};

int main() {
	linked_list a;
	for (int i = 0; i < 5; i++)
		a.add_node_tail(i);
	a.print();            // 0 1 2 3 4
	a.add_node_head(-1);  // -1 0 1 2 3 4
	a.add_node_pos(2, 8); // -1 0 8 1 2 3 4
	a.delete_node_head(); // 0 8 1 2 3 4
	a.delete_node_tail(); // 0 8 1 2 3
	a.delete_node_pos(1); // 0 1 2 3
	return 0;
}