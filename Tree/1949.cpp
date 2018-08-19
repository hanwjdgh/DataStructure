#include <iostream>
#include <ios>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 1000001

using namespace std;

vector <int > v[MAX], tree[MAX];
int visit[MAX],val[MAX];
int dp[MAX][2];

void make_tree(int cur) {
	visit[cur] = 1;

	for (int next : v[cur]) {
		if (!visit[next]) {
			tree[cur].push_back(next);
			make_tree(next);
		}
	}
}

int check(int cur, int chk) {
	int &ret = dp[cur][chk];

	if (ret != -1)
		return ret;

	ret = 0;
	for (int next : tree[cur]) {
		if (chk == 0)
			ret += max(check(next,0),check(next,1));
		else
			ret += check(next,0);
	}
	return ret += (chk==1 ? val[cur] : 0);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, a, b;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> val[i];

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	make_tree(1);

	memset(dp, -1, sizeof(dp));
	cout << max(check(1, 0), check(1, 1)) << endl;
	return 0;
}