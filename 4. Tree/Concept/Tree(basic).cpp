#include <iostream>
#include <vector>
using namespace std;

const int TREE_MAX_SIZE = 10000;
vector <int> child[TREE_MAX_SIZE];

void insert(int p, int c) {
	if (p == -1)
		return;
	child[p].push_back(c);
}

void pre_order(int cur) {
	cout << cur << ' ';
	for (int i = 0; i < child[cur].size(); i++)
		pre_order(child[cur][i]);
}
void in_order(int cur) {
	if (child[cur].size() == 0)
		cout << cur << ' ';
	for (int i = 0; i < child[cur].size(); i++) {
		in_order(child[cur][i]);
		if(i==0)
			cout << cur << ' ';
	}
}
void post_order(int cur) {
	for (int i = 0; i < child[cur].size(); i++)
		post_order(child[cur][i]);
	cout << cur << ' ';
}
int main() {
	insert(-1, 0);
	insert(0, 1);
	insert(0, 2);
	insert(1, 3);
	insert(1, 4);
	/*
	   0
	 1   2
	3 4
	*/
	printf("Pre-order : ");
	pre_order(0);  // 0 1 3 4 2
	printf("\n");

	printf("In-order : ");
	in_order(0);   // 3 1 4 0 2
	printf("\n");

	printf("Post-order : ");
	post_order(0); // 3 4 1 2 0
	printf("\n");
}