#include<cstdio>
const int MAX_N = 50;
int n, a[MAX_N], b[MAX_N];
int main() {
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", a + i);
		for (int j = 0; j<i; j++)
			a[j]>a[i] ? b[j]++ : b[i]++;
	}
	for (int i = 0; i<n; i++) printf("%d ", b[i]);
	return 0;
}