#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> q;
	
	for (int i = 0; i < 5; i++)
		q.push(i);

	cout << q.front() << endl;
	cout <<q.back() << endl;
	cout <<q.size() << endl;
	cout <<(q.empty() ? "Yes" : "No") << endl;

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}