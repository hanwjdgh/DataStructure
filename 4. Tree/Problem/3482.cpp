#include <iostream>
#include <ios>
#include <cstring>
#include <string>
#include <algorithm>

#define MAX 1001

using namespace std;

int C, R;
string lab[MAX];
int visit[MAX][MAX];
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int v_max, sx, sy;

void find(int x, int y) {
	if (v_max < visit[x][y]) {
		v_max = visit[x][y];
		sx = x, sy = y;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C || visit[nx][ny] != 0 || lab[nx][ny] == '#')
			continue;
		visit[nx][ny] = visit[x][y] + 1;
		find(nx, ny);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	while (T--) {
		memset(visit, 0, sizeof(visit));
		v_max = sx = sy = 0;

		cin >> C >> R;

		for (int i = 0; i < R; i++)
			cin >> lab[i];

		for (int i = 1; i < R - 1; i++) {
			for (int j = 1; j < C - 1; j++) {
				if (lab[i][j] == '#')
					continue;

				int cnt = 0;
				for (int a = 0; a < 4; a++) {
					int nx = i + dx[a], ny = i + dy[a];
					if (lab[nx][ny] == '#')
						cnt++;
				}
				if (cnt >= 3) {
					visit[i][j] = 1;
					find(i, j);
					break;
				}
			}
		}
		v_max = 0;
		memset(visit, 0, sizeof(visit));
		visit[sx][sy] = 1;
		find(sx, sy);
		cout << "Maximum rope length is " << v_max - 1 <<"."<< endl;
		for (int i = 0; i < R; i++)
			lab[i].clear();
	}
	return 0;
}