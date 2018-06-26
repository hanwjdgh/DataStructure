#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> s;

	for (int i = 0; i < 5; i++)
		s.push(i);
	// 4 3 2 1 0
	cout << s.top() << endl; // 4
	cout << s.size() << endl; // 5
	cout << (s.empty() ? "Yes" : "No") << endl; // No

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	// 4 3 2 1 0
	return 0;

}