#include <iostream>
#include <queue> // Use queue Library

using namespace std;

int main() {
	// Declaration int queue
	queue<int> q;

	// Push data
	for (int i = 0; i < 5; i++)
		q.push(i);
	// front 0 1 2 3 4 back

	cout << q.front() << endl; // 0
	cout << q.back() << endl; // 4
	cout << q.size() << endl; // 5
	cout << (q.empty() ? "Yes" : "No") << "\n"; // No

	// Pop data
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	//0 1 2 3 4
	
	return 0;
}