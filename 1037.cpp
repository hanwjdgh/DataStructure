#include<cstdio>
int n, a = 1e9, b = 0, x;
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		if (a > x)
			a = x;
		if (b < x)
			b = x;
	}
	printf("%d", a*b);
	return 0;
}