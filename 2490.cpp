#include <cstdio>
int main(void) {
	char str[5] = { 'E','A', 'B', 'C', 'D' };
	int a, b, num, cnt;
	for (a = 0; a < 3; a++) {
		cnt = 0;
		for (b = 0; b < 4; b++) {
			scanf("%d", &num);
			if (num == 0)
				cnt++;
		}
		printf("%c\n", str[cnt]);
	}
	return 0;
}