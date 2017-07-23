#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main(void) {
	int num, x, y, tem, cur, next;
	int a, N, K, end;
	queue<int> Q;
	scanf("%d", &num);

	while (num--) {
		int cost[1001], dis[1001], chk[1001];
		fill(cost, cost + 1001, 0);
		fill(dis, dis + 1001, -1);
		fill(chk, chk + 1001, -1);

		vector<int> adj[1001];
		scanf("%d %d", &N, &K);
		for (a = 0; a < N; a++)
			scanf("%d", &cost[a]);
		for (a = 0; a < K; a++) {
			scanf("%d %d", &x, &y);
			--x; --y;
			adj[x].push_back(y);
			chk[y] = 1;
		}
		scanf("%d", &end);
		for (a = 0; a < N; a++) {
			if (chk[a] != 1) {
				Q.push(a);
				dis[a] = cost[a];
			}
		}

		while (!Q.empty()){
			int cur = Q.front();
			Q.pop();
			for (a = 0; a < adj[cur].size(); a++) {
				next = adj[cur][a];
				tem = dis[cur] + cost[next];

				if (tem > dis[next]) {
					dis[next] = tem;
					Q.push(next);
				}
			}
		}
		printf("%d\n", dis[end - 1]);
	}
	return 0;
}