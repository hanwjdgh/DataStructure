#include <iostream>
#include <string>
using namespace std;

int main() {
	int m, n, dir = 0, x = 0, y = 0;
	int a, cn;
	int fx[4] = { 1,0,-1,0 }, fy[4] = { 0,-1,0,1 };
	char str[10];

	cin >> m >> n;
	for (a = 0; a < n; a++) {
		cin >> str >> cn;
		if (str[0] == 'M') {
			x += fx[dir] * cn;

			y += fy[dir] * cn;
		}
		else
			dir = (dir + 3 - 2 * cn) % 4;
		if (x<0 || y<0 || x>m || y>m) {
			cout << -1;
			return 0;			
		}
	}
	cout << x << " " << y;
	return 0;
}