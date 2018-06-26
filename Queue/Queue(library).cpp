#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> q;

	for (int i = 0; i < 5; i++)
		q.push(i);
	// 0 1 2 3 4
	cout << q.front() << endl; // 0
	cout << q.back() << endl; // 4
	cout << q.size() << endl; // 5
	cout << (q.empty() ? "Yes" : "No") << endl; // No

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	//0 1 2 3 4
	return 0;
}