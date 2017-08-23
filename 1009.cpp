#include <cstdio>


void mod(int, int);
int main(void) {
	int num;
	int a, x, y;
	scanf("%d", &num);
	for (a = 0; a < num; a++) {
		scanf("%d %d", &x, &y);
		mod(x, y);
	}
	return 0;
}

void mod(int a, int b) {
	int arr[100], cnt = 0;
	int x, d = 1;

	if (a % 10 == 0)
		d = 10;
	else {
		while (1) {
			arr[cnt++] = b % 2;
			b /= 2;
			if (b == 0)
				break;
		}
		for (x = cnt - 1; x > -1; --x) {
			d = (d*d) % 10;
			if (arr[x] == 1)
				d = (d*a) % 10;
		}
	}
	printf("%d\n", d);
}