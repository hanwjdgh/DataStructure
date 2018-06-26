#include <iostream>
#include <list>

using namespace std;

list<int> mylist;

void print() {
	list<int>::iterator it;
	for (it = mylist.begin(); it != mylist.end(); it++)
		printf("%d ", *it);
	printf("\n");
}

int main() {
	for (int i = 0; i < 5; i++)
		mylist.push_back(i);
	print(); // 0 1 2 3 4
	printf("%d\n", mylist.size()); // 5
	printf("%s\n",(mylist.empty() ? "Yes" : "No")); //No

	mylist.push_front(-1); print(); // -1 0 1 2 3 4

	list<int>::iterator point = mylist.begin();
	point++; point++;
	mylist.insert(point,8); print(); // -1 0 8 1 2 3 4
	mylist.pop_front(); print(); // 0 8 1 2 3 4
	mylist.pop_back(); print(); // 0 8 1 2 3
	point--;
	mylist.erase(point); print(); // 0 1 2 3
	mylist.clear();
	return 0;
}