#include <iostream>
#include <ios>
#include <vector>
#include <queue>

#define MAX 501
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int t_case = 1;
	while (1) {
		vector <int > v[501];
		int visit[MAX] = { 0, };
		int a, b;
		queue <int > q;

		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int ver = 0, edge = 0;
			if (!visit[i]) {
				cnt++;
				q.push(i);

				while (!q.empty()) {
					int cur = q.front();
					q.pop();

					if (visit[cur])
						continue;
					ver++;
					visit[cur] = 1;

					for (int next : v[cur]) {
						edge++;
						q.push(next);
					}
				}
				if (edge / 2 != ver - 1)
					cnt--;
			}
		}
		if (cnt > 1)
			cout <<"Case "<<t_case<<": A forest of "<<cnt<<" trees."<< "\n";
		else if (cnt==1)
			cout <<"Case "<<t_case<<": There is one tree."<< "\n";
		else
			cout <<"Case "<< t_case <<": No trees."<< "\n";
		t_case++;
	}
	return 0;
}