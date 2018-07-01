#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> dq;
	deque<int>::iterator iter;

	dq.push_front(0); // 0 
	dq.push_front(1); // 1 0
	dq.push_back(3); // 1 0 3
	dq.push_back(4); // 1 0 3 4
	for (iter = dq.begin(); iter != dq.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	dq.pop_front(); // 0 3 4
	dq.pop_back(); // 0 3
	for (iter = dq.begin(); iter != dq.end(); iter++) {
		cout << *iter << " ";
	}
	return 0;
}