#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

vector <int > v[MAX];
int par[MAX];

void dfs(int cur) {
	for (int next : v[cur]) {
		if (!par[next]) {
			par[next] = cur;
			dfs(next);
		}
	}
}

int main() {

	int N;
	int a, b;

	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i <= N; i++)
		printf("%d\n", par[i]);
	return 0;
}