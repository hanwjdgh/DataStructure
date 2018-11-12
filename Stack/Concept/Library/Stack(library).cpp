#include <iostream>
#include <stack> // Use stack Library

using namespace std;

int main() {
	// Declaration int stack
	stack<int> s;

    // Push data
	for (int i = 0; i < 5; i++)
		s.push(i);
	// top 4 3 2 1 0 bottom

	cout << s.top() << endl; // 4
	cout << s.size() << endl; // 5
	cout << (s.empty() ? "Yes" : "No") << endl; // No

    // Pop data
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	// 4 3 2 1 0
	return 0;

}