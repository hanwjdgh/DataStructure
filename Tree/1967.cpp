#include <iostream>
#include <ios>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 10001

using namespace std;

typedef pair <int, int > p;
vector <p > v[MAX];
int visit[MAX];
int fmax_v, fidx;

void find(int cur, int value) {
	visit[cur] = 1;

	if (fmax_v < value) {
		fmax_v = value;
		fidx = cur;
	}

	for (p node : v[cur]) {
		int next = node.first, w = node.second;
		if (!visit[next])
			find(next, value + w);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, a, b, c;

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	find(1, 0);
	int idx = fidx;
	fill(visit, visit + MAX, 0);
	fmax_v = fidx = 0;
	find(idx, 0);
	cout << fmax_v << "\n";
	
	return 0;
}