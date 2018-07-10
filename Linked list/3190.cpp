#include <iostream>
#include <cstdio>
#include <vector>
#include <list>

using namespace std;

vector <pair <int, char> > vp;
list <pair <int, int> > lst;
pair <int, int> tp;

int main(void) {
	int board[100][100];
	int N, K, L, head[2], s = 0,cnt=0;
	int Ddx[4] = { 0, 1, 0, -1 }, Ddy[4] = { 1, 0, -1, 0 };
	int Ldx[4] = { -1, 0, 1, 0 }, Ldy[4] = { 0, -1, 0, 1 };
	char dir = 'D';

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = 0;
	board[0][0] = -1;

	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		board[a - 1][b - 1] = 1;
	}

	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		int a;
		char c;
		scanf("%d %c", &a, &c);
		vp.push_back(make_pair(a, c));
	}

	lst.push_back(make_pair(0, 0));
	int dx=0, dy=0;
	int time = 0;
	while (1) {
		if(dir=='D')
			dx = lst.front().first + Ddx[s], dy = lst.front().second + Ddy[s];
		else 
			dx = lst.front().first + Ldx[s], dy = lst.front().second + Ldy[s];
		time++;

		if (0 > dx || dx >= N || 0 > dy || dy >= N || board[dx][dy] == -1)
			break;

		if (board[dx][dy] != 1) {
			tp = lst.back();
			board[tp.first][tp.second] = 0;
			lst.pop_back();
		}
		lst.push_front(make_pair(dx, dy));
		board[dx][dy] = -1;

		if (cnt < L) {
			if (vp[cnt].first == time) {
				if (dir == vp[cnt].second)
					s = (s + 1) % 4;
				else {
					if (s % 2 == 1) {
						s = (s + 2) % 4;
					}
					dir = vp[cnt].second;
				}
				cnt++;
			}
		}
	}
	printf("%d\n", time);
	return 0;
}