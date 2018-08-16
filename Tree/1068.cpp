#include <iostream>
#include <ios>
#include <vector>

using namespace std;

int par[51];
vector<int> child[51];

int find(int cur) {
	int cnt = 0;
	int ret = 0;
	for (int next : child[cur]) {
		if (next == -1)
			continue;
		++cnt;
		ret += find(next);
	}
	if (!cnt)
		return 1;
	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, root, x;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> par[i];
		if (par[i] == -1)
			root = i;
		else
			child[par[i]].push_back(i);
	}
	cin >> x;
	if (x == root)
		cout << "0" << "\n";
	else {
		int k = par[x];
		for (int i = 0; i < child[k].size(); ++i)
			if (child[k][i] == x)
				child[k][i] = -1;

		cout << find(root) << "\n";
	}
	return 0;
}