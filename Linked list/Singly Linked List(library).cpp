#include <iostream>
#include <list>

using namespace std;

int main(){
	list<int> mylist;
	list<int>::iterator it;

	for (int i = 0; i < 5; i++)
		mylist.push_back(i);

	for (it = mylist.begin(); it != mylist.end(); it++) 
		printf("%d ", *it);
	
	printf("%d", mylist.size());
	mylist.clear();
	return 0;
}