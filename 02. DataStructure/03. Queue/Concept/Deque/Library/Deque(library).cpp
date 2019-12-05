#include <iostream>
#include <deque> // Use queue Library

using namespace std;

int main() {
	// Declaration int deque, iterator
	deque<int> dq;
	deque<int>::iterator iter;

	// Push data
	dq.push_front(0); // front 0       back
	dq.push_front(1); // front 1 0     back
	dq.push_back(3);  // front 1 0 3   back
	dq.push_back(4);  // front 1 0 3 4 back

	for (iter = dq.begin(); iter != dq.end(); iter++) 
		cout << *iter << " "; 
	// 1 0 3 4
	cout << "\n";

	dq.pop_front();   // front 0 3 4 back
	dq.pop_back();    // front 0 3   back
	
	for (iter = dq.begin(); iter != dq.end(); iter++) 
		cout << *iter << " ";
	// 0 3
	
	return 0;
}