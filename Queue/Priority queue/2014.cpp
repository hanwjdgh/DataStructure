#include <iostream>
#include <ios>
#include <map>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long > v;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	long long num, max_v = 0;

	cin >> K >> N;
	priority_queue< long long, vector<long long >, greater<long long > > pq;
	map <long long, int > visit;

	for (int i = 0; i < K; i++) {
		cin >> num;
		v.push_back(num);
		pq.push(num);
		max_v = max(max_v, num);
	}
	
	int cnt = 0;
	while (!pq.empty()) {
		long long var = pq.top();
		pq.pop();
		cnt++;
		if (cnt == N) {
			cout << var << endl;
			break;
		}
		for (int i = 0; i < K; i++) {
			long long temp = v[i] * var;
			if (pq.size() + cnt > N && max_v < temp)
				break;

			if (!visit[temp]) {
				visit[temp] = 1;
				max_v = max(max_v, temp);
				pq.push(temp);
			}
		}
	}
	return 0;
}