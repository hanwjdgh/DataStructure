#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int x, y, w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	printf("%d", min(min(abs(x - 0), abs(w - x)), min(abs(y - 0), abs(h - y))));
	return 0;
}