#include <iostream>
#include <ios>
#include <vector>

#define MAX 1001

using namespace std;

int pre[MAX], in[MAX], pos[MAX];
int n, st;

void find(int s, int e) {
	if (s == e)
		return;
	int root = pre[st++];
	int mid = pos[root];
	find(s, mid);
	find(mid + 1, e);
	cout << root << " ";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	while (T--) {
		cin >> n;

		st = 1;
		fill(pre, pre + MAX, 0);
		fill(in, in + MAX, 0);
		fill(pos, pos + MAX, 0);

		for (int i = 1; i <= n; i++)
			cin >> pre[i];
		for (int i = 1; i <= n; i++) {
			cin >> in[i];
			pos[in[i]] = i;
		}

		find(1, n+1);
		cout << endl;
	}
	return 0;
}