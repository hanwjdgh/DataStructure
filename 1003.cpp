#include <cstdio>

int a, b;

int fibonacci(int n) {
	if (n == 0) {
		++a;
		return 0;
	}
	else if (n == 1) {
		++b;
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
int main(void) {
	int num, x, test;
	scanf("%d", &num);
	for (x = 0; x < num; ++x) {
		a = b = 0;
		scanf("%d", &test);
		fibonacci(test);
		printf("%d %d\n", a, b);
	}
	return 0;
}