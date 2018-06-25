#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

class linked_list{
private:
	node *head, *tail;
public:
	linked_list(){
		head = NULL;
		tail = NULL;
	}

	void add_node(int n){
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if (head == NULL){
			head = tmp;
			tail = tmp;
		}
		else{
			tail->next = tmp;
			tail = tail->next;
		}
	}
	void print() {
		node *cur = head;
		while (cur != NULL) {
			printf("%d ", cur->data);
			cur = cur->next;
		}
	}
};

int main(){
	linked_list a;
	for (int i = 0; i < 5; i++) 
		a.add_node(i);
	
	a.print();
	return 0;
}