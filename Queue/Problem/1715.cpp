#include <iostream>
#include <ios>
#include <queue>
#include <functional>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, x;
	long long ans = 0;

	cin >> N;
	priority_queue< int, vector<int>, greater<int> > pq;

	for(int i=0; i<N; i++){
		cin >> x;
		pq.push(x);
	}

	if (N == 1)
		ans = 0;

	while (!pq.empty()) {
		int p_size = pq.size();
		if (p_size > 1) {
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			ans += (a + b);
			pq.push(a + b);
		}
		else
			break;
	}
	cout << ans << endl;
	return 0;
}