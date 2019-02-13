#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

queue <int> q;

int main() {
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++)
		q.push(i);

	if (q.size() == 1)
		printf("%d", q.front());
	else {
		while (!q.empty()) {
			q.pop();
			if (q.size() == 1) {
				printf("%d", q.front());
				break;
			}
			int val = q.front();
			q.pop();
			q.push(val);
		}
	}
	return 0;
}