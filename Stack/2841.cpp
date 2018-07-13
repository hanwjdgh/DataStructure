#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<int> s[7];

int main() {
	int N, P;
	int a, b, ans = 0;

	cin >> N >> P;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		while (!s[a].empty() && s[a].top() > b) {
			s[a].pop();
			ans++;
		}
		if (s[a].empty() || s[a].top() != b) {
			s[a].push(b);
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}