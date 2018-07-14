#include <iostream>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

queue<int> q[21];

int main() {
	int N, K;
	long long ans = 0;

	cin >> N >> K;
	for (int i = 0; i<N; i++) {
		string arr;
		
		cin >> arr;
		int len = arr.length();
		while (!q[len].empty() && q[len].front() < i - K) {
			q[len].pop();
		}

		ans += q[len].size();
		q[len].push(i);
	}
	printf("%lld\n", ans);
}