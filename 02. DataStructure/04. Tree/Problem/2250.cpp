#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

#define MAX 10001

using namespace std;

vector <int > v[MAX];
int root[MAX];
int cnt = 1, cont=0;
int min_v[MAX], max_v[MAX];

void in_order(int cur, int level) {
	
	if (cur == -1)
		return;

	for (int i = 0; i < v[cur].size(); i++) {
		in_order(v[cur][i], level + 1);
		if (i == 0) {
			cont = max(cont, level);
			min_v[level] = min(min_v[level], cnt);
			max_v[level] = max(max_v[level], cnt);
			cnt++;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, a, b, c, rot;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		v[a].push_back(b);
		v[a].push_back(c);

		root[a]++;
		if (b != -1)
			root[b]++;
		if (c != -1)
			root[c]++;
	}
	for (int i = 1; i <= N; i++)
		if (root[i] == 1)
			rot = i;

	fill(min_v, min_v + MAX, 100000);
	fill(max_v, max_v + MAX, -1);
	in_order(rot, 1);
	
	int ans = -1,idx=0;
	for (int i = 1; i <= cont; i++) {
		int temp = max_v[i] - min_v[i] + 1;
		if (temp > ans) {
			ans = temp;
			idx = i;
		}
	}
	cout << idx << " " << ans << endl;
	return 0;
}