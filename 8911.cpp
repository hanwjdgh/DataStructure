#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int fx[4] = { 0,1,0,-1 }, fy[4] = { 1,0,-1,0 };
int main(void) {
	int num, mx, my, px, py;
	int a, x, y, dir;
	string str;

	scanf("%d%*c", &num);
	while (num--) {
		x = y = dir = 0;
		mx = px = my = py = 0;
		getline(cin, str);
		for (a = 0; a < str.length(); a++) {
			if (str.at(a) == 'F') {
				x += fx[dir] * 1;
				y += fy[dir] * 1;
			}
			else if (str.at(a) == 'B') {
				x += fx[dir] * -1;
				y += fy[dir] * -1;
			}
			else if (str.at(a) == 'L')
				dir = (dir + 3) % 4;
			else if (str.at(a) == 'R')
				dir = (dir + 1) % 4;

			mx = min(mx, x);
			my = min(my, y);
			py = max(py, y);
			px = max(px, x);
		}
		printf("%d\n", abs(px - mx)* abs(py - my));
	}
	return 0;
}