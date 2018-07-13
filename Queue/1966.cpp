#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair <int, int> P;

int main() {
	int T, N, M;
	int a, b, num;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		queue <P> q;
		int max_v = 0, cnt = 1;
		for (int j = 0; j < N; j++) {
			cin >> num;
			q.push(make_pair(j, num));
			max_v = max(max_v, num);
		}

		while (!q.empty()) {
			P tmp = q.front();
			q.pop();
			if (tmp.second == max_v) {
				if (tmp.first == M) {
					printf("%d\n", cnt);
					break;
				}
				else {
					cnt++;
					max_v = 0;
					int size = q.size();
					for (int j = 0; j < size; j++) {
						P tm = q.front();
						max_v = max(max_v, tm.second);
						q.pop();
						q.push(tm);
					}
				}
			}
			else
				q.push(tmp);
		}
	}
	return 0;
}