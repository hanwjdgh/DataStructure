#include <iostream>
#include <ios>
#include "ArrayCQ.h"

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	CQueue cqueue;

	init(&cqueue);

	enQueue(&cqueue, 1);
	enQueue(&cqueue, 2);
	enQueue(&cqueue, 3);

	print(&cqueue);

	peek(&cqueue);
	cout << "Size: " << getSize(&cqueue) << "\n";

	deQueue(&cqueue);
	deQueue(&cqueue);

	cout << "Empty: " << (isEmpty(&cqueue) ? "TRUE" : "FALSE") << "\n";

	enQueue(&cqueue,4);
	enQueue(&cqueue,5);
	enQueue(&cqueue,6);

	print(&cqueue);

	return 0;
}