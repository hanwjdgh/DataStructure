#include<iostream>
#include <queue>

using namespace std;

void Find(int N, int M) {
	queue<int> q;
	int a;
	for (a = 1; a <= N; ++a)
		q.push(a);
	cout << "<";
	while (!q.empty()) {
		for (a = 0; a < M - 1; ++a) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (!q.empty())
			cout << ", ";
	}
	cout << ">";
}

int main(void) {
	int N, M;
	cin >> N >> M;
	Find(N, M);
	return 0;
}