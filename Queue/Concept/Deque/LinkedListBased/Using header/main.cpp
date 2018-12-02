#include <iostream>
#include <ios>
#include "LinkedListDQ.h"

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	DQueue dqueue;

	init(&dqueue);

	pushFront(&dqueue, 2);
	pushFront(&dqueue, 1);
	pushRear(&dqueue, 3);
	pushRear(&dqueue, 4);

	print(&dqueue);

	cout << "Size: " << getSize(&dqueue) << "\n";

	cout << "Empty: " << (isEmpty(&dqueue) ? "TRUE" : "FALSE") << "\n";
	
	popFront(&dqueue);
	popRear(&dqueue);

	print(&dqueue);

	return 0;
}