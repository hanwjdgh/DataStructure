#include <cstdio>
#include <cmath>
using namespace std;

int main(void) {
	int numofcase, cnt;
	int a, numofp, b;
	int x1, y1, x2, y2;
	int px, py, pr;
	double dist1, dist2;
	scanf("%d", &numofcase);
	for (a = 0; a < numofcase; ++a) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &numofp);
		cnt = 0;
		for (b = 0; b < numofp; ++b) {
			scanf("%d %d %d", &px, &py, &pr);
			dist1 = sqrt((px - x1)*(px - x1) + (py - y1)*(py - y1));
			dist2 = sqrt((px - x2)*(px - x2) + (py - y2)*(py - y2));
			if (dist1 < pr && dist2 > pr)
				++cnt;
			if (dist1 > pr && dist2 < pr)
				++cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}