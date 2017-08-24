#include <cstdio>

int main(void) {
	long tcase, num1, num2;
	long a, b, tmp, cnt = 0;

	scanf("%d", &tcase);
	for (a = 0; a < tcase; a++) {
		scanf("%d %d", &num1, &num2);
		if (num2 - num1 == 1)
			printf("1\n");
		else if (num2 - num1 == 2)
			printf("2\n");
		else {
			b = 1;
			tmp = num2 - num1;
			while (1) {
				if (tmp > b*b && tmp <= b*b + b) {
					cnt = 2 * b;
					break;
				}
				if (tmp > b*b + b && tmp <= b*b + 2 * b + 1) {
					cnt = 2 * b + 1;
					break;
				}
				++b;
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}